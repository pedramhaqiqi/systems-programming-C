#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_assignment_validator(char* line){
    int t = 0;
    char eql = '=';
    if (strchr(line,eql)){
        t = 1;
    }
}

typedef struct variable{
    int size;
    char var_name[MAX_VAR_LEN];
    char scope[MAX_NAME_LEN];
    char type[MAX_TYPE_LEN];
    struct var_struct *next; 
} VAR;

VAR variable_parser(char* line){
    VAR parse_var;

}

int alloc_validator(char* line){
    int t = 0;
    char mall[] = "malloc(";
    char call[] = "calloc(";
    if (strstr(line, mall)){
        t = 1;
    }
    else if(strstr(line, call)){
        t = 1;
    }
    return t;

}
int ifloops_validator(char* line){
    int t = 0;
    char ifword[] = "if (";
    char forword[] = "for(";
    char whileword[] = "while(";

    if (strstr(line, ifword)){
        t = 1;
    }
    else if(strstr(line, forword)){
        t = 1;
    }
    else if(strstr(line, whileword)){
        t = 1;
    }
    return t;
}



int main(int argc, char** argv){
    //fgets reutrns the pointer back if it was successful reading the line, otherwise null;
    FILE * fp = fopen(argv[1],"r");
    char line_code[256];
    // char parsed[256];
    int x;
    if (fgets(line_code, 256, fp) == NULL){
        fclose(fp);
        exit(1);
    }
    
    fclose(fp);
    
    // sscanf(line_code, "int %[^;]", parsed);

    
    printf("%d\n", x);
    

}