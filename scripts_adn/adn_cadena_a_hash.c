#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char caracter, c;
    char nombre_archivo[20];
    char cadena[1000];
    int  kmer = 0;
    char letra;
    int  numeroADN = 0;
    int  i = 0, valor, j;
    printf("Escriba el nombre del archivo:");     // Salida en la pantalla
    c                 = getchar();
    nombre_archivo[i] = c;
    for (i = 1; (c = getchar()) != '\n'; i++)       // Recepción de la cadena de ADN
        nombre_archivo[i] = c;
    FILE* archivo;
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
        printf("\nError de apertura del archivo. \n\n");
    else
    {
        while (feof(archivo) == 0) {
            caracter     = fgetc(archivo);
            cadena[kmer] = caracter;
            kmer++;
        }
        for (i = 0; i <= kmer; i++) {
            letra = cadena[i];
            switch (letra)
            {
                case 'A':
                    valor = 0;
                    break;
                case 'C':
                    valor = 1;
                    break;
                case 'G':
                    valor = 2;
                    break;
                case 'T':
                    valor = 3;
                    break;
                default:
                    break;
            }
            kmer--;
            numeroADN = numeroADN + (pow(4, (kmer - 1))) * valor;
        }
    }
    printf("%d\n", numeroADN);
    return 0;
}
