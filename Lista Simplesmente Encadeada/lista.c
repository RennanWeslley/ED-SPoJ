#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int criaLista(tLista *lista) {
    lista->cabeca = NULL;
    lista->tam = 0;
}

int vazio(tLista lista) {
    return lista.tam == 0;
}

int tamanho(tLista lista) {
    return lista.tam;
}

int acessa(tLista lista, int pos, int *dado) {
    if(pos < 1 || pos > lista.tam)
        return 0;
    
    tElemento *p = lista.cabeca;
    
    for(int i = 1; i < pos; p = p->prox, i++);
    
    *dado = p->dado;
    
    return 1;
}

int pesquisa(tLista lista, int dado) {
    if(vazio(lista))
        return -1;
    
    tElemento *p = lista.cabeca;
    
    for(int i = 1; p; p = p->prox, i++)
        if(p->dado == dado)
            return i;
    
    return 0;
}

int insereInicio(tLista *lista, int dado) {
    tElemento *p = (tElemento *) malloc(sizeof(tElemento));
    if(!p)
        return -1;
    
    p->dado = dado;
    p->prox = lista->cabeca;
    lista->cabeca = p;
    lista->tam++;
    
    return 1;
}

int insereIndx(tLista *lista, int pos, int dado) {
    if(pos < 1 || pos > lista->tam)
        return 0;
    
    tElemento *p = lista->cabeca;
    
    for(int i = 1; i < (pos-1); p = p->prox, i++);
    
    tElemento *new = (tElemento *) malloc(sizeof(tElemento));
    if(!new)
        return -1;
    
    new->dado = dado;
    new->prox = p->prox;
    p->prox = new;
    lista->tam++;
    
    return 1;
}

int insere(tLista *lista, int dado) {
    int ret;
    
    if(vazio(*lista)) {
    	ret = insereInicio(lista, dado);
    	return ret;
    }
    
    tElemento *p = lista->cabeca;
    
    for(; p->prox; p = p->prox);
    
    tElemento *new = (tElemento *) malloc(sizeof(tElemento));
    if(!new)
        return -1;
    
    new->dado = dado;
    p->prox = new;
    lista->tam++;
    
    return 1;
}

int excluiInicio(tLista *lista) {
    if(vazio(*lista))
        return 0;
    
    tElemento *p = lista->cabeca;
    lista->cabeca = lista->cabeca->prox;
    free(p);
    lista->tam--;
    
    return 1;
}

int excluiIndx(tLista *lista, int pos) {
    if(pos < 2 || pos > lista->tam)
        return 0;
    
    tElemento *p = lista->cabeca;
    tElemento *aux;
    
    for(int i = 1; i < (pos-1); p = p->prox, i++);
    
    aux = p->prox;
    p->prox = aux->prox;
    free(aux);
    lista->tam--;
    
    return 1;
}

int exclui(tLista *lista, int pos) {
    int ret;
    
    if(pos == 1)
        ret = excluiInicio(lista);
    else
        ret = excluiIndx(lista, pos);
    
    return ret;
}

int exibe(tLista lista) {
    if(vazio(lista)) 
        return 0;
    
    printf("Lista: {");
    for(tElemento *p = lista.cabeca; p; p = p->prox)
    	if(!p->prox)
    		printf("%d}", p->dado);
		else
        	printf("%d, ", p->dado);
    
    return 1;
}
