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

	#include "stdc++.h"
	#include "symboltable.h"
	#include "lex.yy.c"
	#include <string.h>
	#include <stdlib.h>
	using namespace std;

	void yyerror(char *msg);

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  	extern entry_t** constant_table;

	int current_dtype;
	int current_storage;

	table_t symbol_table_list[NUM_TABLES];

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;

	int param_list[10];
	int p_idx = 0;
	int p=0;
  	int rhs = 0;

	void type_check(int,int,int);
	vector<int> merge(vector<int>& v1, vector<int>& v2);
	void backpatch(vector<int>&, int);
	void gencode(string);
	void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void printlist(vector<int>);

	int nextinstr = 0;
	int temp_var_number = 0;
	
	vector<string> ICG;
	typedef struct quadruples
  	{
    		char *op;
    		char *arg1;
    		char *arg2;
    		char *res;
  	}quad;
  	int quadlen = 0;
  	quad** q = (quad**)malloc(100 * sizeof(quad*));
	

#line 123 "y.tab.c" /* yacc.c:337  */
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
#line 55 "yacc.y" /* yacc.c:352  */

	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;
	vector<int>* nextlist;
	int instr;

#line 265 "y.tab.c" /* yacc.c:352  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
       2,     2,     2,    52,     2,     2,     2,    51,     2,     2,
      56,    57,    49,    47,    43,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
      45,    44,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   136,   137,   142,   150,   141,   164,
     165,   168,   169,   172,   173,   176,   177,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   195,   196,
     199,   200,   204,   211,   212,   219,   217,   235,   243,   247,
     253,   259,   264,   265,   266,   275,   283,   290,   299,   300,
     301,   304,   306,   307,   309,   309,   309,   322,   331,   344,
     344,   344,   355,   356,   357,   360,   361,   364,   365,   366,
     370,   377,   380,   386,   396,   402,   409,   416,   423,   430,
     437,   447,   457,   465,   471,   476,   484,   498,   516,   530,
     542,   551,   565,   576,   589,   601,   616,   631,   643,   655,
     656,   659,   678,   679,   680,   681,   682,   685,   693,   701,
     709,   717,   725,   733,   743,   750,   765,   766,   767,   768,
     771,   799,   800,   803,   811,   821,   822,   825,   830,   837,
     840
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONSTANT",
  "HEX_CONSTANT", "CHAR_CONSTANT", "FLOAT_CONSTANT", "STRING",
  "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ", "NOT_EQ",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "INCREMENT", "DECREMENT", "INPUT", "OUTPUT", "SHORT", "INT", "LONG",
  "LONG_LONG", "SIGNED", "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT",
  "CHAR_STAR", "IF", "FOR", "WHILE", "CONTINUE", "BREAK", "RETURN", "COUT",
  "CIN", "','", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UMINUS", "LOWER_THAN_ELSE", "ELSE", "'('", "')'", "'{'", "'}'",
  "';'", "'['", "']'", "$accept", "starter", "builder", "function", "$@1",
  "$@2", "type", "pointer", "data_type", "sign_specifier",
  "type_specifier", "argument_list", "arguments", "arg", "stmt",
  "compound_stmt", "$@3", "statements", "single_stmt", "cin_stat",
  "cout_stat", "for_block", "$@4", "$@5", "if_block", "while_block", "$@6",
  "$@7", "declaration", "declaration_list", "sub_decl", "expression_stmt",
  "expression", "sub_expr", "assignment_expr", "unary_expr", "lhs",
  "identifier", "assign", "arithmetic_expr", "constant", "array_access",
  "array_index", "function_call", "parameter_list", "parameter", "M", "N", YY_NULLPTR
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
     295,   296,   297,    44,    61,    60,    62,    43,    45,    42,
      47,    37,    33,   298,   299,   300,    40,    41,   123,   125,
      59,    91,    93
};
# endif

#define YYPACT_NINF -161

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-161)))

#define YYTABLE_NINF -100

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     379,  -161,     4,     4,   -14,  -161,    -9,    -7,  -161,  -161,
    -161,  -161,  -161,  -161,   364,  -161,  -161,    12,   -15,   424,
    -161,  -161,   -35,  -161,  -161,   120,   357,    82,    -6,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,     7,   399,   152,   -15,
    -161,  -161,    12,  -161,  -161,  -161,  -161,  -161,  -161,    12,
    -161,    12,   285,   285,  -161,  -161,   353,  -161,   -13,  -161,
    -161,  -161,    65,  -161,  -161,  -161,  -161,  -161,   104,   104,
    -161,    61,   373,  -161,  -161,  -161,   100,   373,  -161,  -161,
    -161,  -161,     8,   413,  -161,  -161,   252,   104,   104,   104,
     104,   104,   181,  -161,     4,     5,    40,  -161,  -161,   149,
     149,  -161,  -161,  -161,  -161,   266,  -161,   341,  -161,   399,
     319,   373,  -161,   -38,  -161,  -161,  -161,   413,  -161,  -161,
    -161,   266,   266,   266,   266,   266,   266,   260,  -161,    71,
    -161,   266,   266,  -161,  -161,     1,     1,  -161,  -161,  -161,
    -161,  -161,   179,   137,  -161,    64,  -161,   220,  -161,    76,
      78,  -161,    84,    95,    24,   144,   153,    12,  -161,  -161,
    -161,   111,   114,  -161,  -161,  -161,  -161,   264,   121,   266,
     110,   138,  -161,  -161,  -161,   284,   353,     4,  -161,  -161,
    -161,    18,   341,  -161,  -161,    17,   266,  -161,  -161,  -161,
    -161,   266,  -161,   110,  -161,    35,   341,   220,  -161,  -161,
     141,   266,  -161,  -161,    97,   220,  -161,  -161,  -161,   220,
    -161,  -161,  -161,  -161,   220,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   101,     0,     0,    19,    17,    20,    22,    15,    16,
      26,    24,    25,    27,     0,     3,     4,     0,    10,     0,
      14,     5,     0,    66,    67,     0,     0,    99,   100,    98,
      97,    18,    21,    23,     1,     2,     0,     0,    99,    12,
       9,    13,     0,    63,   104,   105,   106,   102,   103,     0,
      64,     0,     0,     0,    95,    96,     0,    62,     0,    11,
      65,    94,     0,    93,   116,   117,   118,   119,     0,     0,
      92,   114,    87,   115,    89,    91,   114,    86,    88,    90,
     122,   121,     0,    29,   114,   113,     0,     0,     0,     0,
       0,     0,     0,   120,     0,     0,    28,    31,   112,   107,
     108,   109,   110,   111,   128,     0,   124,   127,    84,    85,
     114,    83,   100,     0,   126,    32,     7,     0,    82,   129,
     129,     0,     0,     0,     0,     0,     0,     0,   123,     0,
      30,     0,     0,    79,    78,    76,    77,    75,    74,   125,
      35,     8,    80,    81,    38,   129,    36,     0,    50,     0,
       0,   129,     0,     0,     0,     0,     0,     0,    37,    33,
      34,     0,     0,    40,    39,    41,    42,    99,     0,     0,
       0,     0,    45,    46,    44,     0,     0,     0,    48,    49,
      43,     0,    73,    71,   129,     0,     0,    47,    52,    53,
      51,     0,   129,     0,    70,     0,    72,     0,   129,   129,
      57,     0,    59,   130,     0,     0,   129,    54,    60,     0,
     130,    61,    58,   129,     0,    55,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,   190,  -161,  -161,  -161,    10,   167,  -161,  -161,
     188,  -161,  -161,    93,   222,    87,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   145,   -16,
     175,    29,  -160,   -26,    22,     6,  -161,     0,   202,   258,
     -52,    21,  -161,   186,  -161,   105,   -80,    32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    58,   129,   157,    40,    18,    19,
      20,    95,    96,    97,   158,   159,   144,   145,   160,   161,
     162,   163,   210,   216,   164,   165,   205,   211,   166,    22,
      23,   184,   185,   182,   108,   109,    26,   110,    51,   111,
      73,   112,    82,   168,   113,   114,   131,   206
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    36,    29,    30,    81,   127,    25,     1,    42,   181,
      17,    31,   121,   122,    27,     1,    32,    38,    33,   128,
      25,    28,    24,    37,    17,    43,   195,     1,    64,    65,
      66,    67,     2,     3,    39,    28,    24,   -69,    28,    24,
     132,   204,    27,    83,     2,     3,   125,   126,    37,    62,
      42,    62,    71,    76,   -69,    61,    80,    63,    70,    75,
     191,   191,   116,    28,    24,   147,   107,    57,    84,    84,
      93,   171,    68,    74,    78,   192,   105,   194,   191,   118,
      69,    54,    55,   117,   174,    54,    55,    84,    84,    84,
      84,    84,   199,    94,   115,   133,   134,   135,   136,   137,
     138,   107,    54,    55,   193,   142,   143,     1,    64,    65,
      66,    67,   197,     1,    64,    65,    66,    67,   201,   202,
      54,    55,    56,   146,   189,   -68,   209,    94,   175,   140,
       2,     3,   169,   214,   170,    44,    45,    46,    47,    48,
     191,    36,   -68,    56,   172,    21,   119,   167,   121,   122,
     123,   124,    68,    25,   207,   173,    92,    27,    68,    21,
      69,    56,   105,    37,    49,   196,    69,   176,    28,    24,
     183,   178,    54,    55,   179,   177,   188,   190,    28,    24,
      50,   180,   125,   126,     1,    64,    65,    66,    67,   104,
     121,   122,   123,   124,   186,   -68,   203,   167,    89,    90,
      91,     2,     3,    25,    35,   167,    59,    41,    -6,   167,
     130,    25,   -68,    56,   167,    25,   141,    60,    28,    24,
      25,   148,   198,     1,   125,   126,    28,    24,    53,    68,
      28,    24,   139,   105,     0,    28,    24,    69,   106,    79,
       2,     3,   213,     0,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,    13,   149,   150,   151,   152,   153,
     154,   155,   156,     1,    64,    65,    66,    67,   104,     1,
      64,    65,    66,    67,     0,     0,     0,     0,   140,     0,
       2,     3,     0,     0,    54,    55,     2,     3,     1,    64,
      65,    66,    67,   119,   120,   121,   122,   123,   124,    87,
      88,    89,    90,    91,     0,     2,     3,   -68,    68,    98,
      72,    77,   105,     0,    68,     0,    69,     0,   105,     0,
      92,     0,    69,     0,   -68,    56,    85,    86,     0,   125,
     126,     0,     0,    68,   -99,   -99,   -99,   -99,   -99,    54,
      55,    69,     0,     0,   187,    99,   100,   101,   102,   103,
     119,   120,   121,   122,   123,   124,     1,    64,    65,    66,
      67,     0,     0,   -99,    34,     0,     0,     1,     0,     0,
       0,     0,    44,    45,    46,    47,    48,     0,     0,     0,
      56,     0,     1,     0,     2,     3,   125,   126,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,    13,     2,
       3,    52,     0,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,    13,    44,    45,    46,    47,    48,   200,
      87,    88,    89,    90,    91,     0,     0,   208,     0,     0,
       0,   212,     0,     0,     0,     0,   215,     4,     5,     6,
       7,     8,     9,    49,    10,    11,    12,    13,     4,     5,
       6,     7,     0,     0,     0,    10,    11,    12,    13
};

static const yytype_int16 yycheck[] =
{
       0,    17,     2,     3,    56,    43,     0,     3,    43,   169,
       0,    25,    11,    12,    14,     3,    25,    17,    25,    57,
      14,     0,     0,    17,    14,    60,   186,     3,     4,     5,
       6,     7,    20,    21,    49,    14,    14,    43,    17,    17,
     120,   201,    42,    56,    20,    21,    45,    46,    42,    49,
      43,    51,    52,    53,    60,    49,    56,    51,    52,    53,
      43,    43,    57,    42,    42,   145,    92,    60,    68,    69,
      62,   151,    48,    52,    53,    57,    52,    60,    43,   105,
      56,    20,    21,    43,    60,    20,    21,    87,    88,    89,
      90,    91,    57,    83,    94,   121,   122,   123,   124,   125,
     126,   127,    20,    21,   184,   131,   132,     3,     4,     5,
       6,     7,   192,     3,     4,     5,     6,     7,   198,   199,
      20,    21,    61,    59,   176,    43,   206,   117,   154,    58,
      20,    21,    56,   213,    56,    15,    16,    17,    18,    19,
      43,   157,    60,    61,    60,     0,     9,   147,    11,    12,
      13,    14,    48,   147,    57,    60,    56,   157,    48,    14,
      56,    61,    52,   157,    44,   191,    56,    23,   147,   147,
      60,    60,    20,    21,    60,    22,   176,   177,   157,   157,
      60,    60,    45,    46,     3,     4,     5,     6,     7,     8,
      11,    12,    13,    14,    56,    43,    55,   197,    49,    50,
      51,    20,    21,   197,    14,   205,    39,    19,    56,   209,
     117,   205,    60,    61,   214,   209,   129,    42,   197,   197,
     214,     1,   193,     3,    45,    46,   205,   205,    26,    48,
     209,   209,   127,    52,    -1,   214,   214,    56,    57,    53,
      20,    21,   210,    -1,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    58,    -1,
      20,    21,    -1,    -1,    20,    21,    20,    21,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    13,    14,    47,
      48,    49,    50,    51,    -1,    20,    21,    43,    48,    57,
      52,    53,    52,    -1,    48,    -1,    56,    -1,    52,    -1,
      56,    -1,    56,    -1,    60,    61,    68,    69,    -1,    45,
      46,    -1,    -1,    48,    15,    16,    17,    18,    19,    20,
      21,    56,    -1,    -1,    60,    87,    88,    89,    90,    91,
       9,    10,    11,    12,    13,    14,     3,     4,     5,     6,
       7,    -1,    -1,    44,     0,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      61,    -1,     3,    -1,    20,    21,    45,    46,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    20,
      21,    44,    -1,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    15,    16,    17,    18,    19,   197,
      47,    48,    49,    50,    51,    -1,    -1,   205,    -1,    -1,
      -1,   209,    -1,    -1,    -1,    -1,   214,    24,    25,    26,
      27,    28,    29,    44,    31,    32,    33,    34,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    24,    25,    26,    27,    28,    29,
      31,    32,    33,    34,    64,    65,    66,    69,    71,    72,
      73,    91,    92,    93,    97,    98,    99,   100,   104,   100,
     100,    25,    25,    25,     0,    65,    92,    98,   100,    49,
      70,    73,    43,    60,    15,    16,    17,    18,    19,    44,
      60,   101,    44,   101,    20,    21,    61,    60,    67,    70,
      93,    98,   100,    98,     4,     5,     6,     7,    48,    56,
      98,   100,   102,   103,   104,    98,   100,   102,   104,   106,
     100,   103,   105,    56,   100,   102,   102,    47,    48,    49,
      50,    51,    56,    62,    69,    74,    75,    76,    57,   102,
     102,   102,   102,   102,     8,    52,    57,    96,    97,    98,
     100,   102,   104,   107,   108,   100,    57,    43,    96,     9,
      10,    11,    12,    13,    14,    45,    46,    43,    57,    68,
      76,   109,   109,    96,    96,    96,    96,    96,    96,   108,
      58,    78,    96,    96,    79,    80,    59,   109,     1,    35,
      36,    37,    38,    39,    40,    41,    42,    69,    77,    78,
      81,    82,    83,    84,    87,    88,    91,   100,   106,    56,
      56,   109,    60,    60,    60,    96,    23,    22,    60,    60,
      60,    95,    96,    60,    94,    95,    56,    60,   100,   103,
     100,    43,    57,   109,    60,    95,    96,   109,    94,    57,
      77,   109,   109,    55,    95,    89,   110,    57,    77,   109,
      85,    90,    77,   110,   109,    77,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    67,    68,    66,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    77,    77,    79,    78,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    83,    83,    85,    86,    84,    87,    87,    89,
      90,    88,    91,    91,    91,    92,    92,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    99,
      99,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     1,     0,     4,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     2,     2,
       1,     3,     3,     3,     0,     0,    13,     6,    10,     0,
       0,     9,     3,     2,     2,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       4,     4,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     4,     3,     3,     1,     1,     1,     0,
       0
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
        case 6:
#line 142 "yacc.y" /* yacc.c:1652  */
    {
				func_type = current_dtype;
				is_declaration = 0;
				current_scope = create_new_scope();
				gencode((yyvsp[0].entry)->lexeme + string(":"));
			}
#line 1577 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 150 "yacc.y" /* yacc.c:1652  */
    {
				is_declaration = 0;
				fill_parameter_list((yyvsp[-4].entry),param_list,p_idx);
				p_idx = 0;
				is_func = 1;
				p=1;
			}
#line 1589 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 158 "yacc.y" /* yacc.c:1652  */
    {   is_func = 0;	}
#line 1595 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 164 "yacc.y" /* yacc.c:1652  */
    {is_declaration = 1; }
#line 1601 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 165 "yacc.y" /* yacc.c:1652  */
    {is_declaration = 1; }
#line 1607 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 180 "yacc.y" /* yacc.c:1652  */
    {current_dtype = INT;current_storage=4;}
#line 1613 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 181 "yacc.y" /* yacc.c:1652  */
    {current_dtype = SHORT;current_storage=2;}
#line 1619 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 182 "yacc.y" /* yacc.c:1652  */
    {current_dtype = SHORT;current_storage=2;}
#line 1625 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 183 "yacc.y" /* yacc.c:1652  */
    {current_dtype = LONG;current_storage=8;}
#line 1631 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 184 "yacc.y" /* yacc.c:1652  */
    {current_dtype = LONG;current_storage=8;}
#line 1637 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 185 "yacc.y" /* yacc.c:1652  */
    {current_dtype = LONG_LONG;current_storage=8;}
#line 1643 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 186 "yacc.y" /* yacc.c:1652  */
    {current_dtype = LONG_LONG;current_storage=8;}
#line 1649 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 187 "yacc.y" /* yacc.c:1652  */
    {current_dtype = CHAR;current_storage=1;}
#line 1655 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 188 "yacc.y" /* yacc.c:1652  */
    {current_dtype = FLOAT;current_storage=4;}
#line 1661 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 189 "yacc.y" /* yacc.c:1652  */
    {current_dtype = VOID;current_storage=0;}
#line 1667 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 190 "yacc.y" /* yacc.c:1652  */
    {current_dtype = STRING;current_storage=4;}
#line 1673 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 204 "yacc.y" /* yacc.c:1652  */
    {
							param_list[p_idx++] = (yyvsp[0].entry)->data_type;
							gencode(string("arg ") + (yyvsp[0].entry)->lexeme);
						}
#line 1682 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 211 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1688 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 212 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1694 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 219 "yacc.y" /* yacc.c:1652  */
    {
					if(!p)current_scope = create_new_scope();
					else p = 0;
				}
#line 1703 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 228 "yacc.y" /* yacc.c:1652  */
    {
					current_scope = exit_scope();
					(yyval.content) = new content_t();
					(yyval.content) = (yyvsp[-1].content);
				}
#line 1713 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 235 "yacc.y" /* yacc.c:1652  */
    {
									backpatch((yyvsp[-2].content)->nextlist,(yyvsp[-1].instr));
									(yyval.content) = new content_t();
									(yyval.content)->nextlist = (yyvsp[0].content)->nextlist;
									(yyval.content)->breaklist = merge((yyvsp[-2].content)->breaklist,(yyvsp[0].content)->breaklist);
									(yyval.content)->continuelist = merge((yyvsp[-2].content)->continuelist,(yyvsp[0].content)->continuelist);
								}
#line 1725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 243 "yacc.y" /* yacc.c:1652  */
    {	(yyval.content) = new content_t();	}
#line 1731 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 247 "yacc.y" /* yacc.c:1652  */
    {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						}
#line 1741 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 253 "yacc.y" /* yacc.c:1652  */
    {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						}
#line 1751 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 259 "yacc.y" /* yacc.c:1652  */
    {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						 }
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 264 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1767 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 265 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1773 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 266 "yacc.y" /* yacc.c:1652  */
    {
								if(is_func)
								{
									if(func_type != VOID)
										yyerror("return type (VOID) does not match function type");
								}
							  	else yyerror("return statement not inside function definition");
							}
#line 1786 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 275 "yacc.y" /* yacc.c:1652  */
    {
								if(!is_loop)
									yyerror("Illegal use of continue");
								(yyval.content) = new content_t();
								(yyval.content)->continuelist = {nextinstr};
								gencode("goto _");
							}
#line 1798 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 283 "yacc.y" /* yacc.c:1652  */
    {
								if(!is_loop) {yyerror("Illegal use of break");}
								(yyval.content) = new content_t();
								(yyval.content)->breaklist = {nextinstr};
								gencode("goto _");
						    }
#line 1809 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 291 "yacc.y" /* yacc.c:1652  */
    {
								if(is_func)
								{
									if(func_type != (yyvsp[-1].content)->data_type)
										yyerror("return type does not match function type");
								}
								else yyerror("return statement not in function definition");
							}
#line 1822 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 299 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1828 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 300 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1834 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 301 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1840 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 304 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1846 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 306 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1852 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 307 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t();}
#line 1858 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 309 "yacc.y" /* yacc.c:1652  */
    {is_loop = 1;}
#line 1864 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 309 "yacc.y" /* yacc.c:1652  */
    {is_loop = 0;}
#line 1870 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 310 "yacc.y" /* yacc.c:1652  */
    {
				backpatch((yyvsp[-8].content)->truelist,(yyvsp[-2].instr));
				backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
				backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
				backpatch((yyvsp[-3].content)->nextlist, (yyvsp[-9].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-8].content)->falselist,(yyvsp[-1].content)->breaklist);
				gencode(string("goto ") + to_string((yyvsp[-7].instr)));
			 }
#line 1884 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 323 "yacc.y" /* yacc.c:1652  */
    {
				backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->nextlist);
				(yyval.content)->breaklist = (yyvsp[0].content)->breaklist;
				(yyval.content)->continuelist = (yyvsp[0].content)->continuelist;
			}
#line 1896 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 332 "yacc.y" /* yacc.c:1652  */
    {
				backpatch((yyvsp[-7].content)->truelist,(yyvsp[-5].instr));
				backpatch((yyvsp[-7].content)->falselist,(yyvsp[-1].instr));

				(yyval.content) = new content_t();
				vector<int> temp = merge((yyvsp[-4].content)->nextlist,(yyvsp[-2].content)->nextlist);
				(yyval.content)->nextlist = merge(temp,(yyvsp[0].content)->nextlist);
				(yyval.content)->breaklist = merge((yyvsp[0].content)->breaklist,(yyvsp[-4].content)->breaklist);
				(yyval.content)->continuelist = merge((yyvsp[0].content)->continuelist,(yyvsp[-4].content)->continuelist);
			}
#line 1911 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 344 "yacc.y" /* yacc.c:1652  */
    {is_loop = 1;}
#line 1917 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 344 "yacc.y" /* yacc.c:1652  */
    {is_loop = 0;}
#line 1923 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 345 "yacc.y" /* yacc.c:1652  */
    {
				backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
				backpatch((yyvsp[-5].content)->truelist,(yyvsp[-3].instr));
				backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-5].content)->falselist,(yyvsp[-1].content)->breaklist);
				gencode(string("goto ") + to_string((yyvsp[-7].instr)));
			}
#line 1936 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 355 "yacc.y" /* yacc.c:1652  */
    {is_declaration = 0;}
#line 1942 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 371 "yacc.y" /* yacc.c:1652  */
    {
						(yyval.content) = new content_t(); 
						(yyval.content)->truelist = (yyvsp[-1].content)->truelist; 
						(yyval.content)->falselist = (yyvsp[-1].content)->falselist;
					}
#line 1952 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 377 "yacc.y" /* yacc.c:1652  */
    {	(yyval.content) = new content_t();	}
#line 1958 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 381 "yacc.y" /* yacc.c:1652  */
    {
					(yyval.content) = new content_t();
					(yyval.content)->truelist = (yyvsp[0].content)->truelist; 
					(yyval.content)->falselist = (yyvsp[0].content)->falselist;
				}
#line 1968 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 387 "yacc.y" /* yacc.c:1652  */
    {
					(yyval.content) = new content_t(); 
					(yyval.content)->truelist = (yyvsp[0].content)->truelist; 
					(yyval.content)->falselist = (yyvsp[0].content)->falselist;
				}
#line 1978 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 397 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" > "));
			}
#line 1988 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 403 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" < "));
			}
#line 1998 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 410 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" == "));
			}
#line 2008 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 417 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" != "));
			}
#line 2018 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 424 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" >= "));
			}
#line 2028 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 431 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" <= "));
			}
#line 2038 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 438 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-3].content)->data_type;
				backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
				(yyval.content)->truelist = (yyvsp[0].content)->truelist;
				(yyval.content)->falselist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->falselist);
			}
#line 2051 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 448 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-3].content)->data_type;
				backpatch((yyvsp[-3].content)->falselist,(yyvsp[-1].instr));
				(yyval.content)->truelist = merge((yyvsp[-3].content)->truelist,(yyvsp[0].content)->truelist);
				(yyval.content)->falselist = (yyvsp[0].content)->falselist;
			}
#line 2064 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 458 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
				(yyval.content)->truelist = (yyvsp[0].content)->falselist;
				(yyval.content)->falselist = (yyvsp[0].content)->truelist;
			}
#line 2075 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 466 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type; 
				(yyval.content)->addr = (yyvsp[0].content)->addr;
			}
#line 2085 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 472 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			}
#line 2094 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 477 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			}
#line 2103 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 485 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
		 		(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
		 		(yyval.content)->code = string("t")+to_string(temp_var_number) + string(" = ") + (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[-2].content)->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				temp_var_number++;
		 		rhs = 0;
			}
#line 2119 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 499 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
		 		(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
				//if($3->entry->char_value == NULL)
				//{
					(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + string(" = ") + (yyvsp[0].content)->addr;
				//}
				/*else
				{
		 			$$->code = $1->entry->lexeme + string(" = ") + $3->entry->char_value;
				}*/
				gencode((yyval.content)->code);
		 		rhs = 0;
			}
#line 2139 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 517 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
	 			(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
	 			(yyval.content)->code = string("t")+to_string(temp_var_number) + string(" = ") + (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[-2].content)->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				temp_var_number++;
		 		rhs = 0;
			}
#line 2155 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 531 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
	 			(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
	 			(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + string(" = ") + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
	 			rhs = 0;
			}
#line 2168 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 543 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].data_type),1); 
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].data_type);
			}
#line 2178 "y.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 552 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
			 	(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = string("t")+to_string(temp_var_number) + string(" = ") + (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[-2].content)->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				temp_var_number++;
		 		rhs = 0;
			}
#line 2194 "y.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 566 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
			 	(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + string(" = ") + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
			 	rhs = 0;
			}
#line 2207 "y.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 577 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = string("t")+to_string(temp_var_number) + string(" = ") + (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[-2].content)->entry->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				temp_var_number++;
		 		rhs = 0;
			}
#line 2223 "y.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 590 "yacc.y" /* yacc.c:1652  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = (yyvsp[-2].content)->code + string(" = ") + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
				rhs = 0;
			}
#line 2236 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 602 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;
				(yyval.content)->code = string("t")+to_string(temp_var_number)+ string(" = ")+string((yyvsp[-1].entry)->lexeme);
				gencode((yyval.content)->code);
				temp_var_number++;
				(yyval.content)->code = string("t")+to_string(temp_var_number)+ string(" = ")+string((yyvsp[-1].entry)->lexeme)+string(" + 1");
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[-1].entry)->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				(yyval.content)->code = string("t")+to_string(temp_var_number-1);
				temp_var_number++;
			}
#line 2254 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 617 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;
				(yyval.content)->code = string("t")+to_string(temp_var_number)+ string(" = ")+string((yyvsp[-1].entry)->lexeme);
				gencode((yyval.content)->code);
				temp_var_number++;
				(yyval.content)->code = string("t")+to_string(temp_var_number)+ string(" = ")+string((yyvsp[-1].entry)->lexeme)+string(" - 1");
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[-1].entry)->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				(yyval.content)->code = string("t")+to_string(temp_var_number-1);
				temp_var_number++;
			}
#line 2272 "y.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 632 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
				(yyval.content)->code = string("t")+to_string(temp_var_number)+ string(" = ")+string((yyvsp[0].entry)->lexeme) + string(" - 1");
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[0].entry)->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				(yyval.content)->code = string("t")+to_string(temp_var_number);
				temp_var_number++;
			}
#line 2287 "y.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 644 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
				(yyval.content)->code = string("t")+to_string(temp_var_number)+ string(" = ")+string((yyvsp[0].entry)->lexeme) + string(" + 1");
				gencode((yyval.content)->code);
				(yyval.content)->code = string((yyvsp[0].entry)->lexeme)+string(" = ")+string("t")+to_string(temp_var_number);
				gencode((yyval.content)->code);
				(yyval.content)->code = string("t")+to_string(temp_var_number);
				temp_var_number++;
			}
#line 2302 "y.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 655 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t(); (yyval.content)->entry = (yyvsp[0].entry);}
#line 2308 "y.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 656 "yacc.y" /* yacc.c:1652  */
    {(yyval.content) = new content_t(); (yyval.content)->code = (yyvsp[0].content)->code;}
#line 2314 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 660 "yacc.y" /* yacc.c:1652  */
    {
                    if(is_declaration && !rhs)
                    {
                      (yyvsp[0].entry) = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype,yylineno,current_storage,NULL);
                      if((yyvsp[0].entry) == NULL) 
					  	yyerror("Redeclaration of variable");
                    }
                    else
                    {
                      (yyvsp[0].entry) = search_recursive(yytext);
                      if((yyvsp[0].entry) == NULL) 
					  	yyerror("Variable not declared");
                    }
                    
					(yyval.entry) = (yyvsp[0].entry);
                }
#line 2335 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 678 "yacc.y" /* yacc.c:1652  */
    {rhs=1; (yyval.op) = new string(" + ");}
#line 2341 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 679 "yacc.y" /* yacc.c:1652  */
    {rhs=1; (yyval.op) = new string(" - ");}
#line 2347 "y.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 680 "yacc.y" /* yacc.c:1652  */
    {rhs=1; (yyval.op) = new string(" * ");}
#line 2353 "y.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 681 "yacc.y" /* yacc.c:1652  */
    {rhs=1;	(yyval.op) = new string(" / ");}
#line 2359 "y.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 682 "yacc.y" /* yacc.c:1652  */
    {rhs=1; (yyval.op) = new string(" % ");}
#line 2365 "y.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 686 "yacc.y" /* yacc.c:1652  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" + "));
					 }
#line 2376 "y.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 694 "yacc.y" /* yacc.c:1652  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" - "));
					 }
#line 2387 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 702 "yacc.y" /* yacc.c:1652  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
		 				(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" * "));
					 }
#line 2398 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 710 "yacc.y" /* yacc.c:1652  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" / "));
					 }
#line 2409 "y.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 718 "yacc.y" /* yacc.c:1652  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" % "));
				 	 }
#line 2420 "y.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 726 "yacc.y" /* yacc.c:1652  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-1].content)->data_type;
						(yyval.content)->addr = (yyvsp[-1].content)->addr;
						(yyval.content)->code = (yyvsp[-1].content)->code;
					 }
#line 2431 "y.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 734 "yacc.y" /* yacc.c:1652  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].content)->data_type;
						(yyval.content)->addr = "t" + to_string(temp_var_number);
						std::string expr = (yyval.content)->addr + " = " + "minus " + (yyvsp[0].content)->addr;
						(yyval.content)->code = (yyvsp[0].content)->code + expr;
						temp_var_number++;
				 	 }
#line 2444 "y.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 744 "yacc.y" /* yacc.c:1652  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
	 					(yyval.content)->addr = (yyvsp[0].entry)->lexeme;
			   		 }
#line 2454 "y.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 751 "yacc.y" /* yacc.c:1652  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
						if((yyvsp[0].entry)->value == -1)
						{
							(yyval.content)->addr = ((yyvsp[0].entry)->char_value);
						}
						else
						{
							(yyval.content)->addr = to_string((yyvsp[0].entry)->value);
						}
					 }
#line 2471 "y.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 765 "yacc.y" /* yacc.c:1652  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2477 "y.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 766 "yacc.y" /* yacc.c:1652  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2483 "y.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 767 "yacc.y" /* yacc.c:1652  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2489 "y.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 768 "yacc.y" /* yacc.c:1652  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2495 "y.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 772 "yacc.y" /* yacc.c:1652  */
    {
					if(is_declaration)
					{
						if((yyvsp[-1].entry)->value <= 0)
							yyerror("size of array is not positive");
						else if((yyvsp[-1].entry)->is_constant)
							(yyvsp[-3].entry)->array_dimension = (yyvsp[-1].entry)->value;
							(yyvsp[-3].entry)->storage = current_storage*(yyvsp[-1].entry)->value;
					}
					else if((yyvsp[-1].entry)->is_constant)
					{
						if((yyvsp[-1].entry)->value > (yyvsp[-3].entry)->array_dimension)
							yyerror("Array index out of bound");
						if((yyvsp[-1].entry)->value < 0)
							yyerror("Array index cannot be negative");
					}
					
					(yyval.content) = new content_t();
					(yyval.content)->data_type = (yyvsp[-3].entry)->data_type;
					
					if((yyvsp[-1].entry)->is_constant)
						(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + to_string((yyvsp[-1].entry)->value) + string("]");
					else
						(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + string((yyvsp[-1].entry)->lexeme) + string("]");
					(yyval.content)->entry = (yyvsp[-3].entry);
				}
#line 2526 "y.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 799 "yacc.y" /* yacc.c:1652  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2532 "y.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 800 "yacc.y" /* yacc.c:1652  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2538 "y.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 804 "yacc.y" /* yacc.c:1652  */
    {
					(yyval.data_type) = (yyvsp[-3].entry)->data_type;
					check_parameter_list((yyvsp[-3].entry),param_list,p_idx);
					p_idx = 0;
					gencode(string("call ") + (yyvsp[-3].entry)->lexeme);
				}
#line 2549 "y.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 812 "yacc.y" /* yacc.c:1652  */
    {
					(yyval.data_type) = (yyvsp[-2].entry)->data_type;
				 	check_parameter_list((yyvsp[-2].entry),param_list,p_idx);
				 	p_idx = 0;
	 				gencode(string("call ") + (yyvsp[-2].entry)->lexeme);
				}
#line 2560 "y.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 826 "yacc.y" /* yacc.c:1652  */
    {
					param_list[p_idx++] = (yyvsp[0].content)->data_type;
					gencode(string("param ") + (yyvsp[0].content)->addr);
				}
#line 2569 "y.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 831 "yacc.y" /* yacc.c:1652  */
    {
					param_list[p_idx++] = STRING;
					gencode(string("param ") + (yyvsp[0].entry)->lexeme);
				}
#line 2578 "y.tab.c" /* yacc.c:1652  */
    break;

  case 129:
#line 837 "yacc.y" /* yacc.c:1652  */
    {(yyval.instr) = nextinstr;}
#line 2584 "y.tab.c" /* yacc.c:1652  */
    break;

  case 130:
#line 840 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.content) = new content_t;
				(yyval.content)->nextlist = {nextinstr};
				gencode("goto _");
			}
#line 2594 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2598 "y.tab.c" /* yacc.c:1652  */
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
#line 847 "yacc.y" /* yacc.c:1918  */


void gencode(string x)
{
	std::string instruction;

	instruction = to_string(nextinstr) + string(": ") + x;
	ICG.push_back(instruction);
	nextinstr++;
		


//		----------------------FILL HERE TO GET QUADRUPLE FORMAT---------------------



	char** splitwords = (char**)malloc(10 * sizeof(char*));
	for(int i=0;i<10;i++)
	{	
		splitwords[i] = (char*)malloc(sizeof(char)*20);
	}
	char *temp = (char*)malloc(sizeof(char)*(x.length()+1));
	int i=0;
	int count = 0;
	while(i<x.length())
	{
		temp[i]=x[i];
		i++;
	}
	temp[i]='\0';
	char* token = strtok(temp," ");
	while(token != NULL)
	{
		strcpy(splitwords[count],token);
		//printf("%s ",splitwords[count]);
		count++;
		token = strtok(NULL, " ");
	}
	//printf("\n");
	q[quadlen]= (quad*)malloc(sizeof(quad));
	q[quadlen]->res = (char*)malloc(sizeof(char)*20);
	q[quadlen]->op = (char*)malloc(sizeof(char)*20);
	q[quadlen]->arg1 = (char*)malloc(sizeof(char)*20);
	q[quadlen]->arg2 = (char*)malloc(sizeof(char)*20);
	if(count == 3) //5: c = t0
	{
		strcpy(q[quadlen]->res,splitwords[0]);
		strcpy(q[quadlen]->arg1,splitwords[2]);
		strcpy(q[quadlen]->op,"_____");
		strcpy(q[quadlen]->arg2,"_____");
		
		 
	}
	else if(count == 5) //4: t0 = a + b
	{
		strcpy(q[quadlen]->res,splitwords[0]);
		strcpy(q[quadlen]->arg1,splitwords[2]);
		strcpy(q[quadlen]->arg2,splitwords[4]);
		strcpy(q[quadlen]->op,splitwords[3]);
	}
	else if(count == 4) //2: if t0 goto 4
	{
		strcpy(q[quadlen]->res,splitwords[3]);
		strcpy(q[quadlen]->arg1,splitwords[1]);
		strcpy(q[quadlen]->arg2,"_____");
		strcpy(q[quadlen]->op,splitwords[0]);
	}
	else if(count == 1)// 0: main:
	{
		
		strcpy(q[quadlen]->res,splitwords[0]);
		strcpy(q[quadlen]->op,"_____");
		strcpy(q[quadlen]->arg2,"_____");
		strcpy(q[quadlen]->arg1,"_____");
		
	}
	else if(count == 2)// 3: goto 8
	{
		strcpy(q[quadlen]->res,splitwords[1]);
		strcpy(q[quadlen]->op,splitwords[0]);
		strcpy(q[quadlen]->arg2,"_____");
		strcpy(q[quadlen]->arg1,"_____");	
	}
	quadlen++;


}


void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
	lhs->data_type = arg1->data_type;

	lhs->truelist = {nextinstr};
	lhs->falselist = {nextinstr + 1};

	std::string code;

	code = string("if ") + string(lhs->addr) + string(" goto _");
	gencode(code);

	code = string("goto _");
	gencode(code);
}

void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
}

void backpatch(vector<int>& v1, int number)
{
	for(int i = 0; i<v1.size(); i++)
	{
		string instruction = ICG[v1[i]];

		if(instruction.find("_") < instruction.size())
		{
			instruction.replace(instruction.find("_"),1,to_string(number));
			//instruction.replace(instruction.find("_"),1,arr);
			ICG[v1[i]] = instruction;
			//itoa(number,q[goto_place]->res,10);
			string x =to_string(number);
			char *temp = (char*)malloc(sizeof(char)*(x.length()+1));
			int i=0;
			while(i<x.length())
			{
				temp[i]=x[i];
				i++;
			}
			temp[i]='\0';
			char *lin = (char*)malloc(sizeof(char)*(instruction.length()+1));
			i=0;
			while(i<instruction.length())
			{
				if(instruction[i]==':')
				{
					break;
				}
				lin[i]=instruction[i];
				i++;
			}
			lin[i]='\0';
			int lin_no = atoi(lin);
			strcpy(q[lin_no]->res,temp);
		}
	}
}

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
	vector<int> concat;
	concat.reserve(v1.size() + v2.size());
	concat.insert(concat.end(), v1.begin(), v1.end());
	concat.insert(concat.end(), v2.begin(), v2.end());

	return concat;
}

void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

void displayICG()
{
	ofstream outfile("ICG.code");

	for(int i=0; i<ICG.size();i++)
	outfile << ICG[i] <<endl;

	outfile << nextinstr << ": exit";

	outfile.close();
	printf("\nQUADRUPLE FORMAT\n\n");
	print_dashes(40);
	printf("\t%s\t%s\t%s\t%s\n","op","arg1","arg2","res");
	print_dashes(40);
	for(int i=0;i<quadlen;i++)
	{
		printf("\t%s\t%s\t%s\t%s\n\n",q[i]->op,q[i]->arg1,q[i]->arg2,q[i]->res);
	}
}

void printlist(vector<int> v){
	for(auto it:v)
		cout<<it<<" ";
	cout<<"Next: "<<nextinstr<<endl;
}

int main(int argc, char *argv[])
{
	int i;
	 for(i=0; i<NUM_TABLES;i++)
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();
  	symbol_table_list[0].symbol_table = create_table();
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}

	printf("\nSYMBOL TABLES\n\n");
	display_all();
	printf("\nCONSTANT TABLE\n\n");
	display_constant_table(constant_table);
	
	displayICG();
	
	

}

void yyerror(const char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	
}
