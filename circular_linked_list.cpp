// @TBK-2002 Nour El-din Ahmed
// Created at: 1/4/2023

#ifndef CRCLR_LNKD_LST
#define CRCLR_LNKD_LST

#include <iostream>
#include "Node.cpp"

using namespace std;

template<typename T>
class CircularLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    CircularLinkedList(){
        size = 0;
        head = nullptr, tail = nullptr;
    }
    void insertAtHead(T element){
        Node<T>* node = new Node<T>();
        node->value = element;
        if(head == nullptr){
            head = node;
            tail = node;
            node->next = tail;
            node->previous = head;
        }
        else{
            node->next = head;
            node->previous = tail;
            tail->next = node;
            head->previous = node;
            head = node;
        }
        size++;
    }
    void insertAtEnd(T element){
        Node<T>* node = new Node<T>();
        node->value = element;
        if(head == nullptr){
            head = node;
            tail = node;
            node->next = tail;
            node->previous = head;
        }
        else{
            node->next = head;
            node->previous = tail;
            tail->next = node;
            head->previous = node;
            tail = node;
        }
        size++;
    }
    void insertAt(T element, int index){
        if(index >= size){
            cout << "Out of bounds" << '\n';
            return;
        }
        if(index == size-1) insertAtEnd(element);
        else if(index == 0) insertAtHead(element);
        else{
            Node<T>* it = head;
            Node<T>* node = new Node<T>();
            node->value = element;
            int cnt = 0;
            while(true){
                if(cnt == index){
                    node->previous = it;
                    node->next = it->next;
                    it->next->previous = node;
                    it->next = node;
                    break;
                }
                it = it->next;
                cnt++;
            }
            size++;
        }
    }
    void removeAtHead(){
        if(size == 0) return;
        if(size == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            head->next->previous = tail;
            tail->next = head->next;
            delete head;
            head = tail->next;
        }
        size--;
    }
    void removeAtEnd(){
        if(size == 0) return;
        if(size == 1){
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else{
            tail->previous->next = head;
            head->previous = tail->previous;
            delete tail;
            tail = head->previous;
        }
        size--;
    }
    void removeAt(int index){
        if(index >= size){
            cout << "Out of bounds" << '\n';
            return;
        }
        if(index == size-1) removeAtEnd();
        else if(index == 0) removeAtHead();
        else{
            int cnt = 0;
            Node<T>* it = head;
            while(true){
                if(cnt == index){
                    it->previous->next = it->next;
                    it->next->previous = it->previous;
                    delete it;
                    break;
                }
                it = it->next;
                cnt++;
            }
            size--;
        }
    }
    T retrieveAt(int index){
        // if(index >= size){
        //     cout << "Out of bounds" << '\n';
        //     return ;
        // }

        int cnt = 0;
        Node<T>* it = head;
        while(true){
            if(cnt == index){
                return it->value;
            }
            it = it->next;
            cnt++;
        }

    }
    void replaceAt(T element,int index){
        if(index >= size){
            cout << "Out of bounds" << '\n';
            return ;
        }

        int cnt = 0;
        Node<T>* it = head;
        while(true){
            if(cnt == index){
                it->value = element;
                break;
            }
            it = it->next;
            cnt++;
        }

    }
    bool isExist(T element){
        if(size == 0) return false;
        Node<T>* it = head;
        while(true){
            if(it->value == element) return true;
            if(it == tail) break;
            it = it->next;
        }
        return false;
    }
    bool isItemEqualAt(T element, int index){
        if(index >= size){
            cout << "Out of bounds" << '\n';
            return false;
        }

        int cnt = 0;
        Node<T>* it = head;
        while(true){
            if(cnt == index){
                return it->value == element;
            }
            it = it->next;
            cnt++;
        }
    }

    void swap(int firstItemIdx, int secondItemIdx){
        if(firstItemIdx >= size || secondItemIdx >= size){
            cout << "Out of bounds" << '\n';
            return;
        }
        if(firstItemIdx == secondItemIdx) return;
        int cnt = 0;
        Node<T>* firstItemIt = nullptr;
        Node<T>* secondItemIt = nullptr;
        Node<T>* it = head;
        while(true){
            if(cnt == firstItemIdx){
                firstItemIt = it;
            }
            if(cnt == secondItemIdx){
                secondItemIt = it;
            }
            if(firstItemIt != nullptr && secondItemIt != nullptr) break;
            it = it->next;
            cnt++;
        }

        it = firstItemIt->next;
        if(firstItemIt != secondItemIt->next)
            firstItemIt->next = secondItemIt->next;
        else
            firstItemIt->next = secondItemIt;

        if(secondItemIt != it)
            secondItemIt->next = it;
        else
            secondItemIt->next = firstItemIt;

        it = firstItemIt->previous;
        if(firstItemIt != secondItemIt->previous)
            firstItemIt->previous = secondItemIt->previous;
        else
            firstItemIt->previous = secondItemIt;

        if(secondItemIt != it){
            secondItemIt->previous = it;
        }
        else{
            secondItemIt->previous = firstItemIt;
        }

        secondItemIt->previous->next = secondItemIt;
        secondItemIt->next->previous = secondItemIt;
        firstItemIt->next->previous = firstItemIt;
        firstItemIt->previous->next = firstItemIt;
        
        if(head == firstItemIt){
            head = secondItemIt;
        }
        else if(head == secondItemIt){
            head = firstItemIt;
        }
        if(tail == firstItemIt){
            tail = secondItemIt;
        }
        else if(tail == secondItemIt){
            tail = firstItemIt;
        }
    }

    bool isEmpty(){
        return size == 0;
    }

    int circularLinkedListSize(){
        return size;
    }

    void clear(){
        if(size == 0) return;
        Node<T>* it = head;
        while(--size){
            delete it->previous;
            it = it->next;
        }
        delete it;
        head = nullptr;
        tail = nullptr;
    }

    void print(){
        if(size == 0) return;
        Node<T>* it = head;
        while(true){
            cout << it->value << ' ';
            if(it == tail) break;
            it = it->next;
        }
        cout << '\n';
    }
};

#endif
