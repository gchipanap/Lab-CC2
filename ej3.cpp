#include <iostream>

void swap(int &a, int &b)
{
    int s = a;
    a =b;
    b = s;
}


void order(int array[], int tam)
{
    
    for(int i=0; i<tam; i++)
    {
        for (int j=i+1; j<tam;j++)
        {
            if(array[j] < array[i])
            {   
                swap(array[i], array[j]);
            }
        }
    }
    
}
void print(int array[], int tam)
{
    std::cout<<"orden:" ;
    for(int i=0; i<tam; i++)
    {
        std::cout<<array[i] <<std::endl;
    }
}

int main()
{
    int tam; 
    std::cin>>tam; 
    int array[tam];
    for(int i=0; i<tam; i++)
    {
        std::cin>>array[i];
    }
    order(array, tam);
    print(array, tam);

    return 0;
}