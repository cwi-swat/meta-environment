#ifndef PRE_POST_H
#define PRE_POST_H

#include <MEPT.h>
#include <aterm2.h>

ASF_ASFCondition prepareCondition(ASF_ASFCondition cond);
ASF_ASFConditions prepareConditions(ASF_ASFConditions conds);
PT_Tree RWprepareTerm(PT_Tree tree, ATbool allow_ambs);
ASF_ASFConditionalEquationList RWprepareEquations(ASF_ASFConditionalEquationList eqsList, 
					ATbool mark_layout);

PT_Tree RWrestoreTerm(PT_Tree tree, ATbool remove_layout);
PT_Args RWrestoreArgs(PT_Args args, ATbool remove_layout);
#endif
