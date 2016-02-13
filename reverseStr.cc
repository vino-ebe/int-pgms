#include<iostream>
using namespace std;

void reverse(char *str);
void stringcompress(char *str);

int main()
{
    char str[] = "Hello";
    //reverse(str);
    //cout<<"str is"<<str<<endl;
    char str1[] = "aabccccaaa";
    stringcompress(str1);
    cout<<"str is"<<str1<<endl;
}

void reverse(char *str)
{
    char *tstr = str;
    int len = strlen(str);
    int i = 0, j = len -1,k = len/2;
    char t;
    while(k)
    {
        t = tstr[i];
        tstr[i] = tstr[j];
        tstr[j] = t;
        i++;
        j--;
        k--;
    }
}

void stringcompress(char *str)
{
    char *tstr = str;
    char dstr[20];
    int len = strlen(str);
    int j = 0,c =1, i = 0;
    while(i < len)
    {
        dstr[j]=*(tstr+i);
        j++;
        c = 1;
        while(*(tstr+i) == *(tstr+i+1))
        {
            c++;
            i++;
        }
        dstr[j]=c+'0';
        j++;
        i++;
    }

    cout<<"Final string is"<<dstr<<endl;
}
