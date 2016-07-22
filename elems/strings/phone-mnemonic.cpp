#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printPhonePad(string p[], string pno, int k, string& res)
{
    string s;
    if (k == 10) {
        cout<<res.c_str()<<endl;
        return;
    }

    for (int i = 0; i < p[k].size(); i++) {
        res[k] = p[k][i];
        printPhonePad(p, pno, k + 1, res);
    }
}

int main()
{
    string pad[] =  {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

    string pno("4845479515");

    int k = 0;
    string res;
    printPhonePad(pad, pno, k, res);
}
