#ifndef LIST_ENLAZADA_H
#define LIST_ENLAZADA_H

template <typename T>
class Node {
    private:
        Node<T> *next;
        T elem;
    public:
        Node(Node<T> *next, T);
        Node<T>* getNext();
        T getElem();
        const Node<T>* getNext() const;
        const T getElem() const;
        void setNext(Node<T>*);
        void setElem(T);
};

template <typename CRTP, typename T>
class IIterator
{
public:
    // Virtuales puros porque TIENEN que implementar estos metodos SI O SI
    //cRtp clase heredada y T del value :v
    explicit IIterator(T* ptr = nullptr) : actualpointer {ptr} {} //inicializacion uniforme para evitar la casteacion :v implicita
    IIterator(const IIterator<CRTP, T>& a) : actualpointer {a.actualpointer} {}
    virtual ~IIterator() {}

    bool operator==(const IIterator<CRTP, T>& o) { return actualpointer == o.actualpointer; }
    bool operator!=(const IIterator<CRTP, T>& o) { return actualpointer != o.actualpointer; }
    T& operator*() { return *actualpointer; } //para iteraadores no constantes
    const T& operator*() const { return *actualpointer; } //para iteradores constantes

    virtual CRTP& operator=(const CRTP& o) = 0;
    // este es prefijo p
    virtual CRTP& operator++() = 0; // ++it
    // este es posfijo p   
    virtual CRTP operator++(int) = 0; // it++
    virtual CRTP operator+(unsigned int desplazamiento) = 0;

protected:
    T* actualpointer;
};

template <typename T>
class LinkedList {
    private:
        int size;
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
    public:
        class Iterator : public IIterator<Iterator, Node<T>>
        {
        public:
            explicit Iterator(Node<T>* ptr = nullptr) : IIterator{ptr} {} //explicit para llamar explicitamente el constructor
            Iterator(const Iterator& a) : IIterator{a} {}
            virtual ~Iterator() {}

            virtual Iterator& operator=(const Iterator& o) ;

            virtual Iterator& operator++(); // prefijo
            virtual Iterator operator++(int); // posfijo 
            virtual Iterator operator+(unsigned int offset);
        };
    public:
        LinkedList();
        LinkedList(int, Node<T> *head);
        ~LinkedList();

        void remove(T);
        void print();
        void insert(T);
        Iterator begin();
        Iterator end();
};  

#include "listEnlazada.inl"

#endif
