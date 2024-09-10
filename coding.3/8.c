#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
 int pipefd[2];
 char read_msg[100]; 
 pipe(pipefd);
 int rc1 = fork();
 if (rc1 < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc1 == 0) {
  printf("WAHHH WAHHH I AM A CHILD \n");
  close(pipefd[0]);
  write(pipefd[1], "hi", 2);
  close(pipefd[1]);
 } else {
  int rc2 = fork();
  if (rc2 < 0) {
   printf("eefagsdfgd");
  } else if (rc2 == 0) {
   printf("I AM THE SECOND CHILD \n");
   close(pipefd[1]);
   read(pipefd[0], read_msg, sizeof(read_msg));
   printf("Child received: %s", read_msg);
   close(pipefd[0]);
  } else {
   printf("I AM THE PARENT \n");
   
  }
}
 return 0;
}

/*
Finn Bledsoe
Question 8:

I was able to get two children to communicate via pipe, but probably not in the most optimal ways. I created a second child inside the parent's conditional and then used pipe with a pipefd array for std read and write to communicate and send the text "hi".
*/
