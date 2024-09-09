#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[]) {
 int rc = fork();
 if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  wait(NULL);
  printf("post child wait\n");
 } else {
  int wc = 0; // where the wait went before I added it to the child process.
  printf("%d\n", wc);
}
 return 0;
}

/*
Finn Bledsoe
Question 5:

Wait prints out the PID of the process it waited on. In this case the child.

If you add the wait in the child process it seems like it will always wait for the parent. 
*/
