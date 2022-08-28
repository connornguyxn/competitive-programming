#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define str string
#define nl '\n'
#define sp ' '
#define dec_point(n) fixed << showpoint << setpreciscion(n)
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(a) for (auto& i : a)
#define for_to(l, r) for (int i = l; i <= r; i++)
#define fm(val) "["#val" = "<<(val)<<"] "
const ull MOD = 1e9 + 7;

// <problem link>
// <tags>

///////////////////////////////////////
vector<int> a;
int v, vw;
///////////////////////////////////////
void solve(int s, unordered_set<int> m) {
    if (s == v) {
        for_in(m) {
            cout << a[i] << sp;
        };
        return;
    } else if (s > v) {
        return;
    };
    for_to(0, a.size() - 1) {
        cout << fm(a[i]) << endl;
        m.insert(i);
        solve(s + a[i], m);
        m.erase(i);
    };
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("vnoj_goime_conquathongminh.inp");
    //ofstream cout("vnoj_goime_conquathongminh.out");
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> v >> vw;
        v -= vw;
        int n;
        cin >> n;
        a.resize(n);
        for_in(a) {
            cin >> i;
        };
        sort(a.begin(), a.end());
        solve(0, {});
        if 
        /////////////////
        endc:
        cout << nl;
    };
    return 0;
}