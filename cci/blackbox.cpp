/*Imagine you have a square matrix, where each cell (pixel) is either black or white.
Design an algorithm to find the maximum subsquare such that all four borders are
filled with black pixels.
*/

#include<iostream>

using namespace std;

#define MAX_ROW 2
#define MAX_COL 2

#define BLACK   1
#define WHITE   0

bool isSquare(int box[3][3], int start_row, int end_row, int start_col, int end_col) ;
int main()
{
    int box[3][3] = { 0, 0, 1,
                      1, 1, 0,
                      1, 1, 0 };

    int start_row = 0;
    int end_row = 2;
    int start_col = 0;
    int end_col = 2;
    int max_start_row = MAX_ROW + 1;
    int max_end_row = -1;

    while (start_row < MAX_ROW && end_col > 0) {
        if (isSquare(box, start_row, end_row, start_col, end_col)) {
            cout<<"Found Square"<<endl;
             int val = MAX_ROW - start_row;
             if (val < max_start_row) {
                 max_start_row = start_row;
                 max_end_row = end_row;
             }
        }
        start_row++;
        end_col--;
    }

    start_row = 0;
    end_row--;
    start_col = 0;
    end_col = 2;

    while (start_col > MAX_COL) {
        isSquare(box, start_row, end_row, start_col, end_col);
        start_col++;
        cout<<"Found Square"<<endl;
            int val = MAX_ROW - start_row;
            if (val < max_start_row) {
                max_start_row = start_row;
                max_end_row = end_row;
            }
    }

    cout<<"The big square is at "<<max_start_row<<"and "<<max_end_row<<endl;
}

bool isSquare(int box[3][3], int start_row, int end_row, int start_col, int end_col) {
    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            if (box[i][j] == WHITE) {
                return false;
            }
        }
    }
    return true;
}
