#include <stdio.h>

typedef struct vendedor vendedor;
struct vendedor {
  char nome[100];
  char cod[100];
};

vendedor listaVendedor[4];
