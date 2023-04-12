//
// Created by Rana Essam on 4/8/2023.
//

#ifndef LINEAR_STRUCTURES_NODE_H
#define LINEAR_STRUCTURES_NODE_H

template<typename T>
struct Node
{
    T value;
    Node<T>* next;
    Node<T>* previous;
    Node(){
        next = nullptr;
        previous = nullptr;
    }
};

#endif //LINEAR_STRUCTURES_NODE_H
