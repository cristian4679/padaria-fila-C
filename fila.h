#ifndef FILA_H
#define FILA_H

#include <limits.h>  // Para usar INT_MIN

// Define o tamanho máximo da fila
#define TAMANHO_MAX 5

// Estrutura da fila
struct Fila {
    int itens[TAMANHO_MAX];
    int frente;
    int traseira;
    int tamanho;
};

// Protótipos das funções
struct Fila* criar_fila();
void destruir_fila(struct Fila* fila);
int esta_cheia(struct Fila* fila);
int esta_vazia(struct Fila* fila);
void inserir_cliente(struct Fila* fila, int cliente);
int remover_cliente(struct Fila* fila);
int consultar_proximo_cliente(struct Fila* fila);
void exibir_fila(struct Fila* fila);

#endif
