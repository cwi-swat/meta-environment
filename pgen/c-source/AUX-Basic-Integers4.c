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
static Symbol lf_AUX_Basic_Integers4_1sym ;
static ATerm lf_AUX_Basic_Integers4_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_Basic_Integers4 ( ) {
lf_AUX_Basic_Integers4_1sym = ATmakeSymbol ( "prod(id(\"Basic-Integers\"),w(\"\"),[l(\"abs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Basic_Integers4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Basic-Integers\"),w(\"\"),[l(\"abs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) , lf_AUX_Basic_Integers4_1 , lf_AUX_Basic_Integers4_1sym ) ;
}
void resolve_AUX_Basic_Integers4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Basic_Integers4 ( ) {
}
ATerm lf_AUX_Basic_Integers4_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Basic_Integers4_1sym , ATmakeAppl ( lf_AUX_Basic_Integers4_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
FUNC_EXIT ( atmp000 ) ;
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
FUNC_EXIT ( atmp000 ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Basic_Integers4_1sym , arg0 ) ) ;
}

