#include<iostream>

/*
 * http://www.geeksforgeeks.org/find-possible-words-phone-digits/
 */

using namespace std;

void swap(char *s, char *t);
void permute(char *s, int start, int end,int k);
int r;

int main()
{
    char s[] = "ABC";

    permute(s, 0, 2,4);
    cout<<r<<endl;
}

void permute(char *s, int start, int end, int k)
{

    if(start == end)
    {
        r++;
        if(r == k)
        cout<<s<<endl;

    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(s + start, s + i);
            permute(s, start + 1, end,k);
            swap(s + start, s + i);
        }
    }

}

void swap(char *s, char *t)
{
    char temp;

    temp = *s;
    *s = *t;
    *t = temp;
}
