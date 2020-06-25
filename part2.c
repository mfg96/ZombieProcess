/*
Muhammad Faraz Sohail
Assignment 2
Part2
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

int main(int argc, char *argv[])
{

    printf("Compiling Part1...\n");
    system("cc part1.c -o Q1"); //compiling command for part1

    printf("Executing Part1...\n");
    system("./Q1 &"); //running part1 in background command

    printf("\nAll programs with their states:\n");
    system("ps -l"); //listing all procs with their states and id command

    printf("\nDefunct programs:\n");
    system("ps -l|grep defunct"); //Showing defunct/zomibe processes

    printf("\nPIDs of Defunct process of Part1:\n");
    system("ps -fC Q1 | grep defunct"); //PIDs of part1 defunct process

    printf("\nKilling the Parent process of Zombie process!!\n");
    system("kill -9 $(ps -fC Q1 | grep defunct | awk '{print $3}')"); //killing parent of zombie process

    printf("\nNow showing the processes list:\n");
    system("ps -l"); //again showing all the processes with their status info and PIDs

    exit(0);
}
