#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("sse4.2")
    #include <bits/stdc++.h>
    #define TASK "prince"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define all(VAR) (VAR).begin(), (VAR).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r), _l = (l); i >= _l; i++)
#define Forin(c, var) for (auto c : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (__builtin_clzll(1) - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class T = int>
T inp() {
    T x;
    cin >> x;
    return x;
}

// https://oj.vnoi.info/problem/chvpt_dx2023_hl_congchua
// math, datastruct

struct scmp {
    bool operator()(pii a, pii b) const {
        int s1 = a.fi + a.se;
        int s2 = b.fi + b.se;
        if (s1 == s2) return a.fi < b.fi;
        return s1 < s2;
    }
};
struct dcmp {
    bool operator()(pii a, pii b) const {
        int s1 = a.fi - a.se;
        int s2 = b.fi - b.se;
        if (s1 == s2) return a.fi < b.fi;
        return s1 < s2;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n = inp();
    inp();
    str mvs = inp<str>();
    
    int x, y;
    cin >> x >> y;
    set<pii, scmp> sum = {{x, y}};
    set<pii, dcmp> dif = {{x, y}};
    auto sit = sum.begin();
    auto dit = dif.begin();
    
    Rep(i, n - 1) {
        cin >> x >> y;
        sum.insert({x, y});
        dif.insert({x, y});
    }
    
    Forin(c, mvs) {
        // cout << c << nl;
        if (c == 'A') {
            auto nxt = next(dit);
            if (nxt == dif.end() || (*nxt).fi - (*nxt).se != (*dit).fi - (*dit).se) continue;
            
            sum.erase(sit);
            dif.erase(dit);
            
            dit = nxt;
            sit = sum.find(*dit);
        } else if (c == 'B') {
            auto nxt = next(sit);
            if (nxt == sum.end() || (*nxt).fi + (*nxt).se != (*sit).fi + (*sit).se) continue;
            
            sum.erase(sit);
            dif.erase(dit);
            
            sit = nxt;
            dit = dif.find(*sit);
        } else if (c == 'C') {
            if (sit == sum.begin()) continue;
            auto nxt = prev(sit);
            if ((*nxt).fi + (*nxt).se != (*sit).fi + (*sit).se) continue;
            
            sum.erase(sit);
            dif.erase(dit);
            
            sit = nxt;
            dit = dif.find(*sit);
        } else {
            if (dit == dif.begin()) continue;
            auto nxt = prev(dit);
            if ((*nxt).fi - (*nxt).se != (*dit).fi - (*dit).se) continue;
            
            sum.erase(sit);
            dif.erase(dit);
            
            dit = nxt;
            sit = sum.find(*dit);
        }
        // db(*sit, *dit);
        // Forin(it, sum) cout << it << sp;
        // cout << nl;
        // Forin(it, dif) cout << it << sp;
        // cout << nl;
    }
    
    cout << (*dit).fi << sp << (*dit).se;
    ////////////////
    return 0;
}