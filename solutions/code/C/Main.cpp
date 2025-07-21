#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Polynomial {
    vector<ll> coeffs;
    Polynomial(const vector<ll>& coeffs) : coeffs(coeffs) {}

    ll operator()(ll x) {
        ll ret = 0;
        ll x_power = 1;
        for (ll c : coeffs) {
            ret += x_power * c;
            x_power *= x;
        }
        return ret;
    }
};

constexpr int LIMIT = 1e8;

void solve() {
    int d;
    cin >> d;

    vector<ll> coeffs(d + 1);
    for (int i = 0; i <= d; i++)
        cin >> coeffs[i];

    Polynomial f(coeffs);

    int lo = 1, hi = ceil(pow((double)LIMIT / f.coeffs.back(), 1.0 / d)) + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid) <= LIMIT)
            lo = mid + 1;
        else
            hi = mid;
    }

    print("{}\n", lo - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}