#ifndef INTERFACE_H
#define INTERFACE_H

#include "produto.h" // Precisa conhecer a struct Produto

// Protótipos das funções de Interface (src/interface.c)
int exibir_menu();
Produto ler_dados_produto();
void exibir_sucesso_cadastro(int numero_produto);
void exibir_erro_limite();
void exibir_erro_produto_nao_encontrado(int codigo);
void exibir_detalhes_produto(Produto p);
void listar_todos_produtos(Produto *estoque, int total_produtos);

#endif