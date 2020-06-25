/*
Muhammad Faraz Sohail
Assignment 2
Part1
*/

//libraries for desired functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  int status = 0;

  //forking here
  int id = fork();
  if (id == 0)
  {
    //child
    printf("The child id is: %d \n", id);
  }
  else
  {
    //parent
    clock_t begin = clock(); //start clock time
    printf("Parent id is: %d \n", id);
    sleep(60);             //sleep of 1 minute
    clock_t end = clock(); //end clock time
    printf("The parent ended in (Clocks Per Sec): %lf \n", ((double)(end - begin)) / CLOCKS_PER_SEC);
    //wait(&status);
  }

  exit(0);
}
