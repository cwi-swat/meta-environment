#ifndef _SDFME_UTILS_H
#define _SDFME_UTILS_H

#include "SDFME.h"

SDF_ModuleId SDF_getModuleName(SDF_Module sdfModule);
SDF_Module SDF_setModuleName(SDF_Module sdfModule, const char *name);
SDF_ModuleId SDF_makeModuleId(const char *moduleStr);
SDF_ModuleName SDF_makeModuleName(const char *moduleStr);

ATermList  SDFgetGrammars              (SDF_Module module);
typedef    void (*SDFGrammarFunc)      (SDF_Grammar, ATerm *);
void       SDFforeachGrammar           (SDF_Grammar     grammar,
					SDFGrammarFunc  func,
					void           *user_data);
void       SDFforeachGrammarInSections (SDF_Sections    sections,
					SDFGrammarFunc  func,
					void           *user_data);
void       SDFforeachGrammarInModule   (SDF_Module      module,
					SDFGrammarFunc  func,
					void           *user_data);


ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName);

SDF_ImportList SDF_mergeImportList(SDF_ImportList l1, SDF_ImportList l2);
SDF_ImportList SDF_reverseImportList(SDF_ImportList l);
SDF_ImportList SDF_insertImport(SDF_Import i, SDF_ImportList l);

ATbool SDF_containsImportListImport(SDF_ImportList list, 
                                    SDF_Import  import);
SDF_Module SDF_addModuleImport(SDF_Module mod, SDF_Import import);
SDF_Module SDF_removeModuleImport(SDF_Module mod, SDF_Import import);

SDF_SymbolList  SDF_getModuleSorts(SDF_Module module);

SDF_ProductionList SDF_getModuleProductions(SDF_Module module);
SDF_ProductionList SDF_getModuleVariableProductions(SDF_Module module);
SDF_ProductionList SDF_getModuleLexicalProductions(SDF_Module module);
SDF_ProductionList SDF_getModuleLexicalProductionsGivenSymbol(SDF_Symbol symbol,
                                                              SDF_Module module);
SDF_ProductionList SDF_getModuleContextFreeProductions(SDF_Module module);
SDF_ProductionList  SDF_getGrammarKernelProductions(SDF_Grammar grammar);

SDF_PriorityList    SDF_getGrammarKernelPriorities(SDF_Grammar grammar);

SDF_RestrictionList SDF_getGrammarKernelRestrictions(SDF_Grammar grammar);

SDF_Production SDF_removeAttributes(SDF_Production prod);

ATbool SDF_hasRejectAttribute(SDF_Production prod);
ATbool SDF_hasPreferAttribute(SDF_Production prod);
ATbool SDF_hasAvoidAttribute(SDF_Production prod);

SDF_OptLayout SDF_makeLayoutEmpty();
SDF_OptLayout SDF_makeLayoutSpace();
SDF_OptLayout SDF_makeLayoutNewline();

SDF_Import SDF_makeImport(const char *moduleName);

SDF_Symbol SDF_removeSymbolAnnotations(SDF_Symbol s);
SDF_ModuleId SDF_removeModuleIdAnnotations(SDF_ModuleId m);
SDF_Import SDF_removeImportAnnotations(SDF_Import i);
SDF_ImportList SDF_removeImportListAnnotations(SDF_ImportList l);

SDF_RenamingList SDF_reverseRenamingList(SDF_RenamingList l);
SDF_RenamingList SDF_insertRenaming(SDF_Renaming r, SDF_RenamingList l);

SDF_SymbolList SDF_reverseSymbolList(SDF_SymbolList l);
SDF_SymbolList SDF_insertSymbol(SDF_Symbol r, SDF_SymbolList l);

SDF_LexStrCon SDF_makeLexStrCon(const char *str);
SDF_StrCon SDF_makeStrCon(const char *str);
SDF_SingleQuotedStrCon SDF_makeSingleQuotedStrCon(const char *str);
SDF_Sort SDF_makeSort(const char *str);

int SDF_SDFNatConToInt(SDF_NatCon sdfNatCon);

#endif /* _SDF_UTILS_H */
