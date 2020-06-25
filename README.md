# ZombieProcess

Implementation:

Part1:

1) I used fork() to make 2 processes and sleep() on parent process to block the execution of parent process while child process ended.
2) While parent process is blocked then child process can not terminate and becomes zombie.
3) I used ps -l to list the processes and kill -9 to kill the parent process of defunct/zombie process.

Part2:

1) I used system() to execute following commands in order:
cc part1.c -o Q1							#compiles the first part giving it name of Q1
./Q1 &									#runs part1 in background
ps -l									#listing all procs with their states and id command
ps -l |grep defunct							#Showing defunct/zomibe processes
ps -fC Q1 | grep defunct						#PIDs of part1 defunct process
kill -9 $(ps -fC Q1 | grep defunct | awk '{print $3}')			#killing parent of zombie process
ps -l									#again showing all the processes with their status info and PIDs

Usage:

1) Type cc part1.c for compiling first part and ./a.out to run it then use ps -l and kill command, if you dont use kill then program will automatically terminate in 1 minute. (be sure to use linux environment as sleep() will not work in Windows)
2) Type cc part2.c for compiling part2 and ./a.out to run it rest it will do itself.
