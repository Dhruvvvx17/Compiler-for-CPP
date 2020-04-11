%{

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "y.tab.h"

entry_t** constant_table;
extern table_t SYMBOL_TABLE;
int cmnt_strt = 0;

%}

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

 /* Exclusive states */
%x CMNT

%%
  /* Keywords*/
"int"                             {return INT;}
"char"                            {return CHAR;}
"char*"                           {return CHAR_STAR;}
"float"                           {return FLOAT;}
"void"                            {return VOID;}
"long"                            {return LONG;}
"long long"                       {return LONG_LONG;}
"short"                           {return SHORT;}
"signed"                          {return SIGNED;}
"unsigned"                        {return UNSIGNED;}
"for"                             {return FOR;}
"while"                           {return WHILE;}
"break"                           {return BREAK;}
"continue"                        {return CONTINUE;}
"if"                              {return IF;}
"else"                            {return ELSE;}
"return"                          {return RETURN;}
"cout"				  {return COUT;}
"cin"				  {return CIN;}
{identifier}                      {return  IDENTIFIER;}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?       { yylval.entry = insert(constant_table,yytext,(int)strtol(yytext, NULL, 16),INT,yylineno,0,NULL); return  HEX_CONSTANT;}
'({letter}|{digit})'              { yylval.entry = insert(constant_table,yytext,yytext[1],CHAR,yylineno,0,yytext);return CHAR_CONSTANT;}
[+\-]?{digit}+[lLuU]?             { yylval.entry = insert(constant_table,yytext,atoi(yytext),INT,yylineno,0,NULL); return  DEC_CONSTANT;}
[+\-]?{digit}*\.{digit}+          { yylval.entry = insert(constant_table,yytext,atof(yytext),FLOAT,yylineno,0,NULL); return FLOAT_CONSTANT;}

"/*"                              {cmnt_strt = yylineno; BEGIN CMNT;}
<CMNT>.|{ws}                      ;
<CMNT>\n                          {yylineno++;}
<CMNT>"*/"                        {BEGIN INITIAL;}
<CMNT>"/*"                        {printf("Line %3d: Nested comments are not valid!\n",yylineno);}
<CMNT><<EOF>>                     {printf("Line %3d: Unterminated comment\n", cmnt_strt); yyterminate();}

"//".*                            ;

\"[^\"\n]*\"                      {
                                    if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
                                    {
                                      yyless(yyleng-1);       /* push the quote back if it was escaped */
                                      yymore();
                                    }
                                    else
                                    {
                                      yylval.entry = insert(constant_table,yytext,INT_MAX,STRING,yylineno,0,NULL);
                                      return STRING;
                                    }
                                  }

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	          {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;}

">>"					{return INPUT;}
"<<"					{return OUTPUT;}
"--"			                {return DECREMENT;}
"++"			                {return INCREMENT;}
"+="                      {return ADD_ASSIGN;}
"-="                      {return SUB_ASSIGN;}
"*="                      {return MUL_ASSIGN;}
"/="                      {return DIV_ASSIGN;}
"%="                      {return MOD_ASSIGN;}


"&&"			                {return LOGICAL_AND;}
"||"			                {return LOGICAL_OR;}
"<="			                {return LS_EQ;}
">="			                {return GR_EQ;}
"=="			                {return EQ;}
"!="		                  {return NOT_EQ;}

.                         {return yytext[0];}

%%
