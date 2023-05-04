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
    x = 200;
    printf("hello, I am child (pid:%d) and the x value is %d\n", (int)getpid(), x);
  }
  else
  {
    // parent goes down this path (original process)
    x = 300;
    printf("hello, I am parent of %d (pid:%d) and the x value is %d\n",
           rc, (int)getpid(), x);
  }
  return 0;
}

// Key takeaway here with assigning the x value it seems that each process get's its own copy of the variable x

// After the fork function is called, the child process creates a copy of the parent process's memory, including the value of x. Any changes made to x in the child process will only affect the child process's copy of x, and will not affect the parent process's copy of x.

// Similarly, any changes made to x in the parent process after the fork function call will only affect the parent process 's copy of x, and will not affect the child process' s copy of x.
