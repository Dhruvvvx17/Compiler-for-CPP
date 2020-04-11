%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "symbol_table.h"
	 
	 int yylex();

	entry_t** symbol_table;
	
	entry_t** symbol_table_stack[10]; 
	int tos = 0;

	double Evaluate (double lhs_value,int assign_type,double rhs_value);
	int current_dtype;
	int yyerror(char *msg);
	int DECL = 0;
%}

%union
{
	double dval;
	entry_t* entry;
	int ival;
}

%token <entry> IDENTIFIER

 /* Constants */
%token <dval> DEC_CONSTANT HEX_CONSTANT FLOAT_CONSTANT
%token STRING


 /* Logical and Relational operators */
%token OUTPUT INPUT LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ

 /* Short hand assignment operators */
%token MUL_EQ DIV_EQ MOD_EQ ADD_EQ SUB_EQ
%token INCREMENT DECREMENT

 /* Data types */
%token SHORT INT LONG SIGNED UNSIGNED CONST FLOAT

 /* Keywords */
%token IF FOR DO WHILE CONTINUE BREAK RETURN COUT CIN

%type <dval> expression
%type <dval> subExpr
%type <dval> constant
%type <dval> unaryExpr
%type <dval> arithmeticExpr
%type <dval> assignmentExpr
%type <entry> lhs
%type <ival> assignOp

%start main_program

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

main_program: main_program block
	 |block;

 /* Each block is either a function or a declaration */
block: function|
       declaration;

 /* This is how a function looks like */
function: type IDENTIFIER '(' argument_list ')' compound_statement;

 /* Now we will define a grammar for how types can be specified */

type :data_type pointer
    |data_type
    ;

pointer: '*' pointer
    |'*'
    ;

data_type :sign_specifier type_specifier
    |type_specifier
    ;

sign_specifier :SIGNED
    |UNSIGNED
    ;

type_specifier :INT                    {DECL = 1;current_dtype = 1;}
    |SHORT INT                         {DECL = 1;current_dtype = 2;}
    |SHORT                             {DECL = 1;current_dtype = 2;}
    |LONG                              {DECL = 1;current_dtype = 3;}
    |LONG INT                          {DECL = 1;current_dtype = 3;}
    |FLOAT			       {DECL = 1;current_dtype = 4;}
    ;

 /* grammar rules for argument list */
 /* argument list can be empty */
argument_list :arguments
    |
    ;
 /* arguments are comma separated TYPE ID pairs */
arguments :arguments ',' arg
    |arg
    ;

 /* Each arg is a TYPE ID pair */
arg :type IDENTIFIER
   ;

 /* Generic statement. Can be compound or a single statement */
statement:compound_statement
    |single_statement
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_statement :'{' statements '}'
    ;

statements:statements statement
    |
    ;

 /* Grammar for what constitutes every individual statement */
single_statement :ifBlock
    |whileBlock
    |forBlock
    |declaration
    |function_call ';'
	|RETURN ';'
	|CONTINUE ';'
	|BREAK ';'
	|RETURN subExpr ';'
	|cout_statement ';'
	|cin_statement ';'
	|error
    ;

cout_statement: COUT OUTPUT STRING 
;

cin_statement: CIN INPUT STRING
;

ifBlock:	IF '(' expression ')' statement %prec ELSEIF
		|IF '(' expression ')' statement ELSE statement
		 ;

forBlock:FOR '(' expression_statement  expression_statement ')' statement
    |FOR '(' expression_statement expression_statement expression ')' statement
    |FOR '(' type declarationList ';' expression_statement expression ')' statement
    ;

whileBlock: WHILE '(' expression	')' statement
		;

declaration:		type declarationList decl_end 
			 | declarationList ';'
			 | unaryExpr ';'
			 ;

decl_end: ';'  {DECL = 0;}
			;

declarationList: declarationList ',' subDecl
		|subDecl;

subDecl: assignmentExpr
    |IDENTIFIER                     {$1 -> data_type = current_dtype;}
    |array_index
    ;


expression_statement:expression ';'
    |';'
    ;

expression:
    expression ',' subExpr								{$$ = $1,$3;}
    |subExpr		                                    {$$ = $1;}	
    ;

subExpr:
    subExpr '>' subExpr				{$$ = ($1 > $3);}
    |subExpr '<' subExpr			{$$ = ($1 < $3);}
    |subExpr EQ subExpr				{$$ = ($1 == $3);}
    |subExpr NOT_EQ subExpr               	{$$ = ($1 != $3);}
    |subExpr LS_EQ subExpr                	{$$ = ($1 <= $3);}
    |subExpr GR_EQ subExpr                	{$$ = ($1 >= $3);}
    |subExpr LOGICAL_AND subExpr          	{$$ = ($1 && $3);}
    |subExpr LOGICAL_OR subExpr           	{$$ = ($1 || $3);}
    |'!' subExpr                          	{$$ = (!$2);}
    |arithmeticExpr			  	{$$ = $1;}
    |assignmentExpr                       	{$$ = $1;}
    |unaryExpr                            	{$$ = $1;}
    ;


assignmentExpr :lhs assignOp arithmeticExpr     {$$ = $1->value = Evaluate($1->value,$2,$3);}
    |lhs assignOp array_index                   {$$ = 0;}
    |lhs assignOp function_call                 {$$ = 0;}
    |lhs assignOp unaryExpr                     {$$ = $1->value = Evaluate($1->value,$2,$3);}
    |unaryExpr assignOp unaryExpr               {$$ = 0;}
    ;

/* $1 here refers to the identifier for which an entry in the symbol table has already been created */
unaryExpr:	lhs INCREMENT                          {$$ = $1->value = ($1->value)++;}
	|lhs DECREMENT                                 {$$ = $1->value = ($1->value)--;}
	|DECREMENT lhs                                 {$$ = $2->value = --($2->value);}
	|INCREMENT lhs                                 {$$ = $2->value = ++($2->value);}
	;

lhs:IDENTIFIER                                     {$$ = $1; if(! $1->data_type) $1->data_type = current_dtype;}

    ;

assignOp:'='                                      {$$ = '=';}
    |ADD_EQ                                    {$$ = ADD_EQ;}
    |SUB_EQ                                    {$$ = SUB_EQ;}
    |MUL_EQ                                    {$$ = MUL_EQ;}
    |DIV_EQ                                    {$$ = DIV_EQ;}
    |MOD_EQ                                    {$$ = MOD_EQ;}
    ;

arithmeticExpr: arithmeticExpr '+' arithmeticExpr    {$$ = $1 + $3;}
    |arithmeticExpr '-' arithmeticExpr                {$$ = $1 - $3;}
    |arithmeticExpr '*' arithmeticExpr                {$$ = $1 * $3;}
    |arithmeticExpr '/' arithmeticExpr                {$$ = ($3 == 0) ? yyerror("Divide by 0!") : ($1 / $3);}
	|arithmeticExpr '%' arithmeticExpr                {$$ = (int)$1 % (int)$3;}
	|'(' arithmeticExpr ')'                            {$$ = $2;}
    |'-' arithmeticExpr %prec UMINUS                   {$$ = -$2;}
    |IDENTIFIER                                         {$$ = $1 -> value;}
    |constant                                           {$$ = $1;}
    ;

constant: DEC_CONSTANT                                  {$$ = $1;}
    |HEX_CONSTANT                                       {$$ = $1;}
    |FLOAT_CONSTANT				        {$$ = $1;}
    ;

array_index: IDENTIFIER '[' subExpr ']'
;

function_call: IDENTIFIER '(' parameter_list ')'
             |IDENTIFIER '(' ')'
             ;

parameter_list:
              parameter_list ','  parameter
              |parameter
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

	yyin = fopen("inp_error.cpp", "r");

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


	//printf("\n\tSymbol table");
	display(symbol_table, 0);
	
	printf("\nParsing complete\n");

	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
}
