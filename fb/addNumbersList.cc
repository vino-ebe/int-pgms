#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> s1,s2,s3;

    s1.push(3);
    s1.push(4);
    s1.push(2);

    s2.push(4);
    s2.push(6);
    s2.push(5);

    int carry = 0;
    int n1, n2;

    while(!s1.empty() && !s2.empty())
    {
        n1 = s1.top();
        n2 = s2.top();

        if((n1 + n2) > 9)
        {
            s3.push( (n1 + n2 + carry) % 10);
            carry = (n1 + n2) / 10;
        }
        else
        {
            s3.push(n1 + n2 + carry);
        }
        
        s1.pop();
        s2.pop();
    }

    while(!s3.empty())
    {
        cout<<s3.top()<<endl;
        s3.pop();
    }
}
