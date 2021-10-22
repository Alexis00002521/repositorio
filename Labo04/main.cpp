/*Modificar el ejemplo de Listas Doblemente Enlazadas vista en clase, deberá de:
En lugar de administrar números, deberá de generar un lista con
Id, nombre de usuario y perfil (administrador, cliente, o trabajador).*/
#include "double.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar un usuario." << endl;
    cout <<         "2) Mostrar usuario de inicio a fin." << endl;
    cout <<         "3) Salir." << endl;
    cout <<         "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble user;
    
    bool continuar = true;
    User p;
    do{
        switch(menu()){
            case 1: //Agregar una usuario
                p = solicitarUser();
                user.insertFront(p);
                cout << "Usuario almacenado exitosamente!" << endl;
                break;
            case 2: //Mostrar usuarios de inicio a fin
                user.traversalForwardDirection();
                break;
            case 3: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
