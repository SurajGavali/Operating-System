#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char data[7];
    fp = fopen(argv[1], "r");
    if(fp != NULL){
        fseek(fp,4,SEEK_SET);
        fread(data, sizeof(char), 5 , fp);
        printf("%s", data);
    }
    else
    {
        printf("error\n");
        return -1;
    }
    fclose(fp);
    return 0;
}