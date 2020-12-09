#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;


void display(vector<int> &vec){
    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {4,2,7,5,6};
    sort(v.begin(), v.end());
    display(v);

    sort(v.begin(), v.end(), greater<int>()); 
    display(v);

    sort(v.begin(), v.end(), less<int>());
    display(v);  
    return 0;
}