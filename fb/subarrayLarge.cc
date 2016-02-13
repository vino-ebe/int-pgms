#include<iostream>
using namespace std;

int largeSum(int num[],int size);

int main()
{
    int num[] = { -2,1,-3,4,-1,2,1,-5,4};
    int size = sizeof(num)/sizeof(num[0]);
    largeSum(num,size);
}

int largeSum(int num[],int size)
{
    int i = 1;
    int sum[size];
    int maxsum = 0;

    sum[0] = num[0];
    maxsum = num[0];

    while(i < size)
    {
        sum[i] = max(num[i], sum[i-1] + num[i]);
        maxsum = max(sum[i], maxsum);
        i++;
    }

    cout<<"Max sum:"<<maxsum<<endl;
    return maxsum;
}
