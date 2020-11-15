#include<iostream>
using namespace std;

/*

syntax:
//this syntax is for the function outside class 
<ret-type> <class name>::operator<#>(arg-list) {
    //operators
}


Note: the object of the left calls the operator function and passes the object
on the right as its argument

*/

class Vector2d{
    int x1, x2;

    public:
    Vector2d(int x1, int x2){
        this->x1 = x1;
        this->x2 = x2; 
    }

    Vector2d operator+(Vector2d &v2){
        Vector2d v3(v2.x1+this->x1, v2.x2+this->x2);
        return v3;
    }

    void display(){
        cout<<"["<<x1<<" "<<x2<<"]"<<endl;
    }
     
};

int main(){
    Vector2d v1(10, 12);
    Vector2d v2(1, 2);

    v1.display();
    v2.display();

    Vector2d v3 = v1+v2;
    v3.display();

    return 0;
}