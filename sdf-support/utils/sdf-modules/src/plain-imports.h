#ifndef PLAIN_IMPORTS_H
#define PLAIN_IMPORTS_H

ATermList PI_getTransitiveImports(ATermList idImportPairs, ATerm id);
ATermList PI_getDependingModules(ATermList idImportPairs, ATerm id);
ATermList PI_getDirectDependingModules(ATermList idImportPairs, ATerm id);

#endif
