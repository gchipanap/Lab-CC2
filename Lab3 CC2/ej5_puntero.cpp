#include <iostream>
int tamR(const char* a)
{
    if(*a != '\0')
        return tamR(++a) + 1;
    else
        return 0;     
}
void print( char* array, int tam)
{
    for(int i=0; i<tam;i++)
    {
        std::cout<<*(array+i) << ' ';
    }
    std::cout<<std::endl;
}
void concatenar(char* a, char* b)
{
    while(*a != '\0')
        a++;
    while(*b != '\0')
    {    *a = *b;
        ++a; ++b;}
}

int main()
{ 
    char a[64];
    char b[64];
    std::cin>>a;
    std::cin>>b;
    concatenar(a,b);
    int tam = tamR(a);
    print(a, tam);
    return 0;
}