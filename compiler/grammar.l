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
"int"						{return (INT_TYPE);}
"double"					{return (DOUBLE_TYPE);}
"float"						{return (FLOAT_TYPE);}
"long"						{return (LONG_TYPE);}
"str"						{return (STR_TYPE);}
"def"						{return (DEF);}
"\t"						{return (TAB);}
\"[^\"]*\"					{yylval.tmp_str = ft_strdup(yytext); return (STR_DEF);}
[a-z][a-z_0-9]*				{yylval.tmp_str = ft_strdup(yytext); return (VAR);}
[0-9]+\.[0-9]+d				{yylval.tmp_str = ft_strdup(yytext); return (DOUBLE_DEF);}
[0-9]+\.[0-9]+				{yylval.tmp_str = ft_strdup(yytext); return (FLOAT_DEF);}
[0-9]+l						{yylval.tmp_str = ft_strdup(yytext); return (LONG_DEF);}
[0-9]+						{yylval.tmp_str = ft_strdup(yytext); return (INT_DEF);}
[\[\]\+\-\*\/(),=ld\n]		{return (yytext[0]);}
[ \r\v\f]					{ ; }
.							{return(0);}

%%
