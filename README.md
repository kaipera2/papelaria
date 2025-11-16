# Controle de Estoque de Papelaria
## 1. Objetivo Geral
Gerenciamento do estoque de produtos de uma empresa de papelaria(ou qualquer outra).
## 2. Funcionalidades Implementadas
O sistema atual, controlado por menu, permite as seguintes operações:
* **1. Inserir Novo Produto:**
    * Solicita e armazena código, nome, preço, quantidade atual e estoque mínimo.
    * Possui um limite máximo de cadastro de produtos (`LIMITE_MAXIMO`).
* **2. Verificar Estoque de um Produto:**
    * Permite a busca de um produto específico através do seu código.
    * Exibe os detalhes do produto (nome, preço, quantidade, estoque mínimo).
    * Informa o status ("Estoque OK" ou "ABAIXO DO ESTOQUE MINIMO!").
* **3. Listar todos os Produtos e Status:**
    * Exibe um relatório com todos os produtos cadastrados.
    * Mostra os dados principais (Código, Nome, Preço, Quantidade) e o status de estoque ("OK" ou "ABAIXO").
* **0. Sair do Programa:**
    * Encerra a execução do aplicativo.
## 3. Autores
* Kainã Samuel Ribeiro Cantanhede
* João Paulo Gomes Nogueira
## 4. Etapas Futuras
As próximas funcionalidades a serem implementadas, conforme o plano original de "gerenciar produtos", são:
* Implementar a função de **editar** informações de um produto existente.
* Implementar a função de **excluir** um produto do estoque.
* Criar uma função para **atualizar a quantidade** (registrar entrada/saída de itens).
