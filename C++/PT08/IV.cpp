#include <bits/stdc++.h>
#define TASK "test"
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
// template <class... T>
// void print(T&&... n) {
//     using exp = int[];
//     exp{0, (cout << n << sp, 0)...};
//     cout << endl;
// }
template <class T>
bool mxmz(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
bool mnmz(T &a, T b) { return b < a ? a = b, 1 : 0; }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }

int n, m;
vector<ll> a;
vector<pii> q;
////////////////////////////////////////
struct sub1 {
    sub1() {
        vector<ll> ans(3);
        int i = 0;
        Forin(c, q) {
            ans[c.se] += a[i++];
        }
        cout << ans[1] - ans[2];
    }
};
////////////////////////////////////////
struct sub2 {
    sub2() {
        vector<int> cnt(2);
        Rep(i, m / 2) {
            cnt[q[i].fi]++;
        }
        
        ll ans = accumulate(a.begin(), a.begin() + cnt[1], 0LL);
        a.erase(a.begin(), a.begin() + cnt[0] + cnt[1]);
        
        cnt[0] = cnt[1] = 0;
        For(i, m / 2, m - 1) {
            cnt[q[i].fi]++;
        }
        
        cout << ans - accumulate(a.begin(), a.begin() + cnt[1], 0LL);
    }
};
////////////////////////////////////////
struct full {
    struct Turn {
        int t, bp[2]{0, 0};
    };
    vector<Turn> ts;
    vector<vector<ll>> dp;
    ////////////////////////////////////////
    ll solve(int id, int pos) {
        if (id == m) return 0;
        
        ll& res = dp[id][pos];
        if (res != -1) return res;
        
        if (ts[id].t == 1) {
            res = max(
                solve(id + 1, pos + ts[id].bp[1]),
                solve(id + 1, pos + ts[id].bp[1] + ts[id].bp[0])
            ) + (a[pos + ts[id].bp[1] - 1] - a[pos - 1]);
        } else {
            res = min(
                solve(id + 1, pos + ts[id].bp[1]),
                solve(id + 1, pos + ts[id].bp[1] + ts[id].bp[0])
            ) - (a[pos + ts[id].bp[1] - 1] - a[pos - 1]);
        }
        
        return res;
    }
    ////////////////
    full() {
        ts.push_back({q[0].fi, {0, 0}});
        Forin(it, q) {
            if (it.se != ts.back().t) {
                ts.push_back({it.se, {0, 0}});
            }
            ts.back().bp[it.fi]++;
        }
        m = ts.size();
        
        // print(m);
        // Forin(it, ts) {
        //     print(it.t, it.bp[0], it.bp[1]);
        // }
        
        a.insert(a.begin(), 0);
        For(i, 1, n) {
            a[i] += a[i - 1];
        }
        
        dp.assign(m, vector<ll>(n + 1, -1));
        cout << solve(0, 1);
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int O, tc;
    cin >> O >> tc;
    
    while (tc--) {
        cin >> n >> m;
        
        a.resize(n);
        Rep(i, n) cin >> a[i];
        sort(all(a), greater<ll>());
        
        q.resize(m);
        Rep(i, m) {
            char c;
            cin >> c >> q[i].se;
            q[i].fi = (c == 'p');
        }
        
        if (O == 1) {
            sub1();
        } else if (O == 2) {
            sub2();
        } else {
            full();
        }
        cout << nl;
    }
    ////////////////////
    return 0;
}