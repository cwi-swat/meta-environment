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
static Symbol lf_AUX_MuASF_Signature_Ops3_1_recursivesym ;
static ATerm lf_AUX_MuASF_Signature_Ops3_1_recursive ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_MuASF_Signature_Ops3_1sym ;
static ATerm lf_AUX_MuASF_Signature_Ops3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_MuASF_Signature_Ops3 ( ) {
lf_AUX_MuASF_Signature_Ops3_1_recursivesym = ATmakeSymbol ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[ql(\"remove-funcdef\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Signature_Ops3_1_recursivesym ) ;
lf_AUX_MuASF_Signature_Ops3_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[ql(\"remove-funcdef\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Signature_Ops3_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[ql(\"remove-funcdef\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Signature_Ops3_1 , lf_AUX_MuASF_Signature_Ops3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[ql(\"remove-funcdef\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Signature_Ops3_1_recursive , lf_AUX_MuASF_Signature_Ops3_1_recursivesym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"SigArg\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_MuASF_Signature_Ops3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_MuASF_Signature_Ops3 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_MuASF_Signature_Ops3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 9 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Signature_Ops3_1sym , ATmakeAppl ( lf_AUX_MuASF_Signature_Ops3_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
( tmp [ 0 ] = list_head ( atmp100 ) ) ;
( tmp [ 1 ] = list_tail ( atmp100 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
if ( ! term_equal ( arg0 , tmp [ 2 ] ) ) {
( tmp [ 3 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef5 ) ( tmp [ 2 ] ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
}
else {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
}
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ) ;
{
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
else {
( tmp [ 6 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef2 ) ( tmp [ 2 ] , lf3 ( make_list ( tmp [ 5 ] ) ) , tmp [ 4 ] ) ) , make_list ( tmp [ 8 ] ) ) ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
{
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
else {
( tmp [ 5 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef3 ) ( tmp [ 2 ] , lf3 ( make_list ( tmp [ 4 ] ) ) ) ) , make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
else {
( tmp [ 4 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef4 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( tmp [ 6 ] ) ) ) ) ) ;
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , make_nf1 ( ef1sym , lf2 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Signature_Ops3_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_MuASF_Signature_Ops3_1_recursive ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 9 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Signature_Ops3_1_recursivesym , ATmakeAppl ( lf_AUX_MuASF_Signature_Ops3_1_recursivesym , arg0 , arg1 ) ) ;
{
ATerm atmp10 = arg1 ;
{
ATerm atmp100 = atmp10 ;
if ( not_empty_list ( atmp100 ) ) {
( tmp [ 0 ] = list_head ( atmp100 ) ) ;
( tmp [ 1 ] = list_tail ( atmp100 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
if ( ! term_equal ( arg0 , tmp [ 2 ] ) ) {
( tmp [ 3 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef5 ) ( tmp [ 2 ] ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
}
else {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
}
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ) ;
{
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
else {
( tmp [ 6 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef2 ) ( tmp [ 2 ] , lf3 ( make_list ( tmp [ 5 ] ) ) , tmp [ 4 ] ) ) , make_list ( tmp [ 8 ] ) ) ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
{
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
else {
( tmp [ 5 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef3 ) ( tmp [ 2 ] , lf3 ( make_list ( tmp [ 4 ] ) ) ) ) , make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
else {
( tmp [ 4 ] = lf_AUX_MuASF_Signature_Ops3_1_recursive ( arg0 , make_list ( tmp [ 1 ] ) ) ) ;
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
FUNC_EXIT ( make_nf1 ( ef1sym , lf2 ( cons ( make_list ( ( * ef4 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( tmp [ 6 ] ) ) ) ) ) ;
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , make_nf1 ( ef1sym , lf2 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Signature_Ops3_1_recursivesym , arg0 , ( * ef1 ) ( lf2 ( arg1 ) ) ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

