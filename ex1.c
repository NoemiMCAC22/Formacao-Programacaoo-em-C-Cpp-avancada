#include <stdio.h>
#include <math.h>   /* Para as funcoes de raiz e potencia */
struct ponto {
   int x;
   int y;
};
void le_ponto(struct ponto *p, char *);
float dist(struct ponto p1, struct ponto p2);

void main(void)
{
    struct ponto p1, p2;
    printf("\nDistancia entre os pontos:\n");
    le_ponto(&p1, "primeiro");
    le_ponto(&p2, "segundo");
    printf("\n\nDistancia entre os pontos: %5.2f\n", dist(p1, p2));
}
void le_ponto(struct ponto *p, char *s)
{
    int x, y;
    printf("Digite as coordenadas do %s ponto (x,y): ", s);
    scanf("%d%d", &x, &y);
    p->x = x;
    p->y = y;
}
float dist(struct ponto p1, struct ponto p2)
{
    float s1, s2;
    s1 = pow((p1.x-p2.x), 2);   /* Funcao pow(x,y) retorna x^y */
    s2 = pow((p1.y-p2.y), 2);
    return sqrt( s1 + s2);    /* Funcao sqrt(x) retorna a
                               raiz quadrada de x */
}                               