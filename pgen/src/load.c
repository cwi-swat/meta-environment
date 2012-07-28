#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <asc-support2-me.h>
#include <Error-utils.h>
#include <sglrInterface.h>
#include <inputStringBuilder.h>

#define INITIAL_TABLE_SIZE 8191  

/* Functions are defined in Sdf2-Normalization.c which is generated from the 
 * asf equations in Sdf2-Normailazation.eqs. */
extern void register_Sdf2_Load();
extern void resolve_Sdf2_Load();
extern void init_Sdf2_Load();
extern unsigned const char Sdf2_Load_parsetable_baf[];
extern int Sdf2_Load_parsetable_size;

static void initialize() {
  ASC_initRunTime(INITIAL_TABLE_SIZE);

  if (Sdf2_Load_parsetable_baf != NULL) {
    ATerm parseTable = ATreadFromBinaryString(Sdf2_Load_parsetable_baf, 
					      Sdf2_Load_parsetable_size);

    if (parseTable != NULL) {
      setParseTable(PTBL_ParseTableFromTerm(parseTable));
    }
  }

  register_Sdf2_Load();
  resolve_Sdf2_Load();
  init_Sdf2_Load();

  setKeepAnnotations(ATtrue);
}

static PT_Tree loadFunction(const char *module, const char* path) {
  PT_Tree topModule = (PT_Tree) SDF_makeStrCon(module);
  PT_Tree pathStr = (PT_Tree) SDF_makeStrCon(path);
  PT_Symbol sym = PT_makeSymbolCf(PT_makeSymbolAlt(PT_makeSymbolSort("SDF"), PT_makeSymbolSort("Summary")));

  return PT_applyFunction("load", sym, PT_makeArgs2(topModule, pathStr), 
			  PT_makeAttributesNoAttrs());
}

static PT_ParseTree processResult(PT_Tree result) {
  if (result != NULL) {
    if (PT_isTreeAppl(result)) {
      PT_Tree kid = PT_getArgsHead(PT_getTreeArgs(result));

      if (PT_isTreeAppl(kid)) {
	PT_Symbol rhs = PT_getProductionRhs(PT_getTreeProd(kid));


	if (PT_isEqualSymbol(rhs, PT_makeSymbolCf(PT_makeSymbolSort("SDF")))) {
	  return (PT_ParseTree) SDF_makeStartSDF(SDF_makeOptLayoutAbsent(),
				  (SDF_SDF) kid,
				  SDF_makeOptLayoutAbsent(),
				  0);
	}
	else {
	  ERR_displaySummary(PERR_lowerSummary((PERR_Summary) kid));
	}
      }
    }
  }

  return NULL;
}


PT_ParseTree load(const char *topModule, const char* path) {
  PT_Tree result;
  PT_Tree tree = loadFunction(topModule, path);

  initialize();
  ATerm reduct = innermost(tree);
  result = (PT_Tree) toasfix(reduct);

  unregister_all();

  return processResult(result);
}

PT_ParseTree parseDefinition(const char* path) {
  InputString inputString = IS_createInputStringFromFile(path);
  PT_ParseTree result = NULL;

  initialize();
  loadParseTable();

  result = SGLR_parse(inputString, getParseTableID());

  if (result == NULL) {
    ERR_displaySummary(SGLR_getErrorSummary());
  }

  return result;
}
