#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int size = atoi(argv[1]);
  int time_in_seconds = atoi(argv[2]);
  int *arr = calloc(size * 1048576, sizeof(int));
  size_t arr_size = size * 1048576 * sizeof(int);

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
