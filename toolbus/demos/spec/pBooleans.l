true_sym "true"
false_sym "false"
not_sym "not"

white_space [ \n\t\f\r]
comment "%%"([^\n]*)"\n"

%{
/* #include "y.tab.h" */
int pos = 0;
int lino = 1;
%}

%%

{comment}  { lino++; pos = 0;}
\n         { lino++; pos = 0;}
" "        { pos++; }
\t         { pos = (pos + 8) % 8; }

{true_sym} { pos += 4; return(token2);}
{false_sym} { pos += 5; return(token3);}
{not_sym}  { pos += 3; return(token6);}

.	{ 
          if (yytext[0]=='|') {pos++; return(token4);}
	  if (yytext[0]=='&') {pos++; return(token5);}
	  if (yytext[0]=='(') {pos++; return(token7);}
	  if (yytext[0]==')') {pos++; return(token8);}
          return(yytext[0]);
	};

%%