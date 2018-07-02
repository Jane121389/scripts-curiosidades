#include <stdio.h>
#include <stdlib.h>

struct nodo_s
{
    int dato;
    struct nodo_s* siguiente;
};

struct nodo_s* lista;
struct nodo_s* ultimo;
void crea_nodo(int valor)
{
    struct nodo_s* nuevo_nodo;
    nuevo_nodo = (struct nodo_s *)malloc(sizeof(struct nodo_s));
    if (nuevo_nodo != NULL)
    {
        nuevo_nodo->dato      = valor;
        nuevo_nodo->siguiente = NULL;
    }
    if (lista == NULL)
    {
        lista  = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else
    {
        /* el que hasta ahora era el último tiene que apuntar al nuevo */
        ultimo->siguiente = nuevo_nodo;
        /* hacemos que el nuevo sea ahora el último */
        ultimo = nuevo_nodo;
    }
}

void k_a_final(int k)
{
    int            elemento=0;
    struct nodo_s* auxiliar;
    auxiliar = lista;
    printf("\nMostrando la lista desde el kesimo elemento:\n");
    while (auxiliar != NULL)
    {
        if (elemento >= k)
            printf(" %d ", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
        elemento++;
    }
}

int main()
{
    char           opcion;
    int            i;
    struct nodo_s* auxiliar;
    lista  = (struct nodo_s *) NULL;
    ultimo = (struct nodo_s *) NULL;
    for (i=0; i < 10; i++)
        crea_nodo(i);
    auxiliar = lista;
    printf("\nMostrando la lista completa:\n");
    while (auxiliar != NULL) {
        printf(" %d ", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
    }
    k_a_final(5);
}
