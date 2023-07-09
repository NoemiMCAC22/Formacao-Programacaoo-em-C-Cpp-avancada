#include <stdio.h>
#include <string.h>

struct est1
{
    int i;
    float f;
};

int main()
{
    struct est1 primeira, segunda; /* Declara primeira e segunda como structs da estrutura est1 */
    primeira.i = 10;
    primeira.f = 3.1415;
    segunda = primeira;
    printf(" Os valores armazenados na segunda struct sao : %d e %f\n", segunda.i, segunda.f);

    return( 0 );
}