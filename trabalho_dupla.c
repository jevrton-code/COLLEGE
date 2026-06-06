#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char descricoes[100][51];
    int prioridades[100];
    int status[100];
    int total = 0;
    int i, p, num, continuar;
    char entrada[51];

    printf("=== Cadastro de Tarefas ===\n");
    printf("Digite \"fim\" como descricao para encerrar o cadastro.\n\n");

    while (total < 100) {
        printf("Descricao: ");
        scanf(" %[^\n]", entrada);

        if (strcmp(entrada, "fim") == 0) {
            break;
        }

        strcpy(descricoes[total], entrada);
        status[total] = 0;

        do {
            printf("Prioridade (1-5): ");
            scanf("%d", &prioridades[total]);
        } while (prioridades[total] < 1 || prioridades[total] > 5);

        total++;
        printf("\n");
    }

    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return 0;
    }

    printf("\n=== Tarefas cadastradas ===\n");
    for (i = 0; i < total; i++) {
        printf("%d. [ ] %s\n", i + 1, descricoes[i]);
    }

    printf("\n=== Marcar tarefas concluidas ===\n");
    printf("Digite o numero da tarefa para marcar como concluida (0 para encerrar):\n");

    do {
        scanf("%d", &num);
        if (num >= 1 && num <= total) {
            status[num - 1] = 1;
        } else if (num != 0) {
            printf("Numero invalido. Tente novamente (0 para encerrar):\n");
        }
    } while (num != 0);

    printf("\n=== Lista final de tarefas ===\n");
    for (i = 0; i < total; i++) {
        if (status[i] == 0) {
            printf("%d. [ ] %s\n", i + 1, descricoes[i]);
        }
    }
    for (i = 0; i < total; i++) {
        if (status[i] == 1) {
            printf("%d. [x] %s\n", i + 1, descricoes[i]);
        }
    }

    printf("\n=== Tarefas pendentes por prioridade (5 a 1) ===\n");
    continuar = 0;
    for (p = 5; p >= 1; p--) {
        for (i = 0; i < total; i++) {
            if (status[i] == 0 && prioridades[i] == p) {
                printf("%d. [ ] %s (prioridade %d)\n", i + 1, descricoes[i], p);
                continuar = 1;
            }
        }
    }

    if (!continuar) {
        printf("Nenhuma tarefa pendente.\n");
    }

    return 0;
}
