#include "support.h"
static asymbol * lf_AUX_Grammars4_1sym;
static aterm * lf_AUX_Grammars4_1( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Grammars4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Grammars4_1sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[l(\"normp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Symbol\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Production\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"normp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)") , lf_AUX_Grammars4_1 , lf_AUX_Grammars4_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Production\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Symbol\"))") , lf3 , lf3sym);
}
void resolve_AUX_Grammars4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Productions\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Productions\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Grammars4_1( aterm * arg0) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Grammars4_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( atmp000);
if( ! not_empty_list( atmp000)) {
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( null( ))));
}
else {
tmp[ 0]= m_list_head( atmp000);
tmp[ 1]= m_list_tail( atmp000);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 2] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef4)( ( * ef1)( lf2( make_list( ( * ef2)( ( * ef5)( ( * ef3)( lf3( make_list( tmp[ 6])))) , tmp[ 3] , tmp[ 4])))) , lf_AUX_Grammars4_1( ( * ef1)( lf2( make_list( tmp[ 1])))));
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf1( lf_AUX_Grammars4_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

