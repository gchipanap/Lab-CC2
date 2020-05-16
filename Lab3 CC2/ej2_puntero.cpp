#include <iostream>

void swap(int &a, int &b)
{
    int s = a;
    a =b;
    b = s;
}

void print(int* array, int tam)
{
    for(int i=0; i<tam;i++)
    {
        std::cout<<*(array+i);
    }
    std::cout<<std::endl;
}

void intercambio(int* a, int  tam)
{
    int* b = a+tam-1;
    while( a != b || b<a )
    {
        swap(*a, *b);
        ++a; --b;
    }
}

void intercambioR(int* a, int tam)
{
    int* b = a+tam;
    if(tam != 0)
    {
        swap(*--b, *a);
        intercambioR(++a, tam/2);
    }
}

int main ()
{
    int tam;
    std::cin>>tam;
    int* array = new int[tam];
    for(int i=0; i<tam; i++)
    {
        std::cin>>*(array+i);
    }

    print(array, tam);

    intercambio(array, tam);
    print(array, tam);

    intercambioR(array, tam);
    print(array, tam);
    delete [] array;
    return 0;
}