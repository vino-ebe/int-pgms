#include<iostream>

using namespace std;

int makechange(int n, int denom) ;
int main()
{
    cout<<makechange(25, 25)<<endl;
}

int makechange(int n, int denom) {

    int next_denom = 0;
    int count = 0;

    switch(denom) {
        case 25:
            next_denom = 10;
            break;

        case 10:
            next_denom = 5;
            break;

        case 5:
            next_denom = 1;
            break;

        case 1:
            return 1;
    }

    for (int i = 0; (i * denom) < n; i++)
    {
        cout<<"i is:"<<i<<" n is:"<<n<<endl;
        count += makechange( (n - (i * denom)), next_denom);
    }

    return count;
}
