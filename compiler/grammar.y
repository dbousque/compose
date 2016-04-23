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
	char *tmp_str;
	t_node *node;
}

%token INT_TYPE FLOAT_TYPE DOUBLE_TYPE LONG_TYPE STR_TYPE CHAR_TYPE
%token TAB
%token DEF
%token INT_DEF STR_DEF FLOAT_DEF DOUBLE_DEF LONG_DEF LIST_DEF CHAR_DEF FUNCTION_DEF
%token VAR
%token RET
%token IF
%token WHILE
%token FOR
%token IN
%token RIGHT_ARROW
%type <node> S ASSIGN EXPR VARIA INTEG FLOA STRIN LON DOUBL LIS CHA VAR_DEF VALUE INDE ARGS FUNCTIO FUNC OPERATIO SLIC SLIC_IND CONDITIO WHILE_LO FOR_LOO1 FOR_LOO2 COMPAR RETUR FUNC_DEC DEC_ARGS TYPE_DEF
%left '<' '>' EQUALITY
%left '+' '-'
%left '*' '/'
%left '['
%left '='

%start S

%%

S		: ASSIGN							{top_node = $1;}
		| EXPR								{top_node = $1;}
		| CONDITIO							{top_node = $1;}
		| WHILE_LO							{top_node = $1;}
		| FOR_LOO1							{top_node = $1;}
		| FOR_LOO2							{top_node = $1;}
		| RETUR								{top_node = $1;}
		| FUNC_DEC							{top_node = $1;}
		;

FUNC_DEC: DEF FUNC DEC_ARGS ')' ':'			{$$ = new_node(FUNCTION_DECL, $2, $3, "", NULL);}
		| DEF FUNC DEC_ARGS ')' RIGHT_ARROW TYPE_DEF ':'	{$$ = new_node(FUNCTION_DECL, $2, $3, "", $6);}
		;

DEC_ARGS: DEC_ARGS ',' TYPE_DEF VARIA		{$4->type = $3;$$ = new_node(FUNCTION_ARGS, $1, $4, "", NULL);}
		| TYPE_DEF VARIA					{$2->type = $1;$$ = $2;}
		;

RETUR	: RET EXPR							{$$ = new_node(RETURN, NULL, $2, "", NULL);}
		;

CONDITIO: IF EXPR ':'						{$$ = new_node(CONDITION, NULL, $2, "", NULL);}
		;

WHILE_LO: WHILE EXPR ':'					{$$ = new_node(WHILE_LOOP, NULL, $2, "", NULL);}
		;

FOR_LOO1: FOR ASSIGN RIGHT_ARROW EXPR ':'	{$$ = new_node(FOR_LOOP1, $2, $4, "", NULL);}
		;

FOR_LOO2: FOR VAR_DEF IN EXPR ':'			{$$ = new_node(FOR_LOOP2, $2, $4, "", NULL);}
		;

ASSIGN	: VAR_DEF '=' EXPR					{$$ = new_node(ASSIGNEMENT, $1, $3, "", NULL);}
		;

EXPR	: '(' EXPR ')'						{$$ = new_node(PRIORITY, NULL, $2, "", NULL);}
		| VALUE								{$$ = $1;}
		| INDE								{$$ = $1;}
		| FUNCTIO							{$$ = $1;}
		| OPERATIO							{$$ = $1;}
		| SLIC								{$$ = $1;}
		| COMPAR							{$$ = $1;}
		;

COMPAR	: EXPR EQUALITY EXPR				{$$ = new_node(EQUALITY_CHECK, $1, $3, "", NULL);}
		| EXPR '>' EXPR						{$$ = new_node(GREATER_THAN, $1, $3, "", NULL);}
		| EXPR '<' EXPR						{$$ = new_node(SMALLER_THAN, $1, $3, "", NULL);}
		| EXPR '>' '=' EXPR					{$$ = new_node(GREATER_EQUAL, $1, $4, "", NULL);}
		| EXPR '<' '=' EXPR					{$$ = new_node(SMALLER_EQUAL, $1, $4, "", NULL);}
		;

OPERATIO: EXPR '+' EXPR						{$$ = new_node(ADD, $1, $3, "", NULL);}
		| EXPR '-' EXPR						{$$ = new_node(MINUS, $1, $3, "", NULL);}
		| EXPR '/' EXPR						{$$ = new_node(DIVIDE, $1, $3, "", NULL);}
		| EXPR '*' EXPR						{$$ = new_node(MULTIPL, $1, $3, "", NULL);}
		;

SLIC	: EXPR '[' SLIC_IND ']'				{$$ = new_node(SLICE, $1, $3, "", NULL);}
		;

SLIC_IND: EXPR ':' EXPR						{$$ = new_node(SLICE_INDEXES, $1, $3, "", NULL);}
		;

VALUE	: INTEG								{$$ = $1;}
		| FLOA								{$$ = $1;}
		| STRIN								{$$ = $1;}
		| LON								{$$ = $1;}
		| DOUBL								{$$ = $1;}
		| VARIA								{$$ = $1;}
		| LIS								{$$ = $1;}
		| CHA								{$$ = $1;}
		;

INDE	: EXPR '[' EXPR ']'					{$$ = new_node(INDEX, $1, $3, "", NULL);}
		;

FUNCTIO	: FUNC ARGS ')'						{$$ = new_node(FUNCTION, $1, $2, "", NULL);}
		;

ARGS	: ARGS ',' EXPR						{$$ = new_node(ARGUMENTS, $1, $3, "", NULL);}
		| EXPR								{$$ = $1;}
		;

FLOA	: FLOAT_DEF							{$$ = new_node(FLOATING, NULL, NULL, yylval.tmp_str, NULL);}
		;

STRIN	: STR_DEF							{$$ = new_node(STRING, NULL, NULL, yylval.tmp_str, NULL);}
		;

LON		: LONG_DEF							{yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';$$ = new_node(LONG, NULL, NULL, yylval.tmp_str, NULL);}
		;

DOUBL	: DOUBLE_DEF						{yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';$$ = new_node(DOUBLE, NULL, NULL, yylval.tmp_str, NULL);}
		;

INTEG	: INT_DEF							{$$ = new_node(INTEGER, NULL, NULL, yylval.tmp_str, NULL);}
		;

CHA		: CHAR_DEF							{yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';$$ = new_node(CHAR, NULL, NULL, yylval.tmp_str, NULL);}
		;

LIS		: TYPE_DEF LIST_DEF					{$$ = new_node(LIST, NULL, NULL, yylval.tmp_str, $1);}
		;

VARIA	: VAR								{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, NULL);}
		;

VAR_DEF	: TYPE_DEF VAR						{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, $1);}
		| VAR								{$$ = new_node(VARIABLE, NULL, NULL, yylval.tmp_str, NULL);}
		;

FUNC	: FUNCTION_DEF						{yylval.tmp_str[ft_strlen(yylval.tmp_str) - 1] = '\0';$$ = new_node(0, NULL, NULL, yylval.tmp_str, NULL);}

TYPE_DEF: INT_TYPE							{$$ = new_node(INTEGER, NULL, NULL, "", NULL);}
		| FLOAT_TYPE						{$$ = new_node(FLOATING, NULL, NULL, "", NULL);}
		| LONG_TYPE							{$$ = new_node(LONG, NULL, NULL, "", NULL);}
		| DOUBLE_TYPE						{$$ = new_node(DOUBLE, NULL, NULL, "", NULL);}
		| STR_TYPE							{$$ = new_node(STRING, NULL, NULL, "", NULL);}
		| CHAR_TYPE							{$$ = new_node(CHAR, NULL, NULL, "", NULL);}
		| TYPE_DEF LIST_DEF					{$$ = new_node(LIST, NULL, NULL, "", $1);}
		;

%%

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