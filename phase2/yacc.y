%{
	#include <stdlib.h>
	#include <stdio.h>
	int yyerror(char *msg);

	#include "symbolTable.h"
	#include "y.tab.h"
	#include "lex.yy.c"

	#define SYMBOL_TABLE symbolTableCollection[currentScope].symbolTable

	symbolTable_Collection symbolTableCollection[SCOPE_RANGE];

	int current_dtype;
	int p = 0;
	int is_loop = 0;
	int is_declaration = 0;
	int rhs = 1;

%}

%union
{
	int data_type;
	symbolTableEntry* entry;
}

%token <entry> IDENTIFIER

 /* Constants */
%token DEC_CONSTANT HEX_CONSTANT CHAR_CONSTANT FLOAT_CONSTANT
%token STRING

 /* Logical and Relational operators */
%token LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ

 /* Short hand assignment operators */
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token INCREMENT DECREMENT

 /* Data types */
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST VOID CHAR FLOAT

 /* Keywords */
%token IF FOR WHILE CONTINUE BREAK RETURN

%type <entry> identifier
//%type <entry> array_index

%type <data_type> sub_expr
%type <data_type> unary_expr
%type <data_type> arithmetic_expr
%type <data_type> assignment_expr
//%type <data_type> lhs

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
program : program builder
	| builder
	;

/* Each builder block is either a function or a declaration */
builder : declaration
	;


/* Now we will define a grammar for how types can be specified */
type : data_type pointer
     | data_type
     ;

pointer : '*' pointer
    	| '*'
        ;

data_type : sign_specifier type_specifier
    	  | type_specifier
    	  ;

sign_specifier : SIGNED
    	       | UNSIGNED
    	       ;

type_specifier : INT                    {current_dtype = INT;}
	       |SHORT INT               {current_dtype = SHORT;}
	       |SHORT                   {current_dtype = SHORT;}
	       |LONG                    {current_dtype = LONG;}
	       |LONG INT                {current_dtype = LONG;}
    	       |LONG_LONG               {current_dtype = LONG_LONG;}
    	       |LONG_LONG INT           {current_dtype = LONG_LONG;}
	       |CHAR 			{current_dtype = CHAR;}
	       |FLOAT 			{current_dtype = FLOAT;}
	       |VOID			{current_dtype = VOID;}
    	       ;


// statements throughout the code (single or compounds)
statements : statements stmt
	   |
	   ;

 /* Generic statement. Can be compound or a single statement */
stmt : compound_stmt
     | single_stmt
     ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt : '{' 	{ if(!p)currentScope = createNewScope();
				else p = 0;
			}
		statements
		'}' 	{currentScope = exitScope();}
    	      ;



 /* Grammar for what constitutes every individual statement */
single_stmt : if_block
    	    | for_block
	    | while_block
	    | declaration
	    | CONTINUE ';'		{	if(!is_loop) {yyerror("Illegal use of continue");}	}
	    | BREAK ';'          	{	if(!is_loop) {yyerror("Illegal use of break");}		}
    	    ;

for_block : FOR '(' expression_stmt  expression_stmt ')' 	{ is_loop = 1; } stmt {is_loop = 0;}
    	  | FOR '(' expression_stmt expression_stmt expression ')' {is_loop = 1;} stmt {is_loop = 0;}
    	  ;

if_block : IF '(' expression ')' stmt 			%prec LOWER_THAN_ELSE
	 | IF '(' expression ')' stmt ELSE stmt
    	 ;

while_block : WHILE '(' expression ')' {is_loop = 1;} stmt {is_loop = 0;}
	    ;

declaration : type declaration_list ';'	{ is_declaration = 0; }
	    | declaration_list ';'
	    | unary_expr ';'
	    ;

declaration_list : declaration_list ',' sub_decl
		 | sub_decl
    		 ;

sub_decl : assignment_expr
    	 | identifier
    	 ;			;

/* This is because we can have empty expession statements inside for loops */
expression_stmt : expression ';'
    	        | ';'
 		;

expression : expression ',' sub_expr
    	   | sub_expr
	   ;				

sub_expr : sub_expr '>' sub_expr		{ $$ = $1;}
	 | sub_expr '<' sub_expr		{ $$ = $1;}
	 | sub_expr EQ sub_expr		        { $$ = $1;}
	 | sub_expr NOT_EQ sub_expr   	        { $$ = $1;}
	 | sub_expr LS_EQ sub_expr		{ $$ = $1;}
	 | sub_expr GR_EQ sub_expr		{ $$ = $1;}
	 | sub_expr LOGICAL_AND sub_expr	{ $$ = $1;}
	 | sub_expr LOGICAL_OR sub_expr	        { $$ = $1;}    		    
	 | '!'sub_expr				{ $$ = $2;}
	 | arithmetic_expr			{ $$ = $1;}          
	 | assignment_expr			{ $$ = $1;}
	 | unary_expr				{ $$ = $1;}
         ;


assignment_expr : lhs assign_op  arithmetic_expr		{ rhs=0; }
		| lhs assign_op  unary_expr                     { rhs=0; }
		| unary_expr assign_op  unary_expr		{ rhs=0; }
    		;

unary_expr : identifier INCREMENT	
	   | identifier DECREMENT	
	   | DECREMENT identifier	
	   | INCREMENT identifier
	   ;

lhs : identifier
    ;

identifier : IDENTIFIER    {	if(is_declaration && !rhs) {
                                	$1 = insertEntry(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                                        if($1 == NULL) yyerror("Redeclaration of variable");
                                }
                                else {
                                        $1 = searchAcrossTables(yytext);
	                                if($1 == NULL) yyerror("Variable not declared");
                                }
	                        $$ = $1;
                            }
    	  ;

assign_op : '=' {rhs=1;}
    |ADD_ASSIGN {rhs=1;} 
    |SUB_ASSIGN {rhs=1;}
    |MUL_ASSIGN {rhs=1;}
    |DIV_ASSIGN {rhs=1;}
    |MOD_ASSIGN {rhs=1;}
    ;

arithmetic_expr : arithmetic_expr '+' arithmetic_expr		
    		| arithmetic_expr '-' arithmetic_expr		
    		| arithmetic_expr '*' arithmetic_expr										
    		| arithmetic_expr '/' arithmetic_expr										
		| arithmetic_expr '%' arithmetic_expr										
		| '(' arithmetic_expr')'			
		| '-' arithmetic_expr %prec UMINUS
	        | identifier			{$$ = $1->dataType;}
	        ;



%%

int main(int argc, char *argv[]) {
	for(int i=0; i<SCOPE_RANGE;i++){
		symbolTableCollection[i].symbolTable = NULL;
		symbolTableCollection[i].parent = -1;
	 }

	symbolTableCollection[0].symbolTable = createTable();
	yyin = fopen(argv[1], "r");

	if(!yyparse()){
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else{
		printf("\nPARSING FAILED!\n\n\n");
	}

	printf("SYMBOL TABLES\n\n");
	//display_all();

	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
