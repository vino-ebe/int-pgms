#include<iostream>

using namespace std;

int main()
{
    int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};

    int size = sizeof(a)/sizeof(a[0]);

    int i = 0;
    int j = 1, m = 0, n = 0;
    while(j < size) {
        if ( a[i] > a[j]) {
            m = j;
            break;
        }
        i++;
        j++;
    }

    i = size - 1;
    j = i - 1;

    while(j >= 0) {
        if ( a[i] < a[j]) {
            n = j;
            break;
        }
        i--;
        j--;
    }

    cout<<"M is "<<m<<" N is "<<n<<endl;
    i = 0;
    j = 0;
    // from M to N, verify if there any number which is smaller on the left
    int mid_size = (n - m) + 1;
    int new_n = 0;
    for (i = m; i < m + mid_size; i++) {
        for (j = n + 1; j < size; j++) {
            if (a[i] >= a[j]) { 
                new_n = j;
            }
        }
    }

    int new_m = 0;
    for (int i = m; i < m + mid_size; i++) {
        for (j = 0; j <= m; j++) {
            if (a[i] <= a[j]) { 
                new_m = j;
                break;
            }
        }
    }

    //n = new_n;
    cout<<"New M is "<<new_m<<"New N is "<<new_n<<endl;

}
