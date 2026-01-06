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

Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }

    if(val < root->data) {  //left subtree
        root->left = deleteNode(root->left, val);
    } else if(val > root->data) {   //right subtree
        root->right = deleteNode(root->right, val);
    } else {    //root == val
    
        //case0: 0 children
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //case1: 1 child
        if(root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }

        //case2: 2 children
        Node* IS = getInorderSuccessor(root->right);    //getting IS
        root->data = IS->data;  //replace root data with IS data
        root->right = deleteNode(root->right, IS->data);    //delete IS node
        return root;
    }

    return root;
}

void printInRange(Node* root, int start, int end) {
    if(root == NULL) {
        return;
    }
    
    if(start <= root->data && root->data <= end) {
        printInRange(root->left, start, end);
        cout<<root->data<<" ";
        printInRange(root->right, start, end);
    } else if(root->data < start) {
        printInRange(root->right, start, end);
    } else {
        printInRange(root->left, start, end);
    }
}

void printPath(vector<int> path) {
    cout<<"Path: ";
    for(int i=0; i<path.size(); i++) {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void pathHelper(Node* root, vector<int> &path) {
    if(root == NULL) {
        return;
    }

    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL) { //lead
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
}

void rootToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

bool validateHelper(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->data < min->data) {
        return false;
    }

    if(max != NULL && root->data > max->data) {
        return false;
    }

    return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}


Node* buildBalancedBST(vector<int> sortedArr, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(sortedArr[mid]);

    curr->left = buildBalancedBST(sortedArr, st, mid-1);
    curr->right = buildBalancedBST(sortedArr, mid+1, end);

    return curr;
}

void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void getInorder(Node* root, vector<int> &nodes) {
    if(root == 0) {
        return;
    }

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);

}

Node* convertBalancedBST(Node* root) {   
    vector<int> nodes;
    getInorder(root, nodes);

    return buildBalancedBST(nodes, 0, nodes.size()-1);
}

Node* largestBSTinBT() {

}


Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> mergedNodes;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i=0, j=0;
    while(i<nodes1.size() && j<nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            mergedNodes.push_back(nodes1[i++]);
        } else {
            mergedNodes.push_back(nodes2[j++]);
        }
    }

    while(i<nodes1.size()) {
        mergedNodes.push_back(nodes1[i++]);
    }

    while(j<nodes2.size()) {
        mergedNodes.push_back(nodes2[j++]);
    }

    return buildBalancedBST(mergedNodes, 0, mergedNodes.size()-1);
}   

int main() {
    vector<int> arr = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr);
    inOrderTraversal(root);
    cout<<endl;


    cout<<search(root, 2)<<endl;
    cout<<search(root, 6)<<endl;

    inOrderTraversal(root);
    cout<<endl;
    deleteNode(root, 4);
    inOrderTraversal(root);
    cout<<endl;

    printInRange(root, 3, 5);
    cout<<endl;
    
    rootToLeafPath(root);

    cout<<validateBST(root)<<endl;

    vector<int> sortedArr = {3,4,5,6,7,8,9};
    Node* balancedRoot = buildBalancedBST(sortedArr, 0, sortedArr.size()-1);
    preorderTraversal(balancedRoot);
    cout<<endl;

    //-----------
    Node* root2 = new Node(6);  
    root2->left = new Node(5);  
    root2->left->left = new Node(4);  
    root2->left->left->left = new Node(3);  

    
    root2->right = new Node(7);  
    root2->right->right = new Node(8);  
    root2->right->right->right = new Node(9);

    root2 = convertBalancedBST(root2);
    preorderTraversal(root2);
    cout<<endl;
    //------------
    
    
    //------------

    //------------
    
    
    //------------
    Node* root3 = new Node(2);  
    root3->left = new Node(1);  
    root3->right = new Node(4);  

    Node* root4 = new Node(9);  
    root4->left = new Node(3); 
    root4->right = new Node(12);
    
    Node* root5 = mergeBSTs(root3, root4);
    preorderTraversal(root5);
    cout<<endl;
    //------------

    return 0;
}