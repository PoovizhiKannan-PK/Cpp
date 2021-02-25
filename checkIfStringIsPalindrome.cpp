#include <iostream>
using namespace std;

int main (){
    bool flag = true;
    string s;
    cout << "Enter a String: ";
    cin >> s;
    int i, j;
    int len = s.length();
    for(i =0; i< len/2; i++){
        j = len -1 -i;
        if(s[i] != s[j]){
            flag = false;
            break;
        }
    }

    if(flag == true){
        cout << "It is a Palindrome";
    }else{
        cout << "Not a Palindrome";
    }

    return 0;
}