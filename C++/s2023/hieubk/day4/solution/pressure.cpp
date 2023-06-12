//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "pressure"

using namespace std;

typedef long long ll;
typedef long double ld;

int n, k, num = 0;
pair < pii, int > a[maxn];
int ext[maxn*3];
int T[maxn*12];
int pos[maxn*3];

void Init_Tree(int L, int R, int node){
    if (L == R){
        pos[L] = node;
        return;
    }
    int mid = (L+R)/2;
    Init_Tree(L, mid, node * 2);
    Init_Tree(mid+1, R, node * 2+1);
}

void Update(int vt, int val){
    int u = pos[vt];
    while (u > 0 && val < T[u]) {
        T[u] = val;
        u /= 2;
    }
}

void Init(){
    cin >> n >> k;
    vector <int> v(n*3+2);
    v[0] = 0; v[1] = k;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].F.F >> a[i].F.S >> a[i].S;
        v[++cnt] = a[i].F.F;
        v[++cnt] = a[i].F.S;
        v[++cnt] = a[i].F.F-1;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++){
        a[i].F.F = lower_bound(v.begin(), v.end(), a[i].F.F) - v.begin();
        a[i].F.S = lower_bound(v.begin(), v.end(), a[i].F.S) - v.begin();
    }
    k = v.size()-1;
}

int Get_min(int &u, int &v, int val, int L, int R, int node){
    if (u > R || v < L) return 0;
    if (T[node] > val)  return 0;
    if (L == R) return L;
    int mid = (L+R)/2;
    int x = Get_min(u, v, val, L, mid, node * 2);
    if (x == 0) x = Get_min(u, v, val, mid+1, R, node*2 + 1);
    return x;
}

bool check(int val){
    memset(ext, 0, sizeof ext);
    ext[0] = 1;
    memset(T, 120, sizeof T);
    priority_queue < pii > pq;
    while (!pq.empty()) pq.pop();
    int top = 0;
    for (int i = 1; i <= n; i++){
        int l = a[i].F.F, r = a[i].F.S, p = a[i].S;
        if (p > val) continue;
        while (!pq.empty() && -pq.top().F < l) {
            int u = pq.top().S;
            Update(a[u].F.S, a[u].S);
            pq.pop();
        }
        if (ext[l-1]) Update(r, p);
        else {
            int u = Get_min(l,r,val - p, 1, k, 1);
            if (u == 0 || T[pos[u]] > val - p) continue;
            pq.push({-u, i});
        }
        ext[r] = 1;
    }
    return ext[k];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    Init();
    Init_Tree(1, k, 1);
    sort(a+1, a+n+1);
    long long l = 0, r = 2e9+1;
    while (r - l > 1){
        int mid = l + (r-l)/2;
        if (check(mid)) r = mid;
            else l = mid;
    }
    cout << ((r > 2e9) ? -1 : r);
    return 0;
}

