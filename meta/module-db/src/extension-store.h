#ifndef EXTENSION_STORE_H
#define EXTENSION_STORE_H

void ES_initExtensionStore();
void ES_destroyExtensionStore();
void ES_addExtension(char *key, char *extension);
char *ES_getExtension(char *key);


#endif
