#include<iostream>
#include<string>

using namespace std;

void convertIpToInt(string ip, int& ip_32);

int main()
{
    string ip("255.255.255.255");
    int ip_32;
    convertIpToInt(ip, ip_32);
}

void convertIpToInt(string ip, int& ip_32)
{
    int i = 0;
    int size = ip.size();
    int numOctets = 0;
    int curIndex = 0;
    size_t sz;
    unsigned int val = 0, shift = 8;
    int res = 0;

    while (i < size) {
        if (ip[i] == '.' || (i == size - 1)) {
            val = val << 8;
            res = stoi(ip.substr(curIndex, i)); 
            val |= res;
            numOctets++;
            curIndex = i + 1;
        }
        i++;
    }

    if (numOctets != 4) {
        cout<<"Invalid ip address"<<numOctets<<endl;
    }
    cout<<hex<<val<<endl;
}
