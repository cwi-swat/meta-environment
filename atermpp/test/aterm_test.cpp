// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/aterm_test.cpp
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

void test_aterm()
{
  aterm a = make_term("f(x)");
  aterm label = make_term("label");
  aterm annotation = make_term("annotation");
  aterm b = set_annotation(a, label, annotation);
  BOOST_TEST(a != b);
  aterm c = remove_annotation(b, label);
  BOOST_TEST(a == c);
  
  aterm d = aterm_int(10);
  BOOST_TEST(d.to_int().value() == 10);
  
  aterm e = aterm();
  BOOST_TEST(!e);
}

int test_main( int, char*[] )
{
  test_aterm();
  return 0;
}
