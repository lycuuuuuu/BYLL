
%{
    #include "draw.tab.hpp"
    #include <string>
%}

%option noyywrap

%%
"+"                         {return PLUS;}
"-"                         {return MINUS;}
"**"                        {return POWER;}
"*"                         {return MUL;}
"--"|"//"                   {return COMMENT;}
"/"                         {return DIV;}
"("                         {return L_BRACKET;}
")"                         {return R_BRACKET;}
","                         {return COMMA;}
";"                         {return FENHAO;}
[Rr][Ii]                    {return PI;}
[Rr][Oo][Tt]                {return ROT;}
[Oo][Rr][Ii][Gg][Ii][Nn]    {return ORIGIN;}
[Ss][Cc][Aa][Ll][Ee]        {return SCALE;}
[Ii][Ss]                    {return IS;}
[Ff][Oo][Rr]                {return FOR;}
[Ff][Rr][Oo][Mm]            {return FROM;}
[Tt][Oo]                    {return TO;}
[Ss][Tt][Ee][Pp]            {return STEP;}
[Dd][Rr][Aa][Ww]            {return DRAW;}
[Ss][Ii][Nn]                {return SIN;}
[Cc][Oo][Ss]                {return COS;}
[Tt][Aa][Nn]                {return TAN;}
[Ss][Qq][Rr][Tt]            {return SQRT;}
[Ee][Xx][Pp]                {return EXP;}
[Ll][Nn]                    {return LN;}
[Pp][Ii]                    {yylval.float_val = 3.1415926; return CONST_ID;}
[0-9]+(\.[0-9]+)?           {yylval.float_val = atof(yytext);return CONST_ID;}
[a-zA-Z]+                   {return ID;}
[ \t]                       {}
\n                          {return EOL;}
.                           {printf("Unrecognized character: %s\n", yytext);}
%%