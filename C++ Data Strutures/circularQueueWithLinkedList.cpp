#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* enqueue(Node* head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }
    Node* temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}

Node* dequeue(Node* head){
    Node* temp = head;
    cout << "Removed: "<<temp->data <<"\n";
    head = temp->next;
    free(temp);
    return head;

}
void display(Node* head){
    if(head == NULL) return;
    cout<< head->data << " ";
    display(head->next);
    cout <<"\n";
}

int main(){
    Node* head = NULL;
    head = enqueue(head, 10);
    head = enqueue(head, 20);
    head = enqueue(head, 30);
    display(head);
    head = dequeue(head);
    head = dequeue(head);
    display(head);
    head = enqueue(head, 40);
    head = enqueue(head, 50);
    display(head);
    return 0;
}

