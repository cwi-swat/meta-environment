#include "TB.h"

int nerr = 0;

#define NL fprintf(stderr, "\n");
#define TST_OK(n,s)  \
        fprintf(stderr, "test %d ... ", n); \
        t = TBmake(s); \
        if(!TBmatch(t, s)) { nerr++; fprintf(stderr, "KO\n"); } else fprintf(stderr, "ok\n");

#define TST_KO(n,s,ser)  \
        fprintf(stderr, "test %d ... ", n); \
        t = TBmake(s); \
        if(TBmatch(t, ser)) { nerr++; fprintf(stderr, "KO\n"); } else fprintf(stderr, "ok\n");

#define TST_D(n,s1,s2,v)  \
        fprintf(stderr, "test %d ... ", n); \
        t = TBmake(s1); \
        if(!TBmatch(t, s2, &ival) || ival != v)\
           { nerr++; fprintf(stderr, "KO"); } else fprintf(stderr, "ok");\
        t = TBmake(s2, v);\
        if(!TBmatch(t, s1))\
         { nerr++; fprintf(stderr, " ... KO\n"); } else fprintf(stderr, " ... ok\n");

#define TST_S(n,s1,s2,v)  \
        fprintf(stderr, "test %d ... ", n); \
        t = TBmake(s1); \
        if(!TBmatch(t, s2, &sval) || !streq(sval,v))\
          { nerr++;  fprintf(stderr, "KO"); } else fprintf(stderr, "ok");\
        t = TBmake(s2,v); \
        if(!TBmatch(t, s1))\
         { nerr++; fprintf(stderr, " ... KO\n"); } else fprintf(stderr, " ... ok\n");

#define TST_T(n,s1,s2,tv)  \
        fprintf(stderr, "test %d ... ", n); \
        t = TBmake(s1); \
        if(!TBmatch(t, s2, &tval) || !TBmatch(tval,tv)) { nerr++; fprintf(stderr, "KO"); } else fprintf(stderr, "ok");\
        t = TBmake(s2,TBmake(tv)); \
        if(!TBmatch(t, s1))\
         { nerr++; fprintf(stderr, " ... KO\n"); } else fprintf(stderr, " ... ok\n");

#define TST_P(n,s1,s2)  \
        fprintf(stderr, "test %d ... ", n); \
        t = TBmake(s1); \
        if(!TBmatch(t, s2)) { nerr++; fprintf(stderr, "KO"); } else fprintf(stderr, "ok");

void main(int argc, char *argv[])
{
  term *t, *tval;
  int ival;
  char *sval;

  init_terms();
  init_utils();

  TST_OK(1, "abc");
  TST_OK(2, "  abc");
  TST_OK(3, "abc  ");
  TST_OK(4, "f(a)");

  TST_OK(5, "f(a, b)");
  TST_OK(6, "f (a, b)");
  TST_OK(7, "f( a, b)");
  TST_OK(8, "f(a , b)");
  TST_OK(9, "f(a, b )");
  TST_OK(10, " f ( a , b ) ");

  TST_KO(11, "a", "b");
  TST_KO(12, "ab", "a");
  TST_KO(13, "a", "ab");
  TST_KO(14, "a", "a b");
  TST_KO(15, "f(a,b)", "f(a,b) c");

  TST_OK(20, "123");
  TST_OK(21, " 123");
  TST_OK(22, " 123 ");
  TST_OK(23, " -123 ");

  TST_KO(24, "123", "223");
  TST_KO(25, "123", "133");
  TST_KO(26, "123", "124");
  TST_KO(27, "123", "1234");
  TST_KO(28, "123", "12");
  TST_KO(29, "123", "123 4");

  TST_OK(30, "\"abc\"");
  TST_OK(31, " \"abc\"");
  TST_OK(32, " \"abc\" ");
  TST_KO(33, "\"abc\"", "\"ebc\"");
  TST_KO(34, "\"abc\"", "\"ebc\"");
  TST_KO(35, "\"abc\"", "\"aec\"");
  TST_KO(36, "\"abc\"", "\"abe\"");
  TST_KO(37, "\"abc\"", "\"abcd\"");
  TST_KO(38, "\"abc\"", "\"ab\"");
  TST_KO(39, "\"abc\"", "\"abc\" d");


  TST_OK(40, "\"a\\\"b\"");
  TST_OK(41, "\"a\\bc\"");
  TST_OK(42, "\"a\\fc\"");
  TST_OK(43, "\"a\\nc\"");
  TST_OK(44, "\"a\\rc\"");
  TST_OK(45, "\"a\\tc\"");
  TST_OK(46, "\"a\\vc\"");
  TST_OK(47, "\"a\\\nc\"");
  TST_OK(48, "\"a\\\n\\\"c\"");

  fprintf(stderr, "test %d ... ", 49);
  t = TBmake("123");
  if(TBmatch(t, "%d\"", &ival)){
    nerr++; fprintf(stderr, "KO\n");
  } else fprintf(stderr, "ok\n");


  TST_D(50, "123", "%d", 123);

  TST_D(51, "f(123)", "f(%d)", 123);
  TST_D(52, " f ( -123 ) ", " f ( %d ) ", -123);

  TST_S(53, "\"abc\"", "%s", "abc");
  TST_S(54, "f(\"abc\")", "f(%s)", "abc");
  TST_S(55, "fun(a,b)", "%f(a,b)", "fun");
  TST_S(56, "fun(a,b)", "%f (a,b)", "fun");
  TST_S(57, "fun", "%f", "fun");
  TST_S(58, " fun ", " %f ", "fun");

  TST_T(60, "f(a)", "f(%t)", "a");
  TST_T(61, "f(a,b,c)", "f(%t,b,c)", "a");
  TST_T(62, "f(a,b,c)", "f(a,%t,c)", "b");
  TST_T(63, "f(a,b,c)", "f(a,b,%t)", "c");

  TST_OK(70, "[]");
  TST_OK(71, " []");
  TST_OK(72, "[ ]");
  TST_OK(73, "[] ");
  TST_OK(74, "[ a]");
  TST_OK(75, "[a ]");
  TST_OK(76, "[a] ");
  TST_OK(77, "[a,b,c]");
  TST_OK(78, "[a ,b,c]");
  TST_OK(79, " [ a , b , c ] ");

  TST_T(80, "[]", "[%l]", "[]");
  TST_T(81, "[]", "[ %l]", "[]");
  TST_T(82, "[]", "[%l ]", "[]");
  TST_T(83, "[]", "[%l] ", "[]");
  TST_T(84, "[]", " [ %l ] ", "[]");
  TST_T(85, "[a,b,c]", "[a,b,%l]", "[c]");
  TST_T(86, "[a,b,c]", "[a,b,c,%l]", "[]");
  TST_T(87, "[a,b,c]", " [ a , b , c , %l ] ", " [ ] ");

  TST_T(90, "f(a,b,c)", "f(%l)", "[a,b,c]");
  TST_T(91, "f(a,b,c)", "f(a,%l)", "[b,c]");
  TST_T(92, "f(a,b,c)", "f(a,b,%l)", "[c]");
  TST_T(93, "f(a,b,c)", "f(a,b,c,%l)", "[]");
  TST_T(94, "f(a,b,c)", "f(a,b,c, %l)", "[]");
  TST_T(95, "f(a,b,c)", " f ( a , b , c , %l ) ", "[]");

  TST_S(100, "[f(a,b,c), g(d)]", "[%f(a,b,c), g(d)]", "f");
  TST_T(101, "[f(a,b,c), g(d)]", "[f(%l), g(d)]", "[a,b,c]");
  TST_T(102, "[f(a,b,c), g(d)]", "[f(a,b,c), %t]", "g(d)");
  TST_S(103, "[F(a,b,c), g(d)]", "[%f(a,b,c), g(d)]", "F");

  tval = NULL;
  TST_T(110, "Var", "Var", "[]");
  TST_T(111, "Var$P", "Var$P", "[]");
  TST_T(112, "Var$P", "Var$P:term", "[]");
  TST_T(113, "Var$P:int", "Var$P:int", "[]");
  TST_T(114, "Var$P:int", "Var$P :int", "[]");
  TST_T(115, "Var$P:int", "Var$P: int", "[]");
  TST_T(116, "Var$P:int", "Var$P : int", "[]");

  TST_T(117, "snd-eval(calc(Tid$CALC:int),expr(E$CALC:str))",
	     "snd-eval(calc(Tid$CALC:int),expr(E$CALC:str))", "[]");

  TST_P(120, "true", "<bool>"); NL;
  TST_P(121, "123", "<int>");  NL;
  TST_P(122, "123", " < int > "); NL;
  TST_P(123, "\"abc\"", "<str>"); NL;
  TST_P(124, "f(123)", "f(<int>)"); NL;
  TST_P(125, "[a,b,c]", "<list>"); NL;
  TST_P(126, "f(3,\"abc\",4)", "f(<int>,<str>,<int>)"); NL;
  TST_P(127, "f(3,g(4),5)", "f(<int>,<g(<int>)>, <int>)"); NL;
  TST_P(128, "f(3,g(a,4,b),5)", "f(<int>, <g(a,<int>,b)>, 5)"); NL;

  TST_P(130, "[]", "<list>");  NL;
  TST_P(131, "[]", "<list(int)>"); NL;
  TST_P(132, "[1,2]", "<list>"); NL;
  TST_P(133, "[1, 2]", "<list(int)>"); NL;
  TST_P(134, "f(\"abc\",[1,2], a)", "f(<str>,<list(int)>,<a>)"); NL;

  TST_P(140, "<int>", "<int>"); NL;


  TST_OK(150, "{attr(1) : b}");
  TST_OK(151, "f({1 : a}, b)");
  TST_OK(152, "[a, {2 : b}, c]");

  TST_P(160, "{attr(1) : b}", "b");NL;
  TST_P(161, "f({1 : a}, b)", "f(a,b)");NL;
  TST_P(162, "[a, {2 : b}, c]", "[a,b,c]");NL;

  TST_T(170, "{attr(x) : b}", "{attr(%t):b}", "x");
  TST_S(171, "{attr(x) : b}", "{%f(x):b}", "attr");
  TST_T(172, "{attr(x) : b}", "{attr(x):%t}", "b");
  TST_T(173, "f({attr(x) : b})", "f({attr(%t):b})", "x");
  TST_S(174, "f({attr(x) : b})", "f({%f(x):b})", "attr");
  TST_T(175, "f({attr(x) : b})", "f({attr(x):%t})", "b");

  if(nerr)
    fprintf(stderr, "TBmatch1: %d ERRORS\n", nerr);
  else
    fprintf(stderr, "TBmatch1 TESTS OK\n");
  exit(nerr);
}
