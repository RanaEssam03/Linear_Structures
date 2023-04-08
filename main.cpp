//
// Created by Rana Essam on 3/31/2023.
//

#include <iostream>
#include "circular_linked_list.cpp"
#include "queue.cpp"
#include "single_linked_list.cpp"

using namespace std;



int main(){
    SingleLinkedList<int> sll;
    sll.insertAtTail(3);
    sll.insertAtTail(4);
    sll.insertAtTail(5);
    sll.insertAtTail(6);
    sll.insertAtTail(7);
    sll.insertAtHead(500);
    sll.insertAtHead(400);
    sll.insertAtHead(300);
    sll.insertAtHead(200);
    sll.insertAtHead(100);
    sll.insertAt(3, 2000);
    sll.insertAt(0, 2000);
    sll.insertAt(11, 2000);
    sll.print();
    cout << sll.Size();
//    Queue<int> q;
//    q.enqueue(3);
//    q.enqueue(5);
//    cout << q.dequeue() << '\n';
//    q.enqueue(8);
//    cout << q.first() << '\n';
//    q.print();
//    cout << q.isEmpty() << '\n';
//    cout << q.queueSize() << '\n';
//    q.dequeue();
//    q.dequeue();
//    cout << q.isEmpty() << '\n';
//    cout << q.queueSize() << '\n';
    
    return 0;
}
