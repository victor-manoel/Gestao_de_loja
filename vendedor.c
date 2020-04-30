#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vendedor.h"

bool validarVendedor(char* cod) {
  strcpy(listaVendedor[0].nome, "Andre");
  strcpy(listaVendedor[0].cod, "0001");
  strcpy(listaVendedor[1].nome, "Francisco");
  strcpy(listaVendedor[1].cod, "0002");
  strcpy(listaVendedor[2].nome, "Victor");
  strcpy(listaVendedor[2].cod, "0003");
  strcpy(listaVendedor[3].nome, "Gustavo");
  strcpy(listaVendedor[3].cod, "0004");
  int i;
  for(i = 0; i < 4; i++) {
    if (strcmp(cod, listaVendedor[i].cod) == 0) {
      return true;
    }
  }

  return false;
}