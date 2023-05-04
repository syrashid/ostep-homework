#include <stdio.h>  // input and output
#include <stdlib.h> // memory allocation
#include <unistd.h> // process management

int main(int argc, char *argv[])
{
  int x = 100;
  printf("hello world (pid:%d) and the x value is %d\n", (int)getpid(), x);
  int rc = fork();
  if (rc < 0)
  {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // child (new process)
    printf("hello, I am child (pid:%d) and the x value is %d\n", (int)getpid(), x);
  }
  else
  {
    // parent goes down this path (original process)
    printf("hello, I am parent of %d (pid:%d) and the x value is %d\n",
           rc, (int)getpid(), x);
  }
  return 0;
}
