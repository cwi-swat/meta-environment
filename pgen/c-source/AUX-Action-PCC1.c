/*

    PGEN - the SDF2 parse table generator.
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

*/
/* This C code is generated by the AsfSdfCompiler version 1.0 */

#include  "asc-support.h"
static Symbol lf_AUX_Action_PCC1_1sym ;
static ATerm lf_AUX_Action_PCC1_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Action_PCC1 ( ) {
lf_AUX_Action_PCC1_1sym = ATmakeSymbol ( "prod(id(\"Action-PCC\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CC-LA\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_PCC1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-PCC\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CC-LA\"),w(\"\"),no-attrs)" ) , lf_AUX_Action_PCC1_1 , lf_AUX_Action_PCC1_1sym ) ;
}
void resolve_AUX_Action_PCC1 ( ) {
}
void init_AUX_Action_PCC1 ( ) {
}
ATerm lf_AUX_Action_PCC1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Action_PCC1_1sym , ATmakeAppl ( lf_AUX_Action_PCC1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Action_PCC1_1sym , arg0 , arg1 ) ) ;
}

