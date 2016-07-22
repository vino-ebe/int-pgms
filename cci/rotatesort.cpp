#include<iostream>
void search(int arr[], int num, int low, int high) ;
bool find(int arr[], int num, int size) ;

using namespace std;

int main() {
    int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

    int size = sizeof(arr)/sizeof(arr[0]);

    find(arr, 5, size);
}

bool find(int arr[], int num, int size) {


    search(arr, num, 0, size -1 );

    return true;
}

void search(int arr[], int num, int low, int high) {

    int mid = 0;
    bool found = false;

    while (low < high) {
        mid = (low + high) / 2;
        if (arr[mid] < arr[low]) {
            if (mid != 0) {
                if (arr[mid] < (arr[mid - 1])) {
                    found = true;
                    break;
                }
                high = mid;
            } 
        } else {
            low = mid;
        }
    }

    if (found) {
        cout<<"The rotation index is:"<<mid<<endl;
    } else {
        cout<<"The rotation index not found:"<<endl;
    }
}
