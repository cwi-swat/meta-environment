#include "support.h"
static Symbol lf_AUX_AsFix2Sign_C3_1sym;
static ATerm lf_AUX_AsFix2Sign_C3_1( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef10sym;
static funcptr ef10;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_AsFix2Sign_C3( ) {
lf_AUX_AsFix2Sign_C3_1sym= ATmakeSymbol( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"syntax2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix2Sign_C3_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"ATerm\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"syntax2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2Sign_C3_1 , lf_AUX_AsFix2Sign_C3_1sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"ATerm\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
}
void resolve_AUX_AsFix2Sign_C3( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"synsecs2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"synsecs2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_AsFix2Sign_C3( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_AsFix2Sign_C3_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[6];
PROF( prof_lf_AUX_AsFix2Sign_C3_1);
if( check_sym( arg0 , ef1sym)) {
return ( * ef2)( ( constant0? constant0: ( constant0= ( * ef3)( lf2( make_list( null( )))))) , arg1);
}
if( ! term_equal( arg0 , ( * ef1)( ))) {
tmp[ 0]= ( * ef4)( arg0 , ( constant1? constant1: ( constant1= ( * ef5)( lf3( make_list( ( * ef6)( ( * ef7)( ) , ( * ef8)( ( * ef9)( ( * ef10)( ( * ef11)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 76)) , cons( make_list( make_char( 65)) , cons( make_list( make_char( 89)) , cons( make_list( make_char( 79)) , cons( make_list( make_char( 85)) , cons( make_list( make_char( 84)) , make_list( make_char( 34)))))))))))))))))))) , arg1);
if( check_sym( tmp[ 0] , ef12sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , ef3sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 4] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
return ( * ef2)( ( * ef3)( lf2( make_list( tmp[ 5]))) , tmp[ 3]);
}
}
}
}
return make_nf2( lf_AUX_AsFix2Sign_C3_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

