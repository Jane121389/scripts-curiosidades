#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
    int  iletra=0; //indíce de las letras
    char c;
    char caracter;
    int  j;
    int  il;                        //indice de la letra
    int  longitud=0;                //longitud de la cadena
    int  kmer    =0;                //k-mer
    int  ikmer;                     //indíce de letras de las cadenas k-mer
    char letra            =' ';     //Contendra una letra  de un ácido nucléico de la cadena de ADN
    int  valor_letra      =0;       //valores que asignamos a los ácidos nucléicos (A=1,T=2,C=3,G=4);
    int  ii               =0;       //indice para inicializar los arreglos
    int  indice_repeticion=0;       //indice del elemento del arreglo repeticion_cadena
    int  repeticion_mayor =0;       //la mayor repetición de una cadena
    int  im               =0;       //índice del arreglo indice_mayor
    char construye_cadena[kmer][4]; //Construccion de las cadenas kmer
    char cadenas_kmer[kmer][4];
    char nombre_archivo[20];                  //Escriba el nombre del archivo donde se encuentra la cadena de ADN
    int  peso_kmer[kmer];                     //identifica el peso de la cadena K-mer
    int  pesos_kmer[kmer];                    //identifica los pesos de las cadenas K-mer
    int  repeticion_cadena[(4 ^ kmer)];       //Coloca el número de repeticiones de cadenas k-mer
    int  indice[kmer];                        //indíce del numero de letras de las cadenas k-mer
    int  indice_mayor[1000];                  //indice del elemento de la cadena k-mer que se repite más veces en la cadena de ADN
    printf("Escriba el k-mer:");              //Salida en la pantalla
    scanf("%d", &kmer);                       //Recepción del k-mer
    printf("Escriba el nombre del archivo:"); //Salida en la pantalla
    c=getchar();
    for (j=0; (c=getchar()) != '\n'; j++) //Recepción de la cadena de ADN
        nombre_archivo[j] =c;
    for (ii=1; ii < kmer; ii++) //inicializa el arreglo de los índices de número de letras de las cadenas k-mer del 0 al -kmer
        indice[ii]=-ii;
    for (ii=0; ii < 4 ^ kmer; ii++) //inicializa el arreglo de los índices de número de letras de las cadenas k-mer del 0 al -kmer
        peso_kmer[ii]=0;
    indice[0]=0;
    FILE* archivo;
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
        printf("\nError de apertura del archivo. \n\n");
    else

        while (feof(archivo) == 0)
        {
            caracter = fgetc(archivo);
            letra    =caracter;                  //letra de la cadena de ADN leída
            if (letra == 'A')                    //Si la letra es A (adenina)
                valor_letra=1;                   //valor que se le asigna a la adenina (A)
            else if (letra == 'T')               //Si la letra es T (timina)
                valor_letra=2;                   //valor que se le asigna a la timina (T)
            else if (letra == 'C')               //Si la letra es C (citosina)
                valor_letra=3;                   //valor que se le asigna a la citosina (C)
            else if (letra == 'G')               //Si la letra es G (guanina)
                valor_letra=4;                   //valor que se le asigna a la guanina (G)
            for (ikmer=0; ikmer < kmer; ikmer++) //recorre los arreglos
            {
                if (indice[ikmer] >= 0)
                {
                    peso_kmer[ikmer]=peso_kmer[ikmer] + ((valor_letra - 1) * (4 ^ (kmer - indice[ikmer] - 1))); //asigna un peso a la letra de la cadena, dependiendo de su valor y el nivel en el que esta situada
                    //printf(" indice %d , peso %d ",indice[ikmer],peso_kmer[ikmer]);
                    construye_cadena[ikmer][indice[ikmer]]=letra; //concatena las letras (ácidos nucleicos)
                    //System.out.print("PESO:"+peso_kmer[ikmer]+ " ikmer "+ikmer+ "cadena "+construye_cadena[ikmer]);
                }
                indice[ikmer]=indice[ikmer] + 1; //aumenta en uno los indices de las letras de las cadenas
                if (indice[ikmer] >= kmer)       //si el índice de la cadena es mayor o igual al número k-mer
                {
                    indice[ikmer]                       =0;                                        //inicializa el índice de la cadena
                    indice_repeticion                   =peso_kmer[ikmer];                         //se asigna el valor del indice del elemento de la cadena repeticion_cadena
                    repeticion_cadena[indice_repeticion]=repeticion_cadena[indice_repeticion] + 1; //si se repite la cadena se incrementa en uno el elemento del arreglo repeticion_cadena
                    if (repeticion_cadena[indice_repeticion] >= repeticion_mayor)
                    {
                        if (repeticion_cadena[indice_repeticion] > repeticion_mayor)// si la repeticion de la cadena es mayor que lo que contiene la variable repeticion_mayor
                        {
                            for (ii=0; ii < im; ii++) //inicializamos el arreglo indice_mayor, porque ya existe una cadena con más repeticiones
                                indice_mayor[ii]=0;   //inicializamos con cero
                            im              =0;
                            indice_mayor[im]=indice_repeticion; //se asigna eel indice de la cadena con más repeticiones
                        }
                        else if (repeticion_cadena[indice_repeticion] == repeticion_mayor)// si la repeticion de la cadena es igual que lo que contiene la variable repeticion_mayor
                        {
                            im++;                               //aumenta en uno la variable im
                            indice_mayor[im]=indice_repeticion; //se asigna un elemento del arreglo indice_mayor para colocar el otro indice del arreglo que contiene una cadena del mismo tamaño
                        }
                        repeticion_mayor=repeticion_cadena[indice_repeticion];//asignamos a la variable, el valor de mayores repeticiones
                    }
                    for (j=0; j < kmer; j++) {
                        cadenas_kmer[indice_repeticion][j]=construye_cadena[ikmer][j]; //se coloca la cadena k-mer
                        construye_cadena[ikmer][j]        =' ';                        //se inicializa  el elemento  del arreglo construye_cadena
                    }
                    peso_kmer[ikmer]=0; //se inicializa en cero el elemento  del arreglo peso_kmer*/
                }
            }
        }
    fclose(archivo);
    printf("La(s) cadena(s) %d k-mer más frecuente en la cadena completa de ADN es ", kmer); //imprime en pantalla
    for (ii=0; ii <= im; ii++)                                                               //imprime las cadenas diferentes k-mer pero que tienen la misma catidad de repeticiones en la cadena
        for (j=0; j <= im; j++)
            printf("%c ", cadenas_kmer[indice_mayor[ii]][j]);
}
