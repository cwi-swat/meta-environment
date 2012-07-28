/* $Id$ */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <assert.h>

#include <SDFME-utils.h>
#include <MEPT-utils.h>
#include <SDF2PT.h>
#include "sdf-renaming.h"

static char myversion[] = "1.0";

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
{
    ATwarning("sdf-renaming: renaming sorts in parse trees according to\n"
	      "SDF2 import specifications.\n"
	      "This tool can only be executed on the ToolBus platform.\n");
    exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  static void version(const char *msg) */

static void version(const char *msg)
{
    ATwarning("%s v%s\n", msg, myversion);
    exit(1);
}

/*}}}  */

/*{{{  static SDF_ImportList getRelevantImports(char *moduleName, SDF_ImportList imports) */

static SDF_ImportList getRelevantImports(const char *moduleName, SDF_ImportList imports)
{
  SDF_ModuleId id = SDF_makeModuleId(moduleName);
  SDF_ImportList relevantImports = SDF_makeImportListEmpty();

  while (!SDF_isImportListEmpty(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);
    SDF_ModuleName name = SDF_getImportModuleName(import);
    SDF_ModuleId importId = SDF_getModuleNameModuleId(name);

    assert(!SDF_hasModuleNameParams(name) && 
	   "parameters are supposed to be resolved before using this tool."
	   " See get-import.c in sdf-support/lib");

    if (SDF_isEqualModuleId(id, importId)) {
      relevantImports = SDF_concatImportList(relevantImports,
					     SDF_makeLayoutSpace(),
					     SDF_makeImportListSingle(import));
    }

    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return relevantImports;
}

/*}}}  */

/*{{{  static PT_ParseTree applyRenamings(SDF_Renamings renamings, PT_ParseTree pt) */

static PT_ParseTree applyRenamings(SDF_Renamings renamings, PT_ParseTree pt)
{
  SDF_RenamingList symbolRenamingList = SDF_getRenamingsList(renamings);

  while (SDF_hasRenamingListHead(symbolRenamingList)) {
    SDF_Renaming renaming = SDF_getRenamingListHead(symbolRenamingList);

    if (SDF_isRenamingSymbol(renaming)) {
      SDF_Symbol fromSymbol = SDF_getRenamingFrom(renaming);
      SDF_Symbol toSymbol = SDF_getRenamingTo(renaming);

      pt = PT_renameInParseTree(pt, 
				SDFSymbolToPtSymbol(fromSymbol),
				SDFSymbolToPtSymbol(toSymbol));
    }

    if (SDF_hasRenamingListTail(symbolRenamingList)) {
      symbolRenamingList = SDF_getRenamingListTail(symbolRenamingList);
    }
    else {
      break;
    }
  }

  return pt;
}

/*}}}  */

/*{{{  static ATermList applyImports(SDF_ImportList imports, PT_ParseTree pt) */

static ATermList applyImports(SDF_ImportList imports, PT_ParseTree pt)
{
  ATermList result = ATempty;

  while (!SDF_isImportListEmpty(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);

    if (SDF_hasImportRenamings(import)) {
      SDF_Renamings renamings = SDF_getImportRenamings(import);

      result = ATinsert(result, 
			ATBpack(
			  PT_ParseTreeToTerm(applyRenamings(renamings, pt))));
    }
    else {
      result = ATinsert(result, ATBpack(PT_ParseTreeToTerm(pt)));
    }

    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return result;
}

/*}}}  */

/*{{{  ATerm rename_module(int cid, ATerm imports, char *moduleName, ATerm term) */

ATerm rename_module(int cid, ATerm atImports, const char *moduleName, ATerm term)
{
  SDF_ImportList imports = SDF_ImportListFromTerm(atImports);
  SDF_ImportList relevant = getRelevantImports(moduleName, imports);

  ATermList newModules = applyImports(relevant, 
				      PT_ParseTreeFromTerm(ATBunpack(term)));
  
  return ATmake("snd-value(renamed-module(<term>))", newModules);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i=1; i<argc; i++) {
      if (strcmp(argv[i], "-h") == 0) {
	  usage(argv[0], ATfalse);
      } else if (strcmp(argv[i], "-V") == 0) {
	  version(argv[0]);
      }
  }

  ATBinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();
  PT_initMEPTApi();

  cid = ATBconnect(NULL, NULL, -1, sdf_renaming_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
