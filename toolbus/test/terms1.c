#include "toolbus.h"
#include "terms.h"
#include "utils.h"

int test_no;

#define TST(n)    test_no = n; fprintf(stderr, "\nTest %d ", n)
#define KO(n)     fprintf(stderr, " ... %d fails\n", test_no+ n)
#define PR(s, t)  fprintf(stderr, "Print term %s ... ", s); pr_term(t); fprintf(stderr, "\n");

main()
{
  term *t1, *t2, *t3, *n25, *sabc;

  TST(0); t1 = mk_bool(TBtrue); if(!is_bool(t1)) KO(1); if(!bool_val(t1)) KO(2);

  TST(10); t1 = mk_int(13); if(!is_int(t1)) KO(1); if(int_val(t1) != 13) KO(2);

  TST(20);t1 = mk_str("abc"); if(!is_str(t1)) KO(1); if(!streq(str_val(t1), "abc")) KO(2);

  TST(30); t1 = mk_var("x"); if(!is_var(t1)) KO(1); if(sym(t1) != lookup("x")) KO(2);

  TST(40); t1 = mk_mvar("y"); if(!is_mvar(t1)) KO(1); if(sym(t1) != lookup("y")) KO(2);

  TST(50); t1 = mk_form("y"); if(!is_form(t1)) KO(1); if(sym(t1) != lookup("y")) KO(2);

  TST(60); n25 = mk_int(25); sabc = mk_str("abc");

  t1 = mk_list(n25, mk_list(sabc, NULL));

  if(!is_list(t1)) KO(1);
  if(first(t1) != n25) KO(2);
  if(first(next(t1)) != sabc) KO(3);
  if(length_list(t1) != 2) KO(4);
  if(!elem(n25, t1)) KO(5);
  if(!subset(mk_list(n25, NULL), t1)) KO(6);

  TST(70);
  t2 = mk_list(mk_str("abc"), mk_list(mk_int(25), NULL));
  if(!is_list(t2)) KO(1);
  if(!subset(t2, t1)) KO(2);
  t3 = append_list(t2, mk_int(26));
  if(length_list(t3) != 3) KO(3);
  if(!subset(t2, t3)) KO(4);
  t3 = delete(sabc, t3);
  if(length_list(t3) != 2) KO(5);
  if(elem(mk_str("abc"), t3)) KO(6);  

  TST(80);
  if(!term_equal(mk_bool(TBtrue), mk_bool(TBtrue))) KO(1);
  if(!term_equal(mk_int(3), mk_int(3))) KO(2);
  if(!term_equal(mk_str("abc"), mk_str("abc"))) KO(3);
  if(!term_equal(t1, t1)) KO(4);
  if(!term_equal(mk_appl(lookup("f"), t1), mk_appl(lookup("f"), mk_list(n25, mk_list(sabc, NULL))))) KO(5);

  
  TST(80);
  fprintf(stderr, "\n");
  PR("true",mk_bool(TBtrue));
  PR("3", mk_int(3));
  PR("\"abc\"",mk_str("abc"));
  PR("X", mk_var("X"));
  PR("X?", mk_mvar("X"));
  PR("X", mk_form("X"));
  PR("f(25,\"abc\")", mk_appl(lookup("f"), mk_list(n25, mk_list(sabc, NULL))));
  PR("[1,2]", mk_list(mk_int(1), mk_list(mk_int(2), NULL)));
	
  fprintf(stderr, "\nDone\n");
  
}
