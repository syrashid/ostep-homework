#include <stdio.h>  // input and output
#include <stdlib.h> // memory allocation
#include <unistd.h> // process management

int main(int argc, char *argv[])
{

  printf("gutentag world (pid:%d)\n", (int)getpid());
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
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  }
  else
  {
    // parent goes down this path (original process)
    printf("goodbye, I am parent of %d (pid:%d)\n",
           rc, (int)getpid());
  }
  return 0;
}

// In general, there is no guaranteed way to ensure that the child process prints its message before the parent process. The order in which processes run is determined by the operating system's scheduling algorithm, which is often unpredictable and can depend on many factors, such as the current system load, the priority of the processes, and the specific implementation of the operating system.

// Can use tools like sleep or usleep or flushing the output buffers which could help but no guarentees
