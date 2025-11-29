#include <string.h>
#include "../include/produto.h" // Inclui a definição da struct

// Adiciona um produto ao vetor de estoque
// Retorna 1 se sucesso, 0 se erro
int adicionar_produto(Produto *estoque, int *total_produtos, Produto novo_produto) {
    if (*total_produtos >= LIMITE_MAXIMO) {
        return 0; // Falha
    }

    // Adiciona na posição atual e incrementa o total
    estoque[*total_produtos] = novo_produto;
    (*total_produtos)++;
    return 1; // Sucesso
}

// Busca pelo codigo
int buscar_produto_por_codigo(Produto *estoque, int total_produtos, int codigo_busca) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo_busca) {
            return i; // Retorna a posição no vetor
        }
    }
    return -1; // Não encontrado
}
// Verifica se o estoque está abaixo do mínimo
int verificar_status_baixo(Produto p) {
    if (p.quantidade < p.estoque_minimo) {
        return 1;
    }
    return 0;
}