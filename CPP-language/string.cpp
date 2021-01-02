#include<iostream>
#include<string>
using namespace std;
/*
NOTE:
basic_string        : the class which represents the string
basic_string<char>  : is its specialization 
which is defined as : typedef basic_string<char> string
*/
int main(){
    string str = "hello";
    string str2 = "ironman";
    str.push_back('s');

    cout<<str[3]<<endl;
    cout<<str<<endl; 

    cout<<str.size()<<endl;

    cout<<str.insert(3, ":")<<endl;

    cout<<str.append(str2, 4, 3)<<endl;

    cout<<str.compare(str)<<endl;   //comapre values and not references 

    cout<<str.substr(3, 2)<<endl;

    cout<<(str == str)<<endl;       //this internally uses comapre() and compare values rather than references  

    return 0;
}