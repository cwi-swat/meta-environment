#include "calc.tif.c"

int calculate(term *t)
{ int n;
  char *s;
  term *t1, *t2;

  if(TBmatch(t, "%d", &n))
     return n;
  else if(TBmatch(t, "%s", &s))
	  return atoi(s);
  else if(TBmatch(t, "plus(%t,%t)", &t1, &t2))
	  return calculate(t1) + calculate(t2);
  else if(TBmatch(t, "times(%t,%t)", &t1, &t2))
	  return calculate(t1) * calculate(t2);
  else {
        TBmsg("panic in calculate: %t\n", t);
        return 0;
      }
}

term *expr(char *s)
{ term *trm = TBmake(s);

  if(!trm)
    return TBmake("snd-value(calc-error(%s))", s);
  else
    return TBmake("snd-value(%d)", calculate(trm));
}

void rec_terminate(term *t)
{
  exit(0);
}

void main(int argc, char *argv[])
{
  extern term_list *tool_in_sign, *tool_out_sign;
  term *trm;

  TBinit("calc", argc, argv, calc_handler, calc_check_in_sign);

  TBeventloop();
}
