#include <iostream>

using namespace std;

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int partition(int a[], int l, int r, int key){
    while (l < r)
    {
        while (a[l] < key) l++;
        while (a[r] > key) r--;
        if (l < r) {
            swap(a[l], a[r]);
            l ++;
            r --;
        } 
    }
    return r;
}

void quicksort(int a[], int l, int r){
    // Stop condition
    if (l >= r) return;
    // Step1: Select key element
    int key = a[(l+r)/2];
    // Step2: Sort array again by key
    int k = partition(a, l, r, key);

    // Setp3: Divide array and repeat
    // Left
    quicksort(a, l, k);
    // Right
    quicksort(a, k+1, r);
}   



int main(){
    int a[8] = {6, 7, 8, 5, 4, 1, 2, 3};
    cout << "Origin sort:" << endl;
    print(a, 8);
    cout << "Quick sort: " << endl;
    quicksort(a, 0, 8-1);
    print(a, 8);
    return 0;
}