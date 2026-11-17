#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("\nValor digitado: %d", numero);
    printf("\nEndereco de memoria: %p\n", (void*)&numero);

    return 0;
}
