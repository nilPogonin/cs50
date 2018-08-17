#include <cs50.h>
#include <stdio.h>

int main(void){
    printf("Введите время проведнное в душе: ");
    int m = GetInt();
    printf("За время пребывания в душе вы истратили воду равноценную %i бутылкам воды:)\n", m * 12);
}