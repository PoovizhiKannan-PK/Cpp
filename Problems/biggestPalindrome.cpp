#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int expandFromCenter(string str, int left, int right){
    while(left >= 0 && right < str.length() && str[left] == str[right]){
        left--;
        right++;
    }
    return right - left -1;
}

string findBiggestPalindrome(string str){
    int start = 0;
    int end = 0;
    int len1 = 0;
    int len2 = 0;
    int len = 0;
    for (int i=0; i< str.length(); i++){
        len1 = expandFromCenter(str, i, i);
        len2 = expandFromCenter(str, i, i+1);
        len = max(len1, len2);
        if (len > end - start){
            start = (len/2) - i;
            end = (len/2) + i;
        }
    }
    return str.substr(start, end+1);

}


int main(){
    string str, palindrome;
    cout << "Enter String: ";
    cin >> str;
    
    palindrome = findBiggestPalindrome(str);

    cout << "\nBiggest Palindrome: " << palindrome;

    return 0;
}