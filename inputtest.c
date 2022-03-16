#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int MAX_LEN = 100;
    int i = 0;
    char ch;
    char s[MAX_LEN];
    char sen[100];
    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("%c\n", ch);
    printf("Enter a string: ");
    scanf("%s", s);
    printf("%s\n", s);
    printf("Enter a sentence: ");
    scanf("\n");
    fgets(sen, 100, stdin);
    printf("%s", sen);
    return 0;
}
