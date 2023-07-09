#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
 char nome[30]; /* Nome do produto */
 int codigo; /* Codigo do produto */
 double preco; /* Preco do produto */
};
int main()
{
    
    struct Produto *prod;
    int i;
    prod = (struct Produto *) malloc(10*sizeof(struct Produto));
    if (prod ==NULL)
        {
        printf("\n Memoria Insuficiente");
        exit(1);
        }
       
    strcpy(prod[0].nome,"Pastel nada");
    prod[0].codigo = 13205;
    prod[0].preco = 0.20;
    strcpy(prod[1].nome,"Queque");
    prod[1].codigo = 15202;
    prod[1].preco = 0.50;
    printf("Venda do Manuel: Lista de Produtos");
    for(i=0; i <= 1; i++)
    {
        printf("\n\nProd %d: %s",i+1, prod[i].nome);
        printf("\nCodigo: %d",prod[i].codigo);
        printf("\nPreco : %.2fEur", prod[i].preco);
    }
    return 0;
}