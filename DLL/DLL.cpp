/// @author Rana Essam
/// @created at 8/4/20223
/// @brief this file contains the implementation of double liked list functions (DLL)

#include "DLL.h"

/// @author Rana Essam
/// \tparam T refers to the datatype
/// \param element refers to the element that will be added to the list
template<class T>
void DLL<T>::insertAtHead(T element) {
    auto* newNode = new Node<T>();
    newNode->value = element;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    sz++;
}

/// @author Rana Essam
/// \tparam T refers to the datatype
/// \param element refers to the element that will be added
template<class T>
void DLL<T>::insertAtTail(T element) {
    auto* newNode = new Node<T>();
    newNode->value = element;
    if(head == nullptr){

        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    sz++;

}

/// @author Rana Essam
/// \tparam T refers to the datatype
/// \param element refers to the element that will be added
/// \param index refers to the index which the element will be added in it
template<class T>
void DLL<T>::insertAt(T element, int index) {
    int i = 1;
    if(index > sz){
        std::exit(-1);
    }
    else{
        if(index!= 0) {
            Node<T>*current = head;
            auto*newNode = new Node<T>();
            newNode->value = element;
            while (index != i) {
                current = current->next;
                i++;
            }
            newNode->next = current->next;
            newNode->previous = current->previous;
            if(current->next != nullptr)
                current->next->previous = newNode;
            current->next = newNode;

        }
        else{
            insertAtHead(element);
        }
    }
    sz++;
}

/// @author Rana Essam
/// \tparam T refers to the datatype
/// \param prevNode refers to the previous node which the new node will be inserted after
/// \param data
template<class T>
void DLL<T>::insertAfter(Node<T> *prevNode, int data) {
    Node<T>* current = head;
    int index=0;
    bool flag = false;
    while(current != nullptr){
        index++;
        if(current == prevNode){
            flag = true;
            break;
        }
        current = current->next;
    }
    if(!flag){
        cout << "Invalid Node!\n";
        return;
    }
    if(index==sz-1){
        insertAtTail(data);
        return;
    }
    else if (index == 0){
        insertAtHead(data);
        return;
    }
    insertAt(data, index+1);
}


template<class T>
void DLL<T>::removeAtHead() {
    Node <T>* current = head;
   if(sz == 0){
       cout << "List Is Empty !\n";
       return;
   }
    head = head->next;
   if(current->next != nullptr)
        current->next->previous= nullptr;
    sz--;
    free(current);
    if(sz==0){
        tail = nullptr;
    }
}


template<class T>
void DLL<T>::removeAtTail() {
    Node <T>* current = tail;
    tail = tail->previous;
    if(current->previous != nullptr)
        current->previous->next= nullptr;
    free(current);
    sz--;
    if(sz==0){
        head = nullptr;
    }
}

/// \author Rana Essam
/// \tparam T refers to the data type
/// \param index refers to the index which will be removed
template<class T>
void DLL<T>::removeAt(int index) {
    if(index>= sz){
        cout << "Index Out Of Range\n";
        return;
    }
    else if(index == 0){
        removeAtHead();
        return;
    }
    else if(index == sz-1){
        removeAtTail();
        return;
    }
    else{
        Node<T>* current = head;
        int cnt =0;
        while(cnt != index){
            current = current->next;
            cnt++;
        }
        Node<T>* temp = current;
        current->previous->next = temp->next;
        current->next->previous = temp->previous;
        sz--;
        free(temp);

    }

}

template<class T>
T DLL<T>::retrieveAt(int index) {
    try
    {
        if(sz == 0 || index <0 || index >=sz){
            throw(index);
        }

        Node<T> *current = head;
        int cnt = 0;
        while (cnt != index) {
            current = current->next;
            cnt++;
        }
        return current->value;

    }
    catch (int index){
        cout << "index = " << index << " is out of Range\n";
    }
}

template<class T>
void DLL<T>::replaceAt(T element, int index) {
    if(index >= sz){
        cout << "Index Out Of Range!\n";
        return;
    }
    Node<T>* current = head;
    int cnt =0;
    while(cnt != index){
        current = current->next;
        cnt++;
    }
    current->value = element;
}

template<class T>
bool DLL<T>::isExist(T element) {
    Node<T>* current = head;
    while(current != nullptr){
        if(current->value == element){
            return true;
        }
        current= current->next;
    }
    return false;
}

template<class T>
bool DLL<T>::isItemAtEqual(T element, int index) {
    if(index >= sz){
        cout << "Index Out Of Range!\n";
        return false;
    }
    Node<T>* current = head;
    int cnt =0;
    while(cnt != index){
        current = current->next;
        cnt++;
    }
    return current->value == element;
}

template<class T>
void DLL<T>::swap(int index1, int index2) {

    if(index1 >= sz || index2 >= sz || index1 <0 || index2 < 0){
        cout << "Index Out Of Range!\n";
        return;
    }
    if (index1 == index2){
        return;
    }
    Node<T>* node1 = head;
    Node<T>* node2 = head;
    int cnt =0;
    while(cnt != index1){
        node1 = node1->next;
        cnt++;
    }
    cnt =0;
    while(cnt != index2){
        node2 = node2->next;
        cnt++;
    }
    Node<T>* temp = node1;

    if(node1->next != nullptr)
        node1->next->previous = node2;
    else
        tail = node2;

    if(node2->next != nullptr)
        node2->next->previous = temp;
    else
        tail = temp;


    ::swap(node1->next, node2->next); // this is the function declared in move.h lib

    if(node2->previous != nullptr)
        node2->previous->next = temp;
    else
        head = node1;

    if(node1->previous != nullptr)
        node1->previous->next = node2;
    else
        head = node2;

    ::swap(node1->previous, node2->previous); // this is the function declared in move.h lib

}



template<class T>
void DLL<T>::reverse() {
    Node<T>* current = head;
    int c= sz;
    while(c--){
        ::swap(current->next,current->previous);
        current = current->previous;
    }
    ::swap(head,tail);
}

template<class T>
bool DLL<T>::isEmpty() {
    return sz==0;
}

template<class T>
int DLL<T>::doubleLinkedListSize() {
    return sz;
}

template<class T>
void DLL<T>::clear() {
    int tmp = sz;
    while(tmp--){
        removeAtHead();
    }
}

template<class T>
void DLL<T>::forwardTraversal() {
    Node<T>* current = head;
    while (current!= nullptr){
        cout << current->value << ' ';
        current = current -> next;
    }
    cout << endl;

}

template<class T>
void DLL<T>::backwardTraversal() {
    Node<T>* current = tail;
    while (current != nullptr){
        cout << current->value << ' ';
        current = current->previous;
    }
    cout << endl;
}

