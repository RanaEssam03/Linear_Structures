/// @author Nour El-din Ahmed 20210430
/// @author Noor Eyad 20210499
/// @authors Rana Essam 20210133
/// @date 3/31/2023.
/// @

#include <iostream>
#include "circular_linked_list/circular_linked_list.cpp"
#include "queue/queue.cpp"
#include "single_linked_list/single_linked_list.cpp"
#include "array_based_list/array_based_list.cpp"
#include "DLL/DLL.cpp"
#include "stack/Stack.h"


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
