#ifndef __TOOLS_H__
#define __TOOLS_H__

/*--- tool definitions ------------------------------------*/

typedef term tool_def;
typedef term tool_def_list;

#define mk_tool_def(id,formals, host, command, details) \
        mk_appl6(TBlookup(id), formals, mk_str(host), \
		 mk_str(command), mk_str(details), NULL, NULL)

#define td_name(td)     fun_sym(td)
#define td_formals(td)          elm1(fun_args(td))
#define td_host(td)     str_val(elm2(fun_args(td)))
#define td_command(td)  str_val(elm3(fun_args(td)))
#define td_details(td)  str_val(elm4(fun_args(td)))
#define td_in_sign(td)          elm5(fun_args(td))
#define td_out_sign(id)         elm6(fun_args(td))

void add_tool_def(char *, term_list *, char *, char *, char *, term *, int);
tool_def *find_tool_def(sym_idx);

/*--- tool instances --------------------------------------*/

typedef term tool_inst;
typedef term_list tool_inst_list;
typedef term tool_id;

#define PHASE1  1     /* unconnected */
#define PHASE2  2     /* connected, start state */
#define PHASE3  3     /* snd-eval received      */

#define equal_tool_id(Tid1, Tid2) (int_val(Tid1) == int_val(Tid2))

#define mk_tool_inst(creator, Tid, host, in, out, phase) \
        mk_appl7(s_tool_inst,creator,mk_int(Tid),\
		 mk_int(in), mk_int(out), mk_str(host), \
		 mk_int(phase), NULL)
      

#define ti_name(ti)    fun_sym(ti_creator(ti))
#define ti_creator(ti)         elm1(fun_args(ti))
#define ti_tid(ti)             elm2(fun_args(ti))
#define ti_in(ti)      int_val(elm3(fun_args(ti)))
#define ti_out(ti)     int_val(elm4(fun_args(ti)))
#define ti_host(ti)    str_val(elm5(fun_args(ti)))
#define ti_phase(ti)   int_val(elm6(fun_args(ti)))
#define ti_pending(ti)         elm7(fun_args(ti))

#define is_tool_inst(ti) ((ti) && is_appl(ti) && (fun_sym(ti) == s_tool_inst))

int TCP_transition(tool_inst *, term *, TBbool);
void destroy_ports_for_tool(tool_inst *);
TBbool write_to_tool(sym_idx, term_list *);
int add_tool(char *id, char *host);

void complete_tool_sigs(int);

void  init_tools(void);

#endif /* __TOOLS_H__ */
