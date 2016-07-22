#include<iostream>
using namespace std;

void swap(int a, int i, int j);
void swap_improved(int a, int i, int j);

int main()
{
    int a = 1;

    swap(a, 1, 5);
    swap_improved(a, 1, 5);
}

void swap(int a, int i, int j)
{
    int iMask = 1 << (i - 1);
    int jMask = 1 << (j - 1);

    if (a & jMask) {
        if (a & iMask) {
            a = a | iMask;
            a = a | jMask;
        } else {
            a = a | iMask;
            a = a & (a & ~jMask);
        }
    } else {
        if (a & iMask) {
            a = a & (a & ~iMask);
            a = a | jMask;
        } else {
            a = a & (a & ~iMask);
            a = a & (a & ~jMask);
        }
    }
}

void swap_improved(int a, int i, int j)
{
    int iMask = 1 << (i - 1);
    int jMask = 1 << (j - 1);

    if (((a & iMask) && (a & jMask)) || (!(a & iMask) && !(a & jMask))) {
        cout<<"No need to swap bits"<<endl;
    } else {
        a = a ^ iMask;
        a = a ^ jMask;
    }
}
