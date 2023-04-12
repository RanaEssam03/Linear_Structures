// @nooreyad Noor Eyad
// Created at: 8/4/2023

#include <iostream>

using namespace std;

#ifndef ARRY_BSD_LST
#define ARRY_BSD_LST

template<typename T>
class Array{
private:
    T* arr;
    long long capacity;
    long long  size;
public:
    Array(){
        capacity = 10;
        size = 0;
        arr = new T[capacity];
    }
    Array(int cap){
        capacity = cap;
        size = 0;
        arr = new T[capacity];
    }
    void insert(T data){
        if (!isFull()){
            arr[size++] = data;
        }
        else{
            cout << "Full capacity!" << "\n";
        }
    }
    void insertAt(int index, T data){
        if (!isFull()){
            if (index < 0 || index > size){
                cout << "Out of bounds!" << "\n";
            }
            else{
                for (int i = size; i > index; i--){
                    arr[i] = arr[i-1];
                }
                arr[index] = data;
                size++;
            }
        }
        else{
            cout << "Full capacity!" << "\n";
        }
    }
//    T retrieveAt(int index){
//        if (isEmpty()){
//            cout << "Array is empty!" << "\n";
//            return;
//        }
//        else if (index < 0 || index > size){
//            cout << "Out of bounds!" << "\n";
//            return;
//        }
//        else{
//            return arr[index];
//        }
//    }
    void removeAt(int index){
        if (isEmpty()){
            cout << "Array is empty!" << "\n";
        }
        else if (index < 0 || index > size){
            cout << "Out of bounds!" << "\n";
        }
        else{
            for (int i=index; i < size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
        }
    }
    void replaceAt(int index, T data){
        if (index < 0 || index > size){
            cout << "Out of bounds!" << "\n";
        }
        else{
            arr[index] = data;
        }
    }
    bool isItemAtEqual(int index, T data){
        if (index < 0 || index > size){
            cout << "Out of bounds!" << "\n";
            return -1;
        }
        else if (isEmpty()){
            cout << "List is empty!" << "\n";
            return -1;
        }
        else{
            if (arr[index == data]){
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == capacity;
    }
    int listSize(){
        return size;
    }
    int maxListSize(){
        return capacity;
    }
    void clear(){
        for (T* i = arr; i != arr+size; i++){
            i->~T();
        }
        size = 0;
    }
    void print(){
        for (int i=0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Array(){
        delete[] arr;
        size = 0;
    }
};

#endif