#include "ch10.h"

void pr_exit(int status, pid_t pid)
{
   int sig;

   if (WIFEXITED(status))           /* ������ֹ���ӽ���  */
      printf("process %d normal termination, exit status = %d\n", pid,
              WEXITSTATUS(status));
   else if (WIFSIGNALED(status)){   /* �쳣��ֹ���ӽ���  */
      sig = WTERMSIG(status);
      printf("process %d abnormal termination, signal number = %d%s:\n", pid, sig,
#ifdef WCOREDUMP
              WCOREDUMP(status) ? "(core file generated)" : "");
#else
              "");
#endif
      psignal(sig, "");
   } else if(WIFSTOPPED (status)){   /* ��ֹͣ���ӽ���  */
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

   if ((pid = fork()) == 0)  /* �����ӽ���1 */
      exit(0);               /* �ӽ���1�����˳� */
   if ((pid = fork()) == 0)  /* �����ӽ���2 */
      abort();      /* �ӽ���2����SIGABRT�ź��˳� */
   if ((pid = fork()) == 0) {   /* �����ӽ���3 */
      status/=zero;   /* �ӽ���3��0����������SIGFPE�ź��˳� */
      exit(0);
   }
   while ((pid = wait(&status)) >= 0) /* �ȴ��ӽ���  */
      pr_exit(status, pid);
   perror("wait over");
   exit(EXIT_SUCCESS);
}
