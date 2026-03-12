#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    // int len = 0;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
        // len++;
    }
    
    int pop() {
        int res = 0;
        if(q1.empty()){
            while(!q2.empty()){
                if(q2.size() == 1){
                    res = q2.front();
                    q2.pop();
                    break;
                }
                q1.push(q2.front());
                q2.pop();
                
            }
        }
        else{
            while(!q1.empty()){
                if(q1.size() == 1){
                    res = q1.front();
                    q1.pop();
                    break;
                }
                q2.push(q1.front());
                q1.pop();
            }
        }
        return res;
    }
    
    int top() {
        // int temp = len;
        int res = 0;
        if(q1.empty()){
            while(!q2.empty()){
                if(q2.size() == 1){
                    res = q2.front();
                    // break;
                }
                q1.push(q2.front());
                q2.pop();
                
            }
        }
        else{
            while(!q1.empty()){
                if(q1.size() == 1){
                    res = q1.front();
                    // break;
                }
                q2.push(q1.front());
                q1.pop();
            }
        }
        return res;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */