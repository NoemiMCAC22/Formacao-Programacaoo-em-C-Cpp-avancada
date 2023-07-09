#include <stdio.h>
#define N 4

int main ()
{
    int matrx[N][N];
    int *p;
    int count = 1;

    
    p = matrx[0];
    for (int i = 1; i <= N*N; i++ ) {
        *p++ = count;
        
        if (i  % N == 0)
          count = i / N + 1;

        else 
          count += N;  
    }
        
    for ( int i=0; i<N; i++ )
        {
            for ( int j=0; j<N; j++ )
               printf( " %3d", matrx[i][j] );
            printf( "\n" );
        }

    return( 0 );
}
