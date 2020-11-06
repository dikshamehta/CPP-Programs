#include<iostream>
using namespace std;

//references are implicit pointers 
/*
USAGE:
    1. As reference parameters
    2. Returning references from a function
    3. Independent reference eg, r in below code 

RESTRICTIONS:
    1. They have to be initialized when created
    2. once initialized they can not be made to refer any other variable 
*/

/*
Point to be noted: 
we can use struct instead of class keyword to define a class. 
The only difference is that when using struct all the members are 
by default public, while here in class these are private by default
*/

//USAGE 1. to demontrate how objects are passed to functions 
class C{
    public:
    int a;
    C(int a){
        this->a = a;
    }
};

//passing object to a function using call by value 
void display(C c){
    cout<<"display "<<c.a<<endl;
    c.a = 1;
}

//passing object to a function using pointer  
void display(C *c){
    cout<<"display "<<c->a<<endl;
    c->a = 2;
}

//passing object to a function as reference parameter
//here c is just another name of c in main
void display_ref(C &c){
    //c is reference varaible which will refer to the object passed to this function 
    cout<<"display "<<c.a<<endl;
    c.a = 3;
}



//USAGE 2. to demontrate how objects are returned by functions
int d = 23; //global 

int &func(){
    return d; //d's reference is returning 
}


int main(){
    int a = 50;
    int *p = &a; //normall pointer variable 

    int &r = a; //here, r is reference to a, i.e. r is implicit pointer 
                //here & operator is not working as address of instead it is converting r into a reference 
    //Note: references are alias of a variable
    //so, r is alias of a

    //Restriction 2 demonstration
    int b = 46;
    r = b;
    //&r = b; syntax error
    cout<<a<<"\n";

    //Note: we dont normally use independent references to avoid confusion

    //=================================================

    //USAGE1 : object passing 

    C c(8);
    //passing arg using call by value
    //here a copy of the object c is made and passed to the display function 
    display(c);
    cout<<c.a<<endl;

    //passing arg using pointers
    display(&c);
    cout<<c.a<<endl;

    //passing arg using reference
    display_ref(c);
    cout<<c.a<<endl;

    //USAGE 2 : function returning 
    cout<<"original "<<d<<endl;
    int &ref = func();
    ref = 45;
    cout<<"new "<<d<<endl;

    // a little new syntax of above
    func() = 56;//here func is retruning a reference and we are adding 56 to that ref, therefore this is working
    cout<<"new "<<d<<endl;


    return 0;
}