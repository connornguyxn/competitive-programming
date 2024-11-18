#include "../template.cpp"


struct Line {
    mutable ll k, m, p;
    bool operator < (const Line& o) const {
        return k < o.k;
    }
    bool operator < (ll x) const {
        return p < x;
    }
};
struct ConvexHull : multiset<Line, less<>> {
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    
    bool isect(iterator a, iterator b) {
        if (b == end()) {
            a->p = INFLL;
            return false;
        }
        
        if (a->k == b->k) {
            a->p = (a->m > b->m ? INFLL : -INFLL);
        } else {
            a->p = div(b->m - a->m, a->k - b->k);
        }
        return a->p >= b->p;
    }
    
    void insert(ll k, ll m) {
        iterator z = multiset::insert({k, m, 0}), y = z++, x = y;
        
        while (isect(y, z)) {
            z = erase(z);
        }
        
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }
    
    ll get(ll x) {
        Line l = *lower_bound(x);
        return l.k * x + l.m;
    }
};