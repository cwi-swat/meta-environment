#ifndef MODULE_STORE_H
#define MODULE_STORE_H

void MS_initModuleStore();
void MS_destroyModuleStore();

ATbool MS_existsModule(ATerm moduleName);
void MS_putModuleName(ATerm moduleName);
void MS_removeModuleName(ATerm moduleName);
ATermList MS_getActiveModules();

ATerm MS_getSdfTree(ATerm moduleName);
void MS_putSdfTree(ATerm moduleName, ATerm moduleTree);
void MS_putSdfText(ATerm moduleName, char *text, char *path, int timeStamp);
void MS_removeSdfTree(ATerm moduleName);
char* MS_getSdfTextPath(ATerm moduleName);

void MS_putAsfTree(ATerm moduleName, ATerm tree);
void MS_removeAsfTree(ATerm atModuleName);

void MS_putAsfText(ATerm moduleName, char *text, char *path, int timeStamp);
ATerm MS_getAsfTextValue(ATerm moduleName);
char* MS_getAsfTextPath(ATerm moduleName);
char* MS_getAsfTextText(ATerm moduleName);

ATerm MS_getAsfTree(ATerm moduleName);

void MS_putAsfParseTable(ATerm moduleName, ATerm table, int timeStamp);
void MS_removeAsfParseTable(ATerm atModuleName);
ATerm MS_getAsfParseTable(ATerm moduleName);

void MS_putTermParseTable(ATerm moduleName, ATerm table, int timeStamp);
void MS_removeTermParseTable(ATerm atModuleName);
ATerm MS_getTermParseTable(ATerm moduleName);
#endif
