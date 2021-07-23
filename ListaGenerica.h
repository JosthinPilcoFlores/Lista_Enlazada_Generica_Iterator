#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H
#include <iostream>
#include "IteradorLista.h"
#include "Node.h"
template<typename T>
class ListaGenerica{
    private:
        int size;
        Node<T>* head;
    public:
        ListaGenerica(int,T);
        void insertar(T);
        void remover(T);
        IteradorLista<T> iterador();
        ~ListaGenerica();
};
template<typename T>
ListaGenerica<T>::ListaGenerica(int size,T elem){
    this->size = 0;
    head = new Node<T>(elem);
    head = NULL;
    size+=1;
    for (int i=0; i<size-1; i++){
        std::cout<<"Ingrese elemento: ";
        std::cin>>elem;
        insertar(elem);
    }
}
template<typename T>
void ListaGenerica<T>::insertar(T elem){
    Node<T>* nuevo_nodo = new Node<T>(elem);
    Node<T>* aux1 = head;
    Node<T>* aux2;
    while((aux1 != NULL) && (aux1->elem<elem)){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if(head == aux1){
        head = nuevo_nodo;
    }else{
        aux2->next = nuevo_nodo;
    }
    nuevo_nodo->next=aux1;
    size+=1;
    std::cout<<"Elemento "<<elem<<" insertado correctamente\n";
    system("pause");
    system("cls");
}
template<typename T>
void ListaGenerica<T>::remover(T elem){
    if(head != NULL){
        Node<T>* auxBorrar;
        Node<T>* anterior = NULL;
        auxBorrar = head;
        while((auxBorrar != NULL) && (auxBorrar->elem != elem)){
            anterior = auxBorrar;
            auxBorrar = auxBorrar->next;
        }
        if(auxBorrar == NULL){
            std::cout<<"El elemento "<<elem<<" no existe\n";
            system("pause");
            system("cls");
        }else if(anterior == NULL){
            std::cout<<"Eliminando elemento "<<elem<<std::endl;
            size-=1;
            head = head->next;
            delete auxBorrar;
            system("pause");
            system("cls");
        }else{
            std::cout<<"Eliminando elemento "<<elem<<std::endl;
            size-=1;
            anterior->next = auxBorrar->next;
            delete auxBorrar;
            system("pause");
            system("cls");
        }
    }else{
        std::cout<<"Elemento "<<elem<<" no existe\n";
        system("pause");
        system("cls");
    }
}
template<typename T>
IteradorLista<T> ListaGenerica<T>::iterador(){
    IteradorLista<T> iterador(head);
    return iterador;
}
template<typename T>
ListaGenerica<T>::~ListaGenerica(){
    std::cout<<"\n...Destruyendo Lista...\n";
}
#endif