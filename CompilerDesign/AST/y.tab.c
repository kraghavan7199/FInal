/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ast.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  
  void yyerror();
  typedef struct Abstract_syntax_tree
  {
  	char *name;
  	struct Abstract_syntax_tree *left;
  	struct Abstract_syntax_tree *right;
  }node; 
  
  extern FILE *yyin;
  node* buildTree(char *,node *,node *);
  void printTree(node *);
  #define COUNT 10 
  #define YYSTYPE char*
  int count = 0;

#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
    ID = 258,
    NUM = 259,
    T_lt = 260,
    T_gt = 261,
    T_lteq = 262,
    T_gteq = 263,
    T_neq = 264,
    T_eqeq = 265,
    T_and = 266,
    T_or = 267,
    T_incr = 268,
    T_decr = 269,
    T_not = 270,
    T_eq = 271,
    WHILE = 272,
    INT = 273,
    CHAR = 274,
    FLOAT = 275,
    VOID = 276,
    H = 277,
    MAINTOK = 278,
    INCLUDE = 279,
    BREAK = 280,
    CONTINUE = 281,
    IF = 282,
    ELSE = 283,
    COUT = 284,
    STRING = 285,
    FOR = 286,
    ENDL = 287,
    T_ques = 288,
    T_colon = 289,
    T_pl = 290,
    T_min = 291,
    T_mul = 292,
    T_div = 293
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define T_lt 260
#define T_gt 261
#define T_lteq 262
#define T_gteq 263
#define T_neq 264
#define T_eqeq 265
#define T_and 266
#define T_or 267
#define T_incr 268
#define T_decr 269
#define T_not 270
#define T_eq 271
#define WHILE 272
#define INT 273
#define CHAR 274
#define FLOAT 275
#define VOID 276
#define H 277
#define MAINTOK 278
#define INCLUDE 279
#define BREAK 280
#define CONTINUE 281
#define IF 282
#define ELSE 283
#define COUT 284
#define STRING 285
#define FOR 286
#define ENDL 287
#define T_ques 288
#define T_colon 289
#define T_pl 290
#define T_min 291
#define T_mul 292
#define T_div 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    37,    38,    42,    43,    47,    51,    52,
      53,    54,    58,    59,    60,    61,    67,    68,    69,    73,
      74,    75,    76,    80,    81,    82,    83,    87,    88,    89,
      90,    91,    92,    93,    94,    98,    99,   103,   104,   105,
     109,   110,   111,   115,   116,   117,   121,   122,   126,   130,
     134,   135,   138,   139,   142,   143,   144,   147,   148,   149,
     150,   151,   152,   155,   156,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "T_lt", "T_gt", "T_lteq",
  "T_gteq", "T_neq", "T_eqeq", "T_and", "T_or", "T_incr", "T_decr",
  "T_not", "T_eq", "WHILE", "INT", "CHAR", "FLOAT", "VOID", "H", "MAINTOK",
  "INCLUDE", "BREAK", "CONTINUE", "IF", "ELSE", "COUT", "STRING", "FOR",
  "ENDL", "T_ques", "T_colon", "T_pl", "T_min", "T_mul", "T_div",
  "\"\\\"\"", "'{'", "'}'", "';'", "'('", "')'", "$accept", "S", "START",
  "MAIN", "BODY", "C", "LOOPS", "LOOPBODY", "LOOPC", "statement", "COND",
  "ASSIGN_EXPR", "EXP", "ADDSUB", "TERM", "FACTOR", "TERNARY_EXPR",
  "ternary_statement", "PRINT", "LIT", "TYPE", "RELOP", "bin_boolop",
  "un_boolop", YY_NULLPTR
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
     123,   125,    59,    40,    41
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,    20,    12,   -82,     6,    22,   -82,    42,   -13,    28,
      28,    30,    40,   -82,   -82,    11,    11,   129,   -82,   -82,
     -82,   -82,    23,   -82,   -82,   -82,    32,    76,    49,     4,
      93,   -82,    63,   -82,    59,   -82,    35,   -82,   -82,   -82,
      85,    54,    37,    37,   101,    80,   -82,     7,    72,    33,
     186,    19,   -82,   -82,    79,   -82,     7,     7,     7,     7,
       7,     7,     7,   107,    82,   198,    91,   109,    95,    85,
     -82,   108,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,    54,    54,    54,   206,   -82,    59,    36,    83,    35,
      35,   -82,   -82,    59,     7,   147,   147,   138,    37,   159,
      74,   -82,   175,    54,    59,   129,   -82,   -82,   102,   117,
     148,   113,   123,   -82,    54,   -82,    54,   -82,   -82,   111,
     119,   -82,   147,   127,   159,   159,   206,   120,   -82,   -82,
     126,   -82,   -82,   -82,   125,   -82,    54,   -82,   -82,   147,
     -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     0,     0,     6,     5,
      52,    53,     0,    54,    55,    56,     0,     0,     0,     0,
       0,    11,     0,    23,    24,    37,    40,    43,    25,    26,
      46,     0,     0,     0,     0,     0,    65,     0,     0,     0,
      46,     0,     7,     9,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
      46,     0,    47,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,    34,     8,     0,    37,    37,    41,
      42,    44,    45,    35,     0,     0,     0,    50,     0,     0,
      27,    32,     0,     0,    36,     0,    17,    12,     0,    15,
       0,     0,     0,    48,     0,    33,     0,    31,    22,     0,
       0,    18,     0,     0,     0,     0,     0,     0,    16,    20,
       0,    21,    14,    51,     0,    49,     0,    30,    19,     0,
      29,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   160,   155,   -82,   -26,   -79,   -82,   -17,
     -37,   128,   -20,    34,    45,    58,   -82,   -82,   -82,   -27,
     -82,   -81,    75,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    18,    30,    31,   107,   119,   108,
      48,    33,    34,    35,    36,    37,    38,   113,    39,    40,
      41,    81,    82,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,     1,    50,   103,    53,    64,    66,    20,    21,    49,
      20,    21,     6,    54,    63,    65,    65,   109,    69,    46,
      70,   116,    20,    21,    84,     4,    10,    49,     7,    70,
      70,    70,    70,    70,    70,    70,    86,    86,    56,    57,
      20,    21,    93,   132,     8,   136,    11,    47,     9,    12,
      47,    17,    46,    15,   100,   101,   102,    20,    21,     5,
     141,   111,    83,    16,    56,    57,    42,    70,    58,    59,
     -38,    65,    60,    61,   104,    43,   117,    72,   -38,   118,
     -38,    44,   112,    20,    21,    79,    80,   126,   120,   127,
      87,    88,    45,   129,    58,    59,    20,    21,    23,    24,
      25,    62,   130,    89,    90,    55,    67,   134,   135,   140,
      22,    23,    24,    25,    20,    21,    71,   -39,    91,    92,
      26,    85,    27,    94,    28,   -39,    95,   -39,    22,    23,
      24,    25,    20,    21,    52,    96,    29,    98,    26,    97,
      27,    99,    28,   110,   121,   122,    22,    23,    24,    25,
      20,    21,   128,   123,    29,   124,    26,   125,    27,   133,
      28,   131,    20,    21,   137,    23,    24,    25,   138,   139,
      14,    19,    29,    68,     0,   114,    27,    23,    24,    25,
      73,    74,    75,    76,    77,    78,     0,   105,    27,   106,
      29,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    29,    73,    74,    75,    76,    77,    78,    79,
      80,    73,    74,    75,    76,    77,    78,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -28
};

static const yytype_int16 yycheck[] =
{
      17,    24,    29,    84,    30,    42,    43,     3,     4,    29,
       3,     4,     0,    30,    41,    42,    43,    96,    45,    15,
      47,   102,     3,     4,    51,     5,    39,    47,    22,    56,
      57,    58,    59,    60,    61,    62,    56,    57,     5,     6,
       3,     4,    62,   122,    22,   126,    18,    43,     6,    21,
      43,    40,    15,    23,    81,    82,    83,     3,     4,    39,
     139,    98,    43,    23,     5,     6,    43,    94,    35,    36,
      34,    98,    37,    38,    94,    43,   103,    44,    42,   105,
      44,     5,    99,     3,     4,    11,    12,   114,   105,   116,
      56,    57,    43,   119,    35,    36,     3,     4,    18,    19,
      20,    16,   119,    58,    59,    42,     5,   124,   125,   136,
      17,    18,    19,    20,     3,     4,    44,    34,    60,    61,
      27,    42,    29,    16,    31,    42,    44,    44,    17,    18,
      19,    20,     3,     4,    41,    44,    43,    42,    27,    30,
      29,    33,    31,     5,    42,    28,    17,    18,    19,    20,
       3,     4,    41,     5,    43,    42,    27,    34,    29,    32,
      31,    42,     3,     4,    44,    18,    19,    20,    42,    44,
      10,    16,    43,    45,    -1,   100,    29,    18,    19,    20,
       5,     6,     7,     8,     9,    10,    -1,    40,    29,    42,
      43,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    43,     5,     6,     7,     8,     9,    10,    11,
      12,     5,     6,     7,     8,     9,    10,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    46,    47,     5,    39,     0,    22,    22,     6,
      39,    18,    21,    48,    48,    23,    23,    40,    49,    49,
       3,     4,    17,    18,    19,    20,    27,    29,    31,    43,
      50,    51,    54,    56,    57,    58,    59,    60,    61,    63,
      64,    65,    43,    43,     5,    43,    15,    43,    55,    57,
      64,    68,    41,    51,    54,    42,     5,     6,    35,    36,
      37,    38,    16,    64,    55,    64,    55,     5,    56,    64,
      64,    44,    44,     5,     6,     7,     8,     9,    10,    11,
      12,    66,    67,    43,    64,    42,    57,    58,    58,    59,
      59,    60,    60,    57,    16,    44,    44,    30,    42,    33,
      64,    64,    64,    66,    57,    40,    42,    52,    54,    52,
       5,    55,    54,    62,    67,    44,    66,    64,    51,    53,
      54,    42,    28,     5,    42,    34,    64,    64,    41,    51,
      54,    42,    52,    32,    54,    54,    66,    44,    42,    44,
      64,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    50,    50,
      50,    50,    51,    51,    51,    51,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    60,    60,    61,    62,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     5,     3,     3,     3,     3,     2,
       2,     1,     5,     9,     7,     5,     3,     1,     2,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     7,
       6,     4,     3,     4,     2,     3,     4,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     5,     3,
       4,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 33 "ast.y" /* yacc.c:1646  */
    {printf("Input accepted.\n");}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 51 "ast.y" /* yacc.c:1646  */
    {printTree((yyvsp[-1]));printf("\n");printf("----------------------------------------------------------------\n");}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 52 "ast.y" /* yacc.c:1646  */
    {printTree((yyvsp[0]));printf("\n");printf("----------------------------------------------------------------\n");}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 53 "ast.y" /* yacc.c:1646  */
    {printTree((yyvsp[-1]));printf("\n");printf("----------------------------------------------------------------\n");}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 54 "ast.y" /* yacc.c:1646  */
    {printTree((yyvsp[0]));printf("\n");printf("----------------------------------------------------------------\n");}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("WHILE",(yyvsp[-2]),(yyvsp[0]));}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 61 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("IF",(yyvsp[-2]),(yyvsp[0]));}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 67 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 73 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("SEQ",(yyvsp[-2]),(yyvsp[-1]));}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 74 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("SEQ",(yyvsp[-1]),(yyvsp[0]));}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 75 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 76 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "ast.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 87 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0]));}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 88 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 98 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("=",(yyvsp[-2]),(yyvsp[0]));}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 99 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("=",(yyvsp[-2]),(yyvsp[0]));}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 103 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 104 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("<",(yyvsp[-2]),(yyvsp[0]));}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 105 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree(">",(yyvsp[-2]),(yyvsp[0]));}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 109 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("+",(yyvsp[-2]),(yyvsp[0]));}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 111 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("-",(yyvsp[-2]),(yyvsp[0]));}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 115 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 116 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("*",(yyvsp[-2]),(yyvsp[0]));}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 117 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("/",(yyvsp[-2]),(yyvsp[0]));}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 121 "ast.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 122 "ast.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 126 "ast.y" /* yacc.c:1646  */
    {(yyval)=buildTree("?",(yyvsp[-3]),(yyvsp[0]));}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 130 "ast.y" /* yacc.c:1646  */
    {(yyval) = buildTree(":",(yyvsp[-2]),(yyvsp[0]));}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 138 "ast.y" /* yacc.c:1646  */
    {(yyval) = buildTree((char *)yylval,0,0);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 139 "ast.y" /* yacc.c:1646  */
    {(yyval) = buildTree((char *)yylval,0,0);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 147 "ast.y" /* yacc.c:1646  */
    { (yyval) = "<";}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "ast.y" /* yacc.c:1646  */
    { (yyval) = ">";}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "ast.y" /* yacc.c:1646  */
    { (yyval) = "<=";}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 150 "ast.y" /* yacc.c:1646  */
    { (yyval) = ">=";}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 151 "ast.y" /* yacc.c:1646  */
    { (yyval) = "!=";}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 152 "ast.y" /* yacc.c:1646  */
    { (yyval) = "==";}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1644 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 169 "ast.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
  yyin = fopen("input.c","r");
  printf("Read File");  
/*
  node *root,*temp;
  root = (node*)malloc(sizeof(node));
  temp = (node*)malloc(sizeof(node));
  */
  if(!yyparse())  //yyparse-> 0 if success
  {
    printf("Parsing Complete\n");
  }
  else
  {
    printf("Parsing failed\n");
  }
  fclose(yyin);
  return 0;
}


node* buildTree(char *op,node *left,node *right)
{
	node *new = (node*)malloc(sizeof(node));
	char *newstr = (char *)malloc(strlen(op)+1);
	strcpy(newstr,op);
	new->left=left;
	new->right=right;
	new->name=newstr;
	return (new);
}

void printTree(node *tree)
{
	if(tree->left || tree->right)
		printf("(");
	printf(" %s ",tree->name);
	if(tree->left)
		printTree(tree->left);
	if(tree->right)
		printTree(tree->right);
	if(tree->left || tree->right)
		printf(")");
	
}
void yyerror()
{
	printf("das");
}
/*
void printTree(node *tree,int space)
{
	if(tree == NULL)
		return;
	
	space += COUNT;
	
	printTree(tree->right, space);
	
	printf("\n");
	
	for(int i = COUNT ;i < space; i++)
		printf(" ");
	printf("%s\n",tree->name);
	
	printTree(tree->left, space);
}*/
