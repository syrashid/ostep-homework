#include <fcntl.h>  // open function
#include <stdio.h>  // input and output
#include <stdlib.h> // memory allocation
#include <unistd.h> // process management
#include <string.h> // strlen function

int main(int argc, char *argv[])
{
  printf("hello world (pid:%d)\n", (int)getpid());

  printf("About to open file\n");
  int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
    char *chld_msg = "Hello, from child!\n";
    int bytes_written = write(fd, chld_msg, strlen(chld_msg));
    if (bytes_written == -1)
    {
      perror("write");
      exit(1);
    }
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  }
  else
  {
    // parent goes down this path (original process)
    char *prnt_msg = "Hello, from parent!\n";
    int bytes_written = write(fd, prnt_msg, strlen(prnt_msg));
    if (bytes_written == -1)
    {
      perror("write");
      exit(1);
    }
    printf("hello, I am parent of %d (pid:%d)\n",
           rc, (int)getpid());
    close(fd);
  }
  return 0;
}

// In this case they both can access the file descripter
// As for which one writes first will be dependent on the scheduler or if you configure the processes to be deterministic
