#include <stdio.h>
#include <stdlib.h>

/* Estrutura que será usada para criar os nós da lista */

typedef struct tipo_produto {
    int codigo;                      /* Codigo do produto */
    double preco;                    /* Preco do produto */
    struct tipo_produto *proximo;    /* Proximo elemento da lista encadeada de Produtos */
}  TProduto;

/* Prototipos das funcoes para inserir e listar produtos */

void inserir(TProduto **cabeca);
void inserirProduto (TProduto **cabeca, int cod, double preco);
void listar (TProduto *cabeca);
void gravar(TProduto *noatual);
void ler(TProduto **cabeca);

int main()
{
    TProduto *cabeca = NULL;        /* Ponteiro para a cabeca da lista */
    TProduto *noatual;               /* Ponteiro a ser usado para percorrer a lista no momento de desalocar seus elementos*/
    char q;                          /* Caractere para receber a opcao do utilizador */
    
    // Exemplo de lista de dados
    TProduto a, b, c;

    a.codigo = 1;
    a.preco = 1.5;
    
    b.codigo = 2;
    b.preco = 2.5;

    c.codigo = 5;
    c.preco = 0.5;

    cabeca = &a;
    a.proximo = &b;
    b.proximo = &c;
    c.proximo = NULL;
    
    do {
        printf("\n\nOpcoes: \nI -> para inserir novo produto;\nL -> para listar os produtos; \nS -> para sair \n:");
        scanf("%c", &q);     /* Le a opcao do utilizador */
        switch(q) {
            case 'i': case 'I': inserir(&cabeca); break;
            case 'l': case 'L': listar(cabeca); break;
            case 's': case 'S': break;
            default: printf("\n\n Opcao nao valida");
        }
        getchar();    /* Limpa o buffer de entrada */
    } while ((q != 's') && (q != 'S') );

/* Desaloca a memoria alocada para os elementos da lista */

    noatual = cabeca;
    while (noatual != NULL)
    {
        cabeca = noatual->proximo;
        free(noatual);
        noatual = cabeca;
    }
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

    inserirRegisto( cabeca, cod, preco );
}

/* Funcao para inserir um novo no, ao final da lista */
void inserirProduto (TProduto **cabeca, int cod, double preco)
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
}

void gravar(TProduto *noatual)
{
    FILE *f;

    f = fopen( "produtos.txt", "w" );
    if( f != NULL ) {
        while( noatual != NULL)    /* Enquanto nao chega no fim da lista */
        {
            fprintf(f, "%d %f\n", noatual->codigo, noatual->preco );
            noatual = noatual->proximo;     /* Faz noatual apontar para o proximo no */
        }
        fclose( f );
    }
}

void ler(TProduto **cabeca)
{
    FILE *f;
    int cod;
    float preco;

    f = fopen( "produtos.txt", "r" );
    if( f != NULL ) {
        while( !feof(f) )    /* Enquanto nao chega no fim da lista */
        {
            fscanf(f, "%d %f\n",  );
            inserirProduto( f, cod, preco );
        }
        fclose( f );
    }
}
