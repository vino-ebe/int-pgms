//https://www.youtube.com/watch?v=p8SDPaX1wgw
#include<iostream>
using namespace std;

void print_comb(int a[], int k, int n);
void backtrack_comb(int a[], int k, int n);
void backtrack_perm(int a[], int k, int n);
void print_perm(int a[], int k, int n);
void swap(int a[], int i, int j);
void backtrack_digipad(char a[3][4], int k, int n, char *output);
void swap(int a[], int i, int j);
void print_phone(char a[], int n);

int main()
{
    int a[10] = {1, 2, 3};;
    //backtrack_comb(a, 0, 3);
    int p[5] = {1, 2, 3, 4};
    backtrack_perm(p, 0, 4);
    char arr[3][4] = {"abc","def","ghi"};
    char output[4];
//    backtrack_digipad(arr, 0, 3, output);
}

void backtrack_comb(int a[], int k, int n) 
{
    int ttable[2] = {0, 1};

    if (k == n ) {
        print_comb(a, k, n);
    } else {
        //k = k + 1;

        for (int i = 0; i < 2; i++) {
            a[k] = ttable[i];
            backtrack_comb(a, k+1, n);
        }
    }
}

void print_comb(int a[], int k, int n)
{
    cout<<"{";
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cout<<i+1;
        }
    }
    cout<<"}"<<endl;
}

void backtrack_perm(int a[], int k, int n)
{
    if (k == n) {
        print_perm(a, k, n);
    } else {
        for (int i = k; i < n; i++) {
            swap(a, i, k);
            backtrack_perm(a, k + 1, n);
            swap(a, i , k);
        }
    }
}

void print_perm(int a[], int k, int n)
{
    cout<<"{";
    for (int i = 0; i < n; i++) {
        cout<<a[i];
    }
    cout<<"}"<<endl;
}

void backtrack_digipad(char a[][4], int k, int n, char *output)
{
    if (k == n) {
        print_phone(output, n);
    } else {
        for (int i = 0;i < n;i++) {
            output[k] = a[k][i];
            backtrack_digipad(a, k + 1, n, output);
        }
    }
}

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void print_phone(char a[], int n)
{
    cout<<"{";
    for (int i = 0; i < n; i++) {
        cout<<a[i];
    }
    cout<<"}"<<endl;
}
