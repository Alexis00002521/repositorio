#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};
class ListaSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        void insertaEdad(void);
        void insInicio(int);
        void mostrarListaIter(void);
        void mostrarMayorEdad(void);
};
ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}
void ListaSimple::insertaEdad(void)
{
    int dato;
    cout << "Digite una edad o Ctrl-Z para terminar: ";
    while(cin >> dato){
        if (99 > dato){
            insInicio(dato);
            cout << "Digite un edad o Ctrl-Z para terminar: ";
        }else{
            cout<<"edad no valida\ningrese otra :"; 
        }
        
    }
}

void ListaSimple::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarListaIter(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}
void ListaSimple::mostrarMayorEdad(void)
{
    nodo *saltarin;
    int x=0;
    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        if((saltarin->dato)> x){
            x = saltarin->dato;
        }saltarin = saltarin->sig;  
    } cout<<x;
   
}

int main(void)
{
    cout << endl;
    cout << "EDADES DE PERSONAS Y LA MAYOR EDAD " << endl << endl;

    ListaSimple objListaSimple;

    cout << "INGRESE EDADES A LA LISTA:" << endl;
    objListaSimple.insertaEdad();

    cout<<"\nTODAS LAS EDADES :"<<endl;
    objListaSimple.mostrarListaIter();

    cout<<"\nLA MAYOR EDAD ES :"<<endl;
    objListaSimple.mostrarMayorEdad();

    cout << endl;
    return 0;
}