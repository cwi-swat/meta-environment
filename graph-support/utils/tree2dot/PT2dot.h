#ifndef PT2DOT_H
#define PT2DOT_H

char* PT_printTreeToDot(PT_Tree tree, ATbool sharing, ATbool characters, 
			ATbool characters_sharing, ATbool productions, 
			ATbool layout, ATbool literals);
char* PT_printParseTreeToDot(PT_ParseTree parsetree, ATbool sharing, 
			     ATbool characters_sharing, ATbool characters, 
			     ATbool productions, ATbool layout, 
			     ATbool literals);
char* PT_printAnyToDot(ATerm term, ATbool sharing, ATbool characters, 
		       ATbool characters_sharing, ATbool productions, 
		       ATbool layout, ATbool literals);

#endif
