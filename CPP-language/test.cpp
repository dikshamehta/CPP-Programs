#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        cout<<n<<" ";
        if(n==0) return false; 
        while(n%2==0){
            n/=2;
            cout<<n<<" ";
        }
        return n==1;
    }
};

int main(){
    Solution s;
    cout<<s.isPowerOfTwo(16);
    return 0;
}