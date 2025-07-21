#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ll p, q;
    cin >> p >> q;
    ll g = gcd(p, q);
    print("{} {}", p / g, q / g);
}