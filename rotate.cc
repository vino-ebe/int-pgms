#include<iostream>

using namespace std;

void rotate(char *a, int d);
int main()
{
    char a[] = {'a','b','c','d','e','f','g','h'};

    rotate(a,2);

    cout<<"The string is"<<a<<endl;

    return 0;
}

void rotate(char *a, int d)
{
    char *tmp = new char[d+1];

    strncpy(tmp,a,d);

    int n = 8,i = 0;

    for(i = 0; i < n; i++)
    {
        if(i < d)
        {
            tmp[i] = a[i];
        }
        a[i] = a[d+i];
    }
    i = n-d;
    for(int j = 0; j < d;j++)
    {
        a[i++] = tmp[j];
    }
/*
    if((d+i) < n)
    {
        int k = (d+i);
        for(int j = d; k < n;j++,k++)
        {
            a[j] = a[k];
        }
    }
    */
}
