#include <iostream>
#include "circular_linked_list.cpp"
#include "queue.cpp"
#include "single_linked_list.cpp"
#include "array_based_list.cpp"
#include "DLL/DLL.cpp"

using namespace std;

void printList(node<int>* head){
    while (head != nullptr){
        cout << head->info << " ";
        head = head->next;
    }
    cout << "\n";
}

node<int>* MergeKLists(node<int>* arr[], int k){
    for (int i=1; i <= k; i++){
        while (true){
            node<int>* head0 = arr[0];
            node<int>* headI = arr[i];
            if (headI == nullptr){
                break;
            }
            if (head0->info >= headI->info){
                arr[i] = headI->next;
                headI->next = head0;
                arr[0] = headI;
            }
            else{
                while (head0->next != nullptr){
                    if (head0->next->info >= headI->info){
                        arr[i] = headI->next;
                        headI->next = head0->next;
                        head0->next = headI;
                        break;
                    }
                    head0 = head0->next;
                    if (head0->next == nullptr){
                        arr[i] = headI->next;
                        headI->next = nullptr;
                        head0->next = headI;
                        head0->next->next = nullptr;
                        break;
                    }
                }
            }
        }
    }
    return arr[0];
}

int main(){
    int k;
    cout << "Enter the number of lists: ";
    cin >> k;
    node<int>* arr[k];
    for (int i=1; i <= k; i++){
        SingleLinkedList<int> s;
        int n;
        cout << "Enter the size of the list number " << i << ":";
        cin >> n;
        cout << "Enter elements of the list number " << i << ":";
        for (int j=0; j < n; j++){
            int x; cin >> x;
            s.sortedInsertion(x);
        }
        arr[i-1] = s.getHead();
    }
    node<int>* head = MergeKLists(arr, k-1);
    printList(head);
}