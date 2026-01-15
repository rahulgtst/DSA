#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cerr << #x << " = " << x << '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

template<class T>
void read(vector<T> &v) {
    for (auto &x : v) cin >> x;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll modpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m = MOD) {
    return modpow(a, m - 2, m);
}

void solve() {
    // your solution here
}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
