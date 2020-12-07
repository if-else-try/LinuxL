#include "ch10.h"

void pr_exit(int status, pid_t pid)
{
   int sig;

   if (WIFEXITED(status))           /* 正常终止的子进程  */
      printf("process %d normal termination, exit status = %d\n", pid,
              WEXITSTATUS(status));
   else if (WIFSIGNALED(status)){   /* 异常终止的子进程  */
      sig = WTERMSIG(status);
      printf("process %d abnormal termination, signal number = %d%s:\n", pid, sig,
#ifdef WCOREDUMP
              WCOREDUMP(status) ? "(core file generated)" : "");
#else
              "");
#endif
      psignal(sig, "");
   } else if(WIFSTOPPED (status)){   /* 被停止的子进程  */
      sig = WSTOPSIG (status);
      printf("process %d stopped, signal number = %d: ", pid, sig);
      psignal(sig, "");
   }
}

int zero=0;

int main(void)
{
   pid_t pid;
   int status;

   if ((pid = fork()) == 0)  /* 派生子进程1 */
      exit(0);               /* 子进程1正常退出 */
   if ((pid = fork()) == 0)  /* 派生子进程2 */
      abort();      /* 子进程2生成SIGABRT信号退出 */
   if ((pid = fork()) == 0) {   /* 派生子进程3 */
      status/=zero;   /* 子进程3因0作除数生成SIGFPE信号退出 */
      exit(0);
   }
   while ((pid = wait(&status)) >= 0) /* 等待子进程  */
      pr_exit(status, pid);
   perror("wait over");
   exit(EXIT_SUCCESS);
}
