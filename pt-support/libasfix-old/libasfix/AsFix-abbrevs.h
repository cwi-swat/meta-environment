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
/*
\subsection{AsFix abbreviations}

The abbreviation mechanism will probably be abandoned when
most tools can cope with sharing.
*/

#ifndef ABBREVS_H
#define ABBREVS_H

#include "aterm1.h"
#include "aterm2.h"

/* \Function{AFexpandEqs}{ATerm }{ATerm eqs, ATermList abbrevs}{
Expand all abbreviations in a set of AsFix equations.} */
ATerm AFexpandEqs(ATerm eqs, ATermList abbrevs);

/* \Function{AFexpandModule}{ATerm }{ATerm module}{
Expand all abbreviations in an AsFix module.} */
ATerm AFexpandModule(ATerm module);

/* \Function{AFExpandTerm}{ATerm }{ATerm term}{Expand all
abbreviations in a AsFix term.} */
ATerm AFexpandTerm(ATerm term);

/* \Function{AFcollapseEqs}{ATerm }{ATerm eqs, ATermList *abbrevs}{
Collapse all abbreviations in a set of AsFix equations.} */
ATerm AFcollapseEqs(ATerm eqs, ATermList *abbrevs);

/* \Function{AFcollapseModule}{ATerm }{ATerm module}{
Collapse all abbreviations in an AsFix module.} */
ATerm AFcollapseModule(ATerm module);

/* \Function{AFCollapseTerm}{ATerm }{ATerm term}{Collapse all
abbreviations in a AsFix term.} */
ATerm AFcollapseTerm(ATerm term);

#endif
