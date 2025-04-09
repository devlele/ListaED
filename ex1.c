// Alefe Freitas Santos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MEMORY_ERROR 2
#define EXEC_SUCCESS 0

typedef struct aluno {
    char ra[14];
    char codDisciplina[6];
    float nota;
    int qtdFaltas;
    struct aluno *prox;
} Aluno;

int main(void) {
    Aluno *inicio = NULL, *aux = NULL, *ant = NULL;

    char ra[14];
    char codDisciplina[6];
    float nota;
    int qtdFaltas;

    while (1) {
        printf("Informe o RA (XXX para parar):\n");
        scanf("%s", ra);

        if (strcmp(ra, "XXX") == 0) {
            break;
        }

        printf("Informe a disciplina (max 5 caracteres):\n");
        scanf("%s", codDisciplina);

        printf("Informe a nota do aluno:\n");
        scanf("%f", &nota);

        printf("Informe a quantidade de faltas:\n");
        scanf("%d", &qtdFaltas);

       
        aux = (Aluno *) malloc(sizeof(Aluno));

        strcpy(aux->ra, ra);
        strcpy(aux->codDisciplina, codDisciplina);
        aux->nota = nota;
        aux->qtdFaltas = qtdFaltas;
        aux->prox = NULL;

    
        if (inicio == NULL) {
            inicio = aux; 
        } else {
            ant->prox = aux; 
        }

        ant = aux; 
    }
}

