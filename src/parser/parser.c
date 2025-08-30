/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 19 "src/parser/parser.y"

	#include "parser.h"
	extern int yylex();
	int yyerror(ASTNode **root, char *s);
	int yydebug = 1;

#line 75 "src/parser/parser.c"




# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CST = 3,                        /* CST  */
  YYSYMBOL_IDT = 4,                        /* IDT  */
  YYSYMBOL_PO_ADD = 5,                     /* PO_ADD  */
  YYSYMBOL_PO_SUB = 6,                     /* PO_SUB  */
  YYSYMBOL_PO_MUL = 7,                     /* PO_MUL  */
  YYSYMBOL_PO_DIV = 8,                     /* PO_DIV  */
  YYSYMBOL_PO_AFF = 9,                     /* PO_AFF  */
  YYSYMBOL_PR_EQ = 10,                     /* PR_EQ  */
  YYSYMBOL_PR_GT = 11,                     /* PR_GT  */
  YYSYMBOL_PR_GE = 12,                     /* PR_GE  */
  YYSYMBOL_PR_LT = 13,                     /* PR_LT  */
  YYSYMBOL_PR_LE = 14,                     /* PR_LE  */
  YYSYMBOL_PB_AND = 15,                    /* PB_AND  */
  YYSYMBOL_PB_OR = 16,                     /* PB_OR  */
  YYSYMBOL_PB_NOT = 17,                    /* PB_NOT  */
  YYSYMBOL_PB_IF = 18,                     /* PB_IF  */
  YYSYMBOL_PB_ELIF = 19,                   /* PB_ELIF  */
  YYSYMBOL_PB_ELSE = 20,                   /* PB_ELSE  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_LEFT_BRACKET = 22,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 23,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_BRACE = 24,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 25,               /* RIGHT_BRACE  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_context = 28,                   /* context  */
  YYSYMBOL_if_statement = 29,              /* if_statement  */
  YYSYMBOL_optional_if = 30,               /* optional_if  */
  YYSYMBOL_bool_expr = 31,                 /* bool_expr  */
  YYSYMBOL_expr = 32                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  61

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    56,    56,    59,    60,    61,    62,    66,    69,    70,
      71,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      86,    87,    88,    89,    90,    91,    92,    93
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CST", "IDT", "PO_ADD",
  "PO_SUB", "PO_MUL", "PO_DIV", "PO_AFF", "PR_EQ", "PR_GT", "PR_GE",
  "PR_LT", "PR_LE", "PB_AND", "PB_OR", "PB_NOT", "PB_IF", "PB_ELIF",
  "PB_ELSE", "SEMICOLON", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE",
  "RIGHT_BRACE", "$accept", "program", "context", "if_statement",
  "optional_if", "bool_expr", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -32,     9,    55,   -32,   -32,     6,    49,    49,    49,   -32,
     107,    87,    47,   -32,   104,    89,   -11,    73,    49,    49,
     -32,    47,    47,    47,    47,    47,    47,    47,    47,    47,
     -32,    47,   119,   -32,   -32,   -32,   -32,   -32,     0,     0,
     -32,   -32,   119,   119,   119,   119,   119,    83,    13,    17,
      49,    -6,   -32,   105,   -32,   -32,    39,    45,   -32,    17,
     -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    26,    27,     0,     0,     0,     6,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,    20,     3,    18,    25,    16,    17,    21,    22,
      23,    24,    11,    12,    13,    14,    15,     0,     0,     8,
       0,     0,     7,     0,     3,     3,     0,     0,    10,     8,
       9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -22,   -32,   -31,    -5,    -2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     9,    52,    10,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      11,    13,    15,    16,    18,    19,    17,    23,    24,     3,
      32,    48,    34,    36,    37,    12,     4,     5,    54,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    60,    47,
       6,     7,    56,    57,     0,     8,    50,    51,    49,     0,
       0,     0,     4,     5,     0,    53,    11,     0,     4,     5,
       4,     5,     4,     5,    11,    11,     6,     7,     4,     5,
       0,     8,     6,     7,    58,     0,     6,     8,     0,    31,
      59,     8,     6,     7,     0,     0,     0,     8,    21,    22,
      23,    24,     0,    25,    26,    27,    28,    29,    21,    22,
      23,    24,    21,    22,    23,    24,    35,    25,    26,    27,
      28,    29,     0,     0,    18,    19,    35,     0,    30,    21,
      22,    23,    24,    33,    25,    26,    27,    28,    29,     0,
      18,    19,    18,    19,    21,    22,    23,    24,    20,    55
};

static const yytype_int8 yycheck[] =
{
       2,     6,     7,     8,    15,    16,     8,     7,     8,     0,
      12,    33,    23,    18,    19,     9,     3,     4,    24,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    59,    31,
      17,    18,    54,    55,    -1,    22,    19,    20,    25,    -1,
      -1,    -1,     3,     4,    -1,    50,    48,    -1,     3,     4,
       3,     4,     3,     4,    56,    57,    17,    18,     3,     4,
      -1,    22,    17,    18,    25,    -1,    17,    22,    -1,    22,
      25,    22,    17,    18,    -1,    -1,    -1,    22,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,     5,     6,
       7,     8,     5,     6,     7,     8,    23,    10,    11,    12,
      13,    14,    -1,    -1,    15,    16,    23,    -1,    21,     5,
       6,     7,     8,    24,    10,    11,    12,    13,    14,    -1,
      15,    16,    15,    16,     5,     6,     7,     8,    21,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,     0,     3,     4,    17,    18,    22,    29,
      31,    32,     9,    31,    32,    31,    31,    32,    15,    16,
      21,     5,     6,     7,     8,    10,    11,    12,    13,    14,
      21,    22,    32,    24,    23,    23,    31,    31,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    28,    25,
      19,    20,    30,    31,    24,    24,    28,    28,    25,    25,
      30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    28,    28,    29,    30,    30,
      30,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      32,    32,    32,    32,    32,    32,    32,    32
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     3,     3,     2,     6,     0,     6,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (root, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ASTNode **root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (root);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_CST: /* CST  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 759 "src/parser/parser.c"
        break;

    case YYSYMBOL_PO_ADD: /* PO_ADD  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 765 "src/parser/parser.c"
        break;

    case YYSYMBOL_PO_SUB: /* PO_SUB  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 771 "src/parser/parser.c"
        break;

    case YYSYMBOL_PO_MUL: /* PO_MUL  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 777 "src/parser/parser.c"
        break;

    case YYSYMBOL_PO_DIV: /* PO_DIV  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 783 "src/parser/parser.c"
        break;

    case YYSYMBOL_PO_AFF: /* PO_AFF  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 789 "src/parser/parser.c"
        break;

    case YYSYMBOL_PR_EQ: /* PR_EQ  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 795 "src/parser/parser.c"
        break;

    case YYSYMBOL_PR_GT: /* PR_GT  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 801 "src/parser/parser.c"
        break;

    case YYSYMBOL_PR_GE: /* PR_GE  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 807 "src/parser/parser.c"
        break;

    case YYSYMBOL_PR_LT: /* PR_LT  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 813 "src/parser/parser.c"
        break;

    case YYSYMBOL_PR_LE: /* PR_LE  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 819 "src/parser/parser.c"
        break;

    case YYSYMBOL_PB_AND: /* PB_AND  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 825 "src/parser/parser.c"
        break;

    case YYSYMBOL_PB_OR: /* PB_OR  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 831 "src/parser/parser.c"
        break;

    case YYSYMBOL_PB_NOT: /* PB_NOT  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 837 "src/parser/parser.c"
        break;

    case YYSYMBOL_PB_IF: /* PB_IF  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 843 "src/parser/parser.c"
        break;

    case YYSYMBOL_PB_ELIF: /* PB_ELIF  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 849 "src/parser/parser.c"
        break;

    case YYSYMBOL_PB_ELSE: /* PB_ELSE  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 855 "src/parser/parser.c"
        break;

    case YYSYMBOL_program: /* program  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 861 "src/parser/parser.c"
        break;

    case YYSYMBOL_context: /* context  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 867 "src/parser/parser.c"
        break;

    case YYSYMBOL_if_statement: /* if_statement  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 873 "src/parser/parser.c"
        break;

    case YYSYMBOL_optional_if: /* optional_if  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 879 "src/parser/parser.c"
        break;

    case YYSYMBOL_bool_expr: /* bool_expr  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 885 "src/parser/parser.c"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 49 "src/parser/parser.y"
         { printf("\n-=[ CURRENT AST ]=-\n"); printAST(((*yyvaluep).node)); printf("\n============================\n");}
#line 891 "src/parser/parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ASTNode **root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, root);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, ASTNode **root)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, root); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ASTNode **root)
{
  YY_USE (yyvaluep);
  YY_USE (root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ASTNode **root)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* program: context  */
#line 56 "src/parser/parser.y"
                {*root = (yyvsp[0].node);}
#line 1282 "src/parser/parser.c"
    break;

  case 3: /* context: %empty  */
#line 59 "src/parser/parser.y"
                                                        {(yyval.node) = newASTContext(NULL, newHashMap());}
#line 1288 "src/parser/parser.c"
    break;

  case 4: /* context: context bool_expr SEMICOLON  */
#line 60 "src/parser/parser.y"
                                        {(yyval.node) = (yyvsp[-2].node); addChildASTNode((yyval.node), (yyvsp[-1].node));}
#line 1294 "src/parser/parser.c"
    break;

  case 5: /* context: context expr SEMICOLON  */
#line 61 "src/parser/parser.y"
                                                {(yyval.node) = (yyvsp[-2].node); addChildASTNode((yyval.node), (yyvsp[-1].node));}
#line 1300 "src/parser/parser.c"
    break;

  case 6: /* context: context if_statement  */
#line 62 "src/parser/parser.y"
                                                {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1306 "src/parser/parser.c"
    break;

  case 7: /* if_statement: PB_IF bool_expr LEFT_BRACE context RIGHT_BRACE optional_if  */
#line 66 "src/parser/parser.y"
                                                                   {(yyval.node) = newASTBranch(SB_IF); addChildASTNode((yyval.node), (yyvsp[-4].node)); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1312 "src/parser/parser.c"
    break;

  case 8: /* optional_if: %empty  */
#line 69 "src/parser/parser.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1318 "src/parser/parser.c"
    break;

  case 9: /* optional_if: PB_ELIF bool_expr LEFT_BRACE context RIGHT_BRACE optional_if  */
#line 70 "src/parser/parser.y"
                                                                        {(yyval.node) = newASTBranch(SB_ELIF); addChildASTNode((yyval.node), (yyvsp[-4].node)); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1324 "src/parser/parser.c"
    break;

  case 10: /* optional_if: PB_ELSE LEFT_BRACE context RIGHT_BRACE  */
#line 71 "src/parser/parser.y"
                                                                                                {(yyval.node) = newASTBranch(SB_ELSE); addChildASTNode((yyval.node), (yyvsp[-1].node));}
#line 1330 "src/parser/parser.c"
    break;

  case 11: /* bool_expr: expr PR_EQ expr  */
#line 74 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1336 "src/parser/parser.c"
    break;

  case 12: /* bool_expr: expr PR_GT expr  */
#line 75 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1342 "src/parser/parser.c"
    break;

  case 13: /* bool_expr: expr PR_GE expr  */
#line 76 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1348 "src/parser/parser.c"
    break;

  case 14: /* bool_expr: expr PR_LT expr  */
#line 77 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1354 "src/parser/parser.c"
    break;

  case 15: /* bool_expr: expr PR_LE expr  */
#line 78 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1360 "src/parser/parser.c"
    break;

  case 16: /* bool_expr: bool_expr PB_AND bool_expr  */
#line 79 "src/parser/parser.y"
                                                                {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1366 "src/parser/parser.c"
    break;

  case 17: /* bool_expr: bool_expr PB_OR bool_expr  */
#line 80 "src/parser/parser.y"
                                                                {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1372 "src/parser/parser.c"
    break;

  case 18: /* bool_expr: LEFT_BRACKET bool_expr RIGHT_BRACKET  */
#line 81 "src/parser/parser.y"
                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1378 "src/parser/parser.c"
    break;

  case 19: /* bool_expr: PB_NOT bool_expr  */
#line 82 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[0].node); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1384 "src/parser/parser.c"
    break;

  case 20: /* expr: IDT PO_AFF expr  */
#line 86 "src/parser/parser.y"
                                                                {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), newASTVariable((yyvsp[-2].identifier))); addChildASTNode((yyval.node), (yyvsp[0].node));}
#line 1390 "src/parser/parser.c"
    break;

  case 21: /* expr: expr PO_ADD expr  */
#line 87 "src/parser/parser.y"
                                                                {if ((yyvsp[-2].node)->nodeType == ST_CST && (yyvsp[0].node)->nodeType == ST_CST){(yyval.node) = newASTConstant((yyvsp[-2].node)->data.value + (yyvsp[0].node)->data.value); freeAST((yyvsp[-2].node)); freeAST((yyvsp[0].node));} else {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}}
#line 1396 "src/parser/parser.c"
    break;

  case 22: /* expr: expr PO_SUB expr  */
#line 88 "src/parser/parser.y"
                                                                {if ((yyvsp[-2].node)->nodeType == ST_CST && (yyvsp[0].node)->nodeType == ST_CST){(yyval.node) = newASTConstant((yyvsp[-2].node)->data.value - (yyvsp[0].node)->data.value); freeAST((yyvsp[-2].node)); freeAST((yyvsp[0].node));} else {if ((yyvsp[0].node)->nodeType == ST_CST) {freeAST((yyvsp[-1].node)); (yyval.node) = newASTOperator(SO_ADD); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), newASTConstant(- (yyvsp[0].node)->data.value)); freeAST((yyvsp[0].node));} else {addChildASTNode((yyval.node), (yyvsp[0].node));}}}
#line 1402 "src/parser/parser.c"
    break;

  case 23: /* expr: expr PO_MUL expr  */
#line 89 "src/parser/parser.y"
                                                                {if ((yyvsp[-2].node)->nodeType == ST_CST && (yyvsp[0].node)->nodeType == ST_CST){(yyval.node) = newASTConstant((yyvsp[-2].node)->data.value * (yyvsp[0].node)->data.value); freeAST((yyvsp[-2].node)); freeAST((yyvsp[0].node));} else {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}}
#line 1408 "src/parser/parser.c"
    break;

  case 24: /* expr: expr PO_DIV expr  */
#line 90 "src/parser/parser.y"
                                                                {if ((yyvsp[-2].node)->nodeType == ST_CST && (yyvsp[0].node)->nodeType == ST_CST){(yyval.node) = newASTConstant((yyvsp[-2].node)->data.value / (yyvsp[0].node)->data.value); freeAST((yyvsp[-2].node)); freeAST((yyvsp[0].node));} else {(yyval.node) = (yyvsp[-1].node); addChildASTNode((yyval.node), (yyvsp[-2].node)); addChildASTNode((yyval.node), (yyvsp[0].node));}}
#line 1414 "src/parser/parser.c"
    break;

  case 25: /* expr: LEFT_BRACKET expr RIGHT_BRACKET  */
#line 91 "src/parser/parser.y"
                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1420 "src/parser/parser.c"
    break;

  case 26: /* expr: CST  */
#line 92 "src/parser/parser.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1426 "src/parser/parser.c"
    break;

  case 27: /* expr: IDT  */
#line 93 "src/parser/parser.y"
                                                                        {(yyval.node) = newASTVariable((yyvsp[0].identifier));}
#line 1432 "src/parser/parser.c"
    break;


#line 1436 "src/parser/parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (root, YY_("syntax error"));
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
                      yytoken, &yylval, root);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 96 "src/parser/parser.y"


int yyerror(ASTNode **root,  char *s) {
	printAST(*root);
	fprintf(stderr, "\n\n\n--------------------------------------\nErreur: %s at line : %d\n--------------------------------------\n", s, yylineno);
	return 0;
}
