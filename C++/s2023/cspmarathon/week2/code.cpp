#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse4.2")
#include <bits/stdc++.h>
#define TASK "code"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define Fore(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Forde(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define Bmask(i) (1ULL << (i))
#define Bget(mask, i) ((mask >> (i)) & 1)
#define Blog(n) (63 - __builtin_clzll(n))
template <class T = int>
T inp() { T x; cin >> x; return x; }
template <typename... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << nl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = max(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};


struct cmp {
    bool operator()(str a, str b) const {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
};
int n, m;
vector<str> a, cur;
map<str, int, cmp> cnt;
////////////////////////////////////////
void add() {
    str s = "";
    Forin(it, cur) s += it;
    cnt[s]++;
}
/////////////
void gen(int id) {
    if (id == n) {
        add();
        while (next_permutation(all(cur))) {
            add();
        }
    } else {
        cur.push_back(a[id]);
        gen(id + 1);
        cur.pop_back();
        gen(id + 1);
    }
}
////////////////////////////////////////
int main() {
    // freopen("test.inp", "r", stdin);
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m;
    Rep(i, n) a.push_back(inp<str>());
    sort(all(a));
    
    cur.reserve(n);
    gen(0);
    
    // Forin(it, cnt) cout << it.fi << sp << it.se << nl;
    
    cout << [&]() -> int {
        Forin(it, cnt) {
            if (it.se > 1) {
                return it.fi.size();
            }
        }
        return -1;
    }();
    ////////////////
    return 0;
}
