#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;
using std::getline;

typedef struct reg {
	int conteudo;
	char prioridade;
	struct reg * prox;
} CELULA;

void imprimeLista (CELULA * primeiro);
void filaAdd(CELULA * primeiro, int numero);
CELULA * filaRemove(CELULA ** primeiroDaFila);
void filaRemoveDefinitivamente(CELULA ** primeiroDaFila);

int main() {
	CELULA * primeiroDaFila = (CELULA *) malloc(sizeof(CELULA));
	primeiroDaFila -> conteudo = 10;
	primeiroDaFila -> prox = NULL;
	filaAdd(primeiroDaFila,20);
	filaAdd(primeiroDaFila,30);
	filaAdd(primeiroDaFila,40);
	filaAdd(primeiroDaFila,50);
	CELULA * temp = filaRemove(&primeiroDaFila);
	filaRemoveDefinitivamente(&primeiroDaFila);
	imprimeLista(primeiroDaFila);
	cout << "\n" << temp -> conteudo;
}

void imprimeLista (CELULA * primeiro) {
	if (primeiro == NULL) {
		cout << "\n" << "Empty Queue\n";
	} else {
		while (primeiro != NULL) {
			cout << "\n" << primeiro -> conteudo;
			primeiro = primeiro -> prox;
		}
	}
	cout << "\n";
}

void filaAdd(CELULA * primeiro, int numero) {
	if (primeiro == NULL) {
		cout<<"\n"<<"Empty Queue\n";
		return;
	} else {
		while (primeiro -> prox != NULL) {
			primeiro = primeiro -> prox;
		}
	}
	primeiro -> prox = (CELULA *) malloc(sizeof(CELULA));
	primeiro -> prox -> conteudo = numero;
	primeiro -> prox -> prox = NULL;
}

CELULA * filaRemove(CELULA ** primeiroDaFila) {
	if (*primeiroDaFila == NULL) {
		cout<<"\n"<<"Empty Queue\n";
		return NULL;
	} else {
		CELULA * aux = *primeiroDaFila;
		*primeiroDaFila = aux -> prox;
		return aux;
	}
}

void filaRemoveDefinitivamente(CELULA ** primeiroDaFila) {
	if(*primeiroDaFila == NULL) {
		cout<<"\n"<<"Empty Queue\n";
		return;
	} else {
		CELULA * aux = *primeiroDaFila;
		*primeiroDaFila = aux -> prox;
		free(aux);
	}
}
