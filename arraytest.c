#include <stdio.h>
#include <stdlib.h>


int main (){
    
    int num[] = {154, 160, 138, 128, 75, 64};
    int ceil;
    for(int i=0; i<6 ; i++){
        if (num[i] % 8 == 0){
            ceil = num[i]/ 8;
        } else{
            ceil = (num[i] / 8) + 1;
        }
        printf("ceil of [%d]/8 is [%d]\n", num[i], ceil);
    }
    
    return 0;
}
