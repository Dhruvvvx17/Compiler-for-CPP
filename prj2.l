%{

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "y.tab.h"

int cmnt_strt = 0;

%}

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

 /* Exclusive states */
%x CMNT
 /*%x PREPROC*/

%%
  /* Keywords*/
"int"                             {return INT;}
"long"                            {return LONG;}
"long long"                       {return LONG_LONG;}
"short"                           {return SHORT;}
"signed"                          {return SIGNED;}
"unsigned"                        {return UNSIGNED;}
"for"                             {return FOR;}
"while"                           {return WHILE;}
"do"				  {return DO;}
"break"                           {return BREAK;}
"continue"                        {return CONTINUE;}
"if"                              {return IF;}
"else"                            {return ELSE;}
"return"                          {return RETURN;}
"cin"				  {return CIN;}
"cout"				  {return COUT;}

{identifier}                      {yylval.entry = insert(symbol_table, yytext, INT_MAX); return  IDENTIFIER;}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?        { yylval.dval = (int)strtol(yytext, NULL, 16); return  HEX_CONSTANT;}
[+\-]?{digit}+[lLuU]?              {yylval.dval = atoi(yytext); return  DEC_CONSTANT;}

"/*"                              {cmnt_strt = yylineno; BEGIN CMNT;}
<CMNT>.|{ws}                      ;
<CMNT>\n                          {yylineno++;}
<CMNT>"*/"                        {BEGIN INITIAL;}
<CMNT>"/*"                        {printf("Line %3d: Nested comments are not valid!\n",yylineno);}
<CMNT><<EOF>>                     {printf("Line %3d: Unterminated comment\n", cmnt_strt); yyterminate();}
 
"//".*                            ;

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was escaped */
    yymore();
  }
  else{
  insert( constant_table, yytext, INT_MAX);
  return STRING;
  }
 }

">>"				{return INPUT;}
"<<"				{return OUTPUT;}

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	        {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;}

"--"			                {return DECREMENT;}
"++"			                {return INCREMENT;}
"+="                      		{return ADD_ASSIGN;}
"-="                      		{return SUB_ASSIGN;}
"*="                      		{return MUL_ASSIGN;}
"/="                      		{return DIV_ASSIGN;}
"%="                      		{return MOD_ASSIGN;}


"&&"			                {return LOGICAL_AND;}
"||"			                {return LOGICAL_OR;}

"<="			                {return LS_EQ;}
">="			                {return GR_EQ;}
"=="			                {return EQ;}
"!="		                  	{return NOT_EQ;}

.                         		{return yytext[0];}

%%

