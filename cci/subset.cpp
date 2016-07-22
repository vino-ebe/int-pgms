#include<iostream>

using namespace std;

void printComb(int a[], int n) ;
void generateSubset(int a[], int k, int n);
void generateCoins(int c[], int k, int n) ;
void printCoins(int c[], int n) ;

int main()
{
    int a[3] = { 1, 2, 3};
    int k = 0, n = 3;
    int c[4] = { 25, 10, 5, 1};
    //generateSubset(a, k, n);
    generateCoins(c, 0, 4);
}

void generateSubset(int a[], int k, int n)
{
    if (k == n) {
        printComb(a, n);
        return;
    }
    
    int bitTable[2] = { 1, 0};
    for (int i = 0; i < 2; i++) {
        a[k] = bitTable[i];
        generateSubset(a, k + 1, n);
    }
}

void generateCoins(int c[], int k, int n) {
    if (k == n) {
        printCoins(c, n);
        return;
    }

    int bitTable[2] = { 1, 0};
    for (int i = 0; i < 2; i++) {
        c[k] = bitTable[i];
        generateCoins(c, k + 1, n);
    }
}

void printCoins(int c[], int n) {
    int y[4] = { 25, 10, 5, 1};
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (c[i]) {
            sum = sum + y[i];
        }
    }
    cout<<sum<<endl;
}

void printComb(int a[], int n) {
    int x[3] = {1, 2, 3};
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            cout<<x[i];
        }
    }
    cout<<endl;
}
