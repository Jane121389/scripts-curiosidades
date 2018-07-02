#include <stdio.h>

int main()
{
    int  a=0;     //Declaración de variable entera de tipo entero
    int* puntero; //Declaración de variable puntero de tipo entero
    puntero = &a; //Asignación de la dirección memoria de a
    printf("El valor de a es: %d. \nEl valor de *puntero es: %d. \n", a, *puntero);
    printf("La direccion de memoria de *puntero es: %p", puntero);
    puntero++;
    int* p = &a; //objeto variable y puntero constante
    printf("La direccion de memoria de *puntero es: %p", p);
    a++;
    printf("\nEl valor de *puntero es: %d. \n", *p);
    p=p + 2;
    printf("La direccion de memoria de *puntero es: %p", p);
    printf("El valor de *puntero es: %d. \n", *puntero);
    p=p - 2;
    printf("La direccion de memoria de *puntero es: %p", p);
    return 0;
}
