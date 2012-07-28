// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/make_match_test.cpp
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#include <iostream>
#include <boost/test/minimal.hpp>

#include "atermpp/aterm.h"

using namespace std;
using namespace atermpp;

void test_make_match()
{
  aterm a, b;
  aterm_list l, m;
  int i;
  bool x;

  x = match(make_term("f(16)"), "f(<int>)", i);
  BOOST_TEST(x);
  BOOST_TEST(i == 16); 

  x = match(make_term("[1,2,3]"), "[<int>,<list>]", i, a);
  BOOST_TEST(x);
  BOOST_TEST(i == 1); 
  BOOST_TEST(a.to_list().size() == 2);

  x = match(make_term("[1,2,3]"), "[<list>]", l);

  x = match(make_term("f([1,2,3])"), "f([<list>])", l);

  x = match(make_term("f(2,[1,2,3])"), "f(<term>,[<list>])", a, l);
  
  x = match(make_term("PBES(f(x),[1,2,3])"), "PBES(<term>,[<list>])", a, l);
  
  x = match(make_term("PBES(f(0),[1,2,3],g(2),[a,b])"), "PBES(<term>,[<list>],<term>,[<list>])", a, l, b, m);
}

int test_main( int, char*[] )
{
  test_make_match();
  return 0;
}
