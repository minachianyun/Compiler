%option noyywrap
%{
#include "HW3A.tab.h"
%}

%%
\n			{}
[ \t]+		{ /* do nothing */ }
"add"		{return ADD;}
"sub"		{return SUB;}
"mul"		{return MUL;}
"mod"		{return MOD;}
"inc"		{return INC;}
"dec"		{return DEC;}
"load"		{return LOAD;}
[0-9]+		{ yylval.ival= atoi(yytext);return(INUMBER); }
.			{ return(yytext[0]); }
<<EOF>>	{return END_OF_FILE; }
%%