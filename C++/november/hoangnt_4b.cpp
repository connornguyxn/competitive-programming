#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "4b"
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define Repd(i, n) for (int i = (n); i--; )
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define Fors(i, l, r) for (int i = (l), _r = (r); i < _r; i++)
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

// https://tbhnptlcqntn2023.contest.codeforces.com/group/ZosfxzdjkV/contest/485820/problem/B
// implementation

////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n;
    cin >> n;
    
    vector<vector<char>> a(n * 2 + 1, vector<char>(n * 2 + 1, sp));
    For(i, 1, n) {
        For(j, 1, n) {
            cin >> a[i - j + n][i + j - 1];
        }
    }
    // print(a);
    
    int ans = 0, mx = 0;
    vector<vector<int>> s(n * 2 + 1, vector<int>(n * 2 + 1)), prev = s, preh = s;
    For(i, 1, n * 2) {
        int l = 0;
        For(j, 1, n * 2) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == '#');
            bool ok = str("aeiou").find(a[i][j]) < 5;
            prev[i][j] = (ok ? i : prev[i - 1][j]);
            preh[i][j] = (ok ? j : preh[i][j - 1]);
            if (a[i][j] != '#') continue;
            if (l > 0) [&]() {
                int d = j - l, u = i - d;
                if (u < 0) return;
                if (a[u][l] != '#' || a[u][j] != '#') return;
                if (s[i][j] - s[i][l - 1] - s[u - 1][j] + s[u - 1][l - 1] > 4) return;
                if (prev[i][j] < u || prev[i][l] < u) return;
                if (preh[i][j] < l || preh[u][j] < l) return;
                ans++;
                mxmz(mx, d);
            }();
            l = j;
        }
    }
    cout << ans << nl << mx / 2 + 1;
    ////////////////////
    return 0;
}