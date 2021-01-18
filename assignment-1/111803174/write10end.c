#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char data[10] = "surajgaval";
    printf("%s", data);
    fp = fopen(argv[1], "a+");
    if(fp != NULL){
        fwrite(data, sizeof(char), 10, fp);
        fclose(fp);
        return 1;
    }
    else
    {
        return -1;
    }
    
}