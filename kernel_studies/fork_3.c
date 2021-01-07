#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



void doSomeWork(char *name){
    const int NUM_TIMES = 5;
    for (int i = 0; i < NUM_TIMES; i++){
        sleep(rand() % 4);
        printf("Done pass %d for %s\n", i, name);
    } 
}

int main(int agrc, char *argv[]){
    printf("I'm: %d\n", (int)getpid());
    
    sleep(5);

    pid_t pid = fork();
    srand((int) pid);
    printf("fork returned: %d\n", (int) pid);
    
    if(pid < 0){
    	perror("Fork failed!\n");
    }
    if (pid == 0){
    	printf("I am the child with pid %d\n", (int) getpid());
    	doSomeWork("Child");
        exit(42);
    }
    
    // We must be a parent
    printf("I am the parent, waiting for child to end.\n");
    doSomeWork("Parent");
    
    int status = 0;
    pid_t child_pid = wait(&status);
    printf("Parent knows child %d finished with status %d.\n", (int) child_pid, status);
    
    int childReturnValue = WEXITSTATUS(status); // WEXITSTATUS ==> macro Wait Exit Status!
    printf("    Return value wa %d\n", childReturnValue);


    return 0;
}
