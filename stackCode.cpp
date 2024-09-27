#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::getline;

typedef struct reg {
    int conteudo;
    char prioridade;
    struct reg * prox;
} CELULA;

void pilhaPush(CELULA ** topo, int numero);
CELULA * pilhaPop(CELULA ** topo);
void pilhaPopDefinitivamente(CELULA ** topo);

int main(){
    CELULA * topo = (CELULA *) malloc(sizeof(CELULA));
    topo->conteudo = 10;
    topo->prox = NULL;
    pilhaPush(&topo, 20);
    pilhaPush(&topo, 30);
    pilhaPush(&topo, 40);
    pilhaPopDefinitivamente(&topo);
    CELULA * temp = pilhaPop(&topo);
    std::cout << "\n" << temp->conteudo;
    temp = pilhaPop(&topo);
    std::cout << "\n" << temp->conteudo << "\n";
    pilhaPush(&topo, 50);
    pilhaPush(&topo, 60);
    pilhaPush(&topo, 70);
    temp = pilhaPop(&topo);
    temp = pilhaPop(&topo);
    std::cout << "\n" << temp->conteudo << "\n";
}

// Stack Functions Here!!!

void pilhaPush(CELULA ** topo, int numero){
    if (*topo == NULL) {
        std::cout<<"\n"<<"LISTA VAZIA\n";
        return;
    } else {
        CELULA * aux = (CELULA *) malloc(sizeof(CELULA));
        aux->conteudo = numero;
        aux->prox = *topo;
        *topo = aux;
    }
}

CELULA * pilhaPop(CELULA ** topo){
    if (*topo == NULL) {
        std::cout<<"\n"<<"FILA VAZIA\n";
        return NULL;
    } else {
        //quer dizer que tem pelo menos 2 nós
        CELULA * aux = *topo;
        *topo = aux->prox;
        //free(aux);
        return aux;
    }
}

void pilhaPopDefinitivamente(CELULA ** topo){
    if (*topo == NULL) {
        std::cout<<"\n"<<"FILA VAZIA\n";
        return;
    } else {
        //quer dizer que tem pelo menos 2 nós
        CELULA * aux = *topo;
        *topo = aux->prox;
        free(aux);
    }
}