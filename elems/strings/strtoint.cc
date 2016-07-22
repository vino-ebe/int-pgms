#include<iostream>
#include <string>
#include<cmath>

using namespace std;

bool stringToInt(const string& str, int& t);
bool intToString(int &number, string& s);

int main()
{
    string s = "f1234";
    int res = 0;
    stringToInt(s,res);
    cout<<"Integer is "<<res<<endl;
    string s1;
    intToString(res,s1);
    cout<<"String is "<<s1<<endl;
}

bool stringToInt(const string& s, int& t)
{
    if(!s.size())
    {
        return false;
    }

    int result = 0, j; 

    for(int i = s.size() - 1, j = 0; i >= 0; i--,j++)
    {
        if(s.at(i) > '0' && s.at(i) < '9')
        {
            t += (s.at(i) - '0') * pow(10,j);
        }
        else
        {
            cout<<"Invalid Numeric string"<<endl;
            return false;
        }
    }

    return true;
}

bool intToString(int &number, string& s)
{
    if(number < 0)
    {
        return false;
    }
    string s1;
    while(number)
    { 
        s1 = (number%10) + '0';
        s = s1 + s;
        number = number / 10;
    } 
}
