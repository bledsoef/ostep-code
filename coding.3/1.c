#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
 int x = 100;
 int rc = fork();
 if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
   printf("Child Process \n");
   printf("value of x: %d \n", x);
   x = 8;
 } else { 
   printf("Parent Process \n");
   printf("value of x: %d \n", x);
   x = 9; 
}
 return 0;
}

/*
Finn Bledsoe
Question 1:

Whether or not you set the value of x in the parent or child process has no effect on the value of x in the following process.

*/
