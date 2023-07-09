#include <stdio.h>
#include <string.h>

struct tipo_endereco
{
        char rua [50];
        int numero;
        char bairro [20];
        char cidade [30];
        long int CPOSTAL;
};

struct ficha_pessoal
{
        char nome [50];
        long int telefone;
        struct tipo_endereco endereco;
};

int main (void)
{
	struct ficha_pessoal ficha;
    
	strcpy (ficha.nome,"Luis Osvaldo Silva");
	ficha.telefone=4921234;
	strcpy (ficha.endereco.rua,"Rua das Flores");
	ficha.endereco.numero=10;
	strcpy (ficha.endereco.bairro,"Cidade Velha");
	strcpy (ficha.endereco.cidade,"Amadora");
	ficha.endereco.CPOSTAL=1101;

        printf( "%s\n", ficha.nome );
        printf( "%s %s\n", ficha.endereco.cidade, ficha.endereco.bairro );

	return( 0 );
}
