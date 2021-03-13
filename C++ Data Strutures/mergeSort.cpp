#include <iostream>

using namespace std;

void merge(int *a, int *l, int ln, int *r, int rn){
    int i=0, j=0, k=0;

    while(i < ln && j < rn){
        if(l[i] < r[j]) a[k++] = l[i++];
        else a[k++] = r[j++];
    }

    while(i < ln){
        a[k++] = l[i++];
    }

    while(j < rn){
        a[k++] = r[j++];
    }

}

void mergesort(int *a, int n){
    int i, mid, *l, *r;
    
    if(n < 2) return;
    
    mid = n/2;
    l = new int(mid);
    r = new int(n-mid);

    for(i = 0; i < mid; i++) l[i] = a[i];
    for(i = mid; i < n ; i++) r[i-mid] = a[i];

    mergesort(l, mid);
    mergesort(r, n-mid);
    merge(a, l, mid, r, n-mid);

    free(l);
    free(r);
}


int main(){
    int a[] = {7,9,4,3,6,3,10,15,2,1,12,8,5,11};
    int n = sizeof(a)/sizeof(a[0]);

    mergesort(a, n);
    
    for(int i : a){
        cout << i << " ";
    }

    return 0;
}