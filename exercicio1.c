#include <stdio.h>

int main ()
{
    float matrx[4][4];
    float *p;
    int count;

    p = matrx[0];
    for (count = 0; count < 16; count++ )
    {
        p++;
    }

    for ( int i=0; i<4; i++ )
        {
            for ( int j=0; j<4; j++ )
               printf( " %4.0lf", matrx[i][j] );
            printf( "\n" );
        }

    return( 0 );
}