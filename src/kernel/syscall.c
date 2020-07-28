#include <xbook/syscall.h>
#include <xbook/process.h>
#include <xbook/vmspace.h>
#include <xbook/resource.h>
#include <xbook/trigger.h>
#include <xbook/alarm.h>
#include <xbook/ktime.h>
#include <xbook/clock.h>
#include <xbook/waitque.h>
#include <xbook/srvcall.h>
#include <xbook/fs.h>
#include <xbook/driver.h>
#include <sys/stat.h>
#include <dirent.h>


/* 系统调用表 */ 
syscall_t syscall_table[SYSCALL_NR];

void init_syscall()
{
    /* 进程管理 */
    syscall_table[SYS_EXIT] = sys_exit;
    syscall_table[SYS_FORK] = sys_fork;
    syscall_table[SYS_WAITPID] = sys_waitpid;
    syscall_table[SYS_GETPID] = sys_get_pid;
    syscall_table[SYS_GETPPID] = sys_get_ppid;
    
    syscall_table[SYS_TRIGGER] = sys_trigger_handler;
    syscall_table[SYS_TRIGGERON] = sys_trigger_active;
    syscall_table[SYS_TRIGGERACT] = sys_trigger_action;
    syscall_table[SYS_TRIGRET] = sys_trigger_return;
    
    syscall_table[SYS_SLEEP] = sys_sleep;
    
    syscall_table[SYS_THREAD_CREATE] = sys_thread_create;
    syscall_table[SYS_THREAD_EXIT] = sys_thread_exit;
    syscall_table[SYS_THREAD_JOIN] = sys_thread_join;
    syscall_table[SYS_THREAD_DETACH] = sys_thread_detach;
    
    syscall_table[SYS_GETTID] = sys_get_tid;
    
    syscall_table[SYS_THREAD_CANCEL] = sys_thread_cancel;
    syscall_table[SYS_THREAD_TESTCANCEL] = sys_thread_testcancel;
    syscall_table[SYS_THREAD_CANCELSTATE] = sys_thread_setcancelstate;
    syscall_table[SYS_THREAD_CANCELTYPE] = sys_thread_setcanceltype;
    
    syscall_table[SYS_SCHED_YEILD] = sys_sched_yeild;
    
    syscall_table[SYS_WAITQUE_CREATE] = sys_waitque_create;
    syscall_table[SYS_WAITQUE_DESTROY] = sys_waitque_destroy;
    syscall_table[SYS_WAITQUE_WAIT] = sys_waitque_wait;
    syscall_table[SYS_WAITQUE_WAKE] = sys_waitque_wake;

    /* 内存管理 */
    syscall_table[SYS_HEAP] = sys_vmspace_heap;
    syscall_table[SYS_MUNMAP] = sys_munmap;
    
    /* 设备资源管理 */
    syscall_table[SYS_GETRES] = sys_getres;
    syscall_table[SYS_PUTRES] = sys_putres;
    syscall_table[SYS_READRES] = sys_readres;
    syscall_table[SYS_WRITERES] = sys_writeres;
    syscall_table[SYS_CTLRES] = sys_ctlres;
    syscall_table[SYS_DEVSCAN] = sys_devscan;
    syscall_table[SYS_MMAP] = sys_mmap;
    
    syscall_table[SYS_ALARM] = sys_alarm;
    syscall_table[SYS_KTIME] = sys_get_ktime;
    syscall_table[SYS_GETTICKS] = sys_get_ticks;
    syscall_table[SYS_GETTIMEOFDAY] = sys_gettimeofday;
    syscall_table[SYS_CLOCK_GETTIME] = sys_clock_gettime;
    
    syscall_table[SYS_SRVCALL] = sys_srvcall;
    syscall_table[SYS_SRVCALL_LISTEN] = sys_srvcall_listen;
    syscall_table[SYS_SRVCALL_ACK] = sys_srvcall_ack;
    syscall_table[SYS_SRVCALL_BIND] = sys_srvcall_bind;
    syscall_table[SYS_SRVCALL_UNBIND] = sys_srvcall_unbind;
    syscall_table[SYS_SRVCALL_FETCH] = sys_srvcall_fetch;
    
    syscall_table[SYS_UNID] = sys_unid;
    syscall_table[SYS_TSTATE] = sys_tstate;
    syscall_table[SYS_GETVER] = sys_getver;
    syscall_table[SYS_MSTATE] = sys_mstate;    
    syscall_table[SYS_USLEEP] = sys_usleep;    
    /* 文件系统 */
    syscall_table[SYS_OPEN] = sys_open;
    syscall_table[SYS_CLOSE] = sys_close;
    syscall_table[SYS_READ] = sys_read;
    syscall_table[SYS_WRITE] = sys_write;
    syscall_table[SYS_LSEEK] = sys_lseek;
    syscall_table[SYS_ACCESS] = sys_access;
    syscall_table[SYS_UNLINK] = sys_unlink;
    syscall_table[SYS_FTRUNCATE] = sys_ftruncate;
    syscall_table[SYS_FSYNC] = sys_fsync;
    syscall_table[SYS_IOCTL] = sys_ioctl;
    syscall_table[SYS_FCNTL] = sys_fcntl;
    syscall_table[SYS_TELL] = sys_tell;
    syscall_table[SYS_MKDIR] = sys_mkdir;
    syscall_table[SYS_RMDIR] = sys_rmdir;
    syscall_table[SYS_RENAME] = sys_rename;
    syscall_table[SYS_CHDIR] = sys_chdir;
    syscall_table[SYS_GETCWD] = sys_getcwd;
    syscall_table[SYS_EXECVE] = sys_execve;
    syscall_table[SYS_STAT] = sys_stat;
    syscall_table[SYS_FSTAT] = sys_fstat;
    syscall_table[SYS_CHMOD] = sys_chmod;
    syscall_table[SYS_FCHMOD] = sys_fchmod;
    syscall_table[SYS_OPENDIR] = sys_opendir;
    syscall_table[SYS_CLOSEDIR] = sys_closedir;
    syscall_table[SYS_READDIR] = sys_readdir;
    syscall_table[SYS_REWINDDIR] = sys_rewinddir;

}
