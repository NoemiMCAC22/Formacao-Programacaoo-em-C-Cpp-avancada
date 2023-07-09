#include <stdio.h>
#include <string.h>

int strCmp (char *s, char *t) {
    char *p;
    p = s + strlen(s) - strlen(t); 
    while (*t)
        {
            if (*p != *t) return 0;
            p++;
            t++;
        }
    return 1;
}
int strend(char *s, char *t ) { 

    int s1 = strlen( s );
    int t1 = strlen( t );

    if( t1 <= s1 )
        // comparar as strings s + ( s1 - t1 ) com t
        return strCmp( s + (s1 - t1), t );
        // return !strcmp( s + (s1 - t1), t );

    else
        // devolver falso
        return 0;
}

int main ()
{
    char *s1 = "sado"; // "Mensagem principal do visado";
    char *s2 = "ado";

    printf( "String1: %s\n", s1 );
    printf( "String2: %s\n", s2 ) ;
    // printf( "Resultado strend(): %d\n", strend( s1, s2 ) );
    printf( "Resultado strcmp(): %d\n", strCmp( s1, s2 ) );
    printf( "Resultado strend(): %d\n", strend( s1, s2 ) );

    return( 0 );
}