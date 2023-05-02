//
// Created by Rana Essam on 4/9/2023.
//

#include "Stack.h"


template<class T>
void Stack<T>::push(T element) {
    list.insertAtHead(element);
    cnt++;
}

template<class T>
void Stack<T>::pop() {
    list.removeAtHead();
    if (cnt > 0) {
        cnt--;
    }
}

template<class T>
T Stack<T>::top() {
    return list.retrieveAt(0);
}


template<class T>
bool Stack<T>::isEmpty() {
    return list.isEmpty();
}


template<class T>
int Stack<T>::stackSize() {
    return cnt;
}


template<class T>
void Stack<T>::clear() {
    list.clear();
}


template<class T>
void Stack<T>::print() {
    list.print();
}
