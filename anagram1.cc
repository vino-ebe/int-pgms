#include<iostream>
using namespace std;

int myhash(char word[]);
int main()
{
    char word1[] = {"sstops"};
    char word2[] = {"pots"};

    if(myhash(word1) == myhash(word2))
    {
        cout<<"They are anagram"<<endl;
    }
    else
    {
        cout<<"Not anagram"<<endl;
    }

return 0;
}

int myhash(char word[])
{
    int size = 4; 
    int mhash = 0;
    for(int i = 0; i < size; i++)
    {
        mhash = mhash + word[i] * 31;
        cout<<"mhash is: "<<mhash<<endl;
    }

    return mhash;
}
