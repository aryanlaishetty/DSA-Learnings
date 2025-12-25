#include<iostream>
#include<vector>
#include<queue>
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

static int idx = -1;    //Important - recusion calls cannot override/change this as it is static variable

Node* buildTree(vector<int> nodes) {    //TC: O(n), as the recursion is based on vector traversal linearly
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void preOrderTraversal(Node* root) {    //TC : O(n), n = no. of nodes
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {    //TC : O(n), n = no. of nodes
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {    //TC : O(n), n = no. of nodes
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root) {  //TC : O(n), n = no. of nodes
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout<<endl;
}

void levelOrderTraversal2(Node* root) { //TC : O(n), n = no. of nodes
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {
            cout<<endl;
            if(q.empty()) {
                break;
            }
            q.push(NULL);
        } else {
            cout<<curr->data<<" ";

            if(curr->left != NULL) {
                q.push(curr->left);
            }
            
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;

    return currHt;
}

int count(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount+rightCount+1;
}

int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

int diameter1(Node* root) {     //TC : O(n*n)
    if(root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diameter1(root->left);
    int rightDiam = diameter1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

pair<int, int> diameter2(Node* root) {  //TC : O(n)
    if(root == NULL) {
        return make_pair(0,0);
    }

    //(diameter, height)
    pair<int, int> leftInfo = diameter2(root->left);    //(LD, LH)
    pair<int, int> rightInfo = diameter2(root->right);    //(RD, RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, leftInfo.second));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if(root == NULL && subRoot == NULL) {
        return true;
    } else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot->data) {
        if(isIdentical(root, subRoot)) {
            return true;
        }
    }

    bool isLeftSubtree = isSubtree(root->left, subRoot);

    if(!isLeftSubtree) {
        return isSubtree(root->right, subRoot);
    }

    return true;
}


int main() {
    vector<int> nodesData = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodesData);
    cout<<"Root Node = "<<root->data<<endl;

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);
    cout<<"SubRoot Node = "<<subRoot->data<<endl;

    cout<<"PreOrderTraversal: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"InOrderTraversal: ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"PostOrderTraversal: ";
    postOrderTraversal(root);
    cout<<endl;
    cout<<"LevelOrderTraversal: ";
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"LevelOrderTraversal2: "<<endl;
    levelOrderTraversal2(root);
    cout<<endl;
    cout<<"Height = "<<height(root)<<endl;
    cout<<"Count = "<<count(root)<<endl;
    cout<<"Sum = "<<sum(root)<<endl;
    cout<<"Diameter = "<<diameter1(root)<<endl;
    cout<<"Diameter = "<<diameter2(root).first<<endl;
    cout<<"Is Subtree = "<<isSubtree(root, subRoot)<<endl;


    return 0;
}