#include <stdio.h>
int main(void)
{
int vys, vys2, vys3, s, d, e;
{
printf("Введите высоту лесенки от 1 до 23: ");
scanf("%i", &vys);
}
while (vys<1 || vys>23)
{
printf("Ошибка, введите ещё раз: ");
scanf("%i", &vys);
}
vys2=vys;
vys3=vys;
for(e=1; e<=vys2; e++)
   {
	 vys=vys-1;
    for(s=1; s<=vys; s++)
     {
		 printf("%c", ' ');
     }
    for(d=vys; d<=vys3; d++)
     {
	     printf("%c", '#');
	 }
    printf("\n");
   }
}