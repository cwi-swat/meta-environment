// ======================================================================
//
// Copyright (c) 2004 Wieger Wesselink
//
// ----------------------------------------------------------------------
//
// file          : test/aterm_list_test.cpp
// date          : 12/06/04
// version       : 0.2
//
// author(s)     : Wieger Wesselink  <J.W.Wesselink@tue.nl>
//
// ======================================================================

#include <sstream>
#include <algorithm>
#include <boost/test/minimal.hpp>

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

void test_aterm_list()
{
  aterm_list q = make_term("[1,2,3,4]").to_list();

  aterm_list r = reverse(q); // r == [4,3,2,1]
  BOOST_TEST(r == make_term("[4,3,2,1]")); 

  aterm_list t = tail(q, 2); // t == [3,4]
  BOOST_TEST(t == make_term("[3,4]")); 

  aterm f = q.front(); // f == 1
  BOOST_TEST(f == aterm_int(1));

  q = push_front(q, make_term("[5,6]")); // q == [[5,6],1,2,3,4]

  stringstream os;
  for (aterm_list::iterator i = q.begin(); i != q.end(); ++i)
  {
    os << *i;
  }
  BOOST_TEST(os.str() == "[5,6]1234");

  int sum = 0;
  for_each(r.begin(), r.end(), counter(sum));
  BOOST_TEST(sum == 10);
  
  aterm_list v = make_term("[1,2,3,4]").to_list();
  aterm_list w = make_term("[0,1,2,3,4]").to_list();
  BOOST_TEST(pop_front(w) == v);
}

int test_main( int, char*[] )
{
  test_aterm_list();
  return 0;
}
