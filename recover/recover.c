#include <stdio.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
int main(int argc, char *argv[]){
    (void)argc;
    if(argc != 2){
        fprintf("Usage: *.raw file");
        return 1;
    }
    if(fopen(argv[1], "r") == NULL){
        fprinf("Cannot open file");
        return 2;
    }
    FILE *f = fopen(argv[1], "r");
    uint8_t buf[512];
    int counter = 0;
    FILE *fw = NULL;
    while(fread(buf, BLOCK_SIZE, 1, f)){
        if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0){
            if(fw != NULL){
                fclose(fw);
            }
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
            fw = fopen(filename, "w");
            counter++;
        }
        if(fw != NULL){
            fwrite(buf, BLOCK_SIZE, 1, fw);
        }
    }
    if(fw != NULL){
        fclose(fw);
    }
    fclose(f);
}