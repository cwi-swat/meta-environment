#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <asc-support-me.h>
#include <asc-support2-me.h>
#include "asfnormalization.h"

extern void register_ASF_Normalization();
extern void resolve_ASF_Normalization();
extern void init_ASF_Normalization();

static void initialize() {
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

ASF_ASFModule normalize(ASF_ASFModule input)
{
  ASF_ASFModule lifted;
  PT_Tree applied;
  ATerm reduct;
  PT_ParseTree asfix;
  ASF_ASFModule lowered;

  ATwarning("lifting\n");
  lifted = ASF_liftModule(input);
  ATwarning("lifting done\n");

  ATwarning("normalizing\n");
  applied = PT_applyFunctionToTree("normalize", 
					"ASF-Module",
					1,
					(PT_Tree) lifted);

  initialize();
  reduct = innermost(applied);
  asfix = toasfix(reduct);

  ATwarning("normalizing done\n");

  ATwarning("lowering\n");
  lowered = ASF_lowerModule(ASF_getStartTopASFModule((ASF_Start) asfix));
  ATwarning("lowering done\n");

  return lowered;
}

