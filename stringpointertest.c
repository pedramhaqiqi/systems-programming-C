#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun(char *string){
	char s[] = "tiramisu";
    strcpy(string, s);
    

}

int main() {
    char *sweet = malloc(20 * sizeof(char));
    fun(sweet);
    printf("%s",sweet);
    return 0;
}
