#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que cadastre alunos. Para cada aluno devem ser cadastrados nome e nota  final.
Os  dados  devem  ser  armazenados  em  uma  lista duplamente  encadeada  e  ordenada.
Em  seguida,  crie  uma  função  que  envie  para  o programa  principal  apenas  o  nome  dos  alunos  aprovados, ou  seja,
alunos  com  nota final  de  no  mínimo  7.
Mostre  o  resultado,  se  nenhum  aluno  estiver  aprovado, mostrar mensagem. */

typedef struct Dados{
    char nome[30];
    float nota;
} dados;

typedef struct no
{
    char nome[30];
    float nota;
    struct no *prox;
    struct no *ant;
} noptr;

void insere_lista(noptr **inicio, noptr *novo, dados d)
{
    novo->nota=d.nota;
    strcpy(novo->nome,d.nome);
    novo->ant=NULL;
    noptr *l;
    if(*inicio==NULL){
        novo->prox = NULL;
        *inicio=novo;
    }
    else
    {
        l=*inicio;
        while(l->nota <= novo->nota && l->prox != NULL)
        {
            l=l->prox;
        }
        if(l->nota <= novo->nota && l->prox ==  NULL)
        {
            novo->prox=NULL;
            novo->ant = l;
            l->prox=novo;
        }
        else if((*inicio)->nota == l->nota)
        {
            novo->prox=*inicio;
            *inicio=novo;
        }
        else if(l->nota >= novo->nota && l->nota >= (*inicio)->nota)
        {
            l->ant->prox=novo;
            novo->prox=l;
        }
    }
}

void listar_aprovados(noptr *inicio)
{
    int cont=0;
    noptr *p;
    p=inicio;
    while(p)
    {
        if(p->nota >= 7.0)
        {
            printf("\n%s",p->nome);
            cont++;
        }
        p=p->prox;
    }
    if(cont == 0)
    {
        printf("\nNenhum aluno passou");
    }
}

void main()
{
    noptr *inicio;
    dados d;
    inicio=NULL;
    noptr *info;
    float nota=0;
    char nome[30];
    do
    {
        printf("\nDigite a nota: ");
        scanf("%f",&d.nota);
        if(d.nota > 0)
        {
            printf("\nDigite seu nome: ");
            fflush(stdin);
            gets(d.nome);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(&inicio,info,d);
        }
    }
    while(d.nota > 0);
    printf("\nAlunos que passaram: ");
    listar_aprovados(inicio);
}
