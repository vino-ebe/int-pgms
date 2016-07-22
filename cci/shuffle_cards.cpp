#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void swap(int c[], int x, int y) ;
int getRandom(int upper) ;

int main()
{
    int c[52];
    int r = 0;

    for (int i = 0; i < 52; i++)
    {
        c[i] = i;
    }

    srand(time(NULL));

    for (int i = 0; i < 52; i++) {
        r = getRandom(i);

        swap(c, i, r);
    }

    for (int i = 0; i < 52; i++) {
        cout<<c[i]<<" ";
        if (!( i % 10)) {
            cout<<endl;
        }
    }
}

int getRandom(int upper) {
    return rand() % (upper + 1);
}

void swap(int c[], int x, int y) {
    int temp = c[x];
    c[x] = c[y];
    c[y] = temp;
}

