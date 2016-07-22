#include<iostream>

using namespace std;

int countsteps(int steps) ;
int main()
{
    int steps = 10;

    cout<<"Num steps:"<<countsteps(steps)<<endl;

}

int countsteps(int steps) {
    if (steps < 0) {
        return 0;
    } else if (steps == 0) {
        return 1;
    }

    return  countsteps(steps - 1) + countsteps(steps - 2) + countsteps(steps - 3) ;
}
