#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* createBinarySearchTree(Node* root, int data){
    if (root == NULL){
        Node* temp = new Node();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else if (data <= root->data){
        root->left = createBinarySearchTree(root->left, data);
    }
    else{
        root->right = createBinarySearchTree(root->right, data);
    }
    return root;
}

void treeTraversal(Node* root, vector<int> &v){
    if(root == NULL) return;
    treeTraversal(root->left, v);
    v.push_back(root->data);
    treeTraversal(root->right, v);

}

Node* balancedTree(vector<int> &v, int start, int end){
    if(start > end) return NULL;
    int mid = start + (end-start)/2;
    Node* root = new Node();
    root->data = v[mid];
    root->left = balancedTree(v, start, mid-1);
    root->right = balancedTree(v, mid+1, end);
    return root;
}

void BFS(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data << " ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        q.pop();
    }

}


int main(){

    Node* root = NULL;
    vector <int> v;
    int a[] = {1,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    
    for(int i = 0; i < n ; i++){
        root = createBinarySearchTree(root, a[i]);
    }

    //cout << "Tree: ";
    treeTraversal(root, v);
    //BFS(root);

    root = balancedTree(v, 0, v.size()-1);
    cout << endl;
    BFS(root);

    return 0;

}