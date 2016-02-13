#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "redrumsirismurder";

    int left = 0;
    int right = s.size() - 1;

    while(left != right)
    {
        if(!isalpha(s.at(left)))
                left++;

        if(!isalpha(s.at(right)))
                right--;

        if(s.at(left) != s.at(right))
        {
            cout<<"Not Palindrome"<<endl;
            break;
        }
        left++;
        right--;
    }

    if(left == right)
        cout<<"Palindrom"<<endl;

}

