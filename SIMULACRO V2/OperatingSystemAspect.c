
struct JoinPoint { 
	void** (*fp) (struct JoinPoint *);
	void ** args;
	int argsCount;
	const char ** argsType;
	 void * (*arg)(int, struct JoinPoint *); 
	 const char * (*argType)(int , struct JoinPoint *); 
	void ** retValue;
	const char * retType;
	const char * funcName ;
	const char * targetName ;
	const char * fileName ;
	const char * kind ;
	void * excep_return ;
};

 struct __UTAC__EXCEPTION {
	void * jumpbuf ;
	unsigned long long int prtValue ;
	int pops;
	struct __UTAC__CFLOW_FUNC {
		int (*func)(int,int) ;
		int val ;
		struct __UTAC__CFLOW_FUNC * next; 
	} * cflowfuncs; 
}; 


# 1 "OperatingSystem.c" 
# 1 "<built-in>" 
# 1 "<command-line>" 
# 31 "<command-line>" 
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "OperatingSystem.c" 
# 1 "OperatingSystem.h" 1
# 1 "ComputerSystem.h" 1
# 1 "Simulator.h" 1
# 5 "ComputerSystem.h" 2
# 1 "ComputerSystemBase.h" 1
# 1 "ComputerSystem.h" 1
# 7 "ComputerSystemBase.h" 2
int ComputerSystem_ObtainProgramList(int , char *([]), int ); 
#line 8 "ComputerSystemBase.h"
void ComputerSystem_DebugMessage(int , char , ...); 
#line 11 "ComputerSystemBase.h"
extern char defaultDebugLevel[]; 
#line 12 "ComputerSystemBase.h"
extern int intervalBetweenInterrupts; 
#line 8 "ComputerSystem.h"
void ComputerSystem_PowerOn(int argc, char *argv[], int ); 
#line 9 "ComputerSystem.h"
void ComputerSystem_PowerOff(); 
#line 10 "ComputerSystem.h"
void ComputerSystem_PrintProgramList(); 
# 6 "ComputerSystem.h" 2
# 38 "ComputerSystem.h" 
typedef struct ProgramData {char *executableName; unsigned int arrivalTime; unsigned int type; 
}PROGRAMS_DATA; 
#line 42 "ComputerSystem.h"
extern  PROGRAMS_DATA *programList[20]; 
# 5 "OperatingSystem.h" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 424 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 427 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 428 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 429 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 425 "/usr/include/features.h" 2 3 4
# 448 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 449 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3 4
typedef long unsigned int size_t; 
# 34 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
typedef unsigned char __u_char; 
#line 31 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned short int __u_short; 
#line 32 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __u_int; 
#line 33 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __u_long; 
#line 36 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef signed char __int8_t; 
#line 37 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned char __uint8_t; 
#line 38 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef signed short int __int16_t; 
#line 39 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned short int __uint16_t; 
#line 40 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef signed int __int32_t; 
#line 41 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __uint32_t; 
#line 43 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef signed long int __int64_t; 
#line 44 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __uint64_t; 
#line 52 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __quad_t; 
#line 53 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __u_quad_t; 
#line 61 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __intmax_t; 
#line 62 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __uintmax_t; 
# 130 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 133 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
typedef unsigned long int __dev_t; 
#line 134 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __uid_t; 
#line 135 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __gid_t; 
#line 136 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __ino_t; 
#line 137 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __ino64_t; 
#line 138 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __mode_t; 
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __nlink_t; 
#line 140 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __off_t; 
#line 141 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __off64_t; 
#line 142 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __pid_t; 
#line 143 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef struct {int __val[2]; 
}__fsid_t; 
#line 144 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __clock_t; 
#line 145 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __rlim_t; 
#line 146 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __rlim64_t; 
#line 147 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __id_t; 
#line 148 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __time_t; 
#line 149 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __useconds_t; 
#line 150 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __suseconds_t; 
#line 152 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __daddr_t; 
#line 153 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __key_t; 
#line 156 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __clockid_t; 
#line 159 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef void *__timer_t; 
#line 162 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __blksize_t; 
#line 167 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __blkcnt_t; 
#line 168 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __blkcnt64_t; 
#line 171 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __fsblkcnt_t; 
#line 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __fsblkcnt64_t; 
#line 175 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __fsfilcnt_t; 
#line 176 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __fsfilcnt64_t; 
#line 179 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __fsword_t; 
#line 181 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __ssize_t; 
#line 184 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __syscall_slong_t; 
#line 186 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long int __syscall_ulong_t; 
#line 190 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef  __off64_t __loff_t; 
#line 191 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef char *__caddr_t; 
#line 194 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long int __intptr_t; 
#line 197 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __socklen_t; 
#line 202 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __sig_atomic_t; 
# 36 "/usr/include/stdio.h" 2 3 4
# 4 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4
struct _IO_FILE ; 
#line 5 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h"
typedef struct _IO_FILE __FILE; 
# 37 "/usr/include/stdio.h" 2 3 4
# 4 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4
struct _IO_FILE ; 
#line 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h"
typedef struct _IO_FILE FILE; 
# 38 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libio.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
typedef struct {int __count; union {unsigned int __wch; char __wchb[4]; 
}__value; 
}__mbstate_t; 
#line 30 "/usr/include/x86_64-linux-gnu/bits/_G_config.h"
typedef struct { __off_t __pos;  __mbstate_t __state; 
}_G_fpos_t; 
#line 35 "/usr/include/x86_64-linux-gnu/bits/_G_config.h"
typedef struct { __off64_t __pos;  __mbstate_t __state; 
}_G_fpos64_t; 
# 22 "/usr/include/x86_64-linux-gnu/bits/_G_config.h" 2 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/libio.h" 2 3 4
# 53 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list; 
# 54 "/usr/include/x86_64-linux-gnu/bits/libio.h" 2 3 4
# 149 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
struct _IO_jump_t ; 
#line 149 "/usr/include/x86_64-linux-gnu/bits/libio.h"
struct _IO_FILE ; 
#line 154 "/usr/include/x86_64-linux-gnu/bits/libio.h"
typedef void _IO_lock_t; 
#line 177 "/usr/include/x86_64-linux-gnu/bits/libio.h"
struct _IO_marker {struct _IO_marker *_next; struct _IO_FILE *_sbuf; int _pos; 
}; 
#line 186 "/usr/include/x86_64-linux-gnu/bits/libio.h"
enum __codecvt_result {__codecvt_ok,__codecvt_partial,__codecvt_error,__codecvt_noconv}; 
# 177 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 245 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 311 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
struct _IO_FILE {int _flags; char *_IO_read_ptr; char *_IO_read_end; char *_IO_read_base; char *_IO_write_base; char *_IO_write_ptr; char *_IO_write_end; char *_IO_buf_base; char *_IO_buf_end; char *_IO_save_base; char *_IO_backup_base; char *_IO_save_end; struct _IO_marker *_markers; struct _IO_FILE *_chain; int _fileno; int _flags2;  __off_t _old_offset; unsigned short _cur_column; signed char _vtable_offset; char _shortbuf[1];  _IO_lock_t *_lock;  __off64_t _offset; void *__pad1; void *__pad2; void *__pad3; void *__pad4;  size_t __pad5; int _mode; char _unused2[15 * sizeof (int ) - 4 * sizeof (void *) - sizeof ( size_t )]; 
}; 
#line 314 "/usr/include/x86_64-linux-gnu/bits/libio.h"
typedef struct _IO_FILE _IO_FILE; 
#line 317 "/usr/include/x86_64-linux-gnu/bits/libio.h"
struct _IO_FILE_plus ; 
#line 319 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern struct _IO_FILE_plus _IO_2_1_stdin_; 
#line 320 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern struct _IO_FILE_plus _IO_2_1_stdout_; 
#line 321 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern struct _IO_FILE_plus _IO_2_1_stderr_; 
#line 337 "/usr/include/x86_64-linux-gnu/bits/libio.h"
typedef  __ssize_t __io_read_fn(void *__cookie, char *__buf,  size_t __nbytes); 
#line 346 "/usr/include/x86_64-linux-gnu/bits/libio.h"
typedef  __ssize_t __io_write_fn(void *__cookie, const char *__buf,  size_t __n); 
#line 354 "/usr/include/x86_64-linux-gnu/bits/libio.h"
typedef int __io_seek_fn(void *__cookie,  __off64_t *__pos, int __w); 
#line 357 "/usr/include/x86_64-linux-gnu/bits/libio.h"
typedef int __io_close_fn(void *__cookie); 
# 337 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 389 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
extern int __underflow( _IO_FILE *); 
#line 390 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int __uflow( _IO_FILE *); 
#line 391 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int __overflow( _IO_FILE *, int ); 
#line 433 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_getc( _IO_FILE *__fp); 
#line 434 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_putc(int __c,  _IO_FILE *__fp); 
#line 435 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_feof( _IO_FILE *__fp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 436 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_ferror( _IO_FILE *__fp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 438 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_peekc_locked( _IO_FILE *__fp); 
#line 444 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern void _IO_flockfile( _IO_FILE *) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 445 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern void _IO_funlockfile( _IO_FILE *) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 446 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_ftrylockfile( _IO_FILE *) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 433 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
# 463 "/usr/include/x86_64-linux-gnu/bits/libio.h" 3 4
extern int _IO_vfscanf( _IO_FILE *__restrict , const char *__restrict ,  __gnuc_va_list , int *__restrict ); 
#line 465 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern int _IO_vfprintf( _IO_FILE *__restrict , const char *__restrict ,  __gnuc_va_list ); 
#line 466 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern  __ssize_t _IO_padn( _IO_FILE *, int ,  __ssize_t ); 
#line 467 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern  size_t _IO_sgetn( _IO_FILE *, void *,  size_t ); 
#line 469 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern  __off64_t _IO_seekoff( _IO_FILE *,  __off64_t , int , int ); 
#line 470 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern  __off64_t _IO_seekpos( _IO_FILE *,  __off64_t , int ); 
#line 472 "/usr/include/x86_64-linux-gnu/bits/libio.h"
extern void _IO_free_backup_area( _IO_FILE *) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 46 "/usr/include/stdio.h"
typedef  __gnuc_va_list va_list; 
# 42 "/usr/include/stdio.h" 2 3 4
# 57 "/usr/include/stdio.h" 3 4
typedef  __off_t off_t; 
#line 71 "/usr/include/stdio.h"
typedef  __ssize_t ssize_t; 
#line 78 "/usr/include/stdio.h"
typedef  _G_fpos_t fpos_t; 
# 71 "/usr/include/stdio.h" 3 4
# 131 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 135 "/usr/include/stdio.h" 2 3 4
extern struct _IO_FILE *stdin; 
#line 136 "/usr/include/stdio.h"
extern struct _IO_FILE *stdout; 
#line 137 "/usr/include/stdio.h"
extern struct _IO_FILE *stderr; 
#line 144 "/usr/include/stdio.h"
extern int remove(const char *__filename) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 146 "/usr/include/stdio.h"
extern int rename(const char *__old, const char *__new) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 151 "/usr/include/stdio.h"
extern int renameat(int __oldfd, const char *__old, int __newfd, const char *__new) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 159 "/usr/include/stdio.h"
extern  FILE *tmpfile(void ); 
#line 173 "/usr/include/stdio.h"
extern char *tmpnam(char *__s) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 178 "/usr/include/stdio.h"
extern char *tmpnam_r(char *__s) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 173 "/usr/include/stdio.h" 3 4
# 191 "/usr/include/stdio.h" 3 4
extern char *tempnam(const char *__dir, const char *__pfx) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ )) ; 
#line 199 "/usr/include/stdio.h"
extern int fclose( FILE *__stream); 
#line 204 "/usr/include/stdio.h"
extern int fflush( FILE *__stream); 
#line 213 "/usr/include/stdio.h"
extern int fflush_unlocked( FILE *__stream); 
# 213 "/usr/include/stdio.h" 3 4
# 233 "/usr/include/stdio.h" 3 4
extern  FILE *fopen(const char *__restrict __filename, const char *__restrict __modes); 
#line 240 "/usr/include/stdio.h"
extern  FILE *freopen(const char *__restrict __filename, const char *__restrict __modes,  FILE *__restrict __stream); 
#line 265 "/usr/include/stdio.h"
extern  FILE *fdopen(int __fd, const char *__modes) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 265 "/usr/include/stdio.h" 3 4
# 279 "/usr/include/stdio.h" 3 4
extern  FILE *fmemopen(void *__s,  size_t __len, const char *__modes) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 284 "/usr/include/stdio.h"
extern  FILE *open_memstream(char **__bufloc,  size_t *__sizeloc) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 290 "/usr/include/stdio.h"
extern void setbuf( FILE *__restrict __stream, char *__restrict __buf) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 295 "/usr/include/stdio.h"
extern int setvbuf( FILE *__restrict __stream, char *__restrict __buf, int __modes,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 301 "/usr/include/stdio.h"
extern void setbuffer( FILE *__restrict __stream, char *__restrict __buf,  size_t __size) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 304 "/usr/include/stdio.h"
extern void setlinebuf( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 313 "/usr/include/stdio.h"
extern int fprintf( FILE *__restrict __stream, const char *__restrict __format, ...); 
#line 318 "/usr/include/stdio.h"
extern int printf(const char *__restrict __format, ...); 
#line 321 "/usr/include/stdio.h"
extern int sprintf(char *__restrict __s, const char *__restrict __format, ...) __attribute__  (( __nothrow__ )) ; 
#line 328 "/usr/include/stdio.h"
extern int vfprintf( FILE *__restrict __s, const char *__restrict __format,  __gnuc_va_list __arg); 
#line 333 "/usr/include/stdio.h"
extern int vprintf(const char *__restrict __format,  __gnuc_va_list __arg); 
#line 336 "/usr/include/stdio.h"
extern int vsprintf(char *__restrict __s, const char *__restrict __format,  __gnuc_va_list __arg) __attribute__  (( __nothrow__ )) ; 
#line 342 "/usr/include/stdio.h"
extern int snprintf(char *__restrict __s,  size_t __maxlen, const char *__restrict __format, ...) __attribute__  (( __nothrow__ ))  __attribute__  (( __format__ ( __printf__, 3, 4 )  )) ; 
#line 346 "/usr/include/stdio.h"
extern int vsnprintf(char *__restrict __s,  size_t __maxlen, const char *__restrict __format,  __gnuc_va_list __arg) __attribute__  (( __nothrow__ ))  __attribute__  (( __format__ ( __printf__, 3, 0 )  )) ; 
#line 367 "/usr/include/stdio.h"
extern int vdprintf(int __fd, const char *__restrict __fmt,  __gnuc_va_list __arg) __attribute__  (( __format__ ( __printf__, 2, 0 )  )) ; 
#line 369 "/usr/include/stdio.h"
extern int dprintf(int __fd, const char *__restrict __fmt, ...) __attribute__  (( __format__ ( __printf__, 2, 3 )  )) ; 
#line 378 "/usr/include/stdio.h"
extern int fscanf( FILE *__restrict __stream, const char *__restrict __format, ...); 
#line 383 "/usr/include/stdio.h"
extern int scanf(const char *__restrict __format, ...); 
#line 386 "/usr/include/stdio.h"
extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 365 "/usr/include/stdio.h" 3 4
# 397 "/usr/include/stdio.h" 3 4
extern int fscanf( FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("""__isoc99_fscanf"); 
#line 399 "/usr/include/stdio.h"
extern int scanf(const char *__restrict __format, ...) __asm__ ("""__isoc99_scanf"); 
#line 402 "/usr/include/stdio.h"
extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("""__isoc99_sscanf") __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 422 "/usr/include/stdio.h"
extern int vfscanf( FILE *__restrict __s, const char *__restrict __format,  __gnuc_va_list __arg) __attribute__  (( __format__ ( __scanf__, 2, 0 )  )) ; 
#line 429 "/usr/include/stdio.h"
extern int vscanf(const char *__restrict __format,  __gnuc_va_list __arg) __attribute__  (( __format__ ( __scanf__, 1, 0 )  )) ; 
#line 434 "/usr/include/stdio.h"
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,  __gnuc_va_list __arg) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __format__ ( __scanf__, 2, 0 )  )) ; 
# 420 "/usr/include/stdio.h" 3 4
# 447 "/usr/include/stdio.h" 3 4
extern int vfscanf( FILE *__restrict __s, const char *__restrict __format,  __gnuc_va_list __arg) __asm__ ("""__isoc99_vfscanf") __attribute__  (( __format__ ( __scanf__, 2, 0 )  )) ; 
#line 450 "/usr/include/stdio.h"
extern int vscanf(const char *__restrict __format,  __gnuc_va_list __arg) __asm__ ("""__isoc99_vscanf") __attribute__  (( __format__ ( __scanf__, 1, 0 )  )) ; 
#line 455 "/usr/include/stdio.h"
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,  __gnuc_va_list __arg) __asm__ ("""__isoc99_vsscanf") __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __format__ ( __scanf__, 2, 0 )  )) ; 
#line 477 "/usr/include/stdio.h"
extern int fgetc( FILE *__stream); 
#line 478 "/usr/include/stdio.h"
extern int getc( FILE *__stream); 
#line 484 "/usr/include/stdio.h"
extern int getchar(void ); 
# 477 "/usr/include/stdio.h" 3 4
# 495 "/usr/include/stdio.h" 3 4
extern int getc_unlocked( FILE *__stream); 
#line 496 "/usr/include/stdio.h"
extern int getchar_unlocked(void ); 
#line 506 "/usr/include/stdio.h"
extern int fgetc_unlocked( FILE *__stream); 
# 506 "/usr/include/stdio.h" 3 4
# 517 "/usr/include/stdio.h" 3 4
extern int fputc(int __c,  FILE *__stream); 
#line 518 "/usr/include/stdio.h"
extern int putc(int __c,  FILE *__stream); 
#line 524 "/usr/include/stdio.h"
extern int putchar(int __c); 
#line 537 "/usr/include/stdio.h"
extern int fputc_unlocked(int __c,  FILE *__stream); 
#line 545 "/usr/include/stdio.h"
extern int putc_unlocked(int __c,  FILE *__stream); 
#line 546 "/usr/include/stdio.h"
extern int putchar_unlocked(int __c); 
#line 553 "/usr/include/stdio.h"
extern int getw( FILE *__stream); 
#line 556 "/usr/include/stdio.h"
extern int putw(int __w,  FILE *__stream); 
#line 565 "/usr/include/stdio.h"
extern char *fgets(char *__restrict __s, int __n,  FILE *__restrict __stream); 
# 537 "/usr/include/stdio.h" 3 4
# 605 "/usr/include/stdio.h" 3 4
extern  __ssize_t __getdelim(char **__restrict __lineptr,  size_t *__restrict __n, int __delimiter,  FILE *__restrict __stream); 
#line 608 "/usr/include/stdio.h"
extern  __ssize_t getdelim(char **__restrict __lineptr,  size_t *__restrict __n, int __delimiter,  FILE *__restrict __stream); 
#line 618 "/usr/include/stdio.h"
extern  __ssize_t getline(char **__restrict __lineptr,  size_t *__restrict __n,  FILE *__restrict __stream); 
#line 626 "/usr/include/stdio.h"
extern int fputs(const char *__restrict __s,  FILE *__restrict __stream); 
#line 632 "/usr/include/stdio.h"
extern int puts(const char *__s); 
#line 639 "/usr/include/stdio.h"
extern int ungetc(int __c,  FILE *__stream); 
#line 647 "/usr/include/stdio.h"
extern  size_t fread(void *__restrict __ptr,  size_t __size,  size_t __n,  FILE *__restrict __stream); 
#line 653 "/usr/include/stdio.h"
extern  size_t fwrite(const void *__restrict __ptr,  size_t __size,  size_t __n,  FILE *__restrict __s); 
#line 674 "/usr/include/stdio.h"
extern  size_t fread_unlocked(void *__restrict __ptr,  size_t __size,  size_t __n,  FILE *__restrict __stream); 
#line 676 "/usr/include/stdio.h"
extern  size_t fwrite_unlocked(const void *__restrict __ptr,  size_t __size,  size_t __n,  FILE *__restrict __stream); 
#line 684 "/usr/include/stdio.h"
extern int fseek( FILE *__stream, long int __off, int __whence); 
#line 689 "/usr/include/stdio.h"
extern long int ftell( FILE *__stream); 
#line 694 "/usr/include/stdio.h"
extern void rewind( FILE *__stream); 
# 673 "/usr/include/stdio.h" 3 4
# 707 "/usr/include/stdio.h" 3 4
extern int fseeko( FILE *__stream,  __off_t __off, int __whence); 
#line 712 "/usr/include/stdio.h"
extern  __off_t ftello( FILE *__stream); 
#line 731 "/usr/include/stdio.h"
extern int fgetpos( FILE *__restrict __stream,  fpos_t *__restrict __pos); 
#line 736 "/usr/include/stdio.h"
extern int fsetpos( FILE *__stream, const  fpos_t *__pos); 
# 731 "/usr/include/stdio.h" 3 4
# 757 "/usr/include/stdio.h" 3 4
extern void clearerr( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 759 "/usr/include/stdio.h"
extern int feof( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 761 "/usr/include/stdio.h"
extern int ferror( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 765 "/usr/include/stdio.h"
extern void clearerr_unlocked( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 766 "/usr/include/stdio.h"
extern int feof_unlocked( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 767 "/usr/include/stdio.h"
extern int ferror_unlocked( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 775 "/usr/include/stdio.h"
extern void perror(const char *__s); 
# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr; 
#line 27 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
extern const char *const sys_errlist[]; 
#line 786 "/usr/include/stdio.h"
extern int fileno( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 791 "/usr/include/stdio.h"
extern int fileno_unlocked( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 782 "/usr/include/stdio.h" 2 3 4
# 800 "/usr/include/stdio.h" 3 4
extern  FILE *popen(const char *__command, const char *__modes); 
#line 806 "/usr/include/stdio.h"
extern int pclose( FILE *__stream); 
#line 812 "/usr/include/stdio.h"
extern char *ctermid(char *__s) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 840 "/usr/include/stdio.h"
extern void flockfile( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 844 "/usr/include/stdio.h"
extern int ftrylockfile( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 847 "/usr/include/stdio.h"
extern void funlockfile( FILE *__stream) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 840 "/usr/include/stdio.h" 3 4
# 868 "/usr/include/stdio.h" 3 4
# 6 "OperatingSystem.h" 2
# 26 "OperatingSystem.h" 
# 26 "OperatingSystem.h" 
enum ProgramTypes {USERPROGRAM,DAEMONPROGRAM}; 
#line 29 "OperatingSystem.h"
enum ProcessStates {NEW,READY,EXECUTING,BLOCKED,EXIT}; 
#line 32 "OperatingSystem.h"
enum SystemCallIdentifiers {SYSCALL_END=3,SYSCALL_PRINTEXECPID=5,SYSCALL_YIELD=4,SYSCALL_SLEEP=7}; 
#line 35 "OperatingSystem.h"
enum TypeOfReadyToRunProcessQueues {USERPROCESSQUEUE,DAEMONSQUEUE}; 
#line 55 "OperatingSystem.h"
typedef struct {int busy; int initialPhysicalAddress; int processSize; int state; int priority; int copyOfPCRegister; unsigned int copyOfPSWRegister; int copyOfRegisterAccumulator; int programListIndex; int queueID; int whenToWakeUp; int createTime; int firstExecution; int enterReady; int readyTime; 
}PCB; 
#line 59 "OperatingSystem.h"
extern  PCB processTable[]; 
#line 60 "OperatingSystem.h"
extern int OS_address_base; 
#line 61 "OperatingSystem.h"
extern int sipID; 
#line 64 "OperatingSystem.h"
void OperatingSystem_Initialize(); 
#line 65 "OperatingSystem.h"
void OperatingSystem_InterruptLogic(int ); 
# 2 "OperatingSystem.c" 2
# 1 "OperatingSystemBase.h" 1
# 11 "Heap.h" 1
typedef struct {int info; unsigned int insertionOrder; 
}heapItem; 
#line 20 "Heap.h"
int Heap_poll( heapItem ([]), int , int *); 
# 20 "Heap.h" 
# 30 "Heap.h" 
int Heap_add(int ,  heapItem ([]), int , int *, int ); 
#line 37 "Heap.h"
int Heap_compare( heapItem ,  heapItem , int ); 
#line 43 "Heap.h"
int Heap_getFirst( heapItem ([]), int ); 
#line 10 "OperatingSystemBase.h"
int OperatingSystem_ObtainAnEntryInTheProcessTable(); 
#line 11 "OperatingSystemBase.h"
int OperatingSystem_ObtainProgramSize( FILE **, char *); 
#line 12 "OperatingSystemBase.h"
int OperatingSystem_ObtainPriority( FILE *); 
#line 13 "OperatingSystemBase.h"
int OperatingSystem_LoadProgram( FILE *, int , int ); 
#line 14 "OperatingSystemBase.h"
void OperatingSystem_ReadyToShutdown(); 
#line 15 "OperatingSystemBase.h"
void OperatingSystem_TerminatingSIP(); 
#line 16 "OperatingSystemBase.h"
void OperatingSystem_ShowTime(char ); 
#line 17 "OperatingSystemBase.h"
void OperatingSystem_PrintStatus(); 
#line 18 "OperatingSystemBase.h"
void OperatingSystem_PrintReadyToRunQueue(); 
#line 19 "OperatingSystemBase.h"
void OperatingSystem_PrepareTeachersDaemons(); 
#line 22 "OperatingSystemBase.h"
extern  heapItem sleepingProcessesQueue[]; 
#line 23 "OperatingSystemBase.h"
extern int numberOfSleepingProcesses; 
#line 27 "OperatingSystemBase.h"
extern int baseDaemonsInProgramList; 
# 7 "OperatingSystemBase.h" 2
# 3 "OperatingSystem.c" 2
# 5 "MMU.h" 1
void MMU_SetCTRL(int ); 
#line 6 "MMU.h"
int MMU_GetCTRL(); 
#line 7 "MMU.h"
int MMU_GetMAR(); 
#line 8 "MMU.h"
void MMU_SetMAR(int ); 
#line 9 "MMU.h"
void MMU_SetBase(int ); 
#line 10 "MMU.h"
void MMU_SetLimit(int ); 
#line 13 "MMU.h"
int MMU_GetBase(); 
#line 14 "MMU.h"
int MMU_GetLimit(); 
# 4 "OperatingSystem.c" 2
# 1 "Processor.h" 1
# 1 "MainMemory.h" 1
# 9 "MainMemory.h" 
typedef int MEMORYCELL; 
#line 13 "MainMemory.h"
int MainMemory_GetMAR(); 
#line 14 "MainMemory.h"
void MainMemory_SetMAR(int ); 
#line 15 "MainMemory.h"
void MainMemory_GetMBR( MEMORYCELL *); 
#line 16 "MainMemory.h"
void MainMemory_SetMBR( MEMORYCELL *); 
#line 17 "MainMemory.h"
int MainMemory_GetCTRL(); 
#line 18 "MainMemory.h"
void MainMemory_SetCTRL(int ); 
# 5 "Processor.h" 2
# 1 "ProcessorBase.h" 1
# 4 "Buses.h" 1
enum BusConnection {MAINMEMORY,MMU,CPU,INPUTDEVICE,OUTPUTDEVICE}; 
#line 16 "Buses.h"
typedef struct {int cell; 
}BUSDATACELL; 
#line 19 "Buses.h"
int Buses_write_AddressBus_From_To(int , int ); 
#line 20 "Buses.h"
int Buses_write_DataBus_From_To(int , int ); 
#line 21 "Buses.h"
int Buses_write_ControlBus_From_To(int , int ); 
# 14 "Buses.h" 
# 5 "ProcessorBase.h" 2
# 1 "Instructions.def" 1
# 12 "ProcessorBase.h" 2
enum Instruction {NONEXISTING_INST,ADD_INST,SHIFT_INST,DIV_INST,TRAP_INST,NOP_INST,JUMP_INST,ZJUMP_INST,WRITE_INST,READ_INST,INC_INST,HALT_INST,OS_INST,IRET_INST,MEMADD_INST,LAST_INST}; 
#line 14 "ProcessorBase.h"
void Processor_UpdatePSW(); 
#line 15 "ProcessorBase.h"
void Processor_CheckOverflow(int , int ); 
#line 17 "ProcessorBase.h"
void Processor_CopyInSystemStack(int , int ); 
#line 18 "ProcessorBase.h"
int Processor_CopyFromSystemStack(int ); 
#line 19 "ProcessorBase.h"
void Processor_RaiseInterrupt(const unsigned int ); 
#line 20 "ProcessorBase.h"
void Processor_ACKInterrupt(const unsigned int ); 
#line 21 "ProcessorBase.h"
unsigned int Processor_GetInterruptLineStatus(const unsigned int ); 
#line 24 "ProcessorBase.h"
void Processor_ActivatePSW_Bit(const unsigned int ); 
#line 25 "ProcessorBase.h"
void Processor_DeactivatePSW_Bit(const unsigned int ); 
#line 26 "ProcessorBase.h"
unsigned int Processor_PSW_BitState(const unsigned int ); 
#line 31 "ProcessorBase.h"
int Processor_GetMAR(); 
#line 32 "ProcessorBase.h"
void Processor_SetMAR(int ); 
#line 33 "ProcessorBase.h"
void Processor_GetMBR( BUSDATACELL *); 
#line 34 "ProcessorBase.h"
void Processor_SetMBR( BUSDATACELL *); 
#line 39 "ProcessorBase.h"
void Processor_SetAccumulator(int ); 
#line 40 "ProcessorBase.h"
int Processor_GetAccumulator(); 
#line 44 "ProcessorBase.h"
void Processor_SetPC(int ); 
#line 48 "ProcessorBase.h"
int Processor_GetRegisterA(); 
#line 52 "ProcessorBase.h"
void Processor_SetPSW(unsigned int ); 
#line 53 "ProcessorBase.h"
unsigned int Processor_GetPSW(); 
#line 55 "ProcessorBase.h"
int Processor_Encode(int , int , int ); 
#line 56 "ProcessorBase.h"
int Processor_DecodeOperationCode( BUSDATACELL ); 
#line 57 "ProcessorBase.h"
int Processor_DecodeOperand1( BUSDATACELL ); 
#line 58 "ProcessorBase.h"
int Processor_DecodeOperand2( BUSDATACELL ); 
#line 59 "ProcessorBase.h"
void Processor_GetCodedInstruction(char *,  BUSDATACELL ); 
#line 60 "ProcessorBase.h"
int Processor_ToInstruction(char *); 
#line 13 "Processor.h"
enum PSW_BITS {POWEROFF_BIT=0,ZERO_BIT=1,NEGATIVE_BIT=2,OVERFLOW_BIT=3,EXECUTION_MODE_BIT=7,INTERRUPT_MASKED_BIT=15}; 
#line 17 "Processor.h"
enum INT_BITS {SYSCALL_BIT=2,EXCEPTION_BIT=6,CLOCKINT_BIT=9}; 
#line 20 "Processor.h"
void Processor_InitializeInterruptVectorTable(); 
#line 21 "Processor.h"
void Processor_InstructionCycleLoop(); 
#line 22 "Processor.h"
void Processor_RaiseInterrupt(const unsigned int ); 
#line 24 "Processor.h"
char *Processor_ShowPSW(); 
#line 25 "Processor.h"
int Processor_GetCTRL(); 
#line 26 "Processor.h"
void Processor_SetCTRL(int ); 
# 6 "Processor.h" 2
# 5 "OperatingSystem.c" 2
# 6 "Clock.h" 1
void Clock_Update(); 
#line 7 "Clock.h"
int Clock_GetTime(); 
# 8 "OperatingSystem.c" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 42 "/usr/include/string.h" 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy(void *__restrict __dest, const void *__restrict __src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 47 "/usr/include/string.h"
extern void *memmove(void *__dest, const void *__src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 55 "/usr/include/string.h"
extern void *memccpy(void *__restrict __dest, const void *__restrict __src, int __c,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 60 "/usr/include/string.h"
extern void *memset(void *__s, int __c,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 64 "/usr/include/string.h"
extern int memcmp(const void *__s1, const void *__s2,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 91 "/usr/include/string.h"
extern void *memchr(const void *__s, int __c,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 90 "/usr/include/string.h" 3 4
# 122 "/usr/include/string.h" 3 4
extern char *strcpy(char *__restrict __dest, const char *__restrict __src) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 126 "/usr/include/string.h"
extern char *strncpy(char *__restrict __dest, const char *__restrict __src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 130 "/usr/include/string.h"
extern char *strcat(char *__restrict __dest, const char *__restrict __src) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 133 "/usr/include/string.h"
extern char *strncat(char *__restrict __dest, const char *__restrict __src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 137 "/usr/include/string.h"
extern int strcmp(const char *__s1, const char *__s2) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 140 "/usr/include/string.h"
extern int strncmp(const char *__s1, const char *__s2,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 144 "/usr/include/string.h"
extern int strcoll(const char *__s1, const char *__s2) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 148 "/usr/include/string.h"
extern  size_t strxfrm(char *__restrict __dest, const char *__restrict __src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 40 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct {struct __locale_data *__locales[13]; const unsigned short int *__ctype_b; const int *__ctype_tolower; const int *__ctype_toupper; const char *__names[13]; 
}; 
#line 42 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h"
typedef struct __locale_struct *__locale_t; 
#line 24 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h"
typedef  __locale_t locale_t; 
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4
# 156 "/usr/include/string.h" 2 3 4
extern int strcoll_l(const char *__s1, const char *__s2,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2, 3 )  )) ; 
#line 160 "/usr/include/string.h"
extern  size_t strxfrm_l(char *__dest, const char *__src,  size_t __n,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2, 4 )  )) ; 
#line 167 "/usr/include/string.h"
extern char *strdup(const char *__s) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 175 "/usr/include/string.h"
extern char *strndup(const char *__string,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 226 "/usr/include/string.h"
extern char *strchr(const char *__s, int __c) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 225 "/usr/include/string.h" 3 4
# 253 "/usr/include/string.h" 3 4
extern char *strrchr(const char *__s, int __c) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 273 "/usr/include/string.h"
extern  size_t strcspn(const char *__s, const char *__reject) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 277 "/usr/include/string.h"
extern  size_t strspn(const char *__s, const char *__accept) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
# 272 "/usr/include/string.h" 3 4
# 303 "/usr/include/string.h" 3 4
extern char *strpbrk(const char *__s, const char *__accept) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 330 "/usr/include/string.h"
extern char *strstr(const char *__haystack, const char *__needle) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 336 "/usr/include/string.h"
extern char *strtok(char *__restrict __s, const char *__restrict __delim) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
#line 343 "/usr/include/string.h"
extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2, 3 )  )) ; 
#line 347 "/usr/include/string.h"
extern char *strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2, 3 )  )) ; 
# 329 "/usr/include/string.h" 3 4
# 385 "/usr/include/string.h" 3 4
extern  size_t strlen(const char *__s) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 391 "/usr/include/string.h"
extern  size_t strnlen(const char *__string,  size_t __maxlen) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 396 "/usr/include/string.h"
extern char *strerror(int __errnum) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 411 "/usr/include/string.h"
extern int strerror_r(int __errnum, char *__buf,  size_t __buflen) __asm__ ("""__xpg_strerror_r") __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
# 409 "/usr/include/string.h" 3 4
# 427 "/usr/include/string.h" 3 4
extern char *strerror_l(int __errnum,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 35 "/usr/include/strings.h" 2 3 4
extern int bcmp(const void *__s1, const void *__s2,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 39 "/usr/include/strings.h"
extern void bcopy(const void *__src, void *__dest,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 42 "/usr/include/strings.h"
extern void bzero(void *__s,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 69 "/usr/include/strings.h"
extern char *index(const char *__s, int __c) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 68 "/usr/include/strings.h" 3 4
# 97 "/usr/include/strings.h" 3 4
extern char *rindex(const char *__s, int __c) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 104 "/usr/include/strings.h"
extern int ffs(int __i) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 110 "/usr/include/strings.h"
extern int ffsl(long int __l) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 112 "/usr/include/strings.h"
 __extension__ extern int ffsll(long long int __ll) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 117 "/usr/include/strings.h"
extern int strcasecmp(const char *__s1, const char *__s2) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 121 "/usr/include/strings.h"
extern int strncasecmp(const char *__s1, const char *__s2,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 129 "/usr/include/strings.h"
extern int strcasecmp_l(const char *__s1, const char *__s2,  locale_t __loc) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2, 3 )  )) ; 
#line 135 "/usr/include/strings.h"
extern int strncasecmp_l(const char *__s1, const char *__s2,  size_t __n,  locale_t __loc) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1, 2, 4 )  )) ; 
#line 435 "/usr/include/string.h"
extern void explicit_bzero(void *__s,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 441 "/usr/include/string.h"
extern char *strsep(char **__restrict __stringp, const char *__restrict __delim) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 446 "/usr/include/string.h"
extern char *strsignal(int __sig) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 450 "/usr/include/string.h"
extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 452 "/usr/include/string.h"
extern char *stpcpy(char *__restrict __dest, const char *__restrict __src) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 458 "/usr/include/string.h"
extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 461 "/usr/include/string.h"
extern char *stpncpy(char *__restrict __dest, const char *__restrict __src,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
# 432 "/usr/include/string.h" 2 3 4
# 498 "/usr/include/string.h" 3 4
# 9 "OperatingSystem.c" 2
# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4
# 39 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 36 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap-16.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 46 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline unsigned int __bswap_32(unsigned int __bsx)  
# 863 "OperatingSystemAspect.c"
{
# 865 "OperatingSystemAspect.c"
unsigned int retValue_acc;




# 871 "OperatingSystemAspect.c"
{

#line 47 "/usr/include/x86_64-linux-gnu/bits/byteswap.h"

# 876 "OperatingSystemAspect.c"
retValue_acc = __builtin_bswap32(__bsx);
# 878 "OperatingSystemAspect.c"
return (unsigned int )retValue_acc;
 
# 881 "OperatingSystemAspect.c"

}

# 885 "OperatingSystemAspect.c"
return (unsigned int )retValue_acc;

# 888 "OperatingSystemAspect.c"

}
 
#line 109 "/usr/include/x86_64-linux-gnu/bits/byteswap.h"
static __inline  __uint64_t __bswap_64( __uint64_t __bsx)  
# 894 "OperatingSystemAspect.c"
{
# 896 "OperatingSystemAspect.c"
__uint64_t retValue_acc;




# 902 "OperatingSystemAspect.c"
{

#line 110 "/usr/include/x86_64-linux-gnu/bits/byteswap.h"

# 907 "OperatingSystemAspect.c"
retValue_acc = __builtin_bswap64(__bsx);
# 909 "OperatingSystemAspect.c"
return (__uint64_t )retValue_acc;
 
# 912 "OperatingSystemAspect.c"

}

# 916 "OperatingSystemAspect.c"
return (__uint64_t )retValue_acc;

# 919 "OperatingSystemAspect.c"

}
 
# 108 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 61 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3 4
static __inline  __uint16_t __uint16_identity( __uint16_t __x)  
# 928 "OperatingSystemAspect.c"
{
# 930 "OperatingSystemAspect.c"
__uint16_t retValue_acc;




# 936 "OperatingSystemAspect.c"
{

#line 34 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h"

# 941 "OperatingSystemAspect.c"
retValue_acc = __x;
# 943 "OperatingSystemAspect.c"
return (__uint16_t )retValue_acc;
 
# 946 "OperatingSystemAspect.c"

}

# 950 "OperatingSystemAspect.c"
return (__uint16_t )retValue_acc;

# 953 "OperatingSystemAspect.c"

}
 
#line 38 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h"
static __inline  __uint32_t __uint32_identity( __uint32_t __x)  
# 959 "OperatingSystemAspect.c"
{
# 961 "OperatingSystemAspect.c"
__uint32_t retValue_acc;




# 967 "OperatingSystemAspect.c"
{

#line 39 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h"

# 972 "OperatingSystemAspect.c"
retValue_acc = __x;
# 974 "OperatingSystemAspect.c"
return (__uint32_t )retValue_acc;
 
# 977 "OperatingSystemAspect.c"

}

# 981 "OperatingSystemAspect.c"
return (__uint32_t )retValue_acc;

# 984 "OperatingSystemAspect.c"

}
 
#line 43 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h"
static __inline  __uint64_t __uint64_identity( __uint64_t __x)  
# 990 "OperatingSystemAspect.c"
{
# 992 "OperatingSystemAspect.c"
__uint64_t retValue_acc;




# 998 "OperatingSystemAspect.c"
{

#line 44 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h"

# 1003 "OperatingSystemAspect.c"
retValue_acc = __x;
# 1005 "OperatingSystemAspect.c"
return (__uint64_t )retValue_acc;
 
# 1008 "OperatingSystemAspect.c"

}

# 1012 "OperatingSystemAspect.c"
return (__uint64_t )retValue_acc;

# 1015 "OperatingSystemAspect.c"

}
 
# 62 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/ctype.h" 2 3 4
enum {_ISupper=(((0) < 8?((1 << (0)) << 8):((1 << (0)) >> 8))),_ISlower=(((1) < 8?((1 << (1)) << 8):((1 << (1)) >> 8))),_ISalpha=(((2) < 8?((1 << (2)) << 8):((1 << (2)) >> 8))),_ISdigit=(((3) < 8?((1 << (3)) << 8):((1 << (3)) >> 8))),_ISxdigit=(((4) < 8?((1 << (4)) << 8):((1 << (4)) >> 8))),_ISspace=(((5) < 8?((1 << (5)) << 8):((1 << (5)) >> 8))),_ISprint=(((6) < 8?((1 << (6)) << 8):((1 << (6)) >> 8))),_ISgraph=(((7) < 8?((1 << (7)) << 8):((1 << (7)) >> 8))),_ISblank=(((8) < 8?((1 << (8)) << 8):((1 << (8)) >> 8))),_IScntrl=(((9) < 8?((1 << (9)) << 8):((1 << (9)) >> 8))),_ISpunct=(((10) < 8?((1 << (10)) << 8):((1 << (10)) >> 8))),_ISalnum=(((11) < 8?((1 << (11)) << 8):((1 << (11)) >> 8)))}; 
#line 80 "/usr/include/ctype.h"
extern const unsigned short int **__ctype_b_loc(void ) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 82 "/usr/include/ctype.h"
extern const  __int32_t **__ctype_tolower_loc(void ) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 84 "/usr/include/ctype.h"
extern const  __int32_t **__ctype_toupper_loc(void ) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
# 79 "/usr/include/ctype.h" 3 4
# 108 "/usr/include/ctype.h" 3 4
extern int isalnum(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 109 "/usr/include/ctype.h"
extern int isalpha(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 110 "/usr/include/ctype.h"
extern int iscntrl(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 111 "/usr/include/ctype.h"
extern int isdigit(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 112 "/usr/include/ctype.h"
extern int islower(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 113 "/usr/include/ctype.h"
extern int isgraph(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 114 "/usr/include/ctype.h"
extern int isprint(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 115 "/usr/include/ctype.h"
extern int ispunct(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 116 "/usr/include/ctype.h"
extern int isspace(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 117 "/usr/include/ctype.h"
extern int isupper(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 118 "/usr/include/ctype.h"
extern int isxdigit(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 122 "/usr/include/ctype.h"
extern int tolower(int __c) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 125 "/usr/include/ctype.h"
extern int toupper(int __c) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 130 "/usr/include/ctype.h"
extern int isblank(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 142 "/usr/include/ctype.h"
extern int isascii(int __c) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 146 "/usr/include/ctype.h"
extern int toascii(int __c) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 150 "/usr/include/ctype.h"
extern int _toupper(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 151 "/usr/include/ctype.h"
extern int _tolower(int ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 142 "/usr/include/ctype.h" 3 4
# 251 "/usr/include/ctype.h" 3 4
extern int isalnum_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 252 "/usr/include/ctype.h"
extern int isalpha_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 253 "/usr/include/ctype.h"
extern int iscntrl_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 254 "/usr/include/ctype.h"
extern int isdigit_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 255 "/usr/include/ctype.h"
extern int islower_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 256 "/usr/include/ctype.h"
extern int isgraph_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 257 "/usr/include/ctype.h"
extern int isprint_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 258 "/usr/include/ctype.h"
extern int ispunct_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 259 "/usr/include/ctype.h"
extern int isspace_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 260 "/usr/include/ctype.h"
extern int isupper_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 261 "/usr/include/ctype.h"
extern int isxdigit_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 263 "/usr/include/ctype.h"
extern int isblank_l(int ,  locale_t ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 267 "/usr/include/ctype.h"
extern int __tolower_l(int __c,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 268 "/usr/include/ctype.h"
extern int tolower_l(int __c,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 271 "/usr/include/ctype.h"
extern int __toupper_l(int __c,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 272 "/usr/include/ctype.h"
extern int toupper_l(int __c,  locale_t __l) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 327 "/usr/include/ctype.h" 3 4
# 10 "OperatingSystem.c" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 25 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 26 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 328 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 3 4
typedef int wchar_t; 
# 32 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 57 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 3 4
typedef enum {P_ALL,P_PID,P_PGID}idtype_t; 
# 40 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 55 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 121 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
# 62 "/usr/include/stdlib.h" 2 3 4
typedef struct {int quot; int rem; 
}div_t; 
#line 70 "/usr/include/stdlib.h"
typedef struct {long int quot; long int rem; 
}ldiv_t; 
#line 80 "/usr/include/stdlib.h"
 __extension__ typedef struct {long long int quot; long long int rem; 
}lldiv_t; 
#line 97 "/usr/include/stdlib.h"
extern  size_t __ctype_get_mb_cur_max(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 102 "/usr/include/stdlib.h"
extern double atof(const char *__nptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 105 "/usr/include/stdlib.h"
extern int atoi(const char *__nptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 108 "/usr/include/stdlib.h"
extern long int atol(const char *__nptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 113 "/usr/include/stdlib.h"
 __extension__ extern long long int atoll(const char *__nptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 119 "/usr/include/stdlib.h"
extern double strtod(const char *__restrict __nptr, char **__restrict __endptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 124 "/usr/include/stdlib.h"
extern float strtof(const char *__restrict __nptr, char **__restrict __endptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 128 "/usr/include/stdlib.h"
extern long double strtold(const char *__restrict __nptr, char **__restrict __endptr) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 97 "/usr/include/stdlib.h" 3 4
# 178 "/usr/include/stdlib.h" 3 4
extern long int strtol(const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 182 "/usr/include/stdlib.h"
extern unsigned long int strtoul(const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 189 "/usr/include/stdlib.h"
 __extension__ extern long long int strtoq(const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 194 "/usr/include/stdlib.h"
 __extension__ extern unsigned long long int strtouq(const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 202 "/usr/include/stdlib.h"
 __extension__ extern long long int strtoll(const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 207 "/usr/include/stdlib.h"
 __extension__ extern unsigned long long int strtoull(const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 385 "/usr/include/stdlib.h"
extern char *l64a(long int __n) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 389 "/usr/include/stdlib.h"
extern long int a64l(const char *__s) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __pure__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 385 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef  __u_char u_char; 
#line 34 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __u_short u_short; 
#line 35 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __u_int u_int; 
#line 36 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __u_long u_long; 
#line 37 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __quad_t quad_t; 
#line 38 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __u_quad_t u_quad_t; 
#line 39 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __fsid_t fsid_t; 
#line 44 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __loff_t loff_t; 
#line 48 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __ino_t ino_t; 
#line 60 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __dev_t dev_t; 
#line 65 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __gid_t gid_t; 
#line 70 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __mode_t mode_t; 
#line 75 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __nlink_t nlink_t; 
#line 80 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __uid_t uid_t; 
# 60 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 98 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef  __pid_t pid_t; 
#line 104 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __id_t id_t; 
#line 115 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __daddr_t daddr_t; 
#line 116 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __caddr_t caddr_t; 
#line 122 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __key_t key_t; 
# 115 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 7 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 1 3 4
typedef  __clock_t clock_t; 
# 128 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 7 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 1 3 4
typedef  __clockid_t clockid_t; 
# 130 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 7 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 1 3 4
typedef  __time_t time_t; 
# 131 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 7 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 1 3 4
typedef  __timer_t timer_t; 
# 132 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 149 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
typedef unsigned long int ulong; 
#line 150 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned short int ushort; 
#line 151 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned int uint; 
# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
typedef  __int8_t int8_t; 
#line 25 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h"
typedef  __int16_t int16_t; 
#line 26 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h"
typedef  __int32_t int32_t; 
#line 27 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h"
typedef  __int64_t int64_t; 
# 157 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 178 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef unsigned int u_int8_t __attribute__  (( __mode__ ( __QI__ )  )) ; 
#line 179 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned int u_int16_t __attribute__  (( __mode__ ( __HI__ )  )) ; 
#line 180 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned int u_int32_t __attribute__  (( __mode__ ( __SI__ )  )) ; 
#line 181 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned int u_int64_t __attribute__  (( __mode__ ( __DI__ )  )) ; 
#line 183 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef int register_t __attribute__  (( __mode__ ( __word__ )  )) ; 
# 197 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/select.h" 2 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 1 3 4
# 8 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4
typedef struct {unsigned long int __val[(1024 / (8 * sizeof (unsigned long int )))]; 
}__sigset_t; 
#line 7 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h"
typedef  __sigset_t sigset_t; 
# 5 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4
# 12 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 1 3 4
struct timeval { __time_t tv_sec;  __suseconds_t tv_usec; 
}; 
# 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4
# 12 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
struct timespec { __time_t tv_sec;  __syscall_slong_t tv_nsec; 
}; 
#line 43 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef  __suseconds_t suseconds_t; 
#line 49 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef long int __fd_mask; 
# 40 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4
# 70 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct { __fd_mask __fds_bits[1024 / (8 * ((int )sizeof ( __fd_mask )))]; 
}fd_set; 
#line 77 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef  __fd_mask fd_mask; 
# 91 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 104 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select(int __nfds,  fd_set *__restrict __readfds,  fd_set *__restrict __writefds,  fd_set *__restrict __exceptfds, struct timeval *__restrict __timeout); 
#line 117 "/usr/include/x86_64-linux-gnu/sys/select.h"
extern int pselect(int __nfds,  fd_set *__restrict __readfds,  fd_set *__restrict __writefds,  fd_set *__restrict __exceptfds, const struct timespec *__restrict __timeout, const  __sigset_t *__restrict __sigmask); 
# 113 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 126 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 198 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 1 3 4
# 41 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/sysmacros.h" 1 3 4
# 42 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 2 3 4
# 73 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4
extern unsigned int gnu_dev_major( __dev_t __dev) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 74 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h"
extern unsigned int gnu_dev_minor( __dev_t __dev) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 75 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h"
extern  __dev_t gnu_dev_makedev(unsigned int __major, unsigned int __minor) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
# 85 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4
# 212 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
typedef  __blksize_t blksize_t; 
#line 219 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __blkcnt_t blkcnt_t; 
#line 223 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __fsblkcnt_t fsblkcnt_t; 
#line 227 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef  __fsfilcnt_t fsfilcnt_t; 
# 254 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 1 3 4
# 77 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 2 3 4
# 65 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
# 99 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
struct __pthread_rwlock_arch_t {unsigned int __readers; unsigned int __writers; unsigned int __wrphase_futex; unsigned int __writers_futex; unsigned int __pad3; unsigned int __pad4; int __cur_writer; int __shared; signed char __rwelision; unsigned char __pad1[7]; unsigned long int __pad2; unsigned int __flags; 
}; 
#line 86 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
typedef struct __pthread_internal_list {struct __pthread_internal_list *__prev; struct __pthread_internal_list *__next; 
}__pthread_list_t; 
# 78 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4
# 118 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 146 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
struct __pthread_mutex_s {int __lock; unsigned int __count; int __owner; unsigned int __nusers; int __kind; short __spins; short __elision;  __pthread_list_t __list; 
}; 
#line 176 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
struct __pthread_cond_s { __extension__ union { __extension__ unsigned long long int __wseq; struct {unsigned int __low; unsigned int __high; 
}__wseq32; 
};  __extension__ union { __extension__ unsigned long long int __g1_start; struct {unsigned int __low; unsigned int __high; 
}__g1_start32; 
}; unsigned int __g_refs[2]; unsigned int __g_size[2]; unsigned int __g1_orig_size; unsigned int __wrefs; unsigned int __g_signals[2]; 
}; 
#line 27 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef unsigned long int pthread_t; 
#line 36 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {char __size[4]; int __align; 
}pthread_mutexattr_t; 
#line 45 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {char __size[4]; int __align; 
}pthread_condattr_t; 
#line 49 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef unsigned int pthread_key_t; 
#line 53 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef int pthread_once_t; 
#line 60 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
union pthread_attr_t {char __size[56]; long int __align; 
}; 
#line 62 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_attr_t pthread_attr_t; 
#line 72 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {struct __pthread_mutex_s __data; char __size[40]; long int __align; 
}pthread_mutex_t; 
#line 80 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {struct __pthread_cond_s __data; char __size[48];  __extension__ long long int __align; 
}pthread_cond_t; 
#line 91 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {struct __pthread_rwlock_arch_t __data; char __size[56]; long int __align; 
}pthread_rwlock_t; 
#line 97 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {char __size[8]; long int __align; 
}pthread_rwlockattr_t; 
#line 103 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef volatile int pthread_spinlock_t; 
#line 112 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {char __size[32]; long int __align; 
}pthread_barrier_t; 
#line 118 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union {char __size[4]; int __align; 
}pthread_barrierattr_t; 
# 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4
# 255 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 401 "/usr/include/stdlib.h" 2 3 4
extern long int random(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 404 "/usr/include/stdlib.h"
extern void srandom(unsigned int __seed) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 411 "/usr/include/stdlib.h"
extern char *initstate(unsigned int __seed, char *__statebuf,  size_t __statelen) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
#line 415 "/usr/include/stdlib.h"
extern char *setstate(char *__statebuf) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 432 "/usr/include/stdlib.h"
struct random_data { int32_t *fptr;  int32_t *rptr;  int32_t *state; int rand_type; int rand_deg; int rand_sep;  int32_t *end_ptr; 
}; 
#line 435 "/usr/include/stdlib.h"
extern int random_r(struct random_data *__restrict __buf,  int32_t *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 438 "/usr/include/stdlib.h"
extern int srandom_r(unsigned int __seed, struct random_data *__buf) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
#line 443 "/usr/include/stdlib.h"
extern int initstate_r(unsigned int __seed, char *__restrict __statebuf,  size_t __statelen, struct random_data *__restrict __buf) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2, 4 )  )) ; 
#line 447 "/usr/include/stdlib.h"
extern int setstate_r(char *__restrict __statebuf, struct random_data *__restrict __buf) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 453 "/usr/include/stdlib.h"
extern int rand(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 455 "/usr/include/stdlib.h"
extern void srand(unsigned int __seed) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 459 "/usr/include/stdlib.h"
extern int rand_r(unsigned int *__seed) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 467 "/usr/include/stdlib.h"
extern double drand48(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 468 "/usr/include/stdlib.h"
extern double erand48(unsigned short int __xsubi[3]) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 471 "/usr/include/stdlib.h"
extern long int lrand48(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 473 "/usr/include/stdlib.h"
extern long int nrand48(unsigned short int __xsubi[3]) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 476 "/usr/include/stdlib.h"
extern long int mrand48(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 478 "/usr/include/stdlib.h"
extern long int jrand48(unsigned short int __xsubi[3]) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 481 "/usr/include/stdlib.h"
extern void srand48(long int __seedval) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 483 "/usr/include/stdlib.h"
extern unsigned short int *seed48(unsigned short int __seed16v[3]) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 484 "/usr/include/stdlib.h"
extern void lcong48(unsigned short int __param[7]) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 498 "/usr/include/stdlib.h"
struct drand48_data {unsigned short int __x[3]; unsigned short int __old_x[3]; unsigned short int __c; unsigned short int __init;  __extension__ unsigned long long int __a; 
}; 
#line 502 "/usr/include/stdlib.h"
extern int drand48_r(struct drand48_data *__restrict __buffer, double *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 505 "/usr/include/stdlib.h"
extern int erand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, double *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 510 "/usr/include/stdlib.h"
extern int lrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 514 "/usr/include/stdlib.h"
extern int nrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 519 "/usr/include/stdlib.h"
extern int mrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 523 "/usr/include/stdlib.h"
extern int jrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 527 "/usr/include/stdlib.h"
extern int srand48_r(long int __seedval, struct drand48_data *__buffer) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
#line 530 "/usr/include/stdlib.h"
extern int seed48_r(unsigned short int __seed16v[3], struct drand48_data *__buffer) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 534 "/usr/include/stdlib.h"
extern int lcong48_r(unsigned short int __param[7], struct drand48_data *__buffer) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2 )  )) ; 
#line 539 "/usr/include/stdlib.h"
extern void *malloc( size_t __size) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ )) ; 
#line 542 "/usr/include/stdlib.h"
extern void *calloc( size_t __nmemb,  size_t __size) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ )) ; 
#line 550 "/usr/include/stdlib.h"
extern void *realloc(void *__ptr,  size_t __size) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __warn_unused_result__ )) ; 
#line 563 "/usr/include/stdlib.h"
extern void free(void *__ptr) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 563 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 32 "/usr/include/alloca.h" 2 3 4
extern void *alloca( size_t __size) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 572 "/usr/include/stdlib.h"
extern void *valloc( size_t __size) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ )) ; 
#line 578 "/usr/include/stdlib.h"
extern int posix_memalign(void **__memptr,  size_t __alignment,  size_t __size) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 584 "/usr/include/stdlib.h"
extern void *aligned_alloc( size_t __alignment,  size_t __size) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __malloc__ ))  __attribute__  (( __alloc_size__ ( 2 )  )) ; 
#line 588 "/usr/include/stdlib.h"
extern void abort(void ) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __noreturn__ )) ; 
#line 592 "/usr/include/stdlib.h"
extern int atexit(void (*__func)(void )) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 600 "/usr/include/stdlib.h"
extern int at_quick_exit(void (*__func)(void )) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 608 "/usr/include/stdlib.h"
extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 614 "/usr/include/stdlib.h"
extern void exit(int __status) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __noreturn__ )) ; 
#line 620 "/usr/include/stdlib.h"
extern void quick_exit(int __status) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __noreturn__ )) ; 
#line 626 "/usr/include/stdlib.h"
extern void _Exit(int __status) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __noreturn__ )) ; 
#line 631 "/usr/include/stdlib.h"
extern char *getenv(const char *__name) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 567 "/usr/include/stdlib.h" 2 3 4
# 644 "/usr/include/stdlib.h" 3 4
extern int putenv(char *__string) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 651 "/usr/include/stdlib.h"
extern int setenv(const char *__name, const char *__value, int __replace) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 2 )  )) ; 
#line 654 "/usr/include/stdlib.h"
extern int unsetenv(const char *__name) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 661 "/usr/include/stdlib.h"
extern int clearenv(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 672 "/usr/include/stdlib.h"
extern char *mktemp(char *__template) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 672 "/usr/include/stdlib.h" 3 4
# 685 "/usr/include/stdlib.h" 3 4
extern int mkstemp(char *__template) __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 707 "/usr/include/stdlib.h"
extern int mkstemps(char *__template, int __suffixlen) __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 707 "/usr/include/stdlib.h" 3 4
# 728 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp(char *__template) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
#line 781 "/usr/include/stdlib.h"
extern int system(const char *__command); 
# 781 "/usr/include/stdlib.h" 3 4
# 798 "/usr/include/stdlib.h" 3 4
extern char *realpath(const char *__restrict __name, char *__restrict __resolved) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 805 "/usr/include/stdlib.h"
typedef int (*__compar_fn_t)(const void *, const void *); 
#line 819 "/usr/include/stdlib.h"
extern void *bsearch(const void *__key, const void *__base,  size_t __nmemb,  size_t __size,  __compar_fn_t __compar) __attribute__  (( __nonnull__ ( 1, 2, 5 )  )) ; 
#line 828 "/usr/include/stdlib.h"
extern void qsort(void *__base,  size_t __nmemb,  size_t __size,  __compar_fn_t __compar) __attribute__  (( __nonnull__ ( 1, 4 )  )) ; 
# 817 "/usr/include/stdlib.h" 3 4
# 837 "/usr/include/stdlib.h" 3 4
extern int abs(int __x) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 838 "/usr/include/stdlib.h"
extern long int labs(long int __x) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 842 "/usr/include/stdlib.h"
 __extension__ extern long long int llabs(long long int __x) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 850 "/usr/include/stdlib.h"
extern  div_t div(int __numer, int __denom) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 852 "/usr/include/stdlib.h"
extern  ldiv_t ldiv(long int __numer, long int __denom) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 857 "/usr/include/stdlib.h"
 __extension__ extern  lldiv_t lldiv(long long int __numer, long long int __denom) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 870 "/usr/include/stdlib.h"
extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4 )  )) ; 
#line 876 "/usr/include/stdlib.h"
extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4 )  )) ; 
#line 882 "/usr/include/stdlib.h"
extern char *gcvt(double __value, int __ndigit, char *__buf) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3 )  )) ; 
#line 889 "/usr/include/stdlib.h"
extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4 )  )) ; 
#line 892 "/usr/include/stdlib.h"
extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4 )  )) ; 
#line 894 "/usr/include/stdlib.h"
extern char *qgcvt(long double __value, int __ndigit, char *__buf) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3 )  )) ; 
#line 901 "/usr/include/stdlib.h"
extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf,  size_t __len) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4, 5 )  )) ; 
#line 904 "/usr/include/stdlib.h"
extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf,  size_t __len) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4, 5 )  )) ; 
#line 909 "/usr/include/stdlib.h"
extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf,  size_t __len) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4, 5 )  )) ; 
#line 913 "/usr/include/stdlib.h"
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf,  size_t __len) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 3, 4, 5 )  )) ; 
#line 919 "/usr/include/stdlib.h"
extern int mblen(const char *__s,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 923 "/usr/include/stdlib.h"
extern int mbtowc( wchar_t *__restrict __pwc, const char *__restrict __s,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 926 "/usr/include/stdlib.h"
extern int wctomb(char *__s,  wchar_t __wchar) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 931 "/usr/include/stdlib.h"
extern  size_t mbstowcs( wchar_t *__restrict __pwcs, const char *__restrict __s,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 935 "/usr/include/stdlib.h"
extern  size_t wcstombs(char *__restrict __s, const  wchar_t *__restrict __pwcs,  size_t __n) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 943 "/usr/include/stdlib.h"
extern int rpmatch(const char *__response) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 869 "/usr/include/stdlib.h" 3 4
# 957 "/usr/include/stdlib.h" 3 4
extern int getsubopt(char **__restrict __optionp, char *const *__restrict __tokens, char **__restrict __valuep) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1, 2, 3 )  )) ; 
#line 1007 "/usr/include/stdlib.h"
extern int getloadavg(double __loadavg[], int __nelem) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 1006 "/usr/include/stdlib.h" 3 4
# 1016 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 1017 "/usr/include/stdlib.h" 2 3 4
# 1026 "/usr/include/stdlib.h" 3 4
# 11 "OperatingSystem.c" 2
# 1 "/usr/include/time.h" 1 3 4
# 29 "/usr/include/time.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h" 1 3 4
# 30 "/usr/include/time.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 34 "/usr/include/time.h" 2 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/types/struct_tm.h" 1 3 4
struct tm {int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; int tm_yday; int tm_isdst; long int tm_gmtoff; const char *tm_zone; 
}; 
# 40 "/usr/include/time.h" 2 3 4
# 48 "/usr/include/time.h" 3 4
# 12 "/usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h" 1 3 4
struct itimerspec {struct timespec it_interval; struct timespec it_value; 
}; 
#line 49 "/usr/include/time.h"
struct sigevent ; 
# 49 "/usr/include/time.h" 2 3 4
# 72 "/usr/include/time.h" 3 4
extern  clock_t clock(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 75 "/usr/include/time.h"
extern  time_t time( time_t *__timer) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 79 "/usr/include/time.h"
extern double difftime( time_t __time1,  time_t __time0) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
#line 82 "/usr/include/time.h"
extern  time_t mktime(struct tm *__tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 90 "/usr/include/time.h"
extern  size_t strftime(char *__restrict __s,  size_t __maxsize, const char *__restrict __format, const struct tm *__restrict __tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 107 "/usr/include/time.h"
extern  size_t strftime_l(char *__restrict __s,  size_t __maxsize, const char *__restrict __format, const struct tm *__restrict __tp,  locale_t __loc) __attribute__  (( __nothrow__ , __leaf__ )) ; 
# 104 "/usr/include/time.h" 3 4
# 119 "/usr/include/time.h" 3 4
extern struct tm *gmtime(const  time_t *__timer) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 123 "/usr/include/time.h"
extern struct tm *localtime(const  time_t *__timer) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 129 "/usr/include/time.h"
extern struct tm *gmtime_r(const  time_t *__restrict __timer, struct tm *__restrict __tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 134 "/usr/include/time.h"
extern struct tm *localtime_r(const  time_t *__restrict __timer, struct tm *__restrict __tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 139 "/usr/include/time.h"
extern char *asctime(const struct tm *__tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 142 "/usr/include/time.h"
extern char *ctime(const  time_t *__timer) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 150 "/usr/include/time.h"
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 154 "/usr/include/time.h"
extern char *ctime_r(const  time_t *__restrict __timer, char *__restrict __buf) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 159 "/usr/include/time.h"
extern char *__tzname[2]; 
#line 160 "/usr/include/time.h"
extern int __daylight; 
#line 161 "/usr/include/time.h"
extern long int __timezone; 
#line 166 "/usr/include/time.h"
extern char *tzname[2]; 
#line 170 "/usr/include/time.h"
extern void tzset(void ) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 174 "/usr/include/time.h"
extern int daylight; 
#line 175 "/usr/include/time.h"
extern long int timezone; 
#line 181 "/usr/include/time.h"
extern int stime(const  time_t *__when) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 196 "/usr/include/time.h"
extern  time_t timegm(struct tm *__tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 199 "/usr/include/time.h"
extern  time_t timelocal(struct tm *__tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 202 "/usr/include/time.h"
extern int dysize(int __year) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __const__ )) ; 
# 196 "/usr/include/time.h" 3 4
# 212 "/usr/include/time.h" 3 4
extern int nanosleep(const struct timespec *__requested_time, struct timespec *__remaining); 
#line 216 "/usr/include/time.h"
extern int clock_getres( clockid_t __clock_id, struct timespec *__res) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 219 "/usr/include/time.h"
extern int clock_gettime( clockid_t __clock_id, struct timespec *__tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 223 "/usr/include/time.h"
extern int clock_settime( clockid_t __clock_id, const struct timespec *__tp) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 232 "/usr/include/time.h"
extern int clock_nanosleep( clockid_t __clock_id, int __flags, const struct timespec *__req, struct timespec *__rem); 
#line 235 "/usr/include/time.h"
extern int clock_getcpuclockid( pid_t __pid,  clockid_t *__clock_id) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 242 "/usr/include/time.h"
extern int timer_create( clockid_t __clock_id, struct sigevent *__restrict __evp,  timer_t *__restrict __timerid) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 245 "/usr/include/time.h"
extern int timer_delete( timer_t __timerid) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 250 "/usr/include/time.h"
extern int timer_settime( timer_t __timerid, int __flags, const struct itimerspec *__restrict __value, struct itimerspec *__restrict __ovalue) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 254 "/usr/include/time.h"
extern int timer_gettime( timer_t __timerid, struct itimerspec *__value) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 257 "/usr/include/time.h"
extern int timer_getoverrun( timer_t __timerid) __attribute__  (( __nothrow__ , __leaf__ )) ; 
#line 264 "/usr/include/time.h"
extern int timespec_get(struct timespec *__ts, int __base) __attribute__  (( __nothrow__ , __leaf__ ))  __attribute__  (( __nonnull__ ( 1 )  )) ; 
# 307 "/usr/include/time.h" 3 4
# 12 "OperatingSystem.c" 2
# 14 "OperatingSystem.c" 
void OperatingSystem_PrepareDaemons(); 
#line 15 "OperatingSystem.c"
void OperatingSystem_PCBInitialization(int , int , int , int , int ); 
#line 16 "OperatingSystem.c"
void OperatingSystem_MoveToTheREADYState(int ); 
#line 17 "OperatingSystem.c"
void OperatingSystem_Dispatch(int ); 
#line 18 "OperatingSystem.c"
void OperatingSystem_RestoreContext(int ); 
#line 19 "OperatingSystem.c"
void OperatingSystem_SaveContext(int ); 
#line 20 "OperatingSystem.c"
void OperatingSystem_TerminateProcess(); 
#line 21 "OperatingSystem.c"
int OperatingSystem_LongTermScheduler(); 
#line 22 "OperatingSystem.c"
void OperatingSystem_PreemptRunningProcess(); 
#line 23 "OperatingSystem.c"
int OperatingSystem_CreateProcess(int ); 
#line 24 "OperatingSystem.c"
int OperatingSystem_ObtainMainMemory(int , int ); 
#line 25 "OperatingSystem.c"
int OperatingSystem_ShortTermScheduler(); 
#line 26 "OperatingSystem.c"
int OperatingSystem_ExtractFromReadyToRun(); 
#line 27 "OperatingSystem.c"
void OperatingSystem_HandleException(); 
#line 28 "OperatingSystem.c"
void OperatingSystem_HandleSystemCall(); 
#line 29 "OperatingSystem.c"
void OperatingSystem_PrintReadyToRunQueue(); 
#line 30 "OperatingSystem.c"
void OperatingSystem_SYSCALL_YIELD(); 
#line 31 "OperatingSystem.c"
void OperatingSystem_HandleClockInterrupt(); 
#line 32 "OperatingSystem.c"
void OperatingSystem_SYSCALL_SLEEP(); 
#line 33 "OperatingSystem.c"
void OperatingSystem_MoveToTheBLOCKEDState(int ); 
#line 34 "OperatingSystem.c"
void OperatingSystem_ExtractFromSleepingProcessesQueue(); 
#line 35 "OperatingSystem.c"
int OperatingSystem_MaxProirity(); 
#line 39 "OperatingSystem.c"
 PCB processTable[4]; 
#line 42 "OperatingSystem.c"
int OS_address_base = 4 * (300 / (4 + 1)); 
#line 45 "OperatingSystem.c"
int executingProcessID = (-1); 
#line 48 "OperatingSystem.c"
int sipID; 
#line 51 "OperatingSystem.c"
int initialPID = 4 - 1; 
#line 54 "OperatingSystem.c"
int baseDaemonsInProgramList; 
#line 57 "OperatingSystem.c"
 heapItem readyToRunQueue[2][4]; 
#line 58 "OperatingSystem.c"
int numberOfReadyToRunProcesses[2] = {0,0}; 
#line 61 "OperatingSystem.c"
 heapItem sleepingProcessesQueue[4]; 
#line 62 "OperatingSystem.c"
int numberOfSleepingProcesses = 0; 
#line 65 "OperatingSystem.c"
int numberOfNotTerminatedUserProcesses = 0; 
#line 68 "OperatingSystem.c"
char *statesNames[5] = {"NEW","READY","EXECUTING","BLOCKED","EXIT"}; 
#line 71 "OperatingSystem.c"
char *queueNames[2] = {"USER","DAEMONS"}; 
#line 74 "OperatingSystem.c"
int numberOfClockInterrupts = 0; 
#line 76 "OperatingSystem.c"
int userThrows = 0; 
#line 77 "OperatingSystem.c"
int daemonThrows = 0; 
#line 80 "OperatingSystem.c"
void OperatingSystem_Initialize(int daemonsIndex)  
# 1732 "OperatingSystemAspect.c"
{



# 1737 "OperatingSystemAspect.c"
{

#line 82 "OperatingSystem.c"

#line 82 "OperatingSystem.c"
int i,selectedProcess;
#line 83 "OperatingSystem.c"

#line 83 "OperatingSystem.c"
 FILE *programFile;
#line 86 "OperatingSystem.c"

#line 86 "OperatingSystem.c"
int processSize = OperatingSystem_ObtainProgramSize((&programFile), "OperatingSystemCode");
#line 89 "OperatingSystem.c"
OperatingSystem_LoadProgram(programFile, OS_address_base, processSize); 
#line 92 "OperatingSystem.c"
for(i = 0;i < 4;i++) { { 
#line 93 "OperatingSystem.c"
processTable[i].busy = 0; } } 
#line 96 "OperatingSystem.c"
Processor_InitializeInterruptVectorTable(OS_address_base + 2); 
#line 99 "OperatingSystem.c"
OperatingSystem_PrepareDaemons(daemonsIndex); 
#line 102 "OperatingSystem.c"
OperatingSystem_LongTermScheduler(); 
#line 104 "OperatingSystem.c"
if (numberOfNotTerminatedUserProcesses <= 0){
{ 
#line 105 "OperatingSystem.c"
OperatingSystem_TerminatingSIP(); 
#line 106 "OperatingSystem.c"
OperatingSystem_ShowTime('d'); 
#line 107 "OperatingSystem.c"
ComputerSystem_DebugMessage(99, 'd', "The system will shut down now...\n"); 
#line 108 "OperatingSystem.c"
OperatingSystem_ReadyToShutdown(); } }
#line 113 "OperatingSystem.c"
if (strcmp((programList[processTable[sipID].programListIndex]->executableName), "SystemIdleProcess")){
{ 
#line 115 "OperatingSystem.c"
OperatingSystem_ShowTime('d'); 
#line 116 "OperatingSystem.c"
ComputerSystem_DebugMessage(99, 'd', "FATAL ERROR: Missing SIP program!\n"); 
#line 117 "OperatingSystem.c"
exit(1); } }
#line 122 "OperatingSystem.c"
selectedProcess = OperatingSystem_ShortTermScheduler(); 
#line 125 "OperatingSystem.c"
OperatingSystem_Dispatch(selectedProcess); 
#line 128 "OperatingSystem.c"
Processor_SetPC(OS_address_base); 
# 1790 "OperatingSystemAspect.c"

}

# 1794 "OperatingSystemAspect.c"

}
 
  void __utac_acc__Aspect__4 (void);


#line 133 "OperatingSystem.c"
void OperatingSystem_PrepareDaemons(int programListDaemonsBase)  
# 1803 "OperatingSystemAspect.c"
{



# 1808 "OperatingSystemAspect.c"
{

#line 136 "OperatingSystem.c"
programList[0] = (( PROGRAMS_DATA *)malloc(sizeof ( PROGRAMS_DATA ))); 
#line 137 "OperatingSystem.c"
(programList[0]->executableName) = "SystemIdleProcess"; 
#line 138 "OperatingSystem.c"
(programList[0]->arrivalTime) = 0; 
#line 139 "OperatingSystem.c"
(programList[0]->type) = DAEMONPROGRAM; 
#line 141 "OperatingSystem.c"
sipID = initialPID % 4; 
#line 145 "OperatingSystem.c"
baseDaemonsInProgramList = programListDaemonsBase; 
# 1823 "OperatingSystemAspect.c"

}

{
__utac_acc__Aspect__4();

}

# 1832 "OperatingSystemAspect.c"

}
 
#line 153 "OperatingSystem.c"
int OperatingSystem_LongTermScheduler()  
# 1838 "OperatingSystemAspect.c"
{
# 1840 "OperatingSystemAspect.c"
int retValue_acc;




# 1846 "OperatingSystemAspect.c"
{

#line 156 "OperatingSystem.c"

#line 156 "OperatingSystem.c"
int PID,i,numberOfSuccessfullyCreatedProcesses = 0;
#line 158 "OperatingSystem.c"
for(i = 0;programList[i] != (((void *)0)) && i < 20;i++) { { 
# 158 "OperatingSystem.c" 3 4
# 159 "OperatingSystem.c" 
PID = OperatingSystem_CreateProcess(i); 
#line 160 "OperatingSystem.c"
if (PID < 0){
{ 
#line 165 "OperatingSystem.c"
if (PID == (-3)){
{ 
#line 162 "OperatingSystem.c"
OperatingSystem_ShowTime('e'); 
#line 163 "OperatingSystem.c"
ComputerSystem_DebugMessage(103, 'e', (programList[i]->executableName)); } }
#line 165 "OperatingSystem.c"
if (PID == (-1)){
{ 
#line 166 "OperatingSystem.c"
OperatingSystem_ShowTime('e'); 
#line 167 "OperatingSystem.c"
ComputerSystem_DebugMessage(104, 'e', (programList[i]->executableName), "it does not exist"); } }
#line 169 "OperatingSystem.c"
if (PID == (-2)){
{ 
#line 170 "OperatingSystem.c"
OperatingSystem_ShowTime('e'); 
#line 171 "OperatingSystem.c"
ComputerSystem_DebugMessage(104, 'e', (programList[i]->executableName), "invalid priority or size"); } }
#line 173 "OperatingSystem.c"
if (PID == (-4)){
{ 
#line 174 "OperatingSystem.c"
OperatingSystem_ShowTime('e'); 
#line 175 "OperatingSystem.c"
ComputerSystem_DebugMessage(105, 'e', (programList[i]->executableName)); } }} }else{
{ 
#line 179 "OperatingSystem.c"
numberOfSuccessfullyCreatedProcesses++; 
#line 180 "OperatingSystem.c"
if ((programList[i]->type) == USERPROGRAM){
numberOfNotTerminatedUserProcesses++; }
#line 183 "OperatingSystem.c"
OperatingSystem_MoveToTheREADYState(PID); } }} } 
#line 188 "OperatingSystem.c"
if (numberOfSuccessfullyCreatedProcesses > 0){
{ 
#line 189 "OperatingSystem.c"
OperatingSystem_PrintStatus(); } }
#line 193 "OperatingSystem.c"

# 1904 "OperatingSystemAspect.c"
retValue_acc = numberOfSuccessfullyCreatedProcesses;
# 1906 "OperatingSystemAspect.c"
return (int )retValue_acc;
 
# 1909 "OperatingSystemAspect.c"

}

# 1913 "OperatingSystemAspect.c"
return (int )retValue_acc;

# 1916 "OperatingSystemAspect.c"

}
 
#line 198 "OperatingSystem.c"
int OperatingSystem_CreateProcess(int indexOfExecutableProgram)  
# 1922 "OperatingSystemAspect.c"
{
# 1924 "OperatingSystemAspect.c"
int retValue_acc;




# 1930 "OperatingSystemAspect.c"
{

#line 200 "OperatingSystem.c"

#line 200 "OperatingSystem.c"
int PID;
#line 201 "OperatingSystem.c"

#line 201 "OperatingSystem.c"
int processSize;
#line 202 "OperatingSystem.c"

#line 202 "OperatingSystem.c"
int loadingPhysicalAddress;
#line 203 "OperatingSystem.c"

#line 203 "OperatingSystem.c"
int priority;
#line 204 "OperatingSystem.c"

#line 204 "OperatingSystem.c"
 FILE *programFile;
#line 205 "OperatingSystem.c"

#line 205 "OperatingSystem.c"
 PROGRAMS_DATA *executableProgram = programList[indexOfExecutableProgram];
#line 208 "OperatingSystem.c"
PID = OperatingSystem_ObtainAnEntryInTheProcessTable(); 
#line 209 "OperatingSystem.c"
if (PID == (-3)){
{ 
#line 210 "OperatingSystem.c"

# 1964 "OperatingSystemAspect.c"
retValue_acc = (-3);
# 1966 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }
#line 214 "OperatingSystem.c"
processSize = OperatingSystem_ObtainProgramSize((&programFile), (executableProgram->executableName)); 
#line 215 "OperatingSystem.c"
if (processSize == (-1)){
{ 
#line 216 "OperatingSystem.c"

# 1976 "OperatingSystemAspect.c"
retValue_acc = (-1);
# 1978 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }else{
if (processSize == (-2)){
{ 
#line 219 "OperatingSystem.c"

# 1985 "OperatingSystemAspect.c"
retValue_acc = (-2);
# 1987 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }}
#line 223 "OperatingSystem.c"
priority = OperatingSystem_ObtainPriority(programFile); 
#line 224 "OperatingSystem.c"
if (priority == (-2)){
{ 
#line 225 "OperatingSystem.c"

# 1997 "OperatingSystemAspect.c"
retValue_acc = (-2);
# 1999 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }
#line 229 "OperatingSystem.c"
if ((loadingPhysicalAddress = OperatingSystem_ObtainMainMemory(processSize, PID)) == (-4)){
{ 
#line 230 "OperatingSystem.c"

# 2007 "OperatingSystemAspect.c"
retValue_acc = (-4);
# 2009 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }
#line 234 "OperatingSystem.c"
if ((OperatingSystem_LoadProgram(programFile, loadingPhysicalAddress, processSize)) == (-4)){
{ 
#line 235 "OperatingSystem.c"

# 2017 "OperatingSystemAspect.c"
retValue_acc = (-4);
# 2019 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }
#line 240 "OperatingSystem.c"
OperatingSystem_PCBInitialization(PID, loadingPhysicalAddress, processSize, priority, indexOfExecutableProgram); 
#line 243 "OperatingSystem.c"
OperatingSystem_ShowTime('t'); 
#line 244 "OperatingSystem.c"
ComputerSystem_DebugMessage(70, 't', PID, (executableProgram->executableName)); 
#line 247 "OperatingSystem.c"

# 2030 "OperatingSystemAspect.c"
retValue_acc = PID;
# 2032 "OperatingSystemAspect.c"
return (int )retValue_acc;
 
# 2035 "OperatingSystemAspect.c"

}

# 2039 "OperatingSystemAspect.c"
return (int )retValue_acc;

# 2042 "OperatingSystemAspect.c"

}
 
#line 253 "OperatingSystem.c"
int OperatingSystem_ObtainMainMemory(int processSize, int PID)  
# 2048 "OperatingSystemAspect.c"
{
# 2050 "OperatingSystemAspect.c"
int retValue_acc;




# 2056 "OperatingSystemAspect.c"
{

#line 258 "OperatingSystem.c"
if (processSize > (300 / (4 + 1))){

# 2062 "OperatingSystemAspect.c"
retValue_acc = (-4);
# 2064 "OperatingSystemAspect.c"
return (int )retValue_acc;
 }
#line 258 "OperatingSystem.c"

# 2069 "OperatingSystemAspect.c"
retValue_acc = PID * (300 / (4 + 1));
# 2071 "OperatingSystemAspect.c"
return (int )retValue_acc;
 
# 2074 "OperatingSystemAspect.c"

}

# 2078 "OperatingSystemAspect.c"
return (int )retValue_acc;

# 2081 "OperatingSystemAspect.c"

}
 
#line 263 "OperatingSystem.c"
void OperatingSystem_PCBInitialization(int PID, int initialPhysicalAddress, int processSize, int priority, int processPLIndex)  
# 2087 "OperatingSystemAspect.c"
{



# 2092 "OperatingSystemAspect.c"
{

#line 265 "OperatingSystem.c"
processTable[PID].busy = 1; 
#line 266 "OperatingSystem.c"
processTable[PID].initialPhysicalAddress = initialPhysicalAddress; 
#line 267 "OperatingSystem.c"
processTable[PID].processSize = processSize; 
#line 269 "OperatingSystem.c"
processTable[PID].state = NEW; 
#line 270 "OperatingSystem.c"
processTable[PID].priority = priority; 
#line 271 "OperatingSystem.c"
processTable[PID].programListIndex = processPLIndex; 
#line 274 "OperatingSystem.c"
processTable[PID].createTime = Clock_GetTime(); 
#line 275 "OperatingSystem.c"
processTable[PID].firstExecution = (-1); 
#line 278 "OperatingSystem.c"
if ((programList[processPLIndex]->type) == DAEMONPROGRAM){
{ 
#line 279 "OperatingSystem.c"
processTable[PID].copyOfPCRegister = initialPhysicalAddress; 
#line 280 "OperatingSystem.c"
processTable[PID].copyOfPSWRegister = (((unsigned int )1)) << EXECUTION_MODE_BIT; 
#line 281 "OperatingSystem.c"
processTable[PID].queueID = DAEMONSQUEUE; } }else{
{ 
#line 284 "OperatingSystem.c"
processTable[PID].queueID = USERPROCESSQUEUE; 
#line 285 "OperatingSystem.c"
processTable[PID].copyOfPCRegister = 0; 
#line 286 "OperatingSystem.c"
processTable[PID].copyOfPSWRegister = 0; } }
#line 289 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 290 "OperatingSystem.c"
ComputerSystem_DebugMessage(111, 'p', PID, (programList[processTable[PID].programListIndex]->executableName), statesNames[0]); 
# 2131 "OperatingSystemAspect.c"

}

# 2135 "OperatingSystemAspect.c"

}
 
#line 297 "OperatingSystem.c"
void OperatingSystem_MoveToTheREADYState(int PID)  
# 2141 "OperatingSystemAspect.c"
{



# 2146 "OperatingSystemAspect.c"
{

#line 299 "OperatingSystem.c"

#line 299 "OperatingSystem.c"
int queueID = processTable[PID].queueID;
#line 300 "OperatingSystem.c"
if (Heap_add(PID, readyToRunQueue[queueID], 1, (&numberOfReadyToRunProcesses[queueID]), 4) >= 0){
{ 
#line 301 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 302 "OperatingSystem.c"
ComputerSystem_DebugMessage(110, 'p', PID, (programList[processTable[PID].programListIndex]->executableName), statesNames[processTable[PID].state], statesNames[1]); 
#line 303 "OperatingSystem.c"
processTable[PID].state = READY; 
#line 304 "OperatingSystem.c"
processTable[PID].enterReady = Clock_GetTime(); } }
# 2164 "OperatingSystemAspect.c"

}

# 2168 "OperatingSystemAspect.c"

}
 
#line 314 "OperatingSystem.c"
int OperatingSystem_ShortTermScheduler()  
# 2174 "OperatingSystemAspect.c"
{
# 2176 "OperatingSystemAspect.c"
int retValue_acc;




# 2182 "OperatingSystemAspect.c"
{

#line 316 "OperatingSystem.c"

#line 316 "OperatingSystem.c"
int selectedProcess;
#line 318 "OperatingSystem.c"
selectedProcess = OperatingSystem_ExtractFromReadyToRun(); 
#line 320 "OperatingSystem.c"

# 2193 "OperatingSystemAspect.c"
retValue_acc = selectedProcess;
# 2195 "OperatingSystemAspect.c"
return (int )retValue_acc;
 
# 2198 "OperatingSystemAspect.c"

}

# 2202 "OperatingSystemAspect.c"
return (int )retValue_acc;

# 2205 "OperatingSystemAspect.c"

}
 
#line 325 "OperatingSystem.c"
int OperatingSystem_ExtractFromReadyToRun()  
# 2211 "OperatingSystemAspect.c"
{
# 2213 "OperatingSystemAspect.c"
int retValue_acc;




# 2219 "OperatingSystemAspect.c"
{

#line 327 "OperatingSystem.c"

#line 327 "OperatingSystem.c"
int selectedProcess = (-1);
#line 329 "OperatingSystem.c"
selectedProcess = Heap_poll(readyToRunQueue[USERPROCESSQUEUE], 1, (&numberOfReadyToRunProcesses[USERPROCESSQUEUE])); 
#line 331 "OperatingSystem.c"
if (selectedProcess == (-1)){
{ 
#line 332 "OperatingSystem.c"
selectedProcess = Heap_poll(readyToRunQueue[DAEMONSQUEUE], 1, (&numberOfReadyToRunProcesses[DAEMONSQUEUE])); } }
#line 336 "OperatingSystem.c"

# 2235 "OperatingSystemAspect.c"
retValue_acc = selectedProcess;
# 2237 "OperatingSystemAspect.c"
return (int )retValue_acc;
 
# 2240 "OperatingSystemAspect.c"

}

# 2244 "OperatingSystemAspect.c"
return (int )retValue_acc;

# 2247 "OperatingSystemAspect.c"

}
 
#line 341 "OperatingSystem.c"
void OperatingSystem_Dispatch(int PID)  
# 2253 "OperatingSystemAspect.c"
{



# 2258 "OperatingSystemAspect.c"
{

#line 344 "OperatingSystem.c"
executingProcessID = PID; 
#line 346 "OperatingSystem.c"
processTable[PID].state = EXECUTING; 
#line 347 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 348 "OperatingSystem.c"
ComputerSystem_DebugMessage(110, 'p', PID, (programList[processTable[PID].programListIndex]->executableName), statesNames[1], statesNames[2]); 
#line 350 "OperatingSystem.c"
OperatingSystem_RestoreContext(PID); 
#line 353 "OperatingSystem.c"
if (processTable[PID].firstExecution == (-1)){
{ 
#line 354 "OperatingSystem.c"
processTable[PID].firstExecution = Clock_GetTime(); } }
#line 356 "OperatingSystem.c"
processTable[PID].readyTime += Clock_GetTime() - processTable[PID].enterReady; 
# 2278 "OperatingSystemAspect.c"

}

# 2282 "OperatingSystemAspect.c"

}
 
#line 362 "OperatingSystem.c"
void OperatingSystem_RestoreContext(int PID)  
# 2288 "OperatingSystemAspect.c"
{



# 2293 "OperatingSystemAspect.c"
{

#line 365 "OperatingSystem.c"
Processor_CopyInSystemStack(300 - 1, processTable[PID].copyOfPCRegister); 
#line 366 "OperatingSystem.c"
Processor_CopyInSystemStack(300 - 2, processTable[PID].copyOfPSWRegister); 
#line 369 "OperatingSystem.c"
MMU_SetBase(processTable[PID].initialPhysicalAddress); 
#line 370 "OperatingSystem.c"
MMU_SetLimit(processTable[PID].processSize); 
#line 372 "OperatingSystem.c"
Processor_SetAccumulator(processTable[PID].copyOfRegisterAccumulator); 
# 2306 "OperatingSystemAspect.c"

}

# 2310 "OperatingSystemAspect.c"

}
 
#line 377 "OperatingSystem.c"
void OperatingSystem_PreemptRunningProcess()  
# 2316 "OperatingSystemAspect.c"
{



# 2321 "OperatingSystemAspect.c"
{

#line 380 "OperatingSystem.c"
OperatingSystem_SaveContext(executingProcessID); 
#line 382 "OperatingSystem.c"
OperatingSystem_MoveToTheREADYState(executingProcessID); 
#line 384 "OperatingSystem.c"
executingProcessID = (-1); 
# 2330 "OperatingSystemAspect.c"

}

# 2334 "OperatingSystemAspect.c"

}
 
#line 389 "OperatingSystem.c"
void OperatingSystem_SaveContext(int PID)  
# 2340 "OperatingSystemAspect.c"
{



# 2345 "OperatingSystemAspect.c"
{

#line 392 "OperatingSystem.c"
processTable[PID].copyOfPCRegister = Processor_CopyFromSystemStack(300 - 1); 
#line 395 "OperatingSystem.c"
processTable[PID].copyOfPSWRegister = Processor_CopyFromSystemStack(300 - 2); 
#line 397 "OperatingSystem.c"
processTable[PID].copyOfRegisterAccumulator = Processor_GetAccumulator(); 
# 2354 "OperatingSystemAspect.c"

}

# 2358 "OperatingSystemAspect.c"

}
 
#line 403 "OperatingSystem.c"
void OperatingSystem_HandleException()  
# 2364 "OperatingSystemAspect.c"
{



# 2369 "OperatingSystemAspect.c"
{

#line 406 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 407 "OperatingSystem.c"
ComputerSystem_DebugMessage(71, 'p', executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName)); 
#line 409 "OperatingSystem.c"
OperatingSystem_TerminateProcess(); 
#line 410 "OperatingSystem.c"
OperatingSystem_PrintStatus(); 
# 2380 "OperatingSystemAspect.c"

}

# 2384 "OperatingSystemAspect.c"

}
 
#line 415 "OperatingSystem.c"
void OperatingSystem_TerminateProcess()  
# 2390 "OperatingSystemAspect.c"
{



# 2395 "OperatingSystemAspect.c"
{

#line 417 "OperatingSystem.c"

#line 417 "OperatingSystem.c"
int selectedProcess;
#line 419 "OperatingSystem.c"
processTable[executingProcessID].state = EXIT; 
#line 421 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 422 "OperatingSystem.c"
ComputerSystem_DebugMessage(110, 'p', executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName), statesNames[2], statesNames[4]); 
#line 425 "OperatingSystem.c"
if ((programList[processTable[executingProcessID].programListIndex]->type) == USERPROGRAM){
numberOfNotTerminatedUserProcesses--; }
#line 430 "OperatingSystem.c"

#line 430 "OperatingSystem.c"
int resT = processTable[executingProcessID].firstExecution - processTable[executingProcessID].createTime;
#line 431 "OperatingSystem.c"

#line 431 "OperatingSystem.c"
int retT = Clock_GetTime() - processTable[executingProcessID].createTime;
#line 432 "OperatingSystem.c"

#line 432 "OperatingSystem.c"
int wT = processTable[executingProcessID].readyTime;
#line 433 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 434 "OperatingSystem.c"
ComputerSystem_DebugMessage(550, 'p', "response time", executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName), resT); 
#line 435 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 436 "OperatingSystem.c"
ComputerSystem_DebugMessage(550, 'p', "return time", executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName), retT); 
#line 437 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 438 "OperatingSystem.c"
ComputerSystem_DebugMessage(550, 'p', "waiting time", executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName), wT); 
#line 441 "OperatingSystem.c"
if (numberOfNotTerminatedUserProcesses == 0){
{ 
#line 457 "OperatingSystem.c"
if (executingProcessID == sipID){
{ 
#line 444 "OperatingSystem.c"
OperatingSystem_TerminatingSIP(); 
#line 445 "OperatingSystem.c"
OperatingSystem_ShowTime('d'); 
#line 446 "OperatingSystem.c"
ComputerSystem_DebugMessage(99, 'd', "The system will shut down now...\n"); 
#line 447 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 448 "OperatingSystem.c"
ComputerSystem_DebugMessage(551, 'p', userThrows); 
#line 450 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 451 "OperatingSystem.c"
ComputerSystem_DebugMessage(552, 'p', daemonThrows); 
#line 452 "OperatingSystem.c"
return ; 
 } }
#line 457 "OperatingSystem.c"
OperatingSystem_ReadyToShutdown(); } }
#line 466 "OperatingSystem.c"
selectedProcess = OperatingSystem_ShortTermScheduler(); 
#line 469 "OperatingSystem.c"
OperatingSystem_Dispatch(selectedProcess); 
# 2464 "OperatingSystemAspect.c"

}

# 2468 "OperatingSystemAspect.c"

}
 
#line 473 "OperatingSystem.c"
void OperatingSystem_HandleSystemCall()  
# 2474 "OperatingSystemAspect.c"
{



# 2479 "OperatingSystemAspect.c"
{

#line 475 "OperatingSystem.c"

#line 475 "OperatingSystem.c"
int systemCallID;
#line 478 "OperatingSystem.c"
systemCallID = Processor_GetRegisterA(); 
#line 480 "OperatingSystem.c"
switch(systemCallID){ { 
#line 483 "OperatingSystem.c"
case SYSCALL_PRINTEXECPID: OperatingSystem_ShowTime('p'); 
#line 484 "OperatingSystem.c"
ComputerSystem_DebugMessage(72, 'p', executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName)); 
#line 485 "OperatingSystem.c"
break; 
#line 487 "OperatingSystem.c"
case SYSCALL_END: OperatingSystem_ShowTime('p'); 
#line 490 "OperatingSystem.c"
ComputerSystem_DebugMessage(73, 'p', executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName)); 
#line 491 "OperatingSystem.c"
OperatingSystem_TerminateProcess(); 
#line 492 "OperatingSystem.c"
OperatingSystem_PrintStatus(); 
#line 493 "OperatingSystem.c"
break; 
#line 495 "OperatingSystem.c"
case SYSCALL_YIELD: OperatingSystem_SYSCALL_YIELD(); 
#line 497 "OperatingSystem.c"
break; 
#line 499 "OperatingSystem.c"
case SYSCALL_SLEEP: OperatingSystem_SYSCALL_SLEEP(); 
#line 501 "OperatingSystem.c"
OperatingSystem_PrintStatus(); 
#line 502 "OperatingSystem.c"
break; } } 
# 2516 "OperatingSystemAspect.c"

}

# 2520 "OperatingSystemAspect.c"

}
 
  void __utac_acc__Aspect__3 (void);


#line 508 "OperatingSystem.c"
void OperatingSystem_InterruptLogic(int entryPoint)  
# 2529 "OperatingSystemAspect.c"
{



{
__utac_acc__Aspect__3();

}

# 2539 "OperatingSystemAspect.c"
{

#line 519 "OperatingSystem.c"
switch(entryPoint){ { 
#line 511 "OperatingSystem.c"
case SYSCALL_BIT: OperatingSystem_HandleSystemCall(); 
#line 512 "OperatingSystem.c"
break; 
#line 513 "OperatingSystem.c"
case EXCEPTION_BIT: OperatingSystem_HandleException(); 
#line 515 "OperatingSystem.c"
break; 
#line 516 "OperatingSystem.c"
case CLOCKINT_BIT: OperatingSystem_HandleClockInterrupt(); 
#line 518 "OperatingSystem.c"
break; } } 
# 2556 "OperatingSystemAspect.c"

}

# 2560 "OperatingSystemAspect.c"

}
 
#line 525 "OperatingSystem.c"
void OperatingSystem_SYSCALL_YIELD()  
# 2566 "OperatingSystemAspect.c"
{



# 2571 "OperatingSystemAspect.c"
{

#line 528 "OperatingSystem.c"

#line 528 "OperatingSystem.c"
int actualPID = executingProcessID;
#line 529 "OperatingSystem.c"

#line 529 "OperatingSystem.c"
int queueID = processTable[actualPID].queueID;
#line 530 "OperatingSystem.c"

#line 530 "OperatingSystem.c"
int priority = processTable[actualPID].priority;
#line 531 "OperatingSystem.c"

#line 531 "OperatingSystem.c"
int newProcess = Heap_getFirst(readyToRunQueue[queueID], numberOfReadyToRunProcesses[queueID]);
#line 534 "OperatingSystem.c"
if (newProcess > (-1)){
{ 
#line 544 "OperatingSystem.c"
if (priority == processTable[newProcess].priority && newProcess != actualPID){
{ 
#line 536 "OperatingSystem.c"
Heap_poll(readyToRunQueue[queueID], 1, (&numberOfReadyToRunProcesses[queueID])); 
#line 537 "OperatingSystem.c"
OperatingSystem_ShowTime('s'); 
#line 538 "OperatingSystem.c"
ComputerSystem_DebugMessage(115, 's', actualPID, (programList[processTable[actualPID].programListIndex]->executableName), newProcess, (programList[processTable[newProcess].programListIndex]->executableName)); 
#line 539 "OperatingSystem.c"
OperatingSystem_PreemptRunningProcess(); 
#line 540 "OperatingSystem.c"
OperatingSystem_Dispatch(newProcess); 
#line 541 "OperatingSystem.c"
OperatingSystem_PrintStatus(); } }} }
# 2608 "OperatingSystemAspect.c"

}

# 2612 "OperatingSystemAspect.c"

}
 
#line 549 "OperatingSystem.c"
void OperatingSystem_PrintReadyToRunQueue()  
# 2618 "OperatingSystemAspect.c"
{



# 2623 "OperatingSystemAspect.c"
{

#line 551 "OperatingSystem.c"
OperatingSystem_ShowTime('s'); 
#line 552 "OperatingSystem.c"
ComputerSystem_DebugMessage(112, 's'); 
#line 553 "OperatingSystem.c"

#line 553 "OperatingSystem.c"
int i;
#line 554 "OperatingSystem.c"

#line 554 "OperatingSystem.c"
int j;
#line 556 "OperatingSystem.c"
for(i = 0;i < 2;i++) { { 
#line 557 "OperatingSystem.c"
ComputerSystem_DebugMessage(113, 's', queueNames[i]); 
#line 558 "OperatingSystem.c"
for(j = 0;j < numberOfReadyToRunProcesses[i];j++) { { 
#line 559 "OperatingSystem.c"

#line 559 "OperatingSystem.c"
int PID = readyToRunQueue[i][j].info;
#line 560 "OperatingSystem.c"
if (j == (numberOfReadyToRunProcesses[i] - 1)){
{ 
#line 561 "OperatingSystem.c"
ComputerSystem_DebugMessage(108, 's', PID, processTable[PID].priority, ""); } }else{
{ 
#line 564 "OperatingSystem.c"
ComputerSystem_DebugMessage(108, 's', PID, processTable[PID].priority, ","); } }} } 
#line 567 "OperatingSystem.c"
ComputerSystem_DebugMessage(109, 's'); } } 
# 2658 "OperatingSystemAspect.c"

}

# 2662 "OperatingSystemAspect.c"

}
 
#line 571 "OperatingSystem.c"
void OperatingSystem_HandleClockInterrupt()  
# 2668 "OperatingSystemAspect.c"
{



# 2673 "OperatingSystemAspect.c"
{

#line 572 "OperatingSystem.c"
numberOfClockInterrupts = numberOfClockInterrupts + 1; 
#line 573 "OperatingSystem.c"
OperatingSystem_ShowTime('i'); 
#line 574 "OperatingSystem.c"
ComputerSystem_DebugMessage(120, 'i', numberOfClockInterrupts); 
#line 576 "OperatingSystem.c"

#line 576 "OperatingSystem.c"
int i;
#line 577 "OperatingSystem.c"

#line 577 "OperatingSystem.c"
int actualSleep = numberOfSleepingProcesses;
#line 578 "OperatingSystem.c"
for(i = 0;i < actualSleep;i++) { { 
#line 582 "OperatingSystem.c"
if (numberOfClockInterrupts == processTable[sleepingProcessesQueue[i].info].whenToWakeUp){
{ 
#line 580 "OperatingSystem.c"
OperatingSystem_ExtractFromSleepingProcessesQueue(); } }} } 
#line 583 "OperatingSystem.c"
if (actualSleep != numberOfSleepingProcesses){
{ 
#line 584 "OperatingSystem.c"
OperatingSystem_PrintStatus(); } }
#line 587 "OperatingSystem.c"

#line 587 "OperatingSystem.c"
int newProcess = OperatingSystem_MaxProirity();
#line 588 "OperatingSystem.c"
if (newProcess != (-1)){
{ 
#line 589 "OperatingSystem.c"
OperatingSystem_ShowTime('s'); 
#line 590 "OperatingSystem.c"
ComputerSystem_DebugMessage(121, 's', executingProcessID, (programList[processTable[executingProcessID].programListIndex]->executableName), newProcess, (programList[processTable[newProcess].programListIndex]->executableName)); 
#line 591 "OperatingSystem.c"
OperatingSystem_PreemptRunningProcess(); 
#line 592 "OperatingSystem.c"
OperatingSystem_ExtractFromReadyToRun(); 
#line 593 "OperatingSystem.c"
OperatingSystem_Dispatch(newProcess); 
#line 594 "OperatingSystem.c"
OperatingSystem_PrintStatus(); } }
# 2721 "OperatingSystemAspect.c"

}

# 2725 "OperatingSystemAspect.c"

}
 
#line 600 "OperatingSystem.c"
void OperatingSystem_ExtractFromSleepingProcessesQueue()  
# 2731 "OperatingSystemAspect.c"
{



# 2736 "OperatingSystemAspect.c"
{

#line 602 "OperatingSystem.c"

#line 602 "OperatingSystem.c"
int PID = Heap_poll(sleepingProcessesQueue, 0, (&numberOfSleepingProcesses));
#line 603 "OperatingSystem.c"
if (PID != (-1)){
OperatingSystem_MoveToTheREADYState(PID); }
# 2746 "OperatingSystemAspect.c"

}

# 2750 "OperatingSystemAspect.c"

}
 
#line 607 "OperatingSystem.c"
void OperatingSystem_SYSCALL_SLEEP()  
# 2756 "OperatingSystemAspect.c"
{



# 2761 "OperatingSystemAspect.c"
{

#line 609 "OperatingSystem.c"

#line 609 "OperatingSystem.c"
int PID = executingProcessID;
#line 610 "OperatingSystem.c"
processTable[PID].whenToWakeUp = abs(Processor_GetAccumulator() + numberOfClockInterrupts + 1); 
#line 611 "OperatingSystem.c"
OperatingSystem_SaveContext(PID); 
#line 612 "OperatingSystem.c"
OperatingSystem_MoveToTheBLOCKEDState(PID); 
#line 613 "OperatingSystem.c"
executingProcessID = (-1); 
#line 614 "OperatingSystem.c"

#line 614 "OperatingSystem.c"
int newProcess = OperatingSystem_ShortTermScheduler();
#line 615 "OperatingSystem.c"
if (newProcess != (-1)){
{ 
#line 622 "OperatingSystem.c"
if (processTable[newProcess].queueID == USERPROCESSQUEUE){
{ 
#line 617 "OperatingSystem.c"
userThrows += 1; } }else{
if (processTable[newProcess].queueID == DAEMONSQUEUE){
{ 
#line 620 "OperatingSystem.c"
daemonThrows += 1; } }}
#line 622 "OperatingSystem.c"
OperatingSystem_Dispatch(newProcess); } }
# 2794 "OperatingSystemAspect.c"

}

# 2798 "OperatingSystemAspect.c"

}
 
#line 626 "OperatingSystem.c"
void OperatingSystem_MoveToTheBLOCKEDState(int PID)  
# 2804 "OperatingSystemAspect.c"
{



# 2809 "OperatingSystemAspect.c"
{

#line 629 "OperatingSystem.c"

#line 629 "OperatingSystem.c"
int previousState = processTable[PID].state;
#line 631 "OperatingSystem.c"
if (Heap_add(PID, sleepingProcessesQueue, 0, (&numberOfSleepingProcesses), 20) >= 0){
{ 
#line 632 "OperatingSystem.c"
processTable[PID].state = BLOCKED; 
#line 633 "OperatingSystem.c"
OperatingSystem_ShowTime('p'); 
#line 634 "OperatingSystem.c"
ComputerSystem_DebugMessage(110, 'p', PID, (programList[processTable[PID].programListIndex]->executableName), statesNames[previousState], statesNames[BLOCKED]); } }
# 2825 "OperatingSystemAspect.c"

}

# 2829 "OperatingSystemAspect.c"

}
 
#line 640 "OperatingSystem.c"
int OperatingSystem_MaxProirity()  
# 2835 "OperatingSystemAspect.c"
{
# 2837 "OperatingSystemAspect.c"
int retValue_acc;




# 2843 "OperatingSystemAspect.c"
{

#line 641 "OperatingSystem.c"

#line 641 "OperatingSystem.c"
int queueID = processTable[executingProcessID].queueID;
#line 642 "OperatingSystem.c"

#line 642 "OperatingSystem.c"
int priority = processTable[executingProcessID].priority;
#line 643 "OperatingSystem.c"

#line 643 "OperatingSystem.c"
int newProcess = Heap_getFirst(readyToRunQueue[USERPROCESSQUEUE], numberOfReadyToRunProcesses[USERPROCESSQUEUE]);
#line 644 "OperatingSystem.c"
if (newProcess == (-1)){
{ 
#line 645 "OperatingSystem.c"
newProcess = Heap_getFirst(readyToRunQueue[DAEMONSQUEUE], numberOfReadyToRunProcesses[DAEMONSQUEUE]); } }
#line 648 "OperatingSystem.c"
if (newProcess != (-1)){
{ 
#line 660 "OperatingSystem.c"
if (queueID == processTable[newProcess].queueID){
{ 
#line 653 "OperatingSystem.c"
if (processTable[newProcess].priority >= priority){
{ 
#line 651 "OperatingSystem.c"

# 2874 "OperatingSystemAspect.c"
retValue_acc = (-1);
# 2876 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }
#line 653 "OperatingSystem.c"

# 2881 "OperatingSystemAspect.c"
retValue_acc = newProcess;
# 2883 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }else{
if ((queueID == USERPROCESSQUEUE) && (processTable[newProcess].queueID == DAEMONSQUEUE)){
{ 
#line 656 "OperatingSystem.c"

# 2890 "OperatingSystemAspect.c"
retValue_acc = (-1);
# 2892 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }else{
{ 
#line 659 "OperatingSystem.c"

# 2898 "OperatingSystemAspect.c"
retValue_acc = newProcess;
# 2900 "OperatingSystemAspect.c"
return (int )retValue_acc;
 } }}} }
#line 663 "OperatingSystem.c"

# 2905 "OperatingSystemAspect.c"
retValue_acc = newProcess;
# 2907 "OperatingSystemAspect.c"
return (int )retValue_acc;
 
# 2910 "OperatingSystemAspect.c"

}

# 2914 "OperatingSystemAspect.c"
return (int )retValue_acc;

# 2917 "OperatingSystemAspect.c"

}
 
