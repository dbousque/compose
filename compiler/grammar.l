%{
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../utils/utils.h"
#include "y.tab.h"
%}

%option noyywrap

%%

"return"					{return (RET);}
"def"						{return (DEF);}
"if"						{return (IF);}
"for"						{return (FOR);}
"while"						{return (WHILE);}
"in"						{return (IN);}

"->"						{return (RIGHT_ARROW);}
"=="						{return (EQUALITY);}

"int"						{return (INT_TYPE);}
"double"					{return (DOUBLE_TYPE);}
"float"						{return (FLOAT_TYPE);}
"long"						{return (LONG_TYPE);}
"str"						{return (STR_TYPE);}
"char"						{return (CHAR_TYPE);}

"\t"						{return (TAB);}

\"(\\.|[^\\"\n])*\"			{yylval.tmp_str = ft_strdup(yytext); return (STR_DEF);}
[a-z][a-z_0-9]*\(			{yylval.tmp_str = ft_strdup(yytext); return (FUNCTION_DEF);}
[a-z][a-z_0-9]*				{yylval.tmp_str = ft_strdup(yytext); return (VAR);}
[0-9]+\.[0-9]+d				{yylval.tmp_str = ft_strdup(yytext); return (DOUBLE_DEF);}
[0-9]+\.[0-9]+				{yylval.tmp_str = ft_strdup(yytext); return (FLOAT_DEF);}
[0-9]+l						{yylval.tmp_str = ft_strdup(yytext); return (LONG_DEF);}
[0-9]+c						{yylval.tmp_str = ft_strdup(yytext); return (CHAR_DEF);}
[0-9]+						{yylval.tmp_str = ft_strdup(yytext); return (INT_DEF);}

\[\]						{return (LIST_DEF);}

[\[\]\+\-\*\/\(\),=ld\n:><]	{return (yytext[0]);}
[ \r\v\f\t]					{ ; }
.							{return(0);}

%%
