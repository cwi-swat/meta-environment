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
#ifndef __MATCH_H__
#define __MATCH_H__


extern env *Bindings1, *Bindings2;

       term     *substitute(term *, env *);
       term     *substitute_list(term *, env *);
       TBbool    match(term *, term *, env *, env *);
static TBbool    match1(term *, term *);
static TBbool    match_list(term *, term *);

TBbool    cmatchp(term *, term *);

void     init_match(void);

#endif /* __MATCH_H__ */



