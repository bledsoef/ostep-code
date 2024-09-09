#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
 int rc = fork();
 if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  printf("WAHHH WAHHH I AM A CHILD \n");
 } else {
  int wc = waitpid(rc, NULL, 0); // where the wait went before I added it to the child process.
  printf("%d\n", wc);
}
 return 0;
}

/*
Finn Bledsoe
Question 6:

waitpid() seems like it is best used for when you may have multiple child processes running and you want to wait on a particular one.

*/
