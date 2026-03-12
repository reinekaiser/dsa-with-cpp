#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int x){
        Node* newNode = new Node(x);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int x){
        Node* newNode = new Node(x);

        if (head == NULL){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(){
        if (head == NULL){
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if (head == NULL){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;

        temp->prev = NULL;
        delete temp;
    }


    void print(){
        Node* current = head;
        while(current != NULL){
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){

    DoublyList doublyList;

    doublyList.push_front(1);
    doublyList.push_front(2);
    doublyList.push_front(3);

    doublyList.print();

    doublyList.push_back(4);

    doublyList.pop_front();

    doublyList.print();

    doublyList.pop_back();

    doublyList.print();

    

    return 0;

}