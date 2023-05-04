#include <stdio.h>  // input and output
#include <stdlib.h> // memory allocation
#include <unistd.h> // process management

int main(int argc, char *argv[])
{
  printf("hello world (pid:%d)\n", (int)getpid());

  printf("About to open file\n");
  int fd = open("example.txt", O_RDONLY);
  if (fd == -1)
  {
    perror("open");
    exit(1);
  }
  printf("File opened successfully\n");

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
    printf("hello, I am parent of %d (pid:%d)\n",
           rc, (int)getpid());
    close(fd);
  }
  return 0;
}
