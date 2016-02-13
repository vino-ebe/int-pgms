#include<iostream>

int main()
{
    int matrix[4][3] = { 1,1,1},
                       { 2,2,2},
                       { 3,0,3},
                       { 4,4,4};

}
void checkzero(char **mat, int &row, int &col)
{
    bool found = false;
    for(int i = 0; i < 4 && (found == false); i++)
    {
        for(int j = 0; j < 3;j++)
        {
            if(mat[i][j] == 0)
            {
                row = i;
                col = j;
                found = true;
                break;
            }
        }
    }
}

void setzero(char **mat, int row, int col)
{
    for(int i = 0;i < 4;i++)
    {
        mat[col][i] = 0;
    }
    for(int j = 0;j < 3;j++)
    {
        mat[j][row] = 0;
    }
}
