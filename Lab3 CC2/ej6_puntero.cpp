#include <iostream>
int tamR(const char* a)
{
    if(*a != '\0')
        return tamR(++a) + 1;
    else
        return 0;     
}
void copy(char* a, char* b)
{
    while( *a != '\0')
    {
        *b = *a;
        ++a; ++b;
    }
}
void print( char* array, int tam)
{
    for(int i=0; i<tam;i++)
    {
        std::cout<<*(array+i) << ' ';
    }
    std::cout<<std::endl;
}
int main()
{ 
    char a[64];
    char b[64];
    std::cin>>a;
    std::cin>>b;
    copy(a,b);
    int tam = tamR(b);
    print(b, tam);
    return 0;
}