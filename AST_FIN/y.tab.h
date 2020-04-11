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
    DEC_CONSTANT = 258,
    HEX_CONSTANT = 259,
    FLOAT_CONSTANT = 260,
    IDENTIFIER = 261,
    STRING = 262,
    HASH_INCL = 263,
    HASH_DEF = 264,
    HASH_INCL_END = 265,
    LOGICAL_AND = 266,
    LOGICAL_OR = 267,
    LS_EQ = 268,
    GR_EQ = 269,
    EQ = 270,
    NOT_EQ = 271,
    MUL_EQ = 272,
    DIV_EQ = 273,
    MOD_EQ = 274,
    ADD_EQ = 275,
    SUB_EQ = 276,
    INPUT = 277,
    OUTPUT = 278,
    INCREMENT = 279,
    DECREMENT = 280,
    SHORT = 281,
    INT = 282,
    LONG = 283,
    SIGNED = 284,
    UNSIGNED = 285,
    CONST = 286,
    FLOAT = 287,
    IF = 288,
    FOR = 289,
    DO = 290,
    WHILE = 291,
    CONTINUE = 292,
    BREAK = 293,
    RETURN = 294,
    CIN = 295,
    COUT = 296,
    UMINUS = 297,
    ELSEIF = 298,
    ELSE = 299
  };
#endif
/* Tokens.  */
#define DEC_CONSTANT 258
#define HEX_CONSTANT 259
#define FLOAT_CONSTANT 260
#define IDENTIFIER 261
#define STRING 262
#define HASH_INCL 263
#define HASH_DEF 264
#define HASH_INCL_END 265
#define LOGICAL_AND 266
#define LOGICAL_OR 267
#define LS_EQ 268
#define GR_EQ 269
#define EQ 270
#define NOT_EQ 271
#define MUL_EQ 272
#define DIV_EQ 273
#define MOD_EQ 274
#define ADD_EQ 275
#define SUB_EQ 276
#define INPUT 277
#define OUTPUT 278
#define INCREMENT 279
#define DECREMENT 280
#define SHORT 281
#define INT 282
#define LONG 283
#define SIGNED 284
#define UNSIGNED 285
#define CONST 286
#define FLOAT 287
#define IF 288
#define FOR 289
#define DO 290
#define WHILE 291
#define CONTINUE 292
#define BREAK 293
#define RETURN 294
#define CIN 295
#define COUT 296
#define UMINUS 297
#define ELSEIF 298
#define ELSE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "yacc.y" /* yacc.c:1921  */

	double dval;
	entry_t* entry;
	NODE* node;
	int ival;

#line 153 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
