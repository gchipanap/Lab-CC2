#include <iostream>
void swap(char &a, char &b)
{
    char s = a;
    a =b;
    b = s;
}

void copy(char A[], char B[])
{
    for(int i=0; i<20; i++)
    {
        swap(A[i], B[i]);
    }
}

int main()
{
    char a[20];
    char b[20];
    std::cout<<"Escriba la cadena a: "<< std::endl; std::cin>>a;
    std::cout<<"Escriba la cadena b: "<< std::endl; std::cin>>b;
    copy(a, b);
    std::cout<<b;
    return 0;
}
