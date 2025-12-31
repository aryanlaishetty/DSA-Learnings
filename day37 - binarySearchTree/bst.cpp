#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) { //TC=O(n)
    if(root == NULL) {  //naya value sirf root ke null hone pe insert hoga 
        root = new Node(val);
        return root;
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int i=0; i<arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

bool search(Node* root, int key) {
    if(root == NULL) {  //key not found
        return false;
    }

    if(root->data == key) {  //key found
        return true;
    }

    if(key < root->data) {  //search in left subtree 
        return search(root->left, key);
    } else {                //search in right subtree
        return search(root->right, key);    
    }
}

int main() {
    vector<int> arr = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr);
    inOrderTraversal(root);
    cout<<endl;


    cout<<search(root, 2)<<endl;
    cout<<search(root, 6)<<endl;

    

    return 0;
}