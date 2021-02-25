#include<iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int data){
    if(root == NULL){
        Node* temp = new Node();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        
    }
    else if(data <= root->data){
        root->left = insert(root ->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;

}

void search(Node* root, int x){
    bool flag;
    if(root == 0){
        flag = false;
    }
    else if(root-> data == x){
        flag = true;
    }
    else if(x <= root->data){
        return search(root->left, x);
        
    }
    else if(x > root->data){
        return search(root->right, x);
    }

    if(flag == true){
        cout << "FOund the Number \n";
    }else{
        cout << "Not Found \n";
    }
}

void findMinMax(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    cout << "Min Value: "<<temp->data << "\n";
    
    while(root->right != NULL){
        root = root->right;
    }
    cout << "Max Value: "<<root->data << "\n";

}

void levelOrderTraversal(Node* root){
    if (root == NULL) {
        cout<< "Empty Tree";
        return;
    }
    queue<Node*> q;
    q.push(root);

    cout << "Level Order Traversa: ";
    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
        q.pop();
    }

}


void DFSinOrderTraversal(Node* root){
    if(root == NULL) return;
    DFSinOrderTraversal(root->left);
    cout << root->data << " ";
    DFSinOrderTraversal(root->right);
}

void DFSpreOrderTraversal(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    DFSpreOrderTraversal(root->left);
    DFSpreOrderTraversal(root->right);
}

void DFSpostOrderTraversal(Node* root){
    if(root == NULL) return;
    DFSpostOrderTraversal(root->left);
    DFSpostOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* findMin(Node* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
}

Node* deleteNode(Node* root, int data){
    if(root == NULL) return root;
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    } 
    else{
        if(root->left == NULL && root->right == NULL){
            delete(root);
            root = NULL;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete(temp);
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete(temp);
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            delete(temp);
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 17);
    root = insert(root, 7);
    root = insert(root, 25);
    
    //search(root, 10);
    //search(root, 20);
    //search(root, 115);
    //search(root, 16);

    //findMinMax(root);

    //levelOrderTraversal(root);
    cout << "\nIn Order Traversal: ";
    DFSinOrderTraversal(root);
    root = deleteNode(root, 25);
    cout << "\nIn Order Traversal: ";
    DFSinOrderTraversal(root);

    //cout << "\nPre Order Traversal: ";
    //DFSpreOrderTraversal(root);

    //cout << "\nPost Order Traversal: ";
    //DFSpostOrderTraversal(root);

    return 0;
}

