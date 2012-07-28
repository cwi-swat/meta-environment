// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/is_quoted.cpp
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

int test_main( int, char*[] )
{
  // unquoted function symbol s == "f"
  function_symbol s("\"f\"", 1, false);
  aterm_appl f(s, aterm("x"));

  // convert to string and back
  aterm_appl g = make_term(f.to_string()).to_appl();

  BOOST_TEST(g.is_quoted());
  BOOST_TEST(g.function() != s);
  function_symbol s1("f", 1, true);
  BOOST_TEST(g.function() == s1);

  return 0;
}
