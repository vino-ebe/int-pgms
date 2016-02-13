#include<iostream>

int findgap(int n);

using namespace std;

int main()
{
    int n = 10032;

    cout<<"Max Zero"<<findgap(n)<<endl;
}

int findgap(int n)
{
    int maxZero = 0;
    int curSum = 0;
    while(n)
    {
        if(!(n & 1))
        {
            curSum++;
        }
        else
        {
            if(curSum > maxZero)
                maxZero = curSum;

            curSum = 0;
        }
        n = n>>1;
    }

    return maxZero;
}
