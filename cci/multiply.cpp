#include<iostream>

using namespace std;

int multiply(int a, int b);
int getsign(int x);
int flip(int y);

int main() {
    int a = 5;
    int b = 10;

    int res = multiply(a, b);
    cout<<"The bigger number is "<<res<<endl;
}

int multiply(int a, int b)
{
    int sign = getsign(a - b);
    int q = flip(sign);
    return a * sign + b * q;

}

int getsign(int x)
{
    int res = (x >> 31) & 0x1; 
    return flip(res);
}

int flip(int y)
{
    int res = 1 ^ y;
    return res;
}

