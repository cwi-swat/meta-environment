// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/constructors.cpp
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#include <iostream>
#include "atermpp/aterm.h"

using namespace std;
using namespace atermpp;

int main(int, char*[])
{
  aterm_int i(10);
  aterm_real r(2.5);
  aterm_appl f(function_symbol("f", 2), aterm("x"), aterm("y"));
  if (f.to_string() == "f(x,y)") {
    return 0;
  }

  return 1;
}
