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
static Symbol lf_AUX_Optimize_MuASF19_1sym ;
static ATerm lf_AUX_Optimize_MuASF19_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Optimize_MuASF19 ( ) {
lf_AUX_Optimize_MuASF19_1sym = ATmakeSymbol ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"get-list-embedding\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Optimize_MuASF19_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"get-list-embedding\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),no-attrs)" ) , lf_AUX_Optimize_MuASF19_1 , lf_AUX_Optimize_MuASF19_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Optimize_MuASF19 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"unavailable\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"unavailable\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"is-recursive\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"is-recursive\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"find-list-arg\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"find-list-arg\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"check-emb-lhs-rules\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Optimize-MuASF\"),w(\"\"),[ql(\"check-emb-lhs-rules\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"RuleList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunIdHasEmbeddingAt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Optimize_MuASF19 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Optimize_MuASF19_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_Optimize_MuASF19_1sym , ATmakeAppl ( lf_AUX_Optimize_MuASF19_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
if ( term_equal ( ( * ef3 ) ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ) {
( tmp [ 0 ] = ( * ef5 ) ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , arg1 ) ) ;
if ( term_equal ( ( * ef6 ) ( ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) , tmp [ 0 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ) {
FUNC_EXIT ( tmp [ 0 ] ) ;
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef2 ) ( ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Optimize_MuASF19_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

