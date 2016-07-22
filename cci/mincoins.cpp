#include<iostream>
using namespace std;

void coinChange1(int coins[], int n, int amt, int &count)
{
    if (amt == 0)
    {
        count++;
        return;
    }

    if (amt < 0)
        return ;

    for (int i = 0; i < n; i++)
    {
        if (amt >= coins[i])
        {
            coinChange1(coins, n, amt-coins[i], count);
        }
    }
}

int main()
{
    int coins[] = {1, 2, 3};
    int n = 3;
    int amt = 4;
    int count = 0;

    coinChange1(coins, n, amt, count);
    cout<<"Num coins is "<<count<<endl;
}
