#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C16_3sym;
static aterm * lf_AUX_MuASF_Rules2C16_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5 , aterm * arg6);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef33sym;
static funcptr ef33;
static asymbol * ef34sym;
static funcptr ef34;
static asymbol * ef35sym;
static funcptr ef35;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * ef30sym;
static funcptr ef30;
static asymbol * ef31sym;
static funcptr ef31;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef32sym;
static funcptr ef32;
static asymbol * ef38sym;
static funcptr ef38;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * lf8sym;
static aterm * lf8( aterm * arg1);
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * lf_AUX_MuASF_Rules2C16_1sym;
static aterm * lf_AUX_MuASF_Rules2C16_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef40sym;
static funcptr ef40;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef41sym;
static funcptr ef41;
static asymbol * ef42sym;
static funcptr ef42;
static asymbol * ef44sym;
static funcptr ef44;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * lf9sym;
static aterm * lf9( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C16_2sym;
static aterm * lf_AUX_MuASF_Rules2C16_2( aterm * arg1);
static asymbol * ef45sym;
static funcptr ef45;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef39sym;
static funcptr ef39;
static asymbol * ef36sym;
static funcptr ef36;
static asymbol * ef37sym;
static funcptr ef37;
static asymbol * ef43sym;
static funcptr ef43;
static asymbol * ef46sym;
static funcptr ef46;
static asymbol * ef47sym;
static funcptr ef47;
static asymbol * ef48sym;
static funcptr ef48;
void register_AUX_MuASF_Rules2C16( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C16_3sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf8sym= TmkSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C16_1sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf9sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C16_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C16_1 , lf_AUX_MuASF_Rules2C16_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C16_2 , lf_AUX_MuASF_Rules2C16_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C16_3 , lf_AUX_MuASF_Rules2C16_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf7 , lf7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf8 , lf8sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf9 , lf9sym);
}
void resolve_AUX_MuASF_Rules2C16( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"C-env\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"C-env\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"C-env\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"C-env\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-star-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-star-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-array-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-array-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef34= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-protect-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-protect-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef35= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef36= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef36sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef37= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef37sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef38= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef38sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef39= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef39sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef40= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef40sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef41= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef41sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef42= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef42sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef43= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef43sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef44= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef44sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef45= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef45sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef46= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef46sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef47= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef47sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef48= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef48sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Rules2C16_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5) {
{
aterm * tmp[19];
PROF( prof_lf_AUX_MuASF_Rules2C16_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C16_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef3sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf_AUX_MuASF_Rules2C16_1sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , lf5sym)) {
{
aterm * atmp110= arg_0( atmp11);
{
aterm * atmp12= arg_2( arg1);
{
aterm * atmp13= arg_3( arg1);
{
aterm * atmp14= arg_4( arg1);
if( check_sym( arg4 , lf_AUX_MuASF_Rules2C16_2sym)) {
{
aterm * atmp40= arg_0( arg4);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 1]);
tmp[ 4]= ( * ef10)( tmp[ 1]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , ( * ef5)( ))) {
tmp[ 5]= ( * ef5)( );
t_protect( tmp[ 1]);
t_protect( tmp[ 5]);
if( term_equal( ( * ef32)( tmp[ 1]) , tmp[ 5])) {
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( tmp[ 1]);
t_protect( arg2);
t_protect( atmp14);
t_protect( tmp[ 1]);
t_protect( arg2);
t_protect( arg3);
t_protect( atmp40);
tmp[ 6]= ( * ef44)( ( * ef12)( ) , lf9( make_list( ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , ( * ef23)( atmp13 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , arg2))))) , ( * ef23)( atmp14 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , arg2)))))))) , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)));
if( check_sym( tmp[ 6] , ef45sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
t_protect( arg5);
t_protect( tmp[ 8]);
tmp[ 9]= ( * ef46)( ( * ef47)( ( * ef48)( arg5)) , ( * ef47)( ( * ef48)( tmp[ 8])));
if( check_sym( tmp[ 9] , ef47sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , ef48sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 9]);
return ( * ef6)( ( * ef7)( lf6( make_list( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))) , ( * ef37)( ) , tmp[ 7] , tmp[ 11]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 6]);
}
t_protect( tmp[ 1]);
t_protect( tmp[ 5]);
if( term_equal( ( * ef38)( tmp[ 1]) , tmp[ 5])) {
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( tmp[ 1]);
t_protect( arg2);
t_protect( atmp14);
t_protect( tmp[ 1]);
t_protect( arg2);
t_protect( arg3);
t_protect( atmp40);
tmp[ 6]= ( * ef44)( ( * ef12)( ) , lf9( make_list( ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , ( * ef23)( atmp13 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , arg2))))) , ( * ef23)( atmp14 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , arg2)))))))) , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)));
if( check_sym( tmp[ 6] , ef45sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 7]);
tmp[ 9]= ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef39)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , tmp[ 7]))));
t_protect( arg5);
t_protect( tmp[ 8]);
tmp[ 10]= ( * ef46)( ( * ef47)( ( * ef48)( arg5)) , ( * ef47)( ( * ef48)( tmp[ 8])));
if( check_sym( tmp[ 10] , ef47sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , ef48sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 10]);
return ( * ef6)( ( * ef7)( lf6( make_list( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))) , ( * ef37)( ) , tmp[ 9] , tmp[ 12]);
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 6]);
}
t_protect( tmp[ 1]);
if( term_equal( ( * ef11)( tmp[ 1]) , ( * ef12)( ))) {
t_protect( tmp[ 3]);
tmp[ 6]= ( * ef13)( ( * ef14)( ( * ef15)( lf4( make_list( tmp[ 3])))));
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( tmp[ 1]);
t_protect( tmp[ 6]);
t_protect( atmp14);
t_protect( tmp[ 1]);
t_protect( tmp[ 6]);
t_protect( arg3);
t_protect( atmp40);
tmp[ 7]= ( * ef44)( ( * ef12)( ) , lf9( make_list( ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , ( * ef23)( atmp13 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , tmp[ 6]))))) , ( * ef23)( atmp14 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , tmp[ 6])))))))) , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)));
if( check_sym( tmp[ 7] , ef45sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 6]);
t_protect( arg2);
t_protect( tmp[ 8]);
tmp[ 10]= ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef39)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 116))))))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , ( * ef9)( ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( tmp[ 6] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))))) , tmp[ 8])))));
t_protect( arg5);
tmp[ 11]= ( * ef43)( arg5);
t_protect( tmp[ 11]);
t_protect( tmp[ 9]);
tmp[ 12]= ( * ef46)( ( * ef47)( ( * ef48)( tmp[ 11])) , ( * ef47)( ( * ef48)( tmp[ 9])));
if( check_sym( tmp[ 12] , ef47sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , ef48sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 3]);
tmp[ 15]= ( * ef26)( ( * ef27)( lf4( make_list( tmp[ 3]))));
t_protect( tmp[ 14]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
return ( * ef6)( ( * ef7)( lf6( make_list( arg2))) , tmp[ 15] , tmp[ 10] , tmp[ 14]);
}
}
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
}
}
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf_AUX_MuASF_Rules2C16_1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= list_head( tmp[ 2]);
if( check_sym( tmp[ 3] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 5] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 2]);
tmp[ 7]= list_tail( tmp[ 2]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 4]);
if( term_equal( ( * ef4)( tmp[ 4]) , ( * ef5)( ))) {
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( atmp14);
t_protect( atmp40);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return lf_AUX_MuASF_Rules2C16_3( lf_AUX_MuASF_Rules2C16_1( make_list( tmp[ 7])) , ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , atmp13 , atmp14) , arg2 , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)) , arg5);
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
{
t_protect( atmp00);
tmp[ 4]= list_tail( atmp00);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( tmp[ 1]);
tmp[ 5]= ( * ef10)( tmp[ 1]);
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , ( * ef5)( ))) {
tmp[ 6]= ( * ef5)( );
t_protect( tmp[ 1]);
t_protect( tmp[ 6]);
if( term_equal( ( * ef38)( tmp[ 1]) , tmp[ 6])) {
t_protect( tmp[ 3]);
tmp[ 7]= ( * ef15)( lf4( make_list( tmp[ 3])));
t_protect( tmp[ 4]);
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( tmp[ 1]);
t_protect( tmp[ 7]);
t_protect( tmp[ 7]);
t_protect( atmp14);
t_protect( tmp[ 1]);
t_protect( tmp[ 7]);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg3);
t_protect( atmp40);
t_protect( arg5);
tmp[ 8]= lf_AUX_MuASF_Rules2C16_3( lf_AUX_MuASF_Rules2C16_1( make_list( tmp[ 4])) , ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , ( * ef23)( atmp13 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 115)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 99)) , make_list( make_char( 101))))))))) , ( * ef7)( lf6( cons( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48))))))))) , make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49))))))))))))))))))) , ( * ef23)( atmp14 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 115)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 99)) , make_list( make_char( 101))))))))) , ( * ef7)( lf6( cons( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48))))))))) , make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))))))))))))))) , arg2 , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)) , arg5);
if( check_sym( tmp[ 8] , ef6sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
tmp[ 11]= arg_2( tmp[ 8]);
tmp[ 12]= arg_3( tmp[ 8]);
if( check_sym( tmp[ 9] , ef7sym)) {
tmp[ 13]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 13] , lf6sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 14]);
if( is_single_element( tmp[ 14])) {
t_protect( tmp[ 14]);
tmp[ 15]= list_head( tmp[ 14]);
t_protect( tmp[ 3]);
tmp[ 16]= ( * ef26)( ( * ef33)( lf4( make_list( tmp[ 3]))));
t_protect( tmp[ 15]);
tmp[ 17]= ( * ef34)( tmp[ 15]);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 11]);
t_protect( tmp[ 7]);
t_protect( tmp[ 7]);
t_protect( tmp[ 17]);
t_protect( arg2);
t_protect( tmp[ 15]);
t_protect( arg2);
tmp[ 18]= ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef22)( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48)))))))) , arg2))) , ( * ef39)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , ( * ef16)( ( * ef17)( ( * ef17)( ( * ef17)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( arg2 , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))) , ( * ef19)( ( * ef22)( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))) , arg2))) , ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef35)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , ( * ef9)( ( * ef9)( ( * ef9)( tmp[ 11] , ( * ef16)( ( * ef18)( ( * ef19)( ( * ef22)( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))) , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , make_list( make_char( 116))))))))))))))) , ( * ef7)( lf6( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))))))))))))) , tmp[ 17]) , ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef22)( arg2 , tmp[ 15]))) , ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))))))))))));
t_protect( tmp[ 10]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 17]);
return ( * ef6)( ( * ef7)( lf6( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48))))))))))) , ( * ef8)( tmp[ 10] , tmp[ 16]) , tmp[ 18] , tmp[ 12]);
}
}
}
}
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 7]);
}
t_protect( tmp[ 1]);
t_protect( tmp[ 6]);
if( term_equal( ( * ef32)( tmp[ 1]) , tmp[ 6])) {
t_protect( tmp[ 3]);
tmp[ 7]= ( * ef15)( lf4( make_list( tmp[ 3])));
t_protect( tmp[ 4]);
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( tmp[ 1]);
t_protect( tmp[ 7]);
t_protect( tmp[ 7]);
t_protect( atmp14);
t_protect( tmp[ 1]);
t_protect( tmp[ 7]);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg3);
t_protect( atmp40);
t_protect( arg5);
tmp[ 8]= lf_AUX_MuASF_Rules2C16_3( lf_AUX_MuASF_Rules2C16_1( make_list( tmp[ 4])) , ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , ( * ef23)( atmp13 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 115)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 99)) , make_list( make_char( 101))))))))) , ( * ef7)( lf6( cons( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48))))))))) , make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49))))))))))))))))))) , ( * ef23)( atmp14 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 115)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 99)) , make_list( make_char( 101))))))))) , ( * ef7)( lf6( cons( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48))))))))) , make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))))))))))))))) , arg2 , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)) , arg5);
if( check_sym( tmp[ 8] , ef6sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
tmp[ 11]= arg_2( tmp[ 8]);
tmp[ 12]= arg_3( tmp[ 8]);
if( check_sym( tmp[ 9] , ef7sym)) {
tmp[ 13]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 13] , lf6sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 14]);
if( is_single_element( tmp[ 14])) {
t_protect( tmp[ 14]);
tmp[ 15]= list_head( tmp[ 14]);
t_protect( tmp[ 3]);
tmp[ 16]= ( * ef26)( ( * ef33)( lf4( make_list( tmp[ 3]))));
t_protect( tmp[ 15]);
tmp[ 17]= ( * ef34)( tmp[ 15]);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 11]);
t_protect( tmp[ 7]);
t_protect( tmp[ 7]);
t_protect( tmp[ 17]);
t_protect( arg2);
t_protect( tmp[ 15]);
t_protect( arg2);
tmp[ 18]= ( * ef16)( ( * ef17)( ( * ef17)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef22)( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48)))))))) , arg2))) , ( * ef19)( ( * ef22)( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))) , arg2))) , ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef35)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , ( * ef9)( ( * ef9)( ( * ef9)( tmp[ 11] , ( * ef16)( ( * ef18)( ( * ef19)( ( * ef22)( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))) , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , make_list( make_char( 116))))))))))))))) , ( * ef7)( lf6( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 49)))))))))))))))))) , tmp[ 17]) , ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef22)( arg2 , tmp[ 15]))) , ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))))))));
t_protect( tmp[ 10]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 17]);
return ( * ef6)( ( * ef7)( lf6( make_list( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))) , ( * ef7)( lf6( make_list( ( * ef13)( ( * ef29)( ( * ef14)( tmp[ 7]) , ( * ef13)( ( * ef30)( ( * ef31)( lf7( make_list( make_char( 48)))))))))))))))) , ( * ef8)( tmp[ 10] , tmp[ 16]) , tmp[ 18] , tmp[ 12]);
}
}
}
}
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 7]);
}
t_protect( tmp[ 1]);
if( term_equal( ( * ef11)( tmp[ 1]) , ( * ef12)( ))) {
t_protect( tmp[ 3]);
tmp[ 7]= ( * ef13)( ( * ef14)( ( * ef15)( lf4( make_list( tmp[ 3])))));
t_protect( arg2);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
tmp[ 8]= ( * ef16)( ( * ef17)( ( * ef17)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( tmp[ 7] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))) , ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( arg2 , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))));
t_protect( tmp[ 4]);
t_protect( atmp100);
t_protect( atmp110);
t_protect( atmp12);
t_protect( atmp13);
t_protect( tmp[ 1]);
t_protect( tmp[ 7]);
t_protect( atmp14);
t_protect( tmp[ 1]);
t_protect( tmp[ 7]);
t_protect( arg2);
t_protect( arg3);
t_protect( atmp40);
t_protect( arg5);
tmp[ 9]= lf_AUX_MuASF_Rules2C16_3( lf_AUX_MuASF_Rules2C16_1( make_list( tmp[ 4])) , ( * ef3)( lf_AUX_MuASF_Rules2C16_1( make_list( atmp100)) , lf5( make_list( atmp110)) , atmp12 , ( * ef23)( atmp13 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , tmp[ 7]))))) , ( * ef23)( atmp14 , ( * ef24)( lf8( make_list( ( * ef25)( tmp[ 1] , tmp[ 7])))))) , arg2 , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)) , arg5);
if( check_sym( tmp[ 9] , ef6sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
tmp[ 12]= arg_2( tmp[ 9]);
tmp[ 13]= arg_3( tmp[ 9]);
if( check_sym( tmp[ 10] , ef7sym)) {
tmp[ 14]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 14] , lf6sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 16]= list_head( tmp[ 15]);
t_protect( tmp[ 3]);
tmp[ 17]= ( * ef26)( ( * ef27)( lf4( make_list( tmp[ 3]))));
t_protect( tmp[ 16]);
tmp[ 18]= ( * ef28)( tmp[ 16]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 13]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 16]);
return ( * ef6)( ( * ef7)( lf6( make_list( tmp[ 18]))) , ( * ef8)( tmp[ 11] , tmp[ 17]) , ( * ef9)( tmp[ 8] , tmp[ 12]) , tmp[ 13]);
}
}
}
}
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
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
if( check_sym( arg4 , lf_AUX_MuASF_Rules2C16_2sym)) {
{
aterm * atmp40= arg_0( arg4);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 1] , ef40sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
t_protect( arg5);
tmp[ 5]= ( * ef13)( ( * ef41)( arg5));
t_protect( tmp[ 3]);
t_protect( tmp[ 5]);
t_protect( atmp40);
tmp[ 6]= ( * ef42)( tmp[ 3] , tmp[ 5] , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)));
t_protect( arg1);
t_protect( arg3);
t_protect( atmp40);
tmp[ 7]= ( * ef44)( ( * ef12)( ) , lf9( make_list( arg1)) , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)));
if( check_sym( tmp[ 7] , ef45sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 5]);
t_protect( arg2);
t_protect( tmp[ 6]);
t_protect( tmp[ 8]);
tmp[ 10]= ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef39)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 116))))))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , ( * ef9)( ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( tmp[ 5] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))))) , ( * ef16)( ( * ef18)( ( * ef39)( tmp[ 6] , ( * ef36)( ( * ef37)( ) , tmp[ 8])))))))));
t_protect( arg5);
tmp[ 11]= ( * ef43)( arg5);
t_protect( tmp[ 11]);
t_protect( tmp[ 9]);
tmp[ 12]= ( * ef46)( ( * ef47)( ( * ef48)( tmp[ 11])) , ( * ef47)( ( * ef48)( tmp[ 9])));
if( check_sym( tmp[ 12] , ef47sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , ef48sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 14]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
return ( * ef6)( ( * ef7)( lf6( make_list( arg2))) , ( * ef37)( ) , tmp[ 10] , tmp[ 14]);
}
}
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
}
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 1] , ef40sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
t_protect( atmp00);
tmp[ 5]= list_tail( atmp00);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 3]);
if( term_equal( ( * ef4)( ( * ef40)( tmp[ 3])) , ( * ef12)( ))) {
t_protect( arg5);
tmp[ 6]= ( * ef13)( ( * ef41)( arg5));
t_protect( tmp[ 3]);
t_protect( tmp[ 6]);
t_protect( atmp40);
tmp[ 7]= ( * ef42)( tmp[ 3] , tmp[ 6] , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)));
t_protect( tmp[ 5]);
t_protect( arg1);
t_protect( arg2);
t_protect( arg3);
t_protect( atmp40);
t_protect( arg5);
tmp[ 8]= lf_AUX_MuASF_Rules2C16_3( lf_AUX_MuASF_Rules2C16_1( make_list( tmp[ 5])) , arg1 , arg2 , arg3 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp40)) , ( * ef43)( arg5));
if( check_sym( tmp[ 8] , ef6sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
tmp[ 11]= arg_2( tmp[ 8]);
tmp[ 12]= arg_3( tmp[ 8]);
if( check_sym( tmp[ 9] , ef7sym)) {
tmp[ 13]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 13] , lf6sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 14]);
if( is_single_element( tmp[ 14])) {
t_protect( tmp[ 14]);
tmp[ 15]= list_head( tmp[ 14]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 6]);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( arg2);
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
tmp[ 16]= ( * ef16)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef39)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))) , ( * ef7)( lf6( make_list( arg2))))) , ( * ef36)( ( * ef37)( ) , ( * ef9)( ( * ef16)( ( * ef17)( ( * ef17)( ( * ef17)( ( * ef18)( ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( tmp[ 6] , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100))))))))))))) , ( * ef7)( lf6( make_list( arg2)))))))) , ( * ef19)( ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 99)) , make_list( make_char( 116))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))) , ( * ef19)( ( * ef22)( arg2 , ( * ef13)( ( * ef20)( ( * ef14)( ( * ef21)( lf7( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))) , ( * ef7)( lf6( make_list( arg2))))))))) , ( * ef16)( ( * ef18)( ( * ef39)( tmp[ 7] , ( * ef36)( ( * ef37)( ) , tmp[ 11])))))))));
t_protect( tmp[ 10]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef6)( ( * ef7)( lf6( make_list( tmp[ 15]))) , tmp[ 10] , tmp[ 16] , tmp[ 12]);
}
}
}
}
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf6( lf_AUX_MuASF_Rules2C16_3sym , arg0 , arg1 , arg2 , arg3 , arg4 , arg5);
}
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C16_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C16_2);
return make_nf1( lf_AUX_MuASF_Rules2C16_2sym , arg0);
}
aterm * lf9( aterm * arg0) {
PROF( prof_lf9);
return make_nf1( lf9sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C16_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C16_1);
return make_nf1( lf_AUX_MuASF_Rules2C16_1sym , arg0);
}
aterm * lf8( aterm * arg0) {
PROF( prof_lf8);
return make_nf1( lf8sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

