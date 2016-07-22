#include<iostream>

using namespace std;

void swap(string& str, int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void reverse(string& str, int start, int end)
{
    int size = end - start;
    int i = start, j = (start + size) - 1;

    while (i < j) {
        swap(str, i++, j--);
    }
}

int main() {
    string str("My name is vinoj");

    reverse(str, 0, str.size());
    cout<<"Reversed string is:"<<str<<endl;

    int cur  = 0;
    int i = 0;
    while(i < str.size()) {
        if (str[i] == ' ') {
            reverse(str, cur, i);
            cur = i + 1;
        }
        i++;
    }
    reverse(str, cur, str.size());
    cout<<"Reversed string is:"<<str<<endl;
}
