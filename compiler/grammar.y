%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "../utils/utils.h"

t_node			*top_node;

extern int yylex();
%}

%union
{
	char type;
	char *tmp_str;
	t_node *node;
}

%token INT_TYPE FLOAT_TYPE DOUBLE_TYPE LONG_TYPE STR_TYPE CHAR_TYPE
%token TAB
%token DEF
%token INT_DEF STR_DEF FLOAT_DEF DOUBLE_DEF LONG_DEF LIST_DEF CHAR_DEF FUNCTION_DEF
%token VAR
%token RET
%type <node> S ASSIGN EXPR VARIA INTEG FLOA STRIN LON DOUBL LIS CHA VAR_DEF VALUE INDE ARGS FUNCTIO FUNC
%type <type> TYPE_DEF
%left '+' '-'
%left '*' '/' '='

%start S

%%

S		: ASSIGN				{top_node = $1;}
		| EXPR					{top_node = $1;}
		;

ASSIGN	: VAR_DEF '=' EXPR		{$$ = new_node(ASSIGNEMENT, $1, $3, "", 0);}
		;

EXPR	: VALUE					{$$ = $1;}
		| INDE					{$$ = $1;}
		| FUNCTIO				{$$ = $1;}
		;

VALUE	: INTEG					{$$ = $1;}
		| FLOA					{$$ = $1;}
		| STRIN					{$$ = $1;}
		| LON					{$$ = $1;}
		| DOUBL					{$$ = $1;}
		| VARIA					{$$ = $1;}
		| LIS					{$$ = $1;}
		| CHA					{$$ = $1;}
		;

INDE	: INDE '[' EXPR ']'		{$$ = new_node(INDEX, $1, $3, "", 0);}
		| FUNCTIO '[' EXPR ']'	{$$ = new_node(INDEX, $1, $3, "", 0);}
		| LIS '[' EXPR ']'		{$$ = new_node(INDEX, $1, $3, "", 0);}
		| STRIN '[' EXPR ']'	{$$ = new_node(INDEX, $1, $3, "", 0);}
		| VARIA '[' EXPR ']'	{$$ = new_node(INDEX, $1, $3, "", 0);}
		;

FUNCTIO	: FUNC ARGS ')'			{$$ = new_node(FUNCTION, $1, $2, "", 0);}
		;

ARGS	: ARGS ',' EXPR			{$$ = new_node(ARGUMENTS, $1, $3, "", 0);}
		| EXPR					{$$ = $1;}
		;

FLOA	: FLOAT_DEF				{$$ = new_node(FLOATING, NULL, NULL, yylval.tmp_str, 0);}
		;

STRIN	: STR_DEF				{$$ = new_node(STRING, NULL, NULL, yylval.tmp_str, 0);}
		;

LON		: LONG_DEF				{$$ = new_node(LONG, NULL, NULL, yylval.tmp_str, 0);}
		;

DOUBL	: DOUBLE_DEF			{$$ = new_node(DOUBLE, NULL, NULL, yylval.tmp_str, 0);}
		;

INTEG	: INT_DEF				{$$ = new_node(INTEGER, NULL, NULL, yylval.tmp_str, 0);}
		;

CHA		: CHAR_DEF				{$$ = new_node(CHAR, NULL, NULL, yylval.tmp_str, 0);}
		;

LIS		: TYPE_DEF LIST_DEF		{$$ = new_node(LIST, NULL, NULL, yylval.tmp_str, $1);}
		;

VARIA	: VAR					{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, 0);}
		;

VAR_DEF	: TYPE_DEF VAR			{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, $1);}
		| VAR					{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, 0);}
		;

FUNC	: FUNCTION_DEF			{yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';$$ = new_node(0, NULL, NULL, yylval.tmp_str, 0);}

TYPE_DEF: INT_TYPE				{$$ = INTEGER;}
		| FLOAT_TYPE			{$$ = FLOATING;}
		| LONG_TYPE				{$$ = LONG;}
		| DOUBLE_TYPE			{$$ = DOUBLE;}
		| STR_TYPE				{$$ = STRING;}
		| CHAR_TYPE				{$$ = CHAR;}
		;

%%

int yyerror(char *msg)
{
	printf("%s\n", msg);
	exit(1);
	return (0);
}

t_node	*get_tree()
{
	top_node = NULL;
	yyparse();
	return (top_node);
}

int		main(void)
{
	t_node	*top_node;

	top_node = get_tree();
	print_tree(top_node);
	printf("\n");
	return (0);
}