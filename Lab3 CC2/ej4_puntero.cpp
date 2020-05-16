#include <iostream>

int tamI(const char* a)
{ 
    int sum = 0;
    while( *a != '\0')
        {++sum; ++a;}
    return sum;
}

int tamR(const char* a)
{
    if(*a != '\0')
        return tamR(++a) + 1;
    else
        return 0;
        
}

int main()
{ 
    char a[64];
    char b[64];
    std::cin>>a;
    std::cin>>b;

    int cont;
    cont = tamR(a);
    std::cout<<"elementos: " << cont; 
    std::cout <<std::endl;
    cont = tamI(a);
    std::cout<<"elementos: " << cont;
    
    return 0;
}