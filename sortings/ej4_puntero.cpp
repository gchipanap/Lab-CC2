#include <iostream>

int tamI(char* a)
{ 
    int sum = 0;
    while( a != '\0')
        {++sum; ++a;}
    return sum;
}

int tamR(char* a)
{
    if(a != '\0')
        return tamR(++a) + 1;
}

int main()
{
    int tam; 
    std::cout<<"cantidad elementos de la cadena: ";
    std::cin>>tam; 
    char* a = new char[tam];
    for(int i=0; i<tam; i++)
    {
        std::cout<<"ingrese elemto: "; 
        std::cin>>*a; ++a;
    }
    int cont;

    cont = tamR(a);
    std::cout<<"elementos: " << cont; 
    cont = tamI(a);
    std::cout<<"elementos: " << cont;
    
    return 0;
}