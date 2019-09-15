#include "lista.h"
#include <stdlib.h>

void crear_lista(tLista* l){
    (*l) = (tLista) malloc(sizeof(struct celda));

    if (*l == NULL)
        exit(LST_ERROR_MEMORIA);

    (*l)->elemento = NULL;
    (*l)->siguiente = NULL;
}

void l_insertar(tLista l, tPosicion p, tElemento e){
    tPosicion nodo_nuevo = (tPosicion) malloc(sizeof(struct celda));
    if (nodo_nuevo == NULL)
        exit(LST_ERROR_MEMORIA);

    tPosicion nodo_actual = l;
    

}

void l_eliminar(tLista l, tPosicion p, void (*fEliminar)(tElemento)){
    if (p == l_fin(l))
        exit(LST_POSICION_INVALIDA);
    
    fEliminar((p->siguiente)->elemento);
    (p->siguiente)->elemento = NULL;

    p->siguiente = (p->siguiente)->siguiente;
    p->siguiente = NULL;
    free(p->siguiente);  
}

void l_destruir(tLista * l, void (*fEliminar)(tElemento)){

}

tElemento l_recuperar(tLista l, tPosicion p){
    if (p == l_fin(l))
        exit(LST_POSICION_INVALIDA);

    return (p->siguiente)->elemento;
    
}

tPosicion l_primera(tLista l){
    return l;
}

tPosicion l_siguiente(tLista l, tPosicion p){
    if (p == l_fin(l))
        exit(LST_NO_EXISTE_SIGUIENTE);
    
    return p->siguiente;
}

tPosicion l_fin(tLista l){
    tPosicion toRet = l;
    
    while (toRet->siguiente != NULL)
        toRet = toRet->siguiente;
    
    return toRet;
}

/**
 Destruye la lista L, elimininando cada una de sus celdas. Los elementos almacenados en las celdas son eliminados mediante la funci�n fEliminar parametrizada.
**/
extern void l_destruir(tLista * l, void (*fEliminar)(tElemento));





/**
 Recupera y retorna la posici�n anterior a P en L.
 Si P es primera(L), finaliza indicando LST_NO_EXISTE_ANTERIOR.
**/
extern tPosicion l_anterior(tLista l, tPosicion p);
    tPosicion nodo_actual = l;

    if(nodo_actual->siguiente == p){// cuando p es la primera posicion.
     exit(LST_NO_EXISTE_ANTERIOR);
    }

    while(nodo_actual->siguiente != NULL)  && (nodo_actual->siguiente != p)){
    nodo_actual=nodo_actual->;
    }

    return nodo_actual;
}


extern tPosicion l_ultima(tLista l){
    tPosicion nodo_actual = l;

    if(nodo_actual->elemento!= NULL){
    while((nodo_actual->siguiente!= NULL)&& (nodo_actual->siguiente->siguiente != NULL)){
        nodo_actual=nodo_actual->siguiente;
        }
    }
    return nodo_actual;
}


int l_longitud(tLista l){
    int contador = 0;
    tPosicion nodo = l;
    while (nodo->siguiente != NULL)
    {
        nodo = nodo->siguiente;
        contador++;
    }
    return contador;
}
