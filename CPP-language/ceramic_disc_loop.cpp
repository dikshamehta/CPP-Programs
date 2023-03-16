#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long disc_number(double vt, double v0){
    long n = 1; //Number of discs
    long n_max = 0;
    long l_max = -1; //longest length of the necklace

    while(n<(vt/v0)){
        double v = vt/n;
        long l = round(n * 0.3 * sqrt(v-v0) * 1000000);

        if(l>l_max){
            n_max = n;
            l_max = l;
        }
        else if(l==l_max){
            return 0;
        }

        n = n+1;
    }
    return n_max;
}

int main(){
    double v0;
    double v;

    while(1){
        cin>>v>>v0;

        if (v==0 && v0==0)
        {
            break;
        }

        cout<<disc_number(v, v0)<<"\n"; 

    }

    return 0;
}