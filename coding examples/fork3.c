#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*

   This program illustrates the use of getpid() and getppid()
*/

   int main()
   {
    pid_t pid;
    int i;
    int status = 0;
    pid_t parent;

    pid = fork();
    if (pid < 0){
       perror("fork()");
       printf("main function: errno number is %d\n",errno);
       exit(pid);
    }

    if (pid > 0)
    {
         printf("I am parent and the child  that I forked of has process id %d\n",pid);
	 printf("I am parent with process id %d\n",getpid());
         wait(0);
      }
      else  /*child*/
      {
         printf("I am child the value of pid returned to me is %ld\n",(long) pid);
         printf("I am child with process id %ld\n",(long) getpid());
         printf("I am child with parent process id %ld\n",(long)getppid());
      }

     return 0;
}

