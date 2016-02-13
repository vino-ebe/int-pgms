#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "bbb";

    bool flag[256] = {};
    int maxCount = 0;
    int start = 0, count = 0;

    for(int i = 0;i < s.size(); i++)
    {
        if(flag[s[i]])
        {
            count = (i - start);

            /* Reset the bool flag for the substring */
            for(int k = start; k < i; k++)
            {
                flag[s[k]] = false; 
            }
            start = i;

            flag[s[i]] = true;

            maxCount = max(maxCount, count);
        }
        else
        {
            flag[s[i]] = true;
        }
    }

    cout<<"Maxcount"<<maxCount<<endl;

}
