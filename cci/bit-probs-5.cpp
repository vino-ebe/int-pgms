#include<iostream>

using namespace std;

void insertNintoM(int m, int n, int i, int j);
void swapBits(int n) ;
int main()
{
    int m = 19;
    int n = 1 << 10;
    int i = 2;
    int j = 6;

    insertNintoM(m, n, i, j);
    swapBits(m);
}

void insertNintoM(int m, int n, int i, int j) {
    int leadMask = (1 << j);

    int trailMask = (~0 & 0xFF) >> (8 - i); 

    int resMask = leadMask | trailMask;
    int m_temp = n | resMask;
    int res = n | (m << i);
}

void swapBits(int n) {

    int i = 0, j = 1;
    int t_n = n;

    while(t_n) {
        if (n | ~(1 << i)) {
            n &= ~(1 << j);
        } else {
            n |= (1 << j);
        }
        i = i + 2;
        j = j + 2;
        t_n = t_n >> 2;
    }
}
