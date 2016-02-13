#include<iostream>
using namespace std;

bool palindrome(char *str) ;
int fact(int fact);
int power(int base, int exp) ;

int main()
{
    int f = 5;
    char str[] = "MOTOR";
//    int res = fact(f);
//    cout<<"res is: "<<res<<endl;
 //   cout<<"It is"<<palindrome(str)<<endl;
        cout<<"Power of"<<power(4,3)<<endl;

}

int fact(int f) {

int res = 0;

    if(f == 0) {
        return 1;
    }

    res = f*fact(f - 1); 

    return res;
}

bool palindrome(char *str) {

    int len = strlen(str);
    if(len <= 1) {
        return true;
    }

    if(str[0] == str[len -1]) {
        str[len -1] = '\0';
        str++;
        return(palindrome(str));
    } else {
        return false;
    }

}

int power(int base, int exp) {
    if(exp == 0) {
        return 1;
    } else {
        return base*(power(base,(exp-1)));
    } 

}

