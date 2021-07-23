#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H
#include <iostream>
#include "Node.h"
template<typename T>
class IteradorLista{
    Node<T>* head;
    public:
        IteradorLista(Node<T>*);
        bool hasNext();
        T next();
        T begin(T);
        T end(T);
        ~IteradorLista();
};
template<typename T>
IteradorLista<T>::IteradorLista(Node<T>* head){
    this->head = head;
}
template<typename T>
bool IteradorLista<T>::hasNext(){
    return (head != NULL) ? true : false;
}
template<typename T>
T IteradorLista<T>::next(){
    T elem = head->elem;
    head=head->next;
    return elem;
}
template<typename T>
T IteradorLista<T>::begin(T elem){
    Node<T>* cabeza = new Node<T>(elem);
    cabeza = head;
    T e = cabeza->elem;
    return e;
}
template<typename T>
T IteradorLista<T>::end(T elem){
    Node<T>* cabeza = new Node<T>(elem);
    cabeza = head;
    while (cabeza->next != NULL){
        cabeza=cabeza->next;
    }
    T e = cabeza->elem;
    return e;
}
template<typename T>
IteradorLista<T>::~IteradorLista(){
    std::cout<<"\n...Destruyendo Iterador...\n";
}
#endif