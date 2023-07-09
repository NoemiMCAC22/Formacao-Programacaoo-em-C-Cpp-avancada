#include <stdio.h>
#include <string.h>

#define ANO_ATUAL 2022

typedef enum { BRANCA, AMARELA, VERDE, BEGE, VERMELHO, AZUL } Cor;

typedef struct {
    int ano;
    int nif_dono;
    char estado[200];
    Cor cor;
} Casa;

typedef struct {
    Casa carteira[20];
    int numcasas;
   
} Carteira;

int mudaCor( Casa *c, Cor novaCor ) {

    int res = 0;
    int nif;

    printf("Insira o contribuinte do dono: ");
    scanf("%d", &nif);

    printf("nif_dono=%d \n", c->nif_dono);
    printf("nif inserido=%d",nif);

    if((c->nif_dono)== nif)
    {
        c->cor = novaCor;
        res = 1;
    }
    
    return res;
}

int calculaIdade( Casa c ) {
    int idade = 0;
    
    idade = ANO_ATUAL - c.ano;
    // calcular a idade com o ANO_ATUAL
    return( idade );
}

void mostraCor(Cor nomeDaCor)
{
    switch (nomeDaCor)
    {
    case BRANCA:
    printf("BRANCA");
    break;    
    case AMARELA:
    printf("AMARELA");
    break;
    case VERDE:
    printf("VERDE");
    break;   
    case BEGE:
    printf("BEGE");
    break;        
    case VERMELHO:
    printf("VERMELHO");
    break;   
    case AZUL:
    printf("AZUL");
    break;   
    
    default:
        printf("Invalido");      
    }

}

int main()
{
    Carteira c1;
    int cor;
    Cor novaCor;

    c1.numcasas = 5;

   c1.carteira[0].nif_dono = 123456789;
   c1.carteira[0].ano = 1980;
   strcpy(c1.carteira[0].estado, "Conservado");
   c1.carteira[0].cor = BRANCA; 

   c1.carteira[1].cor = BRANCA;
   c1.carteira[1].ano = 1800;
   c1.carteira[1].nif_dono = 987654321;
   strcpy(c1.carteira[0].estado, "Em ruinas.");
   
   c1.carteira[2].cor = AMARELA;
   c1.carteira[2].ano = 2019;
   c1.carteira[2].nif_dono = 123123123;
   strcpy(c1.carteira[0].estado, "Novo.");

   c1.carteira[3].cor = AMARELA;
   c1.carteira[3].ano = 2000;
   c1.carteira[3].nif_dono = 456456456;
   strcpy(c1.carteira[0].estado, "Precisa de uma pequena remodelacao.");

   c1.carteira[4].cor = VERDE;
   c1.carteira[4].ano = 1995;
   c1.carteira[4].nif_dono = 789789789;
   strcpy(c1.carteira[0].estado, "Em ruinas.");

   printf("Temos %d casas em carteira! \n", c1.numcasas);

   for (int i = 0; i < 5; i++)
    {
        printf("Informacao da casa %d \n", i + 1);
        printf("O contribuinte do proprietario é: %d\n", c1.carteira[i].nif_dono);
        printf("O ano de construcao e: %d\n", c1.carteira[i].ano);
        printf("A cor e:");
        mostraCor(c1.carteira[i].cor);
        printf("\n");
        printf("O estado da casa e: %s\n", c1.carteira[i].estado);
        printf("\n");
        printf("A terceira casa tem a cor:");
        mostraCor(c1.carteira[2].cor);
        printf("\n");
        printf("Insira a nova cor pretendida para casa 3 (1-BRANCA, 2-AMARELA, 3-VERDE, 4-BEGE, 5-VERMELHO, 6-AZUL)");
        scanf("%d", &cor);

    switch (cor)
    {
    case 1:
        novaCor = BRANCA;
        break;    
    case 2:
        novaCor = AMARELA;
        break;
    case 3:
        novaCor = VERDE;
        break;   
    case 4:
        novaCor = BEGE;
        break;        
    case 5:
        novaCor = VERMELHO;
        break;   
    case 6:
        novaCor = AZUL;
        break;   
    default:
        break;     
    }


    mudaCor( &( c1.carteira[2] ), novaCor );
    
    // f) Ler NIF de casa, localizar a casa e 
    // apresentar a sua idade com a funcao calculaIdade()

    printf("\n");
    printf("A terceira casa sera: \n");
    mostraCor(c1.carteira[2].cor);
    printf("\n");

    int nif;

    printf("Insira o Contribuinte do Dono da casa: ");
    scanf("%d", &nif);

    for (int i = 0; i < 5; i++);
    {
        if (c1.carteira[i].nif_dono == nif)
        {
            printf("A idade da casa e: %d \n", calculaIdade(c1.carteira[i]));
        }
    }

    return( 0 );    
}
}