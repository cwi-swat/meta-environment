%{
#include <string.h>

#include "dot.h"
#include "y.tab.h"
%}

layout		[ \t\n\r]
comment		"//".*\n
ws		{layout}|{comment}
id		[a-zA-Z_][a-zA-Z0-9_]*
%%
subgraph { return SUBGRAPH; }
digraph { return DIGRAPH; }
edge { return EDGE; }
graph { return GRAPH; }
node { return NODE; }
strict { return STRICT; }

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
