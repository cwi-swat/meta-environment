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
static Symbol lf_AUX_Parse_Table3_1sym ;
static ATerm lf_AUX_Parse_Table3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Parse_Table3 ( ) {
lf_AUX_Parse_Table3_1sym = ATmakeSymbol ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"states\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"States\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Parse_Table3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"states\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"States\"),w(\"\"),no-attrs)" ) , lf_AUX_Parse_Table3_1 , lf_AUX_Parse_Table3_1sym ) ;
}
void resolve_AUX_Parse_Table3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"States\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"States\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Parse_Table3 ( ) {
}
ATerm lf_AUX_Parse_Table3_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Parse_Table3_1sym , ATmakeAppl ( lf_AUX_Parse_Table3_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
{
ATerm atmp03 = arg_3 ( arg0 ) ;
if ( check_sym ( atmp03 , ef2sym ) ) {
{
ATerm atmp030 = arg_0 ( atmp03 ) ;
{
ATerm atmp04 = arg_4 ( arg0 ) ;
FUNC_EXIT ( atmp04 ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Parse_Table3_1sym , arg0 ) ) ;
}

