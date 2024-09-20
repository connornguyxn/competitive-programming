#include "bits/stdc++.h"
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
void add(ll& a, ll b) { a = (a + b) % MOD; }
void sub(ll& a, ll b) { a = (a + MOD * MOD - b) % MOD; }
void mul(ll& a, ll b) { a = a * (b % MOD) % MOD; }
////////////////////////////////////////
template <class... T>
void print(T&&... a) {
    cout << "[debug] ";
    using e = int[];
    e{(cout << a << sp, 0)...};
    cout << endl;
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

// https://lqdoj.edu.vn/problem/lqdoj2022r3shopping
// segtree

int n, q;
vector<ll> a;
struct Q {
    int l, u, v;
    ll k;
};
vector<Q> qs;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    bool checksub() {
        FORIN(it, qs) {
            if (it.u != 1 || it.v != 1000000000) return false;
        }
        return true;
    }
    ////////////////////////////////////////
    void main() {
        FOR(i, 1, n) {
            a[i] += a[i - 1];
        }
        FORIN(it, qs) {
            int lo = it.l, hi = n, res = it.l - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                
                if (a[mid] - a[it.l - 1] <= it.k) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cout << res - (it.l - 1) << nl;
        }
    }
}
////////////////////////////////////////
namespace sub2 {
    bool checksub() {
        return *max_element(all(a)) <= 500;
    }
    ////////////////////////////////////////
    void main() {
        int m = *max_element(all(a));
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                sum[i][j] = sum[i - 1][j] + a[i] * (a[i] == j);
            }
        }
        
        FORIN(it, qs) {
            int lo = it.l, hi = n, res = it.l - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                
                ll s = 0;
                FOR(i, it.u, min(it.v, m)) {
                    s += sum[mid][i] - sum[it.l - 1][i];
                }
                
                if (s <= it.k) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cout << res - (it.l - 1) << nl;
        }
    }
}
////////////////////////////////////////
namespace sub3 {
    bool checksub() {
        FORIN(it, qs) {
            if (it.v - it.u > 5) return false;
        }
        return true;
    }
    ////////////////////////////////////////
    void main() {
        vector<int> zip;
        zip.reserve(n);
        
        FOR(i, 1, n) zip.push_back(a[i]);
        FORIN(it, qs) {
            zip.push_back(it.u);
            zip.push_back(it.v);
        }
        
        sort(all(zip));
        zip.erase(unique(all(zip)), zip.end());
        
        FOR(i, 1, n) a[i] = lower_bound(all(zip), a[i]) - zip.begin();
        FORIN(it, qs) {
            it.u = lower_bound(all(zip), it.u) - zip.begin();
            it.v = lower_bound(all(zip), it.v) - zip.begin();
        }
        
        vector<vector<int>> pos(zip.size());
        FOR(i, 1, n) {
            pos[a[i]].push_back(i);
        }
        FORIN(it, pos) sort(all(it));
        
        auto getcnt = [&](int p, int l, int r) -> ll {
            if (r < l) return 0;
            return upper_bound(all(pos[p]), r) - lower_bound(all(pos[p]), l);
        };
        
        FORIN(it, qs) {
            int lo = 0, hi = n - it.l + 1, res = -1;
            
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                
                ll sum = 0;
                FOR(i, it.u, it.v) {
                    sum += zip[i] * getcnt(i, it.l, it.l + mid - 1);
                }
                
                if (sum <= it.k) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            cout << res << nl;
        }
    }
}
////////////////////////////////////////
namespace sub4 {
    bool checksub() {
        FORIN(it, qs) {
            if (it.u != 1) return false;
        }
        return true;
    }
    vector<ll> st;
    ////////////////////////////////////////
    void update(int p, ll v, int tl = 1, int tr = n, int tv = 1) {
        if (tl == p && tr == p) {
            st[tv] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if (p <= tm) update(p, v, tl, tm, tvl);
        else update(p, v, tm + 1, tr, tvr);
        st[tv] = st[tvl] + st[tvr];
    }
    ////////////////////////////////////////
    ll get(int l, int r, int tl = 1, int tr = n, int tv = 1) {
        if (l <= tl && tr <= r) {
            return st[tv];
        }
        if (tr < l || r < tl) {
            return 0;
        }
        int tm = (tl + tr) / 2;
        ll lq = get(l, r, tl, tm, tvl);
        ll rq = get(l, r, tm + 1, tr, tvr);
        return lq + rq;
    }
    ////////////////////////////////////////
    void main() {
        resize(n * 4 + 4, st);
        
        // queries with pos
        vector<pair<Q, int>> qwp(q);
        FOR(i, 0, q - 1) {
            qwp[i] = {qs[i], i};
        }
        sort(all(qwp), [](pair<Q, int> a, pair<Q, int> b) {
            return a.fi.v < b.fi.v;
        });
        
        // a with pos
        vector<pair<ll, int>> awp(n + 1);
        FOR(i, 1, n) {
            awp[i] = {a[i], i};
        }
        sort(1 + all(awp));
        
        
        int i = 1;
        vector<int> ans(q);
        FORIN(it, qwp) {
            while (i <= n && awp[i].fi <= it.first.v) {
                update(awp[i].se, awp[i].fi);
                i++;
            }
            
            int lo = 0, hi = n - it.fi.l + 1, res = -1;
            
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                
                ll sum = get(it.fi.l, it.fi.l + mid - 1);
                // print(mid, sum);
                
                if (sum <= it.fi.k) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            ans[it.se] = res;
        }
        
        FORIN(it, ans) cout << it << nl;
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub5 {
    struct Node {
        vector<ll> a, sum;
    };
    vector<Node> st;
    void build(int tl = 1, int tr = n, int tv = 1) {
        if (tl == tr) {
            st[tv].a = st[tv].sum = {a[tl]};
            return;
        }
        int tm = (tl + tr) / 2;
        build(tl, tm, tvl);
        build(tm + 1, tr, tvr);
        merge(all(st[tvl].a), all(st[tvr].a), back_inserter(st[tv].a));
        partial_sum(all(st[tv].a), back_inserter(st[tv].sum));
    }
    ////////////////////////////////////////
    ll getsum(int tv, int u, int v) {
        int r = upper_bound(all(st[tv].a), v) - st[tv].a.begin() - 1;
        if (r < 0) return 0;
        int l = lower_bound(all(st[tv].a), u) - st[tv].a.begin();
        return st[tv].sum[r] - (l > 0 ? st[tv].sum[l - 1] : 0);
    }
    ////////////////////////////////////////
    // {pos, sum}
    pair<int, ll> walk(int l, int u, int v, ll mxsum, int tl = 1, int tr = n, int tv = 1) {
        if (tl == tr) {
            return {tl, getsum(tv, u, v)};
        }
        if (tr < l) return {n + 1, 0};
        int tm = (tl + tr) / 2;
        if (l <= tl) {
            ll sum = getsum(tv, u, v);
            if (sum < mxsum) return {n + 1, sum};
            ll lsum = getsum(tvl, u, v);
            if (lsum < mxsum) return walk(l, u, v, mxsum - lsum, tm + 1, tr, tvr);
            return walk(l, u, v, mxsum, tl, tm, tvl);
        } else {
            auto lq = walk(l, u, v, mxsum, tl, tm, tvl);
            if (lq.fi) return lq;
            auto rq = walk(l, u, v, mxsum - lq.se, tm + 1, tr, tvr);
            return {rq.fi, lq.se + rq.se};
        }
    }
    ////////////////////////////////////////
    void main() {
        st.resize(n * 4);
          
        build();
        
        print(walk(4, 1, 5, 7));
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define task "test"
    // #define task "shopping"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> q;
    
    resize(n + 1, a);
    FOR(i, 1, n) {
        cin >> a[i];
    }
    
    qs.resize(q);
    FORIN(it, qs) cin >> it.l >> it.u >> it.v >> it.k;
    
    // if (sub1::checksub()) return sub1::main(), 0;
    // if (sub2::checksub()) return sub2::main(), 0;
    // if (sub3::checksub()) return sub3::main(), 0;
    // if (sub4::checksub()) return sub4::main(), 0;
    return sub5::main(), 0;
    ////////////////////////////////////////
}