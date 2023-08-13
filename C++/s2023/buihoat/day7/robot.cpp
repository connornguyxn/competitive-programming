#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "robot"
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
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
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

// prac_bh_robot
// <tags>

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> h(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }
    
    auto getid = [m](int i, int j) {
        return i * m + j + 1;
    };
    vector<vector<int>> adj(n * m + 1);
    vector<int> deg(n * m + 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                
                if (ni == n || ni < 0) continue;
                if (nj == m || nj < 0) continue;
                
                if (h[ni][nj] > h[i][j]) {
                    adj[getid(i, j)].push_back(getid(ni, nj));
                    deg[getid(ni, nj)]++;
                }
            }
        }
    }
    
    vector<ll> w(n * m + 1), dp(n * m + 1);
    deque<int> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = getid(i, j);
            
            cin >> w[cur];
            dp[cur] = w[cur];
            
            if (deg[cur] == 0) q.push_front(cur);
        }
    }
    
    ll res = -INFLL;
    
    while (q.size()) {
        int cur = q.back();
        q.pop_back();
        
        mxmz(res, dp[cur]);
        
        for (int nxt : adj[cur]) {
            mxmz(dp[nxt], dp[cur] + w[nxt]);
            
            deg[nxt]--;
            if (deg[nxt] == 0) {
                q.push_front(nxt);
            };
        }
    }
    
    cout << res;
    ////////////////
    return 0;
}