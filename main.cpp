#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct listaCaracteres listaCar;
struct listaCaracteres
{
    char charLista[2];
    listaCar *campEnlace;
};

int main()
{
    int cont = 0;
    listaCar *puntNodo=NULL, *puntAnterior, *puntLista=NULL, *puntMove, *puntAux1=NULL,*puntAux2;
    std::cout << "\n\tListas de enlace simple\n\n"<< std::endl;
    do
    {
        puntAnterior=puntNodo;
        puntNodo = (listaCar *)malloc(sizeof(listaCar));
        std::cout << "\tIngrese un caracter => "<< std::endl;
        fflush(stdin);cin>>(puntNodo->charLista);
        puntNodo->campEnlace=NULL;
        
        if(puntLista==NULL)
        {
            puntNodo->campEnlace=NULL;
            puntLista=puntNodo;
        }
        else
        {
            puntAnterior->campEnlace = puntNodo;
        }
        cont++;
    }while(cont<9);
    
    puntNodo=puntLista;
    
    while(puntNodo->campEnlace!=NULL)
    {
        puntAnterior=puntNodo->campEnlace;
        puntMove=puntNodo;
        
        while(puntAnterior!=NULL)
        {
            if(strcmp(puntNodo->charLista,puntAnterior->charLista)==0)
            {
                puntMove->campEnlace=puntAnterior->campEnlace;
                puntAnterior->campEnlace=NULL;
                
                if(puntAux1==NULL)
                    puntAux1=puntAnterior;
                else
                {
                    puntAux2=puntAux1;
                    
                    while(puntAux2->campEnlace!=NULL)
                        puntAux2=puntAux2->campEnlace;
                    puntAux2->campEnlace=puntAnterior;
                }
                puntAnterior=puntMove->campEnlace;
            }
            else
            {
                puntMove=puntAnterior;
                puntAnterior=puntAnterior->campEnlace;
            }
        }
        puntNodo=puntNodo->campEnlace;
    }
    
    std::cout <<"\n\tLa lista almacena\n\n"<< std::endl;
    
    puntNodo=puntLista;
    
    while(puntNodo!=NULL)
    {
        std::cout << (static_cast<void>("\t%s "),puntNodo->charLista) << std::endl;
        puntNodo=puntNodo->campEnlace;
    }
    std::cin.get();
}
