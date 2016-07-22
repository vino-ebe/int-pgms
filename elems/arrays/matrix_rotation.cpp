#include<iostream>

using namespace std;

int main()
{
    int m[4][4] = {1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16};

    int size = 3;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            int t1 = a[j][size];
            int t2 = a[i][size - j];
            int t3 = a[size - i][size -j];
            int t4 = a[size - i][j];
        }

