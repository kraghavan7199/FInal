/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
