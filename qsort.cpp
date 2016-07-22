#include<iostream>
using namespace std;

void swap(int a[], int x, int y) ;
void quicksort(int a[], int len);
void quicksort_rec(int a[], int left, int right);
int partition(int a[], int left, int right) ;

int main()
{
    int a[] = {10, 20, 8, 15, 23, 7, 9};
    quicksort(a, 7);
}

void quicksort(int a[], int len)
{
    quicksort_rec(a, 0, len -1);
    for (int i = 0; i < 5; i++) {
        cout<<a[i]<<endl;
    }
}

void quicksort_rec(int a[], int left, int right)
{
    if (left < right) {
        int index = partition(a, left, right);
        quicksort_rec(a, left, index - 1);
        quicksort_rec(a, index + 1, right);
    }
}

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int pindex = right;

    for (int i = 0; i < right; i++) {
        if (a[i] > pivot) {
            swap(a, i, pindex);
            pindex = i;
        }
    }
    return pindex;
}

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
