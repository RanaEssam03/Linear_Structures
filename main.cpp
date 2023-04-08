//
// Created by Rana Essam on 3/31/2023.
//

#include <iostream>
#include "circular_linked_list.cpp"
#include "queue.cpp"

using namespace std;



int main(){
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(5);
    cout << q.dequeue() << '\n';
    q.enqueue(8);
    cout << q.first() << '\n';
    q.print();
    cout << q.isEmpty() << '\n';
    cout << q.queueSize() << '\n';
    q.dequeue();
    q.dequeue();
    cout << q.isEmpty() << '\n';
    cout << q.queueSize() << '\n';
    
    return 0;
}
