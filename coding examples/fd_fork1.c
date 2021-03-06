#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*

   This program illustrates fork() with the file descriptor
*/

int main()
{
    FILE  *fd1, *fd2;
    char c;
    pid_t pid;

    pid = fork (); 
   // fd1 = fopen("foo.txt",  "r");
 
 fd1 = fopen("foo.txt",  "r");
     fd2 = fopen("foo.txt", "r"); 


    if (pid > 0){

      // parent
        fscanf(fd1, "%c", &c);
      printf("parent: c = %c\n", c);
	wait(NULL);
    }

else if (pid == 0) {

  // child 

        fscanf(fd2, "%c", &c);
       printf("child: c = %c\n", c);
    }


fclose(fd1);
fclose(fd2);

return 0;

}
