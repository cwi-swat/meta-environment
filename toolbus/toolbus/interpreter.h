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
#ifndef __INTERPETER_H__
#define __INTERPETER_H__

void add_proc_def(char *,term_list *, term_list *,proc *, term *, int);
proc_def  *definition(sym_idx);

static TBbool find_comm(atom *, atom **, proc **, proc_inst **, term *);

static term *itp(term *, proc_inst *);
static ap_form *expand(proc *, proc_inst *);

void rec_from_tool_step(tool_inst *, term *);

void all_internal_steps(void);
void interpreter(void);

void create_toolbus(tool_id *);
void init_interpreter(void);

#endif /* __INTERPETER_H__ */
