/*Implement a method to perform basic string compression using the counts
 * of repeated characters. For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not become smaller than the original
 * string, your method should return the original string.
 */

#include<iostream>
#include<sstream>

using namespace std;
int main()
{
    char str[] = {"aabcccccaaa"};
    int m = 0;
    int n = m + 1;
    int index = 1;
    int len = strlen(str);
    stringstream ss;

    while (n <= len) {

        if (n  == len) {
            ss << str[m];
            ss << index;
            break;
        }

        if (str[m] != str[n]) {
            ss << str[m];
            ss << index;
            m = n;
            n++;
            index = 1;
        } else {
            n++;
            index++;
        }
    }

    cout<<ss.str()<<endl;
}
