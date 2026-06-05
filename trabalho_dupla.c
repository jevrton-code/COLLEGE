#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char descricao[100][128];
int prioridade[100];
int status[100];
int contador_tarefas = 0;

void print_menu() {
    printf("= = = = Menu = = = =\n");
    printf("1 - Cadastrar tarefa\n");
    printf("2 - Listar tarefas\n");
    printf("3 - Sair\n");
}

void cadastrar_tarefa() {
    if (contador_tarefas + 1 > 100) {
        printf("Lista de tarefas cheia!\n");
        return;
    }

    printf("Digite a descricao da tarefa (max 128 caracteres): ");
    scanf(" %[^\n]", descricao[contador_tarefas]);

    printf("Digite a prioridade da tarefa (1-5): ");
    scanf("%d", &prioridade[contador_tarefas]);
    do {
        if (prioridade[contador_tarefas] < 1 || prioridade[contador_tarefas] > 5) {
            printf("Prioridade invalida! Digite novamente (1-5): ");
            scanf("%d", &prioridade[contador_tarefas]);
        }
    } while (prioridade[contador_tarefas] < 1 || prioridade[contador_tarefas] > 5);

    printf("Digite o status da tarefa (0 [em andamento] - 1 [concluida]): ");
    scanf("%d", &status[contador_tarefas]);
    do {
        if (status[contador_tarefas] < 0 || status[contador_tarefas] > 1) {
            printf("Status invalido! Digite novamente (0 [em andamento] - 1 [concluida]): ");
            scanf("%d", &status[contador_tarefas]);
        }
    } while (status[contador_tarefas] < 0 || status[contador_tarefas] > 1);

    contador_tarefas++;
    printf("\nTarefa cadastrada com sucesso!\n");
    return;
}

void listar_tarefas() {
    printf("Lista de tarefas:\n");
    printf("Descricao - Prioridade - Status\n");
    printf("--------------------\n");

    if (contador_tarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        printf("--------------------\n");
        return;
    }

    char status_str[10];
    for (int i = 0; i < contador_tarefas; i++) {
        if (status[i] == 0) {
            strcpy(status_str, "em andamento");
        } else {
            strcpy(status_str, "concluida");
        }

        printf("%s - %d - %s\n", descricao[i], prioridade[i], status_str);
    }
    printf("--------------------\n");
}

int main() {
    int opcao;
    do {
        print_menu();
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar_tarefa();
                break;
            case 2:
                listar_tarefas();
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