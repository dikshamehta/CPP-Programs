#include<iostream>
using namespace std;

class Demo{

    public:
    int data;

    Demo(){

    }

    Demo(int data){
        cout<<"Demo constructor is called"<<endl;
        this->data = data;
    }

    Demo(Demo &obj){
        cout<<"copy constructor is called"<<endl;
    }

    ~Demo(){
        cout<<"Demo destructor called"<<endl;
    }

};

int main(){
    Demo d1(12);
    Demo d2 = d1; //copy of d1 object will be made
                  //and it is assigned to d2, so basically we have 2 objects here in case of the above statement a bitwise copy of d1 is made, therefore constructor is not called specially 
                  //but here copy contructor will be calee, default or the one we make if any

    Demo d3; //construct a new object using default con
    d3 = d2; //assign - data will be copied, no copy contruc will be called

    cout<<d1.data<<endl;
    cout<<d2.data<<endl;
    cout<<d3.data<<endl;

    return 0;
}

/*

NOTE:
Knowing different between initialization and assignment is impi
=> copy constructor is called only when initializaton accurs 

Initialization occurances:
1. explicit initialization (as in ex above)
2. when an object is pased to another function using call by value
3. when a function returns an object 

*/