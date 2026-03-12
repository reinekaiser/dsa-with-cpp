#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class QueueList {
    Node* head;
    Node* tail;

public:
    QueueList(){
        head = tail = NULL;
    }

    void push(int x){
        Node* newNode = new Node(x);
        if (head == NULL){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop(){
        if (head == NULL)
            return;
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int front(){
        if (head == NULL){
            cout << "Empty queue!\n";
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){
    QueueList qll;
    qll.push(1);
    qll.push(2);
    qll.push(3);

    while(!qll.empty()){
        cout << qll.front() << " ";
        qll.pop();
    }

    cout<<endl;

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout<<endl;
    
    return 0;
}