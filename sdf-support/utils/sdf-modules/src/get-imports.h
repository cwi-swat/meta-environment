#ifndef GET_IMPORTS_H
#define GET_IMPORTS_H

ATermList SDF_getImports(SDF_Module module);
SDF_ImportList SDF_getTransitiveImports(ATermList definition, 
					SDF_ModuleId moduleId);
ATermList SDF_getTransitiveImportedModules(ATermList modules, 
					   SDF_ModuleId moduleId);
ATermList SDF_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId);
SDF_ImportList SDF_getModuleImportsList(SDF_Module module);

#endif
