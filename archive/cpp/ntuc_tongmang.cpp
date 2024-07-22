#include <bits/stdc++.h>
using namespace std;

long long a, res = 1;

int main() {
    ifstream cin("_input.inp");
    while (cin >> a){
        res += a - 1;
        //cout << a << ' ' << res << '\n';
	};
    cout << res;
}