#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* push(Node* top, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next  = top;
    top = temp;
    return top;
}

Node* pop(Node* top){
    if(top == NULL){
        cout << "The stack is empty";
        return top;
    }
    Node* temp = new Node();
    temp = top;
    top = temp->next;
    free(temp);
    return top;

}

void display(Node* top){
    if(top == NULL) {
        cout<< "The stack is empty";
        return;
    }
    display(top->next);
    cout<< top->data << " ";
    
}

int main(){
    Node* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = pop(top);
    top = push(top, 40);
    top = pop(top);
    top = push(top, 50);
    top = pop(top);
    top = push(top, 60);
    display(top);


    return 0;
}