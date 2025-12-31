#include<iostream>
#include<vector>
#include<queue>
#include<map>
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


void topView(Node* root) {
    queue<pair<Node*, int>> q;  //(node, HD)
    map<int, int> m;    //(HD, node->data)

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0) {  //HD -> add in map
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL) {
            pair<Node*, int> left = make_pair(currNode->left, currHD - 1);
            q.push(left);
        }
        
        if(currNode->right != NULL) {
            pair<Node*, int> right = make_pair(currNode->right, currHD + 1);
            q.push(right);
        }
    }

    for(auto i : m) {
        cout<<i.second<<" ";
    }
    cout<<endl;
}

void kthHelper(Node* root, int k, int currLevel) {
    if(root == NULL) {
        return;
    }

    if(currLevel == k) {
        cout<<root->data<<" ";
        return;
    }

    kthHelper(root->left, k, currLevel+1);  //left
    kthHelper(root->right, k, currLevel+1); //right
}

void kthLevel(Node* root, int k) {
    kthHelper(root, k, 1);
    cout<<endl;
    return;
}

bool rootToNodePath(Node* root, int n, vector<int> &path) {
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }

    bool isLeft = rootToNodePath(root->left, n, path);
    bool isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight) {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++,j++) {
        if(path1[i] != path2[j]) {
            break;
        }
        lca = path1[i];
    }

    return lca;
}

Node* LCA2(Node* root, int n1, int n2) {    //TC=O(n), SC=O(1)
    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dist(Node* root, int n) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if(rightDist != -1) {
        return rightDist + 1;
    }

    return -1;
}

int minDist(Node* root, int n1, int n2) {   //TC=O(n), SC=O(1)
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int KthAncestor(Node* root, int node, int k) {  //TC=O(n)
    if(root == NULL) {
        return -1;
    }

    if(root->data == node) {
        return 0;
    }

    int leftDist = KthAncestor(root->left, node, k);
    int rightDist = KthAncestor(root->right, node, k);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist : leftDist;
    if(validVal+1 == k) {
        cout<<"Kth Ancestor = "<<root->data<<endl;
    }

    return validVal+1;
}

int transform(Node* root) { //TC=O(n)
    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;

    if(root->left != NULL) {
        root->data += root->left->data;
    }
    
    if(root->right != NULL) {
        root->data += root->right->data;
    }

    return currOld;
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
    topView(root);

    cout<<"Kth Level Nodes : ";
    kthLevel(root, 3);

    cout<<"LCA = "<<LCA(root, 4, 5)<<endl;
    cout<<"LCA2 = "<<LCA2(root, 4, 5)->data<<endl;
    cout<<"Min Distance = "<<minDist(root, 4, 6)<<endl;
    
    KthAncestor(root, 6, 1);
    
    transform(root);
    levelOrderTraversal2(root);

    return 0;
}