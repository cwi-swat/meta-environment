#ifndef __TOOLBUS_H__
#define __TOOLBUS_H__

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/param.h>
#include <netdb.h>

typedef enum TBbool {TBfalse, TBtrue} TBbool;

extern TBbool ToolBus;

void err_sys_warn(const char *, ...);
void err_sys_fatal(const char *, ...);
void err_warn(const char *, ...);
void err_fatal(const char *, ...);

#endif /* __TOOLBUS_H__ */
