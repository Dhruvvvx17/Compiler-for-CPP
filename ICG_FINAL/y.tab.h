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
    CHAR_CONSTANT = 261,
    FLOAT_CONSTANT = 262,
    STRING = 263,
    LOGICAL_AND = 264,
    LOGICAL_OR = 265,
    LS_EQ = 266,
    GR_EQ = 267,
    EQ = 268,
    NOT_EQ = 269,
    MUL_ASSIGN = 270,
    DIV_ASSIGN = 271,
    MOD_ASSIGN = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    INCREMENT = 275,
    DECREMENT = 276,
    INPUT = 277,
    OUTPUT = 278,
    SHORT = 279,
    INT = 280,
    LONG = 281,
    LONG_LONG = 282,
    SIGNED = 283,
    UNSIGNED = 284,
    CONST = 285,
    VOID = 286,
    CHAR = 287,
    FLOAT = 288,
    CHAR_STAR = 289,
    IF = 290,
    FOR = 291,
    WHILE = 292,
    CONTINUE = 293,
    BREAK = 294,
    RETURN = 295,
    COUT = 296,
    CIN = 297,
    UMINUS = 298,
    LOWER_THAN_ELSE = 299,
    ELSE = 300
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define CHAR_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING 263
#define LOGICAL_AND 264
#define LOGICAL_OR 265
#define LS_EQ 266
#define GR_EQ 267
#define EQ 268
#define NOT_EQ 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define INPUT 277
#define OUTPUT 278
#define SHORT 279
#define INT 280
#define LONG 281
#define LONG_LONG 282
#define SIGNED 283
#define UNSIGNED 284
#define CONST 285
#define VOID 286
#define CHAR 287
#define FLOAT 288
#define CHAR_STAR 289
#define IF 290
#define FOR 291
#define WHILE 292
#define CONTINUE 293
#define BREAK 294
#define RETURN 295
#define COUT 296
#define CIN 297
#define UMINUS 298
#define LOWER_THAN_ELSE 299
#define ELSE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 55 "yacc.y" /* yacc.c:1921  */

	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;
	vector<int>* nextlist;
	int instr;

#line 157 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
