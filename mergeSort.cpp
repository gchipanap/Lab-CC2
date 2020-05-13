#include <iostream> 
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

void merge (int* array, int start, int med, int end)
{
    int narr1[med-start+1];
    int narr2[end - med];

    for(int i =0; i < med-start+1; i++) 
        narr1[i] = array[start+i];
    for(int i = 0; i < end-med; i++)
        narr2[i] = array[med + 1 + i];
    
    int i =0;
    int j=0;
    int piv = start;
    while ( i < med-start+1 && j< end-med)
    {
        if (narr1[i] <= narr2[j])
        {
            array[piv] = narr1[i];
            i++;
        }
        else {
            array[piv] = narr2[j];
            j++;
        }
        piv++;
    }
    
    while(i < med-start+1 ) 
    {
        array [piv] = narr1[i];
        i++; piv++;
    }

    while(j < end-med)
    {
        array[piv] = narr2[j];
        j++; piv++;
    }
}

void mergeSort(int array[], int start, int end)
{
    if(start < end)
    {
        int med = start + (end-1) / 2;

        mergeSort(array, start, med);
        mergeSort(array, med + 1, end);

        merge(array, start, med, end);
    }
    print(array, end);
}

int main ()
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
    mergeSort(array, tam, 9);
    return 0;
}   