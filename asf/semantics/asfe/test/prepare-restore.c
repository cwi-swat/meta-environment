/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
    The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

    $Id$
*/
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
#include "preparation.h"
#include "asfix_utils.h"
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
