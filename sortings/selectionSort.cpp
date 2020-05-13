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
void selectionSort(T array[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        T* min = array + i;
        for(int j= i+1; j<tam; j++)
        {
            if(array[j] < *min)
                min = array + j;
        }
        swap(*min, array[i]);
        print(array, tam);
        continue;
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
    
    selectionSort(array, tam);

    std::cout<< "orden final" << std::endl;
    print(array, tam);

    return 0;
}   