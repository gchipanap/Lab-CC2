#include <iostream> 


void swap(int &a, int &b)
{
    int s = a;
    a =b;
    b = s;
}

void Sort(int* const array, int tam)                         // 23-1-54-2-5, 1-23-54-2-5, 1-2-54-23-5
{
    int* arr = array;
    for(int i=0; i<tam; i++)
    {
        int* min = arr;
        int* arr2 = arr+1;
        for(int j = i+1; j<tam; j++)
        {
            if(*arr2 < *min)
                min = arr2;
            ++arr2;
        }
        swap(*min, *arr);
        ++arr;
    }
} 

void print(int* array, int tam)
{
    for(int i=0; i<tam;i++)
    {
        std::cout<<*(array+i) << ' ';
    }
    std::cout<<std::endl;
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
    Sort(array, tam);
    print(array, tam);

    delete [] array;
    return 0; 
}