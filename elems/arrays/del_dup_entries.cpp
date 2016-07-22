#include<iostream>

using namespace std;
void remove(int a[], int size);

int main()
{
    int a[] = { 2, 3, 5, 5, 7, 11, 11, 11, 13};

    int size = sizeof(a)/sizeof(a[0]);

    int cur = 1;
    for (int i = 1; i < size; i++) {
        if (a[cur - 1] != a[i]) {
            a[cur] = a[i];
            cur++;
        }
    }

    for (int i = 0; i < size; i++) {
        cout<<a[i]<<endl;
    }
}

void remove(int a[], int size)
{
    int index = 1;
    int i = 1;

    while (i < size) {
        if (a[index - 1] == a[i]) {
            while(a[++i] == a[index-1]); 
            a[index] = a[i];
        }
        index++;
        i++;
    }

    while(index < size) {
        a[index++] = 0;
    }
}

