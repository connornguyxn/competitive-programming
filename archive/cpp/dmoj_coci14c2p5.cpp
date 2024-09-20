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
////////////////////////////////////////
template <class... T>
void print(T&&... a) {
    // clog << "[debug] ";
    // using e = int[];
    // e{(clog << a << sp, 0)...};
    // clog << endl;
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

// https://dmoj.ca/problem/coci14c2p5
// graph, dsu, math

int n;
vector2<ll> a, b;
vector<int> par;
deque<pii> cs;
////////////////////////////////////////////////////////////////////////////////
int idx(pii a) {
    return n * (a.fi - 1) + a.se;
}
////////////////////////////////////////
int assign(int p, int v) {
    cs.push_back({p, par[p]});
    par[p] = v;
    return v;
}
////////////////////////////////////////
void rollback(int s) {
    while (cs.size() > s) {
        pii cur = cs.back();
        cs.pop_back();
        par[cur.fi] = cur.se;
    }
}
////////////////////////////////////////
int root(int u) {
    return par[u] < 0 ? u : assign(u, root(par[u]));
}
////////////////////////////////////////
bool merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (par[u] > par[v]) swap(u, v);
    assign(u, par[u] + par[v]);
    assign(v, u);
    return true;
}
////////////////////////////////////////////////////////////////////////////////
signed main() {
    // #define TASK "test"
    #define TASK "dmoj_coci14c2p5"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n;
    
    a.resize(n + 1, vector<ll>(n + 1));
    b.resize(n + 1, vector<ll>(n + 1));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> a[i][j];
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> b[i][j];
        }
    }
    
    // print(a);
    // print(b);
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    par.assign(n * n + 1, -1);
    map<pll, vector<pii>> t;
    
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            FOR(d, 0, 3) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 1 || ni > n) continue;
                if (nj < 1 || nj > n) continue;
                
                if (b[ni][nj] == b[i][j] && a[ni][nj] == a[i][j]) {
                    print(idx({i, j}), idx({ni, nj}));
                    merge(idx({i, j}), idx({ni, nj}));
                    continue;
                }
                
                pll curt = {a[i][j] - a[ni][nj], b[ni][nj] - b[i][j]};
                if (curt.fi * curt.se < 0) continue;
                if (curt.se == 0) continue;
                
                int g = __gcd(abs(curt.fi), abs(curt.se));
                curt.fi /= g;
                curt.se /= g;
                if (curt.fi < 0) {
                    curt.fi = -curt.fi;
                    curt.se = -curt.se;
                }
                
                print(idx({i, j}), idx({ni, nj}), curt);
                t[curt].push_back({idx({i, j}), idx({ni, nj})});
            }
        }
    }
    
    int ans = 0;
    FOR(i, 1, n * n) {
        ans = max(ans, -par[root(i)]);
    }
    // vector<int> st = par;
    
    cs.clear();
    FORIN(cur, t) {
        sort(all(cur.se));
        cur.se.erase(unique(all(cur.se)), cur.se.end());
        print(cur);
        
        FORIN(it, cur.se) {
            merge(it.fi, it.se);
            ans = max(ans, -par[root(it.fi)]);
        }
        // print(par);
        
        rollback(0);
        // par = st;
    }
    cout << ans;
    ////////////////////////////////////////
}