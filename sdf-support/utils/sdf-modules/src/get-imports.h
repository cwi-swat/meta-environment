#ifndef GET_IMPORTS_H
#define GET_IMPORTS_H

ATermList GI_getImports(SDF_Module module);
SDF_ImportList GI_getTransitiveImports(ATermList definition, 
					SDF_ModuleId moduleId);
ATermList GI_getTransitiveImportedModules(ATermList modules, 
					   SDF_ModuleId moduleId);
ATermList GI_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId);
SDF_ImportList GI_getModuleImportsList(SDF_Module module);
ATerm GI_getImportModuleNamePlain(SDF_Import import);

#endif
