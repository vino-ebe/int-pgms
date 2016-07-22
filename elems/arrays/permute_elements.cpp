#include<iostream>

using namespace std;

void swap(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int main()
{
    int a[] = { 0, 1, 2, 3};
    int p[] = { 3, 2, 1, 0};

    //res will be {b, d, c, a}

    for (int i = 0; i < 3; i++) {

        int next = i;
        while(p[next] >= 0) {
            swap(a, a[i], a[p[next]]);

            int temp = p[next];

            p[next] -= 4;
            next = temp;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout<<a[i]<<endl;
    }
}

