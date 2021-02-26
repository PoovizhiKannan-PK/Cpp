#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void display(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node* insert(Node* head, int data, int n){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(n==1){
        temp->next = head;
        head = temp;
        display(head);
        return head;
    }
    Node* temp1 = new Node();
    temp1 = head;
    for(int i=0; i<n-2;i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    display(head);
    return head;
}



int main(){
    Node* head = NULL;
    head = insert(head,2,1);
    head = insert(head,4,2);
    head = insert(head,5,1);
    head = insert(head,10,3);
    head = insert(head,6,2);
    
    return 0;

}