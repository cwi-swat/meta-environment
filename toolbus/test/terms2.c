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
  char *str1 = "abc", str2;
  int len2;

  TST(0);
  t1 = mk_bstr(str1, strlen(str1)) ;
  if(!is_bstr(t1)) KO(1);
  if(bstr_len(t1) != strlen(str1)) KO(2);

  pr_term(t1);
  TBmsg("as term: %t\n", t1);
  TBmsg("as string: %b\n", str1, strlen(str1));
  if(!TBmatch(t1, "\"abc\"")) KO(3);

  t2 = TBmakeTerm("%b", str1, strlen(str1));
  TBmsg("t2 = %t\n", t2);

  if(!TBmatch(t2, "%b", &str2, &len2)) KO(4);
  if(len2 != strlen(str1)) KO(5);

  if(!equal_term(t1, t2)) KO(6);
 	
  fprintf(stderr, "\nDone\n");
  
}
