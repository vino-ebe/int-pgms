#include<iostream>

using namespace std;

void printMatrix(int m[][3]);
void rotateImage(int m[][3]);

int main()
{
    int image[3][3] = { 1,2,3,
                        5,6,7,
                        9,10,11 };

    rotateImage(image);
}

void rotateImage(int m[][3])
{
    /* Clockwise
     * 1    5   9
     * 2    6   10
     * 3    7   11 
     */

    int temp[3][3];
    int col = 2; int row = 0;
    int t;

    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            //temp[row++][col] = m[i][j];
            if( i != j)
            {
                t = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = t;
            }
        }
    }

    printMatrix(m);
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
