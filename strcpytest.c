#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(){

    char s1[10];
    char s2[15] = "don't do this";

    strncpy(s1, s2, sizeof(s1)-1);
    s1[9] = '\0';
    
    if (s1[9] == 0){
        printf("NO Error\n");
    }
    printf("%s -- %s\n",s2, s1);


    return 0;
}