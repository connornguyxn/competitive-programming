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
#define lnode (tv * 2)
#define rnode (tv * 2 + 1)
#define FOR(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)
#define FORD(i, r, l) for (int i = (r), _l = (l); i >= _l; i--)
#define FORIN(it, a) for (auto& it : a)
#define bmask(i) (1LL << (i))
#define bget(i, n) ((n) >> (i) & 1)
#define bon(i, n) ((n) | bmask(i))
#define boff(i, n) ((n) & ~bmask(i))
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
template <class T, class... T2>
void mnmz(T& a, T2&&... b) {
    a = min({a, b...});
}
template <class T, class... T2>
void mxmz(T& a, T2&&... b) {
    a = max({a, b...});
}
////////////////////////////////////////
// template <class... T>
// void print(T&&... a) {
//     cout << "[debug] ";
//     using e = int[];
//     e{(cout << a << sp, 0)...};
//     cout << endl;
// }
// template <class Ch, class Tr, class C>
// basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& cout, C a) {
//     cout << "{ ";
//     FORIN(it, a) cout << it << sp;
//     return cout << "}";
// }
// template <class T1, class T2>
// ostream& operator<<(ostream& cout, pair<T1, T2> a) {
//     return cout << '(' << a.fi << sp << a.se << ')';
// }

// https://dmoj.ca/problem/dmopc18c5p5
// dp, segtree

int n;
vector<ll> v, w;
////////////////////////////////////////////////////////////////////////////////
namespace sub1 {
    void main() {
        ll ans = INFLL;
        FOR(stat, 0, bmask(n - 1)) {
            ll res = 0;
            vector<ll> tmp = v;
            
            FOR(i, 1, n - 1) {
                if (bget(i - 1, stat)) swap(v[i], v[i + 1]);
                res += abs(v[i] - w[i]);
            }
            res += abs(v[n] - w[n]);
            
            mnmz(ans, res);
            v = move(tmp);
        }
        cout << ans;
    }
}
////////////////////////////////////////
namespace sub2 {
    void main() {
        vector2<ll> cost(n + 1, vector<ll>(n + 1));
        FOR(i, 1, n) {
            ll cur = 0;
            cost[i][i] = abs(v[i] - w[i]);
            FOR(j, i + 1, n) {
                cur += abs(v[j] - w[j - 1]);
                cost[i][j] = cur + abs(v[i] - w[j]);
            }
        }
        
        vector<ll> dp(n + 1, INFLL);
        dp[0] = 0;
        FOR(i, 1, n) {
            FOR(pre, 1, i) {
                mnmz(dp[i], dp[pre - 1] + cost[pre][i]);
            }
        }
        
        cout << dp[n];
    }
}
////////////////////////////////////////////////////////////////////////////////
namespace sub3 {
    struct Segtree {
        int n;
        vector<ll> st;
        Segtree(int _n) : n(_n), st(n * 4, INFLL) {}
        ////////////////////////////////////////
        void update(int p, ll v, int tl, int tr, int tv) {
            if (tl == tr) {
                st[tv] = v;
                return;
            }
            int tm = (tl + tr) / 2;
            if (p <= tm) update(p, v, tl, tm, lnode);
            else update(p, v, tm + 1, tr, rnode);
            st[tv] = min(st[lnode], st[rnode]);
        }
        void update(int p, ll v) {
            update(p, v, 0, n - 1, 1);
        }
        ////////////////////////////////////////
        ll get(int l, int r, int tl, int tr, int tv) {
            if (tr < l || r < tl) return INFLL;
            if (l <= tl && tr <= r) return st[tv];
            int tm = (tl + tr) / 2;
            return min(get(l, r, tl, tm, lnode), get(l, r, tm + 1, tr, rnode));
        }
        ll get(int l, int r) {
            return get(l, r, 0, n - 1, 1);
        }
    };
    ////////////////////////////////////////
    void main() {
        vector<ll> sum(n + 1);
        FOR(i, 1, n) {
            sum[i] = sum[i - 1] + abs(v[i] - w[i - 1]);
        }
        
        vector<ll> zip{0};
        FOR(i, 1, n) {
            zip.push_back(v[i]);
            zip.push_back(w[i]);
        }
        sort(all(zip));
        zip.erase(unique(all(zip)), zip.end());
        int m = zip.size();
        unordered_map<ll, int> pos;
        FOR(i, 0, m - 1) {
            pos[zip[i]] = i;
        }
        
        Segtree smaller(m), larger(m);
        
        vector<ll> dp(n + 1);
        FOR(i, 1, n) {
            // w[i] >= v[pre]:
            // sum[i] - sum[pre] + (w[i] - v[pre]) + dp[pre - 1]
            // = sum[i] + w[i] + (dp[pre - 1] - sum[pre] - v[pre])
            //
            // w[i] < v[pre]:
            // sum[i] - sum[pre] + (v[pre] - w[i]) + dp[pre - 1]
            // = sum[i] - w[i] + (dp[pre - 1] - sum[pre] + v[pre])
            larger.update(pos[v[i]], dp[i - 1] - sum[i] - v[i]);
            smaller.update(pos[v[i]], dp[i - 1] - sum[i] + v[i]);
            
            dp[i] = min(
                sum[i] + w[i] + larger.get(0, pos[w[i]] - 1),
                sum[i] - w[i] + smaller.get(pos[w[i]], m - 1)
            );
            // print(sum[i] + w[i] + larger.get(pos[w[i]], m - 1));
            // print(sum[i] - w[i] + smaller.get(0, pos[w[i]]));
        }
        
        // print(sum);
        // print(dp);
        
        cout << dp[n];
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "dmoj_dmopc18c5p5"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n;
    
    resize(n + 1, v, w);
    FOR(i, 1, n) {
        cin >> v[i] >> w[i];
    }
    
    if (n <= 20) return sub1::main(), 0;
    if (n <= 2000) return sub2::main(), 0;
    return sub3::main(), 0;
    ////////////////////////////////////////
}