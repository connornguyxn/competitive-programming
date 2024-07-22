#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "pswd"
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
#define all(var) (var).begin(), (var).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Forsd(i, r, l) for (int i = (r), _l = (l); --i >= _l; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog(n) (63 - __builtin_clzll(n))
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};

// https://oj.vnoi.info/problem/chvpt_chvmarathon2_pswd
// string, dsu, easy

int par[N];
////////////////////////////////////////
int root(int v) {
    if (par[v] < 0) return v;
    return par[v] = root(par[v]);
}
////////////////////////////////////////
bool merge(int a, int b) {
    if ((a = root(a)) == (b = root(b))) return false;
    if (-par[a] < -par[b]) {
        swap(a, b);
    };
    par[a] += par[b];
    par[b] = a;
    return true;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    vector<str> a(n);
    Rep(i, n) cin >> a[i];
    
    memset(par, -1, sizeof(par));
    int ans = n;
    unordered_map<char, int> pos;
    
    Rep(i, n) {
        Forin(c, a[i]) {
            if (pos.count(c)) {
                ans -= merge(i, pos[c]);
            } else {
                pos[c] = i;
            }
        }
    }
    
    cout << ans;
    ////////////////
    return 0;
}