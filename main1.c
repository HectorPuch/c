#include <stdio.h> // Input/Output
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait(NULL)
#include <unistd.h> // Constants/Types
#include <stdlib.h> // exit(0)
 
int main(){
 
    pid_t pid = fork();
 
    if (pid == 0) {
 
        printf("I'm the child: %d\n", getpid());
        exit(0);
 
    } else {
 
        printf("I'm the father: %d\n", getpid());
        wait(NULL);
 
    }
 
    return 0;
    
}
