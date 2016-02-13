/*A common problem for compilers and text editors is determining whether the
 * parentheses in a string are balanced and properly nested. For example, the string
 * ((())())() contains properly nested pairs of parentheses, which the strings )()( and
 * ()) do not. Give an algorithm that returns true if a string contains properly nested
 * and balanced parentheses, and false if otherwise. For full credit, identify the position
 * of the first offending parenthesis if the string is not properly nested and balanced
 */
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkIfBracketsMatch(char ch1, char ch2);

int main()
{
    //string str("()())())()");
    string str(")()(");
    string leftBrackets = "{([";
    string rightBrackets = "})]";
    stack<char> st;
    
    /* Pick first char of string
     * If stack is empty, check if the char is found in left bucket
     * if found, push it to the stack
     * if not found return false.
     * if a char from right bucket is found, compare it with the top of stack
     * The top of stack should be its left mate, if not return false
     */

    for (int i = 0; i < str.size(); i++)
    {
        if (st.empty() )
        {
            if (leftBrackets.find(str.at(i)) != -1)
            {
                st.push(str.at(i));
            }
            else if (rightBrackets.find(str.at(i)) != -1)
            {
                cout<<"BAD STRING at pos "<<i<<endl;
                return 0;
            }
            else
            {
                cout<<"INVALID STRING"<<endl;
                return 0;
            }
        }
        else
        {
            if (leftBrackets.find(str.at(i)) != -1)
            {
                st.push(str.at(i));
            }
            else if (rightBrackets.find(str.at(i)) != -1)
            {
                if (!checkIfBracketsMatch( st.top(), str.at(i)))
                {
                    cout<<"BAD STRING at pos "<<i<<endl;
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                cout<<"INVALID STRING"<<endl;
                return 0;
            }
        }
    }

    cout<<"Successful string"<<endl;
}

bool checkIfBracketsMatch(char ch1, char ch2)
{
    switch(ch1)
    {
        case '{':
            if (ch2 == '}')
            {
                return true;
            }
            else
            {
                return false;
            }
            break;

        case '(':
            if (ch2 == ')')
            {
                return true;
            }
            else
            {
                return false;
            }
            break;

        case '[':
            if (ch2 == ']')
            {
                return true;
            }
            else
            {
                return false;
            }
            break;

        default:
            cout<<"Default"<<endl;
            return false;
            break;
    }
}
