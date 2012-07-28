#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <asc-support2-me.h>

#define INITIAL_TABLE_SIZE 8191  

/* Functions are defined in Sdf2-Normalization.c which is generated from the 
 * asf equations in Sdf2-Normailazation.eqs. */
extern void register_Sdf2_Normalization();
extern void resolve_Sdf2_Normalization();
extern void init_Sdf2_Normalization();

static void initialize() 
{
  ASC_initRunTime(INITIAL_TABLE_SIZE);
  
  register_Sdf2_Normalization();
  resolve_Sdf2_Normalization();
  init_Sdf2_Normalization();

  setKeepAnnotations(ATfalse);
}

static PT_Tree addNormalizeFunction(const char *str, PT_ParseTree parseTree) {
  SDF_ModuleName sdfModuleName = SDF_makeModuleName((char*) str);
  PT_Tree ptModuleName = PT_TreeFromTerm(SDF_ModuleNameToTerm(sdfModuleName));
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("normalize",
        "Grammar",
        2,
        ptModuleName,
        ptSyntax);
  }
  else {
    ATerror("addNormalizeFunction: not a proper parse tree: %t\n",
        (ATerm) parseTree);

    return (PT_Tree) NULL;
  }

  return newTree;

}

PT_Tree normalizeGrammar(const char *topModule, PT_ParseTree parseTree) {
  PT_Tree tree = addNormalizeFunction(topModule, parseTree);
  PT_Tree result;

  initialize();
  ATerm reduct = innermost(tree);
  result = toasfix(reduct);
  unregister_all();
  return result;
}

