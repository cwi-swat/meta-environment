/*$Id$*/

/* Handles tool's options. */ 

#include <aterm2.h>

void   OPT_initialize();
void   OPT_cleanup();

int OPT_getIntOptionId();
int OPT_getStringOptionId();
int OPT_getFlagOptionId();

void   OPT_setFlag(int flagOptionId, ATbool value);
ATbool OPT_getFlag(int flagOptionId);

void   OPT_setStringValue(int stringOptionId, const char *value);
const char* OPT_getStringValue(int stringOptionId);

void   OPT_setIntValue(int intOptionId, int value);
int    OPT_getIntValue(int intOptionId);
