#include "../template.cpp"


template <int N>
struct Sieve {
    vector<int> prime;
    array<int, N + 1> spf = {};
    Sieve() {
        prime.reserve(N / 4);
        spf[0] = spf[1] = -1;
        FOR(i, 2, N) {
            if (spf[i] == 0) {
                prime.push_back(i);
                spf[i] = i;
            }
            FORIN(it, prime) {
                if (N / i < it || it > spf[i]) break;
                spf[i * it] = it;
            }
        }
    }
};
Sieve<(int)1e6> sv;