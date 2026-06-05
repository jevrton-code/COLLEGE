#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
    printf("= = = = Menu = = = =\n");
    printf("1 - Cadastrar aluno e sua nota\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Sair\n");
}

int main() {
    /* Aluno */
    char nome[128];
    float nota;

    /* Lista de Alunos */
    char lista_alunos[100][128];
    float lista_notas[100];
    int contador_alunos = 0;

    int opcao;
    do {
        print_menu();
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nome);
                printf("Digite a nota do aluno: ");
                scanf("%f", &nota);

                if (contador_alunos + 1 > 100) {
                    printf("Lista de alunos cheia!\n");
                    break;
                }
                strcpy(lista_alunos[contador_alunos], nome);
                lista_notas[contador_alunos] = nota;

                contador_alunos++;
                printf("\nAluno cadastrado com sucesso!\n");
                break;
            case 2:
                printf("====================\n");    

                if (contador_alunos == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    printf("====================\n");
                    break;
                }
                
                printf("Lista de alunos:\n");
                printf("Nome - Nota\n");
                printf("--------------------\n");
                
                for (int i = 0; i < contador_alunos; i++) {
                    printf("%s - %.1f\n", lista_alunos[i], lista_notas[i]);
                }

                printf("--------------------\n");
                printf("====================\n");
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 3);
    return 0;
}