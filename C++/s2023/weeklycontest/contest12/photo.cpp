#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "PHOTO"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(POS) (1ULL << (POS))
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// photo
// <tags>

int n, k, tc;
vector<int> a;
vector<vector<int>> adj;
int mk[3001];
////////////////////////////////////////
bool dfs(int cur) {
    mk[cur] = 1;
    
    for (int nxt : adj[cur]) {
        if (mk[nxt] == -1) continue;
        if (mk[nxt] == 1) return true;
        if (dfs(nxt)) return true;
    }
    
    mk[cur] = -1;
    
    return false;
}
bool check(int l, int r) {
    for_each(adj.begin(), adj.end(), [](vector<int> &cur) { cur.clear(); });
    for (int i = l; i < r; i++) {
        if (a[i] == a[i + 1]) return false;
        
        if ((i - l) % 2 == 0) {
            adj[a[i]].push_back(a[i + 1]);
        } else {
            adj[a[i + 1]].push_back(a[i]);
        }
    }
    
    memset(mk, 0, sizeof(mk));
    for (int i = 1; i <= k; i++) {
        if (mk[i] == 0 && dfs(i)) return false;
    }
    
    return true;
}
int solve(int s) {
    int l = s, r = n;
    
    while (l < r) {
        int m = (l + r) / 2;
        
        if (check(s, m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    return l;
}
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> n >> k >> tc;
    a.resize(n);
    adj.resize(k + 1);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> bound(n);
    for (int i = 0; i < n; i++) {
        bound[i] = solve(i);
    }
    // db(bound);
    
    while (tc--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        
        cout << (r < bound[l] ? "YES" : "NO") << nl;
    }
    ////////////////
    return 0;
}