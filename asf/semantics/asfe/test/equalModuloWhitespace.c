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
 * This unit test test the function isEqualModuloWhiteSpace by calling this 
 * function on two asfix files from the commandline arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include "preparation.h"
#include "asfix_utils.h"
#include <MEPT-utils.h>

int main(int argc, char *argv[])
{
	ATbool usage = ATfalse;
	FILE *file1, *file2;
	ATerm asfix1, asfix2, term1, term2;
	ATerm bottomOfStack;

	ATinit(argc, argv, &bottomOfStack);
        PT_initMEPTApi();

	if(argc != 3) {
		ATerror("Usage: equalModuloWhitespace asfixfile asfixfile\nSupply two asfix files that are expected to be equal modulo whitespace, but not equal otherwise.\n");
	}
	else {
		if(!(file1 = fopen(argv[1],"r")))
			ATerror("Could not open %s.\n", argv[1]);

		if(!(file2 = fopen(argv[2],"r")))
			ATerror("Could not open %s.\n", argv[2]);
	}
	
	asfix1 = ATreadFromFile(file1);
	asfix2 = ATreadFromFile(file2);

	fclose(file1);
	fclose(file2);

	term1 = asfix_get_term(asfix1);
	term2 = asfix_get_term(asfix2);

	if(!isEqualModuloWhitespace(term1,term2)) {
	  return 1;
	}

	return 0;
}
