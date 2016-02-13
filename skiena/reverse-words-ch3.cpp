#include<iostream>

using namespace std;

void reverse(char *str, int len);
void swap( char *str, int i, int j);
void escapeSpace(char *str);

int main()
{
    char str[] = "name Vinoj";
    char *lindex= str;
    char *tStr = str;

    while(*tStr)
    {
        while(*lindex != ' ' && *lindex)
        {
            lindex++;
        }
        reverse(tStr, (lindex - tStr - 1 ));
        //escapeSpace(lindex);
        tStr = ++lindex;
    }

    cout<<"Now the string is:"<<str<<endl;
    reverse(str, strlen(str) - 1);
    cout<<"Reversed string is:"<<str<<endl;
}

void reverse(char *str, int len)
{
    for (int i = 0, j = len ; i < (len/2) + 1; i++, j--)
    {
        swap(str,i,j);
    }
}

void swap( char *str, int i, int j)
{
    char t;
    t = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = t;
}

void escapeSpace(char *str)
{
    while( str && *str != ' ')
    {
        str++;
    }
}
