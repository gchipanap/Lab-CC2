//.inl para definir las declaraciones inline
template <typename T>
inline Node<T>::Node(Node<T> *next, T elem)
{
    this->elem = elem; //constructor donde inicializa en elem
    this->next = next; 
}

template <typename T>
inline Node<T>* Node<T>::getNext() {return next;}

template <typename T>
inline T Node<T>::getElem() {return elem;}

template <typename T>
inline const Node<T>* Node<T>::getNext() const {return next;}

template <typename T>
inline const T Node<T>::getElem() const {return elem;}

template <typename T>
inline void Node<T>::setNext(Node* next) {this->next = next;}

template <typename T>
inline void Node<T>::setElem(T elem) {this->elem = elem;}

template <typename T>
inline LinkedList<T>::LinkedList()
{
    this->size = 0; 
    this->head = nullptr;
}

template <typename T>
inline LinkedList<T>::~LinkedList()
{
    if(head != nullptr)
    {
        Node<T>* tmp = head;
        Node<T>* del = nullptr;
        while(tmp->getNext() != nullptr)
        {
            del = tmp;
            tmp = tmp->getNext();
            delete del;
        }
        delete tmp;
        head = nullptr;
    }
}

template <typename T>
inline void LinkedList<T>::insert(T n){
    Node<T>* newNode = new Node<T> {nullptr, n};
    if ( this->head == nullptr) //cuando un linkedlist esta en nada
    {
        head = newNode;  //inicializamos la cabeza en el node n
    }
    else if ( n < head->getElem())
    { 
        //primer valor para un link list 
        newNode->setNext(head);
        head = newNode;
    }
    else 
    {
        Node<T>* tmp = head;
        while (tmp->getNext() != nullptr && tmp->getNext()->getElem() < n) //hacemos este bucle para ingresar el valor indicado n en la posicion adecuada, entonces mientra el nodo que recorremos sea menor al nodo ingresar corre el bucle y cuando encontramos el mayor sale, y se ingresa el nodo
            tmp = tmp->getNext(); //avanzamos al siguiente nodo
        if(tmp->getNext() != nullptr)
            newNode->setNext(tmp->getNext());
        tmp->setNext(newNode);
    }
    ++size;
}

template <typename T>
inline void LinkedList<T>::remove(T n)
{
    Node<T>* tmp = head;
    if (tmp->getElem() == n) {  //primer elemento
        head = tmp->getNext();
        delete tmp;
        --size;
    }
    else {
        Node<T>* pre;
        while(tmp1->getNext() != nullptr) {
            pre = tmp;
            tmp = tmp->getNext();
            if (tmp->getElem() == n) {
                pre->setNext(tmp->getNext());
                delete tmp;
                --size;
                return;
            }
        }
    }
}

template <typename T>
inline void LinkedList<T>::print()
{
    if(head == nullptr) //por si est vcio
        return;

    Node<T>* tmp = head;
    do{
        std::cout<< tmp->getElem() <<std::endl;
        tmp = tmp->getNext();
        continue;
    }
    while( tmp != nullptr);
}

template <typename T>
inline typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator=(const Iterator& o) //LinkedList<T>::Iterator& es un tipo dentro de otro tipo xd
{
    actualpointer = o.actualpointer;
    return *this; //referencia al iterador actual
}

template <typename T>
inline typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
    actualpointer = actualpointer->getNext();
    return *this;
}

template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int)
{
    LinkedList<T>::Iterator A {*this};
    ++(*this);   //incrementar el iterador , no ++this porque incremento el puntero, Gabriela no modifiques esto >:v 
    return A;
}

template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator+(unsigned int offset)
{
    int i = 0; 
    while(i < offset)
    {
        ++(*this);
        ++i;
    }
    return *this;  //desreferenciacion 
}

template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return LinkedList<T>::Iterator{head}; // Si el constructor no fuera explicito, return head; funcionaria xd 
}

template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    /*
    Node<T>* newNode = head;
    while(newNode != nullptr)
    {
        newNode = newNode->getNext();
    }
    return LinkedList<T>::Iterator{newNode};
    */
    return LinkedList<T>::Iterator{nullptr};
}
