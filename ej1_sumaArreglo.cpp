#include <iostream>

int sumar_iterativa( int tamn, int array1[])
{
    int acum;
    int t = tamn;
    for(int i=0; i < t; i++)
        {
            acum = acum + array1[i]; 
        }
    return acum;
}
int sumar_recursivo( int tam, int array1[])
{
    if (tam == 0)
    {
        return array1[tam-1]; 
    }
    else
    {
        tam = tam -1;
        return sumar_recursivo( tam-1 , array1) + array1[tam - 1] ;
    }
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
    int acumI;
    int acumR;
    acumI = sumar_iterativa(tam, array);
    acumR = sumar_recursivo(tam, array);
    std::cout<<acumR;

    return 0;
}