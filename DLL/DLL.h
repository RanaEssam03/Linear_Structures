/// @author Rana Essam
/// @created at 8/4/20223
/// @brief this file contains the declaration of double liked list functions (DLL)


#ifndef LINEAR_STRUCTURES_DLL_H
#define LINEAR_STRUCTURES_DLL_H
#include "../Node.cpp"

template <class T>

class DLL {
private:
    Node<T>* head;
    Node<T>* tail;
    int sz;

public:
    DLL(){
        head = nullptr;
        tail = nullptr;
        sz = 0;
    };

    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void insertAfter(Node<T> * prevNode, int data );
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T element, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int index1, int index2 );
    void reverse();
    bool isEmpty();
    int doubleLinkedListSize();
    void clear();
    void forwardTraversal();
    void backwardTraversal();
};


#endif //LINEAR_STRUCTURES_DLL_H
