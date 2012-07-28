#include <aterm2.h>
#include <stdio.h>

static int cid = -1;

void setCid(int cur_cid)
{
  cid = cur_cid;
}

int getCid() 
{
  return cid;
}

