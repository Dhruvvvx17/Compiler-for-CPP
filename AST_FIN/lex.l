%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "y.tab.h"
#include <stdarg.h>

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

{hash_incl}			  {return HASH_INCL;}
{hash_incl_end}			  {return HASH_INCL_END;}
{hash_def}			  {return HASH_DEF;}
"int"                             {return INT;}
"long"                            {return LONG;}
"short"                           {return SHORT;}
"signed"                          {return SIGNED;}
"unsigned"                        {return UNSIGNED;}
"for"                             {
	entry_t** symbol_table = create_table();
	symbol_table_stack[tos+1] = symbol_table; 
	tos++; 
	flag = 0;
	return FOR;}
"while"                           {return WHILE;}
"do"				  {return DO;}
"break"                           {return BREAK;}
"continue"                        {return CONTINUE;}
"if"                              {return IF;}
"else"                            {return ELSE;}
"return"                          {return RETURN;}
"float" 			  {return FLOAT;}
"cin"				{return CIN;}
"cout"				{return COUT;}

{identifier}                       {
					//printf("Creating node for identifier %s\n", yytext);
					yylval.node = newnode("ID", 1, 1, insert(symbol_table_stack, tos, yytext, INT_MIN, DECL));
					return IDENTIFIER;
				   }

{ws}                               ;

[+\-]?{digit}+[lLuU]?              {
					//printf("Creating node for dec constant %s\n", yytext);
					yylval.node = newnode("Number", 1, 1, atoi(yytext));
					return  DEC_CONSTANT;
				   }

{digit}+{opt_frac}{opt_exp}	   {
					//printf("Creating node for float constant%s\n", yytext);
					yylval.node = newnode("Number", 1, 1, atof(yytext));
					return FLOAT_CONSTANT;
				   }

[+\-]?[0][x|X]{hex}+[lLuU]?        {	
					//printf("Creating node for hex %s\n", yytext);
					yylval.node = newnode("Number", 1, 1, (int)strtol(yytext, NULL, 16));
					return  HEX_CONSTANT;
				   }




\/\/(.*)[\n] {comment_count++;}
\/\*([^*]|\*+[^/])*\*+\/ {comment_count++;}

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was escaped */
    yymore();
  }
  else{
  yylval.node = newnode("STRING", 1, 1, yytext);
  return STRING;
  }
 }

\n                              {yylineno++;}

">>"				{return INPUT;}
"<<"				{return OUTPUT;}
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
	//display(symbol_table_stack[tos], tos);
	//printf("end---- %d\n", tos); 
	tos--; 
	return yytext[0];}
.                         {return yytext[0];}

%%

