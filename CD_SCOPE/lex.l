%{

#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <limits.h>
#include "y.tab.h"

int comment_count = 0;
int flag = 1;

%}

hash_incl	#include<
hash_def	#define
hash_incl_end	\.h>

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

opt_frac (\.{digit}+)?
opt_exp ([Ee][+-]?{digit}+)?

			
%%
  /* Keywords*/

"int"                             {return INT;}
"long"                            {return LONG;}
"short"                           {return SHORT;}
"signed"                          {return SIGNED;}
"unsigned"                        {return UNSIGNED;}
"for"                             {entry_t** symbol_table = create_table();
				symbol_table_stack[tos+1] = symbol_table; 
				tos++; 
				flag = 0;
				return FOR;}
"cout"                          {return COUT;}
"cin"                           {return CIN;}
"while"                           {return WHILE;}
"do"				                      {return DO;}
"break"                           {return BREAK;}
"continue"                        {return CONTINUE;}
"if"                              {return IF;}
"else"                            {return ELSE;}
"return"                          {return RETURN;}
"float" 			                    {return FLOAT;}


{identifier}                      {yylval.entry = insert(symbol_table_stack, tos, yytext, INT_MIN, DECL); return  IDENTIFIER;}//by default INT_MIN value will be stored
{ws}                              ;

{digit}+{opt_frac}{opt_exp}	   {yylval.dval = atof(yytext); return FLOAT_CONSTANT;}
[+\-]?[0][x|X]{hex}+[lLuU]?        { yylval.dval = (int)strtol(yytext, NULL, 16); return  HEX_CONSTANT;}//string to long integer
[+\-]?{digit}+[lLuU]?              {yylval.dval = atoi(yytext); return  DEC_CONSTANT;}


\/\/(.*)[\n] {comment_count++;}
\/\*([^*]|\*+[^/])*\*+\/ {comment_count++;}

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was escaped */
    yymore();
  }
  else{
  
  return STRING;
  }
 }

\n                              {yylineno++;}

">>"				{return OUTPUT;}
"<<"				{return INPUT;}
"--"			                {return DECREMENT;}
"++"			                {return INCREMENT;}
"+="                      {return ADD_EQ;}
"-="                      {return SUB_EQ;}
"*="                      {return MUL_EQ;}
"/="                      {return DIV_EQ;}
"%="                      {return MOD_EQ;}


"&&"			                {return LOGICAL_AND;}
"||"			                {return LOGICAL_OR;}
"<="			                {return LS_EQ;}
">="			                {return GR_EQ;}
"=="			                {return EQ;}
"!="		                  {return NOT_EQ;}

"{"			{
	if (flag) {
	entry_t** symbol_table = create_table();
	symbol_table_stack[tos+1] = symbol_table; 
	tos++; }
	else {flag = 1;}
	//printf("begin---- %d\n", tos);
	 return yytext[0];}
"}"		{
	display(symbol_table_stack[tos], tos);
	//printf("end---- %d\n", tos); 
	tos--; 
	return yytext[0];}
.                         {return yytext[0];}

%%

