#ifndef GET_IMPORTS_H
#define GET_IMPORTS_H

ATermList SI_getImports(SDF_Module module);
SDF_ImportList SI_getTransitiveImports(ATermList definition, 
					SDF_ModuleId moduleId);
ATermList SI_getTransitiveImportedModules(ATermList modules, 
					   SDF_ModuleId moduleId);
ATermList SI_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId);
SDF_ImportList SI_getModuleImportsList(SDF_Module module);
ATerm SI_getImportModuleNamePlain(SDF_Import import);

#endif
