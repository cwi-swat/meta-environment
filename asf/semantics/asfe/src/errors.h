#ifndef ERRORS_H
#define ERRORS_H

#include <aterm2.h>

void RWsetError(const char *message, ATerm subject);
ATerm RWgetError();
void  RWclearError();
void printErrors(void);

#endif

