
#include <stdio.h> 
#include <stdlib.h> // For exit() 
  
int main(int argc, char* argv[]) 
{ 
    FILE *original_file, *copy_file; 
    char c;
    
  
    // Open file for reading 
    original_file = fopen(argv[1], "r"); 
    if (original_file == NULL) 
    { 
        exit(1); 
        
    } 
  
    // Open another file for writing 
    copy_file = fopen(argv[2], "w"); 
    if (copy_file == NULL) 
    { 
        exit(1); 

    } 
  
    // Read contents from file 
    c = fgetc(original_file); 
    while (c != EOF) 
    { 
        fputc(c, copy_file); 
        c = fgetc(original_file); 
    }  
  
    fclose(original_file); 
    fclose(copy_file); 
    return 0; 
}
