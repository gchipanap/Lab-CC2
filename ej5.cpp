#include <iostream>
using namespace std;

int cont_i(char array[])
{
    int num = 0;
    while(array[num])  //si existe el array, sumara el tamanio
    {
        num = num + 1;
    }
    return num; 
}
void insert(char A[],char B[]){
    int tam = cont_i(B);
    int a=0;
    for (int i = tam; i<20; i++)
    {     
        B[i] = A[a];        
        a = a +1;
    }
    
}

int main(){
    char a[20];
    char b[20];
    cout<<"Escriba la cadena a: "<<endl;cin>>a;
    cout<<"Escriba la cadena b: "<<endl;cin>>b;
    insert(a, b);
    cout<<"La cadena concatenada es: "<<b<<endl;
}
