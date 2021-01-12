#include<iostream>
using namespace std;

template<class T>
struct Node{ //since we need public members therefor use dtrct instead of class 
    T data;
    Node *next; 
};

template<class T>
class Stack{
    Node<T> *top;

    public: 

    Stack(){
        top = nullptr;
    }

    void push(T data){
        Node<T> *node = new Node<T>;
        node->data = data;
        node->next = nullptr;

        if(top==nullptr){
            top = node;
        }
        else{
            Node<T> *temp = top;
            top = node;
            node->next = temp;
        }
    }

    void traverse(){
        if(top == nullptr){
            cout<<"empty stack";
        }
        else{
            Node<T> *temp = top;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    void pop(){
        if(top == nullptr){
            cout<<"empty stack";
        }
        else{
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
    }
        

};

int main(){
    Stack<int> stack;

    stack.push(10);
    stack.push(11);
    stack.push(4);
    stack.push(22);

    stack.traverse();

    stack.pop();

    stack.traverse();

    stack.push(3);

    stack.traverse();

    return 0;
}