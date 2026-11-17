#include <stdio.h>
int main(void) {
 int numeros[5] = {10, 20, 30, 40, 50};
 int *p = numeros;
 printf("Primeiro numero: %d\n", *p);
 printf("Segundo numero: %d\n", *(p + 1));
 printf("Terceiro numero: %d\n", *(p + 2));
 printf("Quarto numero: %d\n", *(p + 3));
 printf("Quinto numero: %d\n", *(p + 4));
 return 0;
}
