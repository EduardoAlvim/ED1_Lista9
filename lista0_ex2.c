#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Fa�a um programa que cadastre funcion�rios. Para cada funcion�rio devem
ser cadastrados nome e sal�rio. Os dados devem ser armazenados em uma lista
duplamente encadeada. Posteriormente, crie fun��es para mostrar:
� o nome do funcion�rio que tem o maior sal�rio (em caso de empate mostrar
todos);
� a m�dia salarial de todos os funcion�rios juntos;
� a quantidade de funcion�rios com sal�rio superior a um valor fornecido pelo
usu�rio. Caso nenhum funcion�rio satisfa�a essa condi��o, mostrar
mensagem. */

typedef struct no
{
    char nome[30];
    float salario;
    struct no *prox;
    struct no *ant;
} noptr;

void insere_lista(noptr **inicio, noptr *novo, char n[], float s)
{
    novo->salario=s;
    strcpy(novo->nome,n);
    novo->ant=NULL;
    if(*inicio==NULL)
        novo->prox = NULL;
    else
    {
        novo->prox=*inicio;
        (*inicio)->ant=novo;
    }
    *inicio=novo;
}

void maior_sal(noptr *inicio)
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    float maior=0;
    while(p)
    {
        if(maior < p->salario)
        {
            maior = p->salario;
        }
        p = p->prox;
    }
    p=inicio;
    while(p)
    {
        if(maior == p->salario)
        {
            puts(p->nome);
        }
        p = p->prox;
    }
    printf("\n");
}

void media(noptr *inicio)
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    float m, acm=0;
    int cont=0;
    while(p)
    {
        acm=acm+p->salario;
        cont++;
        p = p->prox;
    }
    m=acm/(float)cont;
    printf("\nMedia: %.2f",m);
}

void quant_sup(noptr *inicio, float s)
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    int cont=0;
    while(p)
    {
        if(p->salario > s)
        {
            cont++;
        }
        p = p->prox;
    }
    if(cont > 0)
    {
        printf("\nQuantidade de salario maiores que %.2f: %d",s,cont);
    }
    else
    {
        printf("\nNao existe salario maior que %.2f",s);
    }
}

void main()
{
    noptr *inicio;
    int resp=-1;
    inicio=NULL;
    noptr *info;
    float sal;
    char nome[30];
    do
    {
        printf("\n Menu\n1 Inserir funcionario; \n2 Mostrar o nome do funcion�rio que tem o maior sal�rio; \n3 Mostrar a media salarial de todos os funcion�rios juntos\n4 Mostrar a quantidade de funcion�rios com sal�rio superior a um valor;\n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite seu nome: ");
            fflush(stdin);
            gets(nome);
            fflush(stdin);
            printf("\nDigite seu salario: ");
            scanf("%f",&sal);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(&inicio,info,nome,sal);
        }
        else if(resp == 2)
        {
            maior_sal(inicio);
        }
        else if(resp == 3)
        {
            media(inicio);
        }
        else if(resp == 4)
        {
            printf("\nDigite um valor de salario: ");
            scanf("%f",&sal);
            quant_sup(inicio,sal);
        }
        else if(resp == 0)
        {
            printf("\nSaindo");
        }
        else
        {
            printf("\nComando invalido");
        }
    }
    while(resp!=0);
}
