#include "TB.h"
#include <fcntl.h>


void write_read(char *name, term *t1)
{
  int out = creat(name, 0666);
  int in;
  term *t2;

  if(out < 0)
    err_sys_fatal("Can't create %s\n", name);

  TBwrite(out, t1);
  close(out);
  in = open(name, O_RDONLY);

  if(in < 0)
    err_sys_fatal("Can't open %s for reading\n", name);

  t2 =TBread(in);
  close(in);
  
  if(!t2)
    err_fatal("Parse errors during reading\n");
  else if(!term_equal(t1,t2))
    err_fatal("Terms are unequal\n");
}

int main()
{
  char cbuf[50000];
  int i, n;

  init_utils();
  write_read("fa", mk_int(13));
  write_read("fb", mk_str("abc"));
  write_read("fc", mk_appl1(TBlookup("f"), mk_int(13)));
  write_read("fd", mk_str("ab\\\"c"));  
  write_read("fe", mk_str("ab\\\nc")); 
  write_read("ff", mk_str("a\b\f\n\r\vc")); 
 
  for(i = 0; i < 20000; i++)
    cbuf[i] = i % 256;

  for(i =  9980; i < 10010; i++){
    TBprintf(stderr, "%d ", i);
    write_read("fbin", TBmake("%b", cbuf, i));
  }

  TBprintf(stderr, "Done\n");
  exit(0);
}
