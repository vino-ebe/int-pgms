#include<iostream>

using namespace std;

double mypower(int x, int y) ;
int main()
{
    int x = 2;
    int y = 10;

    int res = 1;

    while(y) {
        if ( y & 1) {
            res = res * x;
        }

        x = x * x;
        y = y >> 1;
    }

    cout<<"Power of "<<x<<"over "<<y<<"is "<<res<<endl;
    mypower(2, 10);
}

double mypower(int x, int y) {
    double res = 1.0;

    while(y)
    {
        res = res * x;
        y--;
    }

    cout<<"My power is "<<res<<endl;
    return res;
}

