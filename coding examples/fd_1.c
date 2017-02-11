#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*

   This program illustrates the use of file descriptor
*/
int main()
{
    FILE  *fd1, *fd2;
    char c;
    pid_t pid;

    fd1 = fopen("foo.txt",  "w");
    fd2 = fopen("foo.txt", "w"); 

     fprintf(fd1, "%s", "Anwar");
     fprintf(fd2, "%s", "Haque");	
	fclose(fd1);
	fclose(fd2);
    
}
