#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

using namespace std;

int polish(string n[10]);
int dooperation(int ch1, int ch2, char op);

int main()
{
    string notation[10] = {"2","101","+","3","*"};

    int res;

    res = polish(notation);

    cout<<"Result:"<<res<<endl;
}

int polish(string n[10])
{
    stack<int> st;

    for(int i = 0; i < 5; i++)
    {
        if(isdigit(n[i][0]))
        {
            int n1  = atoi(n[i].c_str());
            st.push(n1);
        }
        else 
        {
            int arg1 = st.top();
            st.pop();
            int arg2 = st.top();
            st.pop();
            st.push(dooperation(arg1,arg2,n[i].at(0)));
        }
    }

    return st.top();
}

int dooperation(int ch1, int ch2, char op)
{
    int val1 = ch1 ;
    int val2 = ch2 ;
    int res = 0;

    switch(op)
    {
        case '+':
            res = val1 + val2;
            break;

        case '-':
            res = val1 - val2;
            break;

        case '*':
            res = val1 * val2;
            break;

        case '/':
            res = val1 / val2;
            break;

         default:
            res = -1;
    }

    return res;
}
    
