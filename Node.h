#ifndef NODE_H
#define NODE_H
#include <iostream>
template<typename T>
class Node{
    public:
        T elem;
        Node* next;
        Node(T);
        ~Node();
};
template<typename T>
Node<T>::Node(T elem){
    this->elem=elem;
    next=NULL;
}
template<typename T>
Node<T>::~Node(){
    std::cout<<"\n...Destruyendo Nodo...\n";
}
#endif