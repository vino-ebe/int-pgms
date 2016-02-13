#include<iostream>
#include<cmath>

using namespace std;

int convertArray(int a[],int size);
void convertToArray(int a[], int sum);

int main()
{
    int a[] = {1,4,2,1};

    int add = 1;

    int size = sizeof(a)/sizeof(a[0]);

    int sum;

    sum = convertArray(a,size);

    sum = sum + add;

    convertToArray(a,sum);

    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }

}

int convertArray(int a[],int size)
{
    int sum = 0;
    int base = 10;
    int j = 0;

    for(int i = size - 1; i > 0; i--,j++)
    {

        sum += a[i] * pow(base,j);
    }

    return sum;
}

void convertToArray(int a[], int sum)
{

    for(int i = 3; i >= 0; i--)
    {
        a[i] = sum % 10;
        sum = sum / 10;
    }
}


