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

%token INT_TYPE FLOAT_TYPE DOUBLE_TYPE LONG_TYPE STR_TYPE
%token TAB
%token DEF
%token INT_DEF STR_DEF FLOAT_DEF DOUBLE_DEF LONG_DEF
%token VAR
%token RET
%type <node> S ASSIGN EXPR VARIA INTEG FLOA STRIN LON DOUBL
%type <type> TYPE_DEF
%left '+' '-'
%left '*' '/' '='

%start S

%%

S		: ASSIGN				{top_node = $1;}
		| EXPR					{top_node = $1;}
		;

ASSIGN	: EXPR '=' EXPR			{$$ = new_node(ASSIGNEMENT, $1, $3, "", 0);}
		;

EXPR	: INTEG					{$$ = $1;}
		| FLOA					{$$ = $1;}
		| STRIN					{$$ = $1;}
		| LON					{$$ = $1;}
		| DOUBL					{$$ = $1;}
		| VARIA					{$$ = $1;}
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

VARIA	: TYPE_DEF VAR			{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, $1);}
		| VAR					{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, 0);}
		;

TYPE_DEF: INT_TYPE				{$$ = INTEGER;}
		| FLOAT_TYPE			{$$ = FLOATING;}
		| LONG_TYPE				{$$ = LONG;}
		| DOUBLE_TYPE			{$$ = DOUBLE;}
		| STR_TYPE				{$$ = STRING;}
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