#ifndef NODE
#define NODE

template<typename T>
struct node{
    T info;
    node<T>* next;
    node(){
        next = nullptr;
    }
    node(T data){
        info = data;
        next = nullptr;
    }
};


template <typename T>
struct Node{
    T value;
    Node<T>* next;
    Node<T>* previous;
    Node(){
        next = nullptr;
        previous = nullptr;
    }
};

#endif