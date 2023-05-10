#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    fprintf(stderr, "usage: memory-user <memory> <time>\n");
    exit(EXIT_FAILURE);
  }

  int size = atoi(argv[1]);
  int time_in_seconds = atoi(argv[2]);
  int *arr = calloc(size * 1048576, sizeof(int));
  int arr_size = size * 1048576;

  clock_t start_time = clock();

  while ((clock() - start_time) / CLOCKS_PER_SEC < time_in_seconds)
  {
    for (int i = 0; i < arr_size; i++)
    {
      int current = arr[i];
    }
  }

  free(arr);

  return 0;
}
