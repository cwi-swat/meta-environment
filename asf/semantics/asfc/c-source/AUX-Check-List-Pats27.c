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
static Symbol lf_AUX_Check_List_Pats27_2_recursivesym ;
static ATerm lf_AUX_Check_List_Pats27_2_recursive ( ATerm arg1 ) ;
static Symbol lf_AUX_Check_List_Pats27_2sym ;
static ATerm lf_AUX_Check_List_Pats27_2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Check_List_Pats27_1sym ;
static ATerm lf_AUX_Check_List_Pats27_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Check_List_Pats27 ( ) {
lf_AUX_Check_List_Pats27_2_recursivesym = ATmakeSymbol ( "prod(id(\"Check-List-Pats\"),w(\"\"),[ql(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats27_2_recursivesym ) ;
lf_AUX_Check_List_Pats27_2sym = ATmakeSymbol ( "prod(id(\"Check-List-Pats\"),w(\"\"),[ql(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats27_2sym ) ;
lf_AUX_Check_List_Pats27_1sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats27_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_Check_List_Pats27_1 , lf_AUX_Check_List_Pats27_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Check-List-Pats\"),w(\"\"),[ql(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Check_List_Pats27_2 , lf_AUX_Check_List_Pats27_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Check-List-Pats\"),w(\"\"),[ql(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Check_List_Pats27_2_recursive , lf_AUX_Check_List_Pats27_2_recursivesym ) ;
}
void resolve_AUX_Check_List_Pats27 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Check-List-Pats\"),w(\"\"),[ql(\"contains-zero-or-one-list-vars-in-cond\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Check-List-Pats\"),w(\"\"),[ql(\"contains-zero-or-one-list-vars-in-cond\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Check_List_Pats27 ( ) {
}
ATerm lf_AUX_Check_List_Pats27_2 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Check_List_Pats27_2sym , ATmakeAppl ( lf_AUX_Check_List_Pats27_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Check_List_Pats27_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( tmp [ 0 ] ) , lf_AUX_Check_List_Pats27_2_recursive ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
}
if ( is_single_element ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 0 ] ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Check_List_Pats27_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Check_List_Pats27_2_recursive ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Check_List_Pats27_2_recursivesym , ATmakeAppl ( lf_AUX_Check_List_Pats27_2_recursivesym , arg0 ) ) ;
{
ATerm atmp00 = arg0 ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( tmp [ 0 ] ) , lf_AUX_Check_List_Pats27_2_recursive ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
}
if ( is_single_element ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 0 ] ) ) ;
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Check_List_Pats27_2_recursivesym , lf_AUX_Check_List_Pats27_1 ( arg0 ) ) ) ;
}
}
ATerm lf_AUX_Check_List_Pats27_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Check_List_Pats27_1sym , ATmakeAppl ( lf_AUX_Check_List_Pats27_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Check_List_Pats27_1sym , arg0 ) ) ;
}

