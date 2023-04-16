//
// Created by Rana Essam on 3/31/2023.
//

#include <iostream>
#include "circular_linked_list.cpp"
#include "queue.cpp"
#include "single_linked_list.cpp"
#include "array_based_list.cpp"
#include "DLL/DLL.cpp"

using namespace std;



int main(){
    Array<int> arr;
    arr.insert(3);
    arr.insertAt(1, 10);
    arr.insert(4);
    arr.insert(5);
    arr.insert(1);
    arr.print();
    arr.retrieveAt(10);
    arr.print();
    return 0;
}
