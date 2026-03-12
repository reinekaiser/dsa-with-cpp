#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!queue1.empty()){
            queue2.push(queue1.front());
            queue1.pop();
        }
        
        queue1.push(x);
        while(!queue2.empty()){
            queue1.push(queue2.front());
            queue2.pop();
        }
    }
    
    int pop() {
        int ans = queue1.front();
        queue1.pop();
        return ans;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
    }
};

int main(){
    MyStack s;
    s.push(1);
    s.push(2);
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}