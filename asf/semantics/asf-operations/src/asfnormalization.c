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
  PT_Tree term = PT_applyFunctionToTree("normalize", 
					"ASF-Module",
					1,
					input);

  initialize();

  ATerm reduct = innermost(term);


  PT_ParseTree asfix = toasfix(reduct);


  return ASF_getStartTopASFModule((ASF_Start) asfix);
}

