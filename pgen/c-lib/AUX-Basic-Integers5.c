/*

    PGEN - the SDF2 parse table generator.
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

ATermList int2aterm(int value);
int aterm2int(ATermList arg);

static Symbol lf_AUX_Basic_Integers5_1sym ;
static ATerm lf_AUX_Basic_Integers5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Basic_Integers5 ( ) {
lf_AUX_Basic_Integers5_1sym = ATmakeSymbol ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Basic_Integers5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Basic_Integers5_1 , lf_AUX_Basic_Integers5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Basic_Integers5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
static ATerm constant7 = NULL ;
static ATerm constant8 = NULL ;
static ATerm constant9 = NULL ;
static ATerm constant10 = NULL ;
static ATerm constant11 = NULL ;
static ATerm constant12 = NULL ;
static ATerm constant13 = NULL ;
static ATerm constant14 = NULL ;
static ATerm constant15 = NULL ;
static ATerm constant16 = NULL ;
static ATerm constant17 = NULL ;
void init_AUX_Basic_Integers5 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
ATprotect ( & constant7 ) ;
ATprotect ( & constant8 ) ;
ATprotect ( & constant9 ) ;
ATprotect ( & constant10 ) ;
ATprotect ( & constant11 ) ;
ATprotect ( & constant12 ) ;
ATprotect ( & constant13 ) ;
ATprotect ( & constant14 ) ;
ATprotect ( & constant15 ) ;
ATprotect ( & constant16 ) ;
ATprotect ( & constant17 ) ;
}
ATerm lf_AUX_Basic_Integers5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 16 ] ;
FUNC_ENTRY ( lf_AUX_Basic_Integers5_1sym , ATmakeAppl ( lf_AUX_Basic_Integers5_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef5sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , ef5sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( atmp1000 , lf2sym ) ) {
{
ATerm atmp10000 = arg_0 ( atmp1000 ) ;
{
  ATerm tmp;
  int i0 = aterm2int((ATermList) atmp00000);
  int i1 = aterm2int((ATermList) atmp10000);
  int ir = i0 + i1;
  tmp = (ATerm) int2aterm(ir);
/*Tprintf(stderr,"Intvalue = %d\n", ir);
Tprintf(stderr,"Tmp = %t\n", tmp);*/
  return ( * ef1)( ( * ef2)( ( * ef5)( lf2( tmp))));
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
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef4 ) ( arg0 , ( * ef1 ) ( ( * ef2 ) ( atmp100 ) ) ) ) ;
}
}
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{ 
FUNC_EXIT ( ( * ef4 ) ( arg1 , ( * ef1 ) ( ( * ef2 ) ( atmp000 ) ) ) ) ;
}
}
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
tmp [ 0 ] = lf_AUX_Basic_Integers5_1 ( ( * ef1 ) ( ( * ef2 ) ( atmp000 ) ) , ( * ef1 ) ( ( * ef2 ) ( atmp100 ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef3 ) ( tmp [ 2 ] ) ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Basic_Integers5_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

