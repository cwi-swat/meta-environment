#ifndef PICO_SUPPORT_H
#define PICO_SUPPORT_H

typedef char *string;

extern int pico_natural(int *var, string name);
extern string pico_string(string *var, string name);
extern string pico_concat(string s1, string s2);
extern void finish();

extern void debugstep(int linenr);

extern char *source;
#define PICOPROGRAM(name) char *source = name

#define PICONATURAL(var) int var = pico_natural(&var, #var)
#define PICOSTRING(var)  string var = pico_string(&var, #var)

#endif
