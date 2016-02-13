#include<iostream>
#include<string>
#include<map>

using namespace std;

bool isIsomorphic(string s1, string s2);

int main()
{
    string s1 = "foo";
    string s2 = "bar";

    if(isIsomorphic(s1,s2) == true)
        cout<<"It is isomorphic"<<endl;
    else
        cout<<"It is not isomorphic"<<endl;
}

bool isIsomorphic(string s1, string s2)
{
    map<char,char> m;

    if(s1.size() != s2.size())
    {
        return false;
    }
    else
    {
        for (int i = 0;i < s1.size();i++)
        {
            m[s1[i]] = s2[i];
        }

        for (int i = 0; i < s1.size(); i++)
        {
            if(m[s1[i]] != s2[i])
            {
                return false;
            }
        }
    }

    return true;
}
