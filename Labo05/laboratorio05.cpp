// ADMINISTRACIÓN DE UNA LISTA CIRCULAR SIMPLEMENTE ENLAZADA
#include <iostream>

using namespace std;

struct Mascota{
    int edad=0;
    float id=0,peso=0;
    string propietario;
    string raza;
};

typedef Mascota T;

struct nodo{
    T dato;
    nodo *sig;
    
}*pInicio, *ultimo;

class ListaCircSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void insertaNodo(void);
        void insInicio(T);
        void mostrarListaCircIter(void);
        void eliminarListaCircRec(nodo *);
        void eliminar(void);
        bool empty(void);
        bool searchItem(float);
        float solicitarId(void);
        void desplegarLista(void);
        void eliminarNodo(void);

};

ListaCircSimple::ListaCircSimple(void)
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    cout << "Destructor ejecutándose" << endl;
    if(pInicio){
        eliminarListaCircRec(pInicio);
        pInicio = NULL;
    }
}

void ListaCircSimple::eliminarListaCircRec(nodo *p){
    if(p->sig != pInicio)
        eliminarListaCircRec(p->sig);
    delete p;
}

Mascota solicitarMascota(void){
    Mascota p;

    cout << "ID :";
    cin >> p.id; cin.ignore();
    cout << "propietario de la mascota: ";
    getline(cin, p.propietario);
    cout << "Raza: ";
    getline(cin, p.raza);
    cout << "Peso ";
    cin >> p.peso; cin.ignore();
    cout << "edad ";
    cin >> p.edad; cin.ignore();

    return p;
}

void ListaCircSimple::insInicio(T dato)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
        ultimo = pInicio;
        
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}

void ListaCircSimple::mostrarListaCircIter(void)
{
    nodo *saltarin;
    Mascota p;
    cout << endl;
    if(pInicio){
        saltarin = pInicio;
        do{
        cout << "ID: (" << saltarin->dato.id << "). |" ;
        cout << "Propietario: " << saltarin->dato.propietario<<". | ";
        cout << "Raza: " << saltarin->dato.raza<< ". | ";
        cout << "Peso: " << saltarin->dato.peso<< ". | ";
        cout << "Edad de la mascota : " << saltarin->dato.edad<< endl;
        saltarin = saltarin->sig;
        }while(saltarin != pInicio);
    }
}

bool ListaCircSimple::empty(void){
    return pInicio == NULL;
}
////////////////////////////////////////////////////////////////////////////////////////
void ListaCircSimple::eliminar(void)
{   float n;
	nodo* saltarin = new nodo();
	saltarin = pInicio;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	float nodoBuscado = 0;
    n = nodoBuscado ;
	cout << "\n Ingrese el ID del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;cin.ignore();
	if(pInicio!=NULL){
		do{
			
			if(saltarin->dato.id == nodoBuscado)
            {
				cout<<"\n El nodo con el dato ( "<<nodoBuscado<<" ) Encontrado";
				
				if(pInicio == saltarin){
					pInicio = pInicio->sig;
                    ultimo->sig = pInicio;
                    //cout<<"--------INICIO--------";
				}else if(saltarin->sig == pInicio){
					pInicio->sig = pInicio;
					ultimo =pInicio->sig;
                    //cout<<"-----FINAL--------";
				}else{
					anterior->sig = saltarin->sig;
                    //cout<<"-----EN MEDIO-----";
				}
				
				cout << "\n Nodo Eliminado\n\n";
				encontrado = true;
			}
            anterior = saltarin;
			saltarin = saltarin->sig;
		}while(saltarin!=pInicio && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

    
bool ListaCircSimple::searchItem(float datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay mascotas." << endl;
        return false;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && datoB==saltarin->dato.id!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(pInicio==saltarin) // a) saltarín se salió (el dato no está en la lista).
            return false;
        else
            return true;
    }
}

float ListaCircSimple::solicitarId(){
    float id;

    cout << "ingresar id : ";
    cin >> id; cin.ignore();

    return id;

}

void ListaCircSimple::desplegarLista(void){
	nodo* saltarin = new nodo();
	saltarin = pInicio;
	if(pInicio!=NULL){
		do{
			cout << "ID: (" << saltarin->dato.id << "). |" ;
            cout << "Propietario: " << saltarin->dato.propietario<<". | ";
            cout << "Raza: " << saltarin->dato.raza<< ". | ";
            cout << "Peso: " << saltarin->dato.peso<< ". | ";
            cout << "Edad de la mascota : " << saltarin->dato.edad<< endl;
			saltarin = saltarin->sig;
		}while(saltarin!=pInicio);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}



////////////////////////////////////////////////////////////////////////////////////////

//MAIN
int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar una mascota." << endl;
    cout << "2) Mostrar lista." << endl;
    cout << "3) Eliminar mascota." << endl;
    cout << "4) Buscar mascota." << endl;
    cout << "5) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaCircSimple list;
    
    bool continuar = true;
    Mascota p;
    Mascota pref;
    float id,s;
    do{
        switch(menu()){
            case 1: //Agregar una mascota
                p = solicitarMascota();
                list.insInicio(p);
                cout << "mascota almacenada exitosamente!" << endl;
                break;
            case 2: //Mostrar lista
                //list.mostrarListaCircIter();
                list.desplegarLista();
                break;
            case 3: //Eliminar una mascota
                if(list.empty())
                    cout << "No hay mascotas por eliminar" << endl;
                else{
                    cout<<"mascota a eliminar :"<<endl;
                    list.eliminar();
                }
                break;
            case 4: //Buscar una mascota por id
                if(list.empty())
                    cout << "No hay mascota por buscar" << endl;
                else{
                    s = list.solicitarId();
                    cout << "Dicha mascota " << (list.searchItem(s)?"SI":"NO");
                    cout << " se encuentra en la lista." << endl;
                }
                break;
            case 5: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
