#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
 int rc = fork();
 if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
   printf("hello \n");
 } else {
   wait(NULL); 
   printf("goodbye \n");
}
 return 0;
}

/*
Finn Bledsoe
Question 3:

I was unable to do it without using the wait() call.

*/
