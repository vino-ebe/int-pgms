#include<iostream>

using namespace std;

void reverse(char a);
int main() 
{
    char a = 21;

    reverse(a);
}

void reverse(char a)
{
    int res = 0;
    int size = sizeof(a);
    size = size * 8;
    while(size) {
        if (a & 0x1) {
            res |= 1;
        } 
        res = res << 1;
        a = a >> 1;
        size--;
    }
}

