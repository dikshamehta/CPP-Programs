#include<iostream>
#include<utility>
using namespace std;

//concept of functional objects
template<class T>
bool lt(T &x, T &y){
    return x<y;
}

template<class T>
bool gt(T &x, T &y){
    return x>y;
}

template<class T>
void sortVals(T *arr, int n, bool (*compare)(T &, T &)){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(compare(arr[j], arr[j+1])){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

template<class T>
void display(T *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n = 5;
    int arr[] = {2, 1, 8, 5, 4};

    sortVals(arr, n, lt);
    display(arr, n);

    sortVals(arr, n, gt);
    display(arr, n);

    return 0;
}