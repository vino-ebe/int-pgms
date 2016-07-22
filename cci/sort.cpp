#include<iostream>
#include<queue>

using namespace std;

void mergesort(int a[], int low, int high) ;
void merge(int a[], int low, int mid, int high) ;
void quicksort(int a[], int low, int high) ;
int partition(int a[], int low, int high) ;
void radixSort(int a[], int n);
void printNum(int a[], int len) ;
void swap(int a[], int i, int j) ;
int getMax(int a[], int n) ;

int main()
{
    int a[] = {6, 9, 3, 1, 7, 2, 4};
//    mergesort(a, 0, 6);
    //quicksort(a, 0, 6);
    radixSort(a, 7);

    printNum(a, 7);
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int lowhalf[8];
    int upperhalf[8];
    int i = 0, j = 0, k = 0, u = 0, m = 0;
    for (i = 0; i <= mid; i++) {
        lowhalf[k++] = a[i];
    }

    for (j = mid + 1; j <= high; j++) {
        upperhalf[u++] = a[j];
    }
    
    int k1 = 0, u1 = 0;
    // Now merge lower half wuth upper half
    while (k1 < k && u1 < u) {
        if (lowhalf[k1] < upperhalf[u1]) {
            a[m++] = lowhalf[k1++];
        } else {
            a[m++] = upperhalf[u1++];
        }
    }

    if (k1 < k) {
        while (k1 < k) {
            a[m++] = lowhalf[k1++];
        }
    }

    if (u1 < u) {
        while (u1 < u) {
            a[m++] = upperhalf[u1++];
        }
    }
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int pIndex = high;

    while(low < high) {

        do {
            if (a[low] < pivot) {
                low++;
            } else {
                break;
            }
        } while(low < high);

        do {
            if (a[high] > pivot) {
                high--;
            } else {
                break;
            }
        } while(low < high);

        if (a[low] > a[high]) {
            swap(a, low, high);
        }
    }

    for (int i = 0; i < 7; i++) {
        if (a[i] == pivot) {
            return i;
        }
    }
    
    return high;
}

void radixSort(int a[], int n)
{
    int maxDigits = getMax(a, n);
    int x = 0, j = 0, exp = 1, num = 0;
    queue<int> q[10];
    while (x < maxDigits) {

        for (int i = 0; i < n; i++) {
            num = (a[i] / exp) % 10;
            q[num].push(a[i]);
        }

        for (int i = 0; i < 10; i++) {
            while(!q[i].empty()) {
                a[j++] = q[i].front();
                q[i].pop();
            }
        }
        x++;
        j = 0;
        exp = exp * 10;
    }
}

void printNum(int a[], int len) {
    for (int i = 0; i < len; i++) {
        cout<<a[i]<<endl;
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int getMax(int a[], int n) {
    int max = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    while ( (max/10) > 0) {
        count++;
    }
    return count + 1;
}
