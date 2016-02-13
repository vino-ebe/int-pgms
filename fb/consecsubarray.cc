#include<iostream>

using namespace std;

int main()
{
    int a[] = {5,6,4,12};

    int target = 21;

    int size = sizeof(a)/sizeof(a[0]);

    int i = 0, sum = 0, j = 1;

    while(j < size)
    {
        sum = a[i] + a[j];

        if(sum == target)
        {
            cout<<"PRESENT"<<endl;
            break;
        }
        i++;
        j++;
    }
}

