#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "geekforgeeks";
    string p = "g*r.e";

    int i = 0;
    int j = 0;
    bool wildcardMode = false;

    while(j < p.size())
    {
        if(s.at(i) != p.at(j))
        {
            if(p.at(j) == '*')
            {
                if(j == p.size() - 1)
                {
                    /* Matches the whole string */
                    cout<<"The susstring"<<s<<endl;
                    break;
                }
                
                wildcardMode = true;
                j++; /* point j to next char*/
            }
            else if(p.at(j) == '.')
            {
            }
            else
            {
                if(!wildcardMode)
                {
                    cout<<"String did not match"<<endl;
                    break;
                }
            }
        }
        else
        {
            if(wildcardMode)
            {
                wildcardMode = false;
            }
        }

        i++;
        if(!wildcardMode)
        {
            j++;
        }
    }

    if(j == p.size())
    {
        cout<<"The substring is:"<<s.substr(0,i)<<endl;
    }
}


            

    
