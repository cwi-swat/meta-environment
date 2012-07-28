/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

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
