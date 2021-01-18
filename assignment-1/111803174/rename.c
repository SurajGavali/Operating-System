#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    if( !link(argv[1], argv[2])){
        return 1;
    }
    return 0;
}