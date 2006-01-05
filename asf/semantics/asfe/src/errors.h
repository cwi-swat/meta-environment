#ifndef ERRORS_H
#define ERRORS_H

#include <aterm2.h>
#include <MEPT.h>
#include <Error.h>
#include <Location.h>

void RWaddError(char *message, char *subject);
void RWaddLocatedError(char *message, char *subject, LOC_Location loc);
void RWaddDoubleLocatedError(char *msg, char *subject1, LOC_Location loc1,
			     char *subject2, LOC_Location loc2);
ERR_ErrorList RWgetErrors();
void  RWclearErrors();
void printErrors(void);

#endif

