#include<iostream>
#include<string>

using namespace std;
bool isPalindrome(string s);

/* This program should find the longest palindrome from a given strinf.
 * For ex: i/p: bananas. o/p: anana.
 */

int main()
{
    string s = "bananas";
    string maxPalinStr;

    int maxPalindromeLen = 0;

    for (int i = 0;i < s.size();i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if(isPalindrome(s.substr(i, j + 1)))
            {
                maxPalindromeLen = j - i;
                maxPalinStr = s.substr(i, j + 1); 
            }
        }
    }

    cout<<"Max Palindrom substring:"<<maxPalinStr<<endl;
}

bool isPalindrome(string s)
{
    int j = s.size();
    if (j == 1)
        return true;

    for(int i = 0; i < s.size()/2; i++,j--)
    {
        if(s.at(i) != s.at(j - 1))
            return false;
    }

    return true;
}
