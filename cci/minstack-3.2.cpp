/*How would you design a stack which, in addition to push and pop, also has a
 * function min which returns the minimum element? Push, pop and min should
 * all operate in O(1) time.
 */

#include<iostream>
#include<stack>

using namespace std;

class mystack {
    private:
        static const int STACK_SIZE = 100;
        int st[STACK_SIZE];
        int top;
        stack<int> minStack;

    public:
        mystack() {
            top = -1;
        }

        void push(int data) {
            if (top < STACK_SIZE) {
                top++;
                st[top] = data;
            }
            if (data < min()) {
                minStack.push(data);
            }
        }

        int pop() {
            if (top == -1) {
                cout<<"Pop from a Empty Stack"<<endl;
                return top;
            } else {
                if (st[top] == min()) {
                    minStack.pop();
                }
                return  st[top--];
            }
        }

        int min() {
            if (minStack.empty()) {
                return INT_MAX;
            } else {
                return minStack.top();
            }
        }
};
            
int main()
{
    mystack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Top of stack is:"<<s.pop()<<endl;
    cout<<"Min of stack is:"<<s.min()<<endl;
}
