#ifndef ERRORS_H
#define ERRORS_H

#include <aterm2.h>
#include <MEPT.h>

void RWsetError(const char *message, PT_Tree subject);
ATerm RWgetError();
void  RWclearError();
void printErrors(void);

#endif

