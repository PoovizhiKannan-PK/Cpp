#include<iostream>
using namespace std;
#define MAX_SIZE 101

class stack{
    private:
    int A[MAX_SIZE];
    int top;
    public:

    stack(){
        top = -1;
    }

    void push(int value){
        if(top == MAX_SIZE-1){
            cout << "Stack is full";
            return;
        }
        A[++top] = value;
    }

    void pop(){
        if (top == -1){
            cout << "Stack is empty";
            return;
        }
        cout << "Poped " << A[top--] << "\n";
    }

    void print(){
        if(top == -1){
            cout << "Stack is empty";
            return;
        }
        cout <<"Stack is: ";
        for (int i=0; i<=top; i++){
            cout << A[i] << " ";
        }
        cout << "\n";
    }

};

int main(){
    stack s;
    s.push(2);
    s.push(5);
    s.push(6);
    s.pop();
    s.pop();
    s.push(8);
    s.push(3);
    s.print();

    return 0;
}
