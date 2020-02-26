%{

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <limits.h>

#define SIZE 100

//Symbol table 
typedef struct symbolTable{
	char id_name[32];
	char datatype[8];
	char value[8];
	int scope;
	int *lineNumber;
	int occurances;
}symbolTable;

symbolTable symboltable[SIZE];

void init(){
	for(int i=0;i<SIZE;i++){
		symboltable[i].occurances = 0;
	}
}

void init();
void installID(char *idName,int lineNo,int scope);	//function declaration

int scope = 0;			//global variable for scope
int st_index = -1;		//global variable for identifiers' index in symbol table
int parenthesis_match = 0;
int braces_match = 0;
int square_match = 0;

%}

%option yylineno

%%

"main"			{printf("Keyword - main\n");}
"int"			{printf("Keyword - int\n");}
"float"			{printf("Keyword - float\n");}
"char"			{printf("Keyword - char\n");}
"do"			{printf("Keyword - do\n");}
"while"			{printf("Keyword - while\n");}
"for"			{printf("Keyword - for\n");}
"if"			{printf("Keyword - if\n");}
"else"			{printf("Keyword - else\n");}
"cin"			{printf("Keyword - cin\n");}
"cout"			{printf("Keyword - cout\n");}
"return"		{printf("Keyword - return\n");}
"bool"			{printf("Keyword - bool\n");}
"break"			{printf("Keyword - break\n");}
"continue"		{printf("Keyword - continue\n");}

(_|[a-zA-Z])([a-zA-Z]|[0-9]|_){0,31}	{printf("Identifier\n");installID(yytext,yylineno,scope);}

[0-9]+				{printf("Constant - Number\n");}
["]([^\\\n]|\\.|\\\n)*["]	{printf("Literal - String\n");}

"{"				{printf("Symbol - Opening brace\n");++scope;}
"}"				{printf("Symbol - Closing brace\n");--scope;}
"("				{printf("Symbol - Opening parenthesis\n");}
")"				{printf("Symbol - Closing parenthesis\n");}
";"				{printf("Symbol - Semicolon\n");}
","				{printf("Symbol - Comma\n");}
">>"				{printf("Symbol - Input Stream\n");}
"<<"				{printf("Symbol - Output Stream\n");}

"++"				{printf("Operator - Unary - Increment\n");}
"--"				{printf("Operator - Unary - Decrement\n");}
"+"|"-"|"*"|"/"|"%"		{printf("Operator - Arithmetic\n");}
"&"|"|"|"^"			{printf("Operator - Bitwise\n");}
"+="|"-="|"*="|"/="|"%="	{printf("Operator - Shorthand\n");}
"="				{printf("Operator - Assignment\n");}
"&&"|"||"|"!"			{printf("Operator - Logical\n");}
"<="|"<"|">="|">"|"=="		{printf("Operator - Relational\n");}

\/\/(.*)[\n]*			;
\/\*(.*[\n]*)*\*\/[\n]*		;
[\n]*				;
[\t]*				;
[" "]				;

.				{printf("Error occured at line number: %d\n",yylineno);}

%%

void installID(char *id_name,int lineNumber,int scope){
	
	if(st_index<0){
		int i = ++st_index;	
		strcpy(symboltable[i].id_name,id_name);
		symboltable[i].scope = scope;
		symboltable[i].lineNumber = (int*)malloc(sizeof(int)*(1+symboltable[i].occurances));
		symboltable[i].lineNumber[symboltable[i].occurances] = lineNumber;	
		symboltable[i].occurances++;
		return;
	}
	int check = 0;
	int j = 0,k;
	for(j = 0;j<=st_index;j++){
	//check if id_name with same name exists and same scope, if not add as new entry
		if(strcmp(id_name,symboltable[j].id_name)==0 && scope==symboltable[j].scope && !check){
			check = 1;
			k = j;			
		}	
	}
	if(!check){
		int i = ++st_index;	
		strcpy(symboltable[i].id_name,id_name);
		symboltable[i].scope = scope;
		symboltable[i].lineNumber = (int*)realloc(symboltable[i].lineNumber,sizeof(int)*(1+symboltable[i].occurances));		
		symboltable[i].lineNumber[symboltable[i].occurances] = lineNumber;	
		symboltable[i].occurances++;
		return;	
	}
	symboltable[k].lineNumber = (int*)realloc(symboltable[k].lineNumber,sizeof(int)*(1+symboltable[k].occurances));		
	symboltable[k].lineNumber[symboltable[k].occurances] = lineNumber;	
	symboltable[k].occurances++;
}

void displayST(){
	
	printf("\n\n-------SYMBOL TABLE-------\n");
	printf("--------------------------\n");	
	printf("Name\tScope\tLine No.\n");
	for(int i = 0;i<=st_index;i++){
		printf("%s\t%d\t",symboltable[i].id_name,symboltable[i].scope);
		for (int j = 0;j<symboltable[i].occurances;j++){
			if(j == symboltable[i].occurances-1){
				printf("%d",symboltable[i].lineNumber[j]);	
			}
			else
				printf("%d,",symboltable[i].lineNumber[j]);
		}
		printf("\n");
	
	}
	printf("--------------------------\n");
}

int main(){
	init();
	yylex();
	displayST();	

	return 0;	
}

