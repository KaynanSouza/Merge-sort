#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipos.h"

#define TAM 30

int menu() {
    int operacao = 0;

    printf("+====================+\n");
    printf("|     MERGE SORT     |\n");
    printf("+====================+\n");
    printf("| 1. Lista estatica  |\n");
    printf("| 2. Lista dinamica  |\n");
    printf("| 3. Sair            |\n");
    printf("+====================+\n");
    printf(" Digite a opera��o: ");
    scanf("%d", &operacao);

    return operacao;
}

// Fun��es para lista estatica
void printarVetor(int vetor[]) {
    printf("Seu vetor: \n");

    printf("[");
    for (int i = 0; i < TAM; ++i) {
        printf("%d", vetor[i]);

        if (i < TAM - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void preencherVetor(int vetor[]) {
    srand(time(NULL));
    for (int i = 0; i < TAM; ++i) {
        vetor[i] = rand() % 100;
    }
}

void listaEstatica() {
    int vetor[TAM];

    preencherVetor(vetor);
    printf("Vetor desordenado:\n");
    printarVetor(vetor);

    mergeSortEstatico(vetor, 0, TAM - 1);

    printf("Vetor ordenado:\n");
    printarVetor(vetor);
}

void mergeSortEstatico(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSortEstatico(vetor, inicio, meio);
        mergeSortEstatico(vetor, meio + 1, fim);
        mergeEstatico(vetor, inicio, meio, fim);
    }
}

void mergeEstatico(int vetor[], int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int esquerda[tamanhoEsquerda];
    int direita[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++) {
        esquerda[i] = vetor[inicio + i];
    }

    for (int j = 0; j < tamanhoDireita; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}
