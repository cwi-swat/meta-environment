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

TBbool typecheck(char *, TBbool, char *);

#endif /*  __TYPECHECK_H__ */
