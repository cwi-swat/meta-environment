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
/* This C code is generated by the AsfSdfCompiler version 1.3 */

#include  "asc-support.h"
static Symbol lf_AUX_Optimize_MuASF17_1_recursivesym ;
static ATerm lf_AUX_Optimize_MuASF17_1_recursive ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Optimize_MuASF17_1sym ;
static ATerm lf_AUX_Optimize_MuASF17_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_Optimize_MuASF17 ( ) {
lf_AUX_Optimize_MuASF17_1_recursivesym = ATmakeSymbol ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"remove-emb-args\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"EmbeddingAt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Optimize_MuASF17_1_recursivesym ) ;
lf_AUX_Optimize_MuASF17_1sym = ATmakeSymbol ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"remove-emb-args\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"EmbeddingAt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Optimize_MuASF17_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"remove-emb-args\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"EmbeddingAt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Optimize_MuASF17_1 , lf_AUX_Optimize_MuASF17_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"remove-emb-args\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"EmbeddingAt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Optimize_MuASF17_1_recursive , lf_AUX_Optimize_MuASF17_1_recursivesym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Optimize_MuASF17 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[sort(\"Embedding\"),w(\"\"),ql(\"at\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EmbeddingAt\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[sort(\"Embedding\"),w(\"\"),ql(\"at\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EmbeddingAt\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"remove-emb-arg\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Embedding\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"remove-emb-arg\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Embedding\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Optimize_MuASF17 ( ) {
}
ATerm lf_AUX_Optimize_MuASF17_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 5 ] ;
FUNC_ENTRY ( lf_AUX_Optimize_MuASF17_1sym , ATmakeAppl ( lf_AUX_Optimize_MuASF17_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef3sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( check_sym ( atmp110 , ef4sym ) ) {
{
ATerm atmp1100 = arg_0 ( atmp110 ) ;
if ( check_sym ( atmp1100 , ef5sym ) ) {
{
ATerm atmp11000 = arg_0 ( atmp1100 ) ;
if ( check_sym ( atmp11000 , lf3sym ) ) {
{
ATerm atmp110000 = arg_0 ( atmp11000 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( is_single_element ( atmp110000 ) ) {
if ( term_equal ( list_head ( atmp110000 ) , make_char ( 48 ) ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef6 ) ( tmp [ 0 ] , atmp10 ) ) , make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
}
}
}
if ( is_single_element ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
if ( is_single_element ( atmp110000 ) ) {
if ( term_equal ( list_head ( atmp110000 ) , make_char ( 48 ) ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( ( * ef6 ) ( tmp [ 0 ] , atmp10 ) ) ) ) ) ;
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
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( ! term_equal ( atmp110 , ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) {
( tmp [ 2 ] = lf_AUX_Optimize_MuASF17_1_recursive ( make_list ( tmp [ 1 ] ) , ( * ef2 ) ( atmp10 , ( * ef7 ) ( ( * ef3 ) ( atmp110 ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ;
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 4 ] ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Optimize_MuASF17_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Optimize_MuASF17_1_recursive ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 5 ] ;
FUNC_ENTRY ( lf_AUX_Optimize_MuASF17_1_recursivesym , ATmakeAppl ( lf_AUX_Optimize_MuASF17_1_recursivesym , arg0 , arg1 ) ) ;
{
ATerm atmp00 = arg0 ;
{
ATerm atmp000 = atmp00 ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef3sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( check_sym ( atmp110 , ef4sym ) ) {
{
ATerm atmp1100 = arg_0 ( atmp110 ) ;
if ( check_sym ( atmp1100 , ef5sym ) ) {
{
ATerm atmp11000 = arg_0 ( atmp1100 ) ;
if ( check_sym ( atmp11000 , lf3sym ) ) {
{
ATerm atmp110000 = arg_0 ( atmp11000 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( is_single_element ( atmp110000 ) ) {
if ( term_equal ( list_head ( atmp110000 ) , make_char ( 48 ) ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef6 ) ( tmp [ 0 ] , atmp10 ) ) , make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
}
}
}
if ( is_single_element ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
if ( is_single_element ( atmp110000 ) ) {
if ( term_equal ( list_head ( atmp110000 ) , make_char ( 48 ) ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( ( * ef6 ) ( tmp [ 0 ] , atmp10 ) ) ) ) ) ;
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
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( ! term_equal ( atmp110 , ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) {
( tmp [ 2 ] = lf_AUX_Optimize_MuASF17_1_recursive ( make_list ( tmp [ 1 ] ) , ( * ef2 ) ( atmp10 , ( * ef7 ) ( ( * ef3 ) ( atmp110 ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ;
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 4 ] ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Optimize_MuASF17_1_recursivesym , ( * ef1 ) ( lf2 ( arg0 ) ) , arg1 ) ) ;
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

