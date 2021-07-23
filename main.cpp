#include <iostream>
#include <list>
#include "ListaGenerica.h"
using namespace std;
class Persona{
    string nombre="";
    int edad=0;
    public:
        Persona(string,int);
        string getNombre()const;
};
Persona::Persona(string nombre,int edad){
    this->nombre=nombre;
    this->edad=edad;
}
string Persona::getNombre()const{
    return nombre;
}
int main(){
    ListaGenerica<int> a(4,0);
    IteradorLista<int> iterador = a.iterador();
    cout<<"Primer elemento de la lista: "
        <<iterador.begin(0)
        <<"\nUltimo elemento de la lista: "
        <<iterador.end(0)<<endl;
    system("pause");
    system("cls");
    cout<<"Mostrando elementos de la lista:\n";
    while (iterador.hasNext()){
        cout<<iterador.next()<<" -> ";
    }
    cout<<endl;
    system("pause");
    system("cls");
    /*
    //List de STL
    */
    cout<<"Trabajando con \"list\" de libreria STL\n";
    Persona p1("Juan",23),p2("Martin",27),p3("Carlos",43),p4("Bob",45);
    list<Persona> personas;
    cout<<"Se puede agregar personas por atras y delante de la lista\n";
    personas.push_back(p1);
    personas.push_back(p2);
    personas.push_back(p4);
    cout<<"Ingresando 3 personas con push_back y una con push_front\n";
    personas.push_front(p3);
    cout<<"Se pueden mostrar los datos creando un iterator\n";
    list<Persona>::iterator i = personas.begin();
    while (i != personas.end()){
        cout<<i->getNombre()<<endl;
        i++;
    }
    cout<<"Se puede remover un elemento de la lista\n";
    i=personas.begin();
    personas.erase(i);
    i=personas.begin();
    while (i != personas.end()){
        cout<<i->getNombre()<<endl;
        i++;
    }
    cout<<"Se puede obtener el inicio y el final de la lista\n";
    i=personas.begin();
    cout<<"Inicio: "<<i->getNombre()<<endl;
    i=personas.end(); i--;
    cout<<"Final: "<<i->getNombre()<<endl;
    cout<<"Entre otras propiedades\n";
    system("pause");
    system("cls");
    return 0;
}