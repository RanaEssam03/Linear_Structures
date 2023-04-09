//
// Created by Rana Essam on 4/9/2023.
//

#ifndef LINEAR_STRUCTURES_STACK_H
#define LINEAR_STRUCTURES_STACK_H


class Stack {
public:
    Stack();
    void push(int element);
    void pop();
    int top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};


#endif //LINEAR_STRUCTURES_STACK_H
