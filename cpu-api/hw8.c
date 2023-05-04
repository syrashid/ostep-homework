#include <stdio.h>  // input and output
#include <stdlib.h> // memory allocation
#include <unistd.h> // process management

int main(int argc, char *argv[])
{

  int pipefd[2];
  pid_t pid1, pid2;

  // create the pipe
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid1 = fork();

  if (pid1 == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid1 == 0)
  {
    close(pipefd[0]); // close the read end of the pipe

    dup2(pipefd[1], STDOUT_FILENO);

    printf("First Child Says What?\n");
  }
  else
  {
    pid2 = fork();

    if (pid2 == -1)
    {
      perror("fork");
      exit(EXIT_FAILURE);
    }

    if (pid2 == 0)
    {
      close(pipefd[1]); // close the write end of the pipe

      dup2(pipefd[0], STDIN_FILENO);

      char buf[BUFSIZ];
      read(STDIN_FILENO, buf, BUFSIZ);
      printf("Second child print: %s\n", buf);
    }
    else
    {
      close(pipefd[0]);
      close(pipefd[1]);

      waitpid(pid1, NULL, 0);
      waitpid(pid2, NULL, 0);
    }
  }
}

// Important take aways from here are how the read and write ends of pipes are set up, how they need to be closed, and how to access the buffers for reading and writing
