/* Suppose that you are given a sorted sequence of distinct integers {a1, a2, . . . , an}.
 * Give an O(lg n) algorithm to determine whether there exists an i index such as
 * ai = i. For example, in {−10,−3, 3, 5, 7}, a3 = 3. In {2, 3, 4, 5, 6, 7}, there is no
 * such i.
 */

#include<iostream>
using namespace std;

int binsearch(int a[], int low, int high);
int main()
{
    int a[] = {0, 2, 4, 6, 8, 10, 12};

    cout<<"The index is"<<binsearch(a, 0, 6)<<endl;
}

int binsearch(int a[], int low, int high)
{
    if (low <= high)
    {
        int middle = (low + high)/2;

        if (a[middle] == middle)
        {
            return middle;
        }
        else if (a[middle] > middle)
        {
            return binsearch(a, low, middle - 1);
        }
        else
        {
            return binsearch(a, middle + 1, high);
        }
    }

    return -1;
}
