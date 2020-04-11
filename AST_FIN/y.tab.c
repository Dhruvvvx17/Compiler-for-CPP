/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y" /* yacc.c:337  */

	#include <stdlib.h>
	#include <stdio.h>
	#include "symbol_table2.h"
	#include <stdarg.h>
	 
	 int yylex();

	entry_t** symbol_table;
	NODE* root;
	entry_t** symbol_table_stack[10]; 
	int tos = 0;

	double Evaluate (double lhs_value,int assign_type,double rhs_value);
	int current_dtype;
	int current_storage;
	int yyerror(char *msg);
	int yylineno;
	int DECL = 0;

#line 91 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 23 "yacc.y" /* yacc.c:352  */

	double dval;
	entry_t* entry;
	NODE* node;
	int ival;

#line 229 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

#define YYUNDEFTOK  2
#define YYMAXUTOK   299

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,     2,     2,
      55,    56,    48,    46,    42,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    86,    87,    89,    90,    93,    95,    98,
     100,   103,   104,   105,   108,   109,   113,   114,   118,   124,
     125,   129,   130,   133,   134,   138,   139,   142,   143,   144,
     145,   146,   147,   152,   153,   156,   157,   161,   165,   166,
     170,   173,   174,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   191,   193,   195,   196,   199,   200,
     201,   204,   207,   208,   209,   213,   216,   219,   220,   223,
     224,   231,   235,   236,   239,   240,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   259,   260,
     261,   262,   263,   267,   268,   269,   270,   273,   285,   286,
     287,   288,   289,   290,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   304,   305,   306,   309,   312,   313,   316,
     317,   320,   321
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEC_CONSTANT", "HEX_CONSTANT",
  "FLOAT_CONSTANT", "IDENTIFIER", "STRING", "HASH_INCL", "HASH_DEF",
  "HASH_INCL_END", "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ",
  "NOT_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ", "ADD_EQ", "SUB_EQ", "INPUT",
  "OUTPUT", "INCREMENT", "DECREMENT", "SHORT", "INT", "LONG", "SIGNED",
  "UNSIGNED", "CONST", "FLOAT", "IF", "FOR", "DO", "WHILE", "CONTINUE",
  "BREAK", "RETURN", "CIN", "COUT", "','", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "ELSEIF", "ELSE", "'('",
  "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept", "complete_program",
  "headerFilesMacros", "FilesMacros", "headerFiles", "ID_HI",
  "headerMacros", "ID_ME", "macroExpr", "main_program", "block",
  "function", "type", "pointer", "data_type", "sign_specifier",
  "type_specifier", "argument_list", "arguments", "arg", "statement",
  "compound_statement", "statements", "single_statement", "input_st",
  "output_st", "ifBlock", "forBlock", "whileBlock", "declaration", "dl_de",
  "decl_end", "declarationList", "subDecl", "expression_statement",
  "expression", "subExpr", "assignmentExpr", "unaryExpr", "lhs",
  "assignOp", "arithmeticExpr", "constant", "array_index", "function_call",
  "parameter_list", "parameter", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    44,    61,    60,    62,    43,    45,    42,    47,
      37,    33,   297,   298,   299,    40,    41,   123,   125,    59,
      91,    93
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,     6,   373,   -92,   105,    29,    50,    52,    52,   -23,
     -92,    69,   -92,   -92,   -92,   -92,   -92,   -92,   382,   -92,
     -92,    73,    66,   236,   -92,   -92,    35,   -92,   -92,   331,
     256,   -92,   247,    15,   -92,    34,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   223,   -92,   111,   407,    66,   -92,   -92,
     112,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   124,
     -92,   -92,   104,   -92,   -92,   -92,   398,    97,   247,    97,
     310,   -92,   407,   412,   -92,   -92,   -92,   247,   -92,   -92,
     425,   -92,   -92,   -92,   -92,   -92,    92,   -13,   -92,   412,
     -92,   -92,   -92,   -92,   -92,   388,   247,   247,   247,   247,
     247,   247,   247,   247,   -92,    97,    97,    97,    97,    97,
     328,    61,    68,    90,   -92,   116,   -92,     8,   351,   -92,
     -92,    48,    48,   -92,   -92,   -35,   -35,   -92,   -92,   -92,
     -92,   -92,    88,   425,   -92,   -92,   169,    12,   -92,   -92,
     -92,   -92,   242,   -92,   203,   -92,   334,    95,   101,   102,
      99,   107,    40,   139,   154,   -92,   112,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   110,   247,     4,   247,
     -92,   -92,   -92,   316,   182,   185,   -92,    70,   169,   -92,
     112,    80,   146,   156,   -92,   145,   160,   247,   279,   151,
     170,   -92,   279,   -92,   -92,   169,   180,    80,   279,   159,
     -92,   279,   247,   -92,   279,   -92,   166,   -92,   279,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    97,     0,     0,     0,     0,    29,
      27,    30,    25,    26,    32,     3,     5,     6,     2,    15,
      16,     0,    20,     0,    24,    17,     0,    68,    69,     0,
       0,    71,     0,     0,     7,     0,     9,    97,    96,    95,
      28,    31,    14,    97,    62,     0,     0,    22,    19,    23,
       0,    63,   101,   102,   103,    99,   100,    98,    64,     0,
      93,    94,     0,   113,   114,   115,   111,     0,     0,     0,
       0,    86,    87,    85,   112,     8,    11,     0,    10,    12,
      34,    66,    65,    21,    67,    92,     0,   111,    91,    88,
      89,    90,   111,   110,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    36,     0,   109,    82,    83,    80,
      81,    78,    79,    77,    76,   104,   105,   106,   107,   108,
      13,    37,     0,     0,   122,   118,   121,     0,   120,    42,
      18,    35,     0,   117,     0,   119,    97,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,    41,    38,    39,
      48,    49,    43,    45,    44,    46,     0,     0,     0,     0,
      51,    52,    50,     0,     0,     0,    47,     0,    75,    73,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,    72,     0,    54,    55,    74,    56,     0,     0,     0,
      61,     0,     0,    58,     0,    57,     0,    59,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     202,   -92,     0,   176,   -92,   -92,   201,   -92,   -92,   126,
     241,   106,   -92,   -92,   -92,   -92,   -92,   -92,   -92,    64,
     -92,   -92,   -18,   219,   -91,   -56,   -27,    -1,    -2,    19,
     240,   149,   244,   222,   224,   -92,   148
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    34,    17,    36,    78,    18,
      19,    20,   156,    48,    22,    23,    24,   112,   113,   114,
     157,   158,   144,   159,   160,   161,   162,   163,   164,   165,
      44,    82,    26,    27,   181,   182,   178,    71,    72,    30,
      59,    73,    74,    31,   166,   137,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    28,    21,    45,    40,    70,     3,    63,    64,    65,
      66,   -97,   -97,   107,   108,   109,    29,    28,    21,    46,
      28,    98,    99,   100,   101,    75,    38,    39,     7,     8,
       9,    10,    11,    12,    13,    33,    14,    63,    64,    65,
      76,    94,   115,    63,    64,    65,    66,    32,    46,    28,
     110,    67,   102,   103,   142,    68,    35,    85,    37,    69,
      88,    98,    99,   179,     7,     8,    25,   131,   143,   117,
     118,   119,   120,   121,   122,   123,   124,    50,    86,    43,
     111,    86,    25,    63,    64,    65,    66,    67,   136,    77,
     190,    68,   102,   103,    51,    69,    41,     7,     8,   172,
      63,    64,    65,    92,     7,     8,   202,    63,    64,    65,
      87,   177,   187,   183,    47,   136,    60,    61,     4,    63,
      64,    65,    66,   134,   132,   173,   188,    67,     7,     8,
      37,    68,   133,   111,   199,    69,     7,     8,    45,   179,
       7,     8,    29,    28,    67,   139,   206,   -70,     7,     8,
     167,    67,    69,    50,    46,    28,   168,   169,   170,    69,
     195,   174,   189,    67,   -70,    32,   171,    68,   180,   176,
      81,    69,   135,    63,    64,    65,    66,   175,    46,    28,
      96,    97,    98,    99,   100,   101,    29,    28,   187,   185,
      29,    28,   186,    50,     7,     8,    29,    28,   187,    29,
      28,   187,    29,    28,   193,   191,    29,    28,   187,   146,
     197,    89,   192,   102,   103,   204,    93,    67,    95,   194,
      42,    68,   208,    83,    49,    69,   198,     7,     8,     9,
      10,    11,    12,    13,   201,    14,   147,   148,   140,   149,
     150,   151,   152,   153,   154,    63,    64,    65,    66,   134,
      63,    64,    65,    66,   125,   126,   127,   128,   129,   141,
     139,   155,     9,    10,    11,   -70,     7,     8,    14,    84,
      62,     7,     8,    52,    53,    54,    55,    56,    80,    79,
      60,    61,   -70,    32,    90,   146,    91,     0,     0,    67,
     145,     0,     0,    68,    67,     0,     0,    69,    68,    57,
       0,     0,    69,     7,     8,     9,    10,    11,    12,    13,
       0,    14,   147,   148,     0,   149,   150,   151,   152,   153,
     154,    96,    97,    98,    99,   100,   101,    96,    97,    98,
      99,   100,   101,     0,     0,     0,   139,     0,     0,    96,
      97,    98,    99,   100,   101,     0,     0,     0,    52,    53,
      54,    55,    56,     0,   102,   103,     0,     0,     0,     0,
     102,   103,    96,     0,    98,    99,   100,   101,     0,     0,
       0,   104,   102,   103,    57,   184,   -70,     0,     0,     4,
       0,     5,     6,     0,   130,     0,     0,     0,     4,   115,
      58,     0,     0,   -70,    32,   102,   103,     7,     8,     9,
      10,    11,    12,    13,     0,    14,     7,     8,     9,    10,
      11,    12,    13,     0,    14,   -97,   -97,   -97,   -97,   -97,
       0,     0,   -97,   -97,    52,    53,    54,    55,    56,   196,
       0,     0,     0,   200,   105,   106,   107,   108,   109,   203,
       0,   -97,   205,     0,   116,   207,     0,     0,     0,   209,
      57,     9,    10,    11,    12,    13,     0,    14,   105,   106,
     107,   108,   109
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,    21,    27,    32,     0,     3,     4,     5,
       6,    24,    25,    48,    49,    50,    18,    18,    18,    21,
      21,    13,    14,    15,    16,    10,     7,     8,    24,    25,
      26,    27,    28,    29,    30,     6,    32,     3,     4,     5,
       6,    68,    55,     3,     4,     5,     6,    60,    50,    50,
      77,    47,    44,    45,    42,    51,     6,    59,     6,    55,
      62,    13,    14,    59,    24,    25,     2,     6,    56,    96,
      97,    98,    99,   100,   101,   102,   103,    42,    59,     6,
      80,    62,    18,     3,     4,     5,     6,    47,   115,    55,
     181,    51,    44,    45,    59,    55,    27,    24,    25,    59,
       3,     4,     5,     6,    24,    25,   197,     3,     4,     5,
       6,   167,    42,   169,    48,   142,    24,    25,     6,     3,
       4,     5,     6,     7,    56,   152,    56,    47,    24,    25,
       6,    51,    42,   133,   190,    55,    24,    25,   156,    59,
      24,    25,   144,   144,    47,    57,   202,    42,    24,    25,
      55,    47,    55,    42,   156,   156,    55,    55,    59,    55,
     187,    22,   180,    47,    59,    60,    59,    51,   168,    59,
      59,    55,    56,     3,     4,     5,     6,    23,   180,   180,
      11,    12,    13,    14,    15,    16,   188,   188,    42,     7,
     192,   192,     7,    42,    24,    25,   198,   198,    42,   201,
     201,    42,   204,   204,    59,    59,   208,   208,    42,     6,
      59,    62,    56,    44,    45,    56,    67,    47,    69,    59,
      18,    51,    56,    47,    23,    55,    56,    24,    25,    26,
      27,    28,    29,    30,    54,    32,    33,    34,   132,    36,
      37,    38,    39,    40,    41,     3,     4,     5,     6,     7,
       3,     4,     5,     6,   105,   106,   107,   108,   109,   133,
      57,    58,    26,    27,    28,    42,    24,    25,    32,    50,
      30,    24,    25,    17,    18,    19,    20,    21,    55,    35,
      24,    25,    59,    60,    62,     6,    62,    -1,    -1,    47,
     142,    -1,    -1,    51,    47,    -1,    -1,    55,    51,    43,
      -1,    -1,    55,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    11,    12,    13,    14,    15,    16,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    57,    -1,    -1,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    44,    45,    -1,    -1,    -1,    -1,
      44,    45,    11,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    61,    44,    45,    43,    59,    42,    -1,    -1,     6,
      -1,     8,     9,    -1,    56,    -1,    -1,    -1,     6,    55,
      59,    -1,    -1,    59,    60,    44,    45,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    17,    18,    19,    20,    21,   188,
      -1,    -1,    -1,   192,    46,    47,    48,    49,    50,   198,
      -1,    43,   201,    -1,    56,   204,    -1,    -1,    -1,   208,
      43,    26,    27,    28,    29,    30,    -1,    32,    46,    47,
      48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,     6,     8,     9,    24,    25,    26,
      27,    28,    29,    30,    32,    65,    66,    68,    71,    72,
      73,    74,    76,    77,    78,    91,    94,    95,    99,   100,
     101,   105,    60,     6,    67,     6,    69,     6,   101,   101,
      27,    27,    72,     6,    92,    94,   100,    48,    75,    78,
      42,    59,    17,    18,    19,    20,    21,    43,    59,   102,
      24,    25,   102,     3,     4,     5,     6,    47,    51,    55,
      98,    99,   100,   103,   104,    10,     6,    55,    70,   104,
      55,    59,    93,    75,    95,   100,   101,     6,   100,   103,
     105,   106,     6,   103,    98,   103,    11,    12,    13,    14,
      15,    16,    44,    45,    61,    46,    47,    48,    49,    50,
      98,    74,    79,    80,    81,    55,    56,    98,    98,    98,
      98,    98,    98,    98,    98,   103,   103,   103,   103,   103,
      56,     6,    56,    42,     7,    56,    98,   107,   108,    57,
      83,    81,    42,    56,    84,   108,     6,    33,    34,    36,
      37,    38,    39,    40,    41,    58,    74,    82,    83,    85,
      86,    87,    88,    89,    90,    91,   106,    55,    55,    55,
      59,    59,    59,    98,    22,    23,    59,    97,    98,    59,
      74,    96,    97,    97,    59,     7,     7,    42,    56,    94,
      96,    59,    56,    59,    59,    98,    82,    59,    56,    97,
      82,    54,    96,    82,    56,    82,    97,    82,    56,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    67,    68,
      69,    70,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    82,    82,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    87,    88,    88,    89,    89,
      89,    90,    91,    91,    91,    92,    93,    94,    94,    95,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   100,   100,   101,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   105,   106,   106,   107,
     107,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     2,     2,     2,
       2,     1,     1,     3,     2,     1,     1,     1,     6,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     1,     0,     3,     1,     2,     1,     1,
       3,     2,     0,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     2,     3,     4,     4,     5,     7,     6,     7,
       9,     5,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     4,     4,     3,     3,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 84 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("Complete program", 0, 2, (yyvsp[-1].node), (yyvsp[0].node)); root = (yyval.node);}
#line 1532 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 86 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("headerFilesMacros", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1538 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 87 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("headerFilesMacros -> epsilon", 0, 2, NULL, NULL);}
#line 1544 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 89 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1550 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 90 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1556 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 93 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("headerFiles", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1562 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 95 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("ID_HASH", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1568 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 98 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("headerMacros", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1574 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 100 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("ID_MACRO", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1580 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 103 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1586 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 104 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1592 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 105 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1598 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 108 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("main_program", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1604 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 109 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1610 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 113 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1616 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 114 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1622 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 118 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("function", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1628 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 124 "yacc.y" /* yacc.c:1652  */
    {}
#line 1634 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 125 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1640 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 129 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("pointer_star", 0, 2, (yyvsp[0].node), NULL);}
#line 1646 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 130 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("pointer_star", 1, 1, "*");}
#line 1652 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 133 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("data_type", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1658 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 134 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1664 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 138 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("signed", 0, 2, NULL, NULL);}
#line 1670 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 139 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("unsigned", 0, 2, NULL, NULL);}
#line 1676 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 142 "yacc.y" /* yacc.c:1652  */
    {DECL = 1;current_dtype = 1;current_storage=4; (yyval.node) = newnode("int", 0, 2, NULL, NULL);}
#line 1682 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 143 "yacc.y" /* yacc.c:1652  */
    {DECL = 1;current_dtype = 2;current_storage=2; (yyval.node) = newnode("short int", 0, 2, NULL, NULL);}
#line 1688 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 144 "yacc.y" /* yacc.c:1652  */
    {DECL = 1;current_dtype = 2;current_storage=2; (yyval.node) = newnode("short", 0, 2, NULL, NULL);}
#line 1694 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 145 "yacc.y" /* yacc.c:1652  */
    {DECL = 1;current_dtype = 3;current_storage=8; (yyval.node) = newnode("long", 0, 2, NULL, NULL);}
#line 1700 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 146 "yacc.y" /* yacc.c:1652  */
    {DECL = 1;current_dtype = 3;current_storage=8; (yyval.node) = newnode("long int", 0, 2, NULL, NULL);}
#line 1706 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 147 "yacc.y" /* yacc.c:1652  */
    {DECL = 1;current_dtype = 4;current_storage=4; (yyval.node) = newnode("float", 0, 2, NULL, NULL);}
#line 1712 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 152 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 153 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("argument list -> is empty", 0, 2, NULL, NULL);}
#line 1724 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 156 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("arguments", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1730 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 157 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1736 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 161 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("arg", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1742 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 165 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1748 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 166 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1754 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 170 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1760 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 173 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("statements", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1766 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 174 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("statements -> epsilon", 0, 2, NULL, NULL);}
#line 1772 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 178 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1778 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 179 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1784 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 180 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1790 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 181 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1796 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 182 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1802 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 183 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1808 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 184 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1814 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 185 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("single_statement", 0, 2, NULL, NULL);}
#line 1820 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 186 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("single_statement", 0, 2, NULL, NULL);}
#line 1826 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 187 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("single_statement", 0, 2, NULL, NULL);}
#line 1832 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 188 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("single_statement", 0, 2, NULL, (yyvsp[-1].node));}
#line 1838 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 191 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("CIN", 1, 1,(yyvsp[-1].node));}
#line 1844 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 193 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("COUT", 1, 1,(yyvsp[-1].node));}
#line 1850 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 195 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("if", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1856 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 196 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("if", 0, 2, (yyvsp[-4].node), (yyvsp[-2].node));}
#line 1862 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 199 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("for", 0, 2, (yyvsp[-3].node), (yyvsp[0].node));}
#line 1868 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 200 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("for", 0, 2, (yyvsp[-4].node), (yyvsp[0].node));}
#line 1874 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 201 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("for", 0, 2, (yyvsp[-6].node), (yyvsp[0].node));}
#line 1880 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 204 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("while", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1886 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 207 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("declaration", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1892 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 208 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1898 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 209 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1904 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 213 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("dl_de", 0, 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1910 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 216 "yacc.y" /* yacc.c:1652  */
    {DECL = 0; (yyval.node) = newnode("decl_end", 0, 2, NULL, NULL);}
#line 1916 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 219 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("declarationList", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1922 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 220 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1928 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 223 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1934 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 224 "yacc.y" /* yacc.c:1652  */
    {
    			(yyval.node) = (yyvsp[0].node);
    			(yyvsp[0].node)->symtab_entry->data_type = current_dtype;
    			(yyvsp[0].node)->symtab_entry->storage = current_storage;
    			if(! (yyvsp[0].node)->symtab_entry->line_no)
    				(yyvsp[0].node)->symtab_entry->line_no = yylineno;
    		}
#line 1946 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 231 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1952 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 235 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1958 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 236 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode(";", 0, 2, NULL, NULL);}
#line 1964 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 244 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode(">", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1970 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 245 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("<", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1976 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 246 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("==", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1982 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 247 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("!=", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1988 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 248 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("<=", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1994 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 249 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode(">=", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2000 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 250 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("&&", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2006 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 251 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("||", 0, 2, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2012 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 252 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("!", 0, 2, (yyvsp[0].node), NULL);}
#line 2018 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 253 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2024 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 254 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2030 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 255 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2036 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 269 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("--", 0, 2, (yyvsp[0].node), NULL);}
#line 2042 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 270 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("++", 0, 2, (yyvsp[0].node), NULL);}
#line 2048 "y.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 273 "yacc.y" /* yacc.c:1652  */
    {
						if(! (yyvsp[0].node)->symtab_entry->data_type) {
							(yyvsp[0].node)->symtab_entry->data_type = current_dtype;
							(yyvsp[0].node)->symtab_entry->storage = current_storage;
						} 
						if(! (yyvsp[0].node)->symtab_entry->line_no) 
							(yyvsp[0].node)->symtab_entry->line_no = yylineno;
						(yyval.node) = (yyvsp[0].node);
					}
#line 2062 "y.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 285 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("=", 0, 2, NULL, NULL);}
#line 2068 "y.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 286 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("+=", 0, 2, NULL, NULL);}
#line 2074 "y.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 287 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("-=", 0, 2, NULL, NULL);}
#line 2080 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 288 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("*=", 0, 2, NULL, NULL);}
#line 2086 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 289 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("/=", 0, 2, NULL, NULL);}
#line 2092 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 290 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = newnode("%=", 0, 2, NULL, NULL);}
#line 2098 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 298 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2104 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 299 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2110 "y.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 300 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2116 "y.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 301 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2122 "y.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 304 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2128 "y.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 305 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2134 "y.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 306 "yacc.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2140 "y.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 316 "yacc.y" /* yacc.c:1652  */
    {}
#line 2146 "y.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 317 "yacc.y" /* yacc.c:1652  */
    {}
#line 2152 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2156 "y.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 324 "yacc.y" /* yacc.c:1918  */


#include "lex.yy.c"
#include <ctype.h>


double Evaluate (double lhs_value,int operator,double rhs_value)
{
	switch(operator)
	{
		case '=': return rhs_value;
		case ADD_EQ: return (lhs_value + rhs_value);
		case SUB_EQ: return (lhs_value - rhs_value);
		case MUL_EQ: return (lhs_value * rhs_value);
		case DIV_EQ: return (lhs_value / rhs_value);
		case MOD_EQ: return ((int)lhs_value % (int)rhs_value);
	}
}

int main(int argc, char *argv[])
{
	symbol_table = create_table(); //creating empty symbol table and initialising
	symbol_table_stack[0] = symbol_table;

	yyin = fopen("inp1.cpp", "r");

	if(!yyparse())
	{
		//printf("\nParsing complete\n");
	}
	else
	{
		printf("\nParsing FAILED\n");
		fclose(yyin);
		return 0;
	}

	
	//display(symbol_table, 0);
	
	printf("\nParsing complete\n");
	preorder(root);
	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
}
