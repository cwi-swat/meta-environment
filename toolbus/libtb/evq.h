/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
#line 20 "evq.c.nw"
#ifndef EVQ_H
#define EVQ_H

#include "TB.h"

typedef struct {
  int cid;
  int max_size;
  term_list *events;
  term *pending;
} event_queue;

event_queue *TBevq_create(int max_size, int cid);
void TBevq_destroy(event_queue *q);
void TBevq_post(event_queue *q, term *event);
TBbool TBevq_is_full(event_queue *q);
TBbool TBevq_is_empty(event_queue *q);
int TBevq_length(event_queue *q);
TBbool TBevq_ack_event(event_queue *q, term *event);

#endif
