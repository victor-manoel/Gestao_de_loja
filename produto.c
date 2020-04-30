#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "produto.h"
#define SIZE 200 //define uma variável constante

produto listaProduto[100];
int contProdutos = 0;

void cadastroProdutos(){
	produto aux;
  setbuf(stdin, NULL);
  printf("\nDigite o nome do produto: ");
  scanf("%s", aux.nome);
  setbuf(stdin, NULL);
  printf("\nDigite o valor: ");
  scanf("%s", aux.valor);
  setbuf(stdin, NULL);
  printf("\nDigite a quantidade de produtos no estoque: ");
  scanf("%s", aux.qtdE);
  setbuf(stdin, NULL);
  printf("\nDigite o codigo do produto: ");
  scanf("%s", aux.codigo);
  setbuf(stdin, NULL);

  listaProduto[contProdutos] = aux;
  contProdutos++;
}

void listarProdutos() {
  int i;
  for(i = 0; i < contProdutos; i++) {
    printf("Nome: %s\n", listaProduto[i].nome);
    printf("valor: %s\n", listaProduto[i].valor);
    printf("quantidade: %s\n", listaProduto[i].qtdE);
    printf("codigo: %s\n", listaProduto[i].codigo);
    printf("\n");
  }
}
void pesquisarProdutos(){
  	produto aux;
  	char codigoPesquisa[100];
    char nomePesquisa[100];
  	char Pesquisa[100];
  	int op;
  	int i;
	  do{
		  printf("Digite 1 para pesquisar por codigo ou 2 para pesquisar por nome");
		  scanf("%d", &op);
		  switch(op){
			  case 1:
			  	printf("Digite o codigo: ");
			  	scanf("%s", codigoPesquisa);
			  	for(i=0; i<SIZE; i++){
					  if(strcmp(listaProduto[i].codigo, codigoPesquisa) == 0){
						  printf("\nNome: %s\nValor: %s\nQuantidade: %s\nCodigo : %s", listaProduto[i].nome, listaProduto[i].valor, listaProduto[i].qtdE, listaProduto[i].codigo);
					  }
				  }
			  	break;
			  case 2:
			  	printf("\nDigite o nome: ");
			  	scanf("%s", nomePesquisa);
			  	for(i=0; i<SIZE; i++){
					  if(strcmp(listaProduto[i].nome, nomePesquisa) == 0){
						  printf("\nNome: %s\nCodigo: %s\nQuantidade: %s", listaProduto[i].nome, listaProduto[i].codigo, listaProduto[i].qtdE);
						  
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
void excluirProdutos(){
 int i, cod;
  printf("Digite o codigo: ");
  scanf("%d", &cod);
  
  bool naoencontrou=true;
  for(i = 0; i < contProdutos; i++){
    if(strcmp(cod, listaProduto[i].codigo) == 0){
      naoencontrou=false;
      produto aux = listaProduto[i];
      listaProduto[i] = listaProduto[contProdutos];
      contProdutos--;
     printf("Apagado com sucesso.");
     return;
    }
  }
  if(naoencontrou){
    printf("codigo invalido");
  }

}

void alterarProdutos(){
  int i;
  char cod[100];
  printf("Digite o codigo: ");
   scanf("%s", cod);
  bool naoencontrou=true;
  for(i = 0; i < contProdutos; i++){
    if(strcmp(cod, listaProduto[i].codigo) == 0){
      naoencontrou=false;
      printf("Digite o nome : ");
      scanf("%s", listaProduto[i].nome);
      printf("Digite o codigo : ");
      scanf("%s", listaProduto[i].codigo);
      return;
    }
  }
  if(naoencontrou){
      printf("codigo invalido");
    }
}

bool validarCodProduto(char* cod, char* qtdProd) {
  int i;
  for(i = 0; i < contProdutos; i++) {
    if (strcmp(listaProduto[i].codigo, cod) == 0 && strcmp(listaProduto[i].qtdE, qtdProd) <= 0) {
      return true;
    }
  }

  return false;
}

void estoque() {
  
   int i;
  for(i = 0; i < contProdutos; i++) {
    printf("\nNome: %s\n", listaProduto[i].nome);
    printf("quantidade: %s\n", listaProduto[i].qtdE);
    printf("codigo: %s\n", listaProduto[i].codigo);
    printf("\n");
  }

}
