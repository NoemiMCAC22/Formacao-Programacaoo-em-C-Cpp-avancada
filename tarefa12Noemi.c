#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct tag_produto {
   char *prod;
   char *seccao;
   char tipo_produto;
   int codigo;
   struct tag_produto *proximo;
} TProduto;
/* Prototipos das funcoes  */
void inserir(TProduto **cabeca);  /* Insere um produto na lista */
void listar (TProduto *cabeca, FILE *arquivo);   /* Apresenta todos os produtos na tela ou em um arquivo*/
TProduto* le_arquivo(FILE *arquivo);  /* Le a lista de produtos a partir de um arquivo */
void listar_seletivamente(TProduto *cabeca, char *criterio, char *valor); /* Apresenta somente os produtos que satisfaçam determinado critério */
FILE * abre_arquivo(FILE *arquivo, const char * modo);
void le_dados_no(TProduto *novono);
void imprime_no( FILE *arquivo, TProduto * noatual);
TProduto* desaloca_lista(TProduto* cabeca);
void aloca_copia(char ** , char* );
int main()
{
    TProduto *cabeca = NULL;        /* Ponteiro para a cabeca da lista */
    char q;                            /* Caractere para receber a opcao do usuario */
    FILE *arquivo = NULL;	       /* Ponteiro para FILE: arquivo que será lido ou escrito */
    char codigo[5];		       /* nota para comparacao vai ser lida como char */
    do {
        printf("\n\nOpcoes: \
        \nI -> para inserir produto; \
        \nL -> para listar os produtos; \
        \nA -> para ler lista de produtos em um arquivo;\
        \nG -> para gravar lista de produtos para arquivo; \
        \nN -> Para listar os produtos com codigo superior a um valor; \
        \nT -> Para listar os produtos de determinado tipo; \
        \nS -> para sair \n:");
        fflush(stdin);	     /* Limpa o buffer de entrada */
        scanf("%c", &q);     /* Le a opcao do usuario */
        fflush(stdin);       /* Limpa o buffer de entrada */
        switch(q) {
            case 'i': case 'I':		/* Inserir novo no na lista */
            	inserir(&cabeca);
               break;
            case 'l': case 'L':		/* Listar no video a lista de produtos */
               listar(cabeca, stdout);
               printf("\n Aperte <enter> para continuar");
               fflush(stdin);
               scanf("%c",&q);
               fflush(stdin);
               break;
            case 'a': case 'A':		/* Ler a lista a partir de arquivo */
               arquivo = abre_arquivo(arquivo, "r");
               if(arquivo)
               {  cabeca = desaloca_lista(cabeca);	/* Se havia lista anterior, ela e' desalocada */
               	  cabeca = le_arquivo(arquivo);		/* Le arquivo e retorna ponteiro para cabeca da lista */
                  fclose(arquivo);			/* Fecha o arquivo, pois nao precisa mais dele */
               }
               break;
            case 'g':case 'G':		/* Grava a lista para um arquivo */
               arquivo = abre_arquivo(arquivo,"w");
               if(arquivo)
               {
               	  listar(cabeca, arquivo);	/* Grava o arquivo */
                  fclose(arquivo);		/* Fecha o arquivo */
               }   
               break;
            case 'n': case 'N':		/* Lista produtos por cod */
               printf("\n\nCódigo do produto deve ser superior a:");
               gets(codigo);
               listar_seletivamente(cabeca, "codigo", codigo);
               break;
            case 't': case 'T':		/* Lista produtos por tipo  */
            	printf("\n\nQual tipo de Produto?: \
               \nF -> Fruta; \
               \nL -> Legumes; \
               \nS -> Secos; \
               \nL -> Liquidos; \
               \nP -> Padaria; \
               \nO -> Outro tipo.\n:");
               fflush(stdin);
               scanf("%c", &q);
               fflush(stdin);
               listar_seletivamente(cabeca, "tipo_produto", &q);
               break;
            case 's': case 'S':		/* Sair do programa */
            	break;
            default:
            	printf("\n\n Opcao nao valida");
        }
    } while ((q != 's') && (q != 'S') );
    cabeca = desaloca_lista(cabeca);	/* Saindo do programa, desaloca a lista alocada */
}
 

/* Desaloca a memoria alocada para os elementos da lista */
TProduto* desaloca_lista(TProduto* cabeca)
{
   TProduto* noatual;
   noatual = cabeca;
   while (noatual != NULL)
    {
        cabeca = noatual->proximo;	/* Armazena em cabeca o proximo no */
        free(noatual->prod);		/* Nao esquecer de desalocar nome */
        free(noatual->seccao);	/* e endereco			  */
        free(noatual);			/* Desaloca o no atual            */
        noatual = cabeca;		/* Faz no atual apontar para o proximo no */
    }
    return cabeca;
}
 

/* Lista todos os elementos presentes na lista encadeada */
void listar (TProduto *noatual, FILE *arquivo)
{
    while( noatual != NULL)    /* Enquanto nao chega no fim da lista */
    {
        imprime_no(arquivo,noatual);	/* Imprime o no atual */
        noatual = noatual->proximo;     /* Faz noatual apontar para o proximo no */
    }
}
 

/* Lista os elementos de maneira seletiva, seguindo criterios especificados em criterio e dependentes do valor */
void listar_seletivamente(TProduto *noatual, char *criterio, char *valor)
{
	 while( noatual != NULL)    /* Enquanto nao chega no fim da lista */
    {
        if(!strcmp(criterio,"tipo_produto"))	/* Criterio de comparacao e' o tipo de comida */
        {
           if(*valor == noatual->tipo_produto)
           imprime_no(stdout, noatual);
        }
        else
        {
          if(!strcmp(criterio,"nota"))  /* Criterio de comparacao e' a nota */
              if(atoi(valor) <= noatual->codigo)
                 imprime_no(stdout,noatual);
        }
        noatual = noatual->proximo;     /* Faz noatual apontar para o proximo no */
    }
}
 

/* Imprime um no da lista no arquivo especificado */
void imprime_no( FILE *arquivo, TProduto * noatual)
{
   fprintf(arquivo,"\nProduto    : %s", noatual->prod);
   fprintf(arquivo,"\nSeccao: %s", noatual->seccao);
   fprintf(arquivo,"\nTipo de Produto : %c", noatual->tipo_produto);
   fprintf(arquivo,"\nCodigo do Produto    : %d\n", noatual->codigo);
}
 

/* Funcao para abrir arquivo */
FILE* abre_arquivo(FILE* arquivo, const char* modo)
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
 

/* Funcao para inserir um novo no, ao final da lista */
void inserir (TProduto **cabeca)   /* Veja que o parametro e' um ponteiro duplo ... */
{
    TProduto *noatual, *novono;
    if (*cabeca == NULL)    /* Se ainda nao existe nenhum Restaurante na lista */
    {
        /* cria o no cabeca */
        *cabeca = (TProduto *) malloc(sizeof(TProduto));
        novono = *cabeca;
    }
    else
    {
        /* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        noatual = *cabeca;
        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    /* Ao final do while, noatual aponta para o ultimo no */
        novono = (TProduto *) malloc(sizeof(TProduto));/* Aloca memoria para o novo no */
        noatual->proximo = novono;     /* Faz o ultimo no apontar para o novo no */
    }
     le_dados_no(novono);
}
 

/* Entra com os dados via teclado e armazena no no da lista */
void le_dados_no(TProduto *novono)
{
   char buffer[MAX];
    printf("\nNome do Produto:");
    gets(buffer);
    novono->prod = (char *) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(novono->prod,buffer);
    printf("\nSeccao do Produto:");
    gets(buffer);
    novono->seccao = (char *) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(novono->seccao,buffer);
    printf("\n\nQual tipo de Produto?: \
               \nF -> Fruta; \
               \nL -> Legumes; \
               \nS -> Secos; \
               \nL -> Liquidos; \
               \nP -> Padaria; \
               \nO -> Outro tipo.\n:");
    fflush(stdin);
    scanf("%c",&(novono->tipo_produto));
    fflush(stdin);
    printf("\n\n Codigo do Produto:");
    scanf("%d",&(novono->codigo));
    novono->proximo = NULL;
}
 

/* Le a lista de restaurantes, armazenada em um arquivo 
   Retorna o ponteiro para o no cabeca da lista */
TProduto* le_arquivo(FILE *arquivo)
{
   char buffer[MAX+10], produto[MAX],seccao[MAX];
   char produto1;
   TProduto *cabeca = NULL;
   TProduto *noatual = NULL;
   int codigo;
   while(!feof(arquivo))
   {
      fgets(buffer,MAX,arquivo);
      if(strstr(buffer,"Produto    :"))strcpy(produto,buffer+10);	/*strstr verifica se a string2 ocorre na string1: esta' em string.h */
      else if(strstr(buffer,"Seccao:")) strcpy(seccao,buffer+10);
           else if(strstr(buffer,"Tipo de Produto :")) produto1 = buffer[10];
                else if(strstr(buffer, "Codigo    :"))
                {
                  codigo = atoi(buffer+9);
                  if(cabeca == NULL)
                  {
                  	/* cria o no cabeca */
   			cabeca = (TProduto *) malloc(sizeof(TProduto));
   			noatual = cabeca;
                  }
                  else
                  {
                    	noatual->proximo = (TProduto *) malloc(sizeof(TProduto));
                  	noatual = noatual->proximo;
                  }
                  aloca_copia(&(noatual->prod),produto);
                  aloca_copia(&(noatual->seccao), seccao);
                  noatual->prod = produto;
                  noatual->codigo = codigo;
                  noatual->proximo = NULL;
                }
   }
   return cabeca;
}
/* Esta funcao, ao mesmo tempo que aloca uma string com tamanho igual a da segunda string, faz a copia
   da segunda string para a primeira  */
void aloca_copia(char ** str_alocada, char* str_copiada)
{   int i;
    *str_alocada = (char *) malloc((strlen(str_copiada)+1)*sizeof(char));
    for(i=0; (str_copiada[i] && (str_copiada[i] != '\n')); i++)
      *((*str_alocada)+i) = str_copiada[i];
    *((*str_alocada)+i) = 0;
    
    
} 

