#ifndef GENERATE_H
#define GENERATE_H
#include <MEPT.h>

ATerm normalize_and_generate_table(const char *name, PT_ParseTree sdf2term);
ATerm sdf_generate_table(PT_Tree ksdf);

#endif
