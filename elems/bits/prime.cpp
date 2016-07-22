#include<iostream>
#include<vector>

using namespace std;

void getPrime(int n, vector<int>& prime, vector<bool>& is_prime) {
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }

        for (int j = i + i; j <= n; j = j + i) {
            is_prime[j] = false;
        }
    }

    for (vector<int>::iterator it = prime.begin(); it != prime.end(); it++) {
        cout<<*it<<endl;
    }

}

int main() {
    
    int n = 10;
    vector<int> prime;
    vector<bool> is_prime(n + 1, true);
    getPrime(n, prime, is_prime);
}
