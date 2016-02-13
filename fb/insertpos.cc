#include<iostream>

using namespace std;

int main()
{
    int a[] = {1,3,5,6,7};

    int target = 8;

    int start = 0, end = 4;

    while(start <= end)
    {
        int mid = (end + start)/2; 

        if((a[mid] + 1) == target)
        {
            cout<<"Index is:"<<mid + 1<<endl;
            return 0;
        }

        if(a[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}
