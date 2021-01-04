/*
1. It is a template class which can be used to store a pair of two values
*/

#include<utility>
#include<iostream>
#include<vector>

using namespace std;



int main(){
    //storing a pair    -   syntax is quite similar to how we use a user defined class : Demo<int> demoobj1(10);
    pair<int, string> p;
    p.first = 10;
    p.second = "abc";

    //storing multiple pair in a vector 
    vector<pair<int, string>> v; 
    v.push_back(p);

    //to iterate the items
    for(auto iter = v.begin(); iter!=v.end(); iter++){
        cout<<(*iter).first<<"  "<<(*iter).second<<endl;
    }

    //second method to iterate
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<"  "<<v[i].second<<endl;
    }

}