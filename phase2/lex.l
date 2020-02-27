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

 /* REMOVED %x CMNT */


%%
  /* Keywords*/
"int"                             {return INT;}
"char"                            {return CHAR;}
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
"cout"				                    {return COUT;}
"cin"				                      {return CIN;}



{identifier}                      {yylval.entry = insertEntry(symbolTableCollection[currentScope].symbolTable, yytext, INT_MAX, -1); return  IDENTIFIER;}
{ws}                            ;

[+\-]?[0][x|X]{hex}+[lLuU]?        { yylval.dval = (int)strtol(yytext, NULL, 16); return  HEX_CONSTANT;}//string to long integer
[+\-]?{digit}+[lLuU]?              {yylval.dval = atoi(yytext); return  DEC_CONSTANT;}
[+\-]?{digit}+.{digit}+	   {yylval.dval = atoi(yytext); return  FLOAT_CONSTANT;}


\/\/(.*)[\n] {cmnt_strt++;}
\/\*([^*]|\*+[^/])*\*+\/ {cmnt_strt++;}

\"[^\"\n]*\"  {
    if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
      {
        yyless(yyleng-1);       /* push the quote back if it was escaped */
        yymore();
      }
    }

\n                               {yylineno++;}


">>"				{return INPUT;}
"<<"				{return OUTPUT;}
"--"			 	{return DECREMENT;}
"++"			  {return INCREMENT;}
"+="        {return ADD_ASSIGN;}
"-="        {return SUB_ASSIGN;}
"*="        {return MUL_ASSIGN;}
"/="        {return DIV_ASSIGN;}
"%="        {return MOD_ASSIGN;}
"&&"			 	{return LOGICAL_AND;}
"||"			  {return LOGICAL_OR;}
"<="			  {return LS_EQ;}
">="			  {return GR_EQ;}
"=="			  {return EQ;}
"!="		    {return NOT_EQ;}

.                         {return yytext[0];}

%%

