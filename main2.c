#include <stdio.h> // Input/Output
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait(NULL)
#include <unistd.h> // Constants/Types
#include <stdlib.h> // exit(0)
 
int main() {
 
    int p[2];
    pipe(p);
 
    pid_t pid = fork();
    char message[12] = "Hello! I'm your father.";
 
    if (pid == 0) {
        close(p[1]);
        read(p[0], message, 12);
        printf("I'm the child: %s\n", message);
        exit(0);
 
    } else {
        close(p[0]);
        write(p[1], message, 12);
        wait(NULL);
 
    }
 
    return 0;
 
} 
