#ifndef TCLTK_TIDE_H
#define TCLTK_TIDE_H

void init_tide_support(int argc, char *argv[]);
int handle_tide_error(Tcl_Interp *interp, char *code, char *msg, char *info);
int Tide_Init(Tcl_Interp *interp);

extern ATbool use_tide;
extern int tide_cid;

#endif
