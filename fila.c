#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Função para criar a fila
struct Fila* criar_fila() {
    struct Fila* fila = (struct Fila*) malloc(sizeof(struct Fila));
    fila->frente = 0;
    fila->traseira = -1;
    fila->tamanho = 0;
    return fila;
}

// Função para destruir a fila
void destruir_fila(struct Fila* fila) {
    free(fila);
}

// Verifica se a fila está cheia
int esta_cheia(struct Fila* fila) {
    return (fila->tamanho == TAMANHO_MAX);
}

// Verifica se a fila está vazia
int esta_vazia(struct Fila* fila) {
    return (fila->tamanho == 0);
}

// Inserir um cliente na fila
void inserir_cliente(struct Fila* fila, int cliente) {
    if (esta_cheia(fila)) {
        printf("Fila cheia! Cliente %d não pôde ser adicionado.\n", cliente);
        return;
    }
    fila->traseira = (fila->traseira + 1) % TAMANHO_MAX;
    fila->itens[fila->traseira] = cliente;
    fila->tamanho++;
    printf("Cliente %d adicionado à fila.\n", cliente);
}

// Remover o cliente da fila
int remover_cliente(struct Fila* fila) {
    if (esta_vazia(fila)) {
        printf("Fila vazia! Nenhum cliente para remover.\n");
        return INT_MIN;
    }
    int cliente_removido = fila->itens[fila->frente];
    fila->frente = (fila->frente + 1) % TAMANHO_MAX;
    fila->tamanho--;
    printf("Cliente %d atendido e removido da fila.\n", cliente_removido);
    return cliente_removido;
}

// Consultar o próximo cliente na fila
int consultar_proximo_cliente(struct Fila* fila) {
    if (esta_vazia(fila)) {
        printf("Fila vazia! Nenhum cliente para consultar.\n");
        return INT_MIN;
    }
    return fila->itens[fila->frente];
}

// Exibir o estado da fila
void exibir_fila(struct Fila* fila) {
    if (esta_vazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Clientes na fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->frente + i) % TAMANHO_MAX;
        printf("%d ", fila->itens[index]);
    }
    printf("\n");
}
