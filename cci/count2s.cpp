#include<iostream>

using namespace std;

int main()
{
    int a = 25;
    int r = 0, n = 0;
    int count = 0;

    for (int i = 0; i <= 25; i++) {
        n = i;
        do {
            r = n % 10;
            n = n / 10;
            if (r == 2) {
                count++;
                cout<<i<<endl;
            } else if (r == 0 && i == 2) {
                count++;
                cout<<i<<endl;
            }
        }while (n);
    }

    cout<<"Count is "<<count<<endl;
}

