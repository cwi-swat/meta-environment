/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
  $Id$
 */

ATermList sort_and_filter_on_ofs(ATerm name,ATerm firstofs,ATermList eqs);
ATerm rewrite(ATerm trm, ATerm env, int depth);
ATerm v_lookup_plain(ATerm env, ATerm var);
ATermAppl v_lookup_list(ATerm env, ATerm var);
ATbool v_is_bound(ATerm env, ATerm var);
void v_print_slice(ATerm slice);
ATermList prepend(ATermList first, ATermList last, ATermList list);
ATermList prepend_slice(ATermAppl slice, ATermList list);
ATermList append_slice(ATermList list, ATermAppl slice);
ATerm equations_available(int cid, char *name);
void add_equations(int cid, char *modname, ATerm equs);
void remove_equations(int cid, char *modname);
ATerm interpret(int cid, char *modname, ATerm trm);
ATbool no_new_vars(ATerm trm, ATerm env);
ATerm arg_matching(ATerm env, ATerm arg1, ATerm arg2,
		   ATermList conds,
		   ATermList orgargs1, ATermList orgargs2, 
		   ATerm lhs_posinfo, int depth);
ATerm args_matching(ATerm env, ATermList conds,
                    ATermList args1, ATermList args2,
		    ATerm lhs_posinfo, int depth);
ATbool compare_lists(ATermAppl tuple, ATermList list);
ATermList compare_sub_lists(ATermAppl tuple, ATermList elems2);
ATerm sub_list_matching(ATerm asym, ATerm env, ATerm elem,
                        ATermList elems1, ATermList elems2,
                        ATermList conds,
                        ATermList args1, ATermList args2,
			ATerm lhs_posinfo, int depth);
ATerm list_matching(ATerm sym,
                    ATerm env,ATermList elems1, ATermList elems2,
                    ATermList conds, ATermList args1, ATermList args2,
		    ATerm lhs_posinfo, int depth);
ATerm conds_satisfied(ATermList conds, ATerm env, int depth);
ATerm apply_rule(ATerm trm, int depth);
ATerm select_and_rewrite(ATerm trm, int depth);
ATermList rewrite_args(ATermList args, ATerm env, int depth);
ATermList rewrite_elems(ATerm sym, ATermList elems, ATerm env, int depth);
ATerm rewrite(ATerm trm, ATerm env, int depth);
void RWsetError(const char *message, ATerm subject);
ATerm RWgetError();
void  RWclearError();

/* Variables */
extern ATbool run_verbose;
extern ATbool keep_layout;
extern ATerm equations_db;
extern ATerm fail_env;
extern ATerm posinfo;
extern ATerm rewrite_error;
extern ATerm tagCurrentRule;
extern AFun list_var, plain_var;


#define is_fail_env(env)	(ATisEqual(env,fail_env))
/*#define v_lookup(env,var)	(ATdictGet(env,var))*/
#define v_is_slice(val)   (ATgetAFun((ATermAppl)val) == list_var)
#define v_get_first(val)  ((ATermList)ATgetArgument((ATermAppl)val, 1))
#define v_get_last(val)  ((ATermList)ATgetArgument((ATermAppl)val, 2))
#ifndef KEEP_LAYOUT
#define v_is_empty_slice(val) (v_get_first(val) == v_get_last(val))
#else
#define v_is_empty_slice(val) (skipWhitespace(v_get_first(val)) == v_get_last(val))
#endif
#define v_put(env,var,val) ((ATerm)ATinsert((ATermList)env, \
													(ATerm)ATmakeAppl2(plain_var, var,val)))
#define v_put_list(env,var,start,end) \
  ((ATerm)ATinsert((ATermList)env, \
		 (ATerm)ATmakeAppl3(list_var, var, (ATerm)start, (ATerm)end)))
#define get_term(cenv)		(ATgetFirst(cenv))
#define get_env(cenv)		(ATgetFirst(ATgetNext(cenv)))
#define make_cenv(t,e)		(ATmakeList(2, t, e))
