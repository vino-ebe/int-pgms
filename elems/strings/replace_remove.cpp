/* Replace 'a' by two 'd's
 * Remove b from the input
 */

#include<iostream>

using namespace std;

void replace_remove(string str, int size)
{
    char dummy;
    int cnt = 0;
    int index = 0;
    // First replace b's
    for (int i = 0; i < size; i++) {
        if (str.at(i) != 'b') {
            str[index++] = str[i];
        }

        if (str[i] == 'a') {
            cnt++;
        }
    }

    cout<<"str is:"<<str.c_str()<<endl;
    index--;
    int w_index = index + cnt; 
    while(index >= 0) {
        if (str[index] == 'a') {
            str[w_index--] = 'd';
            str[w_index--] = 'd';
            index--;
        } else {
            str[w_index--] = str[index--];
        }
    }

    cout<<"str is:"<<str.c_str()<<endl;
}

int main()
{
    string str("acdbbca");

    replace_remove(str, str.size());
}
