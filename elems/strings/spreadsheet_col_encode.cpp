/* MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. 
    In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.

    Given a column number, find its corresponding Excel column name. Following are more examples.

    Input          Output
    26             Z
    51             AY
    52             AZ
    80             CB
    676            YZ
    702            ZZ
    705            AAC
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n = 27;

    int q = 0;

    string res;
    int i = 0, m;
    char c;

    while (n) {
        q = n / 26;

        m = n % 26;

        if (m == 0) {
            m = 26;
            q = q - 1;
        }
        c = 65 + (m - 1);
        res = c + res;

        n = q;
    }

    cout<<"res is "<<res.c_str()<<endl;
}
