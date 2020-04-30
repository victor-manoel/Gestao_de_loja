#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define SIZE 200 //defini uma variável constante


typedef struct produto produto;
struct produto {
  char nome[SIZE];
  char valor[SIZE];
  char qtdE[SIZE];
  char codigo[SIZE];
};



void cadastroProdutos();
void listarProdutos();
void pesquisarProdutos();
void excluirProdutos();
void alterarProdutos();

bool validarCodProduto(char* cod, char* qtdProd);
void estoque();


#endif // CLIENTE_H_INCLUDED
