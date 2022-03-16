#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char test1[] = "hello";
    char test2[] = "\0";
    printf("sizeof returned[%lu] -- strlen returned [%lu]\n", sizeof(test1), strlen(test1));

    printf("test2 pirints [%s] -- with sizeof returned[%lu] -- and strlen returned [%lu]\n", test2, sizeof(test2), strlen(test2));


    return 0;
}

//Reason that the output of firt test is 
//"sizeof returned[6] -- strlen returned [5]" is that
// sizeof() counts the number of bytes
// needed to store all of hello + \0 character 
//while strlen only counts the number of characters, excluding the 0 str terminator

//Reason for test2 to return 2 as the sizeof \0, is becuase \ + 0 = 1 + 1, lol