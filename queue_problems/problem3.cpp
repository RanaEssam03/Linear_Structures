/// @author : Rana Essam
/// @Created on 4/20/2023.
/// @purpose: problem 3 Queue solution
/// "sorting a queue without extra space"


#include "../queue.cpp"

class Problem3Queue {
public:
    void solve() {
        Queue<int> q;
        q.enqueue(9);   // test case 2
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(1);
        sortQueue(q);
        q.print();
    }

    static void sortQueue(Queue<int> &q) {
        if (q.isEmpty()) {
            return;
        }
        int temp = q.dequeue();
        int sz = q.queueSize();
        while (sz--) {
            if (q.first() < temp) {
                q.enqueue(q.dequeue());
            } else {
                q.enqueue(temp);
                temp = q.dequeue();
            }
        }
        sortQueue(q);
        q.enqueue(temp);

    }

};

//int main() {
//    Problem3Queue p;
//    p.solve();
//}



///_____________________________
//    q.enqueue(3); // test case1
//    q.enqueue(15);
//    q.enqueue(2);
//    q.enqueue(4);