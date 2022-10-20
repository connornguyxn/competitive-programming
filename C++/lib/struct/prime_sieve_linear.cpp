#include "include/debugging.h"
using namespace std;

// Object implementation of eratosthenes sieve (with a linear prime array)
// https://hackmd.io/@Editorial-Slayers/sieve#9Linear-Eratosthenes-Sieve

///////////////////////////////////////
class linear_prime_sieve {
    void build_sieve(int n, vector<int> &prime, vector<int> &isprime) {
        vector<int> lpf(n + 1, 2);
        isprime.resize(n + 1);
        fill(isprime.begin(), isprime.end(), 0);
        prime.push_back(2);
        isprime[2] = 1;
        for (int x = 3; x <= n; x += 2) {
            if (lpf[x] == 2) {
                prime.push_back(lpf[x] = x);
                isprime[x] = 1;
            };
            for (int i = 0; (i < prime.size()) &&
                            (prime[i] <= lpf[x]) &&
                            (prime[i] * x <= n); i++)
            {
                lpf[prime[i] * x] = prime[i];
            };
        };
    };
    /////////////////
    public:
    vector<int> prime, isprime;
    linear_prime_sieve(int n = 1e6) {
        build_sieve(n, prime, isprime);
    };
};
///////////////////////////////////////
int main() {
    int n;
    cin >> n;
    linear_prime_sieve sieve;
    for (int i = 0; i < n; i++) {
        cout << sieve.prime[i] << ' ';
    };
}