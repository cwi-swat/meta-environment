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
static Symbol lf_AUX_Improve_C_code10_1_recursivesym ;
static ATerm lf_AUX_Improve_C_code10_1_recursive ( ATerm arg1 ) ;
static Symbol lf_AUX_Improve_C_code10_1sym ;
static ATerm lf_AUX_Improve_C_code10_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Improve_C_code10 ( ) {
lf_AUX_Improve_C_code10_1_recursivesym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"transform-arg-in-exps\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code10_1_recursivesym ) ;
lf_AUX_Improve_C_code10_1sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"transform-arg-in-exps\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"transform-arg-in-exps\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code10_1 , lf_AUX_Improve_C_code10_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"transform-arg-in-exps\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code10_1_recursive , lf_AUX_Improve_C_code10_1_recursivesym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Improve_C_code10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"transform-arg-in-exp\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"transform-arg-in-exp\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Improve_C_code10 ( ) {
}
ATerm lf_AUX_Improve_C_code10_1 ( ATerm arg0 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code10_1sym , ATmakeAppl ( lf_AUX_Improve_C_code10_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = lf_AUX_Improve_C_code10_1_recursive ( make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
}
}
}
if ( is_single_element ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( ( * ef2 ) ( tmp [ 0 ] ) ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Improve_C_code10_1sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Improve_C_code10_1_recursive ( ATerm arg0 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code10_1_recursivesym , ATmakeAppl ( lf_AUX_Improve_C_code10_1_recursivesym , arg0 ) ) ;
{
ATerm atmp00 = arg0 ;
{
ATerm atmp000 = atmp00 ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = lf_AUX_Improve_C_code10_1_recursive ( make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
}
}
}
if ( is_single_element ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( ( * ef2 ) ( tmp [ 0 ] ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Improve_C_code10_1_recursivesym , ( * ef1 ) ( lf2 ( arg0 ) ) ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

