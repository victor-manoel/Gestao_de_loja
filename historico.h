#ifndef HISTORICO_H_INCLUDED
#define HISTORICO_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define SIZE 200 //defini uma variável constante

typedef struct historico historico;
struct historico {
  char codVendedor[SIZE];
  char codProduto[SIZE];
  char cpfCliente[SIZE];
  char precoProduto[SIZE];
  char quantidade[SIZE];  
};

void cadastroHistorico();
void listarVendas();



#endif // HISTORICO_H_INCLUDED