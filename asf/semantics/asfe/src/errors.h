#ifndef ERRORS_H
#define ERRORS_H

void RWsetError(const char *message, ATerm subject);
ATerm RWgetError();
void  RWclearError();
void printErrors(void);

#endif

