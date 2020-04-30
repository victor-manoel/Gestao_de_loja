#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cliente.h"
#define SIZE 200 //defini uma variável constante

cliente listaClientes[100];
int contClientes = 0;

void salvarArqClientes();

void cadastroClientes(){
	cliente aux;
	int op;
	do{
    setbuf(stdin, NULL);
		printf("\nDigite o nome do cliente: ");
		scanf("%s", aux.nome);
		setbuf(stdin, NULL);
		printf("\nDigite o cep do cliente: ");
		scanf("%s", aux.cep);
		setbuf(stdin, NULL);
		printf("\nDigite o cpf do cliente: ");
		scanf("%s", aux.cpf);
		setbuf(stdin, NULL);
		printf("\nDigite o codigo do cliente: ");
		scanf("%s", aux.codigo);
		setbuf(stdin, NULL);

		listaClientes[contClientes] = aux;
		contClientes++;
	}while(op==1);

  salvarArqClientes();
}

void listarClientes() {
  int i;
  for(i = 0; i < contClientes; i++) {
    printf("Nome: %s\n", listaClientes[i].nome);
    printf("Codigo: %s\n", listaClientes[i].codigo);
    printf("CEP: %s\n", listaClientes[i].cep);
    printf("CPF: %s\n", listaClientes[i].cpf);
    printf("\n");
  }
}
void pesquisarClientes(){
  	cliente aux;
  	char cpfPesquisa[100];
  	char cepPesquisa[100];
  	int op;
  	int i;
	  do{
		  printf("Digite 1 para pesquisar por cpf ou 2 para pesquisar por cep");
		  scanf("%d", &op);
		  switch(op){
			  case 1:
			  	printf("Digite o cpf: ");
			  	scanf("%s", cpfPesquisa);
			  	for(i=0; i<SIZE; i++){
					  if(strcmp(listaClientes[i].cpf, cpfPesquisa) == 0){
						  printf("\nNome: %s\nCep: %s\nCpf: %s", listaClientes[i].nome, listaClientes[i].cep, listaClientes[i].cpf);
					  }
				  }
			  	break;
			  case 2:
			  	printf("\nDigite o cep: ");
			  	scanf("%s", cepPesquisa);
			  	for(i=0; i<SIZE; i++){
					  if(strcmp(listaClientes[i].cep, cepPesquisa) == 0){
						  printf("\nNome: %s\nCep: %s\nCpf: %s", listaClientes[i].nome, listaClientes[i].cep, listaClientes[i].cpf);
						  
						  }
				  }
				  	break;
			  default:
				printf("\nOpcao inválida");
			  	break;
		  }
		  		printf("\nDigite 1 para continuar pesquisando");
		  	 	 scanf("%d", &op);
	  }while(op==1);
  }
void excluirCliente(){
 int i;
 char cod[100];
  printf("Digite o codigo: ");
  scanf("%s", cod);
  
  bool naoencontrou=true;
  for(i = 0; i < contClientes; i++){
    if(strcmp(cod, listaClientes[i].codigo) == 0){
      naoencontrou=false;
      cliente aux = listaClientes[i];
      listaClientes[i] = listaClientes[contClientes];
      contClientes--;
     printf("Apagado com sucesso.");
     return;
    }
  }
  if(naoencontrou){
    printf("codigo invalido");
  }

}

void alterarCliente(){
  int i;
  char cod[100];
  printf("Digite o codigo: ");
   scanf("%s", cod);
  bool naoencontrou=true;
  for(i = 0; i < contClientes; i++){
    if(strcmp(cod, listaClientes[i].codigo) == 0){
      naoencontrou=false;
      printf("Digite o nome : ");
      scanf("%s", listaClientes[i].nome);
      printf("Digite o cep : ");
      scanf("%s", listaClientes[i].cep);
      return;
    }
  }
  if(naoencontrou){
      printf("codigo invalido");
    }
}

bool validarCliente(char* cpf) {
  int i;
  for(i = 0; i < contClientes; i++) {
    if (strcmp(listaClientes[i].cpf, cpf) == 0) {
      return true;
    }
  }

  return false;
}

void salvarArqClientes() {
  FILE *arq;
  if (arq = fopen("clientes.txt", "w")) {
    int i;
    for(i = 0; i < contClientes; i++) {
      fprintf(arq, "%s\n", listaClientes[i].codigo);
      fprintf(arq, "%s\n", listaClientes[i].cpf);
      fprintf(arq, "%s\n", listaClientes[i].nome);
      fprintf(arq, "%s\n", listaClientes[i].cep);
      fprintf(arq, "\n");
    }
  }
}