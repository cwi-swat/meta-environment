#ifndef MODULE_STORE_H
#define MODULE_STORE_H

void MS_initModuleStore();
void MS_destroyModuleStore();

ATbool MS_existsModule(ATerm moduleName);
void MS_putModuleName(ATerm moduleName);
ATermList MS_getActiveModules();

ATerm MS_getSdfTree(ATerm moduleName);
void MS_putSdfTree(ATerm moduleName, ATerm moduleTree);
void MS_putSdfText(ATerm moduleName, char *text, char *path, int timeStamp);
char* MS_getSdfTextPath(ATerm moduleName);

void MS_putAsfText(ATerm moduleName, char *text, char *path, int timeStamp);
char* MS_getAsfTextPath(ATerm moduleName);

void MS_putAsfParseTable(ATerm moduleName, ATerm table,
                         int timeStamp);
ATerm MS_getAsfParseTable(ATerm moduleName);

void MS_putTermParseTable(ATerm moduleName, ATerm table,
                          int timeStamp);
ATerm MS_getTermParseTable(ATerm moduleName);
#endif
