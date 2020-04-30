#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cliente.h"
#include "fornecedor.h"
#include "produto.h"
#include "vendedor.h"
#include "historico.h"

void menuCliente();
void menuFornecedor();
void menuProduto();
void vendaProduto();
void estoque();


void menu() {
  //system("clear");
  int op;
  do {
    printf("GERENCIAR\n");
    printf("-----------------\n");
    printf("1 - Clientes\n");
    printf("2 - Fornecedores\n");
    printf("3 - Produtos\n");
    printf("4 - Vendedores\n");
    printf("5 - Vendas\n");
    printf("6 - Controle de estoque\n");
    printf("7 - historico de compras\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    if (op < 0 && op > 5) {
      printf("Opcao invalida. Digite novamente\n");
    }
  } while (op < 0 && op > 5);

  //system("clear");

  switch (op) {  
    case 1:
      menuCliente();
      break;
    case 2:
      menuFornecedor();
      break;
     case 3:
      menuProduto();
      break;
    case 4:
      //menuVendedor();
      break;
    case 5:
      vendaProduto();
      break;
    case 6:
      estoque();
      break;
    case 7:
      listarVendas();
      break;
  }

  if (op != 0) {
    printf("\nDigite 1 para voltar ao MENU ou qualquer numero para sair: ");
    scanf("%d", &op);
  }

  if (op == 1) {
    menu();
  }
}

void menuCliente() {
  int op;
  do {
    printf("CLIENTE\n");
    printf("1 - Cadastrar clientes\n");
    printf("2 - Listar clientes\n");
    printf("3 - Pesquisar clientes\n");
    printf("4 - excluir clientes\n");
    printf("5 - alterar clientes\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    if (op < 0 && op > 5) {
      printf("Opcao invalida. Digite novamente\n");
    }
  } while (op < 0 && op > 5);

  //system("clear");

  switch (op) {  
    case 1:
      cadastroClientes();
      break;
    case 2:
      listarClientes();
      break;
     case 3:
      pesquisarClientes();
      break;
    case 4:
      excluirCliente();
      break;
    case 5:
      alterarCliente();
      break;
  }

  if (op != 0) {
    printf("\nDigite 1 para voltar ao MENU CLIENTE ou qualquer numero para sair: ");
    scanf("%d", &op);
  }

  if (op == 1) {
    menu();
  }
}

void menuFornecedor() {
  int op;
  do {
    printf("FORNECEDOR\n");
    printf("1 - Cadastrar fornecedor\n");
    printf("2 - Listar fornecedores\n");
    printf("3 - Pesquisar fornecedor\n");
    printf("4 - excluir fornecedor\n");
    printf("5 - alterar fornecedor\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    if (op < 0 && op > 5) {
      printf("Opcao invalida. Digite novamente\n");
    }
  } while (op < 0 && op > 5);

  //system("clear");

  switch (op) {  
    case 1:
      cadastroFornecedores();
      break;
    case 2:
      listarFornecedores();
      break;
     case 3:
      pesquisarFornecedores();
      break;
    case 4:
      excluirFornecedores();
      break;
    case 5:
      alterarFornecedores();
      break;
  }

  if (op != 0) {
    printf("\nDigite 1 para voltar ao MENU FORNECEDOR ou qualquer numero para sair: ");
    scanf("%d", &op);
  }

  if (op == 1) {
    menuFornecedor();
  }  
}

void menuProduto() {
  int op;
  do {
    printf("PRODUTOS\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produto\n");
    printf("3 - Pesquisar produto\n");
    printf("4 - excluir produto\n");
    printf("5 - alterar produto\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    if (op < 0 && op > 5) {
      printf("Opcao invalida. Digite novamente\n");
    }
  } while (op < 0 && op > 5);

  //system("clear");

  switch (op) {  
    case 1:
      cadastroProdutos();
      break;
    case 2:
      listarProdutos();
      break;
     case 3:
      pesquisarProdutos();
      break;
    case 4:
      excluirProdutos();
      break;
    case 5:
      alterarProdutos();
      break;
  }

  if (op != 0) {
    printf("\nDigite 1 para voltar ao MENU PRODUTOS ou qualquer numero para sair: ");
    scanf("%d", &op);
  }

  if (op == 1) {
    menuProduto();
  }  
}

void vendaProduto() {
  char qtdProd[100], codVendedor[100];
  char cpf[100], codigoProd[100];
  char precoProd[100];
  printf("Digite o codigo do vendedor: ");
  scanf("%s", codVendedor);
  printf("Digite o CPF: ");
  scanf("%s", cpf);
  printf("Digite o codigo do produto: ");
  scanf("%s", codigoProd);
  printf("Digite o preco do produto: ");
  scanf("%s", precoProd);
  printf("Digite a quantidade: ");
  scanf("%s", qtdProd);

  bool validar = false;
  validar = validarCliente(cpf);
  validar = validarCodProduto(codigoProd, qtdProd);
  validar = validarVendedor(codVendedor);

  if (validar) {
    historico aux;
    strcpy(aux.codProduto, codigoProd);
    strcpy(aux.codVendedor, codVendedor);
    strcpy(aux.precoProduto, precoProd);
    strcpy(aux.cpfCliente, cpf);
    strcpy(aux.quantidade, qtdProd);
    cadastroHistorico(aux);

    printf("Produto vendido com sucesso\n");
  } else {
    printf("Dados invalidos\n");
  }
}

int main() {
  menu();
  return 0;
}

