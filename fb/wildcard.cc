#include<iostream>
#include<string>

using namespace std;
bool match(string s,string w);

/* * and ?
 * * will any match one or more characers.
 * ? will match just one char
 */

int main()
{
    string s = "gee";
    string w = "*gee";

    if(match(s,w))
        cout<<"Matched"<<endl;
    else
        cout<<"Did not match"<<endl;
}

bool match(string s,string w)
{
    int i = 0;
    int j = 0;

    while(i < s.size() && j < w.size())
    {
        if(s.at(i) == w.at(j))
        {
            i++;
            j++;
        }
        else if(w.at(j) == '*')
        {
            break;
        }
        else
        {
            return false;
        }
    }

    if(w.size()  - 1 == j )
    {
        return true;
    }

    string wss = w.substr(j + 1, w.size());
    cout<<"wss:"<<wss<<endl;

    int msize = s.size() - wss.size();
    string sss = s.substr(msize, s.size());
    cout<<"sss:"<<sss<<endl;

    if(wss == sss)
        return true;
    else
    {
        j = j + 1;
        while(i < s.size())
        {
            if(s.at(i) == w.at(j))
                break;

            i++;
        }

        if(i < s.size())
        {
            s = s.substr(i,s.size());
            w = w.substr(j,w.size());
            return(match(s,w));
        }
        return false;
    }
}
