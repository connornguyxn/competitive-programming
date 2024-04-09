#include <bits/stdc++.h>
#define endl '\n'
#define task "1"
#define ll long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define BASE 311
#define c_bit(i)       __builtin_popcountll(i)
#define Bit(mask,i)    ((mask >> i) & 1)
#define onbit(mask,i)  ((mask) | (1LL << i))
#define offbit(mask,i) ((mask) &~ (1LL << i))

using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll oo = 1e18;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n, m, k;
int a[MAXN], b[MAXN];
int f[5][MAXN], bit[5][MAXN];

int Get(int id, int k){
    int cur = 0;
    if(id % 2 == 0){
        while(k <= m){
            cur = max(bit[id][k], cur);
            k += (k & (-k));
        }
    }
    else{
        while(k > 0){
            cur = max(bit[id][k], cur);
            k -= (k & (-k));
        }
    }
    return cur;
}

void update(int id, int k, int u){
    if(id % 2 == 0){
        while(k > 0){
            bit[id][k] = max(bit[id][k], u);
            k -= (k & (-k));
        }
    }
    else{
        while(k <= m){
            bit[id][k] = max(bit[id][k], u);
            k += (k & (-k));
        }
    }
}

void process(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    b[n + 1] = 0;
    sort(b + 1, b + n + 2);
    m = unique(b + 1, b + n + 2) - b - 1;
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= n; j++){
            if(i % 2 == 0){
                k = upper_bound(b + 1, b + m + 1, a[j]) - b;
            }
            else k = upper_bound(b + 1, b + m + 1, a[j] - 1) - b - 1;
            f[i][j] = Get(i, k) + 1;
            k = lower_bound(b + 1, b + m + 1, a[j]) - b;
            if (i > 1 && f[i][j] <= i) 
                f[i][j] = 0;
            update(i, k, f[i][j]);
            if(i >= 2){
                update(i, k, f[i - 1][j]);
			}
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, f[4][i]);
    }
    cout << ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r")){
       freopen(task".inp","r",stdin);
       freopen(task".out","w",stdout);
    }
    process();
}