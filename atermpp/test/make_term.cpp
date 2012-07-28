// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/make_term.cpp
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#include <iostream>
/*#include <boost/test/minimal.hpp>*/
#include "atermpp/aterm.h"

using namespace std;
using namespace atermpp;

void foo()
{
  const int i       = 42;
  const char* blob  = "12345678";
  const double r    = 3.14;
  const char *func  = "f";

  aterm term[4];
  aterm list[3];
  aterm appl[3];

  term[0] = make_term("<int>" , i);         // integer value: 42
  term[1] = make_term("<str>" , func);      // quoted application: "f", no args
  term[2] = make_term("<real>", r);         // real value: 3.14
  term[3] = make_term("<blob>", 8, blob);   // blob of size 8, data: 12345678

  list[0] = make_term("[]");
  list[1] = make_term("[1,<int>,<real>]", i, r);
  list[2] = make_term("[<int>,<list>]", i+1, list[1]); 

  appl[0] = make_term("<appl>", func);
  appl[1] = make_term("<appl(<int>)>", func, i); 
  appl[2] = make_term("<appl(<int>, <term>, <list>)>", func, 42, term[3], list[2]);

  std::cout << "appl[2] = " << appl[2] << std::endl;
}

int main(int, char*[])
{
  foo();
  return 0;
}
