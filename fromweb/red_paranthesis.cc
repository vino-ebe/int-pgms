/* Find if the given expression contains redundant parantheses. ex :if expr = a+(b*c) , print
 * false, if expr = a+((b*c)), print true.
*/

#include<iostream>

using namespace std;

int main()
{
    string expr = "a + ((b * c))";

    for (int i = 0; i < expr.size(); i++) {
        switch(expr[i]) {
            case '(':
                if (i != 0) {
                    if (expr[i - 1] == '(') {
                        cout<<"Redundant found"<<endl;
                    }
                }
                break;

            case ')':
                if (i != 0) {
                    if (expr[i - 1] == ')') {
                        cout<<"Redundant found"<<endl;
                    }
                }
                break;

            default:
                break;
        }
    }
}
