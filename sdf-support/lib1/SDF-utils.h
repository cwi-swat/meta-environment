#ifndef _SDF_UTILS_H
#define _SDF_UTILS_H

#include "SDF.h"

char      *SDFgetModuleName (SDF_Module sdfModule);

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


ATermList  SDFgetImports    (SDF_Module module);

SDF_SymbolList  SDF_getModuleSorts(SDF_Module module);

SDF_ProductionList SDF_getModuleLexicalProductions(SDF_Module module);
SDF_ProductionList SDF_getModuleLexicalProductionsGivenSymbol(SDF_Symbol symbol,
                                                              SDF_Module module);
SDF_ProductionList SDF_concatProductionList(SDF_ProductionList list1, 
                                            SDF_ProductionList list2);

#endif /* _SDF_UTILS_H */
