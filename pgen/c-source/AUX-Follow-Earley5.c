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
static Symbol lf_AUX_Follow_Earley5_1sym ;
static ATerm lf_AUX_Follow_Earley5_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Follow_Earley5 ( ) {
lf_AUX_Follow_Earley5_1sym = ATmakeSymbol ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"close\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)"
 , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Follow_Earley5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"close\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Follow_Earley5_1 , lf_AUX_Follow_Earley5_1sym ) ;
}
void resolve_AUX_Follow_Earley5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"step\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"step\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Follow_Earley5 ( ) {
}
ATerm lf_AUX_Follow_Earley5_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
FUNC_ENTRY ( lf_AUX_Follow_Earley5_1sym , ATmakeAppl ( lf_AUX_Follow_Earley5_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
{
ATerm ltmp [ 4 ] ;
lbl_lf_AUX_Follow_Earley5_1 : ltmp [ 0 ] = arg0 ;
( ltmp [ 1 ] = arg1 ) ;
( ltmp [ 2 ] = arg2 ) ;
( ltmp [ 3 ] = arg3 ) ;
if ( term_equal ( ltmp [ 2 ] , ltmp [ 3 ] ) ) {
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
( arg2 = ltmp [ 3 ] ) ;
( arg3 = ( * ef1 ) ( ltmp [ 0 ] , ( * ef2 ) ( ltmp [ 0 ] ) , ltmp [ 1 ] , ltmp [ 3 ] ) ) ;
goto lbl_lf_AUX_Follow_Earley5_1 ;
FUNC_EXIT ( make_nf4 ( lf_AUX_Follow_Earley5_1sym , ltmp [ 0 ] , ltmp [ 1 ] , ltmp [ 2 ] , ltmp [ 3 ] ) ) ;
}
}

