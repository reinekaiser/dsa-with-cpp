#include <iostream>

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

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int x){
        Node* newNode = new Node(x);
        if (tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int x){
        Node* newNode = new Node(x);
        if (tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead(){
        if (head == NULL)
            return;

        if (head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        tail->next = head;

        temp->next = NULL;
        delete temp;
    }

    void deleteAtTail(){
        if (head == NULL)
            return;
        if (head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        
        Node* temp = tail;
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }

        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }

    void print(){
        if (head == NULL)
            return;

        cout << head->data << " <-> ";
        Node* temp = head->next;

        while(temp != head){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }
};

int main(){

    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.insertAtTail(4);

    cll.print();

    cll.deleteAtHead();

    cll.print();

    cll.deleteAtTail();

    cll.print();
    return 0;
}