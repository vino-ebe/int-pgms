#include<iostream>
#include<vector>

using namespace std;

void addSpiral(int a[4][4], int row_start, int col_start, int row_end, int col_end, vector<int>& res, int size);

int main()
{
    int a[4][4] = {
                    {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}
                };       

    int row_max = 4;
    int col_max = 4;

    vector<int> res;
    int row_start = 0;
    int col_start = 0;
    int row_end = 3;
    int col_end = 3;
    int size = 4;

    for (int i = 0; i < 2; i++)
    {
        addSpiral(a, row_start, col_start, row_end, col_end, res, size - 1);
        row_start++;
        col_start++;
        row_end--;
        col_end--;
        size = size/2;
    }

    for (int i = 0; i < res.size(); i++) {
        //cout<<res[i]<<endl;
    }
}

void addSpiral(int a[4][4], int row_start, int col_start, int row_end, int col_end, vector<int>& res, int size)
{
    cout<<"First row"<<endl;
    for (int i = row_start; i < size; i++) {
        res.push_back(a[row_start][i]);
        cout<<a[row_start][i]<<endl;
    }

    cout<<"Last col"<<endl;
    for (int i = row_start; i < size; i++) {
        res.push_back(a[i][col_end]);
        cout<<a[i][col_end]<<endl;
    }

    cout<<"Last row"<<endl;
    for (int i = size; i > 0; i--) {
        res.push_back(a[row_end][i]);
        cout<<a[row_end][i]<<endl;
    }

    cout<<"First col"<<endl;
    for (int i = size; i > 0; i--) {
        res.push_back(a[i][col_start]);
        cout<<a[i][col_start]<<endl;
    }
}
                
