#include<iostream>
#include<unordered_map>
using namespace std;

/*
NOTE:
itr acts as a pointer to the elements of the container pair is a struct type
*/

int main(){
    unordered_map<int, int> um = {
        {1, 9},
        {2, 8},
        {3, 7}
    };

    for(auto pair : um){
        cout<<pair.first<<":"<<pair.second<<endl;
    }

    for(auto iter = um.begin(); iter!=um.end(); iter++){
        cout<<iter->first<<":"<<iter->second<<endl;
    }

    return 0;

}