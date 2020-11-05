#include<iostream>
using namespace std;

class C1{
    int a; //private is by default 

    public: //after this members will be public 
    int b; //public
    int b1; //public 

    private: //after this members will be private 
    int c; //private

    protected: //after this members will be protected 
    int d; //protected
};

class C2{
    int a; 

    //one way to declare and define  
    public:
    void func1(){
        cout<<"func1"<<"\n";
    }

    //other way to declare
    int func2();
};

int C2::func2(){ //definition, "::" is scope resolution operator 
    cout<<"func2"<<"\n";
    return 1;
}

//==================FRIEND FUNCTION===============================================================
//these have their major usage in case of operator overloading 
class C3{
    int a;

    public:
    int b;

    friend void friend_func();
};

void non_friend_func(){
    C3 obj;
    obj.b;

    //since this function is non friend it can not access private
}

void friend_func(){
    C3 obj;
    cout<<obj.b;
    cout<<obj.a; //here we can access private members too, as this is friend function 
}

//==================FRIEND CLASSES===============================================================
class C4{
    int a;

    friend class C4Friend;
};

 
class C4Friend{ //this class can access private members of friend class 
    public:
    void func(){
        C4 obj;
        cout<<obj.a<<endl;
    }
};

//==================CONSTRUCTORS & DESTRUCTORS===============================================================
class C5 {
    int a, b;

    public:
    C5(int a, int b){ //by default this is private too, so fo public for outside visibility
        this->a = a; //this is pointer type
        this->b = b;
    }

    C5(int a){
        this->a = a;
    }

    //CPP do not have garbage collector by default, so deconstructor is there
    //this is called by default
    ~C5(){
        // free any dynamically allocated memory
        cout<<"deconstructor C5"<<"\n";
    }
};


int main(){
    C2 obj; //in this default constructor is called
    obj.func1();
    obj.func2();


    //friend class  
    C4Friend c4f;
    c4f.func();


    //constructors object creation 
    //syntax 1:
    C5 objc5(34, 65); //parameterized constructor 

    //syntax 2:
    C5 objc51 = C5(34, 65);

    //syntax in case of single parameter
    C5 objc52 = 56; // equivalent to C5 objc5(56)

    return 0;
}