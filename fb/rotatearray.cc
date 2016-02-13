#include<iostream>

using namespace std;
void rotate(string&,int);

int main()
{
    string arr = "12345";
    int rotateNum = 7;

    rotate(arr,rotateNum);

    cout<<"Rotated array"<<arr<<endl;
}

void rotate(string& arr, int num)
{
    char temp;
    int len = arr.size();
    int last;

    if(num > len)
    {
        num = (num % len) ;
    }

    last = arr.size() - 1;
    int k = last;

    for(int i = 0; i < num; i++)
    {
        temp = arr[last];
        for(int j = last; j > 0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
}
