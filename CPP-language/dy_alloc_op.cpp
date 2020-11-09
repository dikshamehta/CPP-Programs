#include<iostream>
using namespace std;

/*
new and delete

"new" : this is operator is used to dynamically allocate memory
Syntax:
pointer_var = new <var_type>(intializers)
*/

class C{
    int data;
    int *p;
    public:
    C(int data){
        this->data = data;
        this->p = new int(); //this one will be made in heap, 
        //like p will be in data segment only, but int() memory will be allocated to it which will be in heap
    }

    C(){

    }

    void display(){
        cout<<data<<endl;
    }

    ~C(){
        cout<<"destructor is called"<<endl;

        //now objects will delete by delete func, but the variables and objects in this file like *p is not deleted
        //we will delete these type of dynamic allocations here 
        if(p != NULL){
            delete p;
        }
    }
};

int main(){
    //normal int dynamic alloc
    int *p = new int(); //it will work like "int *p = new int" as well
    cout<<*p<<endl;

    int *p1 = new int(34);
    cout<<*p1<<endl;

    int *p2 = new int;
    cout<<*p2<<endl;

    //dynamic class allocation, in this we had to give 234 as we have parameterized constructor in it 
    C *cp = new C(234);
    cp->display();

    //in this case default constructor will be called 
    C *cpp = new C;

    
    //to free uo dynamically allocated memory 
    delete p; //free functio of c is same 
    delete p1;
    delete p2;

    delete cp; //this will call destructor of class 
    delete cpp;

    cout<<"all dynamically allocated objects are deleted"<<endl;

    //dynamically allocating array
    //syntax: <pointer var> = new <var type>[SIZE];

    int *arr = new int[10]; // allocated an integer array of size 10
    C *arr2 = new C[10]; //10 objects of C class in an array 
    delete[] arr;
    delete[] arr2;

    return 0;
}

//if there is not enough memory then "bad_alloc" exception is thrown