/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
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

   $Id$
*/
#ifndef ATERM_MAC_H
#define ATERM_MAC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "encoding.h"
#include "abool.h"
#include "aterm2.h"

/* 
t_is_... macros

\Macro{t\_is\_appl}{ATbool }{ATerm }{Check if a term is an application.}
*/

#define t_is_asfix_appl(t) (ATgetType(t) == AT_APPL && ATgetSymbol((ATermAppl) t) == symbol_asfix_appl)
#define t_is_appl(t) (ATgetType(t) == AT_APPL)

/*
\Macro{t\_is\_list}{ATbool }{ATerm }{Check if a term is a list.}
*/

#define t_is_asfix_list(t) (ATgetType(t) == AT_LIST)

#define t_is_asfix_int(t) (ATgetType(t) == AT_INT)

#define asfix_str_eq(s,t)      (!(strcmp(s,t)))

#define strprefix(a,b) (strncmp(a,b,strlen(b)) == 0)

#endif
