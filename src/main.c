/*Nome do projeto: Controle de estoque de papelaria 
Objetivo geral: Gerenciar estoque 
Principais funcionalidades previstas: Visualizar, inserir e gerenciar produtos de uma empresa 
Autor: [Kainã Samuel Ribeiro Cantanhede e João Paulo Gomes Nogueira] 
Etapas futuras: Implementar todas as funções
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE_MAXIMO 50
int main(){
    //declaração de variáveis
    int total_produtos = 0, codigo_produto[LIMITE_MAXIMO], opcao = -1, estoqueminimo[LIMITE_MAXIMO], qntd[LIMITE_MAXIMO];//array pra armazenar os dadso dos produto
    char nome[LIMITE_MAXIMO][50];//array pra armazenar os nomes dos produtos
    float preco[LIMITE_MAXIMO];//array pra armazenar os preços dos produtos

    do
    { //menu de controle
        printf("===========================================\n");
        printf("          MENU DE CONTROLE DE ESTOQUE\n");
        printf("===========================================\n");
        printf("1 - Inserir Novo Produto\n");
        printf("2 - Verificar Estoque de um Produto\n");
        printf("3 - Listar todos os Produtos e Status\n");
        printf("0 - Sair do Programa\n");
        printf("-------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            //inserção de produto
            case 1:
            printf("Inserindo produto\n");
            if (total_produtos<LIMITE_MAXIMO)//verificação de limite
            {
                //coleta de dados do produto
                total_produtos++;
                printf(">>> Cadastro do Produto #%d <<<\n", total_produtos);//mostra o número do produto que está sendo cadastrado
                printf("Codigo do produto: ");
                scanf("%d", &codigo_produto[total_produtos - 1]);
                printf("Nome do produto: ");
                scanf("%s", nome[total_produtos - 1]);
                printf("Preco unitario: RS");
                scanf("%f", &preco[total_produtos - 1]);
                printf("Quantidade atual em estoque: ");
                scanf("%d", &qntd[total_produtos - 1]);
                printf("Estoque minimo desejado: ");
                scanf("%d", &estoqueminimo[total_produtos - 1]);
                printf("produto cadastrado com sucesso\n");//confirmação de cadastro
                
            } else{
                printf("ERRO: Limite maximo de produtos atingido (%d).\n", LIMITE_MAXIMO);//mensagem de erro caso o limite seja atingido
            }
            break;
            case 2:
            //verificação de estoque
            printf("-------------------------------------------\n");
            printf("Verificando estoque\n");
            if (total_produtos == 0) {
                printf("Nenhum produto cadastrado.\n\n");
                break;
            }
            //busca por código
            int cod_busca = 0; //variável para armazenar o código buscado
            printf("Digite o codigo do produto para verificar o estoque: ");
            scanf("%d", &cod_busca);
            int posicao = -1;//variável para armazenar a posição do produto encontrado
            //mecanismo de busca
            for (int i = 0; i < total_produtos; i++) {//buscar dentro do array
                if (codigo_produto[i] == cod_busca) {
                posicao = i;
                break;
            }
            }
            if (posicao != -1) {//se encontrado, mostrar dados
                //exibir dados do produto
                printf("-------------------------------------------\n");
                printf("DADOS DO PRODUTO:\n");
                printf("Produto: %s\n", nome[posicao]);
                printf("Preco unitario: RS%.2f\n", preco[posicao]);
                printf("Quantidade em estoque: %d\n", qntd[posicao]);
                printf("Estoque minimo desejado: %d\n", estoqueminimo[posicao]);
                if (qntd[posicao] < estoqueminimo[posicao]) {
                    printf("Status: ABAIXO DO ESTOQUE MINIMO!\n");
                    printf("-------------------------------------------\n");
                } else {
                    printf("Status: Estoque OK.\n");
                    printf("-------------------------------------------\n");
                }
            } else {
                printf("Produto com codigo %d nao encontrado.\n", cod_busca);
                printf("-------------------------------------------\n");
            }
            break; 
            case 3:
            //listagem de produtos e status
            if (total_produtos == 0) {
                printf("Nenhum produto cadastrado.\n\n");
            } else {
                printf("===========================================\n");
                printf("      LISTA GERAL DE PRODUTOS E STATUS\n");
                printf("===========================================\n");
                //listagem
            for (int i = 0; i < total_produtos; i++) {//percorrer todos os produtos cadastrados
                printf("Cod: %d | Produto: %s  preco: %.2f | Qtd: %d | Status: ", codigo_produto[i], nome[i], preco[i], qntd[i]);//exibe os dados e ent pula pra proxima linha com o proximo produto
                if (qntd[i] < estoqueminimo[i]) {
                    printf("ABAIXO\n");
                } else {
                    printf("OK.\n");
                }
            }
            }
            break;
            case 0:
            //saída do programa
            printf("Saindo do programa...\n");
            break;
            default:
            printf("Opcao invalida! tente denovo.\n");
        }
    } while (opcao != 0);//loop do menu até a opção de saída ser escolhida
    return 0;
}