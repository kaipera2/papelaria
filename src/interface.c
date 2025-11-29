#include <stdio.h>
#include <stdlib.h>
#include "../include/interface.h"

// Exibe o menu e retorna a opção escolhida
int exibir_menu() {
    int opcao;
    printf("\n===========================================\n");
    printf("          MENU DE CONTROLE DE ESTOQUE\n");
    printf("===========================================\n");
    printf("1 - Inserir Novo Produto\n");
    printf("2 - Verificar Estoque de um Produto\n");
    printf("3 - Listar todos os Produtos e Status\n");
    printf("0 - Sair do Programa\n");
    printf("-------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// cria um struct Produto temporário
Produto ler_dados_produto() {
    Produto p;
    printf("\n>>> Preencha os dados do novo produto <<<\n");
    
    printf("Codigo do produto: ");
    scanf("%d", &p.codigo);
    
    printf("Nome do produto: ");
    scanf("%s", p.nome);
    
    printf("Preco unitario: R$");
    scanf("%f", &p.preco);
    
    printf("Quantidade atual em estoque: ");
    scanf("%d", &p.quantidade);
    
    printf("Estoque minimo desejado: ");
    scanf("%d", &p.estoque_minimo);
    
    return p;
}

void exibir_sucesso_cadastro(int numero_produto) {
    printf("Produto #%d cadastrado com sucesso!\n", numero_produto);
}

void exibir_erro_limite() {
    printf("ERRO: Limite maximo de produtos atingido (%d).\n", LIMITE_MAXIMO);
}

void exibir_erro_produto_nao_encontrado(int codigo) {
    printf("ERRO: Produto com codigo %d nao encontrado.\n", codigo);
    printf("-------------------------------------------\n");
}

// Exibe os detalhes de um produto
void exibir_detalhes_produto(Produto p) {
    printf("-------------------------------------------\n");
    printf("DADOS DO PRODUTO:\n");
    printf("Produto: %s\n", p.nome);
    printf("Preco unitario: R$%.2f\n", p.preco);
    printf("Quantidade em estoque: %d\n", p.quantidade);
    printf("Estoque minimo desejado: %d\n", p.estoque_minimo);
    
    // decidir qual mensagem mostrar
    if (verificar_status_baixo(p)) {
        printf("Status: ABAIXO DO ESTOQUE MINIMO!\n");
    } else {
        printf("Status: Estoque OK.\n");
    }
    printf("-------------------------------------------\n");
}

// Lista a tabela geral
void listar_todos_produtos(Produto *estoque, int total_produtos) {
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }

    printf("===========================================\n");
    printf("      LISTA GERAL DE PRODUTOS E STATUS\n");
    printf("===========================================\n");
    
    for (int i = 0; i < total_produtos; i++) {
        char status[10];
        if (verificar_status_baixo(estoque[i])) {
            sprintf(status, "ABAIXO");
        } else {
            sprintf(status, "OK");
        }

        printf("Cod: %d | Produto: %s | Preco: %.2f | Qtd: %d | Status: %s\n", 
               estoque[i].codigo, 
               estoque[i].nome, 
               estoque[i].preco, 
               estoque[i].quantidade, 
               status);
    }
}