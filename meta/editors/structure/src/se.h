/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

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

#ifndef SE_H
#define SE_H

#include <atb-tool.h>
#include <string.h>
#include <AsFix.h>
#include "AsFix-access.h"
#include <aterm2.h>
#include "deprecated.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "se.tif.h"

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

void AFinitAsFixPatterns();

extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_term;
extern ATerm pattern_asfix_imports;
extern ATerm pattern_asfix_ews;
extern ATerm pattern_asfix_ws;
extern ATerm pattern_asfix_nlws;
extern ATerm pattern_asfix_sort;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_sep;
extern ATerm pattern_asfix_iter;
extern ATerm pattern_asfix_itersep;
extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_prod;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_list;
extern ATerm pattern_asfix_lex;
extern ATerm pattern_asfix_id;

#endif /* SE_H */
