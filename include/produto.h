#ifndef PRODUTO_H
#define PRODUTO_H

#define LIMITE_MAXIMO 50
#define TAM_NOME 50

// Definição da Struct (agrupa os dados que antes eram vetores separados)
typedef struct {
    int codigo;
    char nome[TAM_NOME];
    float preco;
    int quantidade;
    int estoque_minimo;
} Produto;

int adicionar_produto(Produto *estoque, int *total_produtos, Produto novo_produto);
int buscar_produto_por_codigo(Produto *estoque, int total_produtos, int codigo_busca);
int verificar_status_baixo(Produto p); // Retorna 1 se estiver baixo, 0 se OK

#endif