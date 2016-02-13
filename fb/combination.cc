#include<iostream>

using namespace std;

void combinationUtil(int a[], int n, int r, int index, int data[], int i);
void printCombination(int a[], int n, int r);

int main()
{
    int a[] = { 1,2,3,4,5};
    int r = 3;
    int n = sizeof(a)/sizeof(a[0]);
    
    printCombination(a,n,r);

    return 0;
}

void printCombination(int a[], int n, int r)
{
    int data[r];

    int index = 0;

    combinationUtil(a, n, r, 0, data, 0);
}

void combinationUtil(int a[], int n, int r, int index, int data[], int i)
{
    if(index == r)
    {
        for(int i = 0; i < r; i++)
        {
            cout<<data[i];
        }
        cout<<endl;
        return ;
    }

    if (i >= n)
        return;

    data[index] = a[i];

    combinationUtil(a,n,r,index + 1,data,i + 1);

    combinationUtil(a,n,r,index ,data,i + 1);
}
