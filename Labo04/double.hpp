#include <iostream>
#include <string>
using namespace std;

struct User{
    int id;
    string userName;
    string profile;
};

User solicitarUser(void){
    User p;

    cout << "ID : ";
    cin >> p.id; cin.ignore();
    cout << "NOMBRE DEL USUARIO: ";
    getline(cin, p.userName);
    cout << "PERFILES (administrador, cliente, o trabajador) "<<endl;
    cout << "PERFIL DE TRABAJO: ";
    getline(cin, p.profile);
    
    return p;
}

void mostrarUser(User p){
    cout<<"PERFIL | NOMBRE DE USUARIO   |  ID"<<endl;
    cout << p.profile<<" | ";
    cout << p.userName<<" | ";
    cout << "[" << p.id << "]."<<endl;
    
}

//Uso de typedef para generalizar la lista doble con una plantilla

typedef User T;
const T noValido = {-1,"",""};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insertFront(T);
        void insertBack(T);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarUser(saltarin->dato);//cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarUser(q->dato);//cout << q->dato << endl;
        q = q->ant;
    }
}
