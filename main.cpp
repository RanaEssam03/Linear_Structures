//
// Created by Rana Essam on 3/31/2023.
//

#include <iostream>
#include "circular_linked_list.cpp"

using namespace std;



int main(){
    CircularLinkedList<int> cll;
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.insertAt(5, 3);
    cout << cll.retrieveAt(3) << '\n';
    cout << cll.isExist(7) << '\n';
    cout << cll.isItemEqualAt(7, 3) << '\n';
    cll.replaceAt(7, 3);
    cout << cll.isExist(7) << '\n';
    cout << cll.isItemEqualAt(7, 3) << '\n';
    cll.print();
    cll.swap(0, 4);
    cll.print();
    cll.removeAtEnd();
    cll.print();
    cll.removeAtHead();
    cll.print();
    cll.removeAt(1);
    cll.removeAt(1);
    cll.removeAt(1);
    cll.removeAt(0);
    cll.print();
    cout << cll.isEmpty() << '\n';
    cll.insertAtEnd(0);
    cout << cll.isEmpty() << '\n';
    cll.clear();
    cll.print();
    return 0;
}
