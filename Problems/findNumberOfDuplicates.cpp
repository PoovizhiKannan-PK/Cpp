#include<iostream>
using namespace std;


int numberOfDuplicated(int* a, int n, int x, bool searchStart){

    int start = 0;
    int end = n-1;
    int result = -1;
    while(end >= start){
        int mid = start + ((end-start)/2);
        if(a[mid] == x){
            result = mid;
            if (searchStart){
                end = mid -1;
            }else{
                start = mid +1;
            }
        }        
        else if(a[mid] > x){
            end = mid -1;
        }
        else{
            start = mid+1;
        }
    }
    return result;

}


int main(){
    int a[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6};
    int n = sizeof(a)/sizeof(a[0]);
    int startIndex = numberOfDuplicated(a, n, 4, true);

    if(startIndex == -1){
        cout << "Element not found";
    }
    else{
        int endIndex = numberOfDuplicated(a, n, 4, false);
        cout << "4 has " << endIndex - startIndex +1 << " duplicates";
    }


    return 0;
}