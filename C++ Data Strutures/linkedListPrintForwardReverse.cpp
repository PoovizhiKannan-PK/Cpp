#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* insert(Node* head, int data, int n){
    Node* temp = new Node();
    temp->data = data;
    while(n==1){
        temp->next = head;
        head = temp;
        return head;
    }
    Node* temp1 = head;
    for(int i=0; i<n-2; i++){
        temp1 = temp->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return head;
}


void displayForward(Node* head){
    if(head == NULL) return;
    cout << head->data;
    displayForward(head->next);
}

void displayReverse(Node* head){
    if(head == NULL) return;
    displayReverse(head->next);
    cout << head->data;
}

int main(){
    Node* head = NULL;
    head = insert(head,2,1); //2s
    head = insert(head,3,2); //2 3
    head = insert(head,5,2); // 2 5 3
    head = insert(head,6,2); //6 2 5 3
    head = insert(head,7,1); //6 7 2 5 3
    displayForward(head);
    cout<< "\n";
    displayReverse(head);

    return 0;
}