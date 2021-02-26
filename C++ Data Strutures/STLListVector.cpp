#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main(){
    vector<double> v;
    list<double> l;
    list<double>::iterator i;

    for(int i =0; i<10; i++){
        cout<< v.size() << " +1: ";
        v.push_back(i+1);
        l.push_back(i+1);
        cout<< v[i] <<endl;
    }

    cout<< "Vector: ";
    for(vector<double>::iterator i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }

    cout << "\nList: ";
    for( i = l.begin(); i != l.end(); i++){
        cout << *i << " ";
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