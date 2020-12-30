#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int i = 0; // global variable

/*
 * What does it make to be a separated process?
 *
 * 	As we can see, the global variable i is
 * 	beeing used for both Parent and Child 
 * 	processes.
 *
 * 	As we run the binary, one might expect
 * 	the variable to accumulet (increase)
 * 	globally its vallue. But what happens
 * 	is that i has a separate increase for
 * 	both processes.
 * 	
 * 	Therefore, everything we do in one adress
 * 	space, does not interfere with the other
 * 	address space, unless we were using special
 * 	interprocess comunication methods.
*/



void doSomeWork(char *name){
    const int NUM_TIMES = 5;
    for ( ; i < NUM_TIMES; i++){
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
        exit(0);
    }
    
    // We must be a parent
    printf("I am the parent, waiting for child to end.\n");
    doSomeWork("Parent");
    wait(NULL);
    printf("Parent ending.\n");
    
    return 0;
}
