#include<iostream>

using namespace std;

int main()
{
    int a[] = {4,5,6,7,8,1,2};

    int size = sizeof(a)/sizeof(a[0]);

    int i = 0;
    
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(start == end)
        {
            cout<<"Min:"<<a[mid]<<endl;
            break;
        }

        if ((end - start) == 1)
            cout<<"Min:"<<min(a[start],a[end])<<endl;

        if(a[start] < a[end])
        {
            cout<<"Min:"<<a[start]<<endl;
            break;
        }

        if(a[mid] > a[start])
        {
            start = mid ;
        }
        else
        {
            end = mid ;
        }
    }
}
    
