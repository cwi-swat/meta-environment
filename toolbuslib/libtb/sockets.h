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
#ifndef __SOCKETS_H__
#define __SOCKETS_H__

#include <sys/socket.h>

void TBdestroyPort(int);
int  putInt(int, const char *, int);
int  getInt(int, const char *);
int  createWellKnownSocket(char *, int);
int  connectWellKnownSocket(char *, int);
int  accept_in_interval(int, struct sockaddr *, int *);
int  mk_server_ports(int local_port_only);
void tb_sleep(int sec, int usec);

extern int buf_size;
extern int WellKnownSocketPort;
extern int WellKnownGlobalSocket;
extern int WellKnownLocalSocket;

#endif /* __SOCKETS_H__ */
