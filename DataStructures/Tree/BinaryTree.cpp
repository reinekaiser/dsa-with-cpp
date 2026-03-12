#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void printArr(vector<int> arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        if (i == n-1){
            cout << arr[i];
        }
        else {
            cout << arr[i] << "->";
        }
    }
    cout <<endl;
}

static int idx = -1;
Node* buildTree(vector<int> preorder){
    ++idx;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

//preOrder: root -> left - right
void preOrder(Node* root){
    if (root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

    return;
}

//inOrder: left -> root -> right
void inOrder(Node* root){
    if (root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

    return;
}

//postOrder: left -> right -> root
void postOrder(Node* root){
    if (root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

    return;
}

//levelOrder
void levelOrder(Node* root){
    if (root == NULL){
        return;
    }
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL){
            q.push(curr->left);
        }
        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
}

int height(Node* root){
    if (root == NULL)
        return -1;
    
    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height) +1;
}


int count(Node* root){
    if (root == NULL)
        return 0;
    int c_left = count(root->left);
    int c_right = count(root->right);

    return c_left+c_right+1;
}

int sum(Node* root){
    if (root == NULL)
        return 0;
    int s_left = sum(root->left);
    int s_right = sum(root->right);
    
    return s_left+s_right+root->data;
}

bool isIdenticalTree(Node* root1, Node* root2){
    if (root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    bool isValSame = root1->data == root2->data;
    bool isLeftSame = isIdenticalTree(root1->left, root2->left);
    bool isRightSame = isIdenticalTree(root1->right, root2->right);

    return isLeftSame && isRightSame && isValSame;
}

bool isSubtree(Node* root, Node* subRoot){
    if (root ==NULL || subRoot ==NULL){
        return root==subRoot;
    }

    if(root->data == subRoot->data && isIdenticalTree(root, subRoot)){
        return true;
    }

    bool isLeftSame = isSubtree(root->left, subRoot);
    bool isRightSame = isIdenticalTree(root->right, subRoot);

    return isLeftSame || isRightSame;
}

void allPaths(Node* root, string path, vector<string>& ans){
    if (root->left == NULL && root->right == NULL){
        ans.push_back(path);
        return;
    }
    if(root->left){
        allPaths(root->left, path + "->"+ to_string(root->left->data), ans);
    }
    if(root->right){
        allPaths(root->right, path + "->"+ to_string(root->right->data), ans);
    }
}

vector<int> longestPath(Node* root){
    if (root==NULL)
        return {};

    vector<int> leftpath = longestPath(root->left);
    vector<int> rightpath = longestPath(root->right);

    if (leftpath.size() > rightpath.size()){
        leftpath.insert(leftpath.begin(), root->data);
        return leftpath;
    }
    else{
        rightpath.insert(rightpath.begin(), root->data);
        return rightpath;
    }
}




int main(){
    vector<int> preorder = { 1, 2, -1, -1, 3, 4, -1, -1, 5, 6, -1, -1, -1};
    vector<string> ans;
    Node* tree = buildTree(preorder);

    preOrder(tree);
    cout << endl;

    inOrder(tree);
    cout << endl;

    postOrder(tree);
    cout << endl;

    levelOrder(tree);
    cout << endl;

    cout << "Heigh of the tree = " << height(tree) << endl;
    cout << "Number of nodes = " << count(tree) << endl;
    cout << "Sum of nodes = " << sum(tree) << endl;
    
    cout << "All paths: \n";
    allPaths(tree, to_string(tree->data), ans);
    for (int i = 0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }

    cout << "Longest paths: \n";
    printArr(longestPath(tree));

    cout << endl;
    return 0;
}