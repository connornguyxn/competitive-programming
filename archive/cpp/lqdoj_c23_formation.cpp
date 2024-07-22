#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #include <bits/stdc++.h>
    #define TASK "formation"
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
#define Forin(it, var) for (auto it : var)
#define bmask(i) (1ULL << (i))
#define bget(mask, i) ((mask >> (i)) & 1)
#define blog2(n) (63 - __builtin_clzll(n))
const int N = 1e6;
const ll MOD = 1e9 + 7;
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
void mxmz(T &a, T b) { a = max(a, b); }
template <class T>
void mnmz(T &a, T b) { a = min(a, b); }
void add(ll &a, ll b) { a = (a + b) % MOD; }
void sub(ll &a, ll b) { a = (a + MOD - b) % MOD; }
void mul(ll &a, ll b) { a = a * (b % MOD) % MOD; }


// https://lqdoj.edu.vn/problem/lqdoj2023r3formation
// 2d

struct pos {
    int x, y, w;
};
int n, m, k;
vector<vector<int>> a;
////////////////////////////////////////
struct sub5 {
    sub5() {
        vector<vector<int>> ans(n + 1, vector<int>(m + 1, -1));
        deque<pos> q;
        
        For(i, 1, n) For(j, 1, m) {
            if (a[i][j]) {
                q.push_back({i, j, 0});
                ans[i][j] = 0;
            }
        }
        
        while (q.size()) {
            pos cur = q.front();
            q.pop_front();
            
            Rep(d, 4) {
                pos nxt = {cur.x + dx[d], cur.y + dy[d], cur.w + 1};
                
                if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m) continue;
                if (ans[nxt.x][nxt.y] >= 0) continue;
                
                ans[nxt.x][nxt.y] = nxt.w;
                q.push_back(nxt);
            }
        }
        
        For(i, 1, n) {
            For(j, 1, m) cout << ans[i][j] << sp;
            cout << nl;
        }
    }
};
////////////////////////////////////////
struct sub1 {
    int bfs(pos s) {
        deque<pos> q = {s};
        
        int ck = k - a[s.x][s.y], res = 0;
        vector<vector<bool>> mk(n + 1, vector<bool>(m + 1));
        mk[s.x][s.y] = true;
        
        [&]() {
            while (q.size()) {
                pos cur = q.front();
                q.pop_front();
                
                Rep(d, 4) {
                    pos nxt = {cur.x + dx[d], cur.y + dy[d], cur.w + 1};
                    
                    if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m) continue;
                    if (mk[nxt.x][nxt.y]) continue;
                    
                    mk[nxt.x][nxt.y] = true;
                    ck -= a[nxt.x][nxt.y];
                    res += nxt.w * a[nxt.x][nxt.y];
                    if (ck == 0) return;
                    
                    q.push_back(nxt);
                }
            }
        }();
        
        return res;
    }
    sub1() {
        int ans = 0;
        For(i, 1, n) {
            For(j, 1, m) {
                ans += bfs({i, j, 0});
            }
        }
        cout << ans;
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    ////////////////
    cin >> n >> m >> k;
    a.resize(n + 1, vector<int>(m + 1));
    For(i, 1, n) For(j, 1, m) cin >> a[i][j];
    
    // sub5();
    // sub1();
    
    if (k == 1) {
        sub5();
    } else {
        sub1();
    }
    ////////////////
    return 0;
}