#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int x){
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = start + ((end-start)/2);
        if(a[mid] == x){
            return mid;
        }
        else if(x < a[mid]){
            end = mid - 1;
        }
        else if(x > a[mid]){
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int flag = binarySearch(a, 10, 3);
    if(flag != -1){
        cout<< "Found x at: " << flag+1;
    } else{
        cout<< "X Not found";
    }
    return 0;
}