#include <sys/types.h>  // (pid_t typedef)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(void){


	//1.Write a C program that will accept two integer values from the user as input (for example, X and Y)


  int x, y;
 
 

/* 2.Your program will create a parent and child where the parent process will read
X and the child process will read Y. Now, parent and child processes will exchange X and 
2
Y by communicating each other through a pipe (i.e., shared memory)*/


  int fd[2];
  int fd1[2];
  int xread, yread,n;
  char c;
  pid_t pid;
  char line[80];
  int status;
 
  if (pipe(fd) < 0){
    perror("pipe error");
    exit(-1);
  } 

    if (pipe(fd1) < 0){
    perror("pipe error");
    exit(-1);
  } 

  pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(-1);
  }

  if(pid > 0)
  {//parent 

    close(fd[0]); //close read since it does not
    close(fd1[1]);
    printf("From parent %d: child with PID %d is created\n",getpid(),pid);
   	printf("!From parent %d: Reading X from the user. :", getpid());
  	scanf("%d", &x);
    write(fd[1],&x,sizeof(x));
    printf("From parent %d: Reading Y from the pipe\n",getpid());
    read(fd1[0],&y, sizeof(y));
    printf("From parent %d: The value of Y is %d\n",getpid(), y);

    //printf("what is the value of xread %d\n", xread);
    //printf("what is the value of x %d\n", x);
    
    //write(fd[1],&yread,12);
   // write(fd[1], "hello world\n",12); //write to it 

  } else {
  	//child 
    close(fd[1]); //close write end 
    close(fd1[0]);
    //write(fd[0],&y,sizeof(y));
    sleep(5);
    printf("!From child: Reading Y from the User : \n");
    sleep(5);
    printf("A pipe is created for communication between parent and child\n");
 	scanf("%d",&y);
 	printf("From child: Writing Y into the pipe\n");
    write(fd1[1],&y,sizeof(y));
    printf("From child: Reading X from the pipe\n");
    read(fd[0],&x, sizeof(x));
    printf("From child: The value of X is %d\n", x);
    //printf("what is the value of y %d\n", y);
   // n = read(fd[0],line,80); // read from the pipe 
   // printf("what is the value of n %d\n", xread);
   // write(1,line,n); // echo on th4e screen
  }

  return 0;

}