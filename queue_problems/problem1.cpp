/// @Author : Rana Essam
/// @Created on 4/20/2023.
/// @Purpose: problem 1 Queue solution
/// @Description: generating binary numbers from 1 to N using queue


#include "..\queue.cpp"

using namespace std;

class Problem1Queue{
public:
    void solve(){
        int n;
        cout << "Please enter a number: ";
        cin >> n;
        generateNums(n);
    }
    static void generateNums(int n){
        Queue<string> q;
        int cnt;
        bool even = false;
        if (n & 1) {
            cnt = (n + 1) / 2;
        } else {
            even = true;
            cnt = n / 2 + 1;
        }

        while (cnt--) {
            if (q.isEmpty()) {
                q.enqueue("0");
                q.enqueue("1");
            } else {
                q.enqueue(q.first() + '0');
                if (even && cnt == 0) {
                    q.dequeue();
                    break;
                }
                q.enqueue(q.first() + '1');
            }
            cout << q.dequeue() << " ";
        }
        while (!q.isEmpty()) {
            cout << q.dequeue() << " ";
        }
    }
};

//int main() {
//    Problem1Queue p;
//    p.solve();
//}
