#ifndef __TYPECHECK_H__
#define __TYPECHECK_H__

void tc_create(atom *);
void tc_printf(atom *);
void tc_call(char *, atom *, coords *);
void tc_execute(proc *);
void tc_connect(proc *);
void tc_assign(atom *);
void tc_cond(term *, coords *);
void tc_tool_atom(atom *);
TBbool check_formals_vars(term_list *, term_list *, term *, int);
TBbool check_let_vars(term_list *, term_list *, term_list *, term *, int);
void tc_double_decl(char *, char *, term *, int);
void tc_not_decl(char *, char *, term *, int);
void tc_ill_result(char *, char *, term *, int);

TBbool typecheck(char *, TBbool);

#endif /*  __TYPECHECK_H__ */
