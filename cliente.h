#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define SIZE 200 //defini uma variável constante

typedef struct cliente cliente;
struct cliente {
  char nome[SIZE];
  char cep[SIZE];
  char cpf[SIZE];
  char codigo[SIZE];
};

void cadastroClientes();
void listarClientes();
void pesquisarClientes();
void excluirCliente();
void alterarCliente();

bool validarCliente(char *cpf);



#endif // CLIENTE_H_INCLUDED