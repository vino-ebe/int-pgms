#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int num = 11;
    int div = 2;

    int q = 0;
    int k = -1;
    int res = 0;

    while (num > div) {

        while (res < num) {
            k++;
            res = div << k;
        }
        k = k -1;

        num = num - (div << k);
        q += pow(div, k);
        k = 0;
        res = 0;
    }

    cout<<"The quotient is:"<<q<<endl;
}
