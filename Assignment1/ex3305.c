#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){

pid_t pid, pid1, pid2,pid3;
int status;
  
//first fork
pid = fork();

//int childcount  = 0 ;
if(pid < 0){
    exit(EXIT_FAILURE);
}

else if (pid > 0){
  // first parent
  printf("From parent process %d: child_1 is created with PID %d\n", getpid(),pid);
  
    //second child creation
  pid1 = fork();

    if(pid1>0){
      //parent (second child)
      printf("From parent process %d: child_2 is created with PID %d\n", getpid(),pid1);
      printf("From parent Process %d: Waiting for child_2 to complete before creating child_3\n",getpid());
      wait(0);
      pid3 = fork();

      if(pid3>0){
      //parent (thrid child)
        wait(0);
        printf("From parent process %d: child_3 is created with PID %d\n", getpid(),pid3);
          
        
      }

      else
          {
            printf("From child_3: Calling an external program B.out and leaving child_3…\n");
            printf("From the external program B: \n");
            execl("b.out","b.out",NULL);

            }
    }
  


    else if( pid1 ==0)
      {

      }
    //third child creation
  


    
        // printf("I am the parent %d\n", getpid()); 
 // wait(0);
  //printf("wait\n"); 

    }
 else {
    /* Child process of the first fork call */
    pid2 = fork();

    if (pid2>0)
    {
    printf("From child_1: child_1.1 is created with PID %d\n", pid2);
    }
    if(pid2 ==0){
      
  
    }
     

}



return 0; 
}