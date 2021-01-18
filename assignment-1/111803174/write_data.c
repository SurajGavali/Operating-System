#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    FILE *f1, *f2;
    char data[102];
    
    f1 = fopen(argv[1], "r");
    if(f1 != NULL){
        fread(data, sizeof(char), 100 , f1);
        f2 = fopen(argv[2], "w");
        if(f2 != NULL){
            fwrite(data, sizeof(char), 100, f2);
            fclose(f2);
            return 1;
        }
        else{
            fclose(f2);
            return -1;
        }
        
    }
    else
    {
        return -1;
    }
}