#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que cadastre produtos. Para cada produto devem ser
cadastrados código do produto, preço e quantidade estocada. Os dados devem ser
armazenados em uma lista duplamente encadeada e ordenada pelo código.
Posteriormente, crie uma função que envie uma taxa de desconto escolhida pelo
usuário (ex. Digitar 10 para taxa de desconto de 10%). Aplicar a taxa digitada ao
preco de todos os produtos cadastrados e finalmente mostrar um relatório com o
código e o novo preço. Em seguida, crie uma função que envie para o programa
principal o maior preço entre os produtos e o produto que tem a maior quantidade
estocada. */

struct no
{
    int codigo, quant;
    float preco;
    struct no *ant;
    struct no *prox;
};
typedef struct no noptr;

void insere_lista(noptr **inicio, noptr *novo, int c, int q, float p)
{
    novo->codigo=c;
    novo->quant=q;
    novo->preco=p;
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

void lista_todos(noptr *inicio)
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    while(p)
    {
        printf("\nCodigo: %d\nPreco: %.2f", p->codigo,p->preco);
        printf("\n");
        p = p->prox;
    }
    printf("\n");
}

void desconto(noptr **inicio, int desconto)
{
    float desc;
    if(*inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = *inicio;
    while(p)
    {
        desc=p->preco * ((float)desconto/100);
        p->preco=p->preco -  desc;
        p = p->prox;
    }
}

float retornaPreco(noptr *inicio)
{
    float maiorp=0;
    int maiorq=0;
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    while(p)
    {
        if(maiorp<=p->preco)
            maiorp=p->preco;
        if(maiorq<=p->quant)
            maiorq=p->quant;
        p = p->prox;
    }
    p = inicio;
    while(p)
    {
        if(maiorq == p->quant)
            printf("\nCodigo do produto com maior quantidade: %d",p->codigo);
        p = p->prox;
    }
    return maiorp;
}

void main()
{
    noptr *inicio;
    int resp=-1;
    inicio=NULL;
    noptr *info;
    float prec,desc;
    int cod,quant;
    do
    {
        printf("\n Menu\n1 Inserir produto; \n2 Inserir desconto; \n3 Relatorio; \n4 Mostrar maior preço e produto com maior quantidade; \n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite o codigo: ");
            scanf("%d",&cod);
            printf("\nDigite a quantidade estocada: ");
            scanf("%d",&quant);
            printf("\nDigite o preco: ");
            scanf("%f",&prec);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(&inicio,info,cod,quant,prec);
        }
        else if(resp == 2)
        {
            printf("\nDigite o desconto: ");
            scanf("%f",&desc);
            desconto(&inicio,desc);
        }
        else if(resp == 3)
        {
            lista_todos(inicio);
        }
        else if(resp == 4){
            float retorno;
            retorno = retornaPreco(inicio);
            printf("\nMaior preco: %.2f",retorno);
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
