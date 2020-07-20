#include <iostream>
#include <string>
#include <vector>


struct Point
{
    public: 
        int y;
        int x;
        Point(int x, int y);
        Point(Point&& p);
        Point(Point& p);    
        void print();
};
Point::Point(int x, int y)
{
    this -> x = x;
    this -> y = y;
}
Point::Point(Point& p)
{
    x = p.x;
    y = p.y;
}
Point::Point(Point&& p)
{
    x = p.x;
    y = p.y;
}
void Point::print()
{
    std::cout << "[" << x << ", " << y << "]" << std::endl;
}
int main ()
{
    int x; 
    char y ;
    std::string w;
    // Los 2 ejemplos anteriores son lvalue
    x = 5; 
    y =  'a';
    w = "Hola Mundo";
    // Los 3 valores que se encuentran a la derecha de las variables x y a se llaman valores literales y son Rvalue
    std::string s(std::string {"Holi bb"});
    //este es un ejemplo de move semantic ya que estamos inicializando un string s con otro string y s toma el otro string como un rvalue
    //======================================
    int a = 1; 
    char p = 'q';
    //sabemos que a es un lvalue porque es el nombre de una variable
    int& b = a;
    char& o = p;
    //B es una referencia a lvalue por hacer referencia a a
    int&& c = 8; 
    char&& i = 'Hola';
    //c es una referencia a rvalue ya que hacer referencia a 8, pero sigue siendo tambien un lvalue
    //======================================
    //primero crearemos un string
    std::string primer = "Hola mundo";
    std::cout<< primer[0] <<std::endl;
    //Luego crearemos otro string haciendo el cast del primero al rvalue para que segundo tome sus valores
    std::string segundo(std::move(primer));
    //Ahora veremos si se hizo el movimiento que deseamos que es cuando se libera la memoria de primer y todos los valores de primer pasan a segundo
    std::cout<< primer[0] <<std::endl;
    std::cout<< segundo[0] <<std::endl;
    //quedo comprobado. 
    //======================================
    Point p1(1,2);
    p1.print();
    Point p2(p1);
    p2.print();
    Point p4(Point(2,3));
    p4.print();
    //==================
    Point p3(std::move(p1));
    //usamos como constructor copia, con stD::move
    p3.print();

    return 0;

}