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
  char *args[3];
  args[0] = strdup("ls");
  args[1] = strdup("-a"); // was experimenting around with how flags might work. Cool stuff
  args[2] = NULL;
  execvp(args[0], args);
 } else {
  wait(NULL);
}
 return 0;
}

/*
Finn Bledsoe
Question 4:

There are a ton of different versions of exec() because they all expect different input types or slightly differ in how they execute the file/command. The v standing for vector, l for list, etc. 

*/
