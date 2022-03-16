#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 100

int countMalloc(char arr[]){
    char buffer[] = "";
    FILE *file = fopen(arr, "r");

    char mal[] = "malloc";
    char fre[] = "free";
    int malc = 0;
    int fr = 0;

    if(file == NULL){
        fprintf(stderr, "File not found\n");
    }
    else{
        while(fscanf(file, "%s", buffer) != EOF){
            if(strncmp(buffer, mal, 6) == 0){
                malc++;
            }
            else if(strncmp(buffer, fre, 4) == 0){
                fr++;
            }
        }

    }
    if(malc == fr){
            printf("no memory leak! Malloc: %d - Free: %d\n", malc, fr);
        }

        else if(malc > fr){
            printf("MEMORY LEAK! Malloc: %d - Free: %d\n", malc, fr);
        }

        else if(malc < fr){
            printf("TOO MANY FREE! Malloc: %d - Free: %d\n", malc, fr);
        }
    fclose(file);
    return 0;
}
