#include<iostream>

using namespace std;

int fact(int f);
int fact_r(int f);
int fact_d(int f);
int g;

int res[100];

int main()
{
    int f = 5;
    cout<<"Factorial"<<fact(f)<<endl;
    cout<<"Factorial"<<fact_r(f)<<endl;
    cout<<"Recursed: :"<<g<<endl;
    g = 0;
    cout<<"Factorial"<<fact_d(f)<<endl;
    cout<<"Recursed: :"<<g<<endl;
    f = 6;
    g = 0;
    cout<<"Factorial"<<fact_d(f)<<endl;
    cout<<"Recursed: :"<<g<<endl;

}

int fact(int f)
{
    int temp = f;
    int res = f;

    if( f == 0)
        return 0;
    else if (f == 1)
        return 1;
    else
    {
        while(temp > 1)
        {
            res = res * (temp - 1);
            temp--;
        }
    }

    return res;
}

int fact_r(int f)
{
    g++;

    if (f == 0)
        return 0;
    else if (f == 1) 
        return 1;
    else
    {
        return f*fact_r(f-1);
    }
}

int fact_d(int f)
{
    g++;
    if ((f == 0) || (f == 1))
        return 1;
    else if(res[f] != 0)
        return res[f];
    else
        return res[f] = f * fact_d(f - 1);
}
