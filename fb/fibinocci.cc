#include<iostream>

using namespace std;

int fib(int num);

    int res[6];
int main()
{
    int num = 5;


    res[0] = 0;
    res[1] = 1;

    for(int i = 0;i < 6;i++)
    {
        cout<<"Fib"<<fib(i)<<endl;
    }

}

int fib(int num)
{

    if(num == 0)
    {
        return res[0];
    }
    else if(num == 1)
        return res[1];
    else
    {
        if(res[num])
        {
            return res[num];
        }
        else
        {
            res[num - 1] = fib(num - 1);
            res[num - 2] = fib(num - 2);

            return (res[num - 1] + res[num - 2]);
        }
    }
}


