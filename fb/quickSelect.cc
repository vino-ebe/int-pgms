#include<iostream>
#include<vector>

using namespace std;

int quickSelect(vector<int> a, int k,int len);

int main()
{
    vector<int> a;

    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(6);
    a.push_back(4);
    quickSelect(a,4,a.size());
}

int quickSelect(vector<int> a, int k,int len)
{
    int pivot = a[rand() % len];

    vector<int> a1,a2;
    
    for(int i = 0; i < len; i++)
    {
        if(a[i] > pivot)
        {
            a1.push_back(a[i]);
        }
        else if(a[i] < pivot)
        {
            a2.push_back(a[i]);
        }
        else
        {
        }
    }

    if(k <= a1.size())
    {
        quickSelect(a1, k, a1.size());
    }
    else if(k > (len - a2.size()))
    {
        quickSelect(a2, k - (len - a2.size()),a2.size());
    }
    else
    {
        cout<<"Returning pivot"<<pivot<<endl;
        return pivot;
    }
}
