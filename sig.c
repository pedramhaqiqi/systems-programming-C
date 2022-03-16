#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *name;

void sing(int sig){
    printf("happy birthday to you\n");
    printf("happy birthday to you\n");
    printf("happy birthday dear %s\n", name);
    printf("happy birthday to you\n");
    return;
}

int main(int argc, char** argv){
    
    name = argv[1];

    struct sigaction hd;
    hd.sa_handler = sing;
    hd.sa_flags = 0;
    sigemptyset(&hd.sa_mask);

    sigaction(SIGUSR1, &hd, NULL); //actually install the signal SR1.

    while(1){

    }

}
