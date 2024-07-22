#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
#define fi first
#define se second
#define nl '\n'
#define sp ' '
#define ALL(a) (a).begin(), (a).end()
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FOR(i, l, r) for (int i = (l), _n = (r); i <= _n; i++)
#define FORIN(it, a) for (auto& it : a)
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
//template <class Ch, class Tr, class T>
//basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, const T& a) {
//    cout << "{ ";
//    FORIN(it, a) cout << it << sp;
//    return cout << "}";
//}
//template <class... T>
//void print(T&&... a) {
//    using exp = int[];
//    exp{(cout << a << sp, 0)...};
//    cout << endl;
//}


// https://lqdoj.edu.vn/problem/lqdoj2022r2scoring
// graph, math, combinatorics

int n, k;
const int N = 1e6;
const ll MOD = 1e9 + 7;
vector<vector<int>> adj;
vector<ll> fact(N + 1), finv(N + 1);
//////////////////////////////////
ll bpow(ll n, ll k) {
    ll res = 1;
    n %= MOD;
    
    while (k) {
        if (k % 2) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }
    
    return res;
}
//////////////////////////////////
ll nCk(int n, int k) {
    if (n <= N) {
        return fact[n] * finv[k] % MOD * finv[n - k] % MOD;
    }
    
    
    k = min(k, n - k);
    ll res = 1;
    FOR(i, 1, k) {
        res = res * (ll)(n - k + i) % MOD * bpow(i, MOD - 2) % MOD;
    }
    return res;
}
//////////////////////////////////
ll ans;
vector<int> cnt; 
//////////////////////////////////
void dfs(int cur) {
    cnt[cur] = 1;
    FORIN(nxt, adj[cur]) {
        dfs(nxt);
        cnt[cur] += cnt[nxt];
    }
    
    int rem = cnt[cur] - 1;
    FORIN(nxt, adj[cur]) {
        ans = ans * nCk(rem, cnt[nxt]) % MOD;
        rem -= cnt[nxt];
    }
}
//////////////////////////////////
int main() {
    #define TASK "scoring"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    //////////////////////////////////
    cin >> n >> k;
    
    vector<pii> e(n - 1);
    REP(i, n - 1) {
        cin >> e[i].fi >> e[i].se;
    }
    
    vector<int> v(n + 1);
    FOR(i, 1, n) {
        cin >> v[i];
    }
    
    vector<int> deg(n + 1);
    adj.resize(n + 1);
    FORIN(it, e) {
        if (v[it.fi] < v[it.se]) {
            adj[it.fi].push_back(it.se);
            deg[it.se]++;
        } else {
            adj[it.se].push_back(it.fi);
            deg[it.fi]++;
        }
    }
    
    fact[0] = 1;
    FOR(i, 1, N) fact[i] = fact[i - 1] * (ll)i % MOD;
    finv[N] = bpow(fact[N], MOD - 2);
    for (ll i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1) % MOD;
    
    cnt.resize(n + 1);
    ans = nCk(k, n);
    FOR(i, 1, n) {
        if (!deg[i]) {
            dfs(i);
            break;
        }
    }
    
    cout << ans;
    //////////////////////////////////
}
