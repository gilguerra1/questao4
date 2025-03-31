#include <stdio.h>
#include <stdlib.h>
#include <iostream>


typedef struct No{
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if( valor < raiz->valor){
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    }
    else if(valor > raiz->valor){
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
    printf("%d ", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
    emOrdem(raiz->esquerda);
    printf("%d ",raiz->valor);
    emOrdem(raiz->direita);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->valor);
    }
}

int main(){
    No* raiz = NULL;
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 20);
    
    std::cout << "Arvore pre ordem: ";
    preOrdem(raiz);
    std::cout << std::endl;

    std::cout << "Arvore em ordem: ";
    emOrdem(raiz);
    std::cout << std::endl;

    std::cout << "Arvore pos ordem: ";
    posOrdem(raiz);
    std::cout << std::endl;

return 0;
}