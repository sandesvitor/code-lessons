#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

// for each fork() we double the processes!
// so, for each loop, we get exponencially bigger!

int main(int argc, char *argv[]){
    for(int i = 1; i <= 2; i++){
        fork();
        printf("%d: My PID = %d\n", i, (int) getpid());
    }

    sleep(1);
    printf("--> My PID = %d\n", getpid());

    return 0;
}
