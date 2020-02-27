/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    DEC_CONSTANT = 259,
    HEX_CONSTANT = 260,
    FLOAT_CONSTANT = 261,
    STRING = 262,
    LOGICAL_AND = 263,
    LOGICAL_OR = 264,
    LS_EQ = 265,
    GR_EQ = 266,
    EQ = 267,
    NOT_EQ = 268,
    MUL_ASSIGN = 269,
    DIV_ASSIGN = 270,
    MOD_ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    LEFT_ASSIGN = 274,
    RIGHT_ASSIGN = 275,
    AND_ASSIGN = 276,
    XOR_ASSIGN = 277,
    OR_ASSIGN = 278,
    INCREMENT = 279,
    DECREMENT = 280,
    SHORT = 281,
    INT = 282,
    LONG = 283,
    LONG_LONG = 284,
    SIGNED = 285,
    UNSIGNED = 286,
    CONST = 287,
    VOID = 288,
    CHAR = 289,
    FLOAT = 290,
    IF = 291,
    FOR = 292,
    WHILE = 293,
    CONTINUE = 294,
    BREAK = 295,
    RETURN = 296,
    CIN = 297,
    COUT = 298,
    INPUT = 299,
    OUTPUT = 300,
    UMINUS = 301,
    ELSEIF = 302,
    ELSE = 303
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define FLOAT_CONSTANT 261
#define STRING 262
#define LOGICAL_AND 263
#define LOGICAL_OR 264
#define LS_EQ 265
#define GR_EQ 266
#define EQ 267
#define NOT_EQ 268
#define MUL_ASSIGN 269
#define DIV_ASSIGN 270
#define MOD_ASSIGN 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define LEFT_ASSIGN 274
#define RIGHT_ASSIGN 275
#define AND_ASSIGN 276
#define XOR_ASSIGN 277
#define OR_ASSIGN 278
#define INCREMENT 279
#define DECREMENT 280
#define SHORT 281
#define INT 282
#define LONG 283
#define LONG_LONG 284
#define SIGNED 285
#define UNSIGNED 286
#define CONST 287
#define VOID 288
#define CHAR 289
#define FLOAT 290
#define IF 291
#define FOR 292
#define WHILE 293
#define CONTINUE 294
#define BREAK 295
#define RETURN 296
#define CIN 297
#define COUT 298
#define INPUT 299
#define OUTPUT 300
#define UMINUS 301
#define ELSEIF 302
#define ELSE 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "yacc.y"

	double dval;
	symbolTableEntry* entry;
	int ival;

#line 159 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
