#include <iostream>

void print(int array[], int tam)
{
    std::cout<<"orden:" ;
    for(int i=0; i<tam; i++)
    {
        std::cout<<array[i] << " ";
    }
    std::cout<<std::endl;
}

void countingSort(int array[], int tam, int max)
{
    int Oarray[max+1];
    for(int i=0; i<max+1; i++)
        Oarray[i] = 0;

    for(int i=0; i<tam; i++)                     
    {
        ++Oarray[array[i]];
    }

    for(int i=1; i<max+1; i++)
    {
        Oarray[i] = Oarray[i] + Oarray[i-1];
    }
    std::cout<<"acumulador"<< std::endl;
    print(Oarray, max+1);                                 

    int Narray[tam];
    for(int i=0; i<tam; i++)
    {
        Narray[Oarray[array[i]] - 1 ] = array[i] ;
        --Oarray[array[i]];
    }
    std::cout<< "orden final" << std::endl ; 
    print(Narray, tam);
}

int main()
{
    int tam; 
    std::cout<< "cantidad elementos del array: ";
    std::cin>>tam; 
    
    int array[tam];
    for(int i=0; i<tam; i++)
    {
        std::cout<<"ingrese elemto: "; 
        std::cin>>array[i];
    }
    print(array, tam);
    countingSort(array, tam, 9);
    return 0;
}   