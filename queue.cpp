#include "circular_linked_list.cpp"
#ifndef NQUEUE
#define NQUEUE

using namespace std;

template<class T>
class Queue{
private:
    CircularLinkedList<T> lst;

public:
    Queue(){
        
    }

    void enqueue(T element){
        lst.insertAtEnd(element);
    }

    T dequeue(){
        T tmp = lst.retrieveAt(0);
        lst.removeAtHead();
        return tmp;
    }
    
    T first(){
        return lst.retrieveAt(0);
    }

    bool isEmpty(){
        return lst.isEmpty();
    }

    int queueSize(){
        return lst.circularLinkedListSize();
    }

    void print(){
        lst.print();
    }
};



#endif