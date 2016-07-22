#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

bool checkValid(int row, int columns[], int col) ;
void placeQueens(int row, int columns[], vector<int*>& res) ;

int main()
{
    int row = 0;
    int columns[8];
    vector<int*> result;
    placeQueens(row, columns, result);

    for (int i = 0; i < result.size(); i++) {
        int *col = result[i];
        for (int j = 0; j < 8; j++)
        {
            cout<<*(col + i);
        }
        cout<<endl;
    }
            
}

void placeQueens(int row, int columns[], vector<int*>& res) {
    if (row == 8) {
    //    cout<<"Placed All the Queens"<<endl;
        int *tcols = new int[10];
        for (int i = 0; i < 8; i++) {
            tcols[i] = columns[i];
        }
        //memcpy(tcols, columns, 8);
        res.push_back(tcols);
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (checkValid(row, columns, i)) {
            columns[row] = i;
            placeQueens(row + 1, columns, res);
        }
    }
}

bool checkValid(int row, int columns[], int col) {
    int prevCol;
    for (int prevRows = 0; prevRows < row; prevRows++) {
        prevCol = columns[prevRows];

        if (prevCol == col) {
            return false;
        }

        if (abs(row - prevRows) == abs(prevCol - col)) {
            return false;
        }
    }

    return true;
}
        

