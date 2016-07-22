#include<iostream>
#include<string>

using namespace std;

void lookandsay(int n)
{
        cout<<"1"<<endl;
        cout<<"11"<<endl;
    if (n == 1) {
        cout<<"1"<<endl;
    } else if (n == 2) {
        cout<<"11"<<endl;
    } else {
        string temp("11");
        for (int i = 3; i < n; i++) {
            string str;
            int size = temp.size();
            int j = 1, count = 1;

            while (j < size + 1) {
                if (temp[j] != temp[j - 1]) {
                    str += (count + '0'); 
                    str += temp[j - 1];
                    count = 1;
                } else {
                    count++; 
                }
                j++;
            }
            cout<<str<<endl;
            temp = str;
        }
    }
}

int main()
{
    int n = 7;

    lookandsay(n);
}
