#include <iostream>

int cont_i(int array[])
{
    int num = 0;
    while(array[num])
    {
        num = num + 1;
    }
    return num; 
}

int cont_R(int array[], int num)
{
    if (array[num])
        return cont_R(array, num+1) + 1;
    else 
        return 0;
        
}

int main()
{
    int tam; 
    std::cout"cantidad elementos del array: ";
    std::cin>>tam; 
    int array[tam];
    for(int i=0; i<tam; i++)
    {
        std::cout<<"ingrese elemto: "; 
        std::cin>>array[i];
    }
    int cont;

    cont = cont_R(array, 0);
    std::cout<<"elementos: " << cont; 
    
    return 0;
}