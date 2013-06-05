#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Cola{
        int dato;
        struct Cola *siguiente;
        }TipoCola;
        
typedef TipoCola *cola;

void crear(cola *frente, cola *fondo);
bool isEmpty(cola *cola1); 
void encolar(cola *cola1, cola *fondo, int dato);
int desencolar(cola *cola1, cola *fondo);

main(){
       cola cola1, fondo;
       crear(&cola1, &fondo);
       encolar(&cola1, &fondo, 10);
       encolar(&cola1, &fondo, 20);
       printf("%d", cola1->dato);
       printf("%d", fondo->dato);
       getche();
}

void crear(cola *frente, cola *fondo){
     *frente= NULL;
     *fondo= NULL;
}

bool isEmpty(cola *cola1){
     if(!*cola1)
        return true;
     else
         return false;
}

void encolar(cola *cola1, cola *fondo, int dato){
     cola nuevo;
     
     if( (nuevo = (cola)malloc(sizeof (TipoCola) )) == NULL)
         return;
         
     nuevo->dato= dato;
     nuevo->siguiente= NULL;
     
     if(*fondo)  //si hay fondo la cola no esta vacia
        (*fondo)->siguiente= nuevo;  //el fondo apunta a nuevo
        
     *fondo= nuevo; //si no hay fondo entonces el fondo es nuevo;
     
     if(isEmpty(cola1))  //si la cola esta vacia el nuevo tambien es el frente
        *cola1= nuevo;                      
}

int desencolar(cola *cola1, cola *fondo){
    cola nuevo;
    int v;
    
    nuevo= *cola1;
    
    if(!nuevo)
       return 0;
       
    *cola1= nuevo->siguiente;
    v= nuevo->dato;
    
    if(isEmpty(cola1))
       *fondo= NULL;
       
    return v;
}
+void mostrar(cola *cola1){
     cola nuevo;
     
     nuevo= *cola1;
     
     if(isEmpty(&nuevo))
        return;
        
     while(!isEmpty(&nuevo)){
           printf("%d", nuevo->dato);
           nuevo= nuevo->siguiente;
           }
}
//trabajo para ingenieria
//en software
