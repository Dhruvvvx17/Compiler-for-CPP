/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
    STRING = 261,
    LOGICAL_AND = 262,
    LOGICAL_OR = 263,
    LS_EQ = 264,
    GR_EQ = 265,
    EQ = 266,
    NOT_EQ = 267,
    MUL_ASSIGN = 268,
    DIV_ASSIGN = 269,
    MOD_ASSIGN = 270,
    ADD_ASSIGN = 271,
    SUB_ASSIGN = 272,
    LEFT_ASSIGN = 273,
    RIGHT_ASSIGN = 274,
    AND_ASSIGN = 275,
    XOR_ASSIGN = 276,
    OR_ASSIGN = 277,
    INCREMENT = 278,
    DECREMENT = 279,
    SHORT = 280,
    INT = 281,
    LONG = 282,
    LONG_LONG = 283,
    SIGNED = 284,
    UNSIGNED = 285,
    CONST = 286,
    IF = 287,
    FOR = 288,
    DO = 289,
    WHILE = 290,
    CONTINUE = 291,
    BREAK = 292,
    RETURN = 293,
    COUT = 294,
    UMINUS = 295,
    ELSEIF = 296,
    ELSE = 297
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define STRING 261
#define LOGICAL_AND 262
#define LOGICAL_OR 263
#define LS_EQ 264
#define GR_EQ 265
#define EQ 266
#define NOT_EQ 267
#define MUL_ASSIGN 268
#define DIV_ASSIGN 269
#define MOD_ASSIGN 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define LEFT_ASSIGN 273
#define RIGHT_ASSIGN 274
#define AND_ASSIGN 275
#define XOR_ASSIGN 276
#define OR_ASSIGN 277
#define INCREMENT 278
#define DECREMENT 279
#define SHORT 280
#define INT 281
#define LONG 282
#define LONG_LONG 283
#define SIGNED 284
#define UNSIGNED 285
#define CONST 286
#define IF 287
#define FOR 288
#define DO 289
#define WHILE 290
#define CONTINUE 291
#define BREAK 292
#define RETURN 293
#define COUT 294
#define UMINUS 295
#define ELSEIF 296
#define ELSE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "prj2.y" /* yacc.c:1921  */

	double dval;
	entry_t* entry;
	int ival;

#line 148 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
