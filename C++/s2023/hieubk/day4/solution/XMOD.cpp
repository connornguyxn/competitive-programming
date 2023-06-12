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
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "xmod"

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
int a[maxn], rmin[1000002], rmax[1000003];
int use[1000002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> m;
    memset(rmin, 1, sizeof(rmin));
    memset(rmax, -1, sizeof(rmax));
    for (int x, i = 1; i <= n; i++){
        cin >> x;
        if (use[x]) continue;
        use[x] = 1;
        for (int j = x - 1; j <= 1000000; j += x) {
            //MIN(rmin[j], x-1);
            MAX(rmax[j], x-1);
            rmin[j+1] = 0;
        }
        MAX(rmax[1000000], 1000000%x);
        MIN(rmin[1000000], 1000000%x);
    }
    for (int i = 999999; i; i--){
        //if (rmin[i+1] > 0) MIN(rmin[i], rmin[i+1]-1);
        if (rmax[i+1] > 0) MAX(rmax[i], rmax[i+1]-1);
    }
    rmin[0] = 0;
    for (int i = 1; i <= 1000000; i++)
        MIN(rmin[i], rmin[i-1]+1);
    for (int x, i = 1; i <= m; i++){
        cin >> x;
        cout << rmin[x]<< " " << rmax[x] << "\n";
    }
    return 0;
}

