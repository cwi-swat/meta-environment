/*

    PGEN - the SDF2 parse table generator.
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
/* This C code is generated by the AsfSdfCompiler version 1.0 */

#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Membership4_1sym ;
static ATerm lf_AUX_Character_Class_Membership4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Character_Class_Membership4 ( ) {
lf_AUX_Character_Class_Membership4_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Membership\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"sub\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Membership4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Membership\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"sub\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Membership4_1 , lf_AUX_Character_Class_Membership4_1sym ) ;
}
void resolve_AUX_Character_Class_Membership4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Membership\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"in\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Membership\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"in\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"<\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"<\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Character_Class_Membership4 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Character_Class_Membership4_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Character_Class_Membership4_1sym , ATmakeAppl ( lf_AUX_Character_Class_Membership4_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( ) ) ;
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef4sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef5sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , ef6sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
FUNC_EXIT ( ( * ef7 ) ( atmp00000 , arg1 ) ) ;
}
}
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , ef8sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
{
ATerm atmp00001 = arg_1 ( atmp0000 ) ;
if ( term_equal ( atmp00000 , atmp00001 ) ) {
FUNC_EXIT ( ( * ef7 ) ( atmp00000 , arg1 ) ) ;
}
if ( term_equal ( ( * ef11 ) ( atmp00000 , atmp00001 ) , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef9 ) ( ( * ef7 ) ( atmp00000 , arg1 ) , lf_AUX_Character_Class_Membership4_1 ( ( * ef1 ) ( ( * ef4 ) ( ( * ef5 ) ( ( * ef8 ) ( ( * ef10 ) ( atmp00000 ) , atmp00001 ) ) ) ) , arg1 ) ) ) ;
}
}
}
}
}
}
}
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef12sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp0001 = arg_1 ( atmp000 ) ;
FUNC_EXIT ( ( * ef9 ) ( lf_AUX_Character_Class_Membership4_1 ( ( * ef1 ) ( ( * ef4 ) ( atmp0000 ) ) , arg1 ) , lf_AUX_Character_Class_Membership4_1 ( ( * ef1 ) ( ( * ef4 ) ( atmp0001 ) ) , arg1 ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Character_Class_Membership4_1sym , arg0 , arg1 ) ) ;
}

