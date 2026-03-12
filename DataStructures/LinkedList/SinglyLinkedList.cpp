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

class List {

    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int x){
        Node* newNode = new Node(x);

        if (head == NULL){
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void push_back(int x){
        Node* newNode = new Node(x);

        if (head == NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void pop_front(){
        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    }

    void pop_back(){
        if (head == NULL)
            return;
        
        Node* current = head;
        while(current->next->next != NULL)
            current = current->next;

        current-> next = NULL;
        delete tail;
        tail = current;
    }

    void insert(int x, int pos){
        Node* newNode = new Node(x);

        if (pos < 0){
            cout << "invalid pos\n";
            return;
        }
        if (pos == 0){
            if (head == NULL){
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        } 
        else {

            int i = 0;
            Node* current = head;
            while (i != pos-1){
                if (current == NULL){
                    cout << "invalid pos\n";
                    return;
                }
                    
                current = current->next;
                i++;
            }

            newNode->next = current->next;
            current->next = newNode;

        }
    }

    int search(int key){
        Node* current = head;

        int i=0;
        while(current != NULL){
            if (current->data == key){
                return i;
            }

            current = current->next;
            i++;
        }

        return -1;
    }

    int get_middle(){
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void print_linkedlist(){
        Node* current = head;
        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    List linkedList;

    linkedList.push_front(1);
    linkedList.push_front(2);
    linkedList.push_front(3);
    linkedList.push_front(5);

    linkedList.pop_front();

    linkedList.push_back(4);

    linkedList.print_linkedlist();

    linkedList.pop_back();

    linkedList.print_linkedlist();

    linkedList.insert(3,1);
    linkedList.print_linkedlist();

    cout <<" Search for key = ";
    int key;
    cin >> key;
    cout << key << " is found at "<< linkedList.search(key) << endl;

    cout << "Middle of Linked list have data = " << linkedList.get_middle() << endl;

    return 0;
}