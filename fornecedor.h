#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED

#include <stdio.h>
#define SIZE 200 //defini uma variável constante

typedef struct fornecedor fornecedor;
struct fornecedor {
  char nome[SIZE];
  char cnpj[SIZE];
  char endereco[SIZE];
  char telefone[SIZE];
  int quantFornecedor;
};

void cadastroFornecedores();
void listarFornecedores();
void pesquisarFornecedores();
void excluirFornecedores();
void alterarFornecedores();

#endif // FORNECEDOR_H_INCLUDED
