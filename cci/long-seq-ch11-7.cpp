#include<iostream>

using namespace std;

int main()
{
    int a[] = {13, 14, 16, 11, 12, 17, 20};
    int size = sizeof(a)/sizeof(a[0]);
    int si = 0, li = 0;
    int maxsi = 0, maxli = 0;
    for (int i = 0; i < size - 1; i++) {
       if (a[i] < a[i + 1]) {
           li = i + 1;
       } else {
           if ((li - si) > (maxli - maxsi)) {
               maxsi = si;
               maxli = li;
           }
           si = i;
           li = i;
       }
    }


    if ((li - si) > (maxli - maxsi)) {
        cout<<"The longest sequence is from "<<si<<"to"<<li<<endl;
    } else {
        cout<<"The longest sequence is from "<<maxsi<<"to"<<maxli<<endl;
    }
}
