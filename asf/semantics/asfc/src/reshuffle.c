#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <aterm2.h>

#include <SDFME-utils.h>
#include <ASFME-utils.h>
#include <MEPT-utils.h>

#include "reshuffle.h"


static ATermList compiled_modules;

/* The function {\tt filterEquationsGivenProduction} traverse a list
   of equations and looks for all equations with the given
   context-free function as outermost function symbol in the
   left-hand side. */

static ASF_CondEquationList
filterEquationsGivenProduction(PT_Production func, ASF_CondEquationList eqs)
{
  ASF_CondEquation ceq;
  ASF_Equation eq;
  ASF_Tree lhs; 
  PT_Production ofs;
  ASF_CondEquationList equations = ASF_makeCondEquationListEmpty();

  while (ASF_hasCondEquationListHead(eqs)) {
    ceq = ASF_getCondEquationListHead(eqs);
    eq = ASF_getCondEquationEquation(ceq);
    lhs = ASF_getEquationLhs(eq);
    ofs = PT_getTreeProd(PT_makeTreeFromTerm(ASF_makeTermFromTree(lhs)));
    if (PT_isEqualProduction(func, ofs)) {
      if (!ASF_isCondEquationListEmpty(equations)) {
        equations = ASF_makeCondEquationListMany(ceq, "", equations);
      } 
      else {
        equations = ASF_makeCondEquationListSingle(ceq);
      }
    }
    if (ASF_isCondEquationListSingle(eqs)) {
      break;
    }
    eqs = ASF_getCondEquationListTail(eqs);
  };
  return equations;
}

static char* unique_new_name(SDF_ModuleName name)
{
  char *text, *newtext;
  ATerm newname;
  int n = 1;
  PT_ModuleName newModuleName;

  text = SDF_getModuleIdLex(SDF_getModuleNameModuleId(name));

  /* Here we update a global list of AUX module names in order
   * to keep them unique.
   */
  newtext = malloc(strlen(text)+16);
  sprintf(newtext,"AUX-%s%d", text, n);
  newname = ATmake("<str>", newtext);
  while (ATindexOf(compiled_modules, newname, 0) >= 0) {
    n++;
    sprintf(newtext,"AUX-%s%d", text, n);
    newname = ATmake("<str>", newtext);
  }
  compiled_modules = ATinsert(compiled_modules, newname);

  return newtext;
}

static char* createNewModuleName(SDF_ModuleName modname)
{ 
  return unique_new_name(modname);
}

static PT_ModuleName
extendModuleName(SDF_ModuleName modname, PT_ModuleName newModuleName)
{ 
  char *text = SDF_getModuleIdLex(SDF_getModuleNameModuleId(modname));
  PT_ModuleName ptModuleName = PT_makeModuleNameDefault(text);

  return PT_makeModuleNameFromTerm(
           ATsetAnnotation(PT_makeTermFromModuleName(newModuleName),
                           ATparse("module-name"),
                           PT_makeTermFromModuleName(ptModuleName)));
}

static void writeAndCompileAUXFile(PT_ModuleName modName, ATermList auxModule)
{
  char *text, *fname;
  char *path;
  int len;
  FILE *output, *input;
  ATerm oldmod;
  ATbool write;

  text = PT_getModuleNameId(modName);

  /* Check whether the C file exists. */
  path = get_output_dir();
  len = strlen(path) + 1 + strlen(text) + strlen(".c");
  fname = malloc(len + 1);
  if (!fname) {
    ATerror("Not enough memory\n");
  }
  sprintf(fname, "%s/%s.c", path, text);
  input = fopen(fname,"r");
  if (!input) {
    write = ATtrue;
  } 
  else {
    write = ATfalse;
/* Only close input if we actually opened it. Linux fclose crashes on
   closing NULL
*/
    fclose(input);
  }
  free(fname);

  len = strlen(path) + 1 + strlen(text) + strlen(".asfix");
  fname = malloc(len + 1);
  if (!fname) {
    ATerror("Not enough memory\n");
  }
  sprintf(fname, "%s/%s.asfix", path, text);
  /* Check whether it is necessary to generate new C code
   * because of a modified AsFix file. */
  input = fopen(fname,"r");
  if (input) {
    oldmod = ATreadFromFile(input);
    if (!write) {
      write = !ATisEqual(oldmod, auxModule);
    }
    fclose(input);
  }
  else {
    write = ATtrue;
  }
  if (write) {
    output = fopen(fname,"w");
    if (!output)
      ATwarning("Cannot open file %s\n", fname);
    else {
      ATfprintf(output,"%t", auxModule);
      ATfprintf(output, "\n");
      fclose(output);
    }
    /* write full path name instead of only module name */
    generateCode(text, (ATerm)auxModule);
  }
  free(fname);
}

static SDF_ProductionList collectLexicalFunctions(SDF_Symbol symbol, 
                                                  SDF_ModuleList moduleList)
{
  SDF_ProductionList lexFunctions = SDF_makeProductionListEmpty();
  SDF_Module module;

  while (SDF_hasModuleListHead(moduleList)) {
    module = SDF_getModuleListHead(moduleList);

    lexFunctions = SDF_concatProductionList(
                     lexFunctions,
                     SDF_getModuleLexicalProductionsGivenSymbol(symbol, 
                                                                module));
    if (SDF_isModuleListSingle(moduleList)) {
      break;
    }
    moduleList = SDF_getModuleListTail(moduleList);
  }
  return lexFunctions;

}

/* This function uses the sorts to determine whether there are equations
 * for the lexical functions.
 */
static SDF_ProductionList 
reshuffleLexicalConstructorFunctions(SDF_Module sdfMod,
                                     SDF_ModuleList orgModules,
                                     ASF_CondEquationList eqsList)
{
  SDF_Symbol sdfSort;
  SDF_SymbolList sdfSorts;
  SDF_ProductionList funcs, newLexFuncs = SDF_makeProductionListEmpty();

  ASF_CondEquationList selectedEqs;
  ATermList newAuxModule;

  sdfSorts = SDF_getModuleSorts(sdfMod); 
  while (SDF_hasSymbolListHead(sdfSorts)) {
    sdfSort = SDF_getSymbolListHead(sdfSorts);
/* This is tricky in SDF2!!! */
    funcs = collectLexicalFunctions(sdfSort, orgModules); 

    if (!SDF_isProductionListEmpty(funcs)) {
      PT_Production prod = makeLexicalConstructorProd(sdfSort);
      selectedEqs = filterEquationsGivenProduction(prod, eqsList);
      if (!ASF_isCondEquationListEmpty(selectedEqs)) {
/* There are equations for the lexical constructor of sort SORT.
 * So, a new module has to be created containing these lexical functions
 * and the corresponding equations.
 */
        SDF_ModuleName sdfModuleName = SDF_getModuleModuleName(sdfMod);
        PT_ModuleName newPtModuleName = createNewModuleName(sdfModuleName);
        PT_ModuleName extendedPtModuleName = 
                         extendModuleName(sdfModuleName, newPtModuleName);
        newAuxModule = 
          ATmakeList4(PT_makeTermFromModuleName(extendedPtModuleName), 
                      SDF_makeTermFromProductionList(funcs), 
                      (ATerm)ATempty,
                      ASF_makeTermFromCondEquationList(selectedEqs));
        writeAndCompileAUXFile(newPtModuleName, newAuxModule);
      }
      else {
/* There are no equations for the lexical constructor of sort SORT.
 * So, this function is to be added to the module containing no
 * equations.
 */
        if (!SDF_isProductionListEmpty(newLexFuncs)) {
          newLexFuncs = SDF_concatProductionList(newLexFuncs, funcs);
        }
        else {
          newLexFuncs = funcs;
        }
      }
    }
    if (SDF_isSymbolListSingle(sdfSorts)) {
      break;
    }
    sdfSorts = SDF_getSymbolListTail(sdfSorts);
  }
  return newLexFuncs;
}

/*{{{  static void gen_makefile(char *name) */

static void gen_makefile(char *name)
{
  char *text;
  char *path;
  char buf[1024];
  FILE *output;
  ATerm module;

  path = get_output_dir();
  sprintf(buf, "%s/%s.module-list", path, name);
  output = fopen(buf,"w");
  if (!output) {
    ATfprintf(stderr,"Cannot open file %s\n",buf);
  }
  else {
    fprintf(output, "# Generated automatically, please do not edit.\n" );
    while (!ATisEmpty(compiled_modules)) {
      module = ATgetFirst(compiled_modules);
      if (ATmatch(module,"<str>",&text)) {
        ATfprintf(output,"%s.c\n", text);
      }
      compiled_modules = ATgetNext(compiled_modules);
    }
    fclose(output);     
  }
}

/*}}}  */          

void compileModules(char *moduleName,
                    SDF_ModuleList moduleList, 
                    ASF_CondEquationList eqsList)
{
  SDF_Module sdfMod;
  ATermList newAuxModule;
  SDF_ProductionList cfFuncs;
  SDF_Production cfFunc;
  PT_Production flatCfFunc;
  SDF_ModuleList orgModuleList;
  SDF_ModuleName sdfModuleName;
  PT_ModuleName newPtModuleName, extPtModuleName;
  SDF_ProductionList newCfFuncs;
  SDF_ProductionList lexFuncs;
  ASF_CondEquationList selectedEqs;

  ATprotect((ATerm *)&compiled_modules); 
  compiled_modules = ATempty;

  orgModuleList = moduleList;

  while (SDF_hasModuleListHead(moduleList)) {
    sdfMod = SDF_getModuleListHead(moduleList);
    sdfModuleName = SDF_getModuleModuleName(sdfMod);
    newPtModuleName = createNewModuleName(sdfModuleName);
    extPtModuleName = extendModuleName(sdfModuleName, newPtModuleName);
    newCfFuncs = SDF_makeProductionListEmpty();
    lexFuncs = reshuffleLexicalConstructorFunctions(sdfMod,
                                                    orgModuleList,
                                                    eqsList);
    cfFuncs = SDF_getModuleContextFreeProductions(sdfMod);
    while (SDF_hasProductionListHead(cfFuncs)) {
      cfFunc = SDF_getProductionListHead(cfFuncs);
      flatCfFunc = flattenSdfProduction(cfFunc, sdfModuleName);
      selectedEqs = filterEquationsGivenProduction(flatCfFunc, eqsList);
      if (!ASF_isCondEquationListEmpty(selectedEqs)) {
        PT_ModuleName tmpNewPtModuleName =
                         createNewModuleName(sdfModuleName);
        PT_ModuleName tmpExtPtModuleName = 
                         extendModuleName(sdfModuleName, tmpNewPtModuleName);
        newAuxModule = 
          ATmakeList4(PT_makeTermFromModuleName(tmpExtPtModuleName), 
                      (ATerm)ATempty, 
                      SDF_makeTermFromProductionList(
                        SDF_makeProductionListSingle(cfFunc)),
                      ASF_makeTermFromCondEquationList(selectedEqs));
        writeAndCompileAUXFile(tmpNewPtModuleName, newAuxModule);
      }
      else {
        if (!SDF_isProductionListEmpty(newCfFuncs)) {
          newCfFuncs = SDF_makeProductionListMany(cfFunc, "", newCfFuncs);
        }
        else {
          newCfFuncs = SDF_makeProductionListSingle(cfFunc);
        }
      }
      if (SDF_isProductionListSingle(cfFuncs)) {
        break;
      }
      cfFuncs = SDF_getProductionListTail(cfFuncs);
    }
    newAuxModule = ATmakeList4(PT_makeTermFromModuleName(extPtModuleName), 
                               SDF_makeTermFromProductionList(lexFuncs), 
                               SDF_makeTermFromProductionList(newCfFuncs),
                               (ATerm)ATempty);
    writeAndCompileAUXFile(newPtModuleName, newAuxModule);
    if (SDF_isModuleListSingle(moduleList)) {
      break;
    }
    moduleList = SDF_getModuleListTail(moduleList);
  }
  
  gen_makefile(moduleName);
}
