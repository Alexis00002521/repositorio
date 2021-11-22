// ADMINISTRACIÓN DE UN ÁRBOL BINARIO DE BÚSQUEDA
// Alexis Merino 00002521
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *hijoIzq; // Puntero al subárbol izquierdo.
    nodo *hijoDer; // Puntero al subárbol derecho.
};

class ABB{

    private:
        nodo *pAbb;
    
    public:
        ABB();
        ~ABB();
        void insertar(void);
        void insNodoAbb(nodo **, int);
        void buscarNodo(int);
        void buscarN(nodo *, int,int);//metodo de busqueda y medicion del nivel
        void borrarNodo(int);
        void borrarNodoRec(nodo **, int);
        void mostrarEnPreorden(nodo *);
        void mostrarEnInorden(void);
        void mostrarIn(nodo *);
        void mostrarEnPostorden(nodo *);
        void mostrarEnPreorden(void);
        void mostrarPre(nodo *);
        void mostrarEnPostorden(void);
        void mostrarPost(nodo *);
};

ABB::ABB(void)
{
    pAbb = NULL;
}

ABB::~ABB()
{
    cout << "Destructor ejecutandose" << endl;
}

void ABB::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if(resp == 's'|| resp=='S'){
            cout << "Digite el dato: ";
            cin >> dato;
            insNodoAbb(&pAbb, dato);
        }

    }while(resp == 's'|| resp=='S');
}

void ABB::insNodoAbb(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hijoIzq = NULL;
        (*p)->hijoDer = NULL;
    }
    else
        if(dato < (*p)->dato)
            insNodoAbb(&((*p)->hijoIzq), dato);
        else
            if(dato > (*p)->dato)
                insNodoAbb(&((*p)->hijoDer), dato);
            else
                cout << "El llave ya esta en el arbol" << endl << endl; 
}

void ABB::buscarNodo(int dato)
{   
    int h=1;buscarN(pAbb, dato,h);
}

void ABB::buscarN(nodo *p, int dato,int h)
{   
    if(!p)
        cout << "El dato no esta en el arbol" << endl << endl;
    else
        if(dato < p->dato)
            buscarN(p->hijoIzq, dato,h+1);
        else
            if(dato > p->dato)
            buscarN(p->hijoDer, dato,h+1);
            else
                {cout << "\n--Dato encontrado--";
                cout<<"\nNivel / Profundidad : "<<h << endl << endl;}
                
}

///////////////////////////

void ABB::borrarNodo(int dato)
{
    borrarNodoRec(&pAbb, dato);
}

// Función recursiva que borra un nodo en un
//árbol binario de búsqueda.

void ABB::borrarNodoRec(nodo **r, int dato)
{
    nodo *p;

    if(!(*r)) //si se llegó a un NULL.
        cout << "El dato NO esta en el arbol" << endl << endl;
    else
        if(dato < (*r)->dato) //Buscar por subárbol izquierdo del nodo.
            borrarNodoRec(&((*r)->hijoIzq), dato);
        else
            if(dato > (*r)->dato) //Buscar por subárbol derecho del nodo.
                borrarNodoRec(&((*r)->hijoDer), dato);
            else{ //El borrado del nodo se hace a partir de aquí:
                if(!((*r)->hijoIzq) && !((*r)->hijoDer)){ //Si nodo a borrar es una hoja.
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->hijoIzq) && (*r)->hijoDer){ //Si el nodo a borrar
                        p = *r; //solo tiene hijo derecho.
                        *r = (*r)->hijoDer;
                    }
                    else
                        if((*r)->hijoIzq && !((*r)->hijoDer)){ //Si nodo a borrar
                            p = *r; //solo tiene hijo
                            *r = (*r)->hijoIzq; //izquierdo.
                        }
                        else
                            if((*r)->hijoIzq && (*r)->hijoDer){ //Si nodo a borrar tiene
                                p = (*r)->hijoIzq; //dos hijos.
                                if(!p->hijoDer){
                                    (*r)->dato = p ->dato;
                                    (*r)->hijoIzq = p->hijoIzq;
                                }
                                else{
                                    nodo *q;
                                    while(p->hijoDer){
                                        q = p;
                                        p = p->hijoDer;
                                    }
                                    (*r)->dato = p->dato;
                                    q->hijoDer = p->hijoIzq;
                                }
                            }
                delete p;
                cout<<"\nDATO ELIMINADO!..";
            }
}

///////////////////////////

///////In-Orden
void ABB::mostrarEnInorden(void)
{
    mostrarIn(pAbb);
}

void ABB::mostrarIn(nodo *p)
{
    if(p){
        mostrarIn(p->hijoIzq);
        cout << p->dato << "  ";
        mostrarIn(p->hijoDer);
    }
    //cout << endl;
}
////////Pre-Orde
void ABB::mostrarEnPreorden(void)
{
    mostrarPre(pAbb);
}

void ABB::mostrarPre(nodo *p)
{
    if(p){
        cout << p->dato << "  ";
        mostrarPre(p->hijoIzq);
        mostrarPre(p->hijoDer);
    }
    //cout << endl;
}
/////////Pos-Orden
void ABB::mostrarEnPostorden(void)
{
    mostrarPost(pAbb);
}

void ABB::mostrarPost(nodo *p)
{
    if(p){
        mostrarPost(p->hijoIzq);
        mostrarPost(p->hijoDer);
        cout << p->dato << "  ";
    }
    //cout << endl;
}

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACION DE UN ARBOL BINARIO DE BUSQUEDA" << endl << endl;

    ABB objAbb;

    cout << "Insertar datos en el arbol:" << endl;
    objAbb.insertar();
    cout << endl<< endl;

    cout << "Mostrando en inorden:" << endl;
    objAbb.mostrarEnInorden();
    cout << endl;

    cout << "Mostrando en preorden:" << endl;
    objAbb.mostrarEnPreorden();
    cout << endl;

    cout << "Mostrando en postorden:" << endl;
    objAbb.mostrarEnPostorden();
    cout << endl<< endl;

    int datoB;

    cout << "Busquemos un dato:" << endl;
    cout << "Digite el dato a buscar: ";
    cin >> datoB;
    objAbb.buscarNodo(datoB);

    cout << "\nBorremos un dato:" << endl;
    cout << "Digite el dato a borrar: ";
    cin >> datoB;
    objAbb.borrarNodo(datoB);

    cout << "\nMostrando en inorden:" << endl;
    objAbb.mostrarEnInorden();
    cout << endl;

    cout << endl;
    return 0;
}