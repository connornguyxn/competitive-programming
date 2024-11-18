#include "../template.cpp"


template <int N = 1000000>
struct Sieve {
    vector<int> prime;
    array<int, N> spf = {};
    Sieve() {
        prime.reserve(sqrt(N));
        spf[0] = spf[1] = -1;
        FOR(i, 2, n) {
            if (spf[i] == 0) {
                prime.push_back(i);
                spf[i] = i;
            }
            FORIN(it, prime) {
                if (n / i < it || it > spf[i]) break;
                spf[i * it] = it;
            }
        }
    }
};