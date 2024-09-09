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
  close(STDOUT_FILENO);
  printf("some output \n");
 } else {
  printf("some output1 \n");
}
 return 0;
}

/*
Finn Bledsoe
Question 7:

The printf does not output anything if standard output is closed/

*/
