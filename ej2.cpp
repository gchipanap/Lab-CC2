#include <iostream>

void swap(int &a, int &b)
{
    int s = a;
    a =b;
    b = s;
}

void invertir(int array[], int tam)
{
    for(int i=0; i < tam/2-1; i++)
    {
        swap(array[i], array[ i+(tam-(i+1)) ]);
    }
}

void recor(int array[], int tam)
{
    for(int i=0; i < tam/2-1; i++)
        swap(array[i], array[i+1]);
}

void invertirR(int array[], int tam)
{
    if(tam == 0)
        return ;
    else 
        swap(invertirR(array, tam-1), array[tam-1]); 
}

int main ()
{
    int tam;
    std::cin>>tam;
    int array[tam];
    for(int i=0; i<tam; i++)
    {
        std::cin>>array[i];
        std::cout<<array[i];
    }
     invertirR(array,tam );
    for(int i=0; i<tam; i++)
    {
        std::cout<<array[i];
    }

}