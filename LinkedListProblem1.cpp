// author: Noor Eyad
// Date: 4/29/2023.

#include "single_linked_list.cpp"
#include <iostream>

SingleLinkedList<int> combineNodesBetweenZeros(SingleLinkedList<int> list1){
    SingleLinkedList<int> combinedList;
    node<int>* current = list1.getHead();
    while (current != nullptr){
        int sum=0;
        while (current->info != 0){
            sum += current->info;
            current = current->next;
        }
        if (sum != 0){
            combinedList.insertAtTail(sum);
        }
        current = current->next;
    }
    return combinedList;
}

int main(){
    SingleLinkedList<int> s;
    int size;
    cout << "Enter the size of the list: ";
    cin >> size;
    cout << endl;
    cout << "Enter elements: ";
    for (int i=0; i < size; i++){
        int x;
        cin >> x;
        s.insertAtTail(x);
    }
    s = combineNodesBetweenZeros(s);
    s.print();
}
