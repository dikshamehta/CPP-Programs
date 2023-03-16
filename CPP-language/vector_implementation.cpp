#include <iostream>
using namespace std;

class myVector{
    int capacity;
    int size;

    public:
    int *arr;

    public:
    myVector(int capacity){
        size = 0;
        this->capacity = capacity;
        arr = new int[capacity]; // new operator will return the address of array therefore directly can save in arr
    }

    void push_back(int data){

        if(size==capacity){
            capacity = capacity * 2;

            int *temp = new int[capacity];

            for(int i=0; i<size; i++){
                temp[i] = arr[i];
            }

            delete[] arr; //this is will delete the memory allocated for the array in heap

            arr = temp; //adding address of new array stored in temp pointer to arr pointer

        }

        //adding data
        arr[size] = data; 
        size++;
        
    }

    int get(int i){
        if(i<size){
            return arr[i];
        }
        else{
            //check how to do it better
            cout<<"Array Index out of bound";
            return 0; 
        }   
    }

    void set(int i, int val){
        if(i<size){
            arr[i] = val;
        }
        else{
            //check how to do it better
            cout<<"Array Index out of bound";
        }
    }


    int getSize(){
        return size;
    }

    int* getVector(){
        return arr;
    }


};

int main(){
    int *vector;

    myVector obj(2);

    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(1);
    obj.push_back(3);
    obj.push_back(4);
    obj.push_back(5);
    obj.push_back(6);
    obj.push_back(7);
    obj.push_back(8);

    vector = obj.getVector();

    for(int i=0; i<obj.getSize(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<"\n";

    obj.set(3, 5);

    vector = obj.getVector();

    for(int i=0; i<obj.getSize(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<"\n";

}