#include "TB.h"

term *handle_input_from_toolbus(term *e)
{
  int pid1, pid2, Lino, Pos;
  term *Env, *Subs, *Notes, *AtArgs, *trm;
  char *AtFun;

  if(TBmatch(e, "break(%d,%f,%t,%d,%d,%t,%t,%t,%d)",
	     &pid1,
	     &AtFun,
	     &AtArgs,
	     &Lino,
	     &Pos,
	     &Env,
	     &Subs,
	     &Notes,
	     &pid2)){
    TBmsg("%t\n", e);
    return TBmakeTerm("continue(%d)", pid1);

  } else if(TBmatch(e, "terminate")){
    exit(0);

  } else if(TBmatch(e, "shutdown(%t)", &trm)){
    TBmsg("%t\n", trm);
    exit(0);

  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

void main(int argc, char *argv[])
{

  TBinit("txt_dbg", argc, argv, handle_input_from_toolbus);
  TBput(TBmakeTerm("attach-debugger"));
  TBeventloop();
}
