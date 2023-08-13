#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "occstr"
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
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// occstr
// <tags>

int n, m;
str s, p;
////////////////////////////////////////
struct sub1 {
    vector<int> lps;
    
    vector<int> getlps(str a) {
        int n = a.size();
        vector<int> lps(n);
        
        lps[0] = 0;
        int j = 0, i = 1;
        while (i < n) {
            if (a[i] == a[j]) {
                lps[i] = ++j;
                i++;
            } else {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    lps[i] = 0;
                    i++;
                };
            };
        };
        
        return lps;
    };
    
    int kmp(str pat, str txt) {
        int m = pat.length();
        int n = txt.length();
        
        vector<int> res;
        
        int i = 0, j = 0;
        while ((n - i) >= (m - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            };
            if (j == m) {
                res.push_back(i - j);
                j = 0;
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                };
            };
        };
        
        return res.size();
    };
    
    bool mk[25];
    vector<int> res;
    void gen(int id, int cnt) {
        if (id == n) {
            str cur = "";
            for (int i = 0; i < n; i++) {
                if (mk[i]) cur += s[i];
            }
            mxmz(res[cnt], kmp(p, cur));
        } else {
            mk[id] = true;
            gen(id + 1, cnt + 1);
            mk[id] = false;
            gen(id + 1, cnt);
        }
    }
    
    sub1() {
        lps = getlps(p);
        res.resize(n + 1);
        gen(0, 0);
        for (int i = n; i >= 0; i--) {
            cout << res[i] << sp;
        }
    }
};
////////////////////////////////////////
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> s >> p;
    n = s.size();
    m = p.size();
    
    sub1();
    
    
    
    ////////////////
    return 0;
}