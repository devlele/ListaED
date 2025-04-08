// Maria Eduarda Rodrigues Simões e Rafaela Yumi Shimoda

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MEMORY_ERROR 1
#define EXEC_SUCCESS 0

// Estrutura dos dados do aluno
struct listaDadosAluno {
    char ra[14];        
    char disciplina[6];   
    float nota;           
    int faltas;            
    struct listaDadosAluno *prox; // Ponteiro para o próximo nó
};

typedef struct listaDadosAluno Dados;

// Estrutura da lista encadeada
typedef struct 
{
    Dados *inicio;
    Dados *final;
    int qtde;
} ListDados;

// Funções
void ImprimeLista(ListDados *lista, char *cabec);
void InicializaLista(ListDados *lista);
int IncluiAluno(ListDados *lista, char *ra, char *disciplina, float nota, int faltas);
int ExcluiPorDisciplina(ListDados *lista, char *disciplina);
void LeDadosAluno(char *ra, char *disciplina, float *nota, int *faltas);

int main(void) {
    ListDados lista;
    char ra[14], disciplina[6];
    float nota;
    int faltas;

    InicializaLista(&lista);

    // Inserção de alunos na lista
    while (TRUE) {
        printf("Informe o RA ou XXX para parar: \n");
        scanf("%s", ra);
        if (strcmp(ra, "XXX") == 0 || strcmp(ra, "xxx") == 0)  
            break;

        LeDadosAluno(ra, disciplina, &nota, &faltas);

        if (IncluiAluno(&lista, ra, disciplina, nota, faltas) == FALSE) 
		{
            puts("Memória insuficiente para continuar ...");
            return MEMORY_ERROR;
        }
    }

    ImprimeLista(&lista, "Conteúdo da lista");

    // Exclusão de alunos da lista pela disciplina
    while (TRUE) {
        printf("Informe a sigla da disciplina a excluir (ou 'XXX' para parar):\n");
        scanf("%s", disciplina);
        if (strcmp(disciplina, "XXX") == 0 || strcmp(disciplina, "xxx") == 0)
            break;

        if (ExcluiPorDisciplina(&lista, disciplina) == FALSE)
            puts("\nDisciplina não encontrada na lista\n");
        else
            ImprimeLista(&lista, "Novo conteúdo da lista");
    }

    return EXEC_SUCCESS;
}

// Função para incluir um aluno na lista
int IncluiAluno(ListDados *lista, char *ra, char *disciplina, float nota, int faltas) 
{
    Dados *aux;

    // Aloca um novo nó para o aluno
    aux = (Dados *)malloc(sizeof(Dados));
    if (aux == NULL)
        return FALSE;

    // Preenche os dados do novo aluno
    strcpy(aux->ra, ra);
    strcpy(aux->disciplina, disciplina);
    aux->nota = nota;
    aux->faltas = faltas;
    aux->prox = NULL;

    // Encadeia o aluno na lista
    if (lista->inicio == NULL)
        lista->inicio = aux;
    else
        lista->final->prox = aux;

    lista->final = aux;
    lista->qtde++;

    return TRUE;
}

// Função para excluir alunos por disciplina
int ExcluiPorDisciplina(ListDados *lista, char *disciplina) 
{
    Dados *aux, *ant;

    aux = lista->inicio;
    ant = NULL;
    int removed = 0;

    while (aux != NULL) {
        if (strcmp(aux->disciplina, disciplina) == 0) 
		{  // Encontra a disciplina
            // Desvincula o nó
            if (ant == NULL)
                lista->inicio = aux->prox;
            else
                ant->prox = aux->prox;

            free(aux);
            lista->qtde--;
            removed = 1;
            if (lista->final == aux)
                lista->final = ant;

            aux = (ant == NULL) ? lista->inicio : ant->prox;  // Atualiza o ponteiro para o próximo
        } else {
            ant = aux;
            aux = aux->prox;
        }
    }

    return removed;  // Retorna 1 se algum aluno foi removido, 0 caso contrário ????????????????????????????????
}

// Função para imprimir os dados da lista
void ImprimeLista(ListDados *lista, char *cabec) 
{
    Dados *aux;

    if (lista->inicio == NULL)
        printf("\n\n\nLista vazia\n");
    else {
        printf("\n\n\n%s:\n", cabec);

        aux = lista->inicio;
        while (aux != NULL) {
            printf("RA: %s\n", aux->ra);
            printf("Disciplina: %s\n", aux->disciplina);
            printf("Nota: %.2f\n", aux->nota);
            printf("Faltas: %d\n", aux->faltas);
            printf("-------------------------\n");

            aux = aux->prox;
        }
    }
}

// Função para inicializar a lista
void InicializaLista(ListDados *lista) 
{
    lista->inicio = NULL;
    lista->final = NULL;
    lista->qtde = 0;
}

// Função para ler os dados do aluno
void LeDadosAluno(char *ra, char *disciplina, float *nota, int *faltas) 
{
    printf("Informe a disciplina (máximo 5 caracteres): ");
    scanf("%s", disciplina);
    printf("Informe a nota (0 a 10): ");
    scanf("%f", nota);
    printf("Informe a quantidade de faltas: ");
    scanf("%d", faltas);
}