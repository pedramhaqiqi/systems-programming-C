#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    //using strchr and strstr
    //return a pointer to the first index at which the
    //substring or char was first found
    char s[] = "Hi there i am a string of strings";
    char *p; // i am the pointer that will store the fisrt index of the found char or substring
    p = strstr(s, "ringn "); //dummy dont forget to insitalize p with the function
    if (p == NULL){
        printf("Error");
    } else{
        printf("Found it at index - %ld - \n", p - s); //p - s is a long
    }
    return 0;
}