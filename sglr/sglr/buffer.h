/*
  \subsection{buffer.h}

  The buffer data type buffers provides buffering of a file in memory
  without flushing it. It can also be used independently from file IO.

  This buffering facility is similar to that provided by the standard
  IO library.  The difference is that the complete file is stored in
  the buffer.

  A buffer is a structure containing the buffered bytes in the field
  chars.  Further information contained in the structure are the size
  of the buffer, the point until which the buffer is filled. A current
  pointer in the buffer. The file descriptor associated with the file
  which the buffer represents (if any) and the name of that file.

*/

#ifndef _BUFFER
#define _BUFFER

struct BufferStruct {
  char *chars;
  int   size;
  int   fill;
  int   cur;
  int   fd;
  char *name;
};
typedef struct BufferStruct Buffer;

/* 
   The constant |MIN_FILL| indicates the minimal amount of space that
   should be available in the buffer before reading.
*/

#define MIN_FILL 1024
#define STDIN  0
#define STDOUT 1
#define STDERR 2

/* 
   A buffer is created by means of |init_buffer| and released by
   |free_buffer|.
*/

Buffer *init_buffer(void);
void free_buffer(Buffer *b);

/* 
   |buf_open| opens a file with name |name| and associates the
   resulting file descriptor with buffer |b|. |buf_read| reads the
   entire file indicated by the file descriptor in buffer |b| into
   |b->chars|.
*/

void buf_open(Buffer *b, char *name, int flags);
void buf_read(Buffer *b);
void buf_write(int fd, Buffer *b);
char buf_getc(Buffer *b);

#endif
