/* Write a program that performs base conversion.
 * i/p: string
 *      integer b1 which is the base for string
 *      integer b2 which is the base for output.
 *      For Ex: string = 615, b1 = 7, b2 = 13, res = "1A7"
 */
#include<iostream>
#include<math.h>

using namespace std;

void convertToBase(int val, int b, int &res);

void baseconvert(string value, int b1, int b2, string res) {
    int num = 0;

    for (int i = value.size() - 1, k = 0; i >= 0; i--, k++) {
        num += (value[i] - '0') * pow(b1, k);
    }

    cout<<"Num is "<<num<<endl;
    int val = 0;
    convertToBase(num, b2, val);
    cout<<"Num is "<<val<<endl;
}

void convertToBase(int val, int b, int &res)
{
    int k = 0;
    int n;
    string sres;
    while(val) {
        n = val % b;
        res += n * pow(10, k);
        sres = char(n + '0' ) + sres;
        k++;
        val = val / b;
    }
    cout<<"sres "<<sres<<endl;
}

int main()
{
    string value("615");
    string res;

    baseconvert(value, 7, 2, res); 
}
