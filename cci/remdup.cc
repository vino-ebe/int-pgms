#include<iostream>

using namespace std;

void removeDups(int a[], int index, int size, int numDups, int& newSize);
int getNumDups(int a[], int index, int size);
int removeDups1(int a[], int size);

int main()
{
    int a[] = {1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9};
    int num_dup = 0;
    int size = sizeof(a)/sizeof(a[0]);
    bool need_copy = false;
    int newSize = size, dups = 0;

    newSize = removeDups1(a, size);
#if 0
    for(int i = 0; i < size ; i++) {
        if (a[i] == a[i + 1]) {
            if (num_dup >= 2 ) {
                dups = getNumDups(a, i, size);
                removeDups(a, i, size, dups, newSize);
            }
            num_dup++;
        }
    }

#endif
    for (int i = 0; i < newSize; i++) {
        cout<<a[i]<<endl;
    }
}

int removeDups1(int a[], int size)
{
    if (size < 2)
    {
        return size;
    }

    int i = 1;
    int j = 0;

    while(i < size) {
        if (a[i] == a[j]) {
            i++;
        } else {
            j++;
            a[j] = a[i];
            i++;
        }
    }

    return j + 1;
}

void removeDups(int a[], int index, int size, int numDups, int& newSize)
{
    int x = index;
    int i = 0;
    bool sizeExceed = false;
    if ((x + 1 + numDups) < newSize) {
        while(x < size) {
            a[x + 1] = a[x + 1 + numDups];
            x++;
        }
    } else {
        sizeExceed = true;
    }

//    if (!sizeExceed) {
        newSize = newSize - numDups;
  //  }
}

int getNumDups(int a[], int index, int size)
{
    int i = 0;
    int num_dup = 0;

    while (index < size - 1) {
        if (a[index] == a[index + 1]) {
            num_dup++;
            index++;
        } else {
            break;
        }
    }
    return num_dup;
}
                


