#ifndef ERRORS_H
#define ERRORS_H

#include <aterm2.h>
#include <MEPT.h>
#include <ErrorAPI.h>

void RWaddError(char *message, char *subject);
ERR_FeedbackList RWgetErrors();
void  RWclearErrors();
void printErrors(void);

#endif

