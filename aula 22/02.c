#include <stdio.h>
int main(void) {
 int idade = 20;
 int *ponteiro;
 ponteiro = &idade;
 printf("Valor da idade: %d\n", idade);
 printf("Endereco da idade: %p\n", (void *)&idade);
 printf("Endereco armazenado no ponteiro: %p\n",
 (void *)ponteiro);
 printf("Valor acessado pelo ponteiro: %d\n", *ponteiro);
 return 0;
}
