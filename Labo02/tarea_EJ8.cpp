#include <iostream>

void cont(int);

void cont(int x)
{
    int i;

    for(i = 1; i< x ;i++)
    {
        std::cout<<"\n "<<i; 
    }
    
    for(i=x; i>= 1 ; i--)
    {
        std::cout<<"\n "<<i;
    }
         
}

int main(){
    int x=0;

    std::cout<<"\n-------------CONTEO ACENDENTE Y DESENDENTE------------- ";
    std::cout<<"\ningrese un entero : ";
    std::cin>>x;

    cont(x);

    std::cout<<" \n ";
    return 0;
}