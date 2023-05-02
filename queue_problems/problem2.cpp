/// @author : Rana Essam
/// @created on 4/20/2023.
/// @purpose: problem 2 Queue solution
/// @description:  designing a stack that supports push and pop operations using
/// the enqueue and dequeue operations of the queue

#include "../queue/queue.cpp"

class Stack{
private:
    Queue<int>q;
public:
    void push(int n){
        int sz = q.queueSize();
        q.enqueue(n);
        while(sz--){
            q.enqueue(q.dequeue());
        }
    }
    int pop(){
        return q.dequeue();
    }
};


int main(){
   Stack s;
   s.push(5);
   s.push(4);
   s.push(1);
   int n = 3;
   while(n--){
       cout << s.pop() <<" ";
   }
}