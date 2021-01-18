#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    FILE *f1;
    char data[102] = "khgva_iyc_iygWK_kuvea_kgva_hbvaeh_jkbavk_vakhb_ahb_avugb_vkhb_avhkjbvKUHB_HKVAH_avoha_aejvh";
    
    f1 = fopen(argv[1], "w+");
    if(f1 != NULL){
        fwrite(data, sizeof(char), 100 , f1);
        return 1;
    } 
    else
    {
        return 0;
    }
}