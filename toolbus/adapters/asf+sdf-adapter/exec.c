#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1

int stdin_cmd = -1;
int stdout_cmd = -1;
int stderr_cmd = -1;
char *cmd_in = NULL;
char *cmd_out = NULL;
int pid_cmd;

/*
 *     
 * Execute "cmd" and create three file descriptors for communication
 * with it:
 *     stdin_cmd:  for writing to cmd's std input stream
 *     stdout_cmd: for reading from cmd's std output stream
 *     stderr_cmd: for reading from cmd's std error stream 
 *
 * The overall structure is as follows:
 *
 *         +------------+
 *         |   parent   |
 *         +------------+
 *           |   ^   ^
 *   stdin_cmd   |   |
 *           |   stdout_cmd
 *           |   |   |
 *           |   |   stderr_cmd
 *           v   |   | 
 *         +------------+
 *         |    cmd     |
 *         +------------+
 */

void exec_cmd(char *cmd[], char *inp, int inp_len)
{
  int stderr_pipe[2];
  int parent_stdin, parent_stdout, parent_stderr;
  int fd_to_cmd;

  if(!cmd_in){
    cmd_in = tempnam(NULL, cmd[0]); 
    cmd_out = tempnam(NULL, cmd[0]);
  }

  if(stderr_cmd >= 0)
    close(stderr_cmd);

  if(pipe(stderr_pipe) < 0){
    fprintf(stderr, "Can't create pipe"); exit(1);
  }
  parent_stdin  = dup(0);
  parent_stdout = dup(1);
  parent_stderr = dup(2);

  stderr_cmd = stderr_pipe[READ];
  
  close(0); close(1); close(2);

  /* construct fd 0 */

  if((fd_to_cmd = creat(cmd_in, 0777)) < 0){
    perror("creating tmp input file");
    exit(1);
  }
  if(write(fd_to_cmd, inp, inp_len) < 0){
    perror("write to tmp input file");
    exit(-1);
  }

  if(close(fd_to_cmd) < 0){
    perror("close tmp input file");
  }
  
  if(open(cmd_in, O_RDONLY) < 0){
    perror("opening tmp input file");
    exit(1);
  }

  /* cmd_in now acts as fd 0 for cmd */

  /* construct fd 1 */

  if(creat(cmd_out, 0777) < 0){
    perror("creating tmp output file");
    exit(1);
  }

 /* construct fd 2 */

  if(dup(stderr_pipe[WRITE]) < 0){
    perror("creating tmp output file");
    exit(1);
  }
  
  if((pid_cmd = fork())){
    /* adapter: the parent */
    if(pid_cmd < 0){
      fprintf(stderr, "Can't fork\n"); exit(1);
    }
    close(0); close(1); close(2);
    dup(parent_stdin);
    dup(parent_stdout);
    dup(parent_stderr);

    close(parent_stdin);
    close(parent_stdout); 
    close(parent_stderr); 

    close(stderr_pipe[WRITE]);
  } else {
    /* cmd: the child */

    /* close remaining pipe ends ! */

    if(execvp(cmd[0], cmd) < 0){
      fprintf(stderr, "Can't execute cmd %s\n", cmd[0]);
      exit(-1);
    }
  }
}

char err_msg[512];

char *wait_cmd(void)
{
  int n, r, status;
  while ((r = wait(&status)) != pid_cmd && r != -1)
    fprintf(stderr, "status = %d\n", status);

/*  fprintf(stderr, "exit status = %d\n", WEXITSTATUS(status)); */
  if(WEXITSTATUS(status)){
    n = read(stderr_cmd, err_msg, 512);
    /*fprintf(stderr, "error msg (%d bytes): %s\n", n, err_msg);
    fflush(stderr);*/
    if(n >= 4 &
       err_msg[0] == 'd' && err_msg[1] == 'o' &&
       err_msg[2] == 'n' && err_msg[3] == 'e')
      return NULL;
    else
      return err_msg;
  } else
    return NULL;
}

void cleanup_cmd()
{
  if(cmd_in)
    unlink(cmd_in);
  if(cmd_out)
    unlink(cmd_out);
}

/*
char *dummy[] = {"dummy", NULL};

main()
{  
  char line[512] = { '\0' };
  char *msg = "abc\ndef\n", *err;
  int n, status;
  FILE *from_cmd;

  exec_cmd(dummy, msg, strlen(msg));

  if(( err = wait_cmd()))
     fprintf(stderr, "error case: %s\n", err);


  if((from_cmd = fopen(cmd_out, "r")) == NULL){
    perror("opening tmp output file");
    exit(1);
  }

  while(fgets(line, 512, from_cmd) != NULL){
    fprintf(stderr, "from_cmd: %s\n", line);
  }
}
  
*/
