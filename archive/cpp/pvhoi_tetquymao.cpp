#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
#define TASK "tetquymao"
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
const int MOD = 1e9 + 19972207;

int r, c;
vector<int> md;
int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
vector<vector<int>> res;

template <typename T>
ostream &operator<<(ostream &cout, const vector<vector<T>> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << sp;
        }
        cout << nl;
    }
    return cout;
}

struct sub1 {
    vector<vector<int>> mk;
    
    void add_res() {
        for (int i = 0; i < r; i++) {
            if (md[i] == 3) continue;
            
            int s = 0;
            for (int j = 0; j < c; j++) {
                s += mk[i][j];
            }
            
            if (s % 3 != md[i]) return;
        };
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] += mk[i][j];
            }
        }
    }
    
    bool in_bound(int x, int y) {
        if (x < 0 || x >= r) return false;
        if (y < 0 || y >= c) return false;
        return true;
    }
    
    bool valid(int x, int y) {
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!in_bound(nx, ny)) continue;
            if (mk[nx][ny]) return false;
        }
        return true;
    }
    
    void gen(int x, int y) {
        if (x == r) {
            add_res();
            return;
        };
        
        int nx = x + (y + 1) / c;
        int ny = (y + 1) % c;
        if (valid(x, y)) {
            mk[x][y] = 1;
            gen(nx, ny);
            mk[x][y] = 0;
        };
        gen(nx, ny);
    }
    
    sub1() {
        mk = res;
        gen(0, 0);
        cout << res;
    }
};
struct sub2 {
    sub2() {
        ll mul = 1;
        for (int i = 0; i < r; i++) {
            if (md[i] == 2) {
                cout << vector<vector<int>>(r, vector<int>(c));
                return;
            };
            if (md[i] == 3) mul = mul * 2 % MOD;
        }
        for (int i = 0; i < r; i++) {
            if (md[i] == 1) {
                res[i][0] = mul;
            };
            if (md[i] == 3) {
                res[i][0] = mul / 2;
            };
        }
        
        cout << res;
    }
};
////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        // freopen(TASK".cout", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    cin >> r >> c;
    md.resize(r);
    for (int i = 0; i < r; i++) cin >> md[i];
    res.resize(r, vector<int>(c));
    // sub1();
    // sub2();
    if (r * c <= 21) {
        sub1();
    } else if (c == 1) {
        sub2();
    } else {
        sub1();
    }
    ////////////////
    return 0;
}