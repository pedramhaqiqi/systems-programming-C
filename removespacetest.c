#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGHT 100
#define MAX_TYPE_LENGHT 30
#define MAX_NAME_LENGHT 30
#define MAX_VAR_LENGHT 30
#define MAX_SIZE_LENGTHTHTT 30

typedef struct variable{
    char size[MAX_SIZE_LENGTHTHTT];
    char name[MAX_VAR_LENGHT];
    char type[MAX_TYPE_LENGHT]; 
    struct variable *next;
}VAR;

typedef struct functions{
    int totallines;
    int totalvar;
    char name[MAX_NAME_LENGHT];
    VAR *head;    //local variables
}FUN;


VAR* createnewvar(char* size, char* name, char* type){
    
    VAR *variable = malloc(sizeof(VAR));
    
    strcpy(variable->name, name);
    
    strcpy(variable->type, type);
   
    strcpy(variable->size, size);
    
    return variable;
}

VAR* append(VAR *head, char* size, char* name, char* type){
    // Returns new head after inserting newvar
    VAR* newvar = createnewvar(size, name, type);
    newvar->next = head;
    return newvar;
}
char* remove_space(char* string){
    char* new= malloc(sizeof(char) * (strlen(string)+1)) ;
    char* copyof;
    char* token;
    copyof = strdup(string);

    while((token = strtok_r(copyof," ", &copyof))){
        strncat(new, token, strlen(token));
    }
    new[strlen(new)] = 0;
    return new;
}
char *remove_semicolon(char* string){
    char* new= malloc(sizeof(char) * (strlen(string)+1)) ;
    char* copyof;
    char* token;
    copyof = strdup(string);

    while((token = strtok_r(copyof,";", &copyof))){
        strncat(new, token, strlen(token));
    }
    new[strlen(new)] = 0;
    return new;
}
char *remove_semicolon_space(char* string){
    char* new= malloc(sizeof(char) * (strlen(string)+1)) ;
    char* copyof;
    char* token;
    copyof = strdup(string);

    while((token = strtok_r(copyof,";", &copyof))){
        strncat(new, token, strlen(token));
    }
    new[strlen(new)] = 0;
    return remove_space(new);
}


int comma_validator(char* line){
    int t = 0;
    char comma = ',';
    if (strchr(line,comma)){
        t = 1;
    }
    return t;
}

char* parse_by_eql(char* string){
    char* new = malloc(sizeof(char) * (strlen(string)+1)) ;
    char* copyof;
    char* token;
    copyof = strdup(string);

    token = strtok_r(copyof,"=", &copyof);
    strncat(new, token, strlen(token));
    
    new[strlen(new)] = 0;
    return new;
}

char* parse_by_type(char* string, char* type){
    char* new= malloc(sizeof(char) * (strlen(string)+1)) ;
    char* copyof;
    char* token;
    copyof = strdup(string);

    while((token = strtok_r(copyof,type , &copyof))){
        strncat(new, token, strlen(token));
    }
    new[strlen(new)] = 0;
    return new;
}

char* parse_by_comma(char* string){
    char* new = malloc(sizeof(char) * (strlen(string)+1)) ;
    char* copyof;
    char* token;
    copyof = strdup(string);

    while((token = strtok_r(copyof,",", &copyof))){
        strncat(new, token, strlen(token));
    }
    new[strlen(new)] = 0;
    return new;
}


char* test(char * line){
    char *nospace = remove_space(line);
    char *variable;
    variable = parse_by_type(remove_semicolon(nospace), "int");
    return variable;
}

int main(){
    
    char s[50] = "int x,z, j, k = 10;";
    char *size = "sizeof(int)";
    char *type = "int";
    char* variables = parse_by_eql(parse_by_comma(parse_by_type(remove_semicolon_space(s),"int")));
    printf("%s\n", variables);
    
    
    VAR* head = NULL;


    
    
    for(int i = 0; i<; i++){
       head = append(head, size, "TRRR",type);
    }

    

        

    //printf("result remove semi %s\n", remove_semicolon(s));
    //printf("result remove space %s\n", remove_space(s));
    //printf("result remove semi and space %s\n", remove_space(remove_semicolon(s)));
    //test(s);

    
    return 0;
}