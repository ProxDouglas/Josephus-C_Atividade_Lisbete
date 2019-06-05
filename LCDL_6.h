/*
  Arquivo: LCDL_6.c
  Autores:
  		Lucas Stefenoni de Aquino Pereira
  		Gabriel Ferreira
  		Douglas Cavalcanti Teles dos Santos
  		Vinicius Oliveira Souza
  Date: 6/06/2019 10:30
  Descrição: Implementação de Lista Circular Duplamente Ligada
*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

typedef struct Celula{
	int item;
	struct Celula *seguinte;
	struct Celula *anterior;
}Celula;

typedef Celula *Lista;


//Interface
Lista criarListaVazia(); 	 			//Cria uma Lista Vazia
bool verificarVazia(Lista); 			//Devolve TRUE se a lista é vazia.
void mostrarLista(Lista);   			//Mostra os elementos da lista no sentido horário
Lista inserir(Lista, int); 				//Acrescenta o item no inicio da Lista
Lista inserirFimLista(Lista, int); 		//Acrescenta o item no fim da lista
Lista remover (Lista, Celula*); 		//Remove a célula referenciada
Lista esvaziar(Lista); 					//Remove todos os itens da lista
Lista permutacaoJosephus (Lista L, int n, int m); 

void mostrarListaDoFim(Lista);


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

void mostrarLista(Lista L){	// a partir do primeiro
    Lista apont;
    int k;
    printf("\nLista: ");
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


Lista inserir(Lista L, int x){
	Celula *celula, *ultmcelula;
	celula = (Celula*) malloc(sizeof(Celula));
	celula->item = x;
	if(L == NULL){
		celula->anterior = celula;
	}else{
		
		ultmcelula = L->anterior;
		ultmcelula->seguinte = celula;
		celula->anterior = ultmcelula;
		L->anterior = celula;
	}
	
	if(L != NULL){
		celula->seguinte = L;
	}
	else{
		celula->seguinte = celula;
	}
	
	L = celula;
	return L;
}



Lista inserirFimLista(Lista L, int x){
	Celula* celula, *ultmcelula;
	celula = (Celula*) malloc(sizeof(Celula));
	celula->item = x;
	if(L == NULL){
		celula->anterior = celula;
		celula->seguinte = celula;
		L = celula;
	}
	else{
		ultmcelula = L->anterior;
		ultmcelula->seguinte = celula;
		celula->anterior = L->anterior;
		celula->seguinte = L;
		L->anterior = celula;
	}
	return L;
}

Lista remover (Lista L, Celula* eliminado){
	Celula *ant, *prox;
	
	if( L != L->seguinte){ //eliminado->seguinte != NULL &&
		prox = eliminado->seguinte;
		ant = eliminado->anterior;
	
		ant->seguinte = prox;
		prox->anterior = ant;
	
		if(eliminado == L){
			L = prox;
		}
		
		
	}else{
		L = NULL;
	}
	
	eliminado->seguinte = NULL;
	eliminado->anterior = NULL;
	eliminado = NULL;
	
	free(eliminado);
	
	return L;
}


Lista esvaziar(Lista L){
	Celula *celula, *ultm;
	if(L != NULL && L->seguinte !=NULL){
		celula = L->anterior;
		L->anterior = NULL;
		do{
			ultm = celula;
			celula = celula->anterior;
			celula->seguinte == NULL;
			ultm->seguinte = NULL;
			ultm->anterior = NULL;
			ultm = NULL;
			free(ultm);
				
		}while(celula != L);	
		L = NULL;
		free(L);
	}
	else if(L != NULL && L->seguinte == NULL){
		L = NULL;
		free(L);
	}
	return L;
}


Lista permutacaoJosephus (Lista L, int n, int m){
//Mostra na tela a permutação de Josephus, em que n= número de pessoas no circulo e m = passo da morte
	Celula* ponteiro, *eliminado;
	int i;
	ponteiro = L;
	printf("\nSequencia de exclusao: ");
	while(!verificarVazia(L)){
		eliminado = ponteiro;
		for(i=1; i<m; i++){
			eliminado = eliminado->seguinte;
		}
		ponteiro = eliminado->seguinte;
		printf(" %i ", eliminado->item);
		L = remover(L, eliminado);
	}
	if(verificarVazia(L)){
		printf("\n\nSobrevivente = %d \n", eliminado->item);
	}
	return L;
}


void mostrarListaDoFim(Lista L){	// a partir do primeiro
    Lista apont;
    int k;
    printf("\nLista: \n");
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


