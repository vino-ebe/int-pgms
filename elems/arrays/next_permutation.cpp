#include<iostream>

using namespace std;

void swap(int a[], int x, int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
}

int main()
{
    int p[] = {6, 2, 1, 5, 4, 3, 0};

    int size = sizeof(p)/sizeof(p[0]);

    int suffix_index = 0;
    // Find the longest decreasing suffix
    
    for (int i = size - 1; i > 0; i--) {
        if (p[i] > p[i - 1]) {
            suffix_index = i;
            break;
        }
    }

    // Find the smallest number in the prefix
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < suffix_index; i++) {
        if (p[i] < min) {
            min_index = i;
            min = p[i];
        }
    }

    // Find a number in the suffix which is greater the min but smallest
    min = INT_MAX;
    int suffix_min = -1;
    for (int i = suffix_index; i < size; i++) {
        if ((p[i] < min) && (p[i] > p[min_index])) {
            min = p[i];
            suffix_min = i;
        }
    }

    // swap min_index and suffix min
    
    swap(p, min_index, suffix_min);

    // Reverse the suffix

    int j;
    int c = (size / 2) + suffix_index;
    for (int i = suffix_index, j = size - 1; i < c && j > c; i++, j--) {
        swap(p, i, j);
    }

    cout<<"The next permutation is"<<endl;
    for (int i = 0; i < size; i++) {
        cout<<p[i]<<endl;
    }
}
