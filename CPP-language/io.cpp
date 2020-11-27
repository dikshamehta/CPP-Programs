/* 
TEMPLATE IO CLASSES

   template            specific classes
                    charater based           wide-character based
    basic_ios           ios                         wios
    basic_istream      istream                      wistream
    basic_ostream      ostream
    basic_iostream     iostream
    basic_fstream      fstream
    basic_ifstream     ifstream
    basic_ofstream     ofstream

typedef basic_ios<char> ios; 
typedef basic_ios<wchar> wios;

            basic_ios
           /         \
    istream           ostream
    |  |   \         /    |  |
    |  |   basic_iostream |  |
    |  |              | | |  |
    |  basic_ifstream | | |  basic_ofstream
    |                 | | |
    |                 | | |
    istringstream     | | ostringstream
                      | |
                      | |
     basic_stringstream basic_fstream  

refer link : https://en.cppreference.com/w/cpp/io

*/

#include<fstream>
#include<iostream>

using namespace std;

int main(){
    //METHOD 1
    ifstream ifs = ifstream("input.txt");

    while(!(ifs.eof())){
        char c = ifs.get();

        if(c != EOF){       //typedef std::char_traits<char> EOF
            cout<<c;
        }   
    }
    cout<<endl;
    ifs.close();

    //METHOD 2
    ifs = ifstream("input.txt");
    string s;
    ifs>>s;
    cout<<s<<endl;

    ofstream ofs = ofstream("output.txt");
    ofs<<s;
    




    return 0;
}

