/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#include <aterm2.h>
#include <atb-tool.h>

/*}}}  */

/*{{{  static int create_inet_socket(int port) */

static int create_inet_socket(int port)
{
  struct sockaddr_in addr;
  int attempts = 0;
  int sock;
  int opt;
  int retval;

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("swing-connector:socket");
    exit(1);
  }

  opt = 1;
  retval = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  if (retval == -1) {
    perror("swing-connector:setsockopt SO_REUSEADDR");
  }

  memset((char *) &addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);

  while (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    if (attempts > 1000) {
      return -1;
    }
    attempts++;
  }

  return sock; 
}

/*}}}  */
/*{{{  static int allocate_inet_socket() */

static int allocate_inet_socket()
{
  int try_port;
  int sock;

  for (try_port = 10000; try_port < 15000; try_port++) {
    ATwarning("try_port: %d\n", try_port);
    sock = create_inet_socket(try_port);
    if (sock >= 0) {
      return sock;
    }
  }

  return -1;
}

/*}}}  */

/*{{{  static int editor_eventloop(int editor_socket, int read_from_hive_fd, int write_to_hive_fd) */

static int editor_eventloop(int editor_socket, int read_from_hive_fd, int write_to_hive_fd)
{
  ATerm t;
  fd_set set;
  int max_fd;
  int retval;

  while (ATtrue) {
    FD_ZERO(&set);

    FD_SET(editor_socket, &set);
    max_fd = editor_socket;

    FD_SET(read_from_hive_fd, &set);
    if (read_from_hive_fd > max_fd) {
      max_fd = read_from_hive_fd;
    }

    retval = select(max_fd+1, &set, NULL, NULL, NULL);
    if (retval == -1) {
      perror("select");
    }

    if (FD_ISSET(editor_socket, &set)) {
      t = ATBreadTerm(editor_socket);
      ATwarning("editor_eventloop: %t\n", t);
      ATBwriteTerm(write_to_hive_fd, t);
    }

    if (FD_ISSET(read_from_hive_fd, &set)) {
      t = ATBreadTerm(read_from_hive_fd);
      ATBwriteTerm(editor_socket, t);
    }
  }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i;
  int editor_socket;
  int server_socket;
  int retval;
  int read_from_hive_fd = -1;
  int write_to_hive_fd = -1;
  const char *filename;

  for (i=1; i<argc; i++) {
    const char *cur = argv[i];
    if (strcmp(cur, "--read_from_hive_fd") == 0) {
      read_from_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, "--write_to_hive_fd") == 0) {
      write_to_hive_fd = atoi(argv[++i]);
    }
    else if (strcmp(cur, "--filename") == 0) {
      filename = argv[++i];
    }
  }

  assert(read_from_hive_fd >= 0);
  assert(write_to_hive_fd >= 0);

  server_socket = allocate_inet_socket();
  if (server_socket == -1) {
    ATerror("unable to allocate inet socket, giving up.\n");
    exit(1);
  }

  retval = listen(server_socket, 1);
  if (retval == -1) {
    perror("listen");
    exit(1);
  }

  editor_socket = accept(server_socket, NULL, NULL);
  if (editor_socket == -1) {
    perror("accept");
    exit(1);
  }

  retval = close(server_socket);
  if (retval == -1) {
    perror("close:server_socket");
    exit(1);
  }

  retval = editor_eventloop(editor_socket, read_from_hive_fd, write_to_hive_fd);
  return retval;
}

/*}}}  */
