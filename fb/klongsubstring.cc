#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    string s = "abcbbbbcccbdddadacb";
    int k = 0, num = 2;

    string maxSubString;
    int maxCount = 0, count = 0, start = 0;
    int mIndex = 0;

    map<char,int> nMap;
    map<char,int>::iterator it;

    int i = 0;
    while(i < s.size())
    {
        it = nMap.find(s[i]);
        if(it == nMap.end())
        {
            nMap[s[i]] = i;
            k++;

            if(k == 2)
                mIndex = i;

            if ( k > 2)
            {
                count = i - start;
                if(count > maxCount)
                {
                    maxSubString = s.substr(start,i);
                }
                maxCount = max(maxCount,count);

                nMap.clear();

                start = mIndex;

                k = 0;
                i = mIndex - 1;
            }
        }
        i++;
    }

    count = i - start;
    if(count > maxCount)
    {
        maxCount = count;
        maxSubString = s.substr(start,i);
    }

    cout<<"MaxCount = "<<maxCount<<":MaxString:"<<maxSubString<<endl;
}
