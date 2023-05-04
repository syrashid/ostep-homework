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
    printf("hello, I am child (pid:%d)\n", (int)getpid());
    char *args[] = {"ls", NULL};
    execvp(args[0], args);

    // If execvp fails, the following line will be printed
    fprintf(stderr, "execvp failed\n");
    exit(1);
  }
  else
  {
    // parent goes down this path (original process)
    printf("hello, I am parent of %d (pid:%d)\n",
           rc, (int)getpid());
  }
  return 0;
}

// In general, the exec system calls are used to replace the current process image with a new process image. These functions are commonly used in conjunction with the fork system call, which creates a new process that is a copy of the current process. By calling one of the exec functions in the child process, you can replace the child process with a new program, while preserving any state that was inherited from the parent process.

// The exec function is not actually a system call itself, but rather a family of functions that include execl, execle, execlp, execv, execvp, and execvpe. These functions all perform a similar task: replacing the current process image with a new process image.

// The different versions of the exec system call in C serve slightly different purposes and are used in different contexts. Here's a brief overview of each of the six versions you mentioned:

// execl : This function is used to execute a specified program with a list of arguments passed as separate parameters to the function.The final parameter must be a NULL pointer to terminate the list of arguments.

// execle : This function is similar to execl,but it allows you to specify the environment of the new process as an additional parameter.The environment must be passed as an array of pointers to char, terminated by a NULL pointer.

// execlp : This function is similar to execl, but it searches the system PATH environment variable to find the specified program.This allows you to execute a program without specifying its full path.

// execv : This function is similar to execl, but it takes the arguments as an array of pointers to char, terminated by a NULL pointer.This can be more convenient than specifying each argument as a separate parameter, especially when you have a large number of arguments.

// execvp : This function is similar to execv, but it searches the system PATH environment variable to find the specified program.

// execvpe : This function is similar to execvp, but it allows you to specify the environment of the new process as an additional parameter.
