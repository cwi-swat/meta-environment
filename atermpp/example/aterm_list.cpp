// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : example/aterm_list.cpp
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#include <algorithm>
#include <iostream>
#include "atermpp/aterm.h"

using namespace std;
using namespace atermpp;

struct counter
{
  int& m_sum;   

  counter(int& sum)
    : m_sum(sum)
  {}   

  void operator()(const aterm& t)
  {
    m_sum += t.to_int().value();
  }
};

int main()
{
  aterm_list q = make_term("[1,2,3,4]").to_list();
  int sum = 0;
  for_each(q.begin(), q.end(), counter(sum));
  assert(sum == 10);
  
  for (aterm_list::iterator i = q.begin(); i != q.end(); ++i)
  {
    cout << *i;
  }     
}
