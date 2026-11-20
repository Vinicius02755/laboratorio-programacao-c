#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char nome[50];
    int matricula;
    int quantidade;

    printf("===== CADASTRO DE FUNCIONARIOS =====\n\n");

    do {
        printf("Quantos funcionarios deseja cadastrar (1 a 5)? ");
        scanf("%d", &quantidade);

        if (quantidade < 1 || quantidade > 5) {
            printf("Quantidade invalida!\n\n");
        }
    } while (quantidade < 1 || quantidade > 5);

    arquivo = fopen("funcionarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nFuncionario %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", nome);

        printf("Matricula: ");
        scanf("%d", &matricula);

        fprintf(arquivo, "Nome: %s\n", nome);
        fprintf(arquivo, "Matricula: %d\n", matricula);
        fprintf(arquivo, "------------------------------\n");
    }

    fclose(arquivo);

    printf("\nDados gravados com sucesso no arquivo funcionarios.txt!\n");

    return 0;
}
