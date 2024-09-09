#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
 int fd = open("./open_file.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
 int rc = fork();
 if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
   printf("Child Process \n");
   write(fd, "CHILD \n", 8);
 } else { 
   printf("Parent Process \n");
   write(fd, "PARENT \n", 9);
}
 return 0;
}

/*
Finn Bledsoe
Question 2:

Both the child and parent can access the file descriptor. They both are able to write their respective text to the file. If they are writing concurrently it seems that both of their changes are added to the file.

*/
