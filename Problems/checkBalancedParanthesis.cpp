#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <char> s;
    s.push(0);
    string str;
    bool flag = true;
    cout << "Input string: ";
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if (str[i] == '{' || str[i] == '(' || str[i] == '['){
            s.push(str[i]);
        }
        else if(str[i] == '}'){
            if(s.top() == '{'){
                s.pop();
            }
            else{
                flag = false;
                break;
            }
        }
        else if(str[i] == ')'){
            if(s.top() == '('){
                s.pop();
            }
            else{
                flag = false;
                break;
            }
        }
        else if(str[i] == ']'){
            if(s.top() == '['){
                s.pop();
            }
            else{
                flag = false;
                break;
            }
        }
    }

    if(flag == true){
        cout << "balanced";
    }
    else{
        cout << "unblalanced";
    }
    return 0;
}