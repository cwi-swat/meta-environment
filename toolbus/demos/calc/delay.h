#include <math.h>
int delay  = 0;

void setdelay()
{
  char *d;

  if((d = getenv("TB_DELAY")))
    delay = atoi(d);
}
