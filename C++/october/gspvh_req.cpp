#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "req"
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
const int N = 1e7;
ll MOD = 1e9 + 7;
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

// https://gspvh23.contest.codeforces.com/group/FIWwc7nF6c/contest/479930/problem/K
// math, segtree

int n, q;
vector<ll> st;
////////////////////////////////////////
struct Query {
    int l, r, id;
    bool operator<(Query oth) const {
        return r < oth.r;
    }
};
////////////////////
struct Sieve {
    int n;
    vector<int> spf;
    Sieve(int _n) : n(_n), spf(n, 2) {
        for (int i = 3; i < n; i += 2) {
            if (spf[i] > 2) continue;
            spf[i] = i;
            for (ll j = 1LL * i * i; j < n; j += i + i) {
                if (spf[j] == 2) spf[j] = i;
            }
        }
    }
} sieve(N + 1);
////////////////////////////////////////
void update(int p, ll v, int tl = 0, int tr = n - 1, int tv = 1) {
    if (tr < p || p < tl) return;
    if (tl == p && tr == p) {
        st[tv] = v % MOD;
    } else {
        int tm = (tl + tr) / 2;
        update(p, v, tl, tm, tv * 2);
        update(p, v, tm + 1, tr, tv * 2 + 1);
        st[tv] = (st[tv * 2] * st[tv * 2 + 1]) % MOD;
    }
}
////////////////////
ll query(int l, int r, int tl = 0, int tr = n - 1, int tv = 1) {
    if (r < tl || tr < l) return 1;
    if (l <= tl && tr <= r) return st[tv] % MOD;
    int tm = (tl + tr) / 2;
    return (query(l, r, tl, tm, tv * 2) * query(l, r, tm + 1, tr, tv * 2 + 1)) % MOD;
}
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    cin >> n >> n >> q >> MOD;
    
    vector<vector<pii>> fact(n);
    Rep(i, n) {
        int x;
        cin >> x;
        while (x > 1) {
            pii cur{sieve.spf[x], 1};
            while (x % cur.fi == 0) {
                cur.se *= cur.fi;
                x /= cur.fi;
            }
            cur.se /= cur.fi;
            fact[i].push_back(cur);
        }
    }
    // print(fact);
    
    vector<Query> qs(q);
    Rep(i, q) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--;
        qs[i].r--;
        qs[i].id = i;
    }
    sort(all(qs));
    
    st.resize(n * 4, 1);
    vector<int> pre(N, INF), rep(100);
    vector<ll> ans(q);
    int id = -1;
    
    Forin(cq, qs) {
        while (id < cq.r) {
            id++;
            // print("id", id);
            
            int cnt = 0;
            if (fact[id].size()) {
                ll cur = 1;
                Forin(it, fact[id]) {
                    mul(cur, (it.fi - 1) * it.se);
                    if (pre[it.fi] < id) rep[cnt++] = pre[it.fi];
                    pre[it.fi] = id;
                }
                update(id, cur);
            }
            
            // print("rep", rep);
            sort(rep.begin(), rep.begin() + cnt);
            cnt = unique(rep.begin(), rep.begin() + cnt) - rep.begin();
            
            Rep(i, cnt) {
                int p = rep[i];
                ll cur = 1;
                Forin(it, fact[p]) {
                    // print("pre", it.fi, pre[it.fi]);
                    if (pre[it.fi] == p) {
                        mul(cur, (it.fi - 1) * it.se);
                    } else {
                        mul(cur, it.se * it.fi);
                    }
                }
                update(p, cur);
            }
        }
        
        ans[cq.id] = query(cq.l, cq.r);
        // Rep(i, n) cout << query(i, i) << sp;
        // print();
    }
    
    Forin(it, ans) cout << it << sp;
    ////////////////////
    return 0;
}