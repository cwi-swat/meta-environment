#include "toolbus.h"
#include "terms.h"
#include "env.h"
#include "procs.h"
#include "tools.h"
#include "match.h"
#include "utils.h"
#include "interpreter.h"
#include "monitor.h"

mon_method monitoring = none;

void set_monitoring(mon_method m)
{
  monitoring = m;
}
 
term *init_monitoring()
{
  tool_id *create_tool(term *, term_list *);

  switch(monitoring)
    {
    case logger:
     /* add standard logger definition if none defined in the script */
      if(!find_tool_def(mon_logger))
	add_tool_def("logger", NULL, "", "wish-adapter -script "LOGGER_TCL, "", NULL, 0);
      return 
	mk_appl1(mon_logger, create_tool(mk_appl(mon_logger, NULL), NULL));
 
    case viewer:
      /* add standard viewer definition if none defined in the script */
      if(!find_tool_def(mon_viewer))
	add_tool_def("viewer", NULL, "", "wish-adapter -script "VIEWER_TCL, "", NULL, 0);
      return 
	mk_appl1(mon_viewer, create_tool(mk_appl(mon_viewer, NULL), NULL));

    case controller:
      err_warn("controllers not yet implemented");
      return NULL;
    default:
      return NULL;
    }
}

atom *mk_snd_monitor(term *monitor, atom *Atom, proc *P, proc_inst *ProcInst1, proc_inst *ProcInst2)
{
  char *fun;
  proc * pr;
  atom *MonAtom;

  assert(is_monitor(monitor));
  switch(fun_sym(monitor)){
  case mon_viewer:
    fun = "viewpoint"; pr = Delta; break;
  case mon_logger:
    fun = "logpoint"; pr = Delta; break;
  case mon_controller:
    fun = "controlpoint"; pr = P; break;
  default:
    err_warn("mk_snd_monitor: illegal monitor kind: %t", monitor);
    return Delta;
  }
  MonAtom =
    mk_atom(a_snd_monitor,
	    TBmake("[%t,%f(%d,%f,%t,%t,%t,%t,%t,%d,%t)]",
		   monitor,
		   fun,
		   int_val(pi_pid(ProcInst1)),
		   get_txt(at_fun(Atom)),
		   at_args(Atom),
		  /*  substitute_list(at_args(Atom),pi_env(ProcInst1)), */
		   at_coords(Atom),		      
		   pi_env(ProcInst1),
		   pi_subs(ProcInst1),
		   pi_notes(ProcInst1),
		   (ProcInst2) ? int_val(pi_pid(ProcInst2)) : -1,
		   pr),
	    at_coords(Atom));
  /* TBmsg("%t\n", MonAtom); */
  return MonAtom;
}

