%token token1 
%token token2 
%token token3 
%token token4 
%token token5 
%token token6 
%token token7 
%token token8 
%start BOOL 
%% 
BOOL: BOOL token4 NEWNONTERMINAL1 {push("Booleans: BOOL \"|\" BOOL -> BOOL", 2);}
| BOOL token5 NEWNONTERMINAL1 {push("Booleans: BOOL \"&\" BOOL -> BOOL", 2);}
| NEWNONTERMINAL1 ; 

NEWNONTERMINAL1: token2 {push("Booleans: \"true\" -> BOOL", 0);}
| token3 {push("Booleans: \"false\" -> BOOL", 0);}
| token6 token7 BOOL token8 
{push("Booleans: \"not\" \"(\" BOOL \")\" -> BOOL", 1);}
| token7 BOOL token8 {push("Booleans: \"(\" BOOL \")\" -> BOOL", 1);}
; 
%%

#include "lex.yy.c"
