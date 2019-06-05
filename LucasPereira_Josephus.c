/*
  Arquivo: LucasPereira_Josephus.c
  Autores:
  		Lucas Stefenoni de Aquino Pereira
  		Gabriel Ferreira
  		Douglas Cavalcanti Teles dos Santos
  		Vinicius Oliveira Souza
  Date: 6/06/2019 10:30
  Descrição: Programa para simulação do problema de Josephus
*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#include "LCDL_6.h"


Lista criarListaN(Lista, int );


//Interface
//void permutacaoJosephus (Lista, int, int);
/* FUNÇÕES DO HEADER
Lista criarListaVazia();    			//Cria uma Lista Vazia
bool verificarVazia(Lista); 			//Devolve TRUE se a lista é vazia.
void mostrarLista(Lista);   			//Mostra os elementos da lista no sentido horário
Lista inserir(Lista, int); 				//Acrescenta o item no inicio da Lista
Lista InserirFimLista(Lista, int); 		//Acrescenta o item no fim da lista
Lista remover (Lista, Celula*); 		//Remove a célula referenciada
Lista esvaziar(Lista); 					//Remove todos os itens da lista
*/

void main(){

Lista L;
int n = 0, m = 0;
n = 7;
m = 3;
L = criarListaN(L, n);
mostrarLista(L);

L = permutacaoJosephus (L, n, m);
//L = esvaziar(L);
	
//mostrarLista(L);
}


Lista criarListaN(Lista L, int n){
	int i;
	L = criarListaVazia();
	for (i=1;i<=n;i++){
		L = inserirFimLista(L, i);	
	}
return L;	
}


