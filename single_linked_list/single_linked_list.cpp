// @nooreyad Noor Eyad
// Created at: 8/4/2023

#include <iostream>
#include "../Node.cpp"

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
    void swap(int index1, int index2) {
        if (index1 >= size || index2 >= size) {
            cout << "Out of bounds!" << endl;
            return;
        }
        int i = 0, j = 0;
        node<T> *current1 = head;
        node<T> *current2 = head;
//        if (index1 == 0){
//            while (j < index2 - 1) {
//                current2 = current2->next;
//                j++;
//            }
//            node<T> *temp1 = current1->next;
//            node<T> *temp2 = current2->next;
//            node<T> *temp2_2 = temp2->next;
//            current1->next = temp2->next;
//            temp2->next = temp1;
//            temp1->next = temp2_2;
//            head = temp2;
//        }
        while (i < index1 - 1) {
            current1 = current1->next;
            i++;
        }
        while (j < index2 - 1) {
            current2 = current2->next;
            j++;
        }
        node<T>* temp1 = current1->next;
        node<T>* temp2 = current2->next;
        node<T>* temp1_1 = temp1->next;
        node<T>* temp2_2 = temp2->next;
        temp1->next = temp2_2;
        current1->next = temp2;
        temp2->next = temp1_1;
        current2->next = temp1;
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