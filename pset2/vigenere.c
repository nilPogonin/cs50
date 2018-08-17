#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[]){
    string k = argv[1];
    int j = 0;
    printf("plaintext: ");
    string str = get_string();
    int s = strlen(str);
    char arr[s];
    for(int i = 0; i < strlen(str); i++){
        arr[i] = str[i];
    }
    printf("ciphertext: ");
    for(int i = 0; i < strlen(str); i++){
        if(arr[i] >64 && arr[i] < 91){

            if(arr[i] + toupper(k[j%strlen(k)]) -65 < 91)
            printf("%c", arr[i] + toupper(k[j%strlen(k)])-65);
            else{
                int a = 90 - arr[i];
                printf("%c", 64 + toupper(k[j%strlen(k)])-a-65);
            }
            j++;
        } else if(arr[i] > 96 && arr[i] < 123){

            if(arr[i] + tolower(k[j%strlen(k)])-97 < 123)
            printf("%c", arr[i] + tolower(k[j%strlen(k)])-97);
            else{
                int a = 123 - arr[i];
                printf("%c", 97 + tolower(k[j%strlen(k)])-a-97);
            }
            j++;
        } else
            printf("%c", arr[i]);
    }
    printf("\n");
    (void)argc;
}