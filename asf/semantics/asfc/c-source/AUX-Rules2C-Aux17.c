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
/* This C code is generated by the AsfSdfCompiler version 0.1 */

#include  "asc-support.h"
static Symbol lf_AUX_Rules2C_Aux17_2sym ;
static ATerm lf_AUX_Rules2C_Aux17_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Rules2C_Aux17_1sym ;
static ATerm lf_AUX_Rules2C_Aux17_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux17 ( ) {
lf_AUX_Rules2C_Aux17_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux17_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf_AUX_Rules2C_Aux17_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux17_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux17_1 , lf_AUX_Rules2C_Aux17_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux17_2 , lf_AUX_Rules2C_Aux17_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Rules2C_Aux17 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Rules2C_Aux17 ( ) {
}
ATerm lf_AUX_Rules2C_Aux17_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 31 ] ;
FUNC_ENTRY ( lf_AUX_Rules2C_Aux17_2sym , ATmakeAppl ( lf_AUX_Rules2C_Aux17_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , lf4sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
{
ATerm atmp03 = arg_3 ( arg0 ) ;
{
ATerm atmp04 = arg_4 ( arg0 ) ;
{
ATerm atmp05 = arg_5 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux17_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp010 ) ) {
( tmp [ 0 ] = list_head ( atmp010 ) ) ;
( tmp [ 1 ] = list_tail ( atmp010 ) ) ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 2 ] = list_head ( atmp10 ) ) ;
( tmp [ 3 ] = list_tail ( atmp10 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 5 ] = arg_1 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 7 ] = arg_1 ( tmp [ 2 ] ) ) ;
( tmp [ 8 ] = arg_2 ( tmp [ 2 ] ) ) ;
( tmp [ 9 ] = arg_3 ( tmp [ 2 ] ) ) ;
( tmp [ 10 ] = arg_4 ( tmp [ 2 ] ) ) ;
( tmp [ 11 ] = arg_5 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
( tmp [ 14 ] = list_head ( tmp [ 13 ] ) ) ;
( tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ) ;
if ( check_sym ( tmp [ 14 ] , ef3sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ) ;
( tmp [ 17 ] = arg_1 ( tmp [ 14 ] ) ) ;
if ( term_equal ( tmp [ 4 ] , tmp [ 16 ] ) ) {
if ( ! term_equal ( tmp [ 5 ] , tmp [ 17 ] ) ) {
( tmp [ 18 ] = lf_AUX_Rules2C_Aux17_2 ( ( * ef2 ) ( lf3 ( make_list ( atmp000 ) ) , lf4 ( cons ( make_list ( ( * ef3 ) ( tmp [ 4 ] , tmp [ 5 ] ) ) , make_list ( tmp [ 1 ] ) ) ) , atmp02 , atmp03 , atmp04 , atmp05 ) , lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 3 ] ) ) ) ) ;
if ( check_sym ( tmp [ 18 ] , ef1sym ) ) {
( tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ) ;
( tmp [ 20 ] = arg_1 ( tmp [ 18 ] ) ) ;
if ( check_sym ( tmp [ 19 ] , lf_AUX_Rules2C_Aux17_1sym ) ) {
( tmp [ 21 ] = arg_0 ( tmp [ 19 ] ) ) ;
if ( check_sym ( tmp [ 20 ] , lf_AUX_Rules2C_Aux17_1sym ) ) {
( tmp [ 22 ] = arg_0 ( tmp [ 20 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 21 ] ) ) , lf_AUX_Rules2C_Aux17_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 12 ] ) ) , lf4 ( cons ( make_list ( ( * ef3 ) ( tmp [ 4 ] , tmp [ 17 ] ) ) , make_list ( tmp [ 15 ] ) ) ) , tmp [ 8 ] , tmp [ 9 ] , tmp [ 10 ] , tmp [ 11 ] ) ) , make_list ( tmp [ 22 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux17_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
if ( ! term_equal ( arg0 , tmp [ 0 ] ) ) {
if ( check_sym ( arg0 , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( arg0 ) ) ;
( tmp [ 3 ] = arg_1 ( arg0 ) ) ;
( tmp [ 4 ] = arg_2 ( arg0 ) ) ;
( tmp [ 5 ] = arg_3 ( arg0 ) ) ;
( tmp [ 6 ] = arg_4 ( arg0 ) ) ;
( tmp [ 7 ] = arg_5 ( arg0 ) ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
( tmp [ 10 ] = list_head ( tmp [ 9 ] ) ) ;
( tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 10 ] , ef3sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ) ;
( tmp [ 13 ] = arg_1 ( tmp [ 10 ] ) ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 15 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 16 ] = arg_2 ( tmp [ 0 ] ) ) ;
( tmp [ 17 ] = arg_3 ( tmp [ 0 ] ) ) ;
( tmp [ 18 ] = arg_4 ( tmp [ 0 ] ) ) ;
( tmp [ 19 ] = arg_5 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 14 ] , lf3sym ) ) {
( tmp [ 20 ] = arg_0 ( tmp [ 14 ] ) ) ;
if ( check_sym ( tmp [ 15 ] , lf4sym ) ) {
( tmp [ 21 ] = arg_0 ( tmp [ 15 ] ) ) ;
if ( not_empty_list ( tmp [ 21 ] ) ) {
( tmp [ 22 ] = list_head ( tmp [ 21 ] ) ) ;
( tmp [ 23 ] = list_tail ( tmp [ 21 ] ) ) ;
if ( check_sym ( tmp [ 22 ] , ef3sym ) ) {
( tmp [ 24 ] = arg_0 ( tmp [ 22 ] ) ) ;
( tmp [ 25 ] = arg_1 ( tmp [ 22 ] ) ) ;
if ( term_equal ( tmp [ 12 ] , tmp [ 24 ] ) ) {
if ( term_equal ( tmp [ 13 ] , tmp [ 25 ] ) ) {
( tmp [ 26 ] = lf_AUX_Rules2C_Aux17_2 ( arg0 , lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 26 ] , ef1sym ) ) {
( tmp [ 27 ] = arg_0 ( tmp [ 26 ] ) ) ;
( tmp [ 28 ] = arg_1 ( tmp [ 26 ] ) ) ;
if ( check_sym ( tmp [ 27 ] , lf_AUX_Rules2C_Aux17_1sym ) ) {
( tmp [ 29 ] = arg_0 ( tmp [ 27 ] ) ) ;
if ( check_sym ( tmp [ 28 ] , lf_AUX_Rules2C_Aux17_1sym ) ) {
( tmp [ 30 ] = arg_0 ( tmp [ 28 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux17_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 29 ] ) ) ) , lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 30 ] ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
else {
( tmp [ 2 ] = lf_AUX_Rules2C_Aux17_2 ( arg0 , lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_Rules2C_Aux17_1sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Rules2C_Aux17_1sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 5 ] ) ) , lf_AUX_Rules2C_Aux17_1 ( make_list ( tmp [ 6 ] ) ) ) ) ;
}
}
}
}
}
}
else {
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux17_1 ( make_list ( arg0 ) ) , lf_AUX_Rules2C_Aux17_1 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Rules2C_Aux17_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Rules2C_Aux17_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Rules2C_Aux17_1sym , ATmakeAppl ( lf_AUX_Rules2C_Aux17_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux17_1sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

