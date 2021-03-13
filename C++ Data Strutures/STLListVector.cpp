#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main(){
    vector<double> v;
    vector<char> ch = {'a', 'b', 'c', 'd'};
    list<double> l;
    list<double>::iterator i;

    std:string str = "";
    int j =0;
    cout<< "Vector: ";
    for(vector<char>::iterator i = ch.begin(); i != ch.end(); i++){
        cout << *i << " ";
        str.append(1, *i);
        j++;
        //cout << *i << " " << str;
    }

    cout << "\nstr: " << str; 

    cout << "\nList: ";
    for( i = l.begin(); i != l.end(); i++){
        cout << *i << " ";
    }

    cout << "\nList without Iterator: ";
    for(int j : l){
        cout<< j << " ";
    }


    cout << "\nGo to 4th Position: ";
    int n = 5;
    i = l.begin();
    for( int j = 0; j < n-1; j++){
        ++i;
    }
    cout << *i;


    return 0;
}