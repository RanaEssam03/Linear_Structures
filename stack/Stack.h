/// @author Rana Essam
/// @date date description at  4/9/2023.
/// @brief this file contains the declaration of Stack methods

#ifndef LINEAR_STRUCTURES_STACK_H
#define LINEAR_STRUCTURES_STACK_H

#include "../single_linked_list/single_linked_list.cpp"

template<class T>
class Stack {
    SingleLinkedList<T> list;
    int cnt;
public:
    Stack() {
        cnt = 0;
    }

    void push(T element);

    void pop();

    T top();

    bool isEmpty();

    int stackSize();

    void clear();

    void print();
};


#endif //LINEAR_STRUCTURES_STACK_H
