#include <iostream>

void swap(int &a, int &b)
{
    int s = a;
    a =b;
    b = s;
}

int order(int* array, int low, int high)
{
    int pivote = *(array + high );
    int compare = low -1;

    for(int i = low; i<= high - 1; i++)
    {
        if( *(array + pivote) >= *(array + compare))
        {
            compare ++;
            swap( *(array+compare), *(array + i));
        }
        else 
            continue;
        
    }
    swap(*(array + high - 1), *(array + compare + 1)) ;
    return(compare+1);
}

void quickSort(int* array, int low, int high)
{
    if(low < high)
    {
        int ord = order(array, low, high);
        quickSort(array, low, ord - 1);
        quickSort(array, ord +1, high);
    }
}
void print(int* array, int tam)
{
    std::cout << "Array = ";
    for(int i = 0; i < tam; ++i)
    {
        std::cout << *(array +i) << ' ';
    }
    std::cout << std::endl;
}


int main()
{
    int tam; 
    std::cout << "ingrese tam"; std::cin>>tam;
    int* array = new int[tam];
    for(int i = 0; i<tam; i++)
    {
        std::cout << "ingrese num"; std::cin>> *(array + i);
    }
    print(array, tam);

    quickSort(array, 0, tam);

    print(array, tam);

    delete [] array;
    return 0; 

}