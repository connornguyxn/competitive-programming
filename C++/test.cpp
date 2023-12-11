#include <bits/stdc++.h>
#define task "test"
#define ll long long
#define double long double
#define ii pair<int, int>
#define li pair<ll, int>
#define fi first
#define se second
#define c_bit(i)       __builtin_popcountll(i)
#define Bit(mask, i)    ((mask >> i) & 1)
#define onbit(mask, i)  ((mask) bitor (1LL << i))
#define offbit(mask, i) ((mask) &~ (1LL << i))
using namespace std;
const int maxn = 1e5 + 5;
const ll oo = 1e18;
const int mod = 1e9 + 7;
const int dx[] = {0, 1, 0, -1} , dy[] = {1, 0, -1, 0};

template <class X, class Y> bool maximize(X &a, const Y &b)
{
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, const Y &b)
{
    if(a > b) return a = b, true;
    return false;
}

int n, a[maxn], bit[2][maxn], suff[maxn], pref[maxn], change[maxn];

void update(int t, int id, int val)
{
    for(; id <= n; id += id & -id) bit[t][id] += val;
}

int get(int t, int id)
{
    int res = 0;
    for(; id; id -= id & -id) res += bit[t][id];
    return res;
}

ll calc(int l, int r)
{
    if(l == r) return 1;
    int mid = l + r >> 1;
    ll res = 0;
    res += calc(l, mid) + calc(mid + 1, r);

    suff[mid + 1] = pref[mid] = 1e9;
    for(int i = mid; i >= l; -- i) suff[i] = min(suff[i + 1], a[i]);
    for(int i = mid + 1; i <= r; ++ i) pref[i] = min(pref[i - 1], a[i]);

    int ma = 0, mi = 1e9, cnt = 0;
    for(int i = mid, j = mid + 1, k = mid + 1; i >= l; -- i){
        maximize(ma, a[i]);
        minimize(mi, a[i]);
        while(j <= r && a[j] <= ma){
            update(pref[j] & 1, j, 1);
            change[++ cnt] = j;
            ++ j;
        }
        while(k < j && mi <= a[k]) ++ k;
        if((ma - mi) & 1 ^ 1) res += (k - mid - 1);
        res += get(ma & 1, j - 1) - get(ma & 1, k - 1);
    }
    for(int i = 1; i <= cnt; ++ i){
        int p = change[i];
        update(pref[p] & 1, p, -1);
    }

    ma = 0; mi = 1e9; cnt = 0;
    for(int i = mid + 1, j = mid, k = mid; i <= r; ++ i){
        maximize(ma, a[i]);
        minimize(mi, a[i]);
        while(j >= l && a[j] < ma){
            update(suff[j] & 1, j, 1);
            change[++ cnt] = j;
            -- j;
        }
        while(k > j && mi <= a[k]) -- k;
        if((ma - mi) & 1 ^ 1) res += (mid - k);
        res += get(ma & 1, k) - get(ma & 1, j);
    }
    for(int i = 1; i <= cnt; ++ i){
        int p =  change[i];
        update(suff[p] & 1, p, -1);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if(fopen(task".inp","r")){
       freopen(task".inp","r",stdin);
       freopen(task".out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    cout << calc(1, n);
    return 0;
}
