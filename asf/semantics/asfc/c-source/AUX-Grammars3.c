#include "support.h"
static asymbol * lf_AUX_Grammars3_1sym;
static aterm * lf_AUX_Grammars3_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Grammars3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Grammars3_1sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[l(\"normg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Production\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"normg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)") , lf_AUX_Grammars3_1 , lf_AUX_Grammars3_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Production\"))") , lf2 , lf2sym);
}
void resolve_AUX_Grammars3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"lexical syntax\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"context-free syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"lexical syntax\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"context-free syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Productions\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Productions\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"normp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"normp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Grammars3_1( aterm * arg0) {
PROF( prof_lf_AUX_Grammars3_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef2sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , lf2sym)) {
{
aterm * atmp0100= arg_0( atmp010);
t_protect( atmp0000);
t_protect( atmp0100);
t_unprotect( arg0);
return ( * ef3)( ( * ef2)( lf2( make_list( atmp0000))) , ( * ef4)( ( * ef2)( lf2( make_list( atmp0100)))));
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
return make_nf1( lf_AUX_Grammars3_1sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

