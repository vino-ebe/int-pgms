#include<iostream>
#include<array>

using namespace std;

void swap(int arr[], int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void partition(int arr[], int index)
{
    int s = 0;
    int p = 9;
    int lindex = 0;
    int rindex = p - 1;

    int pivot = arr[index];

    while (s < p)
    {
        if (arr[s] < pivot) {
            swap(arr, s, lindex++);
        }

        s++;
    }

    cout<<"Array after first pass is "<<endl;
    for (int i = 0; i < 9; i++) {
        cout<<arr[i]<<endl;
    }

    for (int i = 8; i >= 0 ; --i) {
        if (arr[i] > pivot) {
            swap(arr, i, rindex--);
        }
    }

    cout<<"Array is "<<endl;
    for (int i = 0; i < 9; i++) {
        cout<<arr[i]<<endl;
    }
}

void partition2(int arr[], int index) {
    int lindex = 0;
    int rindex = 9;
    int cur = 0;
    int size = 9;

    int pivot = arr[index];

    while (cur < rindex) {
        if (arr[cur] < pivot) {
            swap(arr, cur++, lindex++);
        } else if (arr[cur] == pivot) {
            cur++;
        } else {
            swap(arr, cur++, --rindex);
        }
    }

    cout<<"Array is "<<endl;
    for (int i = 0; i < 9; i++) {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[] = { 7, 9, 2, 8, 0, 4, 3, 12, 5 };

    partition2(arr, 3);

}
