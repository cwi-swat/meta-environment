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
static Symbol lf_AUX_Renaming_Sdf_Renaming2_1sym ;
static ATerm lf_AUX_Renaming_Sdf_Renaming2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
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
void register_AUX_Renaming_Sdf_Renaming2 ( ) {
lf_AUX_Renaming_Sdf_Renaming2_1sym = ATmakeSymbol ( "prod(id(\"Renaming-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Renamings\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Renaming_Sdf_Renaming2_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Renaming\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Renaming-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Renamings\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)" ) , lf_AUX_Renaming_Sdf_Renaming2_1 , lf_AUX_Renaming_Sdf_Renaming2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Renaming\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Renaming_Sdf_Renaming2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"Renaming\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"Renaming\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renaming\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renaming\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[sort(\"Renamings\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[sort(\"Renamings\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[sort(\"Production\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renaming\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[sort(\"Production\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renaming\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Renaming_Sdf_Renaming2 ( ) {
}
ATerm lf_AUX_Renaming_Sdf_Renaming2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_Renaming_Sdf_Renaming2_1sym , ATmakeAppl ( lf_AUX_Renaming_Sdf_Renaming2_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
FUNC_EXIT ( ( * ef3 ) ( ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( tmp [ 2 ] , ( * ef4 ) ( tmp [ 3 ] , arg1 ) ) ) ) ) , lf_AUX_Renaming_Sdf_Renaming2_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , arg1 ) ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
FUNC_EXIT ( ( * ef3 ) ( ( * ef1 ) ( lf2 ( make_list ( ( * ef5 ) ( tmp [ 2 ] , ( * ef6 ) ( tmp [ 3 ] , arg1 ) ) ) ) ) , lf_AUX_Renaming_Sdf_Renaming2_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , arg1 ) ) ) ;
}
}
else {
FUNC_EXIT ( arg1 ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Renaming_Sdf_Renaming2_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

