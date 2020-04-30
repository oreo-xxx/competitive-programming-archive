#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<long double, long double>;

const ll INF64 = 1LL << 60;
const int INF = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

// 負の数にも対応した mod (a = -11 とかでも OK)
inline long long mod(long long a, long long m) {
    long long res = a % m;
    if (res < 0) res += m;
    return res;
}

// 拡張 Euclid の互除法
long long extGCD(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    long long d = extGCD(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}


ll com (const ll n, const ll k){
    ll ue = 1, sita = 1;
    for(ll i = 0; i < k; ++i){
        ue *= (n-i);
        ue %= MOD;
        sita *= (i + 1);
        sita %= MOD;
    }
    return ue * modinv(sita, MOD) % MOD;
}

void solve() {
    ll x, y; cin >> x >> y;
    ll sum = x + y;
    if(sum % 3 != 0){
        cout << 0 << endl;
        return;
    }

    ll n = sum / 3;
    ll k = min(x-n, n - (x - n));
    cout << com(n,k) << endl;
    return;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}

