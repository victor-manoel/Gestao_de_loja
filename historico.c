#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "historico.h"
#define SIZE 200 //defini uma variável constante

historico listaHistorico[100];
int contHistorico = 0;

void cadastroHistorico(historico aux){
  listaHistorico[contHistorico] = aux;
  contHistorico++;
}

void listarVendas() {
  int i;
  for(i = 0; i < contHistorico; i++) {
    printf("Codigo vendedor: %s\n", listaHistorico[i].codVendedor);
    printf("Codigo produto: %s\n", listaHistorico[i].codProduto);
    printf("CPF Cliente: %s\n", listaHistorico[i].cpfCliente);
    printf("Preço produto: %s\n", listaHistorico[i].precoProduto);
    printf("Quantidade: %s\n", listaHistorico[i].quantidade);
    printf("\n");
  }
}