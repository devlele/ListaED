// Alefe Freitas Santos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char ra[14];
    char codDisciplina[6];
    float nota;
    int qtdFaltas;
    struct aluno* prox;
}