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
#line 1 "prj2.y" /* yacc.c:337  */

	#include <stdlib.h>
	#include <stdio.h>
	#include "symbol_table.h"

	entry_t** symbol_table;
  	entry_t** constant_table;

	double Evaluate (double lhs_value,int assign_type,double rhs_value);
	int current_dtype;
	int yyerror(char *msg);

#line 83 "y.tab.c" /* yacc.c:337  */
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
#line 15 "prj2.y" /* yacc.c:352  */

	double dval;
	entry_t* entry;
	int ival;

#line 216 "y.tab.c" /* yacc.c:352  */
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   348

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
       2,     2,     2,    49,     2,     2,     2,    48,     2,     2,
      53,    54,    46,    44,    40,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
      42,    41,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    73,    76,    77,    80,    84,    85,    87,
      88,    91,    92,    95,    96,    99,   100,   101,   102,   103,
     104,   105,   110,   111,   114,   115,   119,   123,   124,   129,
     132,   133,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   155,   156,   163,   167,   170,   171,   172,
     174,   175,   177,   178,   179,   187,   188,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   212,
     213,   214,   215,   216,   221,   222,   223,   224,   226,   230,
     231,   232,   233,   234,   235,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   249,   250,   253,   255,   256,   260,
     261,   264,   265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONSTANT",
  "HEX_CONSTANT", "STRING", "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ",
  "EQ", "NOT_EQ", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "INCREMENT", "DECREMENT", "SHORT", "INT", "LONG",
  "LONG_LONG", "SIGNED", "UNSIGNED", "CONST", "IF", "FOR", "DO", "WHILE",
  "CONTINUE", "BREAK", "RETURN", "COUT", "','", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "ELSEIF", "ELSE", "'('",
  "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept", "program",
  "builder", "function", "type", "pointer", "data_type", "sign_specifier",
  "type_specifier", "argument_list", "arguments", "arg", "stmt",
  "compound_stmt", "statements", "single_stmt", "if_block", "while_block",
  "do_while_block", "declaration", "declaration_list", "sub_decl",
  "expression", "sub_expr", "assignment_expr", "unary_expr", "lhs",
  "assign_op", "arithmetic_expr", "constant", "array_index",
  "function_call", "parameter_list", "parameter", YY_NULLPTR
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
      44,    61,    60,    62,    43,    45,    42,    47,    37,    33,
     295,   296,   297,    40,    41,   123,   125,    59,    91,    93
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     278,   -24,     6,     6,     9,  -107,    12,    17,  -107,  -107,
     236,  -107,  -107,    91,    39,   320,  -107,  -107,   -34,  -107,
    -107,    15,   256,  -107,   184,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,   258,    71,   277,    39,  -107,  -107,    98,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   146,  -107,
    -107,   196,   272,  -107,  -107,   160,   184,   160,    10,  -107,
     277,   289,  -107,   314,  -107,  -107,  -107,  -107,    23,   -16,
    -107,   289,  -107,  -107,  -107,  -107,  -107,   284,   184,   184,
     184,   184,   184,   184,   184,   184,  -107,   160,   160,   160,
     160,   160,    84,    42,    57,  -107,    21,  -107,   215,   241,
    -107,  -107,    90,    90,  -107,  -107,   208,   208,  -107,  -107,
    -107,  -107,    53,   314,  -107,  -107,   235,    80,  -107,  -107,
    -107,  -107,   169,  -107,    54,  -107,  -107,   269,    59,   116,
      63,    66,    70,   153,  -107,  -107,    98,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,    74,   184,   100,   184,  -107,  -107,
    -107,   173,  -107,   150,   235,    94,   155,  -107,   184,   116,
     184,   116,   235,   126,   157,  -107,   116,   111,  -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,     0,     0,    17,    15,    18,    20,    13,    14,
       0,     3,     4,     0,     8,     0,    12,     5,     0,    51,
      52,     0,     0,    54,     0,    78,    77,    76,    16,    19,
      21,     1,     2,    78,     0,     0,    10,     7,    11,     0,
      48,    82,    83,    84,    80,    81,    79,    49,     0,    74,
      75,     0,    92,    94,    95,     0,     0,     0,     0,    67,
      68,    66,    93,    23,    47,     9,    50,    73,     0,    92,
      72,    69,    70,    71,    92,    91,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,    22,    25,     0,    90,    63,    64,
      61,    62,    59,    60,    58,    57,    85,    86,    87,    88,
      89,    26,     0,     0,   102,    98,   101,     0,   100,    31,
       6,    24,     0,    97,     0,    99,    42,    78,     0,     0,
       0,     0,     0,     0,    41,    29,     0,    30,    27,    28,
      32,    33,    34,    35,     0,     0,     0,     0,    38,    39,
      37,     0,    36,     0,    56,     0,     0,    40,     0,     0,
       0,     0,    55,    43,     0,    45,     0,     0,    44,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   176,  -107,     5,   143,  -107,  -107,   179,  -107,
    -107,    83,    62,   105,  -107,  -107,  -107,  -107,  -107,     2,
     -10,   164,  -106,   -20,     1,     0,    47,   190,    16,  -107,
     180,   181,  -107,   112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,   136,    37,    14,    15,    16,    93,
      94,    95,   137,   138,   124,   139,   140,   141,   142,   143,
      18,    19,   153,   154,    59,    60,    22,    48,    61,    62,
      23,   144,   117,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    20,    17,    34,    58,    13,    39,   -78,   -78,    25,
      21,    20,    17,    35,    20,    13,   -53,    78,    79,    80,
      81,    82,    83,    40,    52,    53,    54,   114,    41,    42,
      43,    44,    45,   -53,    24,    28,    76,    96,    29,    35,
      20,   156,    24,    30,     2,     3,    49,    50,    67,    26,
      27,    70,    84,    85,   164,   126,    46,   127,    98,    99,
     100,   101,   102,   103,   104,   105,    55,    71,    92,    86,
      56,    75,    47,    77,    57,   115,   116,     2,     3,     4,
       5,     6,     7,     8,     9,    36,   128,   111,   129,   130,
     131,   132,   133,   134,    33,    68,   112,   113,    68,    80,
      81,     1,   116,   106,   107,   108,   109,   110,   119,   119,
     135,    39,   145,   151,     2,     3,   147,   126,    92,   127,
     122,     2,     3,   148,    21,    20,    34,   149,    64,    21,
      20,   152,    84,    85,   123,   155,    35,    20,   162,     2,
       3,     4,     5,     6,     7,     8,     9,   160,   128,    25,
     129,   130,   131,   132,   133,   134,    52,    53,    54,    21,
      20,    21,    20,    74,    53,    54,    21,    20,   169,     2,
       3,   119,    52,    53,    54,   114,     2,     3,   166,    65,
      78,    79,    80,    81,    82,    83,    32,    52,    53,    54,
     158,   146,     2,     3,    38,   158,   121,   158,    55,    69,
      53,    54,    56,    66,   159,    55,    57,     2,     3,   161,
     150,   167,    51,    57,    55,    84,    85,   120,    56,     2,
       3,   163,    57,   165,    80,    81,    82,    83,   168,    55,
     157,    72,    73,    56,   125,     0,    31,    57,     0,     1,
       0,    55,    78,    79,    80,    81,    82,    83,    78,    57,
      80,    81,    82,    83,    89,    90,    91,    84,    85,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    41,
      42,    43,    44,    45,     0,     0,     0,    84,    85,    49,
      50,     1,     0,    84,    85,   -78,   -78,   -78,   -78,   -78,
      41,    42,    43,    44,    45,   -78,   -78,    46,   -53,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,   -53,
       0,    63,     0,   -78,     0,   -53,    24,     0,    46,     0,
       0,     0,    96,     0,     0,     0,   -53,    24,    87,    88,
      89,    90,    91,    87,    88,    89,    90,    91,    97,     4,
       5,     6,     7,     8,     9,     4,     5,     6,     7
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,    13,    24,     0,    40,    23,    24,     3,
      10,    10,    10,    13,    13,    10,    40,     7,     8,     9,
      10,    11,    12,    57,     3,     4,     5,     6,    13,    14,
      15,    16,    17,    57,    58,    26,    56,    53,    26,    39,
      39,   147,    58,    26,    23,    24,    23,    24,    48,     2,
       3,    51,    42,    43,   160,     1,    41,     3,    78,    79,
      80,    81,    82,    83,    84,    85,    45,    51,    63,    59,
      49,    55,    57,    57,    53,    54,    96,    23,    24,    25,
      26,    27,    28,    29,    30,    46,    32,     3,    34,    35,
      36,    37,    38,    39,     3,    48,    54,    40,    51,     9,
      10,     3,   122,    87,    88,    89,    90,    91,    55,    55,
      56,    40,    53,   133,    23,    24,    53,     1,   113,     3,
      40,    23,    24,    57,   124,   124,   136,    57,    57,   129,
     129,    57,    42,    43,    54,    35,   136,   136,   158,    23,
      24,    25,    26,    27,    28,    29,    30,    53,    32,     3,
      34,    35,    36,    37,    38,    39,     3,     4,     5,   159,
     159,   161,   161,     3,     4,     5,   166,   166,    57,    23,
      24,    55,     3,     4,     5,     6,    23,    24,    52,    36,
       7,     8,     9,    10,    11,    12,    10,     3,     4,     5,
      40,   129,    23,    24,    15,    40,   113,    40,    45,     3,
       4,     5,    49,    39,    54,    45,    53,    23,    24,    54,
      57,    54,    22,    53,    45,    42,    43,   112,    49,    23,
      24,   159,    53,   161,     9,    10,    11,    12,   166,    45,
      57,    51,    51,    49,   122,    -1,     0,    53,    -1,     3,
      -1,    45,     7,     8,     9,    10,    11,    12,     7,    53,
       9,    10,    11,    12,    46,    47,    48,    42,    43,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    42,    43,    23,
      24,     3,    -1,    42,    43,    13,    14,    15,    16,    17,
      13,    14,    15,    16,    17,    23,    24,    41,    40,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    40,
      -1,    53,    -1,    41,    -1,    57,    58,    -1,    41,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    44,    45,
      46,    47,    48,    44,    45,    46,    47,    48,    54,    25,
      26,    27,    28,    29,    30,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    24,    25,    26,    27,    28,    29,    30,
      61,    62,    63,    64,    66,    67,    68,    79,    80,    81,
      84,    85,    86,    90,    58,     3,    86,    86,    26,    26,
      26,     0,    62,     3,    80,    85,    46,    65,    68,    40,
      57,    13,    14,    15,    16,    17,    41,    57,    87,    23,
      24,    87,     3,     4,     5,    45,    49,    53,    83,    84,
      85,    88,    89,    53,    57,    65,    81,    85,    86,     3,
      85,    88,    90,    91,     3,    88,    83,    88,     7,     8,
       9,    10,    11,    12,    42,    43,    59,    44,    45,    46,
      47,    48,    64,    69,    70,    71,    53,    54,    83,    83,
      83,    83,    83,    83,    83,    83,    88,    88,    88,    88,
      88,     3,    54,    40,     6,    54,    83,    92,    93,    55,
      73,    71,    40,    54,    74,    93,     1,     3,    32,    34,
      35,    36,    37,    38,    39,    56,    64,    72,    73,    75,
      76,    77,    78,    79,    91,    53,    72,    53,    57,    57,
      57,    83,    57,    82,    83,    35,    82,    57,    40,    54,
      53,    54,    83,    72,    82,    72,    52,    54,    72,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    78,    79,    79,    79,
      80,    80,    81,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    91,    91,    92,
      92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     6,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     2,
       1,     2,     1,     0,     3,     1,     2,     1,     1,     3,
       2,     0,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     1,     1,     5,     7,     5,     7,     3,     2,     2,
       3,     1,     1,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     4,     4,     3,     3,
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
        case 15:
#line 99 "prj2.y" /* yacc.c:1652  */
    {current_dtype = INT;}
#line 1471 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 100 "prj2.y" /* yacc.c:1652  */
    {current_dtype = SHORT;}
#line 1477 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 101 "prj2.y" /* yacc.c:1652  */
    {current_dtype = SHORT;}
#line 1483 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 102 "prj2.y" /* yacc.c:1652  */
    {current_dtype = LONG;}
#line 1489 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 103 "prj2.y" /* yacc.c:1652  */
    {current_dtype = LONG;}
#line 1495 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 104 "prj2.y" /* yacc.c:1652  */
    {current_dtype = LONG_LONG;}
#line 1501 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 105 "prj2.y" /* yacc.c:1652  */
    {current_dtype = LONG_LONG;}
#line 1507 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 178 "prj2.y" /* yacc.c:1652  */
    {(yyvsp[0].entry) -> data_type = current_dtype;}
#line 1513 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 187 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-2].dval),(yyvsp[0].dval);}
#line 1519 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 188 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1525 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 193 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) > (yyvsp[0].dval));}
#line 1531 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 194 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) < (yyvsp[0].dval));}
#line 1537 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 195 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) == (yyvsp[0].dval));}
#line 1543 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 196 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) != (yyvsp[0].dval));}
#line 1549 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 197 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) <= (yyvsp[0].dval));}
#line 1555 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 198 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) >= (yyvsp[0].dval));}
#line 1561 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 199 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) && (yyvsp[0].dval));}
#line 1567 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 200 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[-2].dval) || (yyvsp[0].dval));}
#line 1573 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 201 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (!(yyvsp[0].dval));}
#line 1579 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 202 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1585 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 203 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1591 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 204 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1597 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 212 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-2].entry)->value = Evaluate((yyvsp[-2].entry)->value,(yyvsp[-1].ival),(yyvsp[0].dval));}
#line 1603 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 213 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = 0;}
#line 1609 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 214 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = 0;}
#line 1615 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 215 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-2].entry)->value = Evaluate((yyvsp[-2].entry)->value,(yyvsp[-1].ival),(yyvsp[0].dval));}
#line 1621 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 216 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = 0;}
#line 1627 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 221 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-1].entry)->value = ((yyvsp[-1].entry)->value)++;}
#line 1633 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 222 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-1].entry)->value = ((yyvsp[-1].entry)->value)--;}
#line 1639 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 223 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].entry)->value = --((yyvsp[0].entry)->value);}
#line 1645 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 224 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].entry)->value = ++((yyvsp[0].entry)->value);}
#line 1651 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 226 "prj2.y" /* yacc.c:1652  */
    {(yyval.entry) = (yyvsp[0].entry); if(! (yyvsp[0].entry)->data_type) (yyvsp[0].entry)->data_type = current_dtype;}
#line 1657 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 230 "prj2.y" /* yacc.c:1652  */
    {(yyval.ival) = '=';}
#line 1663 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 231 "prj2.y" /* yacc.c:1652  */
    {(yyval.ival) = ADD_ASSIGN;}
#line 1669 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 232 "prj2.y" /* yacc.c:1652  */
    {(yyval.ival) = SUB_ASSIGN;}
#line 1675 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 233 "prj2.y" /* yacc.c:1652  */
    {(yyval.ival) = MUL_ASSIGN;}
#line 1681 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 234 "prj2.y" /* yacc.c:1652  */
    {(yyval.ival) = DIV_ASSIGN;}
#line 1687 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 235 "prj2.y" /* yacc.c:1652  */
    {(yyval.ival) = MOD_ASSIGN;}
#line 1693 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 238 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval);}
#line 1699 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 239 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval);}
#line 1705 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 240 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval);}
#line 1711 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 241 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = ((yyvsp[0].dval) == 0) ? yyerror("Divide by 0!") : ((yyvsp[-2].dval) / (yyvsp[0].dval));}
#line 1717 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 242 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (int)(yyvsp[-2].dval) % (int)(yyvsp[0].dval);}
#line 1723 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 243 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[-1].dval);}
#line 1729 "y.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 244 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = -(yyvsp[0].dval);}
#line 1735 "y.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 245 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].entry) -> value;}
#line 1741 "y.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 246 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1747 "y.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 249 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1753 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 250 "prj2.y" /* yacc.c:1652  */
    {(yyval.dval) = (yyvsp[0].dval);}
#line 1759 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1763 "y.tab.c" /* yacc.c:1652  */
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
#line 268 "prj2.y" /* yacc.c:1918  */


#include "lex.yy.c"
#include <ctype.h>


double Evaluate (double lhs_value,int assign_type,double rhs_value)
{
	switch(assign_type)
	{
		case '=': return rhs_value;
		case ADD_ASSIGN: return (lhs_value + rhs_value);
		case SUB_ASSIGN: return (lhs_value - rhs_value);
		case MUL_ASSIGN: return (lhs_value * rhs_value);
		case DIV_ASSIGN: return (lhs_value / rhs_value);
		case MOD_ASSIGN: return ((int)lhs_value % (int)rhs_value);
	}
}

int main(int argc, char *argv[])
{
	symbol_table = create_table();
	constant_table = create_table();

	yyin = fopen("inp.c", "r");

	if(!yyparse())
	{
		printf("\nParsing complete\n");
	}
	else
	{
			printf("\nParsing failed\n");
	}


	printf("\n\tSymbol table");
	display(symbol_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
}

