/* 
 * This unit test tests the functions RWprepareTerm and RWrestoreTerm.
 *
 * Applying RWrestoreTerm after RWprepareTerm should be the identity if
 * we want to keep the whitespace. 
 *
 * The term is read from stdin, then filtered through the functions, ATisEqual
 * determines their equality. Also the term is dumped to stdout again.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../preparation.h"
#include "../asfix_utils.h"
#include <AsFix.h>

int main(int argc, char *argv[])
{
	ATbool usage = ATfalse;
	ATerm bottomOfStack;
	ATerm in, term, prepared, restored, out;
	
	if(argc == 2) {
		if(!strcmp(argv[1],"--no-whitespace") || !strcmp(argv[1],"-n")) {
			keep_whitespace = ATfalse;
		} else {
			usage = ATtrue;
		}
	} else if (argc == 1) {
		keep_whitespace = ATtrue;
	} else {
		usage = ATtrue;
	}

	if(usage)
		ATerror("Usage: prepare-restore [--no-whitespace] [-n]\nThis test reads an asfix term from stdin, prepares it for rewriting, restores it again and tests the input with the output for equality.\n");
				

	AFinit(argc,argv,&bottomOfStack);

	in = ATreadFromFile(stdin);
	
	in = ATremoveAllAnnotations(in); 

	term = asfix_get_term(in);

	prepared = RWprepareTerm(term);

	restored = RWrestoreTerm(prepared);

	out = asfix_put_term(in, restored);

	ATprintf("%t", out);

	if(!ATisEqual(in, out)) 
		ATerror("Error: Output term is different from input term.\n");
	
	return 0;
}
