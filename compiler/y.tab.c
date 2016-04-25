/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_TYPE = 258,
     FLOAT_TYPE = 259,
     DOUBLE_TYPE = 260,
     LONG_TYPE = 261,
     STR_TYPE = 262,
     CHAR_TYPE = 263,
     TAB = 264,
     DEF = 265,
     INT_DEF = 266,
     STR_DEF = 267,
     FLOAT_DEF = 268,
     DOUBLE_DEF = 269,
     LONG_DEF = 270,
     LIST_DEF = 271,
     CHAR_DEF = 272,
     FUNCTION_DEF = 273,
     VAR = 274,
     RET = 275,
     IF = 276,
     WHILE = 277,
     FOR = 278,
     IN = 279,
     RIGHT_ARROW = 280,
     EQUALITY = 281
   };
#endif
/* Tokens.  */
#define INT_TYPE 258
#define FLOAT_TYPE 259
#define DOUBLE_TYPE 260
#define LONG_TYPE 261
#define STR_TYPE 262
#define CHAR_TYPE 263
#define TAB 264
#define DEF 265
#define INT_DEF 266
#define STR_DEF 267
#define FLOAT_DEF 268
#define DOUBLE_DEF 269
#define LONG_DEF 270
#define LIST_DEF 271
#define CHAR_DEF 272
#define FUNCTION_DEF 273
#define VAR 274
#define RET 275
#define IF 276
#define WHILE 277
#define FOR 278
#define IN 279
#define RIGHT_ARROW 280
#define EQUALITY 281




/* Copy the first part of user declarations.  */
#line 1 "grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "../utils/utils.h"

t_node			*top_node;

extern int yylex();


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "grammar.y"
{
	char *tmp_str;
	t_node *node;
	int type;
}
/* Line 193 of yacc.c.  */
#line 166 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 179 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    35,    31,    29,    37,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
      26,    34,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    39,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    25,    33,    38,    45,    50,    53,    56,    60,    64,
      70,    76,    80,    84,    86,    88,    90,    92,    94,    96,
     100,   104,   108,   113,   118,   122,   126,   130,   134,   139,
     143,   145,   147,   149,   151,   153,   155,   157,   159,   164,
     168,   172,   174,   176,   178,   180,   182,   184,   186,   189,
     191,   194,   196,   198,   200,   202,   204,   206,   208,   210
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    49,    -1,    50,    -1,    45,    -1,    46,
      -1,    47,    -1,    48,    -1,    44,    -1,    42,    -1,    10,
      68,    43,    35,    36,    -1,    10,    68,    43,    35,    25,
      69,    36,    -1,    10,    68,    35,    36,    -1,    10,    68,
      35,    25,    69,    36,    -1,    43,    37,    69,    66,    -1,
      69,    66,    -1,    20,    50,    -1,    21,    50,    36,    -1,
      22,    50,    36,    -1,    23,    49,    25,    50,    36,    -1,
      23,    67,    24,    50,    36,    -1,    67,    34,    50,    -1,
      38,    50,    35,    -1,    55,    -1,    56,    -1,    57,    -1,
      52,    -1,    53,    -1,    51,    -1,    50,    28,    50,    -1,
      50,    27,    50,    -1,    50,    26,    50,    -1,    50,    27,
      34,    50,    -1,    50,    26,    34,    50,    -1,    50,    29,
      50,    -1,    50,    30,    50,    -1,    50,    32,    50,    -1,
      50,    31,    50,    -1,    50,    33,    54,    39,    -1,    50,
      36,    50,    -1,    63,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,    66,    -1,    65,    -1,    64,    -1,    50,
      33,    50,    39,    -1,    68,    58,    35,    -1,    58,    37,
      50,    -1,    50,    -1,    13,    -1,    12,    -1,    15,    -1,
      14,    -1,    11,    -1,    17,    -1,    69,    16,    -1,    19,
      -1,    69,    19,    -1,    19,    -1,    18,    -1,     3,    -1,
       4,    -1,     6,    -1,     5,    -1,     7,    -1,     8,    -1,
      69,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    44,    45,    46,    47,    48,    49,    50,
      53,    54,    55,    56,    59,    60,    63,    66,    69,    72,
      75,    78,    81,    82,    83,    84,    85,    86,    87,    90,
      91,    92,    93,    94,    97,    98,    99,   100,   103,   106,
     109,   110,   111,   112,   113,   114,   115,   116,   119,   122,
     125,   126,   129,   132,   135,   138,   141,   144,   147,   150,
     153,   154,   157,   159,   160,   161,   162,   163,   164,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TYPE", "FLOAT_TYPE", "DOUBLE_TYPE",
  "LONG_TYPE", "STR_TYPE", "CHAR_TYPE", "TAB", "DEF", "INT_DEF", "STR_DEF",
  "FLOAT_DEF", "DOUBLE_DEF", "LONG_DEF", "LIST_DEF", "CHAR_DEF",
  "FUNCTION_DEF", "VAR", "RET", "IF", "WHILE", "FOR", "IN", "RIGHT_ARROW",
  "'<'", "'>'", "EQUALITY", "'+'", "'-'", "'*'", "'/'", "'['", "'='",
  "')'", "':'", "','", "'('", "']'", "$accept", "S", "FUNC_DEC",
  "DEC_ARGS", "RETUR", "CONDITIO", "WHILE_LO", "FOR_LOO1", "FOR_LOO2",
  "ASSIGN", "EXPR", "COMPAR", "OPERATIO", "SLIC", "SLIC_IND", "VALUE",
  "INDE", "FUNCTIO", "ARGS", "FLOA", "STRIN", "LON", "DOUBL", "INTEG",
  "CHA", "LIS", "VARIA", "VAR_DEF", "FUNC", "TYPE_DEF", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    60,    62,   281,    43,
      45,    42,    47,    91,    61,    41,    58,    44,    40,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      42,    42,    42,    42,    43,    43,    44,    45,    46,    47,
      48,    49,    50,    50,    50,    50,    50,    50,    50,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    57,
      58,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    67,    68,    69,    69,    69,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     4,     6,     4,     2,     2,     3,     3,     5,
       5,     3,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     4,     4,     3,     3,     3,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    63,    64,    66,    65,    67,    68,     0,    56,    53,
      52,    55,    54,    57,    62,    59,     0,     0,     0,     0,
       0,     0,     9,     8,     4,     5,     6,     7,     2,     3,
      28,    26,    27,    23,    24,    25,    41,    42,    43,    44,
      40,    47,    46,    45,     0,     0,     0,     0,    59,    16,
       0,     0,     0,    61,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      58,    60,     0,     0,     0,    17,    18,     0,     0,    69,
      22,     0,    31,     0,    30,    29,    34,    35,    37,    36,
       0,     0,    21,    49,     0,     0,    12,     0,     0,    15,
       0,     0,    33,    32,     0,    48,    38,    50,     0,     0,
      10,     0,    19,    20,    39,    13,     0,    14,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    22,    73,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    91,    33,    34,    35,    69,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
     100,   -74,   -74,   -74,   -74,   -74,   -74,    -2,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -30,   158,   158,   158,    21,
     158,    17,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   193,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,     1,   158,    14,     7,   -74,   193,
      29,    48,   153,   -74,    12,   -16,    20,    59,   -74,   122,
     140,   158,   158,   158,   158,   158,   158,   158,   193,   197,
      25,   -74,    -5,   200,    27,   -74,   -74,   158,   158,   -74,
     -74,   158,   198,   158,   198,   198,    68,    68,    24,    24,
      32,    30,   193,   -74,   158,   187,   -74,    -4,   187,   -74,
     171,   182,   -74,   -74,   158,   -74,   -74,   193,   -14,   187,
     -74,    27,   -74,   -74,   193,   -74,   -13,   -74,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,    54,
     -11,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -73,    63,    89,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -70
static const yytype_int8 yytable[] =
{
      46,    99,    79,    79,   -61,    49,    51,    52,    78,    57,
       1,     2,     3,     4,     5,     6,    14,    58,    67,    56,
      95,   109,   115,   118,     1,     2,     3,     4,     5,     6,
      70,    96,   110,    71,    68,    67,    79,    77,   117,    71,
      53,   -69,    72,    79,   -69,    70,    48,    74,    82,    84,
      85,    86,    87,    88,    89,    90,    92,    66,    59,    60,
      61,    62,    63,    64,    65,    66,   100,   101,   104,   106,
     102,   105,   103,    54,    59,    60,    61,    62,    63,    64,
      65,    66,    55,   107,    75,    59,    60,    61,    62,    63,
      64,    65,    66,   114,    80,   108,    47,     0,   111,    64,
      65,    66,     0,     1,     2,     3,     4,     5,     6,   116,
       7,     8,     9,    10,    11,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     1,     2,     3,     4,     5,
       6,     0,     0,     8,     9,    10,    11,    12,    20,    13,
      14,    48,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     8,     9,    10,    11,    12,    81,    13,    14,    48,
      20,     1,     2,     3,     4,     5,     6,     0,     0,     8,
       9,    10,    11,    12,    83,    13,    14,    48,    20,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    76,
       1,     2,     3,     4,     5,     6,    20,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,   112,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,   113,    59,
      60,    61,    62,    63,    64,    65,    66,    62,    63,    64,
      65,    66,    93,     0,    94,    97,     0,    98
};

static const yytype_int8 yycheck[] =
{
       0,    74,    16,    16,    34,    16,    17,    18,    24,    20,
       3,     4,     5,     6,     7,     8,    18,     0,    34,    19,
      25,    25,    36,    36,     3,     4,     5,     6,     7,     8,
      16,    36,    36,    19,    45,    34,    16,    25,   111,    19,
      19,    16,    35,    16,    19,    16,    19,    47,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    33,    26,    27,
      28,    29,    30,    31,    32,    33,    77,    78,    36,    39,
      81,    39,    83,    19,    26,    27,    28,    29,    30,    31,
      32,    33,    19,    94,    36,    26,    27,    28,    29,    30,
      31,    32,    33,   104,    35,    95,     7,    -1,    98,    31,
      32,    33,    -1,     3,     4,     5,     6,     7,     8,   109,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    14,    15,    38,    17,
      18,    19,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    13,    14,    15,    34,    17,    18,    19,
      38,     3,     4,     5,     6,     7,     8,    -1,    -1,    11,
      12,    13,    14,    15,    34,    17,    18,    19,    38,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
       3,     4,     5,     6,     7,     8,    38,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    26,
      27,    28,    29,    30,    31,    32,    33,    29,    30,    31,
      32,    33,    35,    -1,    37,    35,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,    14,    15,    17,    18,    19,    20,    21,    22,    23,
      38,    41,    42,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    55,    56,    57,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    68,    19,    50,
      69,    50,    50,    19,    49,    67,    69,    50,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    50,    58,
      16,    19,    35,    43,    69,    36,    36,    25,    24,    16,
      35,    34,    50,    34,    50,    50,    50,    50,    50,    50,
      50,    54,    50,    35,    37,    25,    36,    35,    37,    66,
      50,    50,    50,    50,    36,    39,    39,    50,    69,    25,
      36,    69,    36,    36,    50,    36,    69,    66,    36
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 43 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 3:
#line 44 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 4:
#line 45 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 5:
#line 46 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 6:
#line 47 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 7:
#line 48 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 8:
#line 49 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 9:
#line 50 "grammar.y"
    {top_node = (yyvsp[(1) - (1)].node);}
    break;

  case 10:
#line 53 "grammar.y"
    {(yyval.node) = new_node(FUNCTION_DECL, (yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node), "", 0);}
    break;

  case 11:
#line 54 "grammar.y"
    {(yyval.node) = new_node(FUNCTION_DECL, (yyvsp[(2) - (7)].node), (yyvsp[(3) - (7)].node), "", (yyvsp[(6) - (7)].type));}
    break;

  case 12:
#line 55 "grammar.y"
    {(yyval.node) = new_node(FUNCTION_DECL, (yyvsp[(2) - (4)].node), NULL, "", 0);}
    break;

  case 13:
#line 56 "grammar.y"
    {(yyval.node) = new_node(FUNCTION_DECL, (yyvsp[(2) - (6)].node), NULL, "", (yyvsp[(5) - (6)].type));}
    break;

  case 14:
#line 59 "grammar.y"
    {(yyvsp[(4) - (4)].node)->type = (yyvsp[(3) - (4)].type);(yyval.node) = new_node(FUNCTION_ARGS, (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node), "", 0);}
    break;

  case 15:
#line 60 "grammar.y"
    {(yyvsp[(2) - (2)].node)->type = (yyvsp[(1) - (2)].type);(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 16:
#line 63 "grammar.y"
    {(yyval.node) = new_node(RETURN, NULL, (yyvsp[(2) - (2)].node), "", 0);}
    break;

  case 17:
#line 66 "grammar.y"
    {(yyval.node) = new_node(CONDITION, NULL, (yyvsp[(2) - (3)].node), "", 0);}
    break;

  case 18:
#line 69 "grammar.y"
    {(yyval.node) = new_node(WHILE_LOOP, NULL, (yyvsp[(2) - (3)].node), "", 0);}
    break;

  case 19:
#line 72 "grammar.y"
    {(yyval.node) = new_node(FOR_LOOP1, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), "", 0);}
    break;

  case 20:
#line 75 "grammar.y"
    {(yyval.node) = new_node(FOR_LOOP2, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), "", 0);}
    break;

  case 21:
#line 78 "grammar.y"
    {(yyval.node) = new_node(ASSIGNEMENT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 22:
#line 81 "grammar.y"
    {(yyval.node) = new_node(PRIORITY, NULL, (yyvsp[(2) - (3)].node), "", 0);}
    break;

  case 23:
#line 82 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 24:
#line 83 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 25:
#line 84 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 26:
#line 85 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 27:
#line 86 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 28:
#line 87 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 29:
#line 90 "grammar.y"
    {(yyval.node) = new_node(EQUALITY_CHECK, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 30:
#line 91 "grammar.y"
    {(yyval.node) = new_node(GREATER_THAN, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 31:
#line 92 "grammar.y"
    {(yyval.node) = new_node(SMALLER_THAN, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 32:
#line 93 "grammar.y"
    {(yyval.node) = new_node(GREATER_EQUAL, (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node), "", 0);}
    break;

  case 33:
#line 94 "grammar.y"
    {(yyval.node) = new_node(SMALLER_EQUAL, (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node), "", 0);}
    break;

  case 34:
#line 97 "grammar.y"
    {(yyval.node) = new_node(ADD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 35:
#line 98 "grammar.y"
    {(yyval.node) = new_node(MINUS, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 36:
#line 99 "grammar.y"
    {(yyval.node) = new_node(DIVIDE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 37:
#line 100 "grammar.y"
    {(yyval.node) = new_node(MULTIPL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 38:
#line 103 "grammar.y"
    {(yyval.node) = new_node(SLICE, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "", 0);}
    break;

  case 39:
#line 106 "grammar.y"
    {(yyval.node) = new_node(SLICE_INDEXES, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 40:
#line 109 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 41:
#line 110 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 42:
#line 111 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 43:
#line 112 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 44:
#line 113 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 45:
#line 114 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 46:
#line 115 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 116 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 48:
#line 119 "grammar.y"
    {(yyval.node) = new_node(INDEX, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "", 0);}
    break;

  case 49:
#line 122 "grammar.y"
    {(yyval.node) = new_node(FUNCTION, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), "", 0);}
    break;

  case 50:
#line 125 "grammar.y"
    {(yyval.node) = new_node(ARGUMENTS, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "", 0);}
    break;

  case 51:
#line 126 "grammar.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 52:
#line 129 "grammar.y"
    {(yyval.node) = new_node(FLOATING, NULL, NULL, yylval.tmp_str, FLOATING);}
    break;

  case 53:
#line 132 "grammar.y"
    {(yyval.node) = new_node(STRING, NULL, NULL, yylval.tmp_str, STRING);}
    break;

  case 54:
#line 135 "grammar.y"
    {yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';(yyval.node) = new_node(LONG, NULL, NULL, yylval.tmp_str, LONG);}
    break;

  case 55:
#line 138 "grammar.y"
    {yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';(yyval.node) = new_node(DOUBLE, NULL, NULL, yylval.tmp_str, DOUBLE);}
    break;

  case 56:
#line 141 "grammar.y"
    {(yyval.node) = new_node(INTEGER, NULL, NULL, yylval.tmp_str, INTEGER);}
    break;

  case 57:
#line 144 "grammar.y"
    {yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';(yyval.node) = new_node(CHAR, NULL, NULL, yylval.tmp_str, CHAR);}
    break;

  case 58:
#line 147 "grammar.y"
    {(yyval.node) = new_node(LIST, NULL, NULL, yylval.tmp_str, (yyvsp[(1) - (2)].type));}
    break;

  case 59:
#line 150 "grammar.y"
    {(yyval.node) = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, 0);}
    break;

  case 60:
#line 153 "grammar.y"
    {(yyval.node) = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, (yyvsp[(1) - (2)].type));}
    break;

  case 61:
#line 154 "grammar.y"
    {(yyval.node) = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, 0);}
    break;

  case 62:
#line 157 "grammar.y"
    {yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';(yyval.node) = new_node(0, NULL, NULL, yylval.tmp_str, 0);}
    break;

  case 63:
#line 159 "grammar.y"
    {(yyval.type) = INTEGER;}
    break;

  case 64:
#line 160 "grammar.y"
    {(yyval.type) = FLOATING;}
    break;

  case 65:
#line 161 "grammar.y"
    {(yyval.type) = LONG;}
    break;

  case 66:
#line 162 "grammar.y"
    {(yyval.type) = DOUBLE;}
    break;

  case 67:
#line 163 "grammar.y"
    {(yyval.type) = STRING;}
    break;

  case 68:
#line 164 "grammar.y"
    {(yyval.type) = CHAR;}
    break;

  case 69:
#line 165 "grammar.y"
    {(yyval.type) = LIST + (yyvsp[(1) - (2)].type);}
    break;


/* Line 1267 of yacc.c.  */
#line 1840 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 168 "grammar.y"


int yyerror(char *msg)
{
	printf("%s\n", msg);
	exit(1);
	return (0);
}

t_node	*get_tree(char *line)
{
	top_node = NULL;

    yy_scan_string(line);
	yyparse();
	yylex_destroy();
	return (top_node);
}

t_node	*parse_line(char *line)
{
	t_node	*top_node;

	top_node = get_tree(line);
	//print_tree(top_node);
	//printf("\n");
	return (top_node);
}
