#include "support.h"
static asymbol * lf_AUX_MuASF_Conds2C4_3sym;
static aterm * lf_AUX_MuASF_Conds2C4_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5 , aterm * arg6);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * lf8sym;
static aterm * lf8( aterm * arg1);
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * lf_AUX_MuASF_Conds2C4_1sym;
static aterm * lf_AUX_MuASF_Conds2C4_1( aterm * arg1);
static asymbol * lf_AUX_MuASF_Conds2C4_2sym;
static aterm * lf_AUX_MuASF_Conds2C4_2( aterm * arg1);
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef22sym;
static funcptr ef22;
void register_AUX_MuASF_Conds2C4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Conds2C4_3sym= TmkSymbol( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"assign-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , SYM_STRING);
lf8sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C4_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C4_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Conds2C4_1 , lf_AUX_MuASF_Conds2C4_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Conds2C4_2 , lf_AUX_MuASF_Conds2C4_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"assign-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Conds2C4_3 , lf_AUX_MuASF_Conds2C4_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf7 , lf7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf8 , lf8sym);
}
void resolve_AUX_MuASF_Conds2C4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-first-cond-and-add-env\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-first-cond-and-add-env\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"cterms2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"cterms2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listconds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listconds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Conds2C4_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5) {
{
aterm * tmp[39];
PROF( prof_lf_AUX_MuASF_Conds2C4_3);
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C4_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Conds2C4_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg3 , lf_AUX_MuASF_Conds2C4_2sym)) {
{
aterm * atmp30= arg_0( arg3);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
{
tmp[ 1]= m_list_tail( atmp00);
{
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
{
tmp[ 10]= m_list_tail( tmp[ 8]);
{
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
{
if( check_sym( tmp[ 12] , ef12sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= arg_1( tmp[ 12]);
{
if( check_sym( tmp[ 14] , lf7sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
{
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 13]);
tmp[ 16]= ( * ef15)( tmp[ 13]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , ( * ef16)( ))) {
t_protect( tmp[ 13]);
t_protect( arg5);
t_protect( atmp30);
tmp[ 17]= ( * ef17)( tmp[ 13] , arg5 , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)));
t_protect( tmp[ 15]);
t_protect( arg5);
t_protect( arg2);
t_protect( arg4);
tmp[ 18]= ( * ef18)( lf7( make_list( tmp[ 15])) , arg5 , arg2 , arg4 , ( * ef19)( lf8( make_list( make_char( 48)))));
if( check_sym( tmp[ 18] , ef20sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= arg_1( tmp[ 18]);
tmp[ 21]= arg_2( tmp[ 18]);
tmp[ 22]= arg_3( tmp[ 18]);
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_protect( tmp[ 13]);
t_protect( tmp[ 15]);
t_protect( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
tmp[ 23]= ( * ef6)( ( * ef2)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef3)( tmp[ 11] , ( * ef12)( tmp[ 13] , lf7( make_list( tmp[ 15]))))) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6]) , lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 23] , ef7sym)) {
tmp[ 24]= arg_0( tmp[ 23]);
tmp[ 25]= arg_1( tmp[ 23]);
if( check_sym( tmp[ 24] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 26]= arg_0( tmp[ 24]);
if( check_sym( tmp[ 25] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 27]= arg_0( tmp[ 25]);
t_protect( tmp[ 26]);
t_protect( tmp[ 20]);
tmp[ 28]= ( * ef8)( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 26])) , tmp[ 20]);
if( check_sym( tmp[ 28] , ef11sym)) {
tmp[ 29]= arg_0( tmp[ 28]);
if( check_sym( tmp[ 29] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 30]= arg_0( tmp[ 29]);
t_protect( tmp[ 30]);
t_protect( tmp[ 22]);
t_protect( atmp30);
t_protect( tmp[ 21]);
tmp[ 31]= ( * ef1)( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 30])) , tmp[ 22] , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)) , tmp[ 21]);
if( check_sym( tmp[ 31] , ef13sym)) {
tmp[ 32]= arg_0( tmp[ 31]);
tmp[ 33]= arg_1( tmp[ 31]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
t_protect( tmp[ 32]);
tmp[ 34]= ( * ef21)( tmp[ 17] , ( * ef14)( tmp[ 19] , tmp[ 32]));
t_protect( tmp[ 27]);
t_protect( atmp10);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
t_protect( arg5);
tmp[ 35]= lf_AUX_MuASF_Conds2C4_3( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 27])) , lf_AUX_MuASF_Conds2C4_1( make_list( atmp10)) , arg2 , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)) , arg4 , arg5);
if( check_sym( tmp[ 35] , ef13sym)) {
tmp[ 36]= arg_0( tmp[ 35]);
tmp[ 37]= arg_1( tmp[ 35]);
t_protect( tmp[ 33]);
t_protect( tmp[ 37]);
tmp[ 38]= ( * ef22)( tmp[ 33] , tmp[ 37]);
t_protect( tmp[ 36]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 35]);
return ( * ef13)( ( * ef14)( tmp[ 34] , tmp[ 36]) , tmp[ 38]);
}
t_unprotect( tmp[ 35]);
t_unprotect( tmp[ 34]);
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 28]);
}
}
}
t_unprotect( tmp[ 23]);
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , ( * ef5)( ))) {
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_protect( tmp[ 13]);
t_protect( tmp[ 15]);
t_protect( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
tmp[ 17]= ( * ef6)( ( * ef2)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef3)( tmp[ 11] , ( * ef12)( tmp[ 13] , lf7( make_list( tmp[ 15]))))) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6]) , lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 17] , ef7sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
tmp[ 19]= arg_1( tmp[ 17]);
if( check_sym( tmp[ 18] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 20]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 21]= arg_0( tmp[ 19]);
t_protect( tmp[ 20]);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
t_protect( arg5);
tmp[ 22]= ( * ef23)( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 20])) , arg2 , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)) , arg4 , arg5);
if( check_sym( tmp[ 22] , ef13sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
tmp[ 24]= arg_1( tmp[ 22]);
t_protect( tmp[ 21]);
t_protect( atmp10);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
t_protect( arg5);
tmp[ 25]= lf_AUX_MuASF_Conds2C4_3( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 21])) , lf_AUX_MuASF_Conds2C4_1( make_list( atmp10)) , arg2 , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)) , arg4 , arg5);
if( check_sym( tmp[ 25] , ef13sym)) {
tmp[ 26]= arg_0( tmp[ 25]);
tmp[ 27]= arg_1( tmp[ 25]);
t_protect( tmp[ 24]);
t_protect( tmp[ 27]);
tmp[ 28]= ( * ef22)( tmp[ 24] , tmp[ 27]);
t_protect( tmp[ 23]);
t_protect( tmp[ 26]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 25]);
return ( * ef13)( ( * ef14)( tmp[ 23] , tmp[ 26]) , tmp[ 28]);
}
t_unprotect( tmp[ 25]);
}
t_unprotect( tmp[ 22]);
}
}
}
t_unprotect( tmp[ 17]);
}
t_unprotect( tmp[ 16]);
}
}
}
}
}
t_protect( tmp[ 12]);
if( term_equal( ( * ef4)( tmp[ 12]) , ( * ef5)( ))) {
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
tmp[ 13]= ( * ef6)( ( * ef2)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef3)( tmp[ 11] , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6]) , lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 13] , ef7sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
tmp[ 15]= arg_1( tmp[ 13]);
if( check_sym( tmp[ 14] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 16]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 17]= arg_0( tmp[ 15]);
t_protect( tmp[ 16]);
t_protect( tmp[ 12]);
t_protect( arg5);
tmp[ 18]= ( * ef8)( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 16])) , ( * ef9)( lf6( make_list( ( * ef10)( tmp[ 12] , arg5)))));
if( check_sym( tmp[ 18] , ef11sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf_AUX_MuASF_Conds2C4_1sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
t_protect( tmp[ 17]);
t_protect( atmp10);
t_protect( tmp[ 20]);
t_protect( atmp30);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 18]);
return lf_AUX_MuASF_Conds2C4_3( lf_AUX_MuASF_Conds2C4_1( make_list( tmp[ 17])) , lf_AUX_MuASF_Conds2C4_1( cons( make_list( atmp10) , make_list( tmp[ 20]))) , arg2 , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)) , arg4 , arg5);
}
}
t_unprotect( tmp[ 18]);
}
}
}
t_unprotect( tmp[ 13]);
}
}
}
}
t_unprotect( tmp[ 10]);
}
t_unprotect( tmp[ 9]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_protect( atmp10);
t_protect( atmp30);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( arg5);
return ( * ef1)( lf_AUX_MuASF_Conds2C4_1( make_list( atmp10)) , arg2 , lf_AUX_MuASF_Conds2C4_2( make_list( atmp30)) , arg4);
}
}
}
}
}
}
}
return make_nf6( lf_AUX_MuASF_Conds2C4_3sym , arg0 , arg1 , arg2 , arg3 , arg4 , arg5);
}
}
aterm * lf_AUX_MuASF_Conds2C4_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C4_2);
return make_nf1( lf_AUX_MuASF_Conds2C4_2sym , arg0);
}
aterm * lf_AUX_MuASF_Conds2C4_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C4_1);
return make_nf1( lf_AUX_MuASF_Conds2C4_1sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf8( aterm * arg0) {
PROF( prof_lf8);
return make_nf1( lf8sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}

