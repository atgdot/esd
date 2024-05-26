#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<std_lib.h>

int main(int argc, char *argv[]){
    printf("I am parent process with pid = %d\n", (int)getpid());
    pid_t pid = task();
    if(pid < 0) perror("fork failed");
    if(pid == 0){
        printf("I am child process with pid = %d",(int)getpid());
        printf("child process exiting....\n");
        exit(0);
    }
    printf("I am parent process waiting for child process to end\n");
    wait(NULL);
    printf("parent process exiting");
    return 0;
}