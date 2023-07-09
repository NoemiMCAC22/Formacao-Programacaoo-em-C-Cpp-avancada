#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#define MAX 100

/* Estrutura que será usada para criar os nós da lista */

typedef struct tipo_produto {
    int codigo;                      /* Codigo do produto */
    double preco;                    /* Preco do produto */
    struct tipo_produto *proximo;    /* Proximo elemento da lista encadeada de Produtos */
}  TProduto;

/* Prototipos das funcoes para inserir e listar produtos */

void inserir(TProduto **cabeca);
void inserirRegisto(TProduto **cabeca, int cod, double preco);
void listar (TProduto *cabeca);
void gravar (TProduto *cabeca);
void carregar (TProduto **cabeca);
void limpar (TProduto *cabeca);
TProduto* desaloca_lista(TProduto* cabeca);
FILE* abre_arquivo(FILE *arquivo, const char * modo);

int main()
{
    TProduto *cabeca = NULL;        /* Ponteiro para a cabeca da lista */
    char q;                         /* Caractere para receber a opcao do utilizador */
    carregar(&cabeca);                        
    do {
        printf("\n\nOpcoes: \nI -> para inserir novo produto;\nL -> para listar os produtos; \nS -> para sair \n:");
        scanf("%c", &q);     /* Le a opcao do utilizador */
        switch(q) {
            case 'i': case 'I': inserir(&cabeca); break;
            case 'l': case 'L': listar(cabeca); break;
            case 'g': case 'G': listar(cabeca); break;
            case 's': case 'S': break;
            default: printf("\n\n Opcao nao valida");
        }
        getchar();    /* Limpa o buffer de entrada */
    } while ((q != 's') && (q != 'S') );

    limpar(cabeca);
}






/* Lista todos os elementos presentes na lista encadeada */
void listar (TProduto *noatual)
{
    int i=0;
    while( noatual != NULL)    /* Enquanto nao chega no fim da lista */
    {
        i++;
        printf("\n\nProduto numero %d\nCodigo: %d \nPreco: €  %.2lf", i, noatual->codigo, noatual->preco);
        noatual = noatual->proximo;     /* Faz noatual apontar para o proximo no */
    }
}
/* Funcao para inserir um novo no, ao final da lista */

void inserir (TProduto **cabeca)
{
    int cod;
    double preco;
    printf("\n Codigo do novo produto: ");
    scanf("%d", &cod);
    printf("\n Preco do produto: € ");
    scanf("%lf", &preco);
    inseriRegisto( cabeca, cod, preco );
}

void inseriRegisto(TProduto **cabeca, int cod, double preco)
{
 
    TProduto *noatual, *novono;

    // Criar o registo do produto
    novono = (TProduto *)malloc(sizeof(TProduto));/* Aloca memoria para o novo no */
    if( novono == NULL ) {
        printf( "Erro de alocacao de memoria\n" );
        exit( 1 );
    }
    novono->codigo = cod;
    novono->preco = preco;
    novono->proximo = NULL;

    if (*cabeca == NULL)    /* Se ainda nao existe nenhum produto na lista */
        *cabeca = novono;
    else
    {
        /* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        noatual = *cabeca;
        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    /* Ao final do while, noatual aponta para o ultimo no */
        // colocar o novo produto no fim da lista
        noatual->proximo = novono;     /* Faz o ultimo no apontar para o novo no */
    }
    
void gravar(TProduto *cabeca)
{
  int novono[100];
    FILE *arq;
    int result;
    int i;

    arq = fopen("ArqTeste.dat", "wb"); // Cria um arquivo bin�rio para grava��o

    if (arq == NULL) // Se n�o conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
   	return;
    }
    // Grava 30 n�meros do vetor a partir da posi��o 0
    result = fwrite (&novono[0], sizeof(TProduto), 10, arq);

    printf("Nro de elementos gravados: %d", result);
    fclose(arq);
}

FILE* abre_arquivo(FILE *arquivo, const char *modo)
{
   static char nome[20]="";
   char novonome[20];
   if(strlen(nome))printf("Nome atual = %s , se quiser mante-lo responda com um enter", nome);
   printf("\nEntre com o nome do arquivo:");
   gets(novonome);
   if(strlen(novonome)) strcpy(nome,novonome);
   arquivo = fopen (nome, modo);
   if(!arquivo) printf("Problema na abertura do arquivo %s", nome);
   return arquivo;
}
void ordenar(TProduto **l) {

    if(*l == NULL || (*l)->proximo == NULL) 
        return; //se for nulo(vazio), ou apenas 1 elemento
    
    TProduto *aux = *l, *t;
    
    while(aux != NULL) {
      t = aux->proximo;
      while(t != NULL) {
        if(aux->codigo > t->codigo) { //se vir depois
            int i;
            float f;
            i = aux->codigo; aux->codigo = t->codigo; t->codigo = i;
            f = aux->preco; aux->preco = t->preco; t->preco = f;
        }
        t = t->proximo;
      }
      aux = aux->proximo;
    }
}

}
