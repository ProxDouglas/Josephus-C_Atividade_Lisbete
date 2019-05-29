/*
  Arquivo: LCDL_X.c
  Autores:
  		Lucas Pereira
  		Gabriel Ferreira
  		Douglas Santos
  Date: 6/06/2019 10:30
  Descrição: Implementação de Lista Circular Duplamente Ligada
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "Booleano.h"

typedef struct Celula{
	int item;
	struct Celula *seguinte;
	struct Celula *anterior;
}Celula;

typedef Celula *Lista;

//Interface
Lista criarListaVazia();    			//Cria uma Lista Vazia
bool verificarVazia(Lista); 			//Devolve TRUE se a lista é vazia.
void mostrarLista(Lista);   			//Mostra os elementos da lista no sentido horário
Lista inserir(Lista, int); 				//Acrescenta o item no inicio da Lista
Lista InserirFimLista(Lista, int); 		//Acrescenta o item no fim da lista
Lista remover (Lista, Celula*); 		//Remove a célula referenciada
Lista esvaziar(Lista); 					//Remove todos os itens da lista
void mostrarLista(Lista);


Lista criarListaVazia(){
	
	Lista L;
	L = NULL;
	return L;
	
	
}

bool verificarVazia(Lista L) {
	bool verif = false;
	
	if (L == NULL){
		verif = true;
	}

return verif;	

}

Lista inserir(Lista L, int x){
	Celula *celula, *prox, *ult, *aux;
	
	celula = (Celula*) malloc(sizeof(Celula));
	prox = (Celula*) malloc(sizeof(Celula));
	ult = (Celula*) malloc(sizeof(Celula));
	aux = (Celula*) malloc(sizeof(Celula));
	
	celula->item = x;
	
	if(L == NULL){
		celula->seguinte = L;
		celula->anterior = L;
		L = celula;
	}
	else{
		ult = L;
		aux = ult;
		do(ult->seguinte != L){
			aux = ult;
			ult = ult->seguinte;
		}
		prox = L;
		prox->anterior = celula;
		celula->seguinte = prox;
    	ult->seguinte = L;
		celula->anterior = aux;
		L = celula;
	}
	return L;
}

Lista InserirFimLista(Lista L, int x){
	Celula* celula, *prox, *ult, *aux;
	celula = (Celula*) malloc(sizeof(Celula));
	celula->item = x;
	
	if(L == NULL){
		L = celula;
		celula->seguinte = L;
		celula->anterior = L;
	}
	else{
		ult = L;
		while(ult->seguinte != L){
			aux = ult;
			ult = ult->seguinte;
		}
		celula->seguinte = L;
		aux->seguinte = celula;
		celula->anterior = aux;
	}
	return L;
}

Lista esvaziar(Lista L){
	Celula *celula, *ant;
	
	if(L != NULL){
		celula = L;
		do{
			ant = celula;
			celula = celula->seguinte;
			free(ant);
		}while(celula->seguinte != NULL);
		L = NULL;
	}
	return L;
}


void mostrarLista(Lista p){		// a partir do primeiro
    Lista apont;
    int k;
    if (p == NULL) printf("lista vazia \n");
    else { 
     	//printf("\n lista = ");
        apont = p; 
        do {
            k = apont->item;  printf(" %d ", k);
            apont = apont->seguinte;
            //printf("\n apont = %d  p = %d ",apont, p);
        }
        while (apont != p);
    }
    printf("\n");
}
