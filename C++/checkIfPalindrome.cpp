#include<iostream>
using namespace std;

int invert(int x){
    int y=0;
    int rem;
    while(x != 0){
        rem = x%10;
        y = (y*10) + rem;
        x = x/10;
    }
    return y;
}


int main(){
    int x;
    cout << "Enter a number";
    cin >> x;
    int y = invert(x);

    if (x == y){
        cout << "It is a palindrome";
    }else{
        cout << "Not a palindrome";
    }

    return 0;
}