#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n = 30;
    vector<vector<int> > v(n);

    v[0].push_back(1);
    v[1].push_back(1);
    v[1].push_back(1);

    int k;

    for (int i = 2; i < n; i++) {
        v[i].push_back(1);
        for (int j = i - 1, k = 1; k < v[i - 1].size() ; k++) { 
            int s1 = v[j].at(k);
            int s2 = v[j].at(k - 1);
            v[i].push_back(s1 + s2);
        }
        v[i].push_back(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout<<v[i][j];
        }
        cout<<endl;
    }

}
