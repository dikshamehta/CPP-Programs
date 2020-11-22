#include<iostream>
using namespace std;

/*
Templates : 
These are generic types which are same for all the data types

GENERIC FUNCTIONS:
    Syntax:
    template <class T> 
    return-type func-name(para-list){

    }

    here, T is a placeholder for a data type 


GENERIC CLASSES:
    syntax:
    template<class T> class class-name{

    }
*/


//GENERIC FUNCTIONS examples 

//example 1
template <class T> 
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//example 2
template <class T1, class T2>
void func(T1 &a, T2 &b, int c){
    cout<<a<<' '<<b<<' '<<c<<endl;
}

//example 3
template <class T>
T sum(T &a, T &b){
    return a + b;
}

class C{

};


//GENERIC CLASS example
template<class T>
class Demo{
    T *arr;
    int size;
    
    public:
    Demo(int size){
        arr = new T[size];
        this->size = size;
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;        
    }

    ~Demo(){
        delete[] arr; //explicity freeing because we created using new 
    }
};




int main(){
    int a = 10, b = 20; 
    float x = 10.34f, y = 20.34f;
    char c1 = 'a', c2 = 'b';

    //GENERIC FUNCTION
    cout<<"original: "<<endl;
    cout<<a<<" "<<b<<endl;
    cout<<x<<" "<<y<<endl;
    cout<<c1<<" "<<c2<<endl;

    swapVals(a, b);
    swapVals(x, y);
    swapVals(c1, c2);

    cout<<"swaped: "<<endl;
    cout<<a<<" "<<b<<endl;
    cout<<x<<" "<<y<<endl;
    cout<<c1<<" "<<c2<<endl;

    func(a, c1, 3);

    sum(a, b);
    sum(c1, c2);

    // to demonstrate that specific data type is replaced with T at runtime
    // C objc1;
    // C objc2;

    // sum(objc1, objc2);


    //GENERIC CLASS
    Demo<int> demoobj1(10);      //creating object of class where param T is int
    Demo<char> demoobj2(10);    //creating object of class where param T is char

    demoobj1.display();
    demoobj2.display();

    return 0; 
}