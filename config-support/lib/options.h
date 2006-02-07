/*$Id$*/

/* Handles tool's options. */ 

#include <aterm2.h>

void   OPT_initialise();
void   OPT_cleanup();
void   OPT_setFlag(const char *name, ATbool value);
ATbool OPT_getFlag(const char *name);

void   OPT_setStringValue(const char *name, const char *value);
const char* OPT_getStringValue(const char *name);

void   OPT_setIntValue(const char *name, int value);
int    OPT_getIntValue(const char *name);
