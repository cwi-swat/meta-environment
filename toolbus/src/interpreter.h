#ifndef __INTERPETER_H__
#define __INTERPETER_H__

void add_proc_def(char *,term_list *, term_list *,proc *, term *, int);
proc_def  *definition(sym_idx);

TBbool find_comm(atom *, atom **, proc **, proc_inst **, term *);

ap_form *expand(proc *, proc_inst *);

void rec_from_tool_step(tool_inst *, term *);

void all_internal_steps(void);
void interpreter(void);

void create_toolbus(tool_id *);
void init_interpreter(void);

#endif /* __INTERPETER_H__ */
