#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link; //Pointer for whole node
};

//Structure: Top->|Data2|->|Data1|->null
class Stack{
    node *top;

    public:
    Stack(){
        top = nullptr;
    }

    //copy constructor
    Stack(const Stack &obj){
        if(obj.top == nullptr){
            top = nullptr;
            return;
        }

    }

    void push(int data){
        //create using new because after push function we want to retain the memory
        //if we only create node obj -> this will be considered as local obj which will destry after the push function returns
        node *obj = new node();
        obj->data = data;
        obj->link = top;
        
        top = obj;
    }

    void pop(){
        if(top == nullptr){
            cout<<"Stack underflow"<<"\n";
            return;
        }
        top = top->link;
    }

    void display(){
        if(top == nullptr){
            cout<<"Stack is empty"<<"\n";
            return;
        }

        node *temp;
        temp = top;
        while(temp != nullptr){
            cout<<temp->data<<"\n";
            temp=temp->link;
        }

    }

};

int main(){
    Stack s1;
    s1.display();
    s1.push(10);
    s1.push(11);
    s1.display();
    s1.pop();
    s1.push(13);
    s1.display();
}