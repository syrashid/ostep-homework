#include <stdio.h>  // input and output
#include <stdlib.h> // memory allocation
#include <unistd.h> // process management

int main(int argc, char *argv[])
{

  printf("hello world (pid:%d)\n", (int)getpid());
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
    int rc_wait = wait(NULL);
    printf("hello, I am child (pid:%d) and I waited for (rc_wait: %d)\n", (int)getpid(), rc_wait);
  }
  else
  {
    // parent goes down this path (original process)
    int rc_wait = wait(NULL);
    printf("hello, I am parent of %d (pid:%d) and I waited for (rc_wait: %d)\n",
           rc, (int)getpid(), rc_wait);
  }
  return 0;
}

// wait() returns the PID of the first child that terminates or -1 if there are no children

// waitpid() allows you to specify which child you want to wait for
