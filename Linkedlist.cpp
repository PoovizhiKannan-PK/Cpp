#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void display(Node* head){
    Node* temp = head;
    cout << "The list is: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node* insert(Node* head){
    int data;
    cout << "Enter data: ";
    cin >> data;
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}




int main() {
    Node* head = NULL;
    while(true){
        cout << "Get input from user: ";
        int input;
        cin >> input;
        switch(input){
            case 1:
            head = insert(head);
            break;
            case 2:
            display(head);
            break;
        }
    }

    return 0;
}