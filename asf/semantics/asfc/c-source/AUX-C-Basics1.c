/*

    Meta-Environment - An environment for language prototyping.
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
#include  "asc-support.h"
static Symbol lf_AUX_C_Basics1_2sym ;
static ATerm lf_AUX_C_Basics1_2 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_C_Basics1_3sym ;
static ATerm lf_AUX_C_Basics1_3 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_C_Basics1_1sym ;
static ATerm lf_AUX_C_Basics1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_C_Basics1_4sym ;
static ATerm lf_AUX_C_Basics1_4 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_C_Basics1_6sym ;
static ATerm lf_AUX_C_Basics1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_C_Basics1_5sym ;
static ATerm lf_AUX_C_Basics1_5 ( ATerm arg1 ) ;
static Symbol lf_AUX_C_Basics1_7sym ;
static ATerm lf_AUX_C_Basics1_7 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_C_Basics1_8sym ;
static ATerm lf_AUX_C_Basics1_8 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_C_Basics1_9sym ;
static ATerm lf_AUX_C_Basics1_9 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_C_Basics1_10sym ;
static ATerm lf_AUX_C_Basics1_10 ( ATerm arg1 ) ;
static Symbol lf_AUX_C_Basics1_11sym ;
static ATerm lf_AUX_C_Basics1_11 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
void register_AUX_C_Basics1 ( ) {
lf_AUX_C_Basics1_2sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_2sym ) ;
lf_AUX_C_Basics1_3sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_3sym ) ;
lf_AUX_C_Basics1_1sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_1sym ) ;
lf_AUX_C_Basics1_4sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_4sym ) ;
lf_AUX_C_Basics1_6sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_6sym ) ;
lf_AUX_C_Basics1_5sym = ATmakeSymbol ( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_5sym ) ;
lf_AUX_C_Basics1_7sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_7sym ) ;
lf_AUX_C_Basics1_8sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_8sym ) ;
lf_AUX_C_Basics1_9sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_9sym ) ;
lf_AUX_C_Basics1_10sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_10sym ) ;
lf_AUX_C_Basics1_11sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics1_11sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf_AUX_C_Basics1_1 , lf_AUX_C_Basics1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_2 , lf_AUX_C_Basics1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_3 , lf_AUX_C_Basics1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_4 , lf_AUX_C_Basics1_4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"TE-pair\"),ql(\",\"))" ) , lf_AUX_C_Basics1_5 , lf_AUX_C_Basics1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_6 , lf_AUX_C_Basics1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_7 , lf_AUX_C_Basics1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_8 , lf_AUX_C_Basics1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_9 , lf_AUX_C_Basics1_9sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_10 , lf_AUX_C_Basics1_10sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics1_11 , lf_AUX_C_Basics1_11sym ) ;
}
void resolve_AUX_C_Basics1 ( ) {
}
void init_AUX_C_Basics1 ( ) {
}
ATerm lf_AUX_C_Basics1_11 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_11sym , ATmakeAppl ( lf_AUX_C_Basics1_11sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_C_Basics1_11sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_C_Basics1_10 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_10sym , ATmakeAppl ( lf_AUX_C_Basics1_10sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C_Basics1_10sym , arg0 ) ) ;
}
ATerm lf_AUX_C_Basics1_9 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_9sym , ATmakeAppl ( lf_AUX_C_Basics1_9sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_C_Basics1_9sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_C_Basics1_8 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_8sym , ATmakeAppl ( lf_AUX_C_Basics1_8sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_C_Basics1_8sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_C_Basics1_7 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_7sym , ATmakeAppl ( lf_AUX_C_Basics1_7sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_C_Basics1_7sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_C_Basics1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_5sym , ATmakeAppl ( lf_AUX_C_Basics1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C_Basics1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_C_Basics1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_6sym , ATmakeAppl ( lf_AUX_C_Basics1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C_Basics1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_C_Basics1_4 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_4sym , ATmakeAppl ( lf_AUX_C_Basics1_4sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_C_Basics1_4sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_C_Basics1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_1sym , ATmakeAppl ( lf_AUX_C_Basics1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C_Basics1_1sym , arg0 ) ) ;
}
ATerm lf_AUX_C_Basics1_3 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_3sym , ATmakeAppl ( lf_AUX_C_Basics1_3sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_C_Basics1_3sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_C_Basics1_2 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_C_Basics1_2sym , ATmakeAppl ( lf_AUX_C_Basics1_2sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_C_Basics1_2sym , arg0 , arg1 , arg2 ) ) ;
}

