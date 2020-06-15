#include <iostream>



class Node
{
    private: 
        int elem;     //elemento que guarda el nodo
        Node *next;   //el puntero del siguiente nodo. usamos la notacion node *next y no node* next porque esta ultima indicaria una lista, en cambio la anterior indica la el puntero a un nodo
    public: 
        Node(int elem, Node* next = nullptr) 
        {
            this->elem = elem; //constructor por defecto donde inicializa en elem
            this->next = next; //igual el puntero a nodo next al pasado por el usuario
        }
        int getElem(){ return elem;} 
        void setElem(int e){ this -> elem = e;}
        Node* getNext() {return next;}
        void setNext(Node* next) {this->next = next;}
        void print(){
            std::cout<< elem << std::endl;
        }
};

class LinkedList
{
private:
    int size;
    Node* head;
public:
    LinkedList(){
        this -> size = 0;
        this -> head = nullptr;
    }
    ~LinkedList(){ 
        if (head != nullptr)
        {
            Node* tmp = head;
            while(tmp->getNext() != nullptr)
            {
                tmp = tmp->getNext();
                delete head;
                head = tmp;
            }
            delete head;
        }
    }

    int getSize() { return size;}
    Node* getNode(int pos){ return head+pos;}
    Node* getNode(){return head;}
    void setSize(int n){ this-> size = n;}
    void setHead(Node* h){ this -> head = h;}
    void setNode(Node a, int pos){ *(head + pos) = a; } 

    void print()
    {
        if(head == nullptr) 
            return;
        do{
            std::cout<< head->getElem() <<std::endl;
            head = head->getNext();
            continue;
        }
        while( head != nullptr);   
    }

    void insert( int n)
    {
        Node* newNode = new Node(n);
        if ( this->head == nullptr) //cuando un linkedlist esta en nada
        {
            head = newNode;  //inicializamos la cabeza en el node n
        }

        else if ( n < head->getElem()) { 
            //primer valor para un link list 
            newNode->setNext(head);
            head = newNode; 
            }
        else 
        {
            while (head->getNext() != nullptr && head->getNext()->getElem() < n) //hacemos este bucle para ingresar el valor indicado n en la posicion adecuada, entonces mientra el nodo que recorremos sea menor al nodo ingresar corre el bucle y cuando encontramos el mayor sale, y se ingresa el nodo
                head = head->getNext(); //avanzamos al siguiente nodo
            if (head->getNext() != nullptr) 
                newNode->setNext(head->getNext());
            head->setNext( newNode);
        }
        this -> size = size +1; 
    }
    void remove(Node n)
    {
        Node* tmp = head; //en el caso haya solo un head si se elimina eliminamos toda la linked list, por lo que creamos un temporal
        if (tmp == nullptr)  // si es que esta vacio
            return;
        
        if(tmp->getElem() == n.getElem()) 
            {  //un solo elemento 
            head = tmp->getNext();
            delete tmp;
            }
        int i = 0; 
    
    
        while( getNode(i)->getElem() != n.getElem()) //3 //para descartar el nodo a borrar y avanzar en la linked list
            {  ++i; std::cout<<3;}
        //entonces sale  del bucle cuando encuentra el nodo que tenemos que borrar
        // tenemos que borrar para empezar a reemplazar los nodoso/
        while ( getNode(i)->getNext() != nullptr)
            {
                setNode( *(getNode(i+1)), i );
            }
        //actualizamos e tamanio de la linked list
        setSize(getSize() -1);
        }
};

int main()
{
    LinkedList lista;
    Node a(5, nullptr);
    lista.insert(a.getElem());
    lista.print();
    lista.insert(3); 
    lista.print();
    Node c(2, nullptr);
    lista.remove( a);
    lista.insert(c.getElem());
    lista.print();
    return 0;
}

    

