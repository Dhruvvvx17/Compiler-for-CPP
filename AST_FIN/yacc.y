%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "symbol_table2.h"
	#include <stdarg.h>
	 
	 int yylex();

	entry_t** symbol_table;
	NODE* root;
	entry_t** symbol_table_stack[10]; 
	int tos = 0;

	double Evaluate (double lhs_value,int assign_type,double rhs_value);
	int current_dtype;
	int current_storage;
	int yyerror(char *msg);
	int yylineno;
	int DECL = 0;
%}

%union
{
	double dval;
	entry_t* entry;
	NODE* node;
	int ival;
}



 /* Constants //%token <dval> DEC_CONSTANT HEX_CONSTANT FLOAT_CONSTANT  */

%token <node> DEC_CONSTANT HEX_CONSTANT FLOAT_CONSTANT
%token <node> IDENTIFIER
%token <node> STRING

%token <node> HASH_INCL
%token <node> HASH_DEF
%token <node> HASH_INCL_END

%token <node> LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ

%token <node> MUL_EQ DIV_EQ MOD_EQ ADD_EQ SUB_EQ INPUT OUTPUT
%token <node> INCREMENT DECREMENT

%token <node> SHORT INT LONG SIGNED UNSIGNED CONST FLOAT

%token <node> IF FOR DO WHILE CONTINUE BREAK RETURN CIN COUT

%type <node> complete_program headerFilesMacros FilesMacros headerFiles ID_HI headerMacros ID_ME macroExpr main_program block 
%type <node> function type pointer data_type sign_specifier type_specifier argument_list arguments arg
%type <node> statement statements compound_statement single_statement 
%type <node> ifBlock forBlock whileBlock input_st output_st
%type <node> declaration dl_de decl_end declarationList subDecl
%type <node> expression_statement expression subExpr assignmentExpr unaryExpr arithmeticExpr lhs function_call

%type <node> constant array_index parameter_list
%type <node> assignOp

%start complete_program

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
%nonassoc ELSEIF
%nonassoc ELSE



%%

  /* Complete_program is made up of headerFilesMacros followed by main_program. */

complete_program:headerFilesMacros main_program		{$$ = newnode("Complete program", 0, 2, $1, $2); root = $$;}
		;
headerFilesMacros:headerFilesMacros FilesMacros		{$$ = newnode("headerFilesMacros", 0, 2, $1, $2);}
		 |					{$$ = newnode("headerFilesMacros -> epsilon", 0, 2, NULL, NULL);}	
		 ;
FilesMacros:headerFiles					{$$ = $1;}
	   |headerMacros				{$$ = $1;}
	   ;
//headerFiles:HASH_INCL IDENTIFIER HASH_INCL_END {$$ = newnode("Seq", 0, 2, )}
headerFiles:HASH_INCL ID_HI				{$$ = newnode("headerFiles", 0, 2, $1, $2);}
	   ;
ID_HI:IDENTIFIER HASH_INCL_END				{$$ = newnode("ID_HASH", 0, 2, $1, $2);}
	;

headerMacros:HASH_DEF ID_ME 				{$$ = newnode("headerMacros", 0, 2, $1, $2);}
	   ;
ID_ME: IDENTIFIER macroExpr				{$$ = newnode("ID_MACRO", 0, 2, $1, $2);}
	;

macroExpr : IDENTIFIER					{$$ = $1;}
	| constant					{$$ = $1;}
	| '(' subExpr ')'				{$$ = $2;}
	;

main_program: main_program block			{$$ = newnode("main_program", 0, 2, $1, $2);}
	 |block						{$$ = $1;}
	 ;

 /* Each block is either a function or a declaration */
block: function						{$$ = $1;}
     | declaration					{$$ = $1;}
     ;

 /* This is how a function looks like */
function: type IDENTIFIER '(' argument_list ')' compound_statement {$$ = newnode("function", 0, 2, $4, $6);}
	;

 /* Now we will define a grammar for how types can be specified */

//todo----------------------
type :data_type pointer					{}
    | data_type						{$$ = $1;}
    //|error	{$$ = $1;}
    ;

pointer: '*' pointer					{$$ = newnode("pointer_star", 0, 2, $2, NULL);}
    |'*'						{$$ = newnode("pointer_star", 1, 1, "*");}
    ;

data_type :sign_specifier type_specifier		{$$ = newnode("data_type", 0, 2, $1, $2);}
    |type_specifier					{$$ = $1;}
    ;

//to do -----------------
sign_specifier :SIGNED					{$$ = newnode("signed", 0, 2, NULL, NULL);}
    |UNSIGNED						{$$ = newnode("unsigned", 0, 2, NULL, NULL);}
    ;

type_specifier :INT                    {DECL = 1;current_dtype = 1;current_storage=4; $$ = newnode("int", 0, 2, NULL, NULL);}
    |SHORT INT                         {DECL = 1;current_dtype = 2;current_storage=2; $$ = newnode("short int", 0, 2, NULL, NULL);}
    |SHORT                             {DECL = 1;current_dtype = 2;current_storage=2; $$ = newnode("short", 0, 2, NULL, NULL);}
    |LONG                              {DECL = 1;current_dtype = 3;current_storage=8; $$ = newnode("long", 0, 2, NULL, NULL);}
    |LONG INT                          {DECL = 1;current_dtype = 3;current_storage=8; $$ = newnode("long int", 0, 2, NULL, NULL);}
    |FLOAT			       {DECL = 1;current_dtype = 4;current_storage=4; $$ = newnode("float", 0, 2, NULL, NULL);}
    ;

 /* grammar rules for argument list */
 /* argument list can be empty */
argument_list :arguments 				{$$ = $1;}
    |							{$$ = newnode("argument list -> is empty", 0, 2, NULL, NULL);}
    ;
 /* arguments are comma separated TYPE ID pairs */
arguments :arguments ',' arg				{$$ = newnode("arguments", 0, 2, $1, $3);}
    |arg						{$$ = $1;}
    ;

 /* Each arg is a TYPE ID pair */
arg :type IDENTIFIER					{$$ = newnode("arg", 0, 2, $1, $2);}
   ;

 /* Generic statement. Can be compound or a single statement */
statement:compound_statement				{$$ = $1;}
    |single_statement 					{$$ = $1; }
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_statement :'{' statements '}' 			{$$ = $2;}
    ;

statements:statements statement 			{$$ = newnode("statements", 0, 2, $1, $2);}
    | 							{$$ = newnode("statements -> epsilon", 0, 2, NULL, NULL);}
    ;

 /* Grammar for what constitutes every individual statement */
single_statement :ifBlock				{$$ = $1;}
    |whileBlock 					{$$ = $1;}
    |forBlock						{$$ = $1;}
    |declaration					{$$ = $1;}
    |function_call ';' 					{$$ = $1;}
	|input_st					{$$ = $1;}
	|output_st					{$$ = $1;}
	|RETURN ';'					{$$ = newnode("single_statement", 0, 2, NULL, NULL);}
	|CONTINUE ';'					{$$ = newnode("single_statement", 0, 2, NULL, NULL);}
	|BREAK ';'					{$$ = newnode("single_statement", 0, 2, NULL, NULL);}
	|RETURN subExpr ';'				{$$ = newnode("single_statement", 0, 2, NULL, $2);}
    ;

input_st: 	CIN INPUT STRING ';'		{$$ = newnode("CIN", 1, 1,$3);}
	;
output_st:	COUT OUTPUT STRING ';'			{$$ = newnode("COUT", 1, 1,$3);}
	;
ifBlock:	IF '(' expression ')' statement %prec ELSEIF 	{$$ = newnode("if", 0, 2, $3, $5);}
		|IF '(' expression ')' statement ELSE statement {$$ = newnode("if", 0, 2, $3, $5);}
		 ;

forBlock:FOR '(' expression_statement  expression_statement ')' statement  		{$$ = newnode("for", 0, 2, $3, $6);}
    |FOR '(' expression_statement expression_statement expression ')' statement 	{$$ = newnode("for", 0, 2, $3, $7);}
    |FOR '(' type declarationList ';' expression_statement expression ')' statement 	{$$ = newnode("for", 0, 2, $3, $9);}
    ;

whileBlock: WHILE '(' expression ')' statement {$$ = newnode("while", 0, 2, $3, $5);}
		;

declaration: type dl_de			{$$ = newnode("declaration", 0, 2, $1, $2);}
	   | declarationList ';'	{$$ = $1;}
	   | unaryExpr ';'		{$$ = $1;}
	   //| error ';'
	   ;

dl_de: declarationList decl_end			{$$ = newnode("dl_de", 0, 2, $1, $2);}
	;

decl_end: ';'					{DECL = 0; $$ = newnode("decl_end", 0, 2, NULL, NULL);} //????
			;

declarationList: declarationList ',' subDecl	{$$ = newnode("declarationList", 0, 2, $1, $3);}
		|subDecl			{$$ = $1;}
		;

subDecl: assignmentExpr {$$ = $1;}
    |IDENTIFIER  {
    			$$ = $1;
    			$1->symtab_entry->data_type = current_dtype;
    			$1->symtab_entry->storage = current_storage;
    			if(! $1->symtab_entry->line_no)
    				$1->symtab_entry->line_no = yylineno;
    		}
    |array_index {$$ = $1;}
    ;


expression_statement: expression ';'	{$$ = $1;}
    |';'				{$$ = newnode(";", 0, 2, NULL, NULL);}
    ;

expression: expression ',' subExpr			
    |subExpr		                        
    ;

subExpr:
    subExpr '>' subExpr			{$$ = newnode(">", 0, 2, $1, $3);}	
    |subExpr '<' subExpr		{$$ = newnode("<", 0, 2, $1, $3);}
    |subExpr EQ subExpr			{$$ = newnode("==", 0, 2, $1, $3);}
    |subExpr NOT_EQ subExpr             {$$ = newnode("!=", 0, 2, $1, $3);}  	
    |subExpr LS_EQ subExpr              {$$ = newnode("<=", 0, 2, $1, $3);}  	
    |subExpr GR_EQ subExpr              {$$ = newnode(">=", 0, 2, $1, $3);}  	
    |subExpr LOGICAL_AND subExpr        {$$ = newnode("&&", 0, 2, $1, $3);}  	
    |subExpr LOGICAL_OR subExpr         {$$ = newnode("||", 0, 2, $1, $3);}  	
    |'!' subExpr			{$$ = newnode("!", 0, 2, $2, NULL);}
    |arithmeticExpr			{$$ = $1;}
    |assignmentExpr                     {$$ = $1;}
    |unaryExpr                          {$$ = $1;}
    ;


assignmentExpr :lhs assignOp arithmeticExpr     
    |lhs assignOp array_index                   
    |lhs assignOp function_call                 
    |lhs assignOp unaryExpr                     
    |unaryExpr assignOp unaryExpr         
    ;

/* $1 here refers to the identifier for which an entry in the symbol table has already been created */
unaryExpr:	lhs INCREMENT                          
	|lhs DECREMENT                                 
	|DECREMENT lhs                  {$$ = newnode("--", 0, 2, $2, NULL);}               
	|INCREMENT lhs     		{$$ = newnode("++", 0, 2, $2, NULL);}
	;

lhs:IDENTIFIER 				{
						if(! $1->symtab_entry->data_type) {
							$1->symtab_entry->data_type = current_dtype;
							$1->symtab_entry->storage = current_storage;
						} 
						if(! $1->symtab_entry->line_no) 
							$1->symtab_entry->line_no = yylineno;
						$$ = $1;
					}

    ;

assignOp:'='				{$$ = newnode("=", 0, 2, NULL, NULL);}                                  
    |ADD_EQ                		{$$ = newnode("+=", 0, 2, NULL, NULL);}
    |SUB_EQ                             {$$ = newnode("-=", 0, 2, NULL, NULL);}
    |MUL_EQ                             {$$ = newnode("*=", 0, 2, NULL, NULL);}       
    |DIV_EQ                             {$$ = newnode("/=", 0, 2, NULL, NULL);}       
    |MOD_EQ                             {$$ = newnode("%=", 0, 2, NULL, NULL);} 
    ;

arithmeticExpr: arithmeticExpr '+' arithmeticExpr     
    |arithmeticExpr '-' arithmeticExpr                
    |arithmeticExpr '*' arithmeticExpr                
    |arithmeticExpr '/' arithmeticExpr               
	|arithmeticExpr '%' arithmeticExpr            
	|'(' arithmeticExpr ')'         {$$ = $2;}              
    |'-' arithmeticExpr %prec UMINUS	{$$ = $2;}
    |IDENTIFIER                         {$$ = $1;}
    |constant				{$$ = $1;}
    ;

constant: DEC_CONSTANT			{$$ = $1;}
    |HEX_CONSTANT			{$$ = $1;}
    |FLOAT_CONSTANT			{$$ = $1;}
    ;

array_index: IDENTIFIER '[' subExpr ']'	
;

function_call: IDENTIFIER '(' parameter_list ')'
             |IDENTIFIER '(' ')'
             ;

parameter_list:parameter_list ','  parameter {}
              |parameter {}
              ;

parameter: subExpr 
	   |STRING

        ;
%%

#include "lex.yy.c"
#include <ctype.h>


double Evaluate (double lhs_value,int operator,double rhs_value)
{
	switch(operator)
	{
		case '=': return rhs_value;
		case ADD_EQ: return (lhs_value + rhs_value);
		case SUB_EQ: return (lhs_value - rhs_value);
		case MUL_EQ: return (lhs_value * rhs_value);
		case DIV_EQ: return (lhs_value / rhs_value);
		case MOD_EQ: return ((int)lhs_value % (int)rhs_value);
	}
}

int main(int argc, char *argv[])
{
	symbol_table = create_table(); //creating empty symbol table and initialising
	symbol_table_stack[0] = symbol_table;

	yyin = fopen("inp1.cpp", "r");

	if(!yyparse())
	{
		//printf("\nParsing complete\n");
	}
	else
	{
		printf("\nParsing FAILED\n");
		fclose(yyin);
		return 0;
	}

	
	//display(symbol_table, 0);
	
	printf("\nParsing complete\n");
	preorder(root);
	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
}
