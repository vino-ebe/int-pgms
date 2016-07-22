#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool convertBase(int n1, int b1, string& res, int b2);
int main()
{
    string res;
    int n1 = 0x1E;
    convertBase(n1,16,res,2);
    cout<<"res is"<<res<<endl;
}

bool convertBase(int n1, int b1, string& result, int b2)
{
    int q = n1,r;

    int power = 0, res = 0;
    int q1 = 0;
    string digits;
    int n2 = n1;
    if(b1 != 10)
    {
        for(;n2; n2=n2/b1)
        {
            res += (n2 % b1) * pow(b1,power++);
        }
        cout<<"Intermediate base 10 is "<<res<<endl;
    }

    q = res;
    power = 0;
    switch(b2)
    {
        case 16:
            digits = "0123456789ABCDEF";
            break;

        case 8:
            digits = "012345678";
            break;

        case 2:
            digits = "01";
            break;
        default:
            cout<<"Base not supported"<<endl;
            return false;
    }

    while(q)
    {
       q1 = q; 
       q = q1 / b2; 
       r = q1 % b2;
       result = digits[r] + result;
    }

    return true;
}
