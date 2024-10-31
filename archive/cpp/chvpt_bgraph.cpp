#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vector2 = vector<vector<T>>;
template <class T>
using vector3 = vector<vector2<T>>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define all(a) (a).begin(), (a).end()
#define tvl (tv * 2)
#define tvr (tv * 2 + 1)
#define FOR(i, l, r) for (ll i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (ll i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1 << (i))
#define bget(i, n) ((n) >> (i) & 1)
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
void addmod(ll& a, ll b) { a = (a + b % MOD) % MOD; }
void submod(ll& a, ll b) { a = (a + MOD - b % MOD) % MOD; }
void mulmod(ll& a, ll b) { a = a * (b % MOD) % MOD; }
template <class T, class... C>
void assign(int n, T v, C&&... a) {
    using e = int[];
    e{(a.assign(n, v), 0)...};
}
template <class... C>
void resize(int n, C&&... a) {
    using e = int[];
    e{(a.resize(n), 0)...};
}
////////////////////////////////////////
template <class... T>
void print(T&&... a) {
    cout << flush;
    clog << "\n[debug] ";
    using e = int[];
    e{(clog << a << sp, 0)...};
    clog << endl;
}
template <class Ch, class Tr, class C>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C a) {
    cout << "{ ";
    FORIN(it, a) cout << it << sp;
    return cout << "}";
}
template <class T1, class T2>
ostream& operator<<(ostream& cout, pair<T1, T2> a) {
    return cout << '(' << a.fi << sp << a.se << ')';
}
void logtime() {
    print("[time]", clock() * 1.0 / CLOCKS_PER_SEC);
}


// https://oj.vnoi.info/problem/chvpt_dothi_1
// tree, math, combinatorics


int n, m;
vector2<int> adj;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    vector<int> mk, cnt1, cnt;
    ////////////////////////////////////////
    void dfs(int cur, int pre) {
        cnt1[cur] = (mk[cur] == 1);
        cnt[cur] = 1;
        
        print(cur, mk[cur]);
        
        FORIN(nxt, adj[cur]) if (nxt != pre) {
            if (mk[nxt] != -1) {
                print(nxt, cur, mk[nxt]);
                if (mk[nxt] == mk[cur]) {
                    cout << 0;
                    exit(0);
                }
                continue;
            }
            
            mk[nxt] = 3 - mk[cur];
            
            dfs(nxt, cur);
            
            cnt1[cur] += cnt1[nxt];
            cnt[cur] += cnt[nxt];
        }
    }
    ////////////////////////////////////////
    ll binpow(ll n, ll k) {
        ll res = 1;
        n %= MOD;
        while (k) {
            if (k % 2) mulmod(res, n);
            mulmod(n, n);
            k /= 2;
        }
        return res;
    }
    ////////////////////////////////////////
    void main() {
        resize(n + 1, cnt1, cnt);
        assign(n + 1, -1, mk);
        
        ll res = 1;
        FOR(i, 1, n) {
            if (mk[i] == -1) {
                mk[i] = 1;
                dfs(i, i);
                mulmod(res, binpow(2, cnt1[i]) + binpow(2, cnt[i] - cnt1[i]));
            }
        }
        
        cout << res;
        
        // print(mk);
    }
    void run() {
        main();
        exit(0);
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "bgraph"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    cin >> n >> m;
    
    resize(n + 1, adj);
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    sub1::run();
    ////////////////////////////////////////
    return 0;
}
