/*
  $Id$
 */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>

#include <SDFME-utils.h>
#include "sdf-modules.tif.h"

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
    ATwarning("sdf-modules: an interface to the sdf-support library.\n"
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

/*{{{  ATerm get_all_imports(int cid, ATerm atModules, char* name)  */

ATerm get_all_imports(int cid, ATerm atModules, char* name) 
{
  ATermList list = (ATermList) atModules;
  SDF_ModuleId id = SDF_makeModuleIdWord(SDF_makeCHARLISTString(name));
  ATermList imports;
 
  imports = SDF_getTransitiveImports(list, id);

  return ATmake("snd-result(all-imports(<term>))", imports);
}

/*}}}  */
/*{{{  ATerm get_import_renamings(int cid, ATerm atImport) */

ATerm get_import_renamings(int cid, ATerm atImport)
{
  SDF_Import import = SDF_ImportFromTerm(atImport);
  SDF_Renamings renamings = SDF_makeRenamingsRenamings(SDF_makeLayoutSpace(),
			       SDF_makeRenamingListEmpty(),
			       SDF_makeLayoutSpace());

  if (SDF_hasImportRenamings(import)) {
    renamings = SDF_getImportRenamings(import);
  }
    

  return ATmake("snd-result(renamings(<term>))", renamings);
}

/*}}}  */
/*{{{  ATerm get_module_id(int cid, ATerm atModule) */

ATerm get_module_id(int cid, ATerm atModule)
{
  SDF_Module module = SDF_ModuleFromTerm(atModule);

  return ATmake("snd-result(module-id(<str>))", SDF_getModuleName(module));
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


  cid = ATBconnect(NULL, NULL, -1, sdf_modules_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
