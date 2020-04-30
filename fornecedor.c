#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "fornecedor.h"
#define SIZE 200 //defini uma variável constante

fornecedor listaFornecedores[100];
int contFornecedores = 0;

void cadastroFornecedores(){
	fornecedor aux;
	int op;
	do{
    setbuf(stdin, NULL);
		printf("\nDigite o nome do fornecedor: ");
		scanf("%s", aux.nome);
		setbuf(stdin, NULL);
		printf("\nDigite o cnpj do fornecedor: ");
		scanf("%s", aux.cnpj);
		setbuf(stdin, NULL);
		printf("\nDigite o endereco do cliente: ");
		scanf("%s", aux.endereco);
		setbuf(stdin, NULL);
		printf("\nDigite o qunatidade do fornecedor: ");
		scanf("%d", &aux.quantFornecedor);
		setbuf(stdin, NULL);

		listaFornecedores[contFornecedores] = aux;
		contFornecedores++;
	}while(op==1);
}

void listarFornecedores() {
  int i;
  for(i = 0; i < contFornecedores; i++) {
    printf("Nome: %s\n", listaFornecedores[i].nome);
    printf("CNPJ: %s\n", listaFornecedores[i].cnpj);
    printf("ENDERECO: %s\n", listaFornecedores[i].endereco);
    printf("Quantidade: %d\n", listaFornecedores[i].quantFornecedor);
    printf("\n");
  }
}
void pesquisarFornecedores(){
  	fornecedor aux;
  	char cnpjPesquisa[100];
  	int op;
  	int i;
	  do{
		  printf("Digite 1 para pesquisar por cpf ou 2 para pesquisar por cep");
		  scanf("%d", &op);
		  switch(op){
			  case 1:
			  	printf("Digite o cnpj: ");
			  	scanf("%s", cnpjPesquisa);
			  	for(i=0; i<SIZE; i++){
					  if(strcpy(listaFornecedores[i].cnpj, cnpjPesquisa)== 0 ){
						  printf("\nNome: %p\nCNPJ: %p\n", listaFornecedores[i].nome, listaFornecedores[i].cnpj);
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
void excluirFornecedores(){
 int i;
 char cnpj[100];
  printf("Digite o cnpj: ");
  scanf("%s", cnpj);
  
  bool naoencontrou=true;
  for(i = 0; i < contFornecedores; i++){
    if(strcmp(cnpj, listaFornecedores[i].cnpj) == 0){
      naoencontrou=false;
      fornecedor aux = listaFornecedores[i];
      listaFornecedores[i] = listaFornecedores[contFornecedores];
      contFornecedores--;
      printf("Apagado com sucesso.");
      return;
    }
  }
  if(naoencontrou){
    printf("codigo invalido");
  }

}

void alterarFornecedores(){
  int i;
  char cnpj[100];
  printf("Digite o CNPJ: ");
   scanf("%s", cnpj);
  bool naoencontrou=true;
  for(i = 0; i < contFornecedores; i++){
    if(strcmp(cnpj, listaFornecedores[i].cnpj) == 0){
      naoencontrou=false;
      printf("Digite o Nome : ");
      scanf("%s", listaFornecedores[i].nome);
      printf("Digite o CNPJ : ");
      scanf("%s", listaFornecedores[i].cnpj);
      return;
    }
  }
  if(naoencontrou){
      printf("codigo invalido");
    }
}