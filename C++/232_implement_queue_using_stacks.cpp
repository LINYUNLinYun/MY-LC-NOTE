#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> tail;
    stack<int> head;
    // int lenght = 0;

    MyQueue() {

    }
    
    void push(int x) {
        if(tail.empty()){
            swapStack();
        }
        tail.push(x);
        // lenght++;
    }
    
    int pop() {
        if(head.empty()){
            swapStack();
        }
        int res = head.top();
        head.pop();
        return res;
        
    }
    
    int peek() {
        if(head.empty()){
            swapStack();
        }
        int res = head.top();
        // head.pop();
        return res;
    }
    
    bool empty() {
        return tail.empty() && head.empty();
    }

    void swapStack(){
        if(tail.empty()){
            while(!head.empty()){
                tail.push(head.top());
                head.pop();
            }
        }
        else{
            while(!tail.empty()){
                head.push(tail.top());
                tail.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */