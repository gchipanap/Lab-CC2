#include <iostream>

int sumar_iterativa( int tam, int* array)
{
    int acum;
    for(int i=0; i <tam ; i++)
        {
            acum = *array;
            ++array; 
        }
    return acum;
}

int main ()
{
    int tam;
    std::cin>>tam;
    int* array = new int[tam];
    for(int _=0; _<tam; _++)
    {
        std::cin>>*array++;
    }

    int acumI;
    int acumR;

    acumI = sumar_iterativa(tam, array);
    acumR = sumar_recursivo(tam, array);
    std::cout<<acumR;

    return 0;
}