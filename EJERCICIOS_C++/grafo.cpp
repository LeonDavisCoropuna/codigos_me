#include "iostream"
#include "vector"
#include <stdexcept>
 
using namespace std;
 
template <class T> //plantilla
class Graph{
    public:
        vector <vector <T>> grafo; //matriz de vectores
       
        Graph(const vector <T> &starts, const vector<T> &ends); //constructor de Graph
        int numOutgoing(const int nodeID) const; //retorna el numero //de nodos que contiene el vector
        const vector<T> & adjacent(const int nodeID) const; //retorna //el vector indicado
        void show(); //muestra la matriz de adyacencia
};
 
template <class T>
Graph<T>::Graph(const vector<T> &starts, const vector<T> &ends){ //recibe como parametros dos vectores
    if( starts.size() != ends.size()){ //comprueba que los vectores //tengan el mismo tamaño
        throw invalid_argument("Error: Los vectores deben tener el mismo tamaño"); //de no ser así se genera un error
    }
    grafo.resize(starts.size()-1); //se indica el tamaño del grafo, //elimina nodos sobrantes o crea nodos hasta llegar al tamaño indicado
    for(size_t i = 0; i < starts.size(); i++) {
        int start = starts [i]-1, end = ends [i];
        grafo[start].push_back(end); //se inserta un nuevo nodo //(inicio) -> (final)
    }
}
 
template <class T>
void Graph<T>::show(){
    int aux = 1; //contador
    cout<<"Inicio \tFinal"<<endl;
    for (auto i = grafo.begin(); i!=grafo.end(); i++){ //se recorre el //grafo por filas
        cout<<aux<<"  -->\t";
        for (auto j = (*i).begin(); j != (*i).end() ; j++){ //se //recorre las columnas de la fila dada
            cout<<*j<<" ";
        }
        aux++;
        cout<<endl;
    }
}
 
template <class T>
int Graph<T>::numOutgoing(const int nodeID) const{
    int num;
    num = grafo[nodeID-1].size(); //nodeID indica la fila de la matriz //y size retorna el tamaño del vector
    return num;
}
 
 
template <class T>
const vector<T>& Graph<T>::adjacent(const int nodeID) const{
 
    if(numOutgoing(nodeID)>0){ //comprueba si el vector tiene más de //un nodo
        return grafo[nodeID-1];
    }
    else{//si tiene 0 datos, retorna un vector vacio
        vector <T> vacio = {};
        return vacio;
    }
}
 
int main(){
 
    vector <int> inicio = {1 ,1 ,1, 5, 5, 4}; //vector inicio
    vector <int> final   = {2, 3, 4, 4, 2, 2}; //vector final
 
    Graph <int> grafo(inicio,final); //se instancia un objeto de la //clase Grafo llamado grafo
 
    grafo.show();
    int nodoID = 1; //seleccionamos la fila nodoID de grafo
    cout<<"\nCantidad de nodos adjayecentes a "<<nodoID<<": "<<grafo.numOutgoing(nodoID)<<endl<<endl;
    vector <int> vec_ady = grafo.adjacent(nodoID); //retornamos el //vector nodoID de grafo
    cout<<"Adyacentes a "<<nodoID<<" -> ";
    for(auto i = vec_ady.begin() ; i != vec_ady.end() ; i++){
        cout<<*i<<"  ";
    }
 
    return 0;
}
