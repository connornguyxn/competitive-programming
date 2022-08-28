#include <bits/stdc++.h>

using namespace std;

const int mod = 111539786;

struct Matrix {
    vector <vector <int> > data;
    int row() const { return data.size(); } 
    int col() const { return data[0].size(); }

    auto & operator [] (int i) { return data[i]; }
    
    const auto & operator[] (int i) const { return data[i]; }

    Matrix() = default;
    
    Matrix(int r, int c): data(r, vector <int> (c)) { }

    Matrix(const vector <vector <int> > &d): data(d) { }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }

    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = *this;
        assert(a.col() == b.row()); 
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k){
                    c[i][j] += 1ll * a[i][k] % mod * (b[k][j] % mod) % mod;
                    c[i][j] %= mod;
                }
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());  
        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

int main(){
    Matrix a({
        {1, 1},
        {1, 0}
    });

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Matrix tmp = a.pow(n - 1);
        cout << (tmp[0][0] + tmp[0][1]) % mod << '\n';
    }
}