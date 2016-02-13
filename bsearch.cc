#include<iostream>

using namespace std;
int bsearch(int a[],int search,int size);
int main()
{

    int a[] = {0,5,13,19,22,41,55,68,72,81,98};

    int size = sizeof(a)/sizeof(int);
    bsearch(a,98,size);

    return 0;
}

int bsearch(int a[],int search,int size)
{
    int low = 0, high = size - 1, middle;

    bool found = false;

    while(low <= high) 
    {
       middle = (high + low)/ 2;
       if(search == a[middle])
       {
          cout<<"Found"<<endl;
          found = true;
          break;
       }
       else if(search < a[middle])
       {
            high = (middle - 1);
       }
       else
       {
           low = middle + 1;
       } 
    }

    if(!found)
        cout<<"Element not found"<<endl;

    return 1;
}
