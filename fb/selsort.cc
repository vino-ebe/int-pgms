#include<iostream>

using namespace std;

void selSort(int num[]);
void swap(int num[],int i,int j);
void merge(int num[],int first,int last, int mid);
void mergeSort(int num[],int first,int last);

int main()
{
    //int num[] = {10,3,12,0,13,9};
    int num[] = {10,3,12,0};
    //selSort(num);
    int size = sizeof(num)/sizeof(num[0]);
    cout<<"Merge Sort"<<endl;
    mergeSort(num,0,size -1);
    for(int i = 0; i < 4; i++)
    {
        cout<<num[i]<<endl;
    }
}

void selSort(int num[])
{
    int size = 6; 

    int small;
    int smallIndex = 0;
    bool swapreq = false;

    for(int i = 0;i < size; i++)
    {
        small = num[i];
        for(int j = i ; j < size; j++)
        {
            if(num[j] < small)
            {
                small = num[j];
                smallIndex = j;
                swapreq = true;
            }
        }

        if(swapreq)
        {
            swap(num,i,smallIndex);
            swapreq = false;
        }
    }
    
    cout<<"Sorted array"<<endl;
    for(int i = 0; i < 6; i++)
    {
        cout<<num[i]<<endl;
    }
}

void mergeSort(int num[],int first,int last)
{
    int mid;

    if(first < last)
    {
        mid = (first + last) / 2;
        mergeSort(num,first,mid);
        mergeSort(num,mid+1,last);
        merge(num,first,last,mid);
    }
}

void merge(int num[],int first,int last, int mid)
{
    int n1 = (mid - first) + 1;
    int n2 = (last - mid);

    int lh[(mid - first) + 1];
    int uh[last - mid];
    
    for (int i = 0; i < n1; i++)
    {
        lh[i] = num[first + i];
    }

    for (int i = 0; i < n2; i++)
    {
        uh[i] = num[(mid + 1) + i];
    }

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if(lh[i] < uh[j])
        {
            num[k] = lh[i];
            i++;
            k++;
        }
        else
        {
            num[k] = uh[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        num[k++] = lh[i];
        i++;
    }

    while (j < n2)
    {
        num[k++] = uh[j];
        j++;
    }
}

void swap(int num[],int i,int j)
{
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}
