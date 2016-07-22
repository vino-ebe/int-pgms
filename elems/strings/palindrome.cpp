#include<iostream>
#include<string>

using namespace std;

bool isspecialchar(char ch) {
    if ((ch == ' ') || (ch == ',') || (ch == '!')) {
        return true;
    } else {
        return false;
    }
}

bool isPalindrome(string str)
{
    int size = str.size();
    int i = 0;
    int j = size - 1;;

    while (i < (size/ 2)) {
        if (str[i] != str[j]) {
            if (isspecialchar(str[i])) {
                i++;
                continue;
            }

            if (isspecialchar(str[j])) {
                j--;
                continue;
            }
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main()
{
    string str("step on no pets");

    if (isPalindrome(str)) {
        cout<<"It is a palindrome"<<endl;
    } else {
        cout<<"It is not a palindrome"<<endl;
    }
}
