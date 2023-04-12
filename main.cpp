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
    DLL<int> list;
    list.insertAtHead(0);
    list.insertAtHead(1);
    list.insertAtTail(5);
    list.forwardTraversal();
    list.swap(0,2);
    list.forwardTraversal();
    return 0;
}
