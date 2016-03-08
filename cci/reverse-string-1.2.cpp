/*Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated
string.
*/

#include<iostream>
using namespace std;

void swap(char *s, int i, int j);
int main()
{
    char str[] = {"I am a big boy"};
    int len = strlen(str);
    int j = len - 1;
    cout<<"Original string:"<<str<<endl;
    for (int i = 0; i < len/2; i++) {
        swap(str, i, j);
        j--;
    }
    cout<<"Reversed string:"<<str<<endl;
}

void swap(char *s, int i, int j)
{
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}
