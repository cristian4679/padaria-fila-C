#include <stdio.h>
#include "fila.h"

int main() {
    struct Fila* fila = criar_fila();
    int opcao, cliente = 1;

    do {
        printf("\nSistema de Gerenciamento de Fila - Padaria\n");
        printf("1. Adicionar cliente à fila\n");
        printf("2. Atender (remover) cliente da fila\n");
        printf("3. Consultar próximo cliente\n");
        printf("4. Exibir estado da fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_cliente(fila, cliente++);
                break;
            case 2:
                remover_cliente(fila);
                break;
            case 3: {
                int proximo_cliente = consultar_proximo_cliente(fila);
                if (proximo_cliente != INT_MIN) {
                    printf("Próximo cliente a ser atendido: %d\n", proximo_cliente);
                }
                break;
            }
            case 4:
                exibir_fila(fila);
                break;
            case 5:
                printf("Saindo...\n");
                destruir_fila(fila);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
