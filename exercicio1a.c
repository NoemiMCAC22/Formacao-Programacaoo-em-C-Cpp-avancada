#include <stdio.h>

int main ()
{
    int matrx[4][4];
    int *p;
    int count;

    p = matrx[0];
    for (count = 0; count < 16; count++ )
        *p++ = 0;

    p = matrx[0];
    for (count = 1; count < 17; count++ )
        *p++ = count;

    for ( int i=0; i<4; i++ )
        {
            for ( int j=0; j<4; j++ )
               printf( " %3d", matrx[i][j] );
            printf( "\n" );
        }

    return( 0 );
}