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
#include <atb-tool.h>
#include <string.h>

#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <ASFME-utils.h>   
#include <aterm2.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "module-db.tif.h"

ATbool complete_asf_sdf2_specification(ATerm module);
ATermList get_imported_modules(ATerm name); 
ASF_CondEquationList getEquations(ATermList mods);
SDF_SDF getSyntax(ATermList modules);

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

#define PATH_SYN_LOC 0        /* Location to store the path to syntax file. */
#define SYN_LOC 1             /* Tree of the syntax file. */
#define SYN_TIME_LOC 2        /* Timestamp of the syntax file. */
#define SYN_UPDATED_LOC 3     /* Is the syntax changed? */
#define PATH_EQS_LOC 4        /* Location to store the path to the equations. */
#define EQS_TREE_LOC 5        /* Tree of the equations. */
#define EQS_TEXT_LOC 6        /* Text file of the equations. */
#define EQS_TIME_LOC 7        /* Timestamp of equations file. */
#define EQS_UPDATED_LOC 8     /* Are the equations changed? */
#define EQS_TABLE_LOC 9       /* Location to store path to equations
                               * parse-table. */
#define EQS_TABLE_TIME_LOC 10 /* Location to store timestamp of equations
                               * parse-table. */
#define TRM_TABLE_LOC 11      /* Location to store path to term parse-table. */
#define TRM_TABLE_TIME_LOC 12 /* Location to store timestamp of term 
                               * parse-table. */
#define LOC_CNT 13            /* Number of locations in entry */

#define Mtrue (ATerm)ATmakeInt(1)
#define Mfalse (ATerm)ATmakeInt(0)
