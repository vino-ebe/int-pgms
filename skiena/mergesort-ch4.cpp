#include<iostream>
#include<vector>

using namespace std;

int merge(int a[], int low, int middle, int high);
void mergesort(int a[], int low, int high);
int main()
{
    int a[] = {4, 3, 2, 1};
    mergesort(a, 0, 3);
}

void mergesort(int a[], int low, int high)
{
    int middle;

    if (low < high)
    {
        middle = (low + high)/2;
        mergesort(a, low, middle);
        mergesort(a, middle + 1, high);
        merge(a, low, middle, high);
    }
    cout<<"Sorted order is:"<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<a[i]<<endl;
    }

}

int merge(int a[], int low, int middle, int high)
{
   cout<<"In merge"<<endl; 
   cout<<"Low:"<<low<<"Middle:"<<middle<<"High:"<<high<<endl;
   /* copy the lower half and upper half into a temp array */

   vector<int> lowhalf;
   vector<int> upperhalf;

   for (int i=low; i<=middle; i++)
   {
       lowhalf.push_back(a[i]);
   }

   for (int i=middle+1; i<=high; i++)
   {
       upperhalf.push_back(a[i]);
   }
   int i = 0, j = 0, k = 0;
   k = low;

    while (i < lowhalf.size() && j < upperhalf.size())
    {
        if (lowhalf[i] < upperhalf[j])
        {
            a[k++] = lowhalf[i];
            i++;
        }
        else
        {
            a[k++] = upperhalf[j];
            j++;
        }
    }

    while (i < lowhalf.size())
    {
        a[k++] = lowhalf[i];
        i++;
    }

    while (j < upperhalf.size())
    {
        a[k++] = upperhalf[j];
        j++;
    }
   return 0;
}
