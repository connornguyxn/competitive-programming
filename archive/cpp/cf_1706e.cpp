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
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
const ll MOD = 1e9 + 7;
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


// https://codeforces.com/problemset/problem/1706/E
// dsu, segtree rollback

int n, m, q;
vector<pii> edges, qs;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    vector<int> par;
    vector<set<pii>> ranges;
    vector2<pii> idx_ranges;
    int edge_idx;
    ////////////////////////////////////////
    int root(int u) {
        return par[u] < 0 ? u : par[u] = root(par[u]);
    }
    ////////////////////////////////////////
    bool merge(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return false;
        if (par[u] > par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        
        FORIN(it, ranges[v]) {
            auto cur = ranges[u].insert(it).fi;
            
            if (cur != ranges[u].begin()) {
                auto pre = prev(cur);
                if (pre->se + 1 == cur->fi) {
                    pii merged{pre->fi, cur->se};
                    ranges[u].erase(pre);
                    ranges[u].erase(cur);
                    cur = ranges[u].insert(merged).fi;
                }
            }
            
            if (cur != prev(ranges[u].end())) {
                auto nxt = next(cur);
                if (cur->se + 1 == nxt->fi) {
                    pii merged{cur->fi, nxt->se};
                    ranges[u].erase(nxt);
                    ranges[u].erase(cur);
                    cur = ranges[u].insert(merged).fi;
                }
            }
            
            idx_ranges[cur->se].push_back({cur->fi, edge_idx + 1});
        }
        ranges[v] = move(set<pii>{});
        
        return true;
    }
    ////////////////////////////////////////
    struct Segtree {
        int timer = 0;
        vector<int> st;
        vector<array<int, 3>> changes;
        Segtree() {
            st.assign(n * 4 + 4, INF);
        }
        ////////////////////////////////////////
        void change(int tv, int val) {
            if (st[tv] == val) return;
            changes.push_back({timer, tv, st[tv]});
            st[tv] = val;
        }
        ////////////////////////////////////////
        void rollback(int t) {
            while (changes.size()) {
                auto& last = changes.back();
                if (last[0] <= t) break;
                st[last[1]] = last[2];
                // print("rolled back", last);
                changes.pop_back();
            }
        }
        ////////////////////////////////////////
        void update(int p, int v, int tl = 0, int tr = n, int tv = 1) {
            if (tl == tr) {
                if (v < st[tv]) {
                    change(tv, v);
                }
                return;
            }
            int tm = (tl + tr) / 2;
            if (p <= tm) update(p, v, tl, tm, tvl);
            else update(p, v, tm + 1, tr, tvr);
            change(tv, min(st[tvl], st[tvr]));
        }
        ////////////////////////////////////////
        int get(int l, int r, int tl = 0, int tr = n, int tv = 1) {
            if (tr < l || r < tl) return INF;
            if (l <= tl && tr <= r) return st[tv];
            int tm = (tl + tr) / 2;
            return min(get(l, r, tl, tm, tvl), get(l, r, tm + 1, tr, tvr));
        }
    };
    ////////////////////////////////////////
    void main() {
        par.assign(n + 1, -1);
        ranges.resize(n + 1);
        FOR(i, 1, n) {
            ranges[i] = {{i, i}};
        }
        
        edge_idx = 0;
        idx_ranges.assign(n + 1, {});
        
        while (edge_idx < m) {
            merge(edges[edge_idx].fi, edges[edge_idx].se);
            edge_idx++;
        }
        
        
        
        
        Segtree st;
        FORD(i, n, 1) {
            FORIN(it, idx_ranges[i]) {
                st.update(it.fi, it.se);
            }
            st.timer++;
        }
        
        struct Q {
            int l, r, idx;
        };
        vector<Q> qsidx;
        FOR(i, 0, q - 1) {
            qsidx.push_back({qs[i].fi, qs[i].se, i});
        }
        sort(all(qsidx), [](const Q& a, const Q& b) {
            return a.r < b.r;
        });
        
        
        
        vector<int> ans(q);
        FORIN(cq, qsidx) {
            st.rollback(n - cq.r);
            
            if (cq.l == cq.r) {
                ans[cq.idx] = 0;
                continue;
            }
            
            ans[cq.idx] = st.get(0, cq.l);
        }
        
        FORIN(it, ans) cout << it << sp;
        cout << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "cf_1706e"
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    atexit(logtime);
    ////////////////////////////////////////
    int tc;
    cin >> tc;
    
    FOR(ct, 1, tc) {
        cin >> n >> m >> q;
        
        edges.resize(m);
        FORIN(it, edges) {
            cin >> it.fi >> it.se;
        }
        
        resize(q, qs);
        FORIN(it, qs) cin >> it.fi >> it.se;
        
        sub1::main();
    }
    ////////////////////////////////////////
    return 0;
}