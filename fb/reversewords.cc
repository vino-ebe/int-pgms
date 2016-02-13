#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string s = "the sky is blue";
    int i = 0; 
    stack<string> mSt;
    int start = 0;

    while(i < s.size())
    {
        if(isspace(s.at(i)))
        {
            string temp = s.substr(start,i - start);
            cout<<"Temp:"<<temp<<endl;
            mSt.push(temp);
            start = i ;
        }
        i++;
    }
    mSt.push(s.substr(start, i - 1));

    while(!mSt.empty())
    {
        cout<<mSt.top();
        mSt.pop();
    }
}

            

