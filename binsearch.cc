#include<iostream>
using namespace std;
int array[] = {1,2,3,4,4,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
int binsearch(int search);
int main()
{
    int search = 25;
    int index = binsearch(search);
    cout<<"Found at index"<<index<<endl;
    return true;
}

int binsearch(int search)
{
    int lowIndex = 0;
    int highIndex = sizeof(array)/sizeof(int) - 1;
    int mp;
    int times = 0;


    do {
        times++;
        mp = ((highIndex + lowIndex)/2);
        if(highIndex < lowIndex)
            break;
        if(array[mp] == search) {
            return mp;
        }else if(array[mp] > search) {
            highIndex = mp - 1;
        }else if(array[mp] < search) {
            lowIndex = mp + 1;
        }

    } while(1);

    mp = -1;
return mp;
}
