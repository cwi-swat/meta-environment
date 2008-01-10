/*$Id$*/

/* Handles tool's options. */ 

#include <aterm2.h>

void   OPT_initialize(void);
void   OPT_cleanup(void);

int OPT_getIntOptionId(void);
int OPT_getStringOptionId(void);
int OPT_getFlagOptionId(void);

void   OPT_setFlag(int flagOptionId, ATbool value);
ATbool OPT_getFlag(int flagOptionId);

void   OPT_setStringValue(int stringOptionId, const char *value);
const char* OPT_getStringValue(int stringOptionId);

void   OPT_setIntValue(int intOptionId, int value);
int    OPT_getIntValue(int intOptionId);
