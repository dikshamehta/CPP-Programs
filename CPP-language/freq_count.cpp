#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<int, int> freq_count(vector<int> &v){
    unordered_map<int, int> um;

    for(auto iter=v.begin(); iter!=v.end(); iter++){
        if(um.find(*iter)== um.end()){
            um[*iter] = 1;
        }
        else{
            um[*iter] = um[*iter] + 1;
        }
    }
    return um;
}

int main(){
    vector<int> v = {2, 2, 2, 3, 3, 4};

    unordered_map<int, int> um = freq_count(v);

    for(auto iter = um.begin(); iter!=um.end(); iter++){
        cout<<iter->first<<":"<<iter->second<<endl;
    }
    
    return 0;
}