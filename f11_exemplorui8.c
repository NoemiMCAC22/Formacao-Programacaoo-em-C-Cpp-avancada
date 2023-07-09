#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANO_ATUAL 2022

typedef enum
{
    BRANCA,
    AMARELA,
    VERDE,
    BEGE,
    VERMELHO,
    AZUL
} Cor;
typedef enum
{
    DEVOLUTO,
    MAU,
    RAZOAVEL,
    BOM,
    EXCELENTE,
    NOVA
} Estado;

typedef struct
{
    int ano_construcao;
    int nif;
    Estado estado;
    Cor cor;
} Casa;

typedef struct
{
    Casa carteira[20];
    int numcasas;
} Carteira;

int mudaCor(Casa *c, Cor novaCor)
{
    int checknif;
    printf("Por favor insira o NIF para alterar a cor da casa.\n");
    scanf("%d", &checknif);
    if (c->nif == checknif)
    {
        c->cor = novaCor;
        printf("\nA cor da casa foi alterada.");
    }
    else
    {
        printf("NIF Errado. Programa terminado.\n");
    }
    return (0);
}

int calculaIdade(Casa *c)
{
    int idade = 0;
    int checknif = 0;
    idade = ANO_ATUAL - c->ano_construcao;
    return (idade);
}

void listaCasas(Carteira c)
{
    int idade;
    if (c.numcasas > 0)
    {
        printf("Numero de casas em carteira: %d\n\n", c.numcasas);
        for (int i = 0; i < c.numcasas; i++)
        {
            idade = calculaIdade(&(c.carteira[i]));
            printf("Casa #%d\n", i + 1);
            printf("Cor: %d\nAno de Construcao: %d\nNIF: %d\nEstado: %d\nIdade: %d\n----------------------\n",
                   c.carteira[i].cor, c.carteira[i].ano_construcao, c.carteira[i].nif, c.carteira[i].estado, idade);
        }
    }
    else
    {
        printf("Carteira vazia.\n");
    }
}

void menu()
{
    printf("\n");
    printf("1-Listar casas em carteira\n");
    printf("2-Muda Cor\n");
    printf("3-Calcular idade da Casa\n");
    printf("4-Sair\n");
    printf("\n");
}

int main()
{

    Carteira c1;
    c1.carteira[0].cor = BRANCA;
    c1.carteira[0].ano_construcao = 1977;
    c1.carteira[0].nif = 100;
    c1.carteira[0].estado = MAU;

    c1.carteira[1].cor = BRANCA;
    c1.carteira[1].ano_construcao = 2007;
    c1.carteira[1].nif = 101;
    c1.carteira[1].estado = RAZOAVEL;

    c1.carteira[2].cor = AMARELA;
    c1.carteira[2].ano_construcao = 2015;
    c1.carteira[2].nif = 102;
    c1.carteira[2].estado = BOM;

    c1.carteira[3].cor = AMARELA;
    c1.carteira[3].ano_construcao = 2021;
    c1.carteira[3].nif = 103;
    c1.carteira[3].estado = EXCELENTE;

    c1.carteira[4].cor = VERDE;
    c1.carteira[4].ano_construcao = 2022;
    c1.carteira[4].nif = 104;
    c1.carteira[4].estado = NOVA;
    c1.numcasas = 5;

        int n;
    while (1)
    {
        menu();
        printf("Opcao: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            listaCasas(c1);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            return (0);
        default:
            printf("Opcao errada.\n");
        }
    }

    /* int idade;
    for (int i = 0; i < 5; i++)
    {
        idade = calculaIdade(&(c1.carteira[i]));
        printf("Casa #%d\n", i + 1);
        printf("Cor: %d\nAno de Construcao: %d\nNIF: %d\nEstado: %d\nIdade: %d\n----------------------\n",
               c1.carteira[i].cor, c1.carteira[i].ano_construcao, c1.carteira[i].nif, c1.carteira[i].estado, idade);
    }
    printf("Numero de casas em carteira: %d\n\n", c1.numcasas);
    mudaCor(&(c1.carteira[1]), AZUL);
    printf("\n----------------------\n");
    printf("Cor: %d\nAno de Construcao: %d\nNIF: %d\nEstado: %d\n----------------------\n",
           c1.carteira[1].cor, c1.carteira[1].ano_construcao, c1.carteira[1].nif, c1.carteira[1].estado); */

    // f) Ler NIF de casa, localizar a casa e
    // apresentar a sua idade com a funcao calculaIdade()

    return (0);
}

