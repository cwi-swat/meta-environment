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
static Symbol lf_AUX_VarEnv22_2_recursivesym ;
static ATerm lf_AUX_VarEnv22_2_recursive ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_VarEnv22_2sym ;
static ATerm lf_AUX_VarEnv22_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf_AUX_VarEnv22_1sym ;
static ATerm lf_AUX_VarEnv22_1 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_VarEnv22 ( ) {
lf_AUX_VarEnv22_2_recursivesym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"is-delaying\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv22_2_recursivesym ) ;
lf_AUX_VarEnv22_2sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"is-delaying\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv22_2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_VarEnv22_1sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv22_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_VarEnv22_1 , lf_AUX_VarEnv22_1sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"is-delaying\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv22_2 , lf_AUX_VarEnv22_2sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"is-delaying\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv22_2_recursive , lf_AUX_VarEnv22_2_recursivesym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_VarEnv22 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_VarEnv22 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_VarEnv22_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 34 ] ;
FUNC_ENTRY ( lf_AUX_VarEnv22_2sym , ATmakeAppl ( lf_AUX_VarEnv22_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_VarEnv22_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
{
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = tmp [ 5 ] ) ;
( tmp [ 7 ] = tmp [ 5 ] ) ;
while ( not_empty_list ( tmp [ 5 ] ) ) {
( tmp [ 8 ] = list_head ( tmp [ 5 ] ) ) ;
( tmp [ 5 ] = list_tail ( tmp [ 5 ] ) ) ;
{
if ( check_sym ( tmp [ 8 ] , ef2sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ) ;
( tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ) ;
{
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 9 ] ) ) ;
{
if ( check_sym ( tmp [ 11 ] , lf4sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ) ;
{
if ( check_sym ( tmp [ 10 ] , lf3sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ) ;
{
if ( not_empty_list ( tmp [ 12 ] ) ) {
( tmp [ 14 ] = list_head ( tmp [ 12 ] ) ) ;
if ( term_equal ( tmp [ 14 ] , make_char ( 100 ) ) ) {
( tmp [ 15 ] = list_tail ( tmp [ 12 ] ) ) ;
{
if ( not_empty_list ( tmp [ 15 ] ) ) {
( tmp [ 16 ] = list_head ( tmp [ 15 ] ) ) ;
if ( term_equal ( tmp [ 16 ] , make_char ( 101 ) ) ) {
( tmp [ 17 ] = list_tail ( tmp [ 15 ] ) ) ;
{
if ( not_empty_list ( tmp [ 17 ] ) ) {
( tmp [ 18 ] = list_head ( tmp [ 17 ] ) ) ;
if ( term_equal ( tmp [ 18 ] , make_char ( 108 ) ) ) {
( tmp [ 19 ] = list_tail ( tmp [ 17 ] ) ) ;
{
if ( not_empty_list ( tmp [ 19 ] ) ) {
( tmp [ 20 ] = list_head ( tmp [ 19 ] ) ) ;
if ( term_equal ( tmp [ 20 ] , make_char ( 97 ) ) ) {
( tmp [ 21 ] = list_tail ( tmp [ 19 ] ) ) ;
{
if ( not_empty_list ( tmp [ 21 ] ) ) {
( tmp [ 22 ] = list_head ( tmp [ 21 ] ) ) ;
if ( term_equal ( tmp [ 22 ] , make_char ( 121 ) ) ) {
( tmp [ 23 ] = list_tail ( tmp [ 21 ] ) ) ;
{
if ( not_empty_list ( tmp [ 23 ] ) ) {
( tmp [ 24 ] = list_head ( tmp [ 23 ] ) ) ;
if ( term_equal ( tmp [ 24 ] , make_char ( 105 ) ) ) {
( tmp [ 25 ] = list_tail ( tmp [ 23 ] ) ) ;
{
if ( not_empty_list ( tmp [ 25 ] ) ) {
( tmp [ 26 ] = list_head ( tmp [ 25 ] ) ) ;
if ( term_equal ( tmp [ 26 ] , make_char ( 110 ) ) ) {
( tmp [ 27 ] = list_tail ( tmp [ 25 ] ) ) ;
{
if ( is_single_element ( tmp [ 27 ] ) ) {
( tmp [ 28 ] = list_head ( tmp [ 27 ] ) ) ;
if ( term_equal ( tmp [ 28 ] , make_char ( 103 ) ) ) {
if ( not_empty_list ( tmp [ 13 ] ) ) {
if ( check_sym ( arg0 , ef3sym ) ) {
( tmp [ 29 ] = arg_0 ( arg0 ) ) ;
if ( check_sym ( tmp [ 29 ] , lf4sym ) ) {
( tmp [ 30 ] = arg_0 ( tmp [ 29 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
( tmp [ 31 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 31 ] , lf4sym ) ) {
( tmp [ 32 ] = arg_0 ( tmp [ 31 ] ) ) ;
if ( not_empty_list ( tmp [ 32 ] ) ) {
if ( term_equal ( list_head ( tmp [ 32 ] ) , make_char ( 95 ) ) ) {
( tmp [ 33 ] = list_tail ( tmp [ 32 ] ) ) ;
if ( term_equal ( ( * ef3 ) ( lf4 ( make_list ( tmp [ 30 ] ) ) ) , ( * ef3 ) ( lf4 ( make_list ( tmp [ 33 ] ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
}
}
}
}
}
}
}
if ( term_equal ( arg0 , tmp [ 3 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
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
}
}
}
}
}
}
}
}
( tmp [ 7 ] = list_tail ( tmp [ 7 ] ) ) ;
( tmp [ 5 ] = tmp [ 7 ] ) ;
}
}
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant1 , ( * ef5 ) ( ) ) ;
}
}
}
if ( check_sym ( arg1 , lf_AUX_VarEnv22_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( lf_AUX_VarEnv22_2_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_VarEnv22_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_VarEnv22_2_recursive ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 34 ] ;
FUNC_ENTRY ( lf_AUX_VarEnv22_2_recursivesym , ATmakeAppl ( lf_AUX_VarEnv22_2_recursivesym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_VarEnv22_2_recursive : ltmp [ 0 ] = arg0 ;
( ltmp [ 1 ] = arg1 ) ;
{
ATerm atmp10 = arg1 ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
{
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = tmp [ 5 ] ) ;
( tmp [ 7 ] = tmp [ 5 ] ) ;
while ( not_empty_list ( tmp [ 5 ] ) ) {
( tmp [ 8 ] = list_head ( tmp [ 5 ] ) ) ;
( tmp [ 5 ] = list_tail ( tmp [ 5 ] ) ) ;
{
if ( check_sym ( tmp [ 8 ] , ef2sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ) ;
( tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ) ;
{
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 9 ] ) ) ;
{
if ( check_sym ( tmp [ 11 ] , lf4sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ) ;
{
if ( check_sym ( tmp [ 10 ] , lf3sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ) ;
{
if ( not_empty_list ( tmp [ 12 ] ) ) {
( tmp [ 14 ] = list_head ( tmp [ 12 ] ) ) ;
if ( term_equal ( tmp [ 14 ] , make_char ( 100 ) ) ) {
( tmp [ 15 ] = list_tail ( tmp [ 12 ] ) ) ;
{
if ( not_empty_list ( tmp [ 15 ] ) ) {
( tmp [ 16 ] = list_head ( tmp [ 15 ] ) ) ;
if ( term_equal ( tmp [ 16 ] , make_char ( 101 ) ) ) {
( tmp [ 17 ] = list_tail ( tmp [ 15 ] ) ) ;
{
if ( not_empty_list ( tmp [ 17 ] ) ) {
( tmp [ 18 ] = list_head ( tmp [ 17 ] ) ) ;
if ( term_equal ( tmp [ 18 ] , make_char ( 108 ) ) ) {
( tmp [ 19 ] = list_tail ( tmp [ 17 ] ) ) ;
{
if ( not_empty_list ( tmp [ 19 ] ) ) {
( tmp [ 20 ] = list_head ( tmp [ 19 ] ) ) ;
if ( term_equal ( tmp [ 20 ] , make_char ( 97 ) ) ) {
( tmp [ 21 ] = list_tail ( tmp [ 19 ] ) ) ;
{
if ( not_empty_list ( tmp [ 21 ] ) ) {
( tmp [ 22 ] = list_head ( tmp [ 21 ] ) ) ;
if ( term_equal ( tmp [ 22 ] , make_char ( 121 ) ) ) {
( tmp [ 23 ] = list_tail ( tmp [ 21 ] ) ) ;
{
if ( not_empty_list ( tmp [ 23 ] ) ) {
( tmp [ 24 ] = list_head ( tmp [ 23 ] ) ) ;
if ( term_equal ( tmp [ 24 ] , make_char ( 105 ) ) ) {
( tmp [ 25 ] = list_tail ( tmp [ 23 ] ) ) ;
{
if ( not_empty_list ( tmp [ 25 ] ) ) {
( tmp [ 26 ] = list_head ( tmp [ 25 ] ) ) ;
if ( term_equal ( tmp [ 26 ] , make_char ( 110 ) ) ) {
( tmp [ 27 ] = list_tail ( tmp [ 25 ] ) ) ;
{
if ( is_single_element ( tmp [ 27 ] ) ) {
( tmp [ 28 ] = list_head ( tmp [ 27 ] ) ) ;
if ( term_equal ( tmp [ 28 ] , make_char ( 103 ) ) ) {
if ( not_empty_list ( tmp [ 13 ] ) ) {
if ( check_sym ( ltmp [ 0 ] , ef3sym ) ) {
( tmp [ 29 ] = arg_0 ( ltmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 29 ] , lf4sym ) ) {
( tmp [ 30 ] = arg_0 ( tmp [ 29 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
( tmp [ 31 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 31 ] , lf4sym ) ) {
( tmp [ 32 ] = arg_0 ( tmp [ 31 ] ) ) ;
if ( not_empty_list ( tmp [ 32 ] ) ) {
if ( term_equal ( list_head ( tmp [ 32 ] ) , make_char ( 95 ) ) ) {
( tmp [ 33 ] = list_tail ( tmp [ 32 ] ) ) ;
if ( term_equal ( ( * ef3 ) ( lf4 ( make_list ( tmp [ 30 ] ) ) ) , ( * ef3 ) ( lf4 ( make_list ( tmp [ 33 ] ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
}
}
}
}
}
}
}
if ( term_equal ( ltmp [ 0 ] , tmp [ 3 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
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
}
}
}
}
}
}
}
}
( tmp [ 7 ] = list_tail ( tmp [ 7 ] ) ) ;
( tmp [ 5 ] = tmp [ 7 ] ) ;
}
}
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant1 , ( * ef5 ) ( ) ) ;
}
}
{
ATerm atmp10 = arg1 ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( arg1 = make_list ( tmp [ 1 ] ) ) ;
goto lbl_lf_AUX_VarEnv22_2_recursive ;
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_VarEnv22_2_recursivesym , ltmp [ 0 ] , lf_AUX_VarEnv22_1 ( ltmp [ 1 ] ) ) ) ;
}
}
}
ATerm lf_AUX_VarEnv22_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_VarEnv22_1sym , ATmakeAppl ( lf_AUX_VarEnv22_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_VarEnv22_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

