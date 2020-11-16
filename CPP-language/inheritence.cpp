#include<iostream>
using namespace std;

/*
Syntax: 
class <derived-class-name> : [acces-specifier] <super-class-name>{

};  

1. private member of super class are not inherited in any case
2. if access specifier is: 
    (a) public    : all the public members of the super class become public members of the subclass and protected
                    members of superclass become protected in subclass 
    (b) private   : all the public and protected members of the super class become private members of the subclass
    (c) protected : all the public and protected members of the super class become protected members of the subclass
3. if no access specifier is given then it is private in class and public in struct by default
*/


/*
Syntax of Multiple Inheritence:
class <derived-class-name> : [access-specifier] <super-class1-name>, [access-specifier] <super-class2>{

};
*/


/*
Diamond Problem in case of Multiple Inheritence is resolve by virtual class. 
Here, top class i.e. the one parent of all is declared virtual class and then internally only one copy of that class is formed
even if 2 classes are inheriting it further. And if there is no multiple inheritence then these classes behave as normal classes. 
*/


//to demontrate normal inheritence
class A{
    int a = 4;
    public: int b = 5;
    protected: int c = 10;
};

class B : public A{
    public:
    void display(){
        cout<<"display "<<c<<endl;
    }
};


//to demonstrate how to pass arguments to super class
class C{
    int a; 

    public:
    C(int a){
        this->a = a;
    }

    int getA(){
        return a;
    }
};

class D : public C{ //no access specifier then private by default
    public:
    D() : C(12){
    }

    D(int x) : C(x*2){ // we can put any expressions here
    }
};

int main(){

    A obja1;
    // cout<<obja1.a<<" ";
    cout<<obja1.b<<" ";
    // cout<<obja1.c<<" ";

    B objb1;
    // cout<<objb1.a<<endl;     this one is not accessed by b
    cout<<objb1.b<<endl;        //this is accessed in b and here too
    // cout<<objb1.c<<endl;     this one can only be accessed in class B

    objb1.display();            //accesing the protected member

    //passing arguments to super class
    D objd1;
    cout<<objd1.getA()<<endl;

    D objd2(23);
    cout<<objd2.getA()<<endl;

    return 0;
}

/*
Note : 
protected behave like private in most cases except in a subclass, as it can access protected member of suuper class
wherease even subclass can not access the private member 
*/

