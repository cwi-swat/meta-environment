#ifndef RW1_H
#define RW1_H

#define RECALLNORMALFORMS 1
   
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "aterm2.h"

/* -- Interface to the rewriter  -- */

int RWinitialiseRewriter(ATerm datatype, long rewritelimit,
                         int mode);
/* initialise the rewriter. If everything is ok, 1 is returned. 
   This function can be used to reset the rewriter, bringing it back to 
   its initial state with a fresh datatype. 
   In this case all assignments, etc. are also reset. 

   mode == 0 INNNERMOST and NOHASH  
   mode == 1 INNERMOST and HASH
   mode == 2 LEFTSEQ and NOHASH
   mode == 3 LEFTSEQ and HASH
*/
   
ATerm RWrewrite(ATerm t);
/* rewrite the term t, and substitute the terms
   assigned to variables in t at appropriate places. 
   The terms assigned to variables are assumed
   to be in normal form and will not be rewritten. 
*/

ATermList RWrewriteList(ATermList l);
/* rewrite the list l of terms t_i, and substitute the terms
   assigned to variables in t_i at appropriate places. 
   The terms assigned to variables are assumed
   to be in normal form and will not be rewritten. 
*/

void RWdeclareVariables(ATermList variable_names);
/* introduce variables which possibly occur in terms which are 
   candidates to be rewritten. */

void RWassignVariable(AFun var, ATerm t, ATerm tsort, int level);
/* set var:=t at given level. The level allows to reset variables at a level easily.
   t = NULL is permitted, it means that the variable is only reset.
   tsort = NULL is permitted. It means that the sort is not important.
*/

ATerm RWgetAssignedVariable(AFun var);
/* get the substitution belonging to var 
   If no substitution is defined than the name of var will be returned.
*/

void RWresetVariables(int level);
/* unassign the variables  at a given level */

void RWflush(void);
/* delete all entries in the hash table. This has no visible effect,
   but influences memory consumption.
*/

#endif
