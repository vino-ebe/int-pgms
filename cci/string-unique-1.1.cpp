/*Implement an algorithm to determine if a string has all unique characters. What
 * if you cannot use additional data structures?
 */

#include<iostream>
#include<string>

using namespace std;

int main()
{
    //string s("I am big boy");
    string s("I am  boy");

    bool bitVector[26];

    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') {
            continue;
        } else if (s.at(i) > 'A' && s.at(i) < 'Z') {
            index = s.at(i) - 'A';
        } else {
            index = s.at(i) - 'a';
        }

        if (index <= 26 ) {
            if (bitVector[index]) {
                cout<<"Not Unique char is:"<<s.at(i)<<endl;
                return 0;
            } else {
                bitVector[index] = true;
            }
        } else{
            cout<<"Invalid character.Aborting.."<<endl;
            return 0;
        }
    }

    cout<<"The string is unique"<<endl;
}
