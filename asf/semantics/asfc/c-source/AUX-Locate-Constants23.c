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
static Symbol lf_AUX_Locate_Constants23_1sym ;
static ATerm lf_AUX_Locate_Constants23_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants23 ( ) {
lf_AUX_Locate_Constants23_1sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"compose-list-of-chars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants23_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"compose-list-of-chars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants23_1 , lf_AUX_Locate_Constants23_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Locate_Constants23 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Locate_Constants23 ( ) {
}
ATerm lf_AUX_Locate_Constants23_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 27 ] ;
FUNC_ENTRY ( lf_AUX_Locate_Constants23_1sym , ATmakeAppl ( lf_AUX_Locate_Constants23_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , ef3sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( atmp1000 , ef4sym ) ) {
{
ATerm atmp10000 = arg_0 ( atmp1000 ) ;
if ( check_sym ( atmp10000 , ef5sym ) ) {
{
ATerm atmp100000 = arg_0 ( atmp10000 ) ;
if ( check_sym ( atmp100000 , lf2sym ) ) {
{
ATerm atmp1000000 = arg_0 ( atmp100000 ) ;
{
ATerm atmp1001 = arg_1 ( atmp100 ) ;
if ( check_sym ( atmp1001 , ef6sym ) ) {
{
ATerm atmp10010 = arg_0 ( atmp1001 ) ;
if ( check_sym ( atmp10010 , lf3sym ) ) {
{
ATerm atmp100100 = arg_0 ( atmp10010 ) ;
if ( not_empty_list ( atmp1000000 ) ) {
if ( term_equal ( list_head ( atmp1000000 ) , make_char ( 109 ) ) ) {
( tmp [ 0 ] = list_tail ( atmp1000000 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 97 ) ) ) {
( tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 107 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 101 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 95 ) ) ) {
( tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 108 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 105 ) ) ) {
( tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 115 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 116 ) ) ) {
if ( is_single_element ( atmp100100 ) ) {
( tmp [ 8 ] = list_head ( atmp100100 ) ) ;
if ( check_sym ( tmp [ 8 ] , ef1sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , ef2sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 10 ] , ef3sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ) ;
( tmp [ 12 ] = arg_1 ( tmp [ 10 ] ) ) ;
if ( check_sym ( tmp [ 11 ] , ef4sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 11 ] ) ) ;
if ( check_sym ( tmp [ 13 ] , ef5sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ) ;
if ( check_sym ( tmp [ 14 ] , lf2sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ) ;
if ( check_sym ( tmp [ 12 ] , ef6sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 12 ] ) ) ;
if ( check_sym ( tmp [ 16 ] , lf3sym ) ) {
( tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 109 ) ) ) {
( tmp [ 18 ] = list_tail ( tmp [ 15 ] ) ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 97 ) ) ) {
( tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 107 ) ) ) {
( tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 101 ) ) ) {
( tmp [ 21 ] = list_tail ( tmp [ 20 ] ) ) ;
if ( not_empty_list ( tmp [ 21 ] ) ) {
if ( term_equal ( list_head ( tmp [ 21 ] ) , make_char ( 95 ) ) ) {
( tmp [ 22 ] = list_tail ( tmp [ 21 ] ) ) ;
if ( not_empty_list ( tmp [ 22 ] ) ) {
if ( term_equal ( list_head ( tmp [ 22 ] ) , make_char ( 99 ) ) ) {
( tmp [ 23 ] = list_tail ( tmp [ 22 ] ) ) ;
if ( not_empty_list ( tmp [ 23 ] ) ) {
if ( term_equal ( list_head ( tmp [ 23 ] ) , make_char ( 104 ) ) ) {
( tmp [ 24 ] = list_tail ( tmp [ 23 ] ) ) ;
if ( not_empty_list ( tmp [ 24 ] ) ) {
if ( term_equal ( list_head ( tmp [ 24 ] ) , make_char ( 97 ) ) ) {
( tmp [ 25 ] = list_tail ( tmp [ 24 ] ) ) ;
if ( is_single_element ( tmp [ 25 ] ) ) {
if ( term_equal ( list_head ( tmp [ 25 ] ) , make_char ( 114 ) ) ) {
if ( is_single_element ( tmp [ 17 ] ) ) {
( tmp [ 26 ] = list_head ( tmp [ 17 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef7 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 109 ] , char_table [ 97 ] , char_table [ 107 ] , char_table [ 101 ] , char_table [ 76 ] , char_table [ 105 ] , char_table [ 115 ] , char_table [ 116 ] ) ) ) ) , ( * ef6 ) ( lf3 ( cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef8 ) ( ( * ef9 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ) ) ) , cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef10 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 99 ] , char_table [ 104 ] , char_table [ 97 ] , char_table [ 114 ] , char_table [ 95 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) , arg0 ) ) ) ) , make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef10 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 99 ] , char_table [ 104 ] , char_table [ 97 ] , char_table [ 114 ] , char_table [ 95 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) , tmp [ 26 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
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
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef7sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , ef5sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( atmp1000 , lf2sym ) ) {
{
ATerm atmp10000 = arg_0 ( atmp1000 ) ;
{
ATerm atmp101 = arg_1 ( atmp10 ) ;
if ( check_sym ( atmp101 , ef3sym ) ) {
{
ATerm atmp1010 = arg_0 ( atmp101 ) ;
if ( check_sym ( atmp1010 , ef4sym ) ) {
{
ATerm atmp10100 = arg_0 ( atmp1010 ) ;
if ( check_sym ( atmp10100 , ef5sym ) ) {
{
ATerm atmp101000 = arg_0 ( atmp10100 ) ;
if ( check_sym ( atmp101000 , lf2sym ) ) {
{
ATerm atmp1010000 = arg_0 ( atmp101000 ) ;
{
ATerm atmp1011 = arg_1 ( atmp101 ) ;
if ( check_sym ( atmp1011 , ef6sym ) ) {
{
ATerm atmp10110 = arg_0 ( atmp1011 ) ;
if ( check_sym ( atmp10110 , lf3sym ) ) {
{
ATerm atmp101100 = arg_0 ( atmp10110 ) ;
if ( not_empty_list ( atmp10000 ) ) {
if ( term_equal ( list_head ( atmp10000 ) , make_char ( 65 ) ) ) {
( tmp [ 0 ] = list_tail ( atmp10000 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 84 ) ) ) {
( tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 101 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 114 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 109 ) ) ) {
if ( not_empty_list ( atmp1010000 ) ) {
if ( term_equal ( list_head ( atmp1010000 ) , make_char ( 65 ) ) ) {
( tmp [ 4 ] = list_tail ( atmp1010000 ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 84 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 109 ) ) ) {
( tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 97 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 107 ) ) ) {
( tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 101 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 76 ) ) ) {
( tmp [ 10 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
if ( term_equal ( list_head ( tmp [ 10 ] ) , make_char ( 105 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 10 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 115 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
if ( is_single_element ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 116 ) ) ) {
if ( not_empty_list ( atmp101100 ) ) {
( tmp [ 13 ] = list_head ( atmp101100 ) ) ;
( tmp [ 14 ] = list_tail ( atmp101100 ) ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
if ( check_sym ( tmp [ 13 ] , ef1sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 13 ] ) ) ;
if ( check_sym ( tmp [ 15 ] , ef2sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 16 ] , ef8sym ) ) {
( tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ) ;
if ( check_sym ( tmp [ 17 ] , ef9sym ) ) {
( tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ) ;
if ( check_sym ( tmp [ 18 ] , lf2sym ) ) {
( tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ) ;
( tmp [ 20 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef13 ) ( lf2 ( make_list ( tmp [ 19 ] ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 20 ] , ef12sym ) ) {
( tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ) ;
if ( check_sym ( tmp [ 21 ] , ef13sym ) ) {
( tmp [ 22 ] = arg_0 ( tmp [ 21 ] ) ) ;
if ( check_sym ( tmp [ 22 ] , lf2sym ) ) {
( tmp [ 23 ] = arg_0 ( tmp [ 22 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef7 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 109 ] , char_table [ 97 ] , char_table [ 107 ] , char_table [ 101 ] , char_table [ 76 ] , char_table [ 105 ] , char_table [ 115 ] , char_table [ 116 ] ) ) ) ) , ( * ef6 ) ( lf3 ( cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef8 ) ( ( * ef9 ) ( lf2 ( make_list ( tmp [ 23 ] ) ) ) ) ) ) ) , cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef10 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 99 ] , char_table [ 104 ] , char_table [ 97 ] , char_table [ 114 ] , char_table [ 95 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) , arg0 ) ) ) ) , make_list ( tmp [ 14 ] ) ) ) ) ) ) ) ) ) ;
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
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 99 ] , char_table [ 111 ] , char_table [ 110 ] , char_table [ 115 ] ) ) ) ) , ( * ef6 ) ( lf3 ( cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 14 , char_table [ 109 ] , char_table [ 97 ] , char_table [ 107 ] , char_table [ 101 ] , char_table [ 95 ] , char_table [ 108 ] , char_table [ 105 ] , char_table [ 115 ] , char_table [ 116 ] , char_table [ 95 ] , char_table [ 99 ] , char_table [ 104 ] , char_table [ 97 ] , char_table [ 114 ] ) ) ) ) , ( * ef6 ) ( lf3 ( make_list ( arg0 ) ) ) ) ) ) ) , make_list ( arg1 ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Locate_Constants23_1sym , arg0 , arg1 ) ) ;
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

