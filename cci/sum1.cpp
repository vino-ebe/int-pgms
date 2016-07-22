#include<iostream>

using namespace std;

int main()
{
    int a[] = {2, -8, 3, -2, 4, -10};

    int size = sizeof(a)/sizeof(a[0]);

    int max = -100, sum = 0;

    int i = 0, j = 1;

    sum = a[0];
    max = a[0];
    int si = 0, ei = 0;

    while (j < size) {
        sum += a[j];

        if (sum > max) {
            max = sum;
            si = i;
            ei = j;
            j++;
        } else {
            i++;
            sum = a[i];
            j = i + 1;
        }
    }

    cout<<"Max is:"<<max<<endl;
    cout<<"si is:"<<si<<"ei is:"<<ei<<endl;
}
