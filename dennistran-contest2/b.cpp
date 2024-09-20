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

// https://codeforces.com/group/OgDyRcm8ue/contest/550507/
// string

int n, k, m;
struct E {
    int u, v;
    char c;
};
vector<E> es;
////////////////////////////////////////////////////////////////////////////////
namespace subf {
    bool checksub() {
        return true;
    }
    ////////////////////////////////////////
    vector<int> par;
    ////////////////////////////////////////
    int root(int u) {
        return par[u] < 0 ? u : par[u] = root(par[u]);
    }
    ////////////////////////////////////////
    bool join(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return false;
        if (par[u] > par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
    ////////////////////////////////////////
    void main() {
        assign(n + 1, -1, par);
        vector2<int> adj(n + 1);
        
        FORIN(it, es) {
            if (it.c == '=') {
                join(it.u, it.v);
            } else if (it.c == '<') {
                adj[it.u].push_back(it.v);
            } else {
                adj[it.v].push_back(it.u);
            }
        }
        
        vector2<int> radj(n + 1), rradj(n + 1);
        vector<int> nodes;
        FOR(cur, 1, n) {
            nodes.push_back(root(cur));
            FORIN(nxt, adj[cur]) {
                radj[root(cur)].push_back(root(nxt));
                rradj[root(nxt)].push_back(root(cur));
            }
        }
        
        sort(all(nodes));
        nodes.erase(unique(all(nodes)), nodes.end());
        
        sort(all(nodes), [&](int a, int b) {
            return rradj[a].size() < rradj[b].size();
        });
        // print(nodes);
        
        vector<char> ans(n + 1, 'a');
        FORIN(cur, nodes) {
            FORIN(nxt, radj[cur]) {
                // print(cur, nxt);
                ans[nxt] = max(ans[nxt], (char)(ans[cur] + 1));
            }
        }
        
        vector<char> ans2(n + 1, 'a' + k - 1);
        sort(all(nodes), [&](int a, int b) {
            return radj[a].size() < radj[b].size();
        });
        // print(nodes);
        
        FORIN(cur, nodes) {
            FORIN(nxt, rradj[cur]) {
                // print(cur, nxt);
                ans2[nxt] = min(ans2[nxt], (char)(ans2[cur] - 1));
            }
        }
        // print(ans);
        // print(ans2);
        
        FOR(i, 1, n) {
            cout << (ans[root(i)] == ans2[root(i)] ? ans[root(i)] : '?');
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    #define TASK "test"
    // #define TASK "b"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    ////////////////////////////////////////
    cin >> n >> k >> m;
    
    resize(m, es);
    FORIN(it, es) {
        str s;
        cin >> s;
        int i = 0;
        while (s[i] <= '9') {
            it.u = it.u * 10 + s[i] - '0';
            i++;
        }
        it.c = s[i];
        i++;
        while (i < (int)s.size()) {
            it.v = it.v * 10 + s[i] - '0';
            i++;
        }
    }
    
    if (subf::checksub()) return subf::main(), 0;
    ////////////////////////////////////////
}