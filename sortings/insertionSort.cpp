#include <iostream>
template <typename T>
void swap(T &a, T &b)
{
    T s = a;
    a =b;
    b = s;
}

template <typename T>
void print(T array[], int tam)
{
    std::cout<<"orden:" ;
    for(int i=0; i<tam; i++)
    {
        std::cout<<array[i] << " ";
    }
    std::cout<<std::endl;
}

template <typename T>
void insertionSort(T array[], int tam)
{
    for(int i=1; i<tam; i++)
    {
        int pivote = i - 1;
        int compare = i;
        while( array[compare] < array[pivote] )
        {
            swap(array[compare], array[pivote]);
            pivote = pivote - 1;   
            compare = compare - 1; 
            continue; 
        }

        print(array, tam);
    }

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
    
    insertionSort(array, tam);
    std::cout<< "orden final" << std::endl;
    print(array, tam);

    return 0;
}