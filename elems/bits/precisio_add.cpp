#include<iostream>

using namespace std;
void add(int a[], int size) ;

int main()
{
    int a[] = {9, 9, 9};
    int carry = 0;

    int size = sizeof(a)/sizeof(a[0]);
    add(a, size);

#if 0
    if ((a[size -1] + 1) < 10) {
        a[size -1] += 1;
    } else {
        for (int i = size - 1; i >= 0; i--) {
            if (carry) {
                a[i] = a[i] + 1;
                if (a[i] == 10) {
                    a[i] = 0;
                    carry = 1;
                    continue;
                }
                carry = 0;
            }

            if ((a[i] + 1) == 10) {
                a[i] = 0;
                carry = 1;
                if (i == 0) {
                    cout<<"Need insert"<<endl;
                }
            }
        }
    }
#endif

    for (int i = 0; i < size; i++) {
        cout<<a[i]<<endl;
    }
}

void add(int a[], int size) {

    int carry = 1;
    for (int i = size - 1; i >= 0; i--) {
        if ((a[i] + carry) == 10) {
            a[i] = 0;
        } else {
            a[i] = a[i] + 1;
            carry = 0;
        }
    }

    if (carry) {
        cout<<"Need insert"<<endl;
    }
}
