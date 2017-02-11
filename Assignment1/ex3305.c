#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define   MAX_COUNT  3

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */
pid_t  pid;
int  main(void)
{
     

     pid = fork();
          if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("child This line is from child, value = %d\n", i);



     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;

   //  for (i = 1; i <= MAX_COUNT; i++)
       printf("I am the parent %d\n", getpid()); 
          printf("FIRST From parent process %d: child_1 is created with PID %d\n", getppid(),getpid());
     printf("*** Parent is done ***\n");

        pid = fork();
          

          if(pid ==0){

               printf("FIRSTGRNAD From child_1: child_1.1 is created with PID %d my parent is %d\n", getpid(),getppid());

          }


    
}
