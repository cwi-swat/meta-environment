%{
#include <string.h>

#include "dot.h"
#include "y.tab.h"

#define YY_NO_UNPUT
%}

layout		[ \t\n\r]
comment		"//".*\n
ws		{layout}|{comment}
id		[a-zA-Z0-9_]+
%%

"digraph" { return DIGRAPH; }
"edge" { return EDGE; }
"graph" { return GRAPH; }
"node" { return NODE; }
"strict" { return STRICT; }
"subgraph" { return SUBGRAPH; }

"{" { return CBO; }
"}" { return CBC; }

{ws} { }
{id} {
	yylval.string = strdup(yytext);
	return ID;
}

"--" {
	yylval.direction = UNDIRECTED;
	return EDGEOP;
}

"->" {
	yylval.direction = DIRECTED;
	return EDGEOP;
}

"\"" {
	char strbuf[BUFSIZ];
	char *ptr = strbuf;
	int c;

	while ((c = input()) != '"'){
		if (c <= 0) {
			yyerror("String constant not terminated at eof");
		}
		if (ptr == &strbuf[BUFSIZ]){
			yyerror("String constant too long");
		}
		if (c == '\\') {
			c = input();
			if (c == '\n') {
				continue;
			}
		}
		*ptr++ = c;		   
	}
	*ptr++ = '\0';
	yylval.string = strdup(strbuf);

	return ID;
}

. { return(yytext[0]); }


%%
