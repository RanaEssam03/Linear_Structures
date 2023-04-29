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
    node<T>* getHead(){
        return head;
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
    void sortedInsertion(T data){
        if (isEmpty() || data < head->info){
            insertAtHead(data);
        }
        else{
            node<T>* newNode = new node<T>(data);
            node<T>* current = head;
            while (current->next != nullptr && current->next->info < data){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    void removeAtHead(){
        if (isEmpty()){
            cout << "List is already empty!" << "\n";
            return;
        }
        node<T>* temp = head;
        head = head->next;
        free(temp);
        size--;
    }
    void removeAtTail(){
        if (isEmpty()){
            cout << "List is already empty!" << "\n";
        }
        node<T>* current = head;
        while (current->next != tail){
            current = current->next;
        }
        node<T>* temp = current->next;
        current->next = nullptr;
        tail = current;
        free(temp);
        size--;
    }
    void removeAt(int index){
        if (index == 0){
            removeAtHead();
        }
        else if (index == size -1){
            removeAtTail();
        }
        else if (index >= size){
            cout << "Out of bounds!" << "\n";
        }
        else{
            node<T>* current = head;
            int i=0;
            while (current != nullptr && i < index-1){
                current = current->next;
                i++;
            }
            node<T>* temp = current->next;
            current->next = temp->next;
            free(temp);
            size--;
        }
    }
    T retrieveAt(int index){
        try{
            if (index == 0){
                return head->info;
            }
            else if (index == size -1){
                return tail->info;
            }
            else if (index >= size || index < 0){
                throw index;
            }
            else{
                node<T>* current = head;
                int i=0;
                while (i < index){
                    current = current->next;
                    i++;
                }
                return current->info;
            }
        }
        catch (int index){
            cout << "index: " << index << " is out of bounds!" << "\n";
        }
    }
    void replaceAt(int index, T data){
        if (index == 0){
            head->info = data;
        }
        else if (index == size -1){
            tail->info = data;
        }
        else if (index >= size){
            cout << "Out of bounds!" << "\n";
        }
        else{
            node<T>* current = head;
            int i=0;
            while (i < index){
                current = current->next;
                i++;
            }
            current->info = data;
        }
    }
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
    bool isItemAtEqual(int index, T data){
        if (index >= size){
            cout << "Out of bounds!" << "\n";
            return false;
        }
        else{
            node<T>* current = head;
            int i=0;
            while (current != nullptr && i < index){
                current = current->next;
                i++;
            }
            if (current->info == data && i == index){
                return true;
            }
            else{
                return false;
            }
        }
    }
    void swapNodes(int index1, int index2) {
        if (index1 >= size || index2 >= size || index1 < 0 || index2 < 0) {
            cout << "Out of bounds!" << endl;
            return;
        }
        if (index1 == index2){
            return;
        }
        if (index1 > index2){
            swap(index1, index2);
        }
        if (index1 == index2-1){
            int i=0;
            node<T>* node1 = head;
            while (i < index1){
                node1 = node1->next;
                i++;
            }
            swap(node1->info, node1->next->info);
            return;
        }
        if (index1 == 0 && index2 != size-1){
            int i=0;
            node<T>* prevIndex2 = head;
            while (i < index2-1){
                prevIndex2 = prevIndex2->next;
                i++;
            }
            node<T>* node1 = head;
            node<T>* node2 = prevIndex2->next;
            node<T>* node1next = node1->next;
            node<T>* node2next = node2->next;
            node1->next = node2next;
            node2->next = node1next;
            prevIndex2->next = node1;
            head = node2;
            return;
        }
        if (index1 == 0 && index2 == size-1){
            int i=0;
            node<T>* prevIndex2 = head;
            while (i < index2-1){
                prevIndex2 = prevIndex2->next;
                i++;
            }
            node<T>* node1 = head;
            node<T>* node2 = tail;
            node<T>* node1next = head->next;
            node1->next = nullptr;
            node2->next = node1next;
            prevIndex2->next = node1;
            head = node2;
            tail = node1;
            return;
        }
        if (index1 != 0 && index2 == size-1){
            int i=0, j=0;
            node<T>* prevIndex1 = head;
            while (i < index1-1){
                prevIndex1 = prevIndex1->next;
                i++;
            }
            node<T>* prevIndex2 = head;
            while (j < index2-1){
                prevIndex2 = prevIndex2->next;
                j++;
            }
            node<T>* node1 = prevIndex1->next;
            node<T>* node2 = prevIndex2->next;
            node<T>* node1Next = node1->next;
            node<T>* node2Next = node2->next;
            node1->next = node2Next;
            node2->next = node1Next;
            prevIndex1->next = node2;
            prevIndex2->next = node1;
            tail = node1;
            return;
        }
        int i=0, j=0;
        node<T>* prevIndex1 = head;
        node<T>* prevIndex2 = head;
        while (i < index1-1){
            prevIndex1 = prevIndex1->next;
            i++;
        }
        while (j < index2-1){
            prevIndex2 = prevIndex2->next;
            j++;
        }
        node<T>* node1 = prevIndex1->next;
        node<T>* node2 = prevIndex2->next;
        node<T>* node1Next = node1->next;
        node<T>* node2Next = node2->next;
        node1->next = node2Next;
        node2->next = node1Next;
        prevIndex1->next = node2;
        prevIndex2->next = node1;
    }
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
        while (head != nullptr){
            node<T>* temp = head;
            head = head->next;
            free(temp);
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
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