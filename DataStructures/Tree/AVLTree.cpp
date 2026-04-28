#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data, height;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root){
    if (root==NULL){
        return 0;
    }
    return root->height;
}

int balanceFactor(Node* root){
    if (root == NULL){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* x){
    Node* y = x->left;
    Node* biggerValue = y->right;

    //rotate
    y->right = x; //->left not change
    x->left = biggerValue;

    //update height
    x->height = max(getHeight(x->left), getHeight(x->right)) +1;
    y->height = max(getHeight(y->left), getHeight(y->right)) +1;

    return y;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* smallerValue = y->left;

    //rotate
    y->left = x; // ->right not change
    x->right = smallerValue;

    x->height = max(getHeight(x->left), getHeight(x->right)) +1;
    y->height = max(getHeight(y->left), getHeight(y->right)) +1;

    return y;
}

Node *insert(Node* root, int key){

    if (root == NULL){
        return new Node(key);
    }

    if (key < root->data){
        root->left = insert(root->left, key);
    } 
    else if (key > root->data){
        root->right = insert(root->right, key);
    }
    else {
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) +1;
    int balance = balanceFactor(root);

    //left heavy
    if (balance > 1){
        if (balanceFactor(root->left) >= 0){ //LL
            //xoay right
            return rightRotate(root);
        }
        else { //LR
            //xoay left
            root->left = leftRotate(root->left);
            //xoay right
            return rightRotate(root);
        }
    } 

    //right heavy
    if (balance < -1){
        if (balanceFactor(root->right) <= 0){ //RR
            //xoay left
            return leftRotate(root);
        } 
        else { //RL
            // right
            root->right = rightRotate(root->right);
            //left
            return leftRotate(root);
        }
    }

    return root;
}

Node* deleteNode(Node* root, int key){
    if (root == NULL){
        return NULL;
    }

    if (key < root->data){
        root->left = deleteNode(root->left, key);
    } else if (key > root->data){
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* curr = root->right;
            while(curr->left != NULL){
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    //after delete
    if (root == NULL){
        return NULL;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) +1;
    int balance = balanceFactor(root);

    //left heavy
    if (balance > 1){
        if (balanceFactor(root->left) >= 0){ //LL
            //xoay right
            return rightRotate(root);
        }
        else { //LR
            //xoay left
            root->left = leftRotate(root->left);
            //xoay right
            return rightRotate(root);
        }
    } 

    //right heavy
    if (balance < -1){
        if (balanceFactor(root->right) <= 0){ //RR
            //xoay left
            return leftRotate(root);
        } 
        else { //RL
            // right
            root->right = rightRotate(root->right);
            //left
            return leftRotate(root);
        }
    }

    return root;
}

void printInOrder(Node* root){
    if (root == NULL){
        return ;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
    
}

int main()
{
    Node *root = new Node(1);

    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    printInOrder(root);
    cout<< endl;

    root = deleteNode(root, 0);

    printInOrder(root);

    return 0;
}
