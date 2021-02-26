#include<iostream>
using namespace std;
#define Max_Length 3

class queue{
    private:
    int a[Max_Length];
    int front = -1;
    int rear = -1;
    int count = 0;

    public:
    void enqueue(int x){
        count++;
        if ((rear+1)% Max_Length == front){
            cout << "Queue is Full \n";
            return;
        }
        else if(isEmpty()){
            rear = front = 0;
        }
        else{
            rear = (rear+1) % Max_Length;
        }
        a[rear] = x;

    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty \n";
        }
        else if(front == rear){
            rear = front = -1;
        }
        else{
            cout << "Removed: " <<a[front] <<'\n';
            front = (front +1) % Max_Length;
        }
    }

    bool isEmpty(){
         return (front == -1 && rear == -1);
    }

    void display(){
        int n = (rear + Max_Length - front)%Max_Length +1;
        cout<< "List: ";
        for (int i = 0; i<n; i++){
            cout<< a[(i+front)%Max_Length] << " ";
        }
        cout << "\n";
    }

};


int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
    q.enqueue(50);
    q.display();
    return 0;
}