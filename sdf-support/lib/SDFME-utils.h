#ifndef _SDFME_UTILS_H
#define _SDFME_UTILS_H

#include "SDFME.h"

char      *SDFgetModuleName (SDF_Module sdfModule);
SDF_Module SDFsetModuleName (SDF_Module sdfModule, char *name);

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
ATerm SDF_getImportModuleNamePlain(SDF_Import import);
ATermList      SDF_getImports(SDF_Module module);
SDF_ImportList SDF_getModuleImportsList(SDF_Module module);
SDF_ImportList SDF_concatImportList(SDF_ImportList l1, SDF_ImportList l2);

SDF_SymbolList  SDF_getModuleSorts(SDF_Module module);

SDF_ProductionList SDF_getModuleProductions(SDF_Module module);
SDF_ProductionList SDF_getModuleLexicalProductions(SDF_Module module);
SDF_ProductionList SDF_getModuleLexicalProductionsGivenSymbol(SDF_Symbol symbol,
                                                              SDF_Module module);
SDF_ProductionList SDF_getModuleContextFreeProductions(SDF_Module module);
SDF_ProductionList SDF_concatProductionList(SDF_ProductionList list1, 
                                            SDF_ProductionList list2);
SDF_ProductionList  SDF_getGrammarKernelProductions(SDF_Grammar grammar);

SDF_PriorityList SDF_concatPriorityList(SDF_PriorityList list1, 
                                        SDF_PriorityList list2);
SDF_PriorityList    SDF_getGrammarKernelPriorities(SDF_Grammar grammar);

SDF_RestrictionList SDF_concatRestrictionList(SDF_RestrictionList list1, 
                                              SDF_RestrictionList list2);
SDF_RestrictionList SDF_getGrammarKernelRestrictions(SDF_Grammar grammar);

SDF_Production SDF_removeAttributes(SDF_Production prod);

ATbool SDF_hasRejectAttribute(SDF_Production prod);
ATbool SDF_hasPreferAttribute(SDF_Production prod);
ATbool SDF_hasAvoidAttribute(SDF_Production prod);

SDF_Layout SDF_makeLayoutEmpty();

SDF_Import SDFmakeImport(char *moduleName);

PT_Symbol SDFsymbol2PtSymbol(SDF_Symbol sdfSymbol);

#endif /* _SDF_UTILS_H */
