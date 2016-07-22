#include<iostream>

using namespace std;

int main()
{
    //int x[] = {1, 9, 3, 7, 0, 7, 7, 2, 1};
    //int y[] = {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};

    int x[] = {1, 2, 3};
    int y[] = {4, 5, 6};

    int x_size = sizeof(x)/sizeof(x[0]);
    int y_size = sizeof(y)/sizeof(y[0]);

    int res[7] = {};

    int carry = 0;
    int scarry = 0;
    int k = 0, m, sum;

    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
            m = x[i] * y[j] + carry;
            carry = m / 10;
            sum = m % 10;
    //        if (res[k + j] + sum) > 10
            res[k + j] =  ((res[k + j] + sum) + scarry ) % 10;
            scarry = (res[k + j] + sum + scarry) / 10;
        }
        k++;
    }

    for (int i = 0; i < k; i++) {
        cout<<res[i]<<endl;
    }
}
