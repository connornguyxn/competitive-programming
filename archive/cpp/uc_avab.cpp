#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx,avx2,f16c,fma,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define max_size 100000
#define nl '\n'
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117624
// greedy, math

///////////////////////////////////////
bool valid(int steps, int dist) {
    //s = n + 1 * n / 2
	long long sum = steps * (steps + 1) / 2;
	if (sum < dist)
        return false;
	return sum % 2 == dist % 2;
}	
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int dist = abs(a - b);
        if (dist == 0) {
            cout << 0 << nl;
            continue;
        }
        int steps = 1;
        while (!valid(steps, dist)) {
            steps++;
        };
        cout << steps << nl;
    };
}