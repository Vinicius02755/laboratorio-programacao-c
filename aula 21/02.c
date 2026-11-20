#include <stdio.h>

typedef struct {
    char nome[50];
    float salario;
    int horasExtras;
} Funcionario;

int main(void) {
    FILE *arquivo;
    Funcionario funcionarios[5];
    int quantidade;
    int caractere;

    printf("===== CADASTRO DE FUNCIONARIOS =====\n\n");

    do {
        printf("Quantos funcionarios deseja cadastrar (1 a 5)? ");
        scanf("%d", &quantidade);

        if (quantidade < 1 || quantidade > 5) {
            printf("Quantidade invalida!\n\n");
        }
    } while (quantidade < 1 || quantidade > 5);

    for (int i = 0; i < quantidade; i++) {
        printf("\nFuncionario %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", funcionarios[i].nome);

        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);

        printf("Horas extras: ");
        scanf("%d", &funcionarios[i].horasExtras);
    }

    // modo "a" acrescenta os novos registros sem apagar os anteriores
    arquivo = fopen("funcionarios.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Nome: %s\n", funcionarios[i].nome);
        fprintf(arquivo, "Salario: R$ %.2f\n", funcionarios[i].salario);
        fprintf(arquivo, "Horas extras: %d\n", funcionarios[i].horasExtras);
        fprintf(arquivo, "------------------------------\n");
    }

    fclose(arquivo);

    printf("\nDados gravados com sucesso!\n");

    arquivo = fopen("funcionarios.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("\n===== FUNCIONARIOS CADASTRADOS =====\n\n");

    while ((caractere = fgetc(arquivo)) != EOF) {
        putchar(caractere);
    }

    fclose(arquivo);

    return 0;
}