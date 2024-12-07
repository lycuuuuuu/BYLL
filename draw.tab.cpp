/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "draw.y"

    #include "calValue.cpp"
    #include <fstream>
    #include <vector>
    #include <cstdlib> // for system()
    #include <sstream>


    using namespace std;
    extern int yylex();
    void yyerror(const char *s) {
        printf("Error: %s\n", s);
    }
    string Cal[10];

    int count1=0;

    float start[5],endPlace[5],step[5];
    int count_ses = 0; //作为上面三个数组的索引

    Queue<float>ConstID1;//常数队列
    Queue<float>ConstID2;//常数队列

    typedef struct{
        float x;
        float y;
    }Point;

    Point origin[5];
    Point rot[5];
    Point scale[5]={{1,1},{1,1},{1,1},{1,1},{1,1}};
    string test;//检测:绘图语句中，前后的ID是否相同。test用来存放第一个ID
    string calculator;//用于存放运算顺序，每一次运算都用一位数字表示，通过查表获取其含义

    int flag_xOry = 0;//用来判断当前应该入x的常数队列还是y的常数队列

    int ID_flag = 0;
    int Init_count = 0;

#line 111 "draw.tab.cpp"

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

#include "draw.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST_ID = 3,                   /* CONST_ID  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_PI = 5,                         /* PI  */
  YYSYMBOL_ORIGIN = 6,                     /* ORIGIN  */
  YYSYMBOL_SCALE = 7,                      /* SCALE  */
  YYSYMBOL_ROT = 8,                        /* ROT  */
  YYSYMBOL_IS = 9,                         /* IS  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_FROM = 11,                      /* FROM  */
  YYSYMBOL_TO = 12,                        /* TO  */
  YYSYMBOL_STEP = 13,                      /* STEP  */
  YYSYMBOL_DRAW = 14,                      /* DRAW  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_POWER = 19,                     /* POWER  */
  YYSYMBOL_L_BRACKET = 20,                 /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 21,                 /* R_BRACKET  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_COMMENT = 23,                   /* COMMENT  */
  YYSYMBOL_FENHAO = 24,                    /* FENHAO  */
  YYSYMBOL_EOL = 25,                       /* EOL  */
  YYSYMBOL_SIN = 26,                       /* SIN  */
  YYSYMBOL_COS = 27,                       /* COS  */
  YYSYMBOL_TAN = 28,                       /* TAN  */
  YYSYMBOL_SQRT = 29,                      /* SQRT  */
  YYSYMBOL_EXP = 30,                       /* EXP  */
  YYSYMBOL_LN = 31,                        /* LN  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_statements = 34,                /* statements  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_expressions = 36,               /* expressions  */
  YYSYMBOL_expression = 37,                /* expression  */
  YYSYMBOL_factor = 38,                    /* factor  */
  YYSYMBOL_exp1 = 39,                      /* exp1  */
  YYSYMBOL_exp2 = 40,                      /* exp2  */
  YYSYMBOL_expressions_const = 41,         /* expressions_const  */
  YYSYMBOL_expression_const = 42,          /* expression_const  */
  YYSYMBOL_factor_const = 43,              /* factor_const  */
  YYSYMBOL_exp1_const = 44,                /* exp1_const  */
  YYSYMBOL_exp2_const = 45                 /* exp2_const  */
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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    66,    69,   105,   110,   116,   122,   135,
     144,   147,   151,   158,   161,   165,   173,   176,   181,   187,
     203,   207,   211,   214,   218,   222,   226,   230,   234,   248,
     258,   262,   266,   273,   277,   281,   289,   293,   299,   306,
     309,   314,   318,   323,   328,   333,   338,   343
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST_ID", "ID", "PI",
  "ORIGIN", "SCALE", "ROT", "IS", "FOR", "FROM", "TO", "STEP", "DRAW",
  "PLUS", "MINUS", "MUL", "DIV", "POWER", "L_BRACKET", "R_BRACKET",
  "COMMA", "COMMENT", "FENHAO", "EOL", "SIN", "COS", "TAN", "SQRT", "EXP",
  "LN", "$accept", "program", "statements", "statement", "expressions",
  "expression", "factor", "exp1", "exp2", "expressions_const",
  "expression_const", "factor_const", "exp1_const", "exp2_const", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
#endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,     4,     6,    18,    25,    33,    60,    16,    27,    31,
      45,    58,   -82,    54,    72,    45,    45,   -82,    74,    74,
      45,    64,    79,    87,    88,    89,    90,   -82,     9,    39,
     -82,   100,    45,    95,   -82,    36,   105,   100,   100,    -9,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      74,   125,   -82,    45,    45,   -82,    -7,    -5,     5,     7,
      34,    38,   -82,   -82,   -82,   -82,   -82,    45,   118,   127,
     -82,   -82,   -82,   -82,   -82,   -82,   137,   -82,   -82,    45,
     138,   133,    15,   -82,   -82,    59,    59,    15,   134,   135,
     136,   139,   140,   141,   142,    21,    63,   -82,   143,   143,
     143,    77,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    59,   -82,   115,   117,   119,   126,   128,
     130,   144,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,    29,    30,
      33,    36,     0,     0,     3,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,    40,     0,     0,     0,     0,
       0,     0,    31,    32,    34,    35,    41,     0,     0,     0,
      42,    43,    44,    45,    46,    47,     0,     6,     7,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,    13,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    14,    15,    22,    23,    24,    25,
      26,    27,    28,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   151,    50,    19,   -29,   -82,   -81,   -15,
      71,    47,   -82,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    94,    95,    96,    97,    98,    27,
      28,    29,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    36,    37,    38,    99,   100,    46,    47,    46,    47,
      46,    47,    55,     8,    70,     9,    71,    51,    83,    84,
      46,    47,    46,    47,    46,    47,    72,    10,    73,    11,
      85,    86,   126,    12,    66,    87,   109,   110,    68,    69,
      14,    88,    89,    90,    91,    92,    93,    15,    17,    46,
      47,    16,    76,    46,    47,    74,    48,    49,    53,    75,
      18,    19,    83,    84,    80,    20,     1,     2,     3,    32,
       4,    21,    22,    23,    24,    25,    26,    17,    33,    87,
     111,   112,   124,   125,    40,    88,    89,    90,    91,    92,
      93,    39,   109,   110,    20,    64,    65,    34,   114,    41,
      21,    22,    23,    24,    25,    26,   101,    42,    43,    44,
      45,    56,    57,    58,    59,    60,    61,    62,    63,    50,
      52,   115,   116,   117,   118,   119,   120,    54,   122,   123,
     109,   110,   109,   110,   109,   110,   127,    67,   128,    77,
     129,   109,   110,   109,   110,   109,   110,   130,    78,   131,
      79,   132,    81,    82,   102,   103,   104,    13,   121,   105,
     106,   107,   113,     0,   108,   133
};

static const yytype_int8 yycheck[] =
{
      15,    16,    18,    19,    85,    86,    15,    16,    15,    16,
      15,    16,    21,     9,    21,     9,    21,    32,     3,     4,
      15,    16,    15,    16,    15,    16,    21,     9,    21,     4,
      15,    16,   113,     0,    50,    20,    15,    16,    53,    54,
      24,    26,    27,    28,    29,    30,    31,    20,     3,    15,
      16,    20,    67,    15,    16,    21,    17,    18,    22,    21,
      15,    16,     3,     4,    79,    20,     6,     7,     8,    11,
      10,    26,    27,    28,    29,    30,    31,     3,    24,    20,
      17,    18,   111,   112,    20,    26,    27,    28,    29,    30,
      31,    20,    15,    16,    20,    48,    49,    25,    21,    20,
      26,    27,    28,    29,    30,    31,    87,    20,    20,    20,
      20,    40,    41,    42,    43,    44,    45,    46,    47,    19,
      25,   102,   103,   104,   105,   106,   107,    22,   109,   110,
      15,    16,    15,    16,    15,    16,    21,    12,    21,    21,
      21,    15,    16,    15,    16,    15,    16,    21,    21,    21,
      13,    21,    14,    20,    20,    20,    20,     6,   108,    20,
      20,    20,    19,    -1,    22,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    10,    33,    34,    35,     9,     9,
       9,     4,     0,    35,    24,    20,    20,     3,    15,    16,
      20,    26,    27,    28,    29,    30,    31,    41,    42,    43,
      44,    45,    11,    24,    25,    41,    41,    45,    45,    42,
      20,    20,    20,    20,    20,    20,    15,    16,    17,    18,
      19,    41,    25,    22,    22,    21,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    43,    45,    12,    41,    41,
      21,    21,    21,    21,    21,    21,    41,    21,    21,    13,
      41,    14,    20,     3,     4,    15,    16,    20,    26,    27,
      28,    29,    30,    31,    36,    37,    38,    39,    40,    40,
      40,    37,    20,    20,    20,    20,    20,    20,    22,    15,
      16,    17,    18,    19,    21,    37,    37,    37,    37,    37,
      37,    36,    37,    37,    38,    38,    40,    21,    21,    21,
      21,    21,    21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    36,
      37,    37,    37,    38,    38,    38,    39,    39,    39,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      42,    42,    42,    43,    43,    43,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    45
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     4,     3,     7,     7,    14,     1,
       1,     3,     3,     1,     3,     3,     1,     2,     2,     1,
       1,     3,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     3,     3,     1,     3,     3,     1,     2,     2,     1,
       3,     3,     4,     4,     4,     4,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
yyparse (void)
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 3: /* statements: statement FENHAO EOL  */
#line 66 "draw.y"
                        {

    }
#line 1222 "draw.tab.cpp"
    break;

  case 4: /* statements: statements statement FENHAO EOL  */
#line 69 "draw.y"
                                    {
        //printf("成功识别");
    }
#line 1230 "draw.tab.cpp"
    break;

  case 5: /* statement: ROT IS expressions_const  */
#line 105 "draw.y"
                            {
        //旋转(逆时针CONST_ID)
        rot[Init_count].x = (yyvsp[0].float_val);
        printf("rot%d is set to %.2f\n",Init_count,rot[Init_count].x);
    }
#line 1240 "draw.tab.cpp"
    break;

  case 6: /* statement: ORIGIN IS L_BRACKET expressions_const COMMA expressions_const R_BRACKET  */
#line 110 "draw.y"
                                                                            {
        //设置原点(默认左上角顶点)
        origin[Init_count].x = (yyvsp[-3].float_val);
        origin[Init_count].y = (yyvsp[-1].float_val);
        printf("origin%d is set to(%.2f,%.2f)\n",Init_count,origin[Init_count].x,origin[Init_count].y);
    }
#line 1251 "draw.tab.cpp"
    break;

  case 7: /* statement: SCALE IS L_BRACKET expressions_const COMMA expressions_const R_BRACKET  */
#line 116 "draw.y"
                                                                           {
        //设置x,y轴比例
        scale[Init_count].x = (yyvsp[-3].float_val);
        scale[Init_count].y = (yyvsp[-1].float_val);
        printf("scale%d is set to (%.2f,%.2f)\n",Init_count,scale[Init_count].x,scale[Init_count].y);
    }
#line 1262 "draw.tab.cpp"
    break;

  case 8: /* statement: FOR ID FROM expressions_const TO expressions_const STEP expressions_const DRAW L_BRACKET expressions COMMA expressions R_BRACKET  */
#line 122 "draw.y"
                                                                                                                                     {
        //绘制图像
        start[count_ses] = (yyvsp[-10].float_val);
        endPlace[count_ses] = (yyvsp[-8].float_val);
        step[count_ses] = (yyvsp[-6].float_val);
        //test = $2;
        count_ses++;
        Init_count++;
    }
#line 1276 "draw.tab.cpp"
    break;

  case 9: /* expressions: expression  */
#line 135 "draw.y"
              {
        //expression是加减乘除乘方后的结果
        Cal[count1] = calculator;
        calculator = "";
        count1++;
    }
#line 1287 "draw.tab.cpp"
    break;

  case 10: /* expression: factor  */
#line 144 "draw.y"
          {
    //factor:乘方乘除后结果
    }
#line 1295 "draw.tab.cpp"
    break;

  case 11: /* expression: expression PLUS expression  */
#line 147 "draw.y"
                               {
        //$$ = $1 + $3;
        calculator += "6";
    }
#line 1304 "draw.tab.cpp"
    break;

  case 12: /* expression: expression MINUS expression  */
#line 151 "draw.y"
                                {
        //$$ =$1 - $3;
        calculator += "7";
    }
#line 1313 "draw.tab.cpp"
    break;

  case 13: /* factor: exp1  */
#line 158 "draw.y"
        {
        //一元加减结果
    }
#line 1321 "draw.tab.cpp"
    break;

  case 14: /* factor: factor MUL factor  */
#line 161 "draw.y"
                      {
        //$$ = $1 * $3;
        calculator += "4";
    }
#line 1330 "draw.tab.cpp"
    break;

  case 15: /* factor: factor DIV factor  */
#line 165 "draw.y"
                      {
        //$$ = $1 / $3;
        //if($3==0){yyerror("除数为0");}
        calculator += "5";
    }
#line 1340 "draw.tab.cpp"
    break;

  case 16: /* exp1: exp2  */
#line 173 "draw.y"
        {
        //乘方结果
    }
#line 1348 "draw.tab.cpp"
    break;

  case 17: /* exp1: PLUS exp2  */
#line 176 "draw.y"
              {
        //一元加
        calculator += "2";

    }
#line 1358 "draw.tab.cpp"
    break;

  case 18: /* exp1: MINUS exp2  */
#line 181 "draw.y"
               {
        //一元减
        calculator += "3";
    }
#line 1367 "draw.tab.cpp"
    break;

  case 19: /* exp2: CONST_ID  */
#line 187 "draw.y"
            {//常量
        calculator += "Y";
        float constid = (yyvsp[0].float_val);
        if(count1%2==0){
            ConstID1.enqueue(constid);
            flag_xOry++;
        }
        else if(count1%2==1){
            ConstID2.enqueue(constid);
            flag_xOry = 0;
        }
        else{
            yyerror("x/y 队列异常");
        }

    }
#line 1388 "draw.tab.cpp"
    break;

  case 20: /* exp2: ID  */
#line 203 "draw.y"
       {//需要检测此ID和绘图处的ID是否匹配
        //if(test!=$1){yyerror("前后ID不匹配");}
        calculator += "Z";
    }
#line 1397 "draw.tab.cpp"
    break;

  case 21: /* exp2: L_BRACKET expression R_BRACKET  */
#line 207 "draw.y"
                                   {
        //带括号的式子:递归到expression
        //不需要其它动作，能识别并递归就行
    }
#line 1406 "draw.tab.cpp"
    break;

  case 22: /* exp2: exp2 POWER exp2  */
#line 211 "draw.y"
                    {//乘方
        calculator += "1";
    }
#line 1414 "draw.tab.cpp"
    break;

  case 23: /* exp2: SIN L_BRACKET expression R_BRACKET  */
#line 214 "draw.y"
                                       {
            //sin
        calculator += "8";
    }
#line 1423 "draw.tab.cpp"
    break;

  case 24: /* exp2: COS L_BRACKET expression R_BRACKET  */
#line 218 "draw.y"
                                       {
            //cos
        calculator += "9";
    }
#line 1432 "draw.tab.cpp"
    break;

  case 25: /* exp2: TAN L_BRACKET expression R_BRACKET  */
#line 222 "draw.y"
                                       {
            //tan
        calculator += "A";
    }
#line 1441 "draw.tab.cpp"
    break;

  case 26: /* exp2: SQRT L_BRACKET expression R_BRACKET  */
#line 226 "draw.y"
                                        {
            //sqrt
        calculator += "B";
    }
#line 1450 "draw.tab.cpp"
    break;

  case 27: /* exp2: EXP L_BRACKET expression R_BRACKET  */
#line 230 "draw.y"
                                       {
            //exp
        calculator += "C";
    }
#line 1459 "draw.tab.cpp"
    break;

  case 28: /* exp2: LN L_BRACKET expression R_BRACKET  */
#line 234 "draw.y"
                                      {
            //ln
        calculator += "D";
    }
#line 1468 "draw.tab.cpp"
    break;

  case 29: /* expressions_const: expression_const  */
#line 248 "draw.y"
                    {
        (yyval.float_val) = (yyvsp[0].float_val);
        //expression是加减乘除乘方后的结果
        //Cal[count1] = calculator;
        //calculator = "";
        //count1++;
    }
#line 1480 "draw.tab.cpp"
    break;

  case 30: /* expression_const: factor_const  */
#line 258 "draw.y"
                {
        (yyval.float_val) = (yyvsp[0].float_val);
    //factor:乘方乘除后结果
    }
#line 1489 "draw.tab.cpp"
    break;

  case 31: /* expression_const: expression_const PLUS expression_const  */
#line 262 "draw.y"
                                           {
        (yyval.float_val) = (yyvsp[-2].float_val) + (yyvsp[0].float_val);
        //calculator += "6";
    }
#line 1498 "draw.tab.cpp"
    break;

  case 32: /* expression_const: expression_const MINUS expression_const  */
#line 266 "draw.y"
                                            {
        (yyval.float_val) =(yyvsp[-2].float_val) - (yyvsp[0].float_val);
        //calculator += "7";
    }
#line 1507 "draw.tab.cpp"
    break;

  case 33: /* factor_const: exp1_const  */
#line 273 "draw.y"
              {
        (yyval.float_val) = (yyvsp[0].float_val);
        //一元加减结果
    }
#line 1516 "draw.tab.cpp"
    break;

  case 34: /* factor_const: factor_const MUL factor_const  */
#line 277 "draw.y"
                                  {
        (yyval.float_val) = (yyvsp[-2].float_val) * (yyvsp[0].float_val);
        //calculator += "4";
    }
#line 1525 "draw.tab.cpp"
    break;

  case 35: /* factor_const: factor_const DIV factor_const  */
#line 281 "draw.y"
                                  {
        (yyval.float_val) = (yyvsp[-2].float_val) / (yyvsp[0].float_val);
        //if($3==0){yyerror("除数为0");}
        //calculator += "5";
    }
#line 1535 "draw.tab.cpp"
    break;

  case 36: /* exp1_const: exp2_const  */
#line 289 "draw.y"
              {
        (yyval.float_val) =(yyvsp[0].float_val);
        //乘方结果
    }
#line 1544 "draw.tab.cpp"
    break;

  case 37: /* exp1_const: PLUS exp2_const  */
#line 293 "draw.y"
                    {
        (yyval.float_val) = (yyvsp[0].float_val);
        //一元加
        //calculator += "2";

    }
#line 1555 "draw.tab.cpp"
    break;

  case 38: /* exp1_const: MINUS exp2_const  */
#line 299 "draw.y"
                     {
        (yyval.float_val) = -(yyvsp[0].float_val);
        //一元减
        //calculator += "3";
    }
#line 1565 "draw.tab.cpp"
    break;

  case 39: /* exp2_const: CONST_ID  */
#line 306 "draw.y"
            {//常量
        (yyval.float_val) = (yyvsp[0].float_val);
    }
#line 1573 "draw.tab.cpp"
    break;

  case 40: /* exp2_const: L_BRACKET expression_const R_BRACKET  */
#line 309 "draw.y"
                                         {
        (yyval.float_val) = (yyvsp[-1].float_val);
        //带括号的式子:递归到expression
        //不需要其它动作，能识别并递归就行
    }
#line 1583 "draw.tab.cpp"
    break;

  case 41: /* exp2_const: exp2_const POWER exp2_const  */
#line 314 "draw.y"
                                {//乘方
        (yyval.float_val) = pow((yyvsp[-2].float_val),(yyvsp[0].float_val));
        //calculator += "1";
    }
#line 1592 "draw.tab.cpp"
    break;

  case 42: /* exp2_const: SIN L_BRACKET expression_const R_BRACKET  */
#line 318 "draw.y"
                                             {
        (yyval.float_val) = sin((yyvsp[-1].float_val));
            //sin
        //calculator += "8";
    }
#line 1602 "draw.tab.cpp"
    break;

  case 43: /* exp2_const: COS L_BRACKET expression_const R_BRACKET  */
#line 323 "draw.y"
                                             {
        (yyval.float_val) = cos((yyvsp[-1].float_val));
            //cos
        //calculator += "9";
    }
#line 1612 "draw.tab.cpp"
    break;

  case 44: /* exp2_const: TAN L_BRACKET expression_const R_BRACKET  */
#line 328 "draw.y"
                                             {
        (yyval.float_val) = tan((yyvsp[-1].float_val));
            //tan
        //calculator += "A";
    }
#line 1622 "draw.tab.cpp"
    break;

  case 45: /* exp2_const: SQRT L_BRACKET expression_const R_BRACKET  */
#line 333 "draw.y"
                                              {
        (yyval.float_val) = sqrt((yyvsp[-1].float_val));
            //sqrt
        //calculator += "B";
    }
#line 1632 "draw.tab.cpp"
    break;

  case 46: /* exp2_const: EXP L_BRACKET expression_const R_BRACKET  */
#line 338 "draw.y"
                                             {
        (yyval.float_val) = exp((yyvsp[-1].float_val));
            //exp
        //calculator += "C";
    }
#line 1642 "draw.tab.cpp"
    break;

  case 47: /* exp2_const: LN L_BRACKET expression_const R_BRACKET  */
#line 343 "draw.y"
                                            {
        (yyval.float_val) = log((yyvsp[-1].float_val));
            //ln
        //calculator += "D";
    }
#line 1652 "draw.tab.cpp"
    break;


#line 1656 "draw.tab.cpp"

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
      yyerror (YY_("syntax error"));
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 352 "draw.y"



int main(int argc, char **argv)
{
    yyparse();

    for(int i=0;i<10;i++){
        cout<<Cal[i]<<endl;
    }

    //Cal[0] = "Z9";
    //Cal[1] = "ZA";

    std::ofstream outfile("params.txt");
    if (!outfile.is_open()) {
        std::cerr << "无法打开文件进行写入。\n";
        return 1;
    }

    outfile << "10" << "\n";
    for (const auto& s : Cal) outfile << s << "\n";

    outfile << ConstID1.size() << "\n";
    Queue<float> temp1 = ConstID1;
    while (!temp1.empty()) { outfile << temp1.dequeue() << " "; } outfile << "\n";

    outfile << ConstID2.size() << "\n";
    Queue<float> temp2 = ConstID2;
    while (!temp2.empty()) { outfile << temp2.dequeue() << " "; } outfile << "\n";

    for(int i=0;i<5;i++){
        outfile << origin[i].x << " " << origin[i].y << "\n";
        outfile << rot[i].x << " " << rot[i].y << "\n";
        outfile << scale[i].x << " " << scale[i].y << "\n";
    }
    outfile << "5" << " ";
    for (float f : start) outfile << f << " ";
    outfile << "\n";

    outfile << 5 << " ";
    for (float f : endPlace) outfile << f << " ";
    outfile << "\n";

    outfile << "5" << " ";
    for (float f : step) outfile << f << " ";
    outfile << "\n";


    outfile.close();

        int result = system("C:\\Users\\lyc\\Desktop\\3\\3.1\\BYYL\\RT+D_Rx\\x64\\Debug\\RT+D_Rx.exe");
        if (result != 0) {
            std::cerr << "执行B出错: " << result << std::endl;
            return 1;
        }
    string input;
    while(1){
        getline(cin, input); // Read a line of input

        if (input == "exit") {
            break; // Exit the loop if the input is "exit"
        }
    }
    return 0;
}
