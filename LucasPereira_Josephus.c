/*
  Arquivo: LucasPereira_Josephus.c
  Autores:
  		Lucas Pereira
  		Gabriel Ferreira
  		Douglas Santos
  Date: 6/06/2019 10:30
  Descri��o: Programa para simula��o do problema de Josephus
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "Booleano.h"
#include "LCDL_X.h"

//Interface
void permutacaoJosephus (Lista, int, int);
/* FUN��ES DO HEADER
Lista criarListaVazia();    			//Cria uma Lista Vazia
bool verificarVazia(Lista); 			//Devolve TRUE se a lista � vazia.
void mostrarLista(Lista);   			//Mostra os elementos da lista no sentido hor�rio
Lista inserir(Lista, int); 				//Acrescenta o item no inicio da Lista
Lista InserirFimLista(Lista, int); 		//Acrescenta o item no fim da lista
Lista remover (Lista, Celula*); 		//Remove a c�lula referenciada
Lista esvaziar(Lista); 					//Remove todos os itens da lista
*/

void main(){

Lista L;
L = criarListaVazia();
bool verif = verificarVazia(L);

mostrarLista(L);

L = inserir(L, 1);
L = inserir(L, 5);
L = inserir(L, 10);

mostrarLista(L);
	
	
}

void permutacaoJosephus (Lista L, int n, int m){
//Mostra na tela a permuta��o de Josephus, em que n= n�mero de pessoas no circulo e m = passo da morte

	
	
	
	
	
	
}
