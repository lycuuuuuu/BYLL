/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DRAW_TAB_HPP_INCLUDED
# define YY_YY_DRAW_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CONST_ID = 258,                /* CONST_ID  */
    ID = 259,                      /* ID  */
    PI = 260,                      /* PI  */
    ORIGIN = 261,                  /* ORIGIN  */
    SCALE = 262,                   /* SCALE  */
    ROT = 263,                     /* ROT  */
    IS = 264,                      /* IS  */
    FOR = 265,                     /* FOR  */
    FROM = 266,                    /* FROM  */
    TO = 267,                      /* TO  */
    STEP = 268,                    /* STEP  */
    DRAW = 269,                    /* DRAW  */
    PLUS = 270,                    /* PLUS  */
    MINUS = 271,                   /* MINUS  */
    MUL = 272,                     /* MUL  */
    DIV = 273,                     /* DIV  */
    POWER = 274,                   /* POWER  */
    L_BRACKET = 275,               /* L_BRACKET  */
    R_BRACKET = 276,               /* R_BRACKET  */
    COMMA = 277,                   /* COMMA  */
    COMMENT = 278,                 /* COMMENT  */
    FENHAO = 279,                  /* FENHAO  */
    EOL = 280,                     /* EOL  */
    SIN = 281,                     /* SIN  */
    COS = 282,                     /* COS  */
    TAN = 283,                     /* TAN  */
    SQRT = 284,                    /* SQRT  */
    EXP = 285,                     /* EXP  */
    LN = 286                       /* LN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "draw.y"

    int int_val;
    float float_val;

#line 100 "draw.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DRAW_TAB_HPP_INCLUDED  */
