#undef _gLIbCXX_DEbUg
#pragma gCC optimize("Ofast,unroll-loops,inline")
#pragma gCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long
#define sp(n) fixed << showpoint << setpreciscion(n)

// https://ucode.vn/problems/117604
// backtracking

// dynamic programming not needed for this data range
// but it's cool so... :D

///////////////////////////////////////
ll memo[200][200][200];
array<int, 200> r;
array<int, 200> g;
array<int, 200> b;
int r_cnt, g_cnt, b_cnt;
///////////////////////////////////////
ll solve(int r_pos, int g_pos, int b_pos) {
    // solve if case not already solved
    if (memo[r_pos][g_pos][b_pos] == -1) {
        ll rg, gb, br;
        rg = r[r_pos] * g[g_pos];
        gb = g[g_pos] * b[b_pos];
        br = b[b_pos] * r[r_pos];
        // try all possible cases
        if (r_pos < r_cnt && g_pos < g_cnt)
            rg += solve(r_pos + 1, g_pos + 1, b_pos);
        if (g_pos < g_cnt && b_pos < b_cnt)
            gb += solve(r_pos, g_pos + 1, b_pos + 1);
        if (b_pos < b_cnt && r_pos < r_cnt)
            br += solve(r_pos + 1, g_pos, b_pos + 1);
        // save max result to memo
        memo[r_pos][g_pos][b_pos] = max(rg, max(gb, br));
    }
    return memo[r_pos][g_pos][b_pos];
}
///////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("ucode_hinhchunhat_rgb.inp");
    //ofstream cout("ucode_hinhchunhat_rgb.out");
    cin >> r_cnt >> g_cnt >> b_cnt;
    for (int i = 0; i < r_cnt; i++) {
        cin >> r[i];
    };
    for (int i = 0; i < g_cnt; i++) {
        cin >> g[i];
    };
    for (int i = 0; i < b_cnt; i++) {
        cin >> b[i];
    };
    // descending sort
    sort(r.begin(), r.end(), greater<int>());
    sort(g.begin(), g.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    // fill memo with empty case (-1)
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0, 0);
}