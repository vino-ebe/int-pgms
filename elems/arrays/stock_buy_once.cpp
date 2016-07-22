#include<iostream>

using namespace std;

int buy_sell_twice(int a[], int size);
int main()
{
    //int a[] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    int a[] = {12, 11, 13, 9, 12, 8, 14, 13, 15, 11};

    int size = sizeof(a)/sizeof(a[0]);

    int p = 0; 

    int minIndex = 0;
    int maxIndex = 1;


    while (maxIndex < size) {

        if (a[minIndex] < a[maxIndex]) {

            if (p < (a[maxIndex] - a[minIndex])) {
                p = (a[maxIndex] - a[minIndex]);
            }
        } else {
            minIndex = maxIndex;
        }

        maxIndex++;
    }

    cout<<"Profit is "<<p<<endl;

    cout<<"Profit for buy sell twice is "<<buy_sell_twice(a, size)<<endl;
}

int buy_sell_twice(int a[], int size)
{
    int minIndex = 0;
    int maxIndex = 1;

    int p1 = 0;
    int p2 = 0;

    while (maxIndex < size) {

        if (a[minIndex] < a[maxIndex]) {
            if (p1 < (a[maxIndex] - a[minIndex])) {
                p1 = (a[maxIndex] - a[minIndex]);
            } 
        } else {
            p2 = p1;
            minIndex = maxIndex;
        }

        maxIndex++;
    }

    return p1 + p2;
}
        
