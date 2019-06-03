/*
  Arquivo: LucasPereira_Josephus.c
  Autores:
  		Lucas Pereira
  		Gabriel Ferreira
  		Douglas Cavalcanti Teles dos Santos
  Date: 6/06/2019 10:30
  Descri��o: Programa para simula��o do problema de Josephus
*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#include "LCDL_6.h"

//Interface
void permutacaoJosephus (Lista, int, int);
/* FUN��ES DO HEADER
Lista criarListaVazia();    					//Cria uma Lista Vazia
bool verificarVazia(Lista); 					//Devolve TRUE se a lista � vazia.
void mostrarLista(Lista);   					//Mostra os elementos da lista no sentido hor�rio
Lista inserir(Lista, int); 						//Acrescenta o item no inicio da Lista
Lista InserirFimLista(Lista, int); 				//Acrescenta o item no fim da lista
Lista remover (Lista, Celula*); 				//Remove a c�lula referenciada
Lista esvaziar(Lista); 							//Remove todos os itens da lista
void permutacaoJosephus (Lista , int , int ); //Permuta��o de Josephus 
*/

void main(){
Lista L;
int n = 10;
L = criarListaN(L, n);	
mostrarLista(L);
}


