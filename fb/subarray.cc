#include<iostream>

int main()
{
    int a[] = {2,3,1,2,4,3};
    int s = 7;

    subarry(a,s);
}

int subarray(int a[],int s)
{
    int sum = a[0];
    int maxIndex = 6;
    int j = 1;

    for (int i = 0; i < 6;i++)
    {
        if(sum >= s)
        {
            maxIndex = min(maxIndex, (i - startIndex) + 1);
            sum = sum - sum[startIndex];
            startIndex = j - startIndex;
        }
        else
        {
            if( j - startIndex >= maxIndex)
            {
                startIndex = j - startIndex;
            }
            sum += num[j];
            i++;
            j++;
        }
    }
        return maxIndex;
}
