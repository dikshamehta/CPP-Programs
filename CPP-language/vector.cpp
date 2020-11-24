#include<iostream>
#include<vector>

using namespace std;

//ways to display
void display(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void display2(vector<int> &vec){
    vector<int>::iterator itr;    
    for(itr = vec.begin(); itr!=vec.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}

void display3(vector<int> &vec){
    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}

int sum(vector<int> &vec){
    int sum = 0;
    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
        sum = sum + *itr;
    }
    return sum;
}


int main(){
    vector<int> v;
    vector<int> v1(10);  //since vector is a class therefore we pass 10 (no of elements we want in vector) to contructor

    //for pushing in array
    v.push_back(3);
    v.push_back(5);

    //for replacing values 
    v[1] = 10;
    v1[4] = 2;

    //for displaying them
    display(v);
    display2(v);
    display(v1);
    display3(v);

    //sum
    cout<<sum(v)<<endl;

    return 0;
}