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
static Symbol lf_AUX_MuASF_Term2C13_1sym ;
static ATerm lf_AUX_MuASF_Term2C13_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_MuASF_Term2C13 ( ) {
lf_AUX_MuASF_Term2C13_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[ql(\"is-special-name\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Term2C13_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[ql(\"is-special-name\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Term2C13_1 , lf_AUX_MuASF_Term2C13_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_MuASF_Term2C13 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_MuASF_Term2C13 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_MuASF_Term2C13_1 ( ATerm arg0 ) {
{
ATerm tmp [ 14 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Term2C13_1sym , ATmakeAppl ( lf_AUX_MuASF_Term2C13_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 109 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = list_head ( tmp [ 1 ] ) ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 97 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 1 ] ) ) ;
{
if ( not_empty_list ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = list_head ( tmp [ 3 ] ) ) ;
if ( term_equal ( tmp [ 4 ] , make_char ( 107 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 3 ] ) ) ;
{
if ( not_empty_list ( tmp [ 5 ] ) ) {
( tmp [ 6 ] = list_head ( tmp [ 5 ] ) ) ;
if ( term_equal ( tmp [ 6 ] , make_char ( 101 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ) ;
{
if ( not_empty_list ( tmp [ 7 ] ) ) {
( tmp [ 8 ] = list_head ( tmp [ 7 ] ) ) ;
if ( term_equal ( tmp [ 8 ] , make_char ( 95 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 7 ] ) ) ;
{
if ( not_empty_list ( tmp [ 9 ] ) ) {
( tmp [ 10 ] = list_head ( tmp [ 9 ] ) ) ;
if ( term_equal ( tmp [ 10 ] , make_char ( 99 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 104 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 97 ) ) ) {
( tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ) ;
if ( is_single_element ( tmp [ 13 ] ) ) {
if ( term_equal ( list_head ( tmp [ 13 ] ) , make_char ( 114 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
}
}
}
}
}
}
}
if ( term_equal ( tmp [ 10 ] , make_char ( 110 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 102 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
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
if ( term_equal ( tmp [ 0 ] , make_char ( 113 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 117 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 111 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 116 ) ) ) {
( tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 101 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
}
}
}
}
}
}
}
}
}
if ( term_equal ( tmp [ 0 ] , make_char ( 110 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 117 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 108 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 108 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
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
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Term2C13_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

