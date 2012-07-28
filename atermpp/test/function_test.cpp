// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/function_test.cpp
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#include <iostream>
#include <string>
#include <boost/test/minimal.hpp>

#include "atermpp/aterm.h"

using namespace std;
using namespace atermpp;

void test_aterm_function()
{
  // create an unquoted function symbol
  function_symbol sym("\"f\"", 1, false);
  BOOST_TEST(!sym.is_quoted()); 
  aterm x = make_term("x");

  aterm_appl a(sym, x);
  BOOST_TEST(a.to_string() == "\"f\"(x)");
  BOOST_TEST(!a.is_quoted());
  BOOST_TEST(a.function() == sym);

  string s = a.to_string();
  aterm_appl b = make_term(s).to_appl();
  BOOST_TEST(b.to_string() == "\"f\"(x)");
  BOOST_TEST(b.is_quoted());     // this is quite unexpected
  BOOST_TEST(b.function() != sym); // this is quite unexpected

  aterm_appl c = read_from_string(s).to_appl();
  BOOST_TEST(c.to_string() == "\"f\"(x)");
  BOOST_TEST(c.is_quoted());     // this is quite unexpected
  BOOST_TEST(c.function() != sym); // this is quite unexpected
  
  aterm_appl f = make_term("f(g(a,b),c)").to_appl();
  aterm_appl g = make_term("g(a,b)").to_appl();
  BOOST_TEST(f.argument(0) == g);
}

int test_main( int, char*[] )
{
  test_aterm_function();
  return 0;
}
