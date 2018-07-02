#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char subcadena[4];
    int repeticiones;
}subcadenas;
main()
{
    subcadenas* sub;
    int         n=0;
    int         peso;
    int         i, j;
    char        c;
    printf("Proporcione el numero de subcadenas: ");
    scanf("%d", &n);
    sub = (subcadenas *)malloc(n * sizeof(subcadenas));
    for (i=0; i < n; i++)
    {
        printf("Escriba el peso: ");
        scanf("%d", &peso);
        printf("Escriba la subcadena: ");
        c=getchar();
        for (j=0; (c=getchar()) != '\n'; j++)
            (sub + peso)->subcadena[j] =c;

        (sub + peso)->repeticiones=(sub + peso)->repeticiones + 1;
    }
    for (i=0; i < n; i++)
    {
        printf("subcadena:%s ", (sub + i)->subcadena);
        printf("repeticiones:%d ", (sub + i)->repeticiones);
    }
}
