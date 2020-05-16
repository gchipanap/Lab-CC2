#include <iostream>
void print(int* array, int tam)
{
    for(int i=0; i<tam;i++)
    {
        std::cout<<*(array+i);
    }
    std::cout<<std::endl;
}
int sumar_iterativa( int tam, int* array)
{
    int acum = 0;
    for(int i=0; i <tam ; i++)
        {
            acum = acum + *array;
            ++array;
        }
    return acum;
}

int sumar_recursiva(int tam, int*array1)
{
    int acum = tam;
    if (acum == 1)
    {
        return *(array1+tam-1); 
    }
    else
    {
        return  *array1 + sumar_recursiva(acum - 1, ++array1)  ;
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

    int acumI;
    int acumR;

    acumI = sumar_iterativa(tam, array);
    std::cout<<acumI;
    std::cout<<std::endl;
    acumR = sumar_recursiva(tam, array);
    std::cout<<acumR;
    delete [] array;
    return 0;
}