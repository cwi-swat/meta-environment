/*

    SGLR - the Scannerless Generalized LR parser.
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
#ifndef _SGLR_STRINGS_H_
#define _SGLR_STRINGS_H_  1

/*  AFuns  */

#define SG_APPL_AFUN		"appl"
#define SG_REGULAR_AFUN		"regular"
#define SG_REJECT_AFUN		"reject"
#define SG_PREFER_AFUN		"prefer"
#define SG_AVOID_AFUN		"avoid"
#define SG_APROD_AFUN		"aprod"
#define SG_AMB_AFUN		"amb"
#define SG_GTRPRIO_AFUN		"gtr-prio"
#define SG_LEFTPRIO_AFUN	"left-prio"
#define SG_RIGHTPRIO_AFUN	"right-prio"
#define SG_SHIFT_AFUN		"shift"
#define SG_REDUCE_AFUN		"reduce"
#define SG_ACCEPT_AFUN		"accept"
#define SG_RANGE_AFUN		"range"
#define SG_CHARCLASS_AFUN	"char-classs"
#define SG_ACTION_AFUN		"action"
#define SG_GOTO_AFUN		"goto"
#define SG_PARSETABLE_AFUN	"parse-table"
#define SG_STATEREC_AFUN	"state-rec"
#define SG_LABEL_AFUN		"label"
#define SG_PARSETREE_AFUN	"parsetree"
#define SG_TERM_AFUN		"term"
#define SG_AF1PARSETREE_AFUN	"asfix1-parsetree"
#define SG_PARSEERROR_AFUN	"parse-error"
#define SG_EOF_AFUN		"eof"
#define SG_PLAIN_AFUN		"plain"
#define SG_CYCLE_AFUN		"cycle"
#define SG_AMBIGUITIES_AFUN	"ambiguities"
#define SG_SNDVALUE_AFUN	"snd-value"
#define SG_CHARACTER_AFUN	"character"
#define SG_LINE_AFUN		"line"
#define SG_COL_AFUN		"col"
#define SG_OFFSET_AFUN		"char"


/*  Attributes  */

#define SG_POSITION_ATTR	"position"
#define SG_INJECTIONS_ATTR	"injections"
#define SG_REJECT_ATTR		"reject"
#define SG_PREFER_ATTR		"prefer"
#define SG_AVOID_ATTR		"avoid"


#endif  /*  _SGLR_STRINGS_H_  */
