#ifndef __SOCKETS_H__
#define __SOCKETS_H__

int  TBmakeInPort(char *, int);
int  TBmakeOutPort(char *, int);
void TBdestroyPort(int);
int  putInt(int, const char *, int);
int  getInt(int, const char *);
int  createWellKnownSocket(char *, int);
int  connectWellKnownSocket(char *, int);
int  accept_in_interval(int, struct sockaddr *, int *);

int connectsocket (const char *, int);
int createsocket (const char *, int);


extern int buf_size;
extern int WellKnownSocketInPort;
extern int WellKnownSocketOutPort;
extern int WellKnownSocketIn;
extern int WellKnownSocketOut;

#endif /* __SOCKETS_H__ */
