#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[]){
    int k = atoi(argv[1]);

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
            if(arr[i] + k < 91)
            printf("%c", arr[i] + k);
            else{
                int a = 90 - arr[i];
                printf("%c", 64 + k-a);
            }
        } else if(arr[i] > 96 && arr[i] < 123){
            if(arr[i] + k < 123)
            printf("%c", arr[i] + k);
            else{
                int a = 123 - arr[i];
                printf("%c", 97 + k-a);
            }
        } else
            printf("%c", arr[i]);
    }
    printf("\n");
    (void)argc;
}