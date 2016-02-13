#include<iostream>

int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);
void swap(int a[], int i, int j);

int main()
{
    int a[] = {2,9,1,23,7,14,6};

    quicksort(a, 0, 6);

    std::cout<<"Sorted list"<<std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout<<a[i]<<std::endl;
    }
}

void quicksort(int a[], int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(a, low, high);
        quicksort(a, low, pivot -1);
        quicksort(a, pivot + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int left = low;
    int right = high;
    int pivot = a[high];
    int pIndex = high;

    while (left < right)
    {
        while (a[left] < pivot)
        {
            left++;
        }

        while (a[right] > pivot)
        {
            right--;
        }

        if (a[left] > a[right])
        {
            swap(a, left, right);
        }
    }

    for (int i = 0; i < 7; i++)
    {
        if (a[i] == pivot)
        {
            pIndex = i;
            break;
        }
    }

    return pIndex;
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
