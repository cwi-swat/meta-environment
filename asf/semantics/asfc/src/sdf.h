#ifndef _SDF_H
#define _SDF_H

#include <SDFME.h>

SDF_ProductionList getModuleListProductions(SDF_ModuleList);
SDF_ModuleName makeModuleNameFromString(const char *str);

#endif
