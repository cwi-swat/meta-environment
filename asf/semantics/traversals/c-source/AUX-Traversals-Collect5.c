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

*/
/* This C code is generated by the AsfSdfCompiler version 1.2 */

#include  "asc-support.h"
static Symbol lf_AUX_Traversals_Collect5_1sym ;
static ATerm lf_AUX_Traversals_Collect5_1 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Traversals_Collect5 ( ) {
lf_AUX_Traversals_Collect5_1sym = ATmakeSymbol ( "prod(id(\"Traversals-Collect\"),w(\"\"),[ql(\"all_in_sections\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Sections\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Traversals_Collect5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Section\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Traversals-Collect\"),w(\"\"),[ql(\"all_in_sections\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Sections\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) , lf_AUX_Traversals_Collect5_1 , lf_AUX_Traversals_Collect5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Section\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Traversals_Collect5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Section\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Sections\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Section\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Sections\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Traversals-Collect\"),w(\"\"),[ql(\"all_in_section\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Section\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Traversals-Collect\"),w(\"\"),[ql(\"all_in_section\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Section\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Traversals_Collect5 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Traversals_Collect5_1 ( ATerm arg0 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Traversals_Collect5_1sym , ATmakeAppl ( lf_AUX_Traversals_Collect5_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
( tmp [ 2 ] = ( * ef3 ) ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = lf_AUX_Traversals_Collect5_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 5 ] , ef2sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( ( * ef2 ) ( lf3 ( cons ( make_list ( tmp [ 4 ] ) , make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Traversals_Collect5_1sym , arg0 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

