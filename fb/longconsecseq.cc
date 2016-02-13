#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int a[] = { 100,4,200,1,3,2};

    unordered_map<int,int> nMap;
    unordered_map<int,int>::iterator it;

    int maxCount;

    for (int i = 0;i < 6; i++)
    {
        nMap[a[i]] = i;
    }

    for (int i = 0; i < 6; i++)
    {
        int left = a[i] - 1;
        int right = a[i] + 1;

        int lcount = 1;
        int rcount = 1;

        while((it = nMap.find(left)) != nMap.end())
        {
            left--;
            lcount++;
            nMap.erase(it);
        }

        while((it = nMap.find(right)) != nMap.end())
        {
            right++;
            rcount++;
            nMap.erase(it);
        }

        if(lcount > rcount)
        {
            maxCount = max(maxCount,lcount);
        }
        else
        {
            maxCount = max(maxCount,rcount);
        }
    }
        
    cout<<"Max count is :"<<maxCount<<endl;
}
