#include<iostream>
using namespace std;

void printMatrix(int m[][3]);
int main()
{
    int mat[3][3] = { 1, 2, 0,
                      3, 0, 1,
                      4, 1, 4 };

    int row_visited[3] = {};
    int col_visited[3] = {};

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(mat[i][j] == 0 && !row_visited[i] && !col_visited[j])
            {
                for(int k = 0; k < 3; k++)
                {
                    mat[i][k] = 0;
                    mat[k][j] = 0;
                }

                row_visited[i] = 1;
                col_visited[j] = 1;
                break;
            }
        }
    }

    printMatrix(mat);

    return 0;
}

void printMatrix(int m[][3])
{
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}
