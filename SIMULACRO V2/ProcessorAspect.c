
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


# 1 "Processor.c" 
# 1 "<built-in>" 
# 1 "<command-line>" 
# 31 "<command-line>" 
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "Processor.c" 
# 1 "Processor.h" 1
# 1 "MainMemory.h" 1
# 1 "Simulator.h" 1
# 9 "MainMemory.h" 2
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
# 2 "Processor.c" 2
# 1 "OperatingSystem.h" 1
# 1 "ComputerSystem.h" 1
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
# 4 "Processor.c" 2
# 6 "Clock.h" 1
void Clock_Update(); 
#line 7 "Clock.h"
int Clock_GetTime(); 
# 6 "Processor.c" 2
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
# 8 "Processor.c" 2
# 11 "Processor.c" 
int Processor_FetchInstruction(); 
#line 12 "Processor.c"
void Processor_DecodeAndExecuteInstruction(); 
#line 13 "Processor.c"
void Processor_ManageInterrupts(); 
#line 14 "Processor.c"
void Processor_ShowTime(char ); 
#line 17 "Processor.c"
extern char *InstructionNames[]; 
#line 20 "Processor.c"
int registerPC_CPU; 
#line 21 "Processor.c"
int registerAccumulator_CPU; 
#line 22 "Processor.c"
 BUSDATACELL registerIR_CPU; 
#line 23 "Processor.c"
unsigned int registerPSW_CPU = 128; 
#line 24 "Processor.c"
int registerMAR_CPU; 
#line 25 "Processor.c"
 BUSDATACELL registerMBR_CPU; 
#line 26 "Processor.c"
int registerCTRL_CPU; 
#line 28 "Processor.c"
int registerA_CPU; 
#line 30 "Processor.c"
int interruptLines_CPU; 
#line 33 "Processor.c"
int interruptVectorTable[10]; 
#line 36 "Processor.c"
char pswmask[] = "----------------"; 
#line 39 "Processor.c"
void Processor_InitializeInterruptVectorTable(int interruptVectorInitialAddress)  
# 822 "ProcessorAspect.c"
{



# 827 "ProcessorAspect.c"
{

#line 40 "Processor.c"

#line 40 "Processor.c"
int i;
#line 41 "Processor.c"
for(i = 0;i < 10;i++) { interruptVectorTable[i] = interruptVectorInitialAddress - 2; } 
#line 44 "Processor.c"
interruptVectorTable[SYSCALL_BIT] = interruptVectorInitialAddress; 
#line 45 "Processor.c"
interruptVectorTable[EXCEPTION_BIT] = interruptVectorInitialAddress + 2; 
#line 46 "Processor.c"
interruptVectorTable[CLOCKINT_BIT] = interruptVectorInitialAddress + 4; 
# 842 "ProcessorAspect.c"

}

# 846 "ProcessorAspect.c"

}
 
  void __utac_acc__Aspect__5 (void);


#line 53 "Processor.c"
void Processor_InstructionCycleLoop()  
# 855 "ProcessorAspect.c"
{



# 860 "ProcessorAspect.c"
{

#line 62 "Processor.c"
while((!Processor_PSW_BitState(POWEROFF_BIT))) { { 
#line 59 "Processor.c"
if (Processor_FetchInstruction() == 1){
{ 
#line 57 "Processor.c"
Processor_DecodeAndExecuteInstruction(); } }
#line 59 "Processor.c"
if (interruptLines_CPU && (!Processor_PSW_BitState(INTERRUPT_MASKED_BIT))){
{ 
#line 60 "Processor.c"
Processor_ManageInterrupts(); } }} } 
# 875 "ProcessorAspect.c"

}

{
__utac_acc__Aspect__5();

}

# 884 "ProcessorAspect.c"

}
 
  void __utac_acc__Aspect__1 (void);


#line 66 "Processor.c"
int Processor_FetchInstruction()  
# 893 "ProcessorAspect.c"
{
# 895 "ProcessorAspect.c"
int retValue_acc;




{
__utac_acc__Aspect__1();

}

# 906 "ProcessorAspect.c"
{

#line 69 "Processor.c"
registerMAR_CPU = registerPC_CPU; 
#line 71 "Processor.c"
Buses_write_AddressBus_From_To(CPU, MMU); 
#line 73 "Processor.c"
registerCTRL_CPU = 0x1; 
#line 74 "Processor.c"
Buses_write_ControlBus_From_To(CPU, MMU); 
#line 76 "Processor.c"
if (registerCTRL_CPU && 0x10){
{ 
#line 79 "Processor.c"
memcpy(((void *)((&registerIR_CPU))), ((void *)((&registerMBR_CPU))), sizeof ( BUSDATACELL )); 
#line 82 "Processor.c"

#line 82 "Processor.c"
char codedInstruction[13];
#line 83 "Processor.c"
Processor_GetCodedInstruction(codedInstruction, registerIR_CPU); 
#line 84 "Processor.c"
Processor_ShowTime('h'); 
#line 85 "Processor.c"
ComputerSystem_DebugMessage(68, 'h', codedInstruction); } }else{
{ 
#line 89 "Processor.c"
Processor_ShowTime('h'); 
#line 90 "Processor.c"
ComputerSystem_DebugMessage(100, 'h', "_ _ _\n"); 
#line 91 "Processor.c"

# 939 "ProcessorAspect.c"
retValue_acc = 0;
# 941 "ProcessorAspect.c"
return (int )retValue_acc;
 } }
#line 93 "Processor.c"

# 946 "ProcessorAspect.c"
retValue_acc = 1;
# 948 "ProcessorAspect.c"
return (int )retValue_acc;
 
# 951 "ProcessorAspect.c"

}

# 955 "ProcessorAspect.c"
return (int )retValue_acc;

# 958 "ProcessorAspect.c"

}
 
  void __utac_acc__Aspect__2 (void);


  void __utac_acc__Aspect__2 (void);


#line 98 "Processor.c"
void Processor_DecodeAndExecuteInstruction()  
# 970 "ProcessorAspect.c"
{



# 975 "ProcessorAspect.c"
{

#line 99 "Processor.c"

#line 99 "Processor.c"
int tempAcc;
#line 102 "Processor.c"

#line 102 "Processor.c"
int operationCode = Processor_DecodeOperationCode(registerIR_CPU);
#line 103 "Processor.c"

#line 103 "Processor.c"
int operand1 = Processor_DecodeOperand1(registerIR_CPU);
#line 104 "Processor.c"

#line 104 "Processor.c"
int operand2 = Processor_DecodeOperand2(registerIR_CPU);
#line 106 "Processor.c"
Processor_DeactivatePSW_Bit(OVERFLOW_BIT); 
#line 109 "Processor.c"
switch(operationCode){ { 
#line 113 "Processor.c"
case ADD_INST: registerAccumulator_CPU = operand1 + operand2; 
#line 114 "Processor.c"
Processor_CheckOverflow(operand1, operand2); 
#line 115 "Processor.c"
registerPC_CPU++; 
#line 116 "Processor.c"
break; 
#line 119 "Processor.c"
case SHIFT_INST: if (operand1 < 0){
{ 
#line 123 "Processor.c"
if (registerAccumulator_CPU & ((-1) << (sizeof (int ) * 8 - (((-operand1)) & 0x1f)))){
Processor_ActivatePSW_Bit(OVERFLOW_BIT); }
#line 123 "Processor.c"
registerAccumulator_CPU <<= (((-operand1)) & 0x1f); } }else{
registerAccumulator_CPU >>= operand1 & 0x1f; }
#line 128 "Processor.c"
registerPC_CPU++; 
#line 129 "Processor.c"
break; 
#line 132 "Processor.c"
case DIV_INST: if (operand2 == 0){
Processor_RaiseInterrupt(EXCEPTION_BIT); }else{
{ 
#line 136 "Processor.c"
registerAccumulator_CPU = operand1 / operand2; 
#line 137 "Processor.c"
registerPC_CPU++; } }
#line 139 "Processor.c"
break; 
#line 142 "Processor.c"
case TRAP_INST: Processor_RaiseInterrupt(SYSCALL_BIT); 
#line 144 "Processor.c"
registerA_CPU = operand1; 
#line 145 "Processor.c"
registerPC_CPU++; 
#line 146 "Processor.c"
break; 
#line 149 "Processor.c"
case NOP_INST: registerPC_CPU++; 
#line 151 "Processor.c"
break; 
#line 154 "Processor.c"
case JUMP_INST: registerPC_CPU += operand1; 
#line 156 "Processor.c"
break; 
#line 159 "Processor.c"
case ZJUMP_INST: if (Processor_PSW_BitState(ZERO_BIT)){
registerPC_CPU += operand1; }else{
registerPC_CPU++; }
#line 164 "Processor.c"
break; 
#line 167 "Processor.c"
case WRITE_INST: registerMBR_CPU.cell = registerAccumulator_CPU; 
#line 169 "Processor.c"
registerMAR_CPU = operand1; 
#line 171 "Processor.c"
Buses_write_DataBus_From_To(CPU, MAINMEMORY); 
#line 173 "Processor.c"
Buses_write_AddressBus_From_To(CPU, MMU); 
#line 175 "Processor.c"
registerCTRL_CPU = 0x2; 
#line 176 "Processor.c"
Buses_write_ControlBus_From_To(CPU, MMU); 
#line 177 "Processor.c"
registerPC_CPU++; 
#line 178 "Processor.c"
break; 
#line 181 "Processor.c"
case READ_INST: registerMAR_CPU = operand1; 
#line 184 "Processor.c"
Buses_write_AddressBus_From_To(CPU, MMU); 
#line 186 "Processor.c"
registerCTRL_CPU = 0x1; 
#line 187 "Processor.c"
Buses_write_ControlBus_From_To(CPU, MMU); 
#line 190 "Processor.c"
registerAccumulator_CPU = registerMBR_CPU.cell; 
#line 191 "Processor.c"
registerPC_CPU++; 
#line 192 "Processor.c"
break; 
#line 195 "Processor.c"
case INC_INST: tempAcc = registerAccumulator_CPU; 
#line 197 "Processor.c"
registerAccumulator_CPU += operand1; 
#line 198 "Processor.c"
Processor_CheckOverflow(tempAcc, operand1); 
#line 199 "Processor.c"
registerPC_CPU++; 
#line 200 "Processor.c"
break; 
#line 203 "Processor.c"
case HALT_INST: if (Processor_PSW_BitState(EXECUTION_MODE_BIT)){
{ 
#line 205 "Processor.c"
Processor_ActivatePSW_Bit(POWEROFF_BIT); } }else{
{ 
#line 208 "Processor.c"
Processor_RaiseInterrupt(EXCEPTION_BIT); } }
#line 211 "Processor.c"
break; 
#line 214 "Processor.c"
case OS_INST: if (Processor_PSW_BitState(EXECUTION_MODE_BIT)){
{ 
#line 218 "Processor.c"
ComputerSystem_DebugMessage(69, 'h', InstructionNames[operationCode], operand1, operand2, registerPC_CPU, registerAccumulator_CPU, registerPSW_CPU, Processor_ShowPSW()); 
#line 220 "Processor.c"
OperatingSystem_InterruptLogic(operand1); 
#line 221 "Processor.c"
registerPC_CPU++; 
#line 223 "Processor.c"
Processor_UpdatePSW(); } }else{
{ 
#line 226 "Processor.c"
Processor_RaiseInterrupt(EXCEPTION_BIT); } }
#line 229 "Processor.c"

{
__utac_acc__Aspect__2();

}
return ; 
 
#line 232 "Processor.c"
case IRET_INST: if (Processor_PSW_BitState(EXECUTION_MODE_BIT)){
{ 
#line 234 "Processor.c"
registerPC_CPU = Processor_CopyFromSystemStack(300 - 1); 
#line 235 "Processor.c"
registerPSW_CPU = Processor_CopyFromSystemStack(300 - 2); } }else{
{ 
#line 238 "Processor.c"
Processor_RaiseInterrupt(EXCEPTION_BIT); } }
#line 241 "Processor.c"
break; 
#line 243 "Processor.c"
case MEMADD_INST: registerMAR_CPU = operand2; 
#line 246 "Processor.c"
Buses_write_AddressBus_From_To(CPU, MMU); 
#line 248 "Processor.c"
registerCTRL_CPU = 0x1; 
#line 249 "Processor.c"
Buses_write_ControlBus_From_To(CPU, MMU); 
#line 252 "Processor.c"
registerAccumulator_CPU = operand1 + registerMBR_CPU.cell; 
#line 254 "Processor.c"
Processor_CheckOverflow(operand1, registerMBR_CPU.cell); 
#line 255 "Processor.c"
registerPC_CPU++; 
#line 256 "Processor.c"
break; 
#line 259 "Processor.c"
default: registerPC_CPU++; 
#line 261 "Processor.c"
break; } } 
#line 265 "Processor.c"
Processor_UpdatePSW(); 
#line 269 "Processor.c"
ComputerSystem_DebugMessage(69, 'h', InstructionNames[operationCode], operand1, operand2, registerPC_CPU, registerAccumulator_CPU, registerPSW_CPU, Processor_ShowPSW()); 
# 1159 "ProcessorAspect.c"

}

{
__utac_acc__Aspect__2();

}

# 1168 "ProcessorAspect.c"

}
 
#line 274 "Processor.c"
void Processor_ManageInterrupts()  
# 1174 "ProcessorAspect.c"
{



# 1179 "ProcessorAspect.c"
{

#line 276 "Processor.c"

#line 276 "Processor.c"
int i;
#line 278 "Processor.c"
for(i = 0;i < 10;i++) { if (Processor_GetInterruptLineStatus(i)){
{ 
#line 282 "Processor.c"
Processor_ACKInterrupt(i); 
#line 284 "Processor.c"
Processor_CopyInSystemStack(300 - 1, registerPC_CPU); 
#line 285 "Processor.c"
Processor_CopyInSystemStack(300 - 2, registerPSW_CPU); 
#line 286 "Processor.c"
Processor_ActivatePSW_Bit(INTERRUPT_MASKED_BIT); 
#line 288 "Processor.c"
Processor_ActivatePSW_Bit(EXECUTION_MODE_BIT); 
#line 290 "Processor.c"
registerPC_CPU = interruptVectorTable[i]; 
#line 291 "Processor.c"
break; } }} 
# 1203 "ProcessorAspect.c"

}

# 1207 "ProcessorAspect.c"

}
 
#line 295 "Processor.c"
char *Processor_ShowPSW()  
# 1213 "ProcessorAspect.c"
{
# 1215 "ProcessorAspect.c"
char* retValue_acc;




# 1221 "ProcessorAspect.c"
{

#line 296 "Processor.c"
strcpy(pswmask, "----------------"); 
#line 297 "Processor.c"

#line 297 "Processor.c"
int tam = strlen(pswmask) - 1;
#line 298 "Processor.c"
if (Processor_PSW_BitState(EXECUTION_MODE_BIT)){
pswmask[tam - EXECUTION_MODE_BIT] = 'X'; }
#line 300 "Processor.c"
if (Processor_PSW_BitState(OVERFLOW_BIT)){
pswmask[tam - OVERFLOW_BIT] = 'F'; }
#line 302 "Processor.c"
if (Processor_PSW_BitState(NEGATIVE_BIT)){
pswmask[tam - NEGATIVE_BIT] = 'N'; }
#line 304 "Processor.c"
if (Processor_PSW_BitState(ZERO_BIT)){
pswmask[tam - ZERO_BIT] = 'Z'; }
#line 306 "Processor.c"
if (Processor_PSW_BitState(POWEROFF_BIT)){
pswmask[tam - POWEROFF_BIT] = 'S'; }
#line 308 "Processor.c"
if (Processor_PSW_BitState(INTERRUPT_MASKED_BIT)){
pswmask[tam - INTERRUPT_MASKED_BIT] = 'M'; }
#line 310 "Processor.c"

# 1250 "ProcessorAspect.c"
retValue_acc = pswmask;
# 1252 "ProcessorAspect.c"
return (char* )retValue_acc;
 
# 1255 "ProcessorAspect.c"

}

# 1259 "ProcessorAspect.c"
return (char* )retValue_acc;

# 1262 "ProcessorAspect.c"

}
 
#line 317 "Processor.c"
void Processor_ShowTime(char section)  
# 1268 "ProcessorAspect.c"
{



# 1273 "ProcessorAspect.c"
{

#line 318 "Processor.c"
ComputerSystem_DebugMessage((Processor_PSW_BitState(EXECUTION_MODE_BIT)?95:94), section, Clock_GetTime()); 
# 1278 "ProcessorAspect.c"

}

# 1282 "ProcessorAspect.c"

}
 
