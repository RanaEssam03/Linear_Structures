// @nooreyad Noor Eyad
// Created at: 8/4/2023

#include <iostream>
#include "Node.cpp"

#ifndef SNGL_LNKD_LST
#define SNGL_LNKD_LST

using namespace std;

template<typename T>
class SingleLinkedList{
private:
    node<T>* head;
    node<T>* tail;
    int size;
public:
    SingleLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insertAtHead(T data){
        node<T>* newNode = new node<T>(data);
        if (isEmpty()){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(T data){
        node<T>* newNode = new node<T>(data);
        if (isEmpty()){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAt(int index, T data){
        if (index == 0){
            insertAtHead(data);
        }
        else if (index == size -1){
            insertAtTail(data);
        }
        else if (index >= size){
            cout << "Out of bounds!" << "\n";
        }
        else{
            node<T>* newNode = new node<T>(data);
            node<T>* current = head;
            int i=0;
            while (current != nullptr && i < index-1){
                current = current->next;
                i++;
            }
            node<T>* temp = current->next;
            current->next = newNode;
            newNode->next = temp;
            size++;
        }
    }
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(int index, T data);
    bool isExist(T data){
        node<T>* current = head;
        while (current != nullptr){
            if (current->info == data){
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool isItemAtEqual(int index, T data);
    void swap(int index1, int index2);
    bool isEmpty(){
        if (head == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    int Size(){
        return size;
    }
    void clear(){
        node<T>* current = head;
        while (current != nullptr){
            node<T>* temp = current;
            current = current->next;
            free(temp);
        }
    }
    void print(){
        if (head == nullptr){
            cout << "List is empty!" << "\n";
            return;
        }
        node<T>* current = head;
        while (current != nullptr){
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif