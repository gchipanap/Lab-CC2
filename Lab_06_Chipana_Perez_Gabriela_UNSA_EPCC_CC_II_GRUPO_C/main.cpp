#include <iostream>
#include <string>
#include "listEnlazada.h"

struct Point{
    int x;
    int y;
    Point(int x1 = 0, int y1 = 0){ x = x1; y = y1;}
    ~Point(){}
    bool operator==(const Point& p) {return x == p.x;}
    bool operator!=(const Point& p) {return x != p.x;}
    bool operator<=(const Point& p) {return x <= p.x;}
    bool operator>=(const Point& p) {return x >= p.x;}
    bool operator<(const Point& p) {return x < p.x;}
    bool operator>(const Point& p) {return x > p.x;}
};

std::ostream& operator<<(std::ostream& o, const Point& p)
{
    o << '[' << p.x << ' ' << p.y << ']';
    return o;
}

int main()
{

    LinkedList<int> l;
    l.insert(8);
    l.insert(4);
    l.insert(6);
    l.insert(1);
    l.insert(10);
    std::cout<< "primer testeo" << std::endl;
    l.print();

    std::cout<< "segundo testeo" << std::endl;
    LinkedList<int>::Iterator i;
    i = l.begin();
    while(i != l.end())
    {
        std::cout << (*i).getElem() << std::endl;
        ++i;
    }

    std::cout<< "tercer testeo" << std::endl;
    for(const Node<int>& it : l)
    {
        std::cout << it.getElem() << std::endl;
    }

/*****************************************************/

    LinkedList<std::string> l1;
    l1.insert("Miau");
    l1.insert("miau1");
    l1.insert("Miau 2");
    
    std::cout<< "primer testeo" << std::endl;
    l1.print();

    std::cout<< "segundo testeo" << std::endl;
    LinkedList<std::string>::Iterator i1;
    i1 = l1.begin();
    while(i1 != l1.end())
    {
        std::cout << (*i1).getElem() << std::endl;
        ++i1;
    }

    std::cout<< "tercer testeo" << std::endl;
    for(const Node<std::string>& it1 : l1)
    {
        std::cout << it1.getElem() << std::endl;
    }

/*****************************************************/

    LinkedList<Point> l2;
    l2.insert({1, 4});
    l2.insert({5, 2});
    l2.insert({3, 10});
    l2.insert({10, 8});
    l2.insert({2, 3});
    
    std::cout<< "primer testeo" << std::endl;
    l2.print();

    std::cout<< "segundo testeo" << std::endl;
    LinkedList<Point>::Iterator i2;
    i2 = l2.begin();
    while(i2 != l2.end())
    {
        std::cout << (*i2).getElem() << std::endl;
        ++i2;
    }

    std::cout<< "tercer testeo" << std::endl;
    for(const Node<Point>& it2 : l2)
    {
        std::cout << it2.getElem() << std::endl;
    }

    return 0;
}
