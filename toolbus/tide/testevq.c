
#include "evq.h"
#include "testevq.tif.c"

event_queue *burst_queue;

void rec_terminate(int cid, term *arg)
{
  exit(1);
}

void rec_ack_event(int cid, term *ev)
{
  TBprintf(stderr, "rec_ack_event(%t)\n", ev);
  TBcheck_ack_event(burst_queue, ev);
  if(TBevq_is_empty(burst_queue))
    TBprintf(stderr, "queue is empty!\n");
}

void start_burst(int cid, int nr)
{
  static int count = 0;
  int i;

  TBprintf(stderr, "start_burst(%d) (%d)\n", nr, count);
  for(i=0; i<nr; count++, i++) {
    TBpost_event(burst_queue, TBmake("burst(%d)", count));
    TBprintf(stderr, ".");
  }
  TBprintf(stderr, "\nqueue length: %d\n", TBevq_length(burst_queue));
  if(TBevq_is_full(burst_queue))
    TBprintf(stderr, "queue is full!\n");
}


int main(int argc, char *argv[])
{
  int cid;

  TB_init();
  cid = TB_parseArgs(argc, argv, testevq_handler, testevq_check_in_sign);
  TB_connect(cid);

  burst_queue = TBcreate_evq(25, -1);
  TB_eventloop();
}
