#include "toolbus.h"
#include "terms.h"
#include "utils.h"
#include "env.h"

#define TST(n) fprintf(stderr, "\nTest %d ", n)
#define KO(n)  fprintf(stderr, " ... %d fails\n", n)

trace_update(term *t1, term *t2, int n)
{
}

main()
{ env *e1, *e2;
  var *vx, *vy;
  term *t1, *t2;

  vx = mk_var("x"); vy = mk_var("y");

  t1 = mk_int(55); t2 = mk_str("abc");

  TST(0);
  if(!is_var(vx)) KO(1);
  if(!streq(get_txt(sym(vx)), "x")) KO(2);

  if(!is_var(vy)) KO(3);
  if(!streq(get_txt(sym(vy)), "y")) KO(4);

  if(!is_int(t1)) KO(5);
  if(!is_str(t2)) KO(6);

  TST(10);

  e1 = assign(vx, t1, NULL);
  if(!term_equal(value(vx,e1), t1)) KO(11);

  e1 = assign(vx, t2, e1);
  if(!term_equal(value(vx,e1), t2)) KO(12); 

  e1 = assign(vy, t1, e1);
  if(!term_equal(value(vy,e1), t1)) KO(13);

  e1 = assign(vx, t1, assign(vy, t2, NULL));
  e2 =assign(vx, t2, NULL);
  e1 = update(e2, e1, 0);
  
  if(!term_equal(value(vx,e1), t2)) KO(14); 

  fprintf(stderr, "\nDone\n");     

}
