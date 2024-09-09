#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
 int rc1 = fork();
 if (rc1 < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc1 == 0) {
  printf("WAHHH WAHHH I AM A CHILD \n");
 } else {
  int rc2 = fork();
  if (rc2 < 0) {
   printf("eefagsdfgd");
  } else if (rc2 == 0) {
   printf("I AM THE SECOND CHILD \n");
  } else {
   printf("I AM THE PARENT \n");
   
   pipe();
  }
}
 return 0;
}

/*
Finn Bledsoe
Question 6:

waitpid() seems like it is best used for when you may have multiple child processes running and you want to wait on a particular one.

*/
