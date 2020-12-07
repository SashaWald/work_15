#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int status;
    printf("I am the parent. Pid: %d\n",getpid());
    int f = fork();
    if (f){
        f = fork();
    }
    if (f){
        int n = wait(&status);
        printf("Child %d finished first! \n Time slept: %d\n Parent finished.\n",n,WEXITSTATUS(status));
        return(0);
    }
    else{
        int cpid = getpid();
        srand(time(NULL));
        printf("Child created with pid %d\n",cpid);
        int r2 = (rand()%9)+2;
        sleep(r2);
        printf("Child with pid %d is done\n",cpid);
        return(r2);
    }
    return(0);
}