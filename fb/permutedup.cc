#include<iostream>
#include<map>
#include<string>
#include<cstdlib>

using namespace std;

void swap(int *i, int *j);
void permute(int a[], int l, int r);
void hashResult(int a[], string& s, int size);

int main()
{
    int a[] = {1, 1, 3};

    string dup[6];
    int dupIndex = 0;

    permute(a, 0, 2);
}

    map<string,int> permString;
void permute(int a[], int l, int r)
{
    map<string,int>::iterator it;

    if (l == r)
    {
        string s;
        hashResult(a, s,3);
//        if ((it = permString.find(s.c_str())) == permString.end())
        {
            permString[s.c_str()] = 1;
            cout<<"Permuted: "<<s.c_str()<<endl;
        }
    }
    else
    {
        for (int i = l; i < r; i++)
        {
            swap(a + 1, a + i);
            permute(a, l + 1, r);
            swap(a + 1, a + i);
        }
    }
}

void hashResult(int a[], string& s, int size)
{
    for (int i = 0; i < size; i++)
    {
        char c = a[i] + '0';
        s = s + c; 
    }
}

void swap(int *i, int *j)
{
    int t = *i;
    *i = *j;
    *j = t;
}
