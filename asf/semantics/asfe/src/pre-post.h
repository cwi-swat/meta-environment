#ifndef PRE_POST_H
#define PRE_POST_H

#include <MEPT.h>
#include <aterm2.h>

PT_Tree RWprepareTerm(PT_Tree tree, ATbool allow_ambs);
ASF_CondEquationList RWprepareEquations(ASF_CondEquationList eqsList, 
					ATbool mark_layout);

PT_Tree RWrestoreTerm(PT_Tree tree, ATbool remove_layout);
PT_Args RWrestoreArgs(PT_Args args, ATbool remove_layout);
#endif
