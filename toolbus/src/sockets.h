#ifndef __SOCKETS_H__
#define __SOCKETS_H__

void TBdestroyPort(int);
int  putInt(int, const char *, int);
int  getInt(int, const char *);
int  createWellKnownSocket(char *, int);
int  connectWellKnownSocket(char *, int);
int  accept_in_interval(int, struct sockaddr *, int *);

extern int buf_size;
extern int WellKnownSocketPort;
extern int WellKnownGlobalSocket;
extern int WellKnownLocalSocket;

#endif /* __SOCKETS_H__ */
