#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val){
    if (root == NULL){
        return new TreeNode(val); 
    }

    if ( val < root->data ){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* buildBST(vector<int> arr){
    TreeNode* root = NULL;
    for (int val : arr){
        root = insert(root, val);
    }
    return root;
}

void printInOrder(TreeNode* root){
    if (root == NULL){
        return;
    }

    printInOrder(root->left);
    cout << root->data <<" ";
    printInOrder(root->right);
}

bool search(TreeNode* root, int key){
    if (root == NULL){
        return false;
    }

    if (key < root->data){
        return search(root->left, key);
    } else if (key > root->data){
        return search(root->right, key);
    } else{
        return true;
    }
}

TreeNode* deleteNode(TreeNode* root, int val){
    if (root==NULL){
        return NULL;
    }

    if (val < root->data){
        root->left = deleteNode(root->left, val);
    }else if (val > root->data){
        root->right = deleteNode(root->right, val);
    }else {
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        } else if (root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            TreeNode* curr = root->right; //right subtree
            while(curr->left!=NULL && root !=NULL){ //left most
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    return root;
}

bool isBST(TreeNode* root, TreeNode* min, TreeNode* max){
    if (root == NULL)
        return true;
    
    if (min!=NULL && root->data <= min->data){
        return false;
    } else if (max!=NULL && root->data >= max->data){
        return false;
    }

    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    TreeNode* root = buildBST(arr);

    root = insert(root, 8);
    printInOrder(root);

    cout << endl;

    cout << search(root, 3) << endl;

    root = deleteNode(root, 3);
    printInOrder(root);
    cout << endl;


    cout << isBST(root, NULL, NULL) <<endl;

    return 0;
}