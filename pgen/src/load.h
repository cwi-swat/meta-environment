#ifndef LOAD_H
#define LOAD_H
#include <MEPT.h>

PT_ParseTree load(const char *topModule, const char* path);
PT_ParseTree parseDefinition(const char *fp);

#endif
