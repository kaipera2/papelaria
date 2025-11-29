#include <stdio.h>
#include <stdlib.h>
#include "../include/produto.h"   // a struct Produto e as constantes
#include "../include/interface.h" // os menus

int main() {
    Produto estoque[LIMITE_MAXIMO]; 
    int total_produtos = 0;
    int opcao;
    Produto novo_produto;
    int codigo_busca;
    int indice_encontrado;

    do {
        // Exibe o menu
        opcao = exibir_menu();

        switch (opcao) {
            case 1: // Inserir Novo Produto
                novo_produto = ler_dados_produto();
                if (adicionar_produto(estoque, &total_produtos, novo_produto)) {
                    exibir_sucesso_cadastro(total_produtos);
                } else {
                    exibir_erro_limite();
                }
                break;

            case 2: // Verificar estoque
                if (total_produtos == 0) {
                    printf("\nNenhum produto cadastrado para verificar.\n");
                } else {
                    printf("\nDigite o codigo do produto para verificar: ");
                    scanf("%d", &codigo_busca);

                    // Busca a posição do produto
                    indice_encontrado = buscar_produto_por_codigo(estoque, total_produtos, codigo_busca);

                    if (indice_encontrado != -1) {
                        exibir_detalhes_produto(estoque[indice_encontrado]);
                    } else {
                        exibir_erro_produto_nao_encontrado(codigo_busca);
                    }
                }
                break;

            case 3: // Listar Tudo
                listar_todos_produtos(estoque, total_produtos);
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}