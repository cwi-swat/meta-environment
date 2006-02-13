# 1 "aterm.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "aterm.c"


# 1 "/usr/include/stdio.h" 1 3
# 28 "/usr/include/stdio.h" 3
# 1 "/usr/include/features.h" 1 3
# 291 "/usr/include/features.h" 3
# 1 "/usr/include/sys/cdefs.h" 1 3
# 292 "/usr/include/features.h" 2 3
# 314 "/usr/include/features.h" 3
# 1 "/usr/include/gnu/stubs.h" 1 3
# 315 "/usr/include/features.h" 2 3
# 29 "/usr/include/stdio.h" 2 3





# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 201 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 3
typedef unsigned int size_t;
# 35 "/usr/include/stdio.h" 2 3

# 1 "/usr/include/bits/types.h" 1 3
# 28 "/usr/include/bits/types.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 29 "/usr/include/bits/types.h" 2 3


# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 32 "/usr/include/bits/types.h" 2 3


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
# 63 "/usr/include/bits/types.h" 3
typedef struct
{
  long __val[2];
} __quad_t;
typedef struct
{
  __u_long __val[2];
} __u_quad_t;
# 128 "/usr/include/bits/types.h" 3
# 1 "/usr/include/bits/typesizes.h" 1 3
# 129 "/usr/include/bits/types.h" 2 3


typedef unsigned long long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef int __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long long int __fsfilcnt64_t;




typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef int __intptr_t;


typedef unsigned int __socklen_t;
# 37 "/usr/include/stdio.h" 2 3









typedef struct _IO_FILE FILE;





# 62 "/usr/include/stdio.h" 3
typedef struct _IO_FILE __FILE;
# 72 "/usr/include/stdio.h" 3
# 1 "/usr/include/libio.h" 1 3
# 32 "/usr/include/libio.h" 3
# 1 "/usr/include/_G_config.h" 1 3
# 14 "/usr/include/_G_config.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 294 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 3
typedef long int wchar_t;
# 321 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 3
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3
# 24 "/usr/include/_G_config.h" 3
# 1 "/usr/include/wchar.h" 1 3
# 48 "/usr/include/wchar.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 49 "/usr/include/wchar.h" 2 3

# 1 "/usr/include/bits/wchar.h" 1 3
# 51 "/usr/include/wchar.h" 2 3
# 71 "/usr/include/wchar.h" 3
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3
# 1 "/usr/include/gconv.h" 1 3
# 28 "/usr/include/gconv.h" 3
# 1 "/usr/include/wchar.h" 1 3
# 48 "/usr/include/wchar.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 49 "/usr/include/wchar.h" 2 3
# 29 "/usr/include/gconv.h" 2 3


# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 32 "/usr/include/gconv.h" 2 3





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            const unsigned char **, const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  const unsigned char *,
                                  const unsigned char **,
                                  const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, const unsigned char *,
                                          const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (const char *, const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  struct __gconv_step_data __data [1];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t ;
typedef int _G_int32_t ;
typedef unsigned int _G_uint16_t ;
typedef unsigned int _G_uint32_t ;
# 33 "/usr/include/libio.h" 2 3
# 53 "/usr/include/libio.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stdarg.h" 1 3
# 43 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3
# 162 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE;
# 172 "/usr/include/libio.h" 3
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 195 "/usr/include/libio.h" 3
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 263 "/usr/include/libio.h" 3
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 311 "/usr/include/libio.h" 3
  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 350 "/usr/include/libio.h" 3
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 402 "/usr/include/libio.h" 3
extern int __underflow (_IO_FILE *) ;
extern int __uflow (_IO_FILE *) ;
extern int __overflow (_IO_FILE *, int) ;
extern wint_t __wunderflow (_IO_FILE *) ;
extern wint_t __wuflow (_IO_FILE *) ;
extern wint_t __woverflow (_IO_FILE *, wint_t) ;
# 432 "/usr/include/libio.h" 3
extern int _IO_getc (_IO_FILE *__fp) ;
extern int _IO_putc (int __c, _IO_FILE *__fp) ;
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp) ;





extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
# 462 "/usr/include/libio.h" 3
extern int _IO_vfscanf (_IO_FILE * , const char * ,
                        __gnuc_va_list, int *) ;
extern int _IO_vfprintf (_IO_FILE *, const char *,
                         __gnuc_va_list) ;
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) ;
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) ;

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) ;
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) ;

extern void _IO_free_backup_area (_IO_FILE *) ;
# 73 "/usr/include/stdio.h" 2 3
# 86 "/usr/include/stdio.h" 3


typedef _G_fpos_t fpos_t;




# 138 "/usr/include/stdio.h" 3
# 1 "/usr/include/bits/stdio_lim.h" 1 3
# 139 "/usr/include/stdio.h" 2 3



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;









extern int remove (const char *__filename) ;

extern int rename (const char *__old, const char *__new) ;






extern FILE *tmpfile (void) ;
# 173 "/usr/include/stdio.h" 3
extern char *tmpnam (char *__s) ;

# 183 "/usr/include/stdio.h" 3
extern char *tmpnam_r (char *__s) ;
# 195 "/usr/include/stdio.h" 3
extern char *tempnam (const char *__dir, const char *__pfx)
     ;





extern int fclose (FILE *__stream) ;

extern int fflush (FILE *__stream) ;




extern int fflush_unlocked (FILE *__stream) ;
# 218 "/usr/include/stdio.h" 3



extern FILE *fopen (const char * __filename,
                    const char * __modes) ;

extern FILE *freopen (const char * __filename,
                      const char * __modes,
                      FILE * __stream) ;
# 241 "/usr/include/stdio.h" 3

# 252 "/usr/include/stdio.h" 3
extern FILE *fdopen (int __fd, const char *__modes) ;
# 273 "/usr/include/stdio.h" 3



extern void setbuf (FILE * __stream, char * __buf) ;



extern int setvbuf (FILE * __stream, char * __buf,
                    int __modes, size_t __n) ;





extern void setbuffer (FILE * __stream, char * __buf,
                       size_t __size) ;


extern void setlinebuf (FILE *__stream) ;





extern int fprintf (FILE * __stream,
                    const char * __format, ...) ;

extern int printf (const char * __format, ...) ;

extern int sprintf (char * __s,
                    const char * __format, ...) ;


extern int vfprintf (FILE * __s, const char * __format,
                     __gnuc_va_list __arg) ;

extern int vprintf (const char * __format, __gnuc_va_list __arg)
     ;

extern int vsprintf (char * __s, const char * __format,
                     __gnuc_va_list __arg) ;





extern int snprintf (char * __s, size_t __maxlen,
                     const char * __format, ...)
     ;

extern int vsnprintf (char * __s, size_t __maxlen,
                      const char * __format, __gnuc_va_list __arg)
     ;

# 351 "/usr/include/stdio.h" 3


extern int fscanf (FILE * __stream,
                   const char * __format, ...) ;

extern int scanf (const char * __format, ...) ;

extern int sscanf (const char * __s,
                   const char * __format, ...) ;

# 381 "/usr/include/stdio.h" 3


extern int fgetc (FILE *__stream) ;
extern int getc (FILE *__stream) ;


extern int getchar (void) ;








extern int getc_unlocked (FILE *__stream) ;
extern int getchar_unlocked (void) ;




extern int fgetc_unlocked (FILE *__stream) ;





extern int fputc (int __c, FILE *__stream) ;
extern int putc (int __c, FILE *__stream) ;


extern int putchar (int __c) ;








extern int fputc_unlocked (int __c, FILE *__stream) ;




extern int putc_unlocked (int __c, FILE *__stream) ;
extern int putchar_unlocked (int __c) ;





extern int getw (FILE *__stream) ;


extern int putw (int __w, FILE *__stream) ;





extern char *fgets (char * __s, int __n, FILE * __stream)
     ;



extern char *gets (char *__s) ;

# 477 "/usr/include/stdio.h" 3


extern int fputs (const char * __s, FILE * __stream)
     ;


extern int puts (const char *__s) ;



extern int ungetc (int __c, FILE *__stream) ;



extern size_t fread (void * __ptr, size_t __size,
                     size_t __n, FILE * __stream) ;

extern size_t fwrite (const void * __ptr, size_t __size,
                      size_t __n, FILE * __s) ;

# 506 "/usr/include/stdio.h" 3
extern size_t fread_unlocked (void * __ptr, size_t __size,
                              size_t __n, FILE * __stream) ;
extern size_t fwrite_unlocked (const void * __ptr, size_t __size,
                               size_t __n, FILE * __stream) ;





extern int fseek (FILE *__stream, long int __off, int __whence) ;

extern long int ftell (FILE *__stream) ;

extern void rewind (FILE *__stream) ;

# 546 "/usr/include/stdio.h" 3



extern int fgetpos (FILE * __stream, fpos_t * __pos)
     ;

extern int fsetpos (FILE *__stream, const fpos_t *__pos) ;
# 565 "/usr/include/stdio.h" 3

# 575 "/usr/include/stdio.h" 3


extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;




extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;





extern void perror (const char *__s) ;






# 1 "/usr/include/bits/sys_errlist.h" 1 3
# 27 "/usr/include/bits/sys_errlist.h" 3
extern int sys_nerr;
extern const char *const sys_errlist[];
# 602 "/usr/include/stdio.h" 2 3




extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;






extern FILE *popen (const char *__command, const char *__modes) ;


extern int pclose (FILE *__stream) ;





extern char *ctermid (char *__s) ;
# 655 "/usr/include/stdio.h" 3
extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;
# 679 "/usr/include/stdio.h" 3

# 4 "aterm.c" 2
# 1 "/usr/include/stdlib.h" 1 3
# 33 "/usr/include/stdlib.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 34 "/usr/include/stdlib.h" 2 3


# 93 "/usr/include/stdlib.h" 3


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;



# 137 "/usr/include/stdlib.h" 3
extern size_t __ctype_get_mb_cur_max (void) ;




extern double atof (const char *__nptr) ;

extern int atoi (const char *__nptr) ;

extern long int atol (const char *__nptr) ;

# 157 "/usr/include/stdlib.h" 3


extern double strtod (const char * __nptr,
                      char ** __endptr) ;

# 174 "/usr/include/stdlib.h" 3


extern long int strtol (const char * __nptr,
                        char ** __endptr, int __base) ;

extern unsigned long int strtoul (const char * __nptr,
                                  char ** __endptr, int __base)
     ;

# 264 "/usr/include/stdlib.h" 3
extern double __strtod_internal (const char * __nptr,
                                 char ** __endptr, int __group)
     ;
extern float __strtof_internal (const char * __nptr,
                                char ** __endptr, int __group)
     ;
extern long double __strtold_internal (const char * __nptr,
                                       char ** __endptr,
                                       int __group) ;

extern long int __strtol_internal (const char * __nptr,
                                   char ** __endptr,
                                   int __base, int __group) ;



extern unsigned long int __strtoul_internal (const char * __nptr,
                                             char ** __endptr,
                                             int __base, int __group) ;
# 408 "/usr/include/stdlib.h" 3
extern char *l64a (long int __n) ;


extern long int a64l (const char *__s) ;




# 1 "/usr/include/sys/types.h" 1 3
# 29 "/usr/include/sys/types.h" 3






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 62 "/usr/include/sys/types.h" 3
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 100 "/usr/include/sys/types.h" 3
typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3
# 1 "/usr/include/time.h" 1 3
# 74 "/usr/include/time.h" 3


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3
# 147 "/usr/include/sys/types.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 148 "/usr/include/sys/types.h" 2 3



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 163 "/usr/include/sys/types.h" 3
typedef char int8_t;
typedef short int int16_t;
typedef int int32_t;






typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;




typedef int register_t;
# 213 "/usr/include/sys/types.h" 3
# 1 "/usr/include/endian.h" 1 3
# 37 "/usr/include/endian.h" 3
# 1 "/usr/include/bits/endian.h" 1 3
# 38 "/usr/include/endian.h" 2 3
# 214 "/usr/include/sys/types.h" 2 3


# 1 "/usr/include/sys/select.h" 1 3
# 31 "/usr/include/sys/select.h" 3
# 1 "/usr/include/bits/select.h" 1 3
# 32 "/usr/include/sys/select.h" 2 3


# 1 "/usr/include/bits/sigset.h" 1 3
# 23 "/usr/include/bits/sigset.h" 3
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3
# 118 "/usr/include/time.h" 3
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3

# 1 "/usr/include/bits/time.h" 1 3
# 69 "/usr/include/bits/time.h" 3
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3







extern int select (int __nfds, fd_set * __readfds,
                   fd_set * __writefds,
                   fd_set * __exceptfds,
                   struct timeval * __timeout) ;
# 122 "/usr/include/sys/select.h" 3

# 217 "/usr/include/sys/types.h" 2 3


# 1 "/usr/include/sys/sysmacros.h" 1 3
# 220 "/usr/include/sys/types.h" 2 3
# 231 "/usr/include/sys/types.h" 3
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 266 "/usr/include/sys/types.h" 3
# 1 "/usr/include/bits/pthreadtypes.h" 1 3
# 23 "/usr/include/bits/pthreadtypes.h" 3
# 1 "/usr/include/bits/sched.h" 1 3
# 83 "/usr/include/bits/sched.h" 3
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3


struct _pthread_fastlock
{
  long int __status;
  int __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;







typedef long __pthread_cond_align_t;


typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
                 - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;
# 150 "/usr/include/bits/pthreadtypes.h" 3
typedef unsigned long int pthread_t;
# 267 "/usr/include/sys/types.h" 2 3



# 417 "/usr/include/stdlib.h" 2 3






extern long int random (void) ;


extern void srandom (unsigned int __seed) ;





extern char *initstate (unsigned int __seed, char *__statebuf,
                        size_t __statelen) ;



extern char *setstate (char *__statebuf) ;







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data * __buf,
                     int32_t * __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf) ;

extern int initstate_r (unsigned int __seed, char * __statebuf,
                        size_t __statelen,
                        struct random_data * __buf) ;

extern int setstate_r (char * __statebuf,
                       struct random_data * __buf) ;






extern int rand (void) ;

extern void srand (unsigned int __seed) ;




extern int rand_r (unsigned int *__seed) ;







extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;


extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3]) ;


extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3]) ;


extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3]) ;
extern void lcong48 (unsigned short int __param[7]) ;





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data * __buffer,
                      double * __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
                      struct drand48_data * __buffer,
                      double * __result) ;


extern int lrand48_r (struct drand48_data * __buffer,
                      long int * __result) ;
extern int nrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data * __buffer,
                      long int * __result) ;


extern int mrand48_r (struct drand48_data * __buffer,
                      long int * __result) ;
extern int jrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data * __buffer,
                      long int * __result) ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;

extern int seed48_r (unsigned short int __seed16v[3],
                     struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
                      struct drand48_data *__buffer) ;









extern void *malloc (size_t __size) ;

extern void *calloc (size_t __nmemb, size_t __size)
     ;







extern void *realloc (void *__ptr, size_t __size) ;

extern void free (void *__ptr) ;




extern void cfree (void *__ptr) ;



# 1 "/usr/include/alloca.h" 1 3
# 25 "/usr/include/alloca.h" 3
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 26 "/usr/include/alloca.h" 2 3







extern void *alloca (size_t __size) ;






# 579 "/usr/include/stdlib.h" 2 3




extern void *valloc (size_t __size) ;
# 592 "/usr/include/stdlib.h" 3


extern void abort (void) ;



extern int atexit (void (*__func) (void)) ;





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;






extern void exit (int __status) ;

# 624 "/usr/include/stdlib.h" 3


extern char *getenv (const char *__name) ;




extern char *__secure_getenv (const char *__name) ;





extern int putenv (char *__string) ;





extern int setenv (const char *__name, const char *__value, int __replace)
     ;


extern int unsetenv (const char *__name) ;






extern int clearenv (void) ;
# 663 "/usr/include/stdlib.h" 3
extern char *mktemp (char *__template) ;







extern int mkstemp (char *__template) ;
# 690 "/usr/include/stdlib.h" 3
extern char *mkdtemp (char *__template) ;





extern int system (const char *__command) ;

# 714 "/usr/include/stdlib.h" 3
extern char *realpath (const char * __name,
                       char * __resolved) ;






typedef int (*__compar_fn_t) (const void *, const void *);









extern void *bsearch (const void *__key, const void *__base,
                      size_t __nmemb, size_t __size, __compar_fn_t __compar);



extern void qsort (void *__base, size_t __nmemb, size_t __size,
                   __compar_fn_t __compar);



extern int abs (int __x) ;
extern long int labs (long int __x) ;












extern div_t div (int __numer, int __denom)
     ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     ;

# 778 "/usr/include/stdlib.h" 3
extern char *ecvt (double __value, int __ndigit, int * __decpt,
                   int * __sign) ;




extern char *fcvt (double __value, int __ndigit, int * __decpt,
                   int * __sign) ;




extern char *gcvt (double __value, int __ndigit, char *__buf) ;




extern char *qecvt (long double __value, int __ndigit,
                    int * __decpt, int * __sign) ;
extern char *qfcvt (long double __value, int __ndigit,
                    int * __decpt, int * __sign) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf) ;




extern int ecvt_r (double __value, int __ndigit, int * __decpt,
                   int * __sign, char * __buf,
                   size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int * __decpt,
                   int * __sign, char * __buf,
                   size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
                    int * __decpt, int * __sign,
                    char * __buf, size_t __len) ;
extern int qfcvt_r (long double __value, int __ndigit,
                    int * __decpt, int * __sign,
                    char * __buf, size_t __len) ;







extern int mblen (const char *__s, size_t __n) ;


extern int mbtowc (wchar_t * __pwc,
                   const char * __s, size_t __n) ;


extern int wctomb (char *__s, wchar_t __wchar) ;



extern size_t mbstowcs (wchar_t * __pwcs,
                        const char * __s, size_t __n) ;

extern size_t wcstombs (char * __s,
                        const wchar_t * __pwcs, size_t __n)
     ;








extern int rpmatch (const char *__response) ;
# 910 "/usr/include/stdlib.h" 3
extern int getloadavg (double __loadavg[], int __nelem) ;






# 5 "aterm.c" 2
# 1 "/usr/include/ctype.h" 1 3
# 30 "/usr/include/ctype.h" 3

# 48 "/usr/include/ctype.h" 3
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 81 "/usr/include/ctype.h" 3
extern const unsigned short int **__ctype_b_loc (void)
     ;
extern const __int32_t **__ctype_tolower_loc (void)
     ;
extern const __int32_t **__ctype_toupper_loc (void)
     ;
# 96 "/usr/include/ctype.h" 3






extern int isalnum (int) ;
extern int isalpha (int) ;
extern int iscntrl (int) ;
extern int isdigit (int) ;
extern int islower (int) ;
extern int isgraph (int) ;
extern int isprint (int) ;
extern int ispunct (int) ;
extern int isspace (int) ;
extern int isupper (int) ;
extern int isxdigit (int) ;



extern int tolower (int __c) ;


extern int toupper (int __c) ;


# 142 "/usr/include/ctype.h" 3
extern int isascii (int __c) ;



extern int toascii (int __c) ;



extern int _toupper (int) ;
extern int _tolower (int) ;
# 323 "/usr/include/ctype.h" 3

# 6 "aterm.c" 2
# 1 "/usr/include/string.h" 1 3
# 28 "/usr/include/string.h" 3





# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stddef.h" 1 3
# 34 "/usr/include/string.h" 2 3




extern void *memcpy (void * __dest,
                     const void * __src, size_t __n) ;


extern void *memmove (void *__dest, const void *__src, size_t __n)
     ;






extern void *memccpy (void * __dest, const void * __src,
                      int __c, size_t __n)
     ;





extern void *memset (void *__s, int __c, size_t __n) ;


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     ;


extern void *memchr (const void *__s, int __c, size_t __n)
      ;

# 80 "/usr/include/string.h" 3


extern char *strcpy (char * __dest, const char * __src)
     ;

extern char *strncpy (char * __dest,
                      const char * __src, size_t __n) ;


extern char *strcat (char * __dest, const char * __src)
     ;

extern char *strncat (char * __dest, const char * __src,
                      size_t __n) ;


extern int strcmp (const char *__s1, const char *__s2)
     ;

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     ;


extern int strcoll (const char *__s1, const char *__s2)
     ;

extern size_t strxfrm (char * __dest,
                       const char * __src, size_t __n) ;

# 126 "/usr/include/string.h" 3
extern char *strdup (const char *__s) ;
# 160 "/usr/include/string.h" 3


extern char *strchr (const char *__s, int __c) ;

extern char *strrchr (const char *__s, int __c) ;











extern size_t strcspn (const char *__s, const char *__reject)
     ;


extern size_t strspn (const char *__s, const char *__accept)
     ;

extern char *strpbrk (const char *__s, const char *__accept)
     ;

extern char *strstr (const char *__haystack, const char *__needle)
     ;



extern char *strtok (char * __s, const char * __delim)
     ;




extern char *__strtok_r (char * __s,
                         const char * __delim,
                         char ** __save_ptr) ;

extern char *strtok_r (char * __s, const char * __delim,
                       char ** __save_ptr) ;
# 228 "/usr/include/string.h" 3


extern size_t strlen (const char *__s) ;

# 241 "/usr/include/string.h" 3


extern char *strerror (int __errnum) ;




extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) ;




extern void __bzero (void *__s, size_t __n) ;



extern void bcopy (const void *__src, void *__dest, size_t __n) ;


extern void bzero (void *__s, size_t __n) ;


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     ;


extern char *index (const char *__s, int __c) ;


extern char *rindex (const char *__s, int __c) ;



extern int ffs (int __i) ;
# 287 "/usr/include/string.h" 3
extern int strcasecmp (const char *__s1, const char *__s2)
     ;


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     ;
# 309 "/usr/include/string.h" 3
extern char *strsep (char ** __stringp,
                     const char * __delim) ;
# 379 "/usr/include/string.h" 3

# 7 "aterm.c" 2
# 1 "/usr/include/assert.h" 1 3
# 65 "/usr/include/assert.h" 3



extern void __assert_fail (const char *__assertion, const char *__file,
                           unsigned int __line, const char *__function)
     ;


extern void __assert_perror_fail (int __errnum, const char *__file,
                                  unsigned int __line,
                                  const char *__function)
     ;




extern void __assert (const char *__assertion, const char *__file, int __line)
     ;



# 8 "aterm.c" 2

# 1 "_aterm.h" 1



# 1 "aterm2.h" 1
# 14 "aterm2.h"
# 1 "aterm1.h" 1
# 10 "aterm1.h"
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stdarg.h" 1 3
# 110 "/usr/lib/gcc-lib/i386-redhat-linux/3.2/include/stdarg.h" 3
typedef __gnuc_va_list va_list;
# 11 "aterm1.h" 2
# 1 "encoding.h" 1
# 43 "encoding.h"
typedef unsigned int header_type;
# 12 "aterm1.h" 2
# 1 "abool.h" 1
# 9 "abool.h"
typedef enum { ATfalse=0, ATtrue } ATbool;
# 13 "aterm1.h" 2
# 29 "aterm1.h"
typedef struct _ATerm
{
        header_type header;
        struct _ATerm *next;
} *ATerm;
# 43 "aterm1.h"
ATerm ATmake(const char *pattern, ...);
ATbool ATmatch(ATerm t, const char *pattern, ...);

ATerm ATmakeTerm(ATerm pat, ...);
ATbool ATmatchTerm(ATerm t, ATerm pat, ...);
ATerm ATvmake(const char *pat);
ATerm ATvmakeTerm(ATerm pat);
void AT_vmakeSetArgs(va_list *args);
ATbool ATvmatch(ATerm t, const char *pat);
ATbool ATvmatchTerm(ATerm t, ATerm pat);

ATerm ATreadFromTextFile(FILE *file);
ATerm ATreadFromSharedTextFile(FILE *f);
ATerm ATreadFromBinaryFile(FILE *file);
ATerm ATreadFromFile(FILE *file);
ATerm ATreadFromNamedFile(const char *name);
ATerm ATreadFromString(const char *string);
ATerm ATreadFromSharedString(char *s, int size);
ATerm ATreadFromBinaryString(char *s, int size);
# 70 "aterm1.h"
extern ATbool AT_isEqual(ATerm t1, ATerm t2);
extern ATbool AT_isDeepEqual(ATerm t1, ATerm t2);
# 84 "aterm1.h"
ATbool ATwriteToTextFile(ATerm t, FILE *file);
long ATwriteToSharedTextFile(ATerm t, FILE *f);
ATbool ATwriteToBinaryFile(ATerm t, FILE *file);
ATbool ATwriteToNamedTextFile(ATerm t, const char *name);
ATbool ATwriteToNamedBinaryFile(ATerm t, const char *name);
char *ATwriteToString(ATerm t);
char *ATwriteToSharedString(ATerm t, int *len);
char *ATwriteToBinaryString(ATerm t, int *len);
ATerm ATsetAnnotation(ATerm t, ATerm label, ATerm anno);
ATerm ATgetAnnotation(ATerm t, ATerm label);
ATerm ATremoveAnnotation(ATerm t, ATerm label);

void ATprotect(ATerm *atp);
void ATunprotect(ATerm *atp);
void ATprotectArray(ATerm *start, int size);
void ATunprotectArray(ATerm *start);







void ATinit(int argc, char *argv[], ATerm *bottomOfStack);
void ATinitialize(int argc, char *argv[]);
void ATsetWarningHandler(void (*handler)(const char *format, va_list args));
void ATsetErrorHandler(void (*handler)(const char *format, va_list args));
void ATsetAbortHandler(void (*handler)(const char *format, va_list args));
void ATwarning(const char *format, ...);
void ATerror(const char *format, ...);
void ATabort(const char *format, ...);
int ATprintf(const char *format, ...);
int ATfprintf(FILE *stream, const char *format, ...);
int ATvfprintf(FILE *stream, const char *format, va_list args);
# 15 "aterm2.h" 2
# 1 "afun.h" 1



# 1 "atypes.h" 1
# 11 "atypes.h"
typedef unsigned int ShortHashNumber;







typedef int MachineWord;
typedef unsigned int HashNumber;
# 5 "afun.h" 2
# 22 "afun.h"
typedef MachineWord AFun;


typedef struct _SymEntry
{
  header_type header;
  struct _SymEntry *next;
  AFun id;
  char *name;
  int count;
  int index;
} *SymEntry;
# 54 "afun.h"
struct _ATerm;
extern struct _ATerm **at_lookup_table_alias;
extern SymEntry *at_lookup_table;

unsigned int AT_symbolTableSize();
void AT_initSymbol(int argc, char *argv[]);
int AT_printSymbol(AFun sym, FILE *f);
ATbool AT_isValidSymbol(AFun sym);

ATbool AT_isMarkedSymbol(AFun sym);
void AT_freeSymbol(SymEntry sym);
void AT_markProtectedSymbols();


void AT_markProtectedSymbols_young();


unsigned int AT_hashSymbol(char *name, int arity);
ATbool AT_findSymbol(char *name, int arity, ATbool quoted);
void AT_unmarkAllAFuns();
# 16 "aterm2.h" 2
# 27 "aterm2.h"
typedef struct
{
        header_type header;
        ATerm next;
        int value;
} *ATermInt;

typedef struct
{
        header_type header;
        ATerm next;
        double value;
} *ATermReal;

typedef struct
{
        header_type header;
        ATerm next;
} *ATermAppl;

typedef struct _ATermList
{
        header_type header;
        ATerm next;
        ATerm head;
        struct _ATermList *tail;
} *ATermList;

typedef struct
{
        header_type header;
        ATerm next;
        ATerm ph_type;
} *ATermPlaceholder;

typedef struct
{
        header_type header;
        ATerm next;
        int size;
        void *data;
} *ATermBlob;

struct _ATermTable;

typedef struct _ATermTable *ATermIndexedSet;
typedef struct _ATermTable *ATermTable;
# 83 "aterm2.h"
ATermInt ATmakeInt(int value);




ATermReal ATmakeReal(double value);




ATermAppl ATmakeAppl(AFun sym, ...);
ATermAppl ATmakeAppl0(AFun sym);
ATermAppl ATmakeAppl1(AFun sym, ATerm arg0);
ATermAppl ATmakeAppl2(AFun sym, ATerm arg0, ATerm arg1);
ATermAppl ATmakeAppl3(AFun sym, ATerm arg0, ATerm arg1, ATerm arg2);
ATermAppl ATmakeAppl4(AFun sym, ATerm arg0, ATerm arg1, ATerm arg2,
                       ATerm arg3);
ATermAppl ATmakeAppl5(AFun sym, ATerm arg0, ATerm arg1, ATerm arg2,
                       ATerm arg4, ATerm arg5);
ATermAppl ATmakeAppl6(AFun sym, ATerm arg0, ATerm arg1, ATerm arg2,
                       ATerm arg4, ATerm arg5, ATerm arg6);







ATermAppl ATsetArgument(ATermAppl appl, ATerm arg, int n);


ATermList ATgetArguments(ATermAppl appl);
ATermAppl ATmakeApplList(AFun sym, ATermList args);
ATermAppl ATmakeApplArray(AFun sym, ATerm args[]);


extern ATermList ATempty;

ATermList ATmakeList(int n, ...);




ATermList ATmakeList1(ATerm el0);
# 150 "aterm2.h"
ATermList ATgetTail(ATermList list, int start);
ATermList ATreplaceTail(ATermList list, ATermList newtail, int start);
ATermList ATgetPrefix(ATermList list);
ATerm ATgetLast(ATermList list);
ATermList ATgetSlice(ATermList list, int start, int end);
ATermList ATinsert(ATermList list, ATerm el);
ATermList ATinsertAt(ATermList list, ATerm el, int index);
ATermList ATappend(ATermList list, ATerm el);
ATermList ATconcat(ATermList list1, ATermList list2);
int ATindexOf(ATermList list, ATerm el, int start);
int ATlastIndexOf(ATermList list, ATerm el, int start);
ATerm ATelementAt(ATermList list, int index);
ATermList ATremoveElement(ATermList list, ATerm el);
ATermList ATremoveElementAt(ATermList list, int idx);
ATermList ATremoveAll(ATermList list, ATerm el);
ATermList ATreplace(ATermList list, ATerm el, int idx);
ATermList ATreverse(ATermList list);
ATermList ATsort(ATermList list, int (*compare)(const ATerm t1, const ATerm t2));
int ATcompare(ATerm t1, ATerm t2);
ATerm ATdictCreate();
ATerm ATdictGet(ATerm dict, ATerm key);
ATerm ATdictPut(ATerm dict, ATerm key, ATerm value);
ATerm ATdictRemove(ATerm dict, ATerm key);

ATermTable ATtableCreate(long initial_size, int max_load_pct);
void ATtableDestroy(ATermTable table);
void ATtableReset(ATermTable table);
void ATtablePut(ATermTable table, ATerm key, ATerm value);
ATerm ATtableGet(ATermTable table, ATerm key);
void ATtableRemove(ATermTable table, ATerm key);
ATermList ATtableKeys(ATermTable table);
ATermList ATtableValues(ATermTable table);

ATermIndexedSet
           ATindexedSetCreate(long initial_size, int max_load_pct);
void ATindexedSetDestroy(ATermIndexedSet set);
void ATindexedSetReset(ATermIndexedSet set);
long ATindexedSetPut(ATermIndexedSet set, ATerm elem, ATbool *isnew);
long ATindexedSetGetIndex(ATermIndexedSet set, ATerm elem);
void ATindexedSetRemove(ATermIndexedSet set, ATerm elem);
ATermList ATindexedSetElements(ATermIndexedSet set);
ATerm ATindexedSetGetElem(ATermIndexedSet set, long index);


ATermList ATfilter(ATermList list, ATbool (*predicate)(ATerm));


ATermPlaceholder ATmakePlaceholder(ATerm type);




ATermBlob ATmakeBlob(int size, void *data);






void ATregisterBlobDestructor(ATbool (*destructor)(ATermBlob));
void ATunregisterBlobDestructor(ATbool (*destructor)(ATermBlob));

AFun ATmakeAFun(char *name, int arity, ATbool quoted);
# 222 "aterm2.h"
void ATprotectAFun(AFun sym);

void ATunprotectAFun(AFun sym);

void ATprotectMemory(void *start, int size);
void ATunprotectMemory(void *start);






ATerm AT_getAnnotations(ATerm t);
ATerm AT_setAnnotations(ATerm t, ATerm annos);
ATerm AT_removeAnnotations(ATerm t);


ATerm ATremoveAllAnnotations(ATerm t);




unsigned char *ATchecksum(ATerm t);
ATbool ATdiff(ATerm t1, ATerm t2, ATerm *templ, ATerm *diffs);
# 255 "aterm2.h"
int ATcompare(ATerm t1, ATerm t2);

void ATsetChecking(ATbool on);
ATbool ATgetChecking(void);


extern int at_gc_count;


int ATcalcUniqueSubterms(ATerm t);
int ATcalcUniqueSymbols(ATerm t);

int ATcalcTextSize(ATerm t);

void AT_writeToStringBuffer(ATerm t, char *buffer);
# 5 "_aterm.h" 2






typedef struct ProtEntry
{
        struct ProtEntry *next;
        ATerm *start;
        int size;
} ProtEntry;




extern ATbool silent;

extern ATbool low_memory;

extern ProtEntry **at_prot_table;
extern int at_prot_table_size;
extern ProtEntry *at_prot_memory;

void AT_markTerm(ATerm t);

void AT_markTerm_young(ATerm t);



void AT_unmarkTerm(ATerm t);
void AT_unmarkIfAllMarked(ATerm t);
void AT_unmarkAll();
int AT_calcTextSize(ATerm t);
int AT_calcCoreSize(ATerm t);
int AT_calcSubterms(ATerm t);
int AT_calcUniqueSubterms(ATerm t);
int AT_calcUniqueSymbols(ATerm t);
int AT_calcTermDepth(ATerm t);
void AT_assertUnmarked(ATerm t);
void AT_assertMarked(ATerm t);
int AT_calcAllocatedSize();
# 10 "aterm.c" 2
# 1 "memory.h" 1
# 43 "memory.h"
typedef struct Block
{

  header_type data[(1<<13)];

  int size;
  int frozen;
  struct Block *next_by_size;




  struct Block *next_before;
  struct Block *next_after;



  header_type *end;

} Block;

typedef struct BlockBucket
{
  struct Block *first_before;
  struct Block *first_after;
} BlockBucket;

extern Block *at_blocks[(256 +3)];

extern Block *at_old_blocks[(256 +3)];
extern header_type *top_at_blocks[(256 +3)];
extern Block *at_freeblocklist;
extern int at_freeblocklist_size;




extern int at_nrblocks[(256 +3)];
extern ATerm at_freelist[(256 +3)];



extern BlockBucket block_table[4099];


extern int nb_minor_since_last_major;
extern int old_bytes_in_young_blocks_after_last_major;
extern int old_bytes_in_old_blocks_after_last_major;
extern int old_bytes_in_young_blocks_since_last_major;
extern int nb_live_blocks_before_last_gc[(256 +3)];
extern int nb_reclaimed_blocks_during_last_gc[(256 +3)];
extern int nb_reclaimed_cells_during_last_gc[(256 +3)];


extern header_type *min_heap_address;
extern header_type *max_heap_address;




void AT_initMemory(int argc, char *argv[]);
void AT_cleanupMemory();
HashNumber AT_hashnumber(ATerm t);
ATerm AT_allocate(int size);
void AT_freeTerm(int size, ATerm t);
ATbool AT_isValidTerm(ATerm term);
ATerm AT_isInsideValidTerm(ATerm term);
void AT_validateFreeList(int size);
int AT_inAnyFreeList(ATerm t);
void AT_printAllTerms(FILE *file);
void AT_printAllAFunCounts(FILE *file);
# 11 "aterm.c" 2

# 1 "list.h" 1
# 9 "list.h"
void AT_initList(int argc, char *argv[]);
# 13 "aterm.c" 2
# 1 "make.h" 1
# 11 "make.h"
void AT_initMake(int argc, char *argv[]);
# 14 "aterm.c" 2
# 1 "gc.h" 1
# 12 "gc.h"
void AT_initGC(int argc, char *argv[], ATerm *bottomOfStack);
void AT_setBottomOfStack(ATerm *bottomOfStack);
void AT_cleanupGC();

void AT_collect_minor();

extern void AT_init_gc_parameters(ATbool low_memory);
extern int gc_min_number_of_blocks;
extern int max_freeblocklist_size;
extern int min_nb_minor_since_last_major;
extern int good_gc_ratio;
extern int small_allocation_rate_ratio;
extern int old_increase_rate_ratio;



void AT_collect();

extern AFun at_parked_symbol;
# 15 "aterm.c" 2
# 1 "util.h" 1
# 16 "aterm.c" 2
# 1 "bafio.h" 1
# 11 "bafio.h"
void AT_initBafIO(int argc, char *argv[]);
void AT_getBafVersion(int *major, int *minor);
ATbool AT_interpretBaf(FILE *input, FILE *output);
ATerm AT_readFromBinaryFile(FILE *f);
# 17 "aterm.c" 2
# 1 "version.h" 1
# 9 "version.h"
extern char *at_version;
extern char *at_date;
# 18 "aterm.c" 2

# 1 "tafio.h" 1
# 13 "tafio.h"
extern ATerm AT_readFromSharedTextFile(int *c, FILE *f);
# 20 "aterm.c" 2
# 1 "md5.h" 1
# 46 "md5.h"
typedef unsigned char *POINTER;


typedef unsigned short int UINT2;


typedef unsigned long int UINT4;
# 66 "md5.h"
typedef struct {
  UINT4 state[4];
  UINT4 count[2];
  unsigned char buffer[64];
} MD5_CTX;

void MD5Init ();
void MD5Update ();

void MD5Final ();
# 21 "aterm.c" 2
# 56 "aterm.c"
char aterm_id[] = "$Id$";



ATbool silent = ATtrue;
ATbool low_memory = ATfalse;





static void (*warning_handler) (const char *format, va_list args) = ((void *)0);

static void (*error_handler) (const char *format, va_list args) = ((void *)0);


static void (*abort_handler) (const char *format, va_list args) = ((void *)0);


static int buffer_size = 0;
static char *buffer = ((void *)0);


static int line = 0;
static int col = 0;
static char error_buf[32];
static int error_idx = 0;

ProtEntry *free_prot_entries = ((void *)0);
ProtEntry **at_prot_table = ((void *)0);
int at_prot_table_size = 0;
ProtEntry *at_prot_memory = ((void *)0);

static ATerm *mark_stack = ((void *)0);
static int mark_stack_size = 0;
int mark_stats[3] = {0, 0x7FFFFFFF, 0};







static ATerm fparse_term(int *c, FILE * f);
static ATerm sparse_term(int *c, char **s);
static ATerm AT_diff(ATerm t1, ATerm t2, ATermList *diffs);
# 111 "aterm.c"
void
AT_cleanup(void)
{
  AT_cleanupGC();
  AT_cleanupMemory();
}
# 129 "aterm.c"
void ATinitialize(int argc, char *argv[])
{
  ATerm bottom;

  ATinit(argc, argv, &bottom);
}
# 143 "aterm.c"
void
ATinit(int argc, char *argv[], ATerm * bottomOfStack)
{
  int lcv;
  static ATbool initialized = ATfalse;
  ATbool help = ATfalse;

  if (initialized)
    return;



  for (lcv=1; lcv < argc; lcv++) {
    if ((!(strcmp(argv[lcv],"-at-silent")))) {
      silent = ATtrue;
    } else if((!(strcmp(argv[lcv],"-at-verbose")))) {
      silent = ATfalse;

    } else if(0 || (!(strcmp(argv[lcv],"-at-low-memory")))) {
      low_memory = ATtrue;

    } else if((!(strcmp(argv[lcv],"-at-help")))) {
      help = ATtrue;
    }
  }





  AT_init_gc_parameters(low_memory);



  if (!silent)




  ATfprintf(stderr, "  ATerm Library, version %s, built: %s\n",
            at_version, at_date);


  if(help) {
    fprintf(stderr, "    %-20s: print this help info\n", "-at-help");
    fprintf(stderr, "    %-20s: generate runtime gc information.\n",
            "-at-verbose");
    fprintf(stderr, "    %-20s: suppress runtime gc information.\n",
            "-at-silent");

    fprintf(stderr, "    %-20s: try to minimize the memory usage.\n",
            "-at-low-memory");

  }





  if (bottomOfStack == ((void *)0))
    ATerror("ATinit: illegal bottomOfStack (arg 3) passed.\n");




  ((void) ((sizeof(header_type) == sizeof(ATerm *)) ? 0 : (__assert_fail ("sizeof(header_type) == sizeof(ATerm *)", "aterm.c", 208, ((const char *) 0)), 0)));
  ((void) ((sizeof(header_type) >= 4) ? 0 : (__assert_fail ("sizeof(header_type) >= 4", "aterm.c", 209, ((const char *) 0)), 0)));




  buffer_size = 4096;
  buffer = (char *) malloc(4096);
  if (!buffer)
    ATerror("ATinit: cannot allocate string buffer of size %d\n",
            4096);




  at_prot_table_size = 100003;
  at_prot_table = (ProtEntry **)calloc(at_prot_table_size, sizeof(ProtEntry *));
  if(!at_prot_table)
    ATerror("ATinit: cannot allocate space for prot-table of size %d\n",
            at_prot_table_size);





  mark_stack = (ATerm *) malloc(sizeof(ATerm) * 16384);
  if (!mark_stack)
    ATerror("cannot allocate marks stack of %d entries.\n",
            16384);
  mark_stack_size = 16384;





  AT_initMemory(argc, argv);
  AT_initSymbol(argc, argv);
  AT_initList(argc, argv);
  AT_initMake(argc, argv);
  AT_initGC(argc, argv, bottomOfStack);
  AT_initBafIO(argc, argv);



  initialized = ATtrue;

  atexit(AT_cleanup);

  if(help) {
    fprintf(stderr, "\n");
    exit(0);
  }
}
# 269 "aterm.c"
void
ATsetWarningHandler(void (*handler) (const char *format, va_list args))
{
  warning_handler = handler;
}
# 282 "aterm.c"
void
ATsetErrorHandler(void (*handler) (const char *format, va_list args))
{
  error_handler = handler;
}
# 295 "aterm.c"
void
ATsetAbortHandler(void (*handler) (const char *format, va_list args))
{
  abort_handler = handler;
}




void
ATwarning(const char *format,...)
{
  va_list args;

  __builtin_stdarg_start((args),format);
  if (warning_handler) {
    warning_handler(format, args);
  }
  else {
    ATvfprintf(stderr, format, args);
  }

  __builtin_va_end(args);
}
# 327 "aterm.c"
void
ATerror(const char *format,...)
{
  va_list args;

  __builtin_stdarg_start((args),format);
  if (error_handler)
    error_handler(format, args);
  else
  {
    ATvfprintf(stderr, format, args);
    exit(1);
  }

  __builtin_va_end(args);
}
# 351 "aterm.c"
void
ATabort(const char *format,...)
{
  va_list args;

  __builtin_stdarg_start((args),format);
  if (abort_handler)
    abort_handler(format, args);
  else
  {
    ATvfprintf(stderr, format, args);
    abort();
  }

  __builtin_va_end(args);
}
# 376 "aterm.c"
void
ATprotect(ATerm * term)
{
  ATprotectArray(term, 1);
}
# 389 "aterm.c"
void
ATunprotect(ATerm * term)
{
  a = b;
  ATunprotectArray(term);
}
# 402 "aterm.c"
void ATprotectArray(ATerm *start, int size)
{
  ProtEntry *entry;
  ShortHashNumber hnr;


  int i;
  for(i=0; i<size; i++) {
    ((void) ((start[i] == ((void *)0) || AT_isValidTerm(start[i])) ? 0 : (__assert_fail ("start[i] == ((void *)0) || AT_isValidTerm(start[i])", "aterm.c", 411, ((const char *) 0)), 0)));

  }


  if(!free_prot_entries) {
    int i;
    ProtEntry *entries = (ProtEntry *)calloc(100000,
                                             sizeof(ProtEntry));
    int a;
    if(!entries)
      ATerror("out of memory in ATprotect.\n");
    for(i=0; i<100000; i++) {
      entries[i].next = free_prot_entries;
      free_prot_entries = &entries[i];
    }
  }
  entry = free_prot_entries;
  free_prot_entries = free_prot_entries->next;
  hnr = (((ShortHashNumber)(start)) >> 2);

  hnr %= at_prot_table_size;
  entry->next = at_prot_table[hnr];
  at_prot_table[hnr] = entry;
  entry->start = start;
  entry->size = size;
}
# 444 "aterm.c"
void ATunprotectArray(ATerm *start)
{
  ShortHashNumber hnr;
  ProtEntry *entry, *prev;
  int a;

  hnr = (((ShortHashNumber)(start)) >> 2);
  hnr %= at_prot_table_size;
  entry = at_prot_table[hnr];

  prev = ((void *)0);
  while(entry->start != start) {
    prev = entry;
    entry = entry->next;
    ((void) ((entry) ? 0 : (__assert_fail ("entry", "aterm.c", 457, ((const char *) 0)), 0)));
  }

  if(prev)
    prev->next = entry->next;
  else
    at_prot_table[hnr] = entry->next;

  entry->next = free_prot_entries;
  free_prot_entries = entry;
}




void AT_printAllProtectedTerms(FILE *file)
{
  int i, j;

  fprintf(file, "protected terms:\n");
  for(i=0; i<at_prot_table_size; i++) {
    ProtEntry *cur = at_prot_table[i];
    int a;
    while(cur) {
      for(j=0; j<cur->size; j++) {
        if(cur->start[j]) {
          ATfprintf(file, "%t\n", i, cur->start[j]);
          fflush(file);
        }
      }
    }
  }
}




void ATprotectMemory(void *start, int size)
{
  ProtEntry *entry = (ProtEntry *)malloc(sizeof(ProtEntry));
  int a;
  if (entry == ((void *)0)) {
    ATerror("out of memory in ATprotectMemory.\n");
  }
 
  entry->start = (ATerm *)start;
  entry->size = size;
  entry->next = at_prot_memory;
  at_prot_memory = entry;
}




void ATunprotectMemory(void *start)
{
  ProtEntry *entry, *prev;
  int a;
  prev = ((void *)0);
  for (entry=at_prot_memory; entry; entry=entry->next) {
    if (entry->start == start) {
      if (prev) {
        prev->next = entry->next;
      } else {
        at_prot_memory = entry->next;
      }
      free(entry);
      break;
    }
    prev = entry;
  }
}
# 535 "aterm.c"
int
ATprintf(const char *format,...)
{
  int result = 0;
  va_list args;

  __builtin_stdarg_start((args),format);
  result = ATvfprintf(stdout, format, args);
  __builtin_va_end(args);

  return result;
}
# 555 "aterm.c"
int
ATfprintf(FILE * stream, const char *format,...)
{
  int result = 0;
  va_list args;

  __builtin_stdarg_start((args),format);
  result = ATvfprintf(stream, format, args);
  __builtin_va_end(args);

  return result;
}



int
ATvfprintf(FILE * stream, const char *format, va_list args)
{
  const char *p;
  char *s;
  char fmt[16];
  int result = 0;
  ATerm t;
  ATermList l;

  for (p = format; *p; p++)
  {
    if (*p != '%')
    {
      fputc(*p, stream);
      continue;
    }

    s = fmt;
    while (!((*__ctype_b_loc ())[(int) (((int) *p))] & (unsigned short int) _ISalpha))
      *s++ = *p++;
    *s++ = *p;
    *s = '\0';

    switch (*p)
    {
      case 'c':
      case 'd':
      case 'i':
      case 'o':
      case 'u':
      case 'x':
      case 'X':
        fprintf(stream, fmt, __builtin_va_arg(args, int));
        break;

      case 'e':
      case 'E':
      case 'f':
      case 'g':
      case 'G':
        fprintf(stream, fmt, __builtin_va_arg(args, double));
        break;

      case 'p':
        fprintf(stream, fmt, __builtin_va_arg(args, void *));
        break;

      case 's':
        fprintf(stream, fmt, __builtin_va_arg(args, char *));
        break;






      case 't':
        ATwriteToTextFile(__builtin_va_arg(args, ATerm), stream);
        break;
      case 'l':
        l = __builtin_va_arg(args, ATermList);
        fmt[strlen(fmt) - 1] = '\0';
        while (!((ATbool)(((ATermList)(l))->head == ((void *)0) && ((ATermList)(l))->tail == ((void *)0))))
        {
          ATwriteToTextFile(((l)->head), stream);




          l = ((l)->tail);
          if (!((ATbool)(((ATermList)(l))->head == ((void *)0) && ((ATermList)(l))->tail == ((void *)0))))
            fputs(fmt + 1, stream);
        }
        break;
      case 'a':
      case 'y':
        AT_printSymbol(__builtin_va_arg(args, AFun), stream);
        break;
      case 'n':
        t = __builtin_va_arg(args, ATerm);
        switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7))
        {
          case 2:
          case 3:
          case 6:
            ATwriteToTextFile(t, stream);
            break;

          case 5:
            fprintf(stream, "<...>");
            break;

          case 4:
            fprintf(stream, "[...(%d)]", ((int)((((ATermList) t)->header) >> 10)));
            break;

          case 1:
            if (AT_isValidSymbol((((t)->header) >> 10))) {
              AT_printSymbol((((t)->header) >> 10), stream);
              fprintf(stream, "(...(%d))",
                      ((unsigned int)(((t->header) & ((1<<4) | (1<<5) | (1<<6))) >> 4)));
            } else {
              fprintf(stream, "<sym>(...(%d))",
                      ((unsigned int)(((t->header) & ((1<<4) | (1<<5) | (1<<6))) >> 4)));
            }
            if (((t->header) & (1<<3))) {
              fprintf(stream, "{}");
            }
            break;
          case 0:
            fprintf(stream, "@");
            break;
          default:
            fprintf(stream, "#");
            break;
        }
        break;

      case 'h':
        {
          unsigned char *digest = ATchecksum(__builtin_va_arg(args, ATerm));
          int i;
          for (i=0; i<16; i++) {
            fprintf(stream, "%02x", digest[i]);
          }
        }
        break;


      default:
        fputc(*p, stream);
        break;
    }
  }
  return result;
}
# 716 "aterm.c"
static void
resize_buffer(int n)
{
  buffer_size = n;
  buffer = (char *) realloc(buffer, buffer_size);
  if (!buffer)
    ATerror("resize_buffer(aterm.c): cannot allocate string buffer of size %d\n", buffer_size);
}
# 733 "aterm.c"
ATbool
writeToTextFile(ATerm t, FILE * f)
{
  AFun sym;
  ATerm arg;
  int i, arity, size;
  ATermAppl appl;
  ATermList list;
  ATermBlob blob;
  char *name;

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7))
  {
    case 2:
      fprintf(f, "%d", ((ATermInt) t)->value);
      break;
    case 3:
      fprintf(f, "%.15e", ((ATermReal) t)->value);
      break;
    case 1:


      appl = (ATermAppl) t;

      sym = (((appl)->header) >> 10);
      AT_printSymbol(sym, f);
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      name = (at_lookup_table[(sym)]->name);
      if (arity > 0 || (!(((at_lookup_table_alias[(sym)]->header) & (1<<3)) ? ATtrue : ATfalse) && *name == '\0')) {
        fputc('(', f);
        for (i = 0; i < arity; i++) {
          if (i != 0) {
            fputc(',', f);
          }
          arg = (*((ATerm *)(appl) + 2 + (i)));
          ATwriteToTextFile(arg, f);
        }
        fputc(')', f);
      }


      break;
    case 4:


      list = (ATermList) t;
      if(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0)))) {
        ATwriteToTextFile(((list)->head), f);
        list = ((list)->tail);
      }
      while(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0)))) {
        fputc(',', f);
        ATwriteToTextFile(((list)->head), f);
        list = ((list)->tail);
      }


      break;
    case 5:


      fputc('<', f);
      ATwriteToTextFile((((ATermPlaceholder) t)->ph_type), f);
      fputc('>', f);


      break;
    case 6:


      blob = (ATermBlob) t;
      size = ((blob)->size);
      fprintf(f, "\"%c%-.*d%c", 0xFF, 12, size, 0xFF);
      fwrite(((blob)->data), ((blob)->size), 1, f);
      fputc('"', f);


      break;

    case 0:
      if(AT_inAnyFreeList(t))
        ATerror("ATwriteToTextFile: printing free term at %p!\n", t);
      else
        ATerror("ATwriteToTextFile: free term %p not in freelist?\n", t);
      return ATfalse;

    case 7:
      ATerror("ATwriteToTextFile: not a term but an afun: %y\n", t);
      return ATfalse;
  }

  return ATtrue;
}

ATbool
ATwriteToTextFile(ATerm t, FILE * f)
{
  ATbool result = ATtrue;
  ATerm annos;

  if (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7) == 4) {
    fputc('[', f);

    if (!((ATbool)(((ATermList)((ATermList) t))->head == ((void *)0) && ((ATermList)((ATermList) t))->tail == ((void *)0))))
      result = writeToTextFile(t, f);

    fputc(']', f);
  } else {
    result = writeToTextFile(t, f);
  }

  annos = (ATerm) AT_getAnnotations(t);
  if (annos) {
    fputc('{', f);
    result &= writeToTextFile(annos, f);
    fputc('}', f);
  }

  return result;
}
# 862 "aterm.c"
ATbool ATwriteToNamedTextFile(ATerm t, const char *name)
{
  FILE *f;
  ATbool result;

  if(!strcmp(name, "-")) {
    return ATwriteToTextFile(t, stdout);
  }

  if(!(f = fopen(name, "wb"))) {
    return ATfalse;
  }

  result = ATwriteToTextFile(t, f);
  fclose(f);

  return result;
}
# 895 "aterm.c"
static int
symbolTextSize(AFun sym)
{
  char *id = (at_lookup_table[(sym)]->name);

  if ((((at_lookup_table_alias[(sym)]->header) & (1<<3)) ? ATtrue : ATfalse))
  {
    int len = 2;
    while (*id)
    {

      switch (*id)
      {
        case '\\':
        case '"':
        case '\n':
        case '\t':
        case '\r':
          len += 2;
          break;
        default:
          len++;
      }
      id++;
    }
    return len;
  }
  else
    return strlen(id);
}
# 933 "aterm.c"
static char *
writeSymbolToString(AFun sym, char *buf)
{
  char *id = (at_lookup_table[(sym)]->name);

  if ((((at_lookup_table_alias[(sym)]->header) & (1<<3)) ? ATtrue : ATfalse))
  {
    *buf++ = '"';
    while (*id)
    {

      switch (*id)
      {
        case '\\':
        case '"':
          *buf++ = '\\';
          *buf++ = *id;
          break;
        case '\n':
          *buf++ = '\\';
          *buf++ = 'n';
          break;
        case '\t':
          *buf++ = '\\';
          *buf++ = 't';
          break;
        case '\r':
          *buf++ = '\\';
          *buf++ = 'r';
          break;
        default:
          *buf++ = *id;
      }
      id++;
    }
    *buf++ = '"';
    return buf;
  }
  else
  {
    strcpy(buf, id);
    return buf + strlen(buf);
  }
}




static char *topWriteToString(ATerm t, char *buf);

static char *
writeToString(ATerm t, char *buf)
{
  ATerm trm;
  ATermList list;
  ATermAppl appl;
  ATermBlob blob;
  AFun sym;
  int i, size, arity;
  char *name;

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7))
  {
    case 2:


      sprintf(buf, "%d", (((ATermInt) t)->value));
      buf += strlen(buf);


      break;

    case 3:


      sprintf(buf, "%.15e", (((ATermReal) t)->value));
      buf += strlen(buf);


      break;

    case 1:


      appl = (ATermAppl) t;
      sym = (((appl)->header) >> 10);
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      name = (at_lookup_table[(sym)]->name);
      buf = writeSymbolToString(sym, buf);
      if (arity > 0 || (!(((at_lookup_table_alias[(sym)]->header) & (1<<3)) ? ATtrue : ATfalse) && *name == '\0')) {
        *buf++ = '(';
        if (arity > 0) {
          buf = topWriteToString((*((ATerm *)(appl) + 2 + (0))), buf);
          for (i = 1; i < arity; i++) {
            *buf++ = ',';
            buf = topWriteToString((*((ATerm *)(appl) + 2 + (i))), buf);
          }
        }
        *buf++ = ')';
      }


      break;

    case 4:


      list = (ATermList) t;
      if (!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))))
      {
        buf = topWriteToString(((list)->head), buf);
        list = ((list)->tail);
        while (!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))))
        {
          *buf++ = ',';
          buf = topWriteToString(((list)->head), buf);
          list = ((list)->tail);
        }
      }


      break;

    case 5:


      trm = (((ATermPlaceholder) t)->ph_type);
      buf = topWriteToString(trm, buf);


      break;

    case 6:


      blob = (ATermBlob) t;
      size = ((blob)->size);
      sprintf(buf, "\"%c%-.*d%c", 0xFF, 12, size, 0xFF);
      buf += 1 + 2 + 12;

      memcpy(buf, ((blob)->data), size);
      buf += size;

      *buf++ = '"';


      break;
  }
  return buf;
}

static char *
topWriteToString(ATerm t, char *buf)
{
  ATerm annos = AT_getAnnotations(t);

  if (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7) == 4) {
    *buf++ = '[';
    buf = writeToString(t, buf);
    *buf++ = ']';
  } else if (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7) == 5) {
    *buf++ = '<';
    buf = writeToString(t, buf);
    *buf++ = '>';
  } else {
    buf = writeToString(t, buf);
  }

  if (annos) {
    *buf++ = '{';
    buf = writeToString(annos, buf);
    *buf++ = '}';
  }

  return buf;
}
# 1117 "aterm.c"
static int topTextSize(ATerm t);

static int
textSize(ATerm t)
{
  char numbuf[32];
  ATerm trm;
  ATermList list;
  ATermAppl appl;
  AFun sym;
  int i, size, arity;
  char *name;

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7))
  {
    case 2:
      sprintf(numbuf, "%d", (((ATermInt) t)->value));
      size = strlen(numbuf);
      break;

    case 3:
      sprintf(numbuf, "%.15e", (((ATermReal) t)->value));
      size = strlen(numbuf);
      break;

    case 1:
      appl = (ATermAppl) t;
      sym = (((appl)->header) >> 10);
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      name = (at_lookup_table[(sym)]->name);
      size = symbolTextSize(sym);
      for (i = 0; i < arity; i++) {
        size += topTextSize((*((ATerm *)(appl) + 2 + (i))));
      }
      if (arity > 0 || (!(((at_lookup_table_alias[(sym)]->header) & (1<<3)) ? ATtrue : ATfalse) && *name == '\0')) {

        if (arity > 1) {
          size += arity - 1;
        }

        size += 2;
      }
      break;

    case 4:
      list = (ATermList) t;
      if (((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))))
        size = 0;
      else
      {
        size = ((int)(((list)->header) >> 10)) - 1;

        while (!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))))
        {
          size += topTextSize(((list)->head));
          list = ((list)->tail);
        }
      }
      break;

    case 5:
      trm = (((ATermPlaceholder) t)->ph_type);
      size = topTextSize(trm);
      break;

    case 6:
      size = 12 + 4 + (((ATermBlob) t)->size);
      break;

    default:
      ATerror("textSize: Illegal type %d\n", ((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7));
      return -1;
  }
  return size;
}

static int
topTextSize(ATerm t)
{
  ATerm annos = AT_getAnnotations(t);
  int size = textSize(t);

  if (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7) == 4 || ((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7) == 5) {
    size += 2;
  }

  if (annos) {
    size += 2;
    size += textSize(annos);
  }

  return size;
}

int
AT_calcTextSize(ATerm t)
{
  return topTextSize(t);
}







char *
ATwriteToString(ATerm t)
{
  int size = topTextSize(t)+1;
  char *end;

  if(size > buffer_size) resize_buffer(size);

  end = topWriteToString(t, buffer);
  *end++ = '\0';

  ((void) ((end - buffer == size) ? 0 : (__assert_fail ("end - buffer == size", "aterm.c", 1234, ((const char *) 0)), 0)));

  return buffer;
}






void
AT_writeToStringBuffer(ATerm t, char *buffer)
{
  topWriteToString(t, buffer);
}




int ATcalcTextSize(ATerm t)
{
  return AT_calcTextSize(t);
}
# 1266 "aterm.c"
static void
store_char(int c, int pos)
{
  if (pos >= buffer_size)
    resize_buffer(buffer_size * 2);

  buffer[pos] = c;
}
# 1282 "aterm.c"
static void
fnext_char(int *c, FILE * f)
{
  *c = fgetc(f);
  if(*c != (-1)) {
    if (*c == '\n')
    {
      line++;
      col = 0;
    }
    else
    {
      col++;
    }
    error_buf[error_idx++] = *c;
    error_idx %= 32;
  }
}
# 1308 "aterm.c"
static void
fskip_layout(int *c, FILE * f)
{
  while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace))
    fnext_char(c, f);
}
# 1322 "aterm.c"
static void
fnext_skip_layout(int *c, FILE * f)
{
  do
  {
    fnext_char(c, f);
  } while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
}
# 1339 "aterm.c"
ATermList
fparse_terms(int *c, FILE * f)
{
  ATermList list;
  ATerm el = fparse_term(c, f);

  if(el == ((void *)0)) {
    return ((void *)0);
  }

  list = ATinsert(ATempty, el);

  while(*c == ',') {
    fnext_skip_layout(c, f);
    el = fparse_term(c, f);
    if(el == ((void *)0)) {
      return ((void *)0);
    }
    list = ATinsert(list, el);
  }

  return ATreverse(list);
}




static ATerm fparse_blob(int *c, FILE *f)
{
  char lenspec[12 +2];
  int len;
  char *data;

  if (fread(lenspec, 1, 12 +1, f) != 12 +1) {
    return ((void *)0);
  }

  if (lenspec[12] != ((char)0xFF)) {
    return ((void *)0);
  }

  lenspec[12] = '\0';

  len = atoi(lenspec);

  data = (char *)malloc(len);
  if (!data) {
    ATerror("out of memory in fparse_blob\n");
  }
  if (fread(data, 1, len, f) != len) {
    return ((void *)0);
  }

  fnext_char(c, f);
  if (*c != '"') {
    return ((void *)0);
  }

  fnext_skip_layout(c, f);

  return (ATerm)ATmakeBlob(len, data);
}
# 1409 "aterm.c"
static ATerm
fparse_quoted_appl(int *c, FILE * f)
{
  int len = 0;
  ATermList args = ATempty;
  AFun sym;
  char *name;


  fnext_char(c, f);

  if (*c == 0xFF) {
    return fparse_blob(c, f);
  }

  while (*c != '"') {
    switch (*c) {
      case (-1):
        return ((void *)0);
      case '\\':
        fnext_char(c, f);
        if (*c == (-1))
          return ((void *)0);
        switch (*c) {
          case 'n':
            store_char('\n', len++);
            break;
          case 'r':
            store_char('\r', len++);
            break;
          case 't':
            store_char('\t', len++);
            break;
          default:
            store_char(*c, len++);
            break;
        }
        break;
      default:
        store_char(*c, len++);
        break;
    }
    fnext_char(c, f);
  }

  store_char('\0', len);

  name = strdup(buffer);
  if (!name)
    ATerror("fparse_quoted_appl: symbol too long.");

  fnext_skip_layout(c, f);


  if (*c == '(') {
    fnext_skip_layout(c, f);
    if(*c != ')') {
      args = fparse_terms(c, f);
    } else {
      args = ATempty;
    }
    if (args == ((void *)0) || *c != ')')
      return ((void *)0);
    fnext_skip_layout(c, f);
  }


  sym = ATmakeAFun(name, ((int)(((args)->header) >> 10)), ATtrue);
  free(name);
  return (ATerm)ATmakeApplList(sym, args);
}
# 1488 "aterm.c"
static ATermAppl
fparse_unquoted_appl(int *c, FILE * f)
{
  int len = 0;
  AFun sym;
  ATermList args = ATempty;
  char *name = ((void *)0);

  if (*c != '(') {

    while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISalnum)
           || *c == '-' || *c == '_' || *c == '+' || *c == '*' || *c == '$')
    {
      store_char(*c, len++);
      fnext_char(c, f);
    }
    store_char('\0', len++);
    name = strdup(buffer);
    if (!name) {
      ATerror("fparse_unquoted_appl: symbol too long.");
    }

    fskip_layout(c, f);
  }


  if (*c == '(') {
    fnext_skip_layout(c, f);
    if(*c != ')') {
      args = fparse_terms(c, f);
    } else {
      args = ATempty;
    }
    if (args == ((void *)0) || *c != ')') {
      return ((void *)0);
    }
    fnext_skip_layout(c, f);
  }


  sym = ATmakeAFun(name ? name : "", ((int)(((args)->header) >> 10)), ATfalse);
  if (name != ((void *)0)) {
    a = b;
    free(name);
  }

  return ATmakeApplList(sym, args);
}
# 1543 "aterm.c"
static ATerm
fparse_num(int *c, FILE * f)
{
  char num[32], *ptr = num, *numend = num + 30;

  if (*c == '-')
  {
    *ptr++ = *c;
    fnext_char(c, f);
  }

  while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit) && ptr < numend)
  {
    *ptr++ = *c;
    fnext_char(c, f);
  }
  if (*c == '.' || toupper(*c) == 'E')
  {


    if (*c == '.')
    {
      *ptr++ = *c;
      fnext_char(c, f);
      while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit) && ptr < numend)
      {
        *ptr++ = *c;
        fnext_char(c, f);
      }
    }
    if (toupper(*c) == 'E' && ptr < numend)
    {
      *ptr++ = *c;
      fnext_char(c, f);
      if (*c == '-' || *c == '+')
      {
        *ptr++ = *c;
        fnext_char(c, f);
      }
      while (ptr < numend && ((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit))
      {
        *ptr++ = *c;
        fnext_char(c, f);
      }
    }
    *ptr = '\0';
    return (ATerm) ATmakeReal(atof(num));


  }
  else
  {


    *ptr = '\0';
    return (ATerm) ATmakeInt(atoi(num));


  }
}
# 1611 "aterm.c"
static ATerm
fparse_term(int *c, FILE * f)
{
  ATerm t, result = ((void *)0);

  switch (*c)
  {
    case '"':
      result = (ATerm) fparse_quoted_appl(c, f);
      break;
    case '[':
      fnext_skip_layout(c, f);
      if (*c == ']')
        result = (ATerm) ATempty;
      else
      {
        result = (ATerm) fparse_terms(c, f);
        if (result == ((void *)0) || *c != ']')
          return ((void *)0);
      }
      fnext_skip_layout(c, f);
      break;
    case '<':
      fnext_skip_layout(c, f);
      t = fparse_term(c, f);
      if (t != ((void *)0) && *c == '>')
      {
        result = (ATerm) ATmakePlaceholder(t);
        fnext_skip_layout(c, f);
      }
      break;
    default:
      if (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISalpha) || *c == '(') {
        result = (ATerm) fparse_unquoted_appl(c, f);
      }
      else if (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit)) {
        result = fparse_num(c, f);
      }
      else if (*c == '.' || *c == '-') {
        result = fparse_num(c, f);
      }
      else {
        result = ((void *)0);
      }
  }

  if(result != ((void *)0)) {
    fskip_layout(c, f);

    if (*c == '{') {

      fnext_skip_layout(c, f);
      if (*c != '}') {
        ATerm annos = (ATerm) fparse_terms(c, f);
        if (annos == ((void *)0) || *c != '}')
          return ((void *)0);
        result = AT_setAnnotations(result, annos);
      }
      fnext_skip_layout(c, f);
    }


    if (*c == ':') {
      ATerm type;
      fnext_skip_layout(c, f);
      type = fparse_term(c, f);
      if (type != ((void *)0)) {
        result = ATsetAnnotation(result, ATreadFromString(("type")), type);
      } else {
        return ((void *)0);
      }
    }

    if (*c == '?') {
      fnext_skip_layout(c, f);
      result = ATsetAnnotation(result, ATreadFromString(("result")), ATreadFromString(("true")));
    }


  }

  return result;
}
# 1703 "aterm.c"
ATerm
readFromTextFile(int *c, FILE *file)
{
  ATerm term;
  fskip_layout(c, file);

  term = fparse_term(c, file);

  if (term)
  {
    ungetc(*c, file);
  }
  else
  {
    int i;
    fprintf(stderr, "readFromTextFile: parse error at line %d, col %d%s",
            line, col, (line||col)?":\n":"");
    for (i = 0; i < 32; ++i)
    {
      char c = error_buf[(i + error_idx) % 32];
      if (c)
        fprintf(stderr, "%c", c);
    }
    fprintf(stderr, "\n");
    fflush(stderr);
  }

  return term;
}
# 1740 "aterm.c"
ATerm
ATreadFromTextFile(FILE * file)
{
  int c;

  line = 0;
  col = 0;
  error_idx = 0;
  memset(error_buf, 0, 32);

  fnext_char(&c, file);
  return readFromTextFile(&c, file);
}
# 1761 "aterm.c"
ATerm ATreadFromFile(FILE *file)
{
  int c;

  fnext_char(&c, file);
  if(c == 0) {

    return ATreadFromBinaryFile(file);
  } else if (c == '!') {

    return AT_readFromSharedTextFile(&c, file);
  } else {

    line = 0;
    col = 0;
    error_idx = 0;
    memset(error_buf, 0, 32);

    return readFromTextFile(&c, file);
  }
}
# 1790 "aterm.c"
ATerm ATreadFromNamedFile(const char *name)
{
  FILE *f;
  ATerm t;

  if(!strcmp(name, "-"))
    return ATreadFromFile(stdin);

  if(!(f = fopen(name, "rb")))
    return ((void *)0);

  t = ATreadFromFile(f);
  fclose(f);

  return t;
}
# 1820 "aterm.c"
ATermList
sparse_terms(int *c, char **s)
{
  ATermList list;
  ATerm el = sparse_term(c, s);

  if(el == ((void *)0)) {
    return ((void *)0);
  }

  list = ATinsert(ATempty, el);

  while(*c == ',') {
    do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
    el = sparse_term(c, s);
    if(el == ((void *)0)) {
      return ((void *)0);
    }
    list = ATinsert(list, el);
  }

  return ATreverse(list);
}




static ATerm sparse_blob(int *c, char **s)
{
  char *lenspec;
  int len;
  char *data;
  ATermBlob blob;

  lenspec = *s;
  len = atoi(lenspec);
  if (lenspec[12] != (char)0xFF) {
    return ((void *)0);
  }

  *s += (12 +1);

  data = malloc(len);
  if (!data) {
    ATerror("out of memory in sparse_blob (%d)\n", len);
  }
  memcpy(data, *s, len);

  blob = ATmakeBlob(len, data);

  *s += len;

  ((*c) = ((unsigned char)*(*s)++));
  if (*c != '"') {
    return ((void *)0);
  }

  ((*c) = ((unsigned char)*(*s)++));

  return (ATerm)blob;
}
# 1889 "aterm.c"
static ATerm
sparse_quoted_appl(int *c, char **s)
{
  int len = 0;
  ATermList args = ATempty;
  AFun sym;
  char *name;


  ((*c) = ((unsigned char)*(*s)++));

  if (*c == 0xFF) {
    return sparse_blob(c, s);
  }

  while (*c != '"')
  {
    switch (*c)
    {
      case (-1):




        return ((void *)0);
      case '\\':
        ((*c) = ((unsigned char)*(*s)++));
        if (*c == (-1))
          return ((void *)0);
        switch (*c)
        {
          case 'n':
            store_char('\n', len++);
            break;
          case 'r':
            store_char('\r', len++);
            break;
          case 't':
            store_char('\t', len++);
            break;
          default:
            store_char(*c, len++);
            break;
        }
        break;
      default:
        store_char(*c, len++);
        break;
    }
    ((*c) = ((unsigned char)*(*s)++));
  }

  store_char('\0', len);

  name = strdup(buffer);
  if (!name)
    ATerror("fparse_quoted_appl: symbol too long.");

  do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));


  if (*c == '(')
  {
    do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
    if(*c != ')') {
      args = sparse_terms(c, s);
    } else {
      args = ATempty;
    }
    if (args == ((void *)0) || *c != ')')
      return ((void *)0);
    do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
  }


  sym = ATmakeAFun(name, ((int)(((args)->header) >> 10)), ATtrue);
  free(name);
  return (ATerm)ATmakeApplList(sym, args);
}
# 1976 "aterm.c"
static ATermAppl
sparse_unquoted_appl(int *c, char **s)
{
  int len = 0;
  AFun sym;
  ATermList args = ATempty;
  char *name = ((void *)0);

  if (*c != '(') {

    while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISalnum)
           || *c == '-' || *c == '_' || *c == '+' || *c == '*' || *c == '$')
    {
      store_char(*c, len++);
      ((*c) = ((unsigned char)*(*s)++));
    }
    store_char('\0', len);
    name = strdup(buffer);
    if (!name) {
      ATerror("sparse_unquoted_appl: symbol too long.");
    }

    while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace)) ((*c) = ((unsigned char)*(*s)++));
  }


  if (*c == '(') {
    do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
    if(*c != ')') {
      args = sparse_terms(c, s);
    } else {
      args = ATempty;
    }
    if (args == ((void *)0) || *c != ')')
      return ((void *)0);
    do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
  }


  sym = ATmakeAFun(name ? name : "", ((int)(((args)->header) >> 10)), ATfalse);
  if (name != ((void *)0)) {
    a = b;
    free(name);
  }

  return ATmakeApplList(sym, args);
}
# 2030 "aterm.c"
static ATerm
sparse_num(int *c, char **s)
{
  char num[32], *ptr = num;

  if (*c == '-')
  {
    *ptr++ = *c;
    ((*c) = ((unsigned char)*(*s)++));
  }

  while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit))
  {
    *ptr++ = *c;
    ((*c) = ((unsigned char)*(*s)++));
  }
  if (*c == '.' || toupper(*c) == 'E')
  {


    if (*c == '.')
    {
      *ptr++ = *c;
      ((*c) = ((unsigned char)*(*s)++));
      while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit))
      {
        *ptr++ = *c;
        ((*c) = ((unsigned char)*(*s)++));
      }
    }
    if (toupper(*c) == 'E')
    {
      *ptr++ = *c;
      ((*c) = ((unsigned char)*(*s)++));
      if (*c == '-' || *c == '+')
      {
        *ptr++ = *c;
        ((*c) = ((unsigned char)*(*s)++));
      }
      while (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit))
      {
        *ptr++ = *c;
        ((*c) = ((unsigned char)*(*s)++));
      }
    }
    *ptr = '\0';
    return (ATerm) ATmakeReal(atof(num));


  }
  else
  {


    *ptr = '\0';
    return (ATerm) ATmakeInt(atoi(num));


  }
}
# 2099 "aterm.c"
static ATerm
sparse_term(int *c, char **s)
{
  ATerm t, result = ((void *)0);

  switch (*c)
  {
    case '"':
      result = (ATerm) sparse_quoted_appl(c, s);
      break;
    case '[':
      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      if (*c == ']')
        result = (ATerm) ATempty;
      else
      {
        result = (ATerm) sparse_terms(c, s);
        if (result == ((void *)0) || *c != ']')
          return ((void *)0);
      }
      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      break;
    case '<':
      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      t = sparse_term(c, s);
      if (t != ((void *)0) && *c == '>')
      {
        result = (ATerm) ATmakePlaceholder(t);
        do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      }
      break;
    default:
      if (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISalpha) || *c == '(') {
        result = (ATerm) sparse_unquoted_appl(c, s);
      }
      else if (((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISdigit)) {
        result = sparse_num(c, s);
      }
      else if (*c == '.' || *c == '-') {
        result = sparse_num(c, s);
      }
      else {
        result = ((void *)0);
      }
  }

  if(result != ((void *)0)) {
    while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace)) ((*c) = ((unsigned char)*(*s)++));

    if (*c == '{') {



      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      if (*c != '}') {
        ATerm annos = (ATerm) sparse_terms(c, s);
        if (annos == ((void *)0) || *c != '}')
          return ((void *)0);
        result = AT_setAnnotations(result, annos);
      }
      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));


    }



    if (*c == ':') {
      ATerm type;
      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      type = sparse_term(c, s);
      if (type != ((void *)0)) {
        result = ATsetAnnotation(result, ATreadFromString(("type")), type);
      } else {
        return ((void *)0);
      }
    }

    if (*c == '?') {
      do { ((*c) = ((unsigned char)*(*s)++)); } while(((*__ctype_b_loc ())[(int) ((*c))] & (unsigned short int) _ISspace));
      result = ATsetAnnotation(result, ATreadFromString(("result")), ATreadFromString(("true")));
    }


  }

  return result;
}
# 2195 "aterm.c"
ATerm
ATreadFromString(const char *string)
{
  int c;
  const char *orig = string;
  ATerm term;

  do { ((*&c) = ((unsigned char)*(*(char **) &string)++)); } while(((*__ctype_b_loc ())[(int) ((*&c))] & (unsigned short int) _ISspace));

  term = sparse_term(&c, (char **) &string);

  if (term == ((void *)0))
  {
    int i;
    fprintf(stderr, "ATreadFromString: parse error at or near:\n");
    fprintf(stderr, "%s\n", orig);
    for (i = 1; i < string - orig; ++i)
      fprintf(stderr, " ");
    fprintf(stderr, "^\n");
  }
  else
    string--;

  return term;
}
# 2228 "aterm.c"
void AT_markTerm(ATerm t)
{
  int i, arity;
  AFun sym;
  ATerm *current = mark_stack + 1;
  ATerm *limit = mark_stack + mark_stack_size - 256;
  int a;



  mark_stack[0] = ((void *)0);
  *current++ = t;

  while (ATtrue) {
    if (current >= limit) {
      int current_index;



      current_index = current - mark_stack;


      mark_stack_size = mark_stack_size * 2;
      mark_stack = (ATerm *) realloc(mark_stack, sizeof(ATerm) * mark_stack_size);
      if (!mark_stack)
        ATerror("cannot realloc mark stack to %d entries.\n", mark_stack_size);
      limit = mark_stack + mark_stack_size - 256;
      if(!silent) {
        fprintf(stderr, "resized mark stack to %d entries\n", mark_stack_size);
      }
      fflush(stderr);

      current = mark_stack + current_index;



    }






    t = *--current;

    if (!t) {
      if(current != mark_stack) {
        ATabort("AT_markTerm: premature end of mark_stack.\n");
      }
      break;
    }

    if ((((t->header) & (1<<2)) ? ATtrue : ATfalse))
      continue;

    ((t->header) |= (1<<2));




    (((t->header) = (((t->header) & ~((1<<0) | (1<<1))) | ((((((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0))<3)?(((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0))+1):(((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0))))) << 0))));


    if(((t->header) & (1<<3)))
      *current++ = AT_getAnnotations(t);

    switch ((((t->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
      case 2:
      case 3:
      case 6:
        break;

      case 1:
        sym = ((((ATermAppl) t)->header) >> 10);


        if(AT_isValidSymbol(sym)) {
          (at_lookup_table[(sym)]->header |= (((1<<0) | (1<<1))|(1<<2)));
        } else {
          continue;
        }
# 2319 "aterm.c"
        arity = ((unsigned int)(((t->header) & ((1<<4) | (1<<5) | (1<<6))) >> 4));
        if (arity > 6) {
          arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
        }
        for (i = 0; i < arity; i++) {
          ATerm arg = (*((ATerm *)((ATermAppl) t) + 2 + (i)));
          *current++ = arg;
        }
        break;

      case 4:
        if (!((ATbool)(((ATermList)((ATermList) t))->head == ((void *)0) && ((ATermList)((ATermList) t))->tail == ((void *)0)))) {
          *current++ = (ATerm) (((ATermList) t)->tail);
          *current++ = (((ATermList) t)->head);
        }
        break;

      case 5:
        *current++ = (((ATermPlaceholder) t)->ph_type);
        break;
    }
  }




}


void AT_markTerm_young(ATerm t) {
  int i, arity;
  AFun sym;
  ATerm *current = mark_stack + 1;
  ATerm *limit = mark_stack + mark_stack_size - 256;
  int a;



  if((((t->header) & (1<<2)) ? ATtrue : ATfalse) || (((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0)) == 3)) {

    return;
  }

  mark_stack[0] = ((void *)0);
  *current++ = t;

  while (ATtrue) {
    if (current >= limit) {
      int current_index;




      current_index = current - mark_stack;

      mark_stack_size = mark_stack_size * 2;
      mark_stack = (ATerm *) realloc(mark_stack, sizeof(ATerm) * mark_stack_size);
      if (!mark_stack)
        ATerror("cannot realloc mark stack to %d entries.\n", mark_stack_size);
      limit = mark_stack + mark_stack_size - 256;
      if(!silent) {
        fprintf(stderr, "resized mark stack to %d entries\n", mark_stack_size);
      }
      fflush(stderr);

      current = mark_stack + current_index;



    }






    t = *--current;

    if (!t) {
      if(current != mark_stack) {
        ATabort("AT_markTerm: premature end of mark_stack.\n");
      }
      break;
    }

    if((((t->header) & (1<<2)) ? ATtrue : ATfalse) || (((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0)) == 3)) {

      continue;
    }

    ((t->header) |= (1<<2));


    (((t->header) = (((t->header) & ~((1<<0) | (1<<1))) | ((((((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0))<3)?(((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0))+1):(((unsigned int)(((t->header) & ((1<<0) | (1<<1))) >> 0))))) << 0))));

    if(((t->header) & (1<<3)))
      *current++ = AT_getAnnotations(t);

    switch ((((t->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
      case 2:
      case 3:
      case 6:
        break;

      case 1:
        sym = ((((ATermAppl) t)->header) >> 10);

        if(AT_isValidSymbol(sym)) {
          if(!(((unsigned int)(((at_lookup_table[(sym)]->header) & ((1<<0) | (1<<1))) >> 0)) == 3)) (at_lookup_table[(sym)]->header |= (((1<<0) | (1<<1))|(1<<2)));
        } else {
          continue;
        }

        arity = ((unsigned int)(((t->header) & ((1<<4) | (1<<5) | (1<<6))) >> 4));
        if (arity > 6) {
          arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
        }
        for (i = 0; i < arity; i++) {
          ATerm arg = (*((ATerm *)((ATermAppl) t) + 2 + (i)));
          *current++ = arg;
        }

        break;

      case 4:
        if (!((ATbool)(((ATermList)((ATermList) t))->head == ((void *)0) && ((ATermList)((ATermList) t))->tail == ((void *)0)))) {
          *current++ = (ATerm) (((ATermList) t)->tail);
          *current++ = (((ATermList) t)->head);
        }
        break;

      case 5:
        *current++ = (((ATermPlaceholder) t)->ph_type);
        break;
    }
  }




}
# 2473 "aterm.c"
void
AT_unmarkTerm(ATerm t)
{
  int i, arity;
  AFun sym;
  ATerm *current = mark_stack + 1;
  ATerm *limit = mark_stack + mark_stack_size - 256;
  ATerm *depth = mark_stack;
  int a;

  mark_stack[0] = ((void *)0);
  *current++ = t;

  while (ATtrue) {
    if (current > limit) {
      int current_index, depth_index;

      current_index = current - mark_stack;
      depth_index = depth - mark_stack;


      mark_stack_size = mark_stack_size * 2;
      mark_stack = (ATerm *) realloc(mark_stack, sizeof(ATerm) * mark_stack_size);
      if (!mark_stack)
        ATerror("cannot realloc mark stack to %d entries.\n", mark_stack_size);
      limit = mark_stack + mark_stack_size - 256;
      if(!silent) {
        fprintf(stderr, "resized mark stack to %d entries\n", mark_stack_size);
      }

      current = mark_stack + current_index;
      depth = mark_stack + depth_index;
    }

    if (current > depth)
      depth = current;

    t = *--current;

    if (!t)
      break;

    ((t->header) &= ~(1<<2));

    if(((t->header) & (1<<3)))
      *current++ = AT_getAnnotations(t);

    switch ((((t->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
      case 2:
      case 3:
      case 6:
        break;

      case 1:
        sym = ((((ATermAppl) t)->header) >> 10);
        (at_lookup_table[(sym)]->header &= ~(1<<2));
        arity = ((unsigned int)(((t->header) & ((1<<4) | (1<<5) | (1<<6))) >> 4));
        if (arity > 6)
          arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
        for (i = 0; i < arity; i++)
          *current++ = (*((ATerm *)((ATermAppl) t) + 2 + (i)));
        break;

      case 4:
        if (!((ATbool)(((ATermList)((ATermList) t))->head == ((void *)0) && ((ATermList)((ATermList) t))->tail == ((void *)0)))) {
          *current++ = (ATerm) (((ATermList) t)->tail);
          *current++ = (((ATermList) t)->head);
        }
        break;

      case 5:
        *current++ = (((ATermPlaceholder) t)->ph_type);
        break;
    }
  }
}




void AT_unmarkIfAllMarked(ATerm t)
{
  if((((t->header) & (1<<2)) ? ATtrue : ATfalse)) {

    ((t->header) &= ~(1<<2));
    switch(((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
      case 2:
      case 3:
      case 6:
        break;

      case 5:
        AT_unmarkIfAllMarked((((ATermPlaceholder)t)->ph_type));
        break;

      case 4:
        {
          ATermList list = (ATermList)t;
          while(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0)))) {
            ((list->header) &= ~(1<<2));
            AT_unmarkIfAllMarked(((list)->head));
            list = ((list)->tail);
            if (!(((list->header) & (1<<2)) ? ATtrue : ATfalse)) {
              break;
            }
          }
          ((list->header) &= ~(1<<2));
        }
        break;
      case 1:
        {
          ATermAppl appl = (ATermAppl)t;
          int cur_arity, cur_arg;
          AFun sym;

          sym = (((appl)->header) >> 10);
          (at_lookup_table[(sym)]->header &= ~(1<<2));
          cur_arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
          for(cur_arg=0; cur_arg<cur_arity; cur_arg++) {
            AT_unmarkIfAllMarked((*((ATerm *)(appl) + 2 + (cur_arg))));
          }
        }
        break;
      default:
        ATerror("collect_terms: illegal term\n");
        break;
    }

    if(((t->header) & (1<<3))) {
      a =b;
      AT_unmarkIfAllMarked(AT_getAnnotations(t));
    }
  }
  else {

  }
}




void AT_unmarkAll()
{
  int size;

  for (size=1; size<(256 +3); size++) {
    int last = (1<<13) - ((1<<13) % size) - size;
    Block *block = at_blocks[size];
    int a;
    while (block) {
      int idx;
      ATerm data = (ATerm)block->data;
      for (idx=0; idx <= last; idx += size) {
        ((((ATerm)(((header_type *)data)+idx))->header) &= ~(1<<2));
      }
      block = block->next_by_size;
    }
  }

  AT_unmarkAllAFuns();
}
# 2641 "aterm.c"
static int
calcCoreSize(ATerm t)
{
  int i, arity, size = 0;
  AFun sym;

  if ((((t->header) & (1<<2)) ? ATtrue : ATfalse))
    return size;

  ((t->header) |= (1<<2));

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 2:
      size = 12;
      break;

    case 3:
    case 6:
      size = 16;
      break;

    case 1:
      sym = ((((ATermAppl) t)->header) >> 10);
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      size = 8 + arity * 4;
      if (!AT_isMarkedSymbol(sym)) {
        size += strlen((at_lookup_table[(sym)]->name)) + 1;
        size += sizeof(struct _SymEntry);
        (at_lookup_table[(sym)]->header |= (((1<<0) | (1<<1))|(1<<2)));
      }
      for (i = 0; i < arity; i++)
        size += calcCoreSize((*((ATerm *)((ATermAppl) t) + 2 + (i))));
      break;

    case 4:
      size = 16;
      while (!((ATbool)(((ATermList)((ATermList) t))->head == ((void *)0) && ((ATermList)((ATermList) t))->tail == ((void *)0)))) {
        size += 16;
        size += calcCoreSize((((ATermList) t)->head));
        t = (ATerm)(((ATermList)t)->tail);
      }
      break;

    case 5:
      size = 12;
      size += calcCoreSize((((ATermPlaceholder) t)->ph_type));
      break;
  }

  if(((t->header) & (1<<3)))
    size += calcCoreSize(AT_getAnnotations(t));

  return size;
}
# 2703 "aterm.c"
int
AT_calcCoreSize(ATerm t)
{
  int result = calcCoreSize(t);
  a = b;
  AT_unmarkTerm(t);
  return result;
}
# 2719 "aterm.c"
int AT_calcSubterms(ATerm t)
{
  int i, arity, nr_subterms = 0;
  AFun sym;
  ATermList list;

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 2:
    case 3:
    case 6:
    case 5:
      nr_subterms = 1;
      break;

    case 1:
      nr_subterms = 1;
      sym = ((((ATermAppl) t)->header) >> 10);
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      for (i = 0; i < arity; i++)
        nr_subterms += AT_calcSubterms((*((ATerm *)((ATermAppl)t) + 2 + (i))));
      break;

    case 4:
      list = (ATermList)t;
      while(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0)))) {
        nr_subterms += AT_calcSubterms(((list)->head)) + 1;
        list = ((list)->tail);
      }
      break;
  }

  if(((t->header) & (1<<3)))
    nr_subterms += AT_calcSubterms(AT_getAnnotations(t));

  return nr_subterms;
}
# 2764 "aterm.c"
static int
calcUniqueSubterms(ATerm t)
{
  int i, arity, nr_unique = 0;
  AFun sym;
  ATermList list;

  if ((((t->header) & (1<<2)) ? ATtrue : ATfalse))
    return 0;

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 2:
    case 3:
    case 6:
    case 5:
      nr_unique = 1;
      break;

    case 1:
      nr_unique = 1;
      sym = ((((ATermAppl) t)->header) >> 10);
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      for (i = 0; i < arity; i++)
        nr_unique += calcUniqueSubterms((*((ATerm *)((ATermAppl)t) + 2 + (i))));
      break;

    case 4:
      list = (ATermList)t;
      while(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))) && !(((list->header) & (1<<2)) ? ATtrue : ATfalse)) {
        nr_unique += calcUniqueSubterms(((list)->head)) + 1;
        ((list->header) |= (1<<2));
        list = ((list)->tail);
      }
      if (((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))) && !(((list->header) & (1<<2)) ? ATtrue : ATfalse)) {
        ((list->header) |= (1<<2));
        nr_unique++;
      }
      break;
  }

  if(((t->header) & (1<<3)))
    nr_unique += calcUniqueSubterms(AT_getAnnotations(t));

  ((t->header) |= (1<<2));

  return nr_unique;
}
# 2819 "aterm.c"
int
AT_calcUniqueSubterms(ATerm t)
{
  int result;

  result = calcUniqueSubterms(t);
  
  AT_unmarkIfAllMarked(t);
  return result;
}




int ATcalcUniqueSubterms(ATerm t)
{
  return AT_calcUniqueSubterms(t);
}
# 2843 "aterm.c"
static int calcUniqueSymbols(ATerm t)
{
  int i, arity, nr_unique = 0;
  AFun sym;
  ATermList list;

  if ((((t->header) & (1<<2)) ? ATtrue : ATfalse))
    return 0;

  switch (((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 2:
      if (!at_lookup_table[0]->count++)
        nr_unique = 1;
      break;
    case 3:
      if (!at_lookup_table[1]->count++)
        nr_unique = 1;
      break;
    case 6:
      if (!at_lookup_table[2]->count++)
        nr_unique = 1;
      break;
    case 5:
      if (!at_lookup_table[3]->count++)
        nr_unique = 1;
      nr_unique += calcUniqueSymbols((((ATermPlaceholder)t)->ph_type));
      break;

    case 1:
      sym = ((((ATermAppl) t)->header) >> 10);
      nr_unique = AT_isMarkedSymbol(sym) ? 0 : 1;
      ((void) ((at_lookup_table[sym]) ? 0 : (__assert_fail ("at_lookup_table[sym]", "aterm.c", 2874, ((const char *) 0)), 0)));
      at_lookup_table[sym]->count++;
      (at_lookup_table[(sym)]->header |= (((1<<0) | (1<<1))|(1<<2)));
      arity = ((at_lookup_table_alias[(sym)]->header) >> 10);
      for (i = 0; i < arity; i++) {
        nr_unique += calcUniqueSymbols((*((ATerm *)((ATermAppl)t) + 2 + (i))));
      }
      break;

    case 4:
      list = (ATermList)t;
      while(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))) && !(((list->header) & (1<<2)) ? ATtrue : ATfalse)) {
        ((list->header) |= (1<<2));
        if (!at_lookup_table[4]->count++)
          nr_unique++;
        nr_unique += calcUniqueSymbols(((list)->head));
        list = ((list)->tail);
      }
      if(((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0))) && !(((list->header) & (1<<2)) ? ATtrue : ATfalse)) {
        ((list->header) |= (1<<2));
        if (!at_lookup_table[5]->count++)
          nr_unique++;
      }
      break;
  }

  if(((t->header) & (1<<3))) {
    if (!at_lookup_table[6]->count++)
      nr_unique++;
    nr_unique += calcUniqueSymbols(AT_getAnnotations(t));
  }

  ((t->header) |= (1<<2));

  return nr_unique;
}
# 2918 "aterm.c"
int
AT_calcUniqueSymbols(ATerm t)
{
  int result = calcUniqueSymbols(t);

  a = b;
  AT_unmarkIfAllMarked(t);


  return result;
}





int ATcalcUniqueSymbols(ATerm t)
{
  return AT_calcUniqueSymbols(t);
}





void AT_assertUnmarked(ATerm t)
{
  ATermAppl appl;
  AFun sym;
  int i;

  ((void) ((!(((t->header) & (1<<2)) ? ATtrue : ATfalse)) ? 0 : (__assert_fail ("!(((t->header) & (1<<2)) ? ATtrue : ATfalse)", "aterm.c", 2947, ((const char *) 0)), 0)));
  switch(((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 1:
      appl = (ATermAppl)t;
      sym = (((appl)->header) >> 10);
      ((void) ((!AT_isMarkedSymbol(sym)) ? 0 : (__assert_fail ("!AT_isMarkedSymbol(sym)", "aterm.c", 2952, ((const char *) 0)), 0)));
      for(i=0; i<((at_lookup_table_alias[(sym)]->header) >> 10); i++)
        AT_assertUnmarked((*((ATerm *)(appl) + 2 + (i))));
      break;

    case 4:
      if((ATermList)t != ATempty) {
        AT_assertUnmarked((((ATermList)t)->head));
        AT_assertUnmarked((ATerm)(((ATermList)t)->tail));
      }
      break;

    case 5:
      AT_assertUnmarked((((ATermPlaceholder)t)->ph_type));
      break;
  }

  if(((t->header) & (1<<3)))
    AT_assertUnmarked(AT_getAnnotations(t));
}




void AT_assertMarked(ATerm t)
{
  ATermAppl appl;
  AFun sym;
  int i;

  ((void) (((((t->header) & (1<<2)) ? ATtrue : ATfalse)) ? 0 : (__assert_fail ("(((t->header) & (1<<2)) ? ATtrue : ATfalse)", "aterm.c", 2982, ((const char *) 0)), 0)));
  switch(((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 1:
      appl = (ATermAppl)t;
      sym = (((appl)->header) >> 10);
      ((void) ((AT_isMarkedSymbol(sym)) ? 0 : (__assert_fail ("AT_isMarkedSymbol(sym)", "aterm.c", 2987, ((const char *) 0)), 0)));
      for(i=0; i<((at_lookup_table_alias[(sym)]->header) >> 10); i++)
        AT_assertMarked((*((ATerm *)(appl) + 2 + (i))));
      break;

    case 4:
      if((ATermList)t != ATempty) {
        AT_assertMarked((((ATermList)t)->head));
        AT_assertMarked((ATerm)(((ATermList)t)->tail));
      }
      break;

    case 5:
      AT_assertMarked((((ATermPlaceholder)t)->ph_type));
      break;
  }

  if(((t->header) & (1<<3)))
    AT_assertMarked(AT_getAnnotations(t));

}
# 3017 "aterm.c"
int AT_calcTermDepth(ATerm t)
{
  int arity, i, maxdepth = 0, depth = 0;
  ATermAppl appl;
  ATermList list;

  if(((t->header) & (1<<3)))
    maxdepth = AT_calcTermDepth(AT_getAnnotations(t));

  switch(((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 2:
    case 3:
    case 6:
      return ((1) > (maxdepth) ? (1) : (maxdepth));

    case 1:
      appl = (ATermAppl)t;
      arity = ((at_lookup_table_alias[((((appl)->header) >> 10))]->header) >> 10);
      for(i=0; i<arity; i++) {
        depth = AT_calcTermDepth((*((ATerm *)(appl) + 2 + (i))));
        if(depth > maxdepth)
          maxdepth = depth;
      }
      return maxdepth+1;

    case 4:
      list = (ATermList)t;
      while(!((ATbool)(((ATermList)(list))->head == ((void *)0) && ((ATermList)(list))->tail == ((void *)0)))) {
        depth = AT_calcTermDepth(((list)->head));
        if(depth > maxdepth)
          maxdepth = depth;
        list = ((list)->tail);
      }
      return maxdepth+1;

    case 5:
      return 1+((AT_calcTermDepth((((ATermPlaceholder)t)->ph_type))) > (maxdepth) ? (AT_calcTermDepth((((ATermPlaceholder)t)->ph_type))) : (maxdepth));


    default:
      ATerror("Trying to calculate the depth of a free term.\n");
      return 0;
  }
}
# 3070 "aterm.c"
unsigned char *ATchecksum(ATerm t)
{
  MD5_CTX context;
  static unsigned char digest[16];
  char *buf;
  int len;

  MD5Init(&context);
  buf = ATwriteToSharedString(t, &len);
  MD5Update(&context, buf, len);
  MD5Final(digest, &context);

  return digest;
}





static ATermList AT_diffList(ATermList l1, ATermList l2, ATermList *diffs)
{
  ATermList result = ATempty;
  ATerm el1, el2;

  while (!((ATbool)(((ATermList)(l1))->head == ((void *)0) && ((ATermList)(l1))->tail == ((void *)0)))) {
    if (((ATbool)(((ATermList)(l2))->head == ((void *)0) && ((ATermList)(l2))->tail == ((void *)0)))) {
      if (*diffs) {
        *diffs = ATinsert(*diffs, ATmake("diff(<term>,[])", l1));
      }
      return ATreverse(ATinsert(result, ATreadFromString(("<diff-lists>"))));
    }
    el1 = ((l1)->head);
    el2 = ((l2)->head);
    result = ATinsert(result, AT_diff(el1, el2, diffs));

    l1 = ((l1)->tail);
    l2 = ((l2)->tail);
  }

  if (!((ATbool)(((ATermList)(l2))->head == ((void *)0) && ((ATermList)(l2))->tail == ((void *)0)))) {
    if (*diffs) {
      *diffs = ATinsert(*diffs, ATmake("diff([],<term>)", l2));
    }
    return ATreverse(ATinsert(result, ATreadFromString(("<diff-lists>"))));
  }

  return ATreverse(result);
}




static ATerm AT_diff(ATerm t1, ATerm t2, ATermList *diffs)
{
  ATerm diff = ((void *)0);

  if (((ATbool)((ATerm)(t1) == (ATerm)(t2)))) {
    return t1;
  }

  if (((((t1)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7) != ((((t2)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    diff = ATreadFromString(("<diff-types>"));
  } else {
    switch (((((t1)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
      case 2:
      case 3:
      case 6:
        diff = ATreadFromString(("<diff-values>"));
        break;

      case 5:
        {
          ATerm ph1, ph2;

          ph1 = (((ATermPlaceholder)t1)->ph_type);
          ph2 = (((ATermPlaceholder)t2)->ph_type);
          return (ATerm)ATmakePlaceholder(AT_diff(ph1, ph2, diffs));
        }
        break;

      case 1:
        {
          ATermAppl appl1, appl2;
          AFun afun1, afun2;

          appl1 = (ATermAppl)t1;
          appl2 = (ATermAppl)t2;
          afun1 = (((appl1)->header) >> 10);
          afun2 = (((appl2)->header) >> 10);
          if (afun1 == afun2) {
            ATermList args1 = ATgetArguments(appl1);
            ATermList args2 = ATgetArguments(appl2);
            ATermList args = AT_diffList(args1, args2, diffs);
            return (ATerm)ATmakeApplList(afun1, args);
          } else {
            diff = ATreadFromString(("<diff-appls>"));
          }
        }
        break;

      case 4:
        return (ATerm)AT_diffList((ATermList)t1, (ATermList)t2, diffs);
    }
  }

  if (diffs) {
    *diffs = ATinsert(*diffs, ATmake("diff(<term>,<term>)", t1, t2));
  }

  return diff;
}





ATbool ATdiff(ATerm t1, ATerm t2, ATerm *template, ATerm *diffs)
{
  ATerm templ;

  if (diffs) {
    *diffs = (ATerm)ATempty;
  }

  templ = AT_diff(t1, t2, (ATermList *)diffs);

  if (template) {
    *template = templ;
  }

  if (diffs) {
    *diffs = (ATerm)ATreverse((ATermList)*diffs);
  }

  return !((ATbool)((ATerm)(t1) == (ATerm)(t2)));
}
# 3215 "aterm.c"
ATbool AT_isDeepEqual(ATerm t1, ATerm t2)
{
  int type;
  ATbool result = ATtrue;

  if (t1 == ((void *)0) && t2 == ((void *)0)) {
    return ATtrue;
  }

  if (t1 == ((void *)0) || t2 == ((void *)0)) {
    return ATfalse;
  }

  type = ((((t1)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7);
  if (type != ((((t2)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    return ATfalse;
  }

  switch(type) {
    case 1:
      {
        ATermAppl appl1 = (ATermAppl)t1, appl2 = (ATermAppl)t2;
        AFun sym = (((appl1)->header) >> 10);
        int i, arity = ((at_lookup_table_alias[(sym)]->header) >> 10);

        if(sym != (((appl2)->header) >> 10))
          return ATfalse;

        for(i=0; i<arity; i++) {
          if(!AT_isDeepEqual((*((ATerm *)(appl1) + 2 + (i))), (*((ATerm *)(appl2) + 2 + (i)))))
            return ATfalse;
        }
      }
      break;

    case 4:
      {
        ATermList list1 = (ATermList)t1, list2 = (ATermList)t2;
        if(((int)(((list1)->header) >> 10)) != ((int)(((list2)->header) >> 10)))
          return ATfalse;

        while(!((ATbool)(((ATermList)(list1))->head == ((void *)0) && ((ATermList)(list1))->tail == ((void *)0)))) {
          if(!AT_isDeepEqual(((list1)->head), ((list2)->head)))
            return ATfalse;

          list1 = ((list1)->tail);
          list2 = ((list2)->tail);
        }
      }
      break;

    case 2:
      result = (((((ATermInt)t1)->value) == (((ATermInt)t2)->value)) ? ATtrue : ATfalse);
      break;

    case 3:
      result = (((((ATermReal)t1)->value) == (((ATermReal)t2)->value)) ? ATtrue : ATfalse);
      break;

    case 6:
      result = (((((ATermBlob)t1)->data) == (((ATermBlob)t2)->data)) &&
                ((((ATermBlob)t1)->size) == (((ATermBlob)t2)->size))) ? ATtrue : ATfalse;
      break;

    case 5:
      result = AT_isDeepEqual((((ATermPlaceholder)t1)->ph_type),
                              (((ATermPlaceholder)t1)->ph_type));
      break;

    default:
      ATerror("illegal term type: %d\n", type);
  }

  if(result) {
    if(((t1->header) & (1<<3))) {
      if(((t2->header) & (1<<3))) {
        result = AT_isDeepEqual(AT_getAnnotations(t1), AT_getAnnotations(t2));
      } else {
        result = ATfalse;
      }
    } else if(((t2->header) & (1<<3))) {
      result = ATfalse;
    }
  }

  return result;
}
# 3310 "aterm.c"
ATbool AT_isEqual(ATerm t1, ATerm t2)
{
  int type;
  ATbool result = ATtrue;

  if(t1 == t2)
    return ATtrue;

  if (t1 == ((void *)0) || t2 == ((void *)0)) {
    return ATfalse;
  }

  type = ((((t1)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7);
  if(type != ((((t2)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7))
    return ATfalse;

  switch(type) {
    case 1:
      {
        ATermAppl appl1 = (ATermAppl)t1, appl2 = (ATermAppl)t2;
        AFun sym = (((appl1)->header) >> 10);
        int i, arity = ((at_lookup_table_alias[(sym)]->header) >> 10);

        if(sym != (((appl2)->header) >> 10))
          return ATfalse;

        for(i=0; i<arity; i++)
          if(!AT_isEqual((*((ATerm *)(appl1) + 2 + (i))), (*((ATerm *)(appl2) + 2 + (i)))))
            return ATfalse;
      }
      break;

    case 4:
      {
        ATermList list1 = (ATermList)t1, list2 = (ATermList)t2;
        if(((int)(((list1)->header) >> 10)) != ((int)(((list2)->header) >> 10)))
          return ATfalse;

        while(!((ATbool)(((ATermList)(list1))->head == ((void *)0) && ((ATermList)(list1))->tail == ((void *)0)))) {
          if(!AT_isEqual(((list1)->head), ((list2)->head)))
            return ATfalse;

          list1 = ((list1)->tail);
          list2 = ((list2)->tail);
        }
      }
      break;

    case 2:
      result = (((((ATermInt)t1)->value) == (((ATermInt)t2)->value)) ? ATtrue : ATfalse);
      break;

    case 3:
      result = (((((ATermReal)t1)->value) == (((ATermReal)t2)->value)) ? ATtrue : ATfalse);
      break;

    case 6:
      result = (((((ATermBlob)t1)->data) == (((ATermBlob)t2)->data)) &&
                ((((ATermBlob)t1)->size) == (((ATermBlob)t2)->size))) ? ATtrue : ATfalse;
      break;

    case 5:
      result = AT_isEqual((((ATermPlaceholder)t1)->ph_type),
                         (((ATermPlaceholder)t1)->ph_type));
      break;

    default:
      ATerror("illegal term type: %d\n", type);
  }

  if(result) {
    if(((t1->header) & (1<<3))) {
      if(((t2->header) & (1<<3))) {
        result = AT_isEqual(AT_getAnnotations(t1), AT_getAnnotations(t2));
      } else {
        result = ATfalse;
      }
    } else if(((t2->header) & (1<<3))) {
      result = ATfalse;
    }
  }

  return result;
}





ATerm ATremoveAllAnnotations(ATerm t)
{
  switch(((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7)) {
    case 2:
    case 3:
    case 6:
      return AT_removeAnnotations(t);

    case 4:
      {
        if(((ATbool)(((ATermList)((ATermList)t))->head == ((void *)0) && ((ATermList)((ATermList)t))->tail == ((void *)0)))) {
          return AT_removeAnnotations(t);
        } else {
          ATermList l = (ATermList)t;
          ATerm new_head, head = ((l)->head);
          ATermList new_tail, tail = ((l)->tail);
          new_head = ATremoveAllAnnotations(head);
          new_tail = (ATermList)ATremoveAllAnnotations((ATerm)tail);
          if (new_head == head && new_tail == tail) {
            return AT_removeAnnotations(t);
          }
          return (ATerm)ATinsert(new_tail, new_head);
        }
      }

    case 1:
      {
        ATermAppl appl = (ATermAppl)t;
        AFun fun = (((appl)->header) >> 10);
        int arity = ((at_lookup_table_alias[(fun)]->header) >> 10);
        if (arity <= 6) {
          ATerm arg, args[6];
          int i;
          ATbool changed = ATfalse;
          for (i=0; i<arity; i++) {
            arg = (*((ATerm *)(appl) + 2 + (i)));
            args[i] = ATremoveAllAnnotations(arg);
            if (args[i] != arg) {
              changed = ATtrue;
            }
          }
          if (changed) {
            return (ATerm)ATmakeApplArray(fun, args);
          } else {
            return AT_removeAnnotations(t);
          }
        } else {
          ATermList args = ATgetArguments(appl);
          ATermList new_args = (ATermList)ATremoveAllAnnotations((ATerm)args);
          if (args == new_args) {
            return AT_removeAnnotations(t);
          }
          return (ATerm)ATmakeApplList(fun, new_args);
        }
      }

    case 5:
      {
        ATermPlaceholder ph = (ATermPlaceholder)t;
        return (ATerm)ATmakePlaceholder(ATremoveAllAnnotations(((ph)->ph_type)));
      }

    default:
      ATerror("illegal term type: %d\n", ((((t)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7));
      return ((void *)0);
  }
}




static int AT_compareArguments(ATermAppl t1, ATermAppl t2)
{
  int arity1;
  int arity2;
  int i;
  ATerm arg1;
  ATerm arg2;
  int result = 0;

  arity1 = ((at_lookup_table_alias[((((t1)->header) >> 10))]->header) >> 10);
  arity2 = ((at_lookup_table_alias[((((t2)->header) >> 10))]->header) >> 10);


  for (i = 0; result == 0 && i < arity1 && i < arity2; i++) {
    arg1 = (*((ATerm *)(t1) + 2 + (i)));
    arg2 = (*((ATerm *)(t2) + 2 + (i)));
    result = ATcompare(arg1,arg2);
  }

  if (arity1 < arity2) {
    return -1;
  }
  else if (arity1 > arity2) {
    return 1;
  }

  return result;

}




static int AT_compareAppls(ATermAppl t1, ATermAppl t2)
{
  AFun fun1;
  AFun fun2;
  char *name1;
  char *name2;
  int result;

  fun1 = (((t1)->header) >> 10);
  fun2 = (((t2)->header) >> 10);

  name1 = (at_lookup_table[(fun1)]->name);
  name2 = (at_lookup_table[(fun2)]->name);

  result = strcmp(name1,name2);
  if (result != 0) {
    return result;
  }

  return AT_compareArguments(t1,t2);

}




static int AT_compareInts(ATermInt t1, ATermInt t2)
{
  int i1;
  int i2;
  i1 = ((t1)->value);
  i2 = ((t2)->value);
  if (i1 < i2) {
    return -1;
  }
  else if (i1 > i2) {
    return 1;
  }
  return 0;
}




static int AT_compareReals(ATermReal t1, ATermReal t2)
{
  double r1;
  double r2;
  r1 = ((t1)->value);
  r2 = ((t2)->value);
  if (r1 < r2) {
    return -1;
  }
  else if (r1 > r2) {
    return 1;
  }
  return 0;
}




static int AT_compareLists(ATermList t1, ATermList t2)
{
  int length1;
  int length2;
  ATerm elt1;
  ATerm elt2;
  int result = 0;

  while (result == 0 && !((ATbool)(((ATermList)(t1))->head == ((void *)0) && ((ATermList)(t1))->tail == ((void *)0))) && !((ATbool)(((ATermList)(t2))->head == ((void *)0) && ((ATermList)(t2))->tail == ((void *)0)))) {
    elt1 = ((t1)->head);
    elt2 = ((t2)->head);

    result = ATcompare(elt1,elt2);

    t1 = ((t1)->tail);
    t2 = ((t2)->tail);
  }

  if (result != 0) {
    return result;
  }

  length1 = ((int)(((t1)->header) >> 10));
  length2 = ((int)(((t2)->header) >> 10));

  if (length1 < length2) {
    return -1;
  }
  else if (length1 > length2) {
    return 1;
  }
  return 0;
}




static int AT_comparePlaceholders(ATermPlaceholder t1, ATermPlaceholder t2)
{
  ATerm type1;
  ATerm type2;
  type1 = ((t1)->ph_type);
  type2 = ((t2)->ph_type);
  return ATcompare(type1,type2);
}




static int AT_compareBlobs(ATermBlob t1, ATermBlob t2)
{
  char *data1;
  char *data2;
  int size1;
  int size2;
  int result = 0;
  data1 = ((t1)->data);
  data2 = ((t2)->data);
  size1 = ((t1)->size);
  size2 = ((t2)->size);

  if (size1 < size2) {
    result = memcmp(data1, data2, size1);
    if (result == 0) {
      return -1;
    }
  }
  else if (size1 > size2) {
    result = memcmp(data1, data2, size2);
    if (result == 0) {
      return 1;
    }
  }
  else {
    return memcmp(data1, data2, size1);
  }

  return result;
}




int ATcompare(ATerm t1, ATerm t2)
{
  int type1;
  int type2;
  int result = 0;

  if (((ATbool)((ATerm)(t1) == (ATerm)(t2)))) {
    return 0;
  }

  type1 = ((((t1)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7);
  type2 = ((((t2)->header) & ((1<<7) | (1<<8) | (1<<9))) >> 7);

  if (type1 < type2) {
    return -1;
  }
  else if (type2 > type1) {
    return 1;
  }

  switch (type1) {
    case 1:
      result = AT_compareAppls((ATermAppl) t1, (ATermAppl) t2);
      break;
    case 2:
      result = AT_compareInts((ATermInt) t1, (ATermInt) t2);
      break;
    case 3:
      result = AT_compareReals((ATermReal) t1, (ATermReal) t2);
      break;
    case 4:
      result = AT_compareLists((ATermList) t1, (ATermList) t2);
      break;
    case 5:
      result = AT_comparePlaceholders((ATermPlaceholder) t1,
                                    (ATermPlaceholder) t2);
      break;
    case 6:
      result = AT_compareBlobs((ATermBlob) t1, (ATermBlob) t2);
      break;
    default:
      ATabort("Unknown ATerm type %d\n", type1);
      break;
  }

  if (result == 0) {
    ATerm annos1 = AT_getAnnotations( (t1) );
    ATerm annos2 = AT_getAnnotations( (t2) );
    if (annos1 && annos2) {
      return ATcompare(annos1,annos2);
    }
    if (annos1) {
      return 1;
    }
    if (annos2) {
      return -1;
    }
  }

  return result;
}
