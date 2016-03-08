/* Given an image represented by an NxN matrix, where each pixel in the image is
 * 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
 * place?
 */

#include <iostream>

using namespace std;

void swap(int a[][3], int i, int j);
int main()
{
    int p[3][3] = {
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}
                  };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i != j) && (i < j) ) {
                swap(p, i, j);
            }
        }
    }

    cout<<"{"<<endl;
    for (int i = 0; i < 3; i++) {
        cout<<"\t{";
        for (int j = 0; j < 3; j++) {
            cout<<p[i][j]<<",";
        }
        cout<<"}";
        cout<<endl;
    }
    cout<<"}"<<endl;
}

void swap(int a[][3], int i, int j)
{
    int t = a[i][j];
    a[i][j] = a[j][i];
    a[j][i] = t;
}
