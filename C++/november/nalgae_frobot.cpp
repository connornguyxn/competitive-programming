#if DEBUG
    #include "lib/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "frobot"
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
#define Ford(i, r, l) for (int i = (r) + 1, _l = (l); --i >= _l; )
#define Forin(it, var) for (auto& it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ull BASE = 311;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// right, down, left, up, lower right, lower left, upper left, upper right
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
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

// https://sos.contest.codeforces.com/group/I5RsBaI6Kd/contest/488969
// implementation, pathfinding

struct Pos {
    int x, y, d = 0;
    ll w = 0;
    bool operator < (const Pos &o) const {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return d < o.d;
    }
};
struct Cmp {
    bool operator () (const Pos &a, const Pos &b) const {
        return a.w > b.w;
    }
};
struct Move {
    Pos pre = {-1, -1};
    ll w = 0;
    int type = -1;
};
////////////////////////////////////////
////////////////////////////////////////
int main() {
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////////
    int n, m, xs, ys, xt, yt;
    cin >> n >> m >> xs >> ys >> xt >> yt;
    
    vector<int> k(4);
    Rep(i, 4) cin >> k[i];
    
    vector<vector<bool>> a(n + 1, vector<bool>(m + 1));
    For(i, 1, n) For(j, 1, m) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
    }
    
    priority_queue<Pos, vector<Pos>, Cmp> pq;
    pq.push({xs, ys});
    map<Pos, Move> dst;
    dst[{xs, ys}] = {{-1, -1}, 0, -1};
    
    while (pq.size()) {
        Pos cur = pq.top();
        pq.pop();
        
        if (cur.x == xt && cur.y == yt) {
            cout << cur.w << nl;
            vector<int> ans;
            
            while (cur.x != xs || cur.y != ys || cur.d != 0) {
                ans.push_back(dst[cur].type);
                cur = dst[cur].pre;
            }
            reverse(all(ans));
            
            cout << ans.size() << nl;
            Forin(it, ans) cout << it + 1 << sp;
            
            return 0;
        }
        
        auto try_move = [&](Pos nxt , int type) {
            nxt.w += k[type];
            if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m) return;
            if (a[nxt.x][nxt.y]) return;
            if (dst.count(nxt) && dst[nxt].w <= nxt.w) return;
            
            dst[nxt] = {cur, nxt.w, type};
            pq.push(nxt);
        };
        
        try_move({cur.x + dx[cur.d], cur.y + dy[cur.d], cur.d, cur.w}, 0);
        try_move({cur.x + dx[cur.d + 4], cur.y + dy[cur.d + 4], cur.d, cur.w}, 1);
        try_move({cur.x, cur.y, (cur.d + 1) % 4, cur.w}, 2);
        try_move({cur.x, cur.y, (cur.d + 3) % 4, cur.w}, 3);
    }
    
    cout << -1;
    ////////////////////
    return 0;
}