#include<iostream>

/*
Namespace : It is kind of same, as was in python. This is the area where all the variables resides
using : this keyword brings all the variables of a particular namespace in the current namespace 
current namespace : global namespace of our current program

Note
If we are not using keyword "using" then while using variable of same namespace we have to use scope resolution operator,
<namespace name>::<identifier name>
*/

namespace ns1{
    using namespace std;    //since we want to use "cout" in this namespace 
    int a = 10;
    int b = 11;

    void func(){
        cout<<b<<endl;
    }
}

//using namespace ns1;    //this syntax includes variables from ns1 namespace into current namespace 

int c = 10; //c is in global namespace
int main(){
    std::cout<<ns1::a<<std::endl;
    std::cout<<ns1::b<<std::endl; 
}