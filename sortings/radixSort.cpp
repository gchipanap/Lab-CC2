#include <iostream>

int pow(int x, int exp)
{
    int p = 1;
    for(int _ = 0; _ < exp; ++_)
        p *= x;
    return p;
}

void print(int array[], int tam)
{
    std::cout << "Array = ";
    for(int i = 0; i < tam; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void countingSort(int array[], int tam, int exp)
{
    int Oarray[10] {0};

    for(int i = 0; i < tam; ++i)
    {
        ++Oarray[(array[i] / pow(10, exp)) % 10];
    }

    for(int i = 1; i < 10; ++i)
    {
        Oarray[i] += Oarray[i - 1];
    }

    int Narray[tam];
    for(int i = 0; i < tam; ++i)
    {
        Narray[Oarray[(array[i] / pow(10, exp)) % 10] - 1] = array[i];
        --Oarray[(array[i] / pow(10, exp)) % 10];
    }

    for(int i = 0; i < tam; ++i)
    {
        array[i] = Narray[i];
    }
}

void radixSort(int array[], int tam, int maxDigits)
{
    for(int i = 0; i < maxDigits-1; ++i)
        countingSort(array, tam, i);
    print(array, tam);
}

int main()
{
    int tam; 
    std::cout << "Cantidad elementos del array: ";
    std::cin >> tam;

    int array[tam];
    for(int i = 0; i < tam; ++i)
    {
        std::cout << "Ingrese elemento: ";
        std::cin >> array[i];
    }
    int t;
    std::cout<< "ingrese nro max de digitos: " ;
    std::cin>>t;
    radixSort(array, tam, t);
    return 0;
}