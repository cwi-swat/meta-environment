#ifndef __ENV_H__
#define __ENV_H__

/* ---------------------- env ----------------------- */

/* typedef term env; */
/* typedef term entry; */

/* #define mk_entry(v, t)  mk_list2(v, t) */

/* #define entry_var(ent)  elm1(ent) */
/* #define entry_sym(ent)  var_sym(elm1(ent)) */
/* #define entry_val(ent)  elm2(ent) */

/* #define mk_env(v,t,e)  mk_list(mk_entry(v,t),e) */

env  *assign(var *, term *, env *);
env  *update(env *, env *);
term *value(term *, env *);
env  *create_env(term_list *, const char *, term_list *, env *);
env  *undefine(term_list *, env *);
env  *define(term_list *, env *);

void init_env(void);

#endif /* __ENV_H__ */
