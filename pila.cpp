#include "iostream"
#include "vector" //libería que nos permite usar vector
using namespace std;

template <typename T>
class Stack{
    public:
        vector <T> pila;
        bool empty() const; //comprobar si la pila esta vacía o no
        void push(const T&); // inserta elementos
        void pop(); //elimina elementos
        T &top(); //retorna el último valor ingresado
        void print(); //muestra los datos
};

template <typename T>
bool Stack<T>::empty()const{
    return pila.empty(); //empty retorna un valor boleano, true si esta vacío
}
template <typename T>
void Stack<T>::push(const T &dato){
    pila.push_back(dato); //agrega un dato en el tope del stack
}
template <typename T>
void Stack<T>::pop(){
    pila.pop_back(); //inserta un dato al inicio de la pila
}
template <typename T>
T &Stack<T>::top(){
    return pila[pila.size()-1]; //retorna el nodo de la pila ingresado más recientemente
}
template <typename T>
void Stack<T>::print(){
    for (auto i = pila.begin(); i != pila.end(); ++i){   
        cout << *i << " "; //muesta los datos de la pila    
    }
}

//usamos el operator+ para concatenar los datos de ambas pilas en una sola
template <typename T>
Stack <T> operator+(Stack <T> const p1,Stack <T> const p2){
    Stack <T> aux; 
    aux=p1; //iniciamos nuestra nueva pila asignandole la informacion de la primera pila
    for (auto i = p2.pila.begin(); i != p2.pila.end(); ++i)
        aux.push(*i); //insertados los elementos de la segunda pila en la nueva //pila
    return aux; //retornamos la nueva pila que sería la suma de la primera y segunda pila
}
int main(){
    Stack <int> a,b;
    a.push(3);
    a.push(5);
    b.push(8);
    b.push(2);
    Stack <int>c= a+b;
    c.print();
    cout<<"\n"<<a.top()<<endl;;
    
    return 0;
    system("pause");
}
