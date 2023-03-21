#include <iostream>
using namespace std;

class myVector{
    int capacity;
    int size;
    int *arr;

    public:
    //Default Constructor
    myVector(){
        size = 0;
        this->capacity = 16;
        arr = new int[capacity]; // new operator will return the address of array therefore directly can save in arr
    }

    //Overloaded Constructor
    myVector(int capacity){
        size = 0;
        this->capacity = capacity;
        arr = new int[capacity]; // new operator will return the address of array therefore directly can save in arr
    }

    //Copy Constructor
    myVector(const myVector &obj){
        size = obj.size;
        capacity = obj.capacity;

        arr = new int[capacity];
        
        for(int i=0; i<size; i++){
            arr[i] = obj.arr[i];
        }

    }

    //Operator Overloading
    int& operator[](int index){
        return this->arr[index];
    }

    myVector& operator=(myVector obj){
        size = obj.size;
        capacity = obj.capacity;

        for(int i=0; i<size; i++){
            arr[i] = obj.arr[i];
        }
    
        return *this;
    }

    //User Functions
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
            //check how to do it better -> just print the msg and exit
            cout << "Array index out of bound, exiting";
            exit(0);
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
    //Default constructor
    myVector obj1;
    myVector obj2;

    //Function Overloaded Constructor
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

    // get, set methods
    obj.set(3, 5);

    vector = obj.getVector();

    for(int i=0; i<obj.getSize(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<"\n";


   //operator overloading []
   cout<<obj[4]<<" ";
   obj[4] = 10;
   cout<<obj[4]<<" ";

   obj2 = obj1 = obj;
   cout<<"\n"<<obj1[6];
   cout<<"\n"<<obj2[6];

   //copy constructor
   myVector vec(obj);
   cout<<"\n"<<vec[6]<<" ";

}