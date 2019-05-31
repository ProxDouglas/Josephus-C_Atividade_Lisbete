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
//#include <stdbool.h>
#include "Booleano.h"

typedef struct Celula{
	int item;
	struct Celula *seguinte;
	struct Celula *anterior;
}Celula;

typedef Celula *Lista;

/*typedef struct Celula{
	int item;
	struct Celula *inicio;
	struct Celula *fim;
}Lista;*/

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
	bool verif = FALSE;
	if (L == NULL)verif = TRUE;
return verif;	
}


Lista inserir(Lista L, int x){
	Celula *celula, *ultmcelula;
	celula = (Celula*) malloc(sizeof(Celula));
	celula->item = x;
	if(L == NULL){
		celula->anterior = NULL;
	}else{
		
		ultmcelula = L->anterior;
		if(ultmcelula == NULL){
			L->seguinte = celula;
			L->anterior = celula;
			celula->anterior = L;	
		}
		else{
			ultmcelula->seguinte = celula;
			celula->anterior = ultmcelula;
			L->anterior = celula;
		}
	}
	
	celula->seguinte = L;
	L = celula;
	return L;
}


Lista InserirFimLista(Lista L, int x){
	Celula* celula, *ultmcelula;
	celula = (Celula*) malloc(sizeof(Celula));
	celula->item = x;
	if(L == NULL){
		celula->anterior = NULL;
		celula->seguinte = L;
		L = celula;
	}
	else{
		if(L->anterior == NULL){
			celula->anterior = L;
			L->seguinte = celula;
		}
		else {
			ultmcelula = L->anterior;
			ultmcelula->seguinte = celula;
			celula->anterior = L->anterior;
		}
		celula->seguinte = L;
		L->anterior = celula;
	}
	return L;
}


Lista esvaziar(Lista L){
	Celula *celula, *ultm;
	
	if(L != NULL){
		celula = L->anterior;
		do{
			//ultm = celula;
			celula = celula->anterior;
			
			//celula->seguinte == NULL;
			//ultm = NULL;
			//free(ultm);
				
		}while(celula !=L);
		
		//celula = NULL;
		//free(celula);
	}
	
	
	
	return L;
}

/*Lista esvaziar(Lista L){
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
}*/


void mostrarLista(Lista L){	// a partir do primeiro
    Lista apont;
    int k;
    if (L == NULL) printf("lista vazia \n");
    else { 
     	//printf("\n lista = ");
        apont = L; 
        do {
            k = apont->item;  printf(" %d ", k);
            apont = apont->seguinte;
            //printf("\n apont = %d  p = %d ",apont, p);
        }
        while (apont != L);
    }
    printf("\n");
}

void mostrarListaDoFim(Lista L){	// a partir do primeiro
    Lista apont;
    int k;
    printf("\n");
    if (L == NULL) printf("lista vazia \n");
    else { 
     	//printf("\n lista = ");
        apont = L;
		apont = apont->anterior; 
        do {
            k = apont->item;  printf(" %d ", k);
            apont = apont->anterior;
            //printf("\n apont = %d  p = %d ",apont, p);
        }
        while (apont != L->anterior);
    }
    printf("\n");
}
