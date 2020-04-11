%{
	#include "stdc++.h"
	#include "symboltable.h"
	#include "lex.yy.c"
	#include <string.h>
	#include <stdlib.h>
	using namespace std;

	void yyerror(char *msg);

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  	extern entry_t** constant_table;

	int current_dtype;
	int current_storage;

	table_t symbol_table_list[NUM_TABLES];

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;

	int param_list[10];
	int p_idx = 0;
	int p=0;
  	int rhs = 0;

	void type_check(int,int,int);
	vector<int> merge(vector<int>& v1, vector<int>& v2);
	void backpatch(vector<int>&, int);
	void gencode(string);
	void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void printlist(vector<int>);

	int nextinstr = 0;
	int temp_var_number = 0;
	
	vector<string> ICG;
	typedef struct quadruples
  	{
    		char *op;
    		char *arg1;
    		char *arg2;
    		char *res;
  	}quad;
  	int quadlen = 0;
  	quad** q = (quad**)malloc(100 * sizeof(quad*));
	
%}

%union
{
	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;
	vector<int>* nextlist;
	int instr;
}

%token <entry> IDENTIFIER

 /* Constants */
%token <entry> DEC_CONSTANT HEX_CONSTANT CHAR_CONSTANT FLOAT_CONSTANT STRING

 /* Logical and Relational operators */
%token LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ

 /* Short hand assignment operators */
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token INCREMENT DECREMENT INPUT OUTPUT

 /* Data types */
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST VOID CHAR FLOAT CHAR_STAR

 /* Keywords */
%token IF FOR WHILE CONTINUE BREAK RETURN COUT CIN

%type <entry> identifier
%type <entry> constant
%type <entry> array_index

%type <op> assign;
%type <data_type> function_call

%type <content> lhs
%type <content> sub_expr
%type <content> expression
%type <content> expression_stmt
%type <content> unary_expr
%type <content> arithmetic_expr
%type <content> assignment_expr
%type <content> array_access

%type <content> cin_stat
%type <content> cout_stat
%type <content> if_block
%type <content> for_block
%type <content> while_block
%type <content> compound_stmt

%type <content> statements
%type <content> single_stmt
%type <content> stmt


%type <instr> M
%type <content> N

%left ','
%right '='
%left LOGICAL_OR
%left LOGICAL_AND
%left EQ NOT_EQ
%left '<' '>' LS_EQ GR_EQ
%left '+' '-'
%left '*' '/' '%'
%right '!'


%nonassoc UMINUS
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

 /* Program is made up of multiple builder blocks. */
starter: starter builder
			 | builder;

 /* Each builder block is either a function or a declaration */
builder: function
			 | declaration
			 ;

 /* This is how a function looks like */
function: type identifier 	
			{
				func_type = current_dtype;
				is_declaration = 0;
				current_scope = create_new_scope();
				gencode($2->lexeme + string(":"));
			}

		 '(' argument_list ')' 	
		 	{
				is_declaration = 0;
				fill_parameter_list($2,param_list,p_idx);
				p_idx = 0;
				is_func = 1;
				p=1;
			}

		 compound_stmt	{   is_func = 0;	}
          
		;
 
 /* Now we will define a grammar for how types can be specified */

type : data_type pointer    {is_declaration = 1; }
     | data_type		    {is_declaration = 1; }
		 ;

pointer: '*' pointer
    	| '*'
       ;

data_type : sign_specifier type_specifier
    	| type_specifier
    	;

sign_specifier : SIGNED
    		| UNSIGNED
    		;

type_specifier :INT                    {current_dtype = INT;current_storage=4;}
    |SHORT INT                         {current_dtype = SHORT;current_storage=2;}
    |SHORT                             {current_dtype = SHORT;current_storage=2;}
    |LONG                              {current_dtype = LONG;current_storage=8;}
	|LONG INT                          {current_dtype = LONG;current_storage=8;}
    |LONG_LONG                         {current_dtype = LONG_LONG;current_storage=8;}
    |LONG_LONG INT                     {current_dtype = LONG_LONG;current_storage=8;}
	|CHAR 							   {current_dtype = CHAR;current_storage=1;}
	|FLOAT 							   {current_dtype = FLOAT;current_storage=4;}
	|VOID							   {current_dtype = VOID;current_storage=0;}
	|CHAR_STAR					 	   {current_dtype = STRING;current_storage=4;}
    ;

 /* grammar rules for argument list */
 /* argument list can be empty */
argument_list : arguments
    	|
    	;
 /* arguments are comma separated TYPE ID pairs */
arguments : arguments ',' arg
    	| arg
    	;

 /* Each arg is a TYPE ID pair */
arg : type identifier	{
							param_list[p_idx++] = $2->data_type;
							gencode(string("arg ") + $2->lexeme);
						}
    ;

 /* Generic statement. Can be compound or a single statement */
stmt:compound_stmt		{$$ = new content_t(); $$=$1;}
    |single_stmt		{$$ = new content_t(); $$=$1;}
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :
				'{' 	
				
				{
					if(!p)current_scope = create_new_scope();
					else p = 0;
				}
				
				statements
				
				'}' 
				
				{
					current_scope = exit_scope();
					$$ = new content_t();
					$$ = $3;
				}
    ;

statements:statements M stmt	{
									backpatch($1->nextlist,$2);
									$$ = new content_t();
									$$->nextlist = $3->nextlist;
									$$->breaklist = merge($1->breaklist,$3->breaklist);
									$$->continuelist = merge($1->continuelist,$3->continuelist);
								}

    |							{	$$ = new content_t();	}
    ;

 /* Grammar for what constitutes every individual statement */
single_stmt :if_block	{
							$$ = new content_t();
							$$ = $1;
							backpatch($$->nextlist, nextinstr);
						}

		    |for_block	{
							$$ = new content_t();
							$$ = $1;
							backpatch($$->nextlist, nextinstr);
						}
		
	    	|while_block {
							$$ = new content_t();
							$$ = $1;
							backpatch($$->nextlist, nextinstr);
						 }
	    	|declaration 		{$$ = new content_t();}
	    	|function_call ';'	{$$ = new content_t();}
			|RETURN ';'	  {
								if(is_func)
								{
									if(func_type != VOID)
										yyerror("return type (VOID) does not match function type");
								}
							  	else yyerror("return statement not inside function definition");
							}
	
			|CONTINUE ';'	{
								if(!is_loop)
									yyerror("Illegal use of continue");
								$$ = new content_t();
								$$->continuelist = {nextinstr};
								gencode("goto _");
							}
	
			|BREAK ';'      {
								if(!is_loop) {yyerror("Illegal use of break");}
								$$ = new content_t();
								$$->breaklist = {nextinstr};
								gencode("goto _");
						    }
	
			|RETURN sub_expr ';' 
							{
								if(is_func)
								{
									if(func_type != $2->data_type)
										yyerror("return type does not match function type");
								}
								else yyerror("return statement not in function definition");
							}
			|cin_stat ';'		{$$ = new content_t();}
			|cout_stat ';'		{$$ = new content_t();}
			|error			{$$ = new content_t();}
	    ;

cin_stat: CIN INPUT identifier		{$$ = new content_t();}
	;
cout_stat: COUT OUTPUT identifier	{$$ = new content_t();}
	| COUT OUTPUT constant		{$$ = new content_t();}
	;
for_block: FOR '(' expression_stmt M expression_stmt M expression ')' {is_loop = 1;} N M stmt {is_loop = 0;}
	         {
				backpatch($5->truelist,$11);
				backpatch($12->nextlist,$6);
				backpatch($12->continuelist, $6);
				backpatch($10->nextlist, $4);
				$$ = new content_t();
				$$->nextlist = merge($5->falselist,$12->breaklist);
				gencode(string("goto ") + to_string($6));
			 }

    		 ;

if_block:IF '(' expression ')' M stmt 	%prec LOWER_THAN_ELSE
	 		{
				backpatch($3->truelist,$5);
				$$ = new content_t();
				$$->nextlist = merge($3->falselist,$6->nextlist);
				$$->breaklist = $6->breaklist;
				$$->continuelist = $6->continuelist;
			}

		|IF '(' expression ')' M stmt  ELSE N M stmt
			{
				backpatch($3->truelist,$5);
				backpatch($3->falselist,$9);

				$$ = new content_t();
				vector<int> temp = merge($6->nextlist,$8->nextlist);
				$$->nextlist = merge(temp,$10->nextlist);
				$$->breaklist = merge($10->breaklist,$6->breaklist);
				$$->continuelist = merge($10->continuelist,$6->continuelist);
			}
    ;

while_block: WHILE M '(' expression	')' M {is_loop = 1;} stmt {is_loop = 0;}
			{
				backpatch($8->nextlist,$2);
				backpatch($4->truelist,$6);
				backpatch($8->continuelist, $2);
				$$ = new content_t();
				$$->nextlist = merge($4->falselist,$8->breaklist);
				gencode(string("goto ") + to_string($2));
			}
		;

declaration: type  declaration_list ';'			{is_declaration = 0;}
			 | declaration_list ';'
			 | unary_expr ';'


declaration_list: declaration_list ',' sub_decl
					|sub_decl
					;

sub_decl: assignment_expr
    		|identifier
    		|array_access
			;

/* This is because we can have empty expession statements inside for loops */
expression_stmt: expression ';'	 
					{
						$$ = new content_t(); 
						$$->truelist = $1->truelist; 
						$$->falselist = $1->falselist;
					}
    			
				| ';'	{	$$ = new content_t();	}
    			;

expression: expression ',' sub_expr
				{
					$$ = new content_t();
					$$->truelist = $3->truelist; 
					$$->falselist = $3->falselist;
				}
    		| sub_expr	
				{
					$$ = new content_t(); 
					$$->truelist = $1->truelist; 
					$$->falselist = $1->falselist;
				}
			;

sub_expr:

		sub_expr '>' sub_expr	
			{
				type_check($1->data_type,$3->data_type,2);
				$$ = new content_t();
				gencode_rel($$, $1, $3, string(" > "));
			}
		| sub_expr '<' sub_expr
			{
				type_check($1->data_type,$3->data_type,2);
				$$ = new content_t();
				gencode_rel($$, $1, $3, string(" < "));
			}

		| sub_expr EQ sub_expr
			{
				type_check($1->data_type,$3->data_type,2);
				$$ = new content_t();
				gencode_rel($$, $1, $3, string(" == "));
			}

		| sub_expr NOT_EQ sub_expr
			{
				type_check($1->data_type,$3->data_type,2);
				$$ = new content_t();
				gencode_rel($$, $1, $3, string(" != "));
			}

		| sub_expr GR_EQ sub_expr
			{
				type_check($1->data_type,$3->data_type,2);
				$$ = new content_t();
				gencode_rel($$, $1, $3, string(" >= "));
			}

		| sub_expr LS_EQ sub_expr
			{
				type_check($1->data_type,$3->data_type,2);
				$$ = new content_t();
				gencode_rel($$, $1, $3, string(" <= "));
			}

		|sub_expr LOGICAL_AND M sub_expr
			{
				type_check($1->data_type,$4->data_type,2);
				$$ = new content_t();
				$$->data_type = $1->data_type;
				backpatch($1->truelist,$3);
				$$->truelist = $4->truelist;
				$$->falselist = merge($1->falselist,$4->falselist);
			}

		|sub_expr LOGICAL_OR M sub_expr
			{
				type_check($1->data_type,$4->data_type,2);
				$$ = new content_t();
				$$->data_type = $1->data_type;
				backpatch($1->falselist,$3);
				$$->truelist = merge($1->truelist,$4->truelist);
				$$->falselist = $4->falselist;
			}

		|'!' sub_expr
			{
				$$ = new content_t();
				$$->data_type = $2->data_type;
				$$->truelist = $2->falselist;
				$$->falselist = $2->truelist;
			}

		|arithmetic_expr
			{
				$$ = new content_t(); 
				$$->data_type = $1->data_type; 
				$$->addr = $1->addr;
			}
    	|assignment_expr
			{
				$$ = new content_t(); 
				$$->data_type = $1->data_type;
			}
		|unary_expr	
			{
				$$ = new content_t(); 
				$$->data_type = $1->data_type;
			}
    ;

assignment_expr :
	lhs assign arithmetic_expr	
			{
				type_check($1->entry->data_type,$3->data_type,1);
		 		$$ = new content_t();
				$$->data_type = $3->data_type;
		 		$$->code = string("t")+to_string(temp_var_number) + string(" = ") + $1->entry->lexeme + *$2 + $3->addr;
				gencode($$->code);
				$$->code = string($1->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				temp_var_number++;
		 		rhs = 0;
			}

    |
	lhs '=' arithmetic_expr	
			{
				type_check($1->entry->data_type,$3->data_type,1);
		 		$$ = new content_t();
				$$->data_type = $3->data_type;
				//if($3->entry->char_value == NULL)
				//{
					$$->code = $1->entry->lexeme + string(" = ") + $3->addr;
				//}
				/*else
				{
		 			$$->code = $1->entry->lexeme + string(" = ") + $3->entry->char_value;
				}*/
				gencode($$->code);
		 		rhs = 0;
			}

    |	
	lhs assign array_access
			{
				type_check($1->entry->data_type,$3->data_type,1);
	 			$$ = new content_t();
				$$->data_type = $3->data_type;
	 			$$->code = string("t")+to_string(temp_var_number) + string(" = ") + $1->entry->lexeme + *$2 + $3->addr;
				gencode($$->code);
				$$->code = string($1->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				temp_var_number++;
		 		rhs = 0;
			}

    |
	lhs '=' array_access
			{
				type_check($1->entry->data_type,$3->data_type,1);
	 			$$ = new content_t();
				$$->data_type = $3->data_type;
	 			$$->code = $1->entry->lexeme + string(" = ") + $3->addr;
				gencode($$->code);
	 			rhs = 0;
			}

    |

	lhs assign function_call
			{
				type_check($1->entry->data_type,$3,1); 
				$$ = new content_t(); 
				$$->data_type = $3;
			}

	|

	lhs assign unary_expr  
	        {
				type_check($1->entry->data_type,$3->data_type,1);
			 	$$ = new content_t();
				$$->data_type = $3->data_type;
			 	$$->code = string("t")+to_string(temp_var_number) + string(" = ") + $1->entry->lexeme + *$2 + $3->addr;
				gencode($$->code);
				$$->code = string($1->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				temp_var_number++;
		 		rhs = 0;
			}

	|
	lhs '=' unary_expr  
	        {
				type_check($1->entry->data_type,$3->data_type,1);
			 	$$ = new content_t();
				$$->data_type = $3->data_type;
			 	$$->code = $1->entry->lexeme + string(" = ") + $3->addr;
				gencode($$->code);
			 	rhs = 0;
			}

	|
	unary_expr assign unary_expr		
			{
				type_check($1->data_type,$3->data_type,1);
				$$ = new content_t();
				$$->data_type = $3->data_type;
			 	$$->code = string("t")+to_string(temp_var_number) + string(" = ") + $1->entry->lexeme + *$2 + $3->addr;
				gencode($$->code);
				$$->code = string($1->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				temp_var_number++;
		 		rhs = 0;
			}
	|
	unary_expr '=' unary_expr		
			{
				type_check($1->data_type,$3->data_type,1);
				$$ = new content_t();
				$$->data_type = $3->data_type;
			 	$$->code = $1->code + string(" = ") + $3->addr;
				gencode($$->code);
				rhs = 0;
			}
    ;

unary_expr:	
	identifier INCREMENT	
			{
				$$ = new content_t();
				$$->data_type = $1->data_type;
				$$->code = string("t")+to_string(temp_var_number)+ string(" = ")+string($1->lexeme);
				gencode($$->code);
				temp_var_number++;
				$$->code = string("t")+to_string(temp_var_number)+ string(" = ")+string($1->lexeme)+string(" + 1");
				gencode($$->code);
				$$->code = string($1->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				$$->code = string("t")+to_string(temp_var_number-1);
				temp_var_number++;
			}

 	| identifier DECREMENT		
	 		{
				$$ = new content_t();
				$$->data_type = $1->data_type;
				$$->code = string("t")+to_string(temp_var_number)+ string(" = ")+string($1->lexeme);
				gencode($$->code);
				temp_var_number++;
				$$->code = string("t")+to_string(temp_var_number)+ string(" = ")+string($1->lexeme)+string(" - 1");
				gencode($$->code);
				$$->code = string($1->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				$$->code = string("t")+to_string(temp_var_number-1);
				temp_var_number++;
			}

	| DECREMENT identifier	
			{
				$$ = new content_t();
				$$->data_type = $2->data_type;
				$$->code = string("t")+to_string(temp_var_number)+ string(" = ")+string($2->lexeme) + string(" - 1");
				gencode($$->code);
				$$->code = string($2->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				$$->code = string("t")+to_string(temp_var_number);
				temp_var_number++;
			}

	| INCREMENT identifier
			{
				$$ = new content_t();
				$$->data_type = $2->data_type;
				$$->code = string("t")+to_string(temp_var_number)+ string(" = ")+string($2->lexeme) + string(" + 1");
				gencode($$->code);
				$$->code = string($2->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode($$->code);
				$$->code = string("t")+to_string(temp_var_number);
				temp_var_number++;
			}

lhs: identifier		{$$ = new content_t(); $$->entry = $1;}
   | array_access	{$$ = new content_t(); $$->code = $1->code;}
	 ;

identifier:IDENTIFIER
                {
                    if(is_declaration && !rhs)
                    {
                      $1 = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype,yylineno,current_storage,NULL);
                      if($1 == NULL) 
					  	yyerror("Redeclaration of variable");
                    }
                    else
                    {
                      $1 = search_recursive(yytext);
                      if($1 == NULL) 
					  	yyerror("Variable not declared");
                    }
                    
					$$ = $1;
                }
    		 ;

assign:	ADD_ASSIGN 	{rhs=1; $$ = new string(" + ");}
    |SUB_ASSIGN 	{rhs=1; $$ = new string(" - ");}
    |MUL_ASSIGN 	{rhs=1; $$ = new string(" * ");}
    |DIV_ASSIGN 	{rhs=1;	$$ = new string(" / ");}
    |MOD_ASSIGN 	{rhs=1; $$ = new string(" % ");}
    ;

arithmetic_expr: arithmetic_expr '+' arithmetic_expr
					 {
						type_check($1->data_type,$3->data_type,0);
						$$ = new content_t();
						$$->data_type = $1->data_type;
						gencode_math($$, $1, $3, string(" + "));
					 }

			| arithmetic_expr '-' arithmetic_expr
			  		 {
						type_check($1->data_type,$3->data_type,0);
						$$ = new content_t();
						$$->data_type = $1->data_type;
						gencode_math($$, $1, $3, string(" - "));
					 }

			| arithmetic_expr '*' arithmetic_expr
					 {
						type_check($1->data_type,$3->data_type,0);
						$$ = new content_t();
		 				$$->data_type = $1->data_type;
						gencode_math($$, $1, $3, string(" * "));
					 }

			| arithmetic_expr '/' arithmetic_expr
					 {
						type_check($1->data_type,$3->data_type,0);
						$$ = new content_t();
						$$->data_type = $1->data_type;
						gencode_math($$, $1, $3, string(" / "));
					 }

		    | arithmetic_expr '%' arithmetic_expr
					 {
						type_check($1->data_type,$3->data_type,0);
						$$ = new content_t();
						$$->data_type = $1->data_type;
						gencode_math($$, $1, $3, string(" % "));
				 	 }

			|'(' arithmetic_expr ')'
					 {
						$$ = new content_t();
						$$->data_type = $2->data_type;
						$$->addr = $2->addr;
						$$->code = $2->code;
					 }

    		|'-' arithmetic_expr %prec UMINUS	
					 {
						$$ = new content_t();
						$$->data_type = $2->data_type;
						$$->addr = "t" + to_string(temp_var_number);
						std::string expr = $$->addr + " = " + "minus " + $2->addr;
						$$->code = $2->code + expr;
						temp_var_number++;
				 	 }

    	    |identifier
					 {
						$$ = new content_t();
						$$->data_type = $1->data_type;
	 					$$->addr = $1->lexeme;
			   		 }

    		|constant
					 {
						$$ = new content_t();
						$$->data_type = $1->data_type;
						if($1->value == -1)
						{
							$$->addr = ($1->char_value);
						}
						else
						{
							$$->addr = to_string($1->value);
						}
					 }
    		 ;

constant: DEC_CONSTANT 			{$1->is_constant=1; $$ = $1;}
    	| HEX_CONSTANT			{$1->is_constant=1; $$ = $1;}
		| CHAR_CONSTANT			{$1->is_constant=1; $$ = $1;}
		| FLOAT_CONSTANT		{$1->is_constant=1; $$ = $1;}
    ;

array_access: identifier '[' array_index ']'					
				{
					if(is_declaration)
					{
						if($3->value <= 0)
							yyerror("size of array is not positive");
						else if($3->is_constant)
							$1->array_dimension = $3->value;
							$1->storage = current_storage*$3->value;
					}
					else if($3->is_constant)
					{
						if($3->value > $1->array_dimension)
							yyerror("Array index out of bound");
						if($3->value < 0)
							yyerror("Array index cannot be negative");
					}
					
					$$ = new content_t();
					$$->data_type = $1->data_type;
					
					if($3->is_constant)
						$$->code = string($1->lexeme) + string("[") + to_string($3->value) + string("]");
					else
						$$->code = string($1->lexeme) + string("[") + string($3->lexeme) + string("]");
					$$->entry = $1;
				}

array_index: constant		{$$ = $1;}
		   | identifier		{$$ = $1;}
					 ;

function_call: identifier '(' parameter_list ')'
				{
					$$ = $1->data_type;
					check_parameter_list($1,param_list,p_idx);
					p_idx = 0;
					gencode(string("call ") + $1->lexeme);
				}

             | identifier '(' ')'	
			 	{
					$$ = $1->data_type;
				 	check_parameter_list($1,param_list,p_idx);
				 	p_idx = 0;
	 				gencode(string("call ") + $1->lexeme);
				}
         ;

parameter_list:
              parameter_list ','  parameter
              |parameter
              ;

parameter: sub_expr	
				{
					param_list[p_idx++] = $1->data_type;
					gencode(string("param ") + $1->addr);
				}
		 | STRING	
		 		{
					param_list[p_idx++] = STRING;
					gencode(string("param ") + $1->lexeme);
				}
		 ;

M: 			{$$ = nextinstr;}
 ;

N:			{
				$$ = new content_t;
				$$->nextlist = {nextinstr};
				gencode("goto _");
			}
	;

%%

void gencode(string x)
{
	std::string instruction;

	instruction = to_string(nextinstr) + string(": ") + x;
	ICG.push_back(instruction);
	nextinstr++;
		


//		----------------------FILL HERE TO GET QUADRUPLE FORMAT---------------------



	char** splitwords = (char**)malloc(10 * sizeof(char*));
	for(int i=0;i<10;i++)
	{	
		splitwords[i] = (char*)malloc(sizeof(char)*20);
	}
	char *temp = (char*)malloc(sizeof(char)*(x.length()+1));
	int i=0;
	int count = 0;
	while(i<x.length())
	{
		temp[i]=x[i];
		i++;
	}
	temp[i]='\0';
	char* token = strtok(temp," ");
	while(token != NULL)
	{
		strcpy(splitwords[count],token);
		//printf("%s ",splitwords[count]);
		count++;
		token = strtok(NULL, " ");
	}
	//printf("\n");
	q[quadlen]= (quad*)malloc(sizeof(quad));
	q[quadlen]->res = (char*)malloc(sizeof(char)*20);
	q[quadlen]->op = (char*)malloc(sizeof(char)*20);
	q[quadlen]->arg1 = (char*)malloc(sizeof(char)*20);
	q[quadlen]->arg2 = (char*)malloc(sizeof(char)*20);
	if(count == 3) //5: c = t0
	{
		strcpy(q[quadlen]->res,splitwords[0]);
		strcpy(q[quadlen]->arg1,splitwords[2]);
		strcpy(q[quadlen]->op,"_____");
		strcpy(q[quadlen]->arg2,"_____");
		
		 
	}
	else if(count == 5) //4: t0 = a + b
	{
		strcpy(q[quadlen]->res,splitwords[0]);
		strcpy(q[quadlen]->arg1,splitwords[2]);
		strcpy(q[quadlen]->arg2,splitwords[4]);
		strcpy(q[quadlen]->op,splitwords[3]);
	}
	else if(count == 4) //2: if t0 goto 4
	{
		strcpy(q[quadlen]->res,splitwords[3]);
		strcpy(q[quadlen]->arg1,splitwords[1]);
		strcpy(q[quadlen]->arg2,"_____");
		strcpy(q[quadlen]->op,splitwords[0]);
	}
	else if(count == 1)// 0: main:
	{
		
		strcpy(q[quadlen]->res,splitwords[0]);
		strcpy(q[quadlen]->op,"_____");
		strcpy(q[quadlen]->arg2,"_____");
		strcpy(q[quadlen]->arg1,"_____");
		
	}
	else if(count == 2)// 3: goto 8
	{
		strcpy(q[quadlen]->res,splitwords[1]);
		strcpy(q[quadlen]->op,splitwords[0]);
		strcpy(q[quadlen]->arg2,"_____");
		strcpy(q[quadlen]->arg1,"_____");	
	}
	quadlen++;


}


void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
	lhs->data_type = arg1->data_type;

	lhs->truelist = {nextinstr};
	lhs->falselist = {nextinstr + 1};

	std::string code;

	code = string("if ") + string(lhs->addr) + string(" goto _");
	gencode(code);

	code = string("goto _");
	gencode(code);
}

void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
}

void backpatch(vector<int>& v1, int number)
{
	for(int i = 0; i<v1.size(); i++)
	{
		string instruction = ICG[v1[i]];

		if(instruction.find("_") < instruction.size())
		{
			instruction.replace(instruction.find("_"),1,to_string(number));
			//instruction.replace(instruction.find("_"),1,arr);
			ICG[v1[i]] = instruction;
			//itoa(number,q[goto_place]->res,10);
			string x =to_string(number);
			char *temp = (char*)malloc(sizeof(char)*(x.length()+1));
			int i=0;
			while(i<x.length())
			{
				temp[i]=x[i];
				i++;
			}
			temp[i]='\0';
			char *lin = (char*)malloc(sizeof(char)*(instruction.length()+1));
			i=0;
			while(i<instruction.length())
			{
				if(instruction[i]==':')
				{
					break;
				}
				lin[i]=instruction[i];
				i++;
			}
			lin[i]='\0';
			int lin_no = atoi(lin);
			strcpy(q[lin_no]->res,temp);
		}
	}
}

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
	vector<int> concat;
	concat.reserve(v1.size() + v2.size());
	concat.insert(concat.end(), v1.begin(), v1.end());
	concat.insert(concat.end(), v2.begin(), v2.end());

	return concat;
}

void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

void displayICG()
{
	ofstream outfile("ICG.code");

	for(int i=0; i<ICG.size();i++)
	outfile << ICG[i] <<endl;

	outfile << nextinstr << ": exit";

	outfile.close();
	printf("\nQUADRUPLE FORMAT\n\n");
	print_dashes(40);
	printf("\t%s\t%s\t%s\t%s\n","op","arg1","arg2","res");
	print_dashes(40);
	for(int i=0;i<quadlen;i++)
	{
		printf("\t%s\t%s\t%s\t%s\n\n",q[i]->op,q[i]->arg1,q[i]->arg2,q[i]->res);
	}
}

void printlist(vector<int> v){
	for(auto it:v)
		cout<<it<<" ";
	cout<<"Next: "<<nextinstr<<endl;
}

int main(int argc, char *argv[])
{
	int i;
	 for(i=0; i<NUM_TABLES;i++)
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();
  	symbol_table_list[0].symbol_table = create_table();
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}

	printf("\nSYMBOL TABLES\n\n");
	display_all();
	printf("\nCONSTANT TABLE\n\n");
	display_constant_table(constant_table);
	
	displayICG();
	
	

}

void yyerror(const char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	
}
