/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam, 
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
/* This C code is generated by the AsfSdfCompiler version 1.3 */

#include  "asc-support.h"
static Symbol lf_AUX_MuLiterals1_2sym ;
static ATerm lf_AUX_MuLiterals1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuLiterals1_3sym ;
static ATerm lf_AUX_MuLiterals1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuLiterals1_4sym ;
static ATerm lf_AUX_MuLiterals1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuLiterals1_1sym ;
static ATerm lf_AUX_MuLiterals1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuLiterals1_5sym ;
static ATerm lf_AUX_MuLiterals1_5 ( ATerm arg1 ) ;
void register_AUX_MuLiterals1 ( ) {
lf_AUX_MuLiterals1_2sym = ATmakeSymbol ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuLiterals1_2sym ) ;
lf_AUX_MuLiterals1_3sym = ATmakeSymbol ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuLiterals1_3sym ) ;
lf_AUX_MuLiterals1_4sym = ATmakeSymbol ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuLiterals1_4sym ) ;
lf_AUX_MuLiterals1_1sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuLiterals1_1sym ) ;
lf_AUX_MuLiterals1_5sym = ATmakeSymbol ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuLiterals1_5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf_AUX_MuLiterals1_1 , lf_AUX_MuLiterals1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)" ) , lf_AUX_MuLiterals1_2 , lf_AUX_MuLiterals1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" ) , lf_AUX_MuLiterals1_3 , lf_AUX_MuLiterals1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)" ) , lf_AUX_MuLiterals1_4 , lf_AUX_MuLiterals1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_MuLiterals1_5 , lf_AUX_MuLiterals1_5sym ) ;
}
void resolve_AUX_MuLiterals1 ( ) {
}
void init_AUX_MuLiterals1 ( ) {
}
ATerm lf_AUX_MuLiterals1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuLiterals1_5sym , ATmakeAppl ( lf_AUX_MuLiterals1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuLiterals1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_MuLiterals1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuLiterals1_1sym , ATmakeAppl ( lf_AUX_MuLiterals1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuLiterals1_1sym , arg0 ) ) ;
}
ATerm lf_AUX_MuLiterals1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuLiterals1_4sym , ATmakeAppl ( lf_AUX_MuLiterals1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuLiterals1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_MuLiterals1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuLiterals1_3sym , ATmakeAppl ( lf_AUX_MuLiterals1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuLiterals1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_MuLiterals1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuLiterals1_2sym , ATmakeAppl ( lf_AUX_MuLiterals1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuLiterals1_2sym , arg0 ) ) ;
}

