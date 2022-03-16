
int main(){
    int i = 0;
    char name[] = malloc(sizeof(char * 2));
    char list[] = malloc(sizeof(char * 3));
    
    for (int i; i < sizeof(name); i){
        printf("%c", name[i]);
    }

    free(name);
    free(list);
    
    return 0;
}