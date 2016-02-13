#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int a[] = {-1,0,1,2,-1,4};

    int i = 0; int left = 0;
    int size = sizeof(a)/sizeof(a[0]);
    int right = size -1;
    int sum = 0;

    vector<int> arr(a, a + size);

    sort(arr.begin(),arr.end());

    right = size - 1;

    for(int i = 0; i < size -2; i++)
    {
        left = i + 1;

        while(left < right)
        {
            if(arr[i] + arr[left] + arr[right] == sum)
            {
                cout<<"Triplets are"<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;
                left++;
                right--;
            }
            else if(arr[i] + arr[left] + arr[right] > sum)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
}
