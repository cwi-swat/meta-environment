#include <MEPT-utils.h>
#include <PTMEPT-utils.h>
#include <ASFME-utils.h>
#include <asc-support-me.h>
#include <asc-support2-me.h>
#include "asfnormalization.h"

extern void register_ASF_Normalization();
extern void resolve_ASF_Normalization();
extern void init_ASF_Normalization();

/*{{{  static void initialize()  */

static void initialize() 
{
  static ATbool initialized = ATfalse;

  if (!initialized) {
    PT_initMEPTApi();
    ASF_initASFMEApi();
    ASC_initRunTime(INITIAL_TABLE_SIZE);
    PT_initAsFix2Api();
    setKeepAnnotations(ATfalse);

    register_ASF_Normalization();
    resolve_ASF_Normalization();
    init_ASF_Normalization();
  }

  initialized = ATtrue;
}

/*}}}  */

/*{{{  PT_Tree normalizeCharacter(PT_Tree tree) */

PT_Tree normalizeCharacter(PT_Tree tree)
{
  PT_Tree resultTree;

  initialize();

  tree = (PT_Tree) PTPT_liftTree(tree);

  tree = PT_applyFunctionToTree("constructors", 
				"Tree",
				1,
				(PT_Tree) tree);

  resultTree = toasfix(innermost(tree));
  resultTree = PTPT_lowerTree((PTPT_Tree) resultTree);

  return resultTree;

}

/*}}}  */

/*{{{  ASF_ASFModule normalize(ASF_ASFModule input) */

ASF_ASFModule normalize(ASF_ASFModule input)
{
  ASF_ASFModule lifted;
  PT_Tree applied;
  ATerm reduct;
  PT_Tree asfix;
  ASF_ASFModule lowered;
  ATermTable liftCache = ATtableCreate(2000, 75);
  ATermTable lowerCache = ATtableCreate(2000, 75);

  lifted = ASF_liftModule(input, liftCache, lowerCache);

  applied = PT_applyFunctionToTree("normalize", 
					"ASF-Module",
					1,
					(PT_Tree) lifted);

  initialize();
  reduct = innermost(applied);
  asfix = toasfix(reduct);

  lowered = ASF_lowerModule((ASF_ASFModule) asfix, lowerCache);

  ATtableDestroy(liftCache);
  ATtableDestroy(lowerCache);

  return lowered;
}

/*}}}  */
