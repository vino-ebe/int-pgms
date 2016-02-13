#include<iostream>
using namespace std;

int array[] = {5,2,1,9,3,10,3,7,11};

void selsort(int array[],int size);
void
swap(int (array)[],int i, int minIndex) ;
void printList(int array[],int size) ;
void inssort(int array[],int size) ;

void merge(int a[], int low, int high, int mid) ;
void partition(int a[],int right, int left) ;
int main()
{

    int size = sizeof(array)/sizeof(int);
    //selsort(array,size);
    //inssort(array,size);
    int a[] = {3,7,12,14,2,11,9,6};
    //merge(a,0,7,3);
    partition(a,7,0);
    return 0;
}

void selsort(int array[],int size)
{
    cout<<"Selection sort"<<endl;
    int minItem = array[0];
    int minIndex = 0;

    for(int i = 0; i < size; i++) {
        minIndex = i;
        for(int j = i; j < size; j++) {
            if(array[j] < array[minIndex]) {
                swap(array,j,minIndex);
            }
        }
    }

    printList(array,size);
}

void inssort(int array[],int size) {
    cout<<"Insertion Sort"<<endl;
int curIndex;

    for(int i = 0; i < (size - 1);i++) {
        curIndex = i + 1;
        for(int j = i ; j >= 0;j--) {
            if(array[curIndex] < array[j]) {
                swap(array,curIndex,j);
                curIndex = j;
            }

        }
    }
    printList(array,size);

}

void merge(int a[], int low, int high, int mid) {

    int lowHalfSize = low+mid+1;
    int highHalfSize = mid+high+1;

    int t[10];
    int i = low, l = low;
    int h = high;
    int j = mid + 1;

    //int a[] = {3,7,12,14,2,6,9,11};
    //compare the first element of first half with first element of second half.
    //if the first half has the smallest element, increment first half index, and vice versa
    while(l <= mid && j <= h) {
        if(a[l] < a[j]) {
            t[i] = a[l];
            i++;
            l++;
        } else {
            t[i] = a[j];
            j++;
            i++;
        }
    }

    // This loop is requied because, either half can be skewed and we still have elements in the either half which are not copied to t.
    // append them to the array t. Since they are already sorted, there is no comparison required.
    if(l <= mid) {
        while(l <= mid) {
            t[i] = a[l];
            l++;
            i++;
        }
    }

    if(j <= high) {
        while(j <= high) {
            t[i] = a[j];
            j++;
            i++;
        }
    }
    printList(t,high+1);
}

void partition(int a[],int right, int left) {

    int pivot = a[right]; 

    int i = left; 
    int j = right;
    int rindex = right;
    int pIndex = right;
    //int a[] = {3,7,12,14,2,6,9,11};
   
    while(i < j) {
        while(a[i] < pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(a[i] > a[j]) {
            swap(a,i,j);
        }
    }
        
    printList(a,right+1);
}

        


void printList(int array[],int size) {
    cout<<"Sorted list:"<<endl;
    for(int i = 0; i < size; i++) {
       cout<<array[i]<<endl;
    }
}
    

void
swap(int (array)[],int i, int minIndex) {
    int t = array[i];
    array[i] = array[minIndex];
    array[minIndex] = t;
}
