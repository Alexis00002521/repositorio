#include <iostream>

void DivEu(int,int);
void Eu(int ,int);
void divicion(int,int, int*, int* );


void DivEu(int x,int y){
    int aux;

    aux= x/y;
    std::cout<<"\nresultado :"<<aux;

}

void divicion(int x,int y,int*c,int*r)
{   int aux1,Aux2;

    *c = x / y; 
    *r = x % y;
    if(*r==0){
        std::cout<<"\nEl mcd es :"<<y;
    }else{
    x = y;
    y = *r;
    
    divicion(x,y,c,r);
    } 
}
int main(){
    int a=0,b=0;
    int co=0,re=0;
    std::cout<<"\n--------MAXIMO COMUN DIVISOR (MCD) POR EL METODO DE EUCLIDES---------";

    
    std::cout<<"\nIngrese el mayor :";
    std::cin>>a;
    std::cout<<"\nIngrese el manor :";
    std::cin>>b;

    divicion(a,b,&co,&re); 
    std::cout<<" \n";
    
    std::cout<<" \n";
    return 0;
}