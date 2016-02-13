#include<iostream>
using namespace std;

int main()
{
    //int vector[]={31,-41,59,26,-53,58,97,-93,-23,84};
    int vector[]={-2,1,-3,4,-1,2,1,-5,4};
    int maxsum = 0;
    int sum = 0;
    for(int i = 0; i < 9;i++)
    {
        sum = sum + vector[i];
        if(sum < 0)
            sum = 0;

        if(sum > maxsum)
            maxsum = sum;
    }


    cout<<"Max sum is: "<<maxsum<<endl;
}
